// Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

// This file is part of BRSS.

// BRSS is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// BRSS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
// You should have received a copy of the GNU Affero General Public License
// along with BRSS. If not, see <http://www.gnu.org/licenses/>


#include <random>
#include <cmath>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QMessageBox>

#include <osg/Group>
#include <osg/Math>
#include <osg/PositionAttitudeTransform>
#include <osgViewer/GraphicsWindow>
#include <osg/ShapeDrawable>
#include <osg/Camera>
#include <osg/Material>
#include <osg/BlendFunc>
#include <osg/Texture>
#include <osg/Texture2D>
#include <osg/Object>
#include <osg/CullFace>

#include "osg_widget.hpp"

#include "program.hpp"


//http://stackoverflow.com/questions/20433443/creating-a-sphere-using-osggeometry-in-openscenegraph
osg::ref_ptr<osg::Geode> buildSphere( float const radius, osg::Vec4 const & color, size_t const rings = 10, size_t const sectors= 10)
{
	osg::ref_ptr<osg::Geode>      sphereGeode = new osg::Geode;
	osg::ref_ptr<osg::Geometry>   sphereGeometry = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array>  sphereVertices = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec3Array>  sphereNormals = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec2Array>  sphereTexCoords = new osg::Vec2Array;
	osg::ref_ptr<osg::Vec4Array>  sphereColors = new osg::Vec4Array;

	float const R = 1.f/float(rings - 1);
	float const S = 1.f/float(sectors - 1);

	sphereGeode->addDrawable(sphereGeometry);

	// Establish texture coordinates, vertex list, and normals
	for(size_t r = 0; r < rings; ++r)
	{
		for(size_t s = 0; s < sectors; ++s)
		{
			float const y = float(sin( -M_PI_2 + M_PI * r * R));
			float const x = float(cos( 2 * M_PI * s * S) * sin( M_PI * r * R ));
			float const z = float(sin( 2 * M_PI * s * S) * sin( M_PI * r * R ));

			sphereTexCoords->push_back(osg::Vec2(s * R, r * R));

			sphereVertices->push_back (osg::Vec3( x * radius,
			                                      y * radius,
			                                      z * radius));
			sphereNormals->push_back  ( osg::Vec3( x, y, z ) );
			sphereColors->push_back(color);
		}
	}

	sphereGeometry->setVertexArray  (sphereVertices);
	sphereGeometry->setTexCoordArray(0, sphereTexCoords);
	sphereGeometry->setColorArray(sphereColors);
	sphereGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	// Generate quads for each face.
	for(size_t r = 0; r < rings - 1; ++r)
	{
		for(size_t s = 0; s < sectors - 1; ++s)
		{
			osg::ref_ptr<osg::DrawElementsUInt> face =
			        new osg::DrawElementsUInt( osg::PrimitiveSet::QUADS,
			                                   4 )
			;
			// Corners of quads should be in CCW order.
			face->push_back(unsigned((r + 0) * sectors + (s + 0)));
			face->push_back(unsigned((r + 0) * sectors + (s + 1)));
			face->push_back(unsigned((r + 1) * sectors + (s + 1)));
			face->push_back(unsigned((r + 1) * sectors + (s + 0)));

			sphereGeometry->addPrimitiveSet(face);
		}
	}

	return sphereGeode;
}

osg_widget::osg_widget(std::string const & filename, QWidget *parent, double const scaleX, double const scaleY):
	QGLWidget(parent),
	m_window
	(
		new osgViewer::GraphicsWindowEmbedded( this->x(), this->y(),this->width(), this->height() )
	),
	m_scaleX(scaleX),
	m_scaleY(scaleY)
{
	try
	{
		std::vector<brss::error_t> warnings;
		prog = brss::parser(brss::lex(filename), warnings);

		if(warnings.size() > 0)
		{
			QString msg ("");
			for (auto const & e : warnings)
			{
				msg+= QString("<font color='#d8a70d'>") + QString::fromStdString(e.first) + QString("</font><p>")
					+  QString::fromStdString(e.second) + QString("</p></br>");
			}
			QMessageBox::warning(nullptr, "Attention !", msg);
		}
	}
	catch (brss::error_t const & e)
	{
		auto msg = QString("<font color='#ff0000'>ERROR ") + QString::fromStdString(e.first) + QString("</font><p>") + QString::fromStdString(e.second);
		QMessageBox::critical(nullptr, "Echec de compilation", msg);
		exit(1);
	}

	m_radiusCells = float(prog.dimension)/2;
	m_radiusMolecule = 5.f;


	m_viewer =new osgViewer::Viewer;

	m_group = new osg::Group;

	// Cellule
	{
		osg::ref_ptr<osg::Geode> cellule = buildSphere(m_radiusCells, osg::Vec4(1.f,1.f,1.f,0.2f), 30, 30);
		m_group->addChild(cellule);
	}

	size_t id = 0;
	for(auto const & m : prog.molecules_index)
	{
		molecules_id.push_back(std::vector<molecule>());
		for (size_t i = 0; i < m.get().popinit; ++i)
		{
			//molecules_id[i].push_back(molecule(id, m.get().id, m.get().velocity));
			m_molecules.push_back(molecule(id, m.get().id, m.get().velocity));
			id++;
		}
	}

	auto size = std::pow(m_molecules.size(), 1.f/3.f);
	size_t cpt = 0;

	// Enzymes
	for (size_t k = 0; k < size; ++k)
	{
		for (size_t j = 0; j < size; ++j)
		{
			for (size_t i = 0; i < size; ++i)
			{
				if(cpt >= m_molecules.size())
				{
					break;
				}

				auto radius = prog.molecules_index[m_molecules.at(cpt).type].get().taille/2;
				auto c = prog.molecules_index[m_molecules.at(cpt).type].get().couleur;

				auto color = osg::Vec4(float(c[0]/255),float(c[1]/255),float(c[2]/255),1.f);
				osg::ref_ptr<osg::Geode> enzyme = buildSphere(radius, color);
				osg::ref_ptr<osg::PositionAttitudeTransform> transform = new osg::PositionAttitudeTransform;
				auto mat = osg::Matrix::translate(-size*m_radiusMolecule, -size*m_radiusMolecule, -size*m_radiusMolecule);
				auto pos = osg::Vec3(float(i)*2.f*m_radiusMolecule, float(j)*2.f*m_radiusMolecule, float(k)*2.f*m_radiusMolecule) * mat;

				transform->setPosition(pos);
				transform->addChild(enzyme);

				m_group->addChild(transform);

				cpt++;
			}
		}
	}

	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setViewport( 0, 0, this->width(), this->height() );
	camera->setClearColor( osg::Vec4( 0.f, 0.f, 0.f, 1.f ) );
	double aspectRatio = double( this->width()) / double( this->height() );
	camera->setProjectionMatrixAsPerspective( 30, aspectRatio, 1, 1000);
	camera->setGraphicsContext( m_window );

	m_viewer->setCamera(camera.get());
	m_viewer->setSceneData(m_group.get());

	osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator;
	manipulator->setAllowThrow( false );
	this->setMouseTracking(true);
	m_viewer->setCameraManipulator(manipulator.get());
	m_viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
	m_viewer->realize();
}

void osg_widget::initializeGL()
{
	osg::ref_ptr<osg::Group> group = dynamic_cast<osg::Group*>(m_viewer->getSceneData());

	// Cellule
	{
		osg::ref_ptr<osg::Group> geode = dynamic_cast<osg::Geode*>(group->getChild(0));
		osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
		osg::ref_ptr<osg::Material> material = new osg::Material;
		material->setAlpha(osg::Material::FRONT_AND_BACK, 0.2f);
		stateSet->setAttributeAndModes( material.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
		osg::ref_ptr<osg::BlendFunc> bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA,osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
		stateSet->setAttributeAndModes(bf.get());
		stateSet->setAttributeAndModes(new osg::CullFace(osg::CullFace::FRONT));
		stateSet->setAttributeAndModes(new osg::CullFace(osg::CullFace::BACK));
		stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON);
	}

	//Enzymes
	for  (size_t i = 0; i < group->getNumChildren()-1; ++i)
	{
		osg::ref_ptr<osg::PositionAttitudeTransform> transform = dynamic_cast<osg::PositionAttitudeTransform*>(group->getChild(unsigned(i+1)));
		osg::ref_ptr<osg::Group> geode = dynamic_cast<osg::Geode*>(transform->getChild(0));
		osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
		stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON);
	}
}

void osg_widget::resizeGL(int width, int height)
{
	if (m_window.valid())
	{
		m_window->resized(m_window->getTraits()->x, m_window->getTraits()->y, width, height);
		m_window->getEventQueue()->windowResize(m_window->getTraits()->x, m_window->getTraits()->y, width, height);
	}
}

void osg_widget::paintGL()
{
	if (m_viewer.valid())
	{
		m_viewer->frame();
	}
}

osgGA::EventQueue* osg_widget::getEventQueue() const
{
	osgGA::EventQueue* eventQueue = m_window->getEventQueue();
	return eventQueue;
}


void osg_widget::mouseMoveEvent(QMouseEvent* event)
{
	this->getEventQueue()->mouseMotion(float(event->x()*m_scaleX), float(event->y()*m_scaleY));
}

void osg_widget::mousePressEvent(QMouseEvent* event)
{
	unsigned int button = 0;

	if (Qt::LeftButton == event->button()) {button = 1;}
	//else if (Qt::MiddleButton == event->button()) {button = 2;}
	else if (Qt::RightButton == event->button()) {button = 3;}

	this->getEventQueue()->mouseButtonPress(float(event->x()*m_scaleX), float(event->y()*m_scaleY), button);
}

void osg_widget::mouseReleaseEvent(QMouseEvent* event)
{
	unsigned int button = 0;

	if (Qt::LeftButton == event->button()) {button = 1;}
	//else if (Qt::MiddleButton == event->button()) {button = 2;}
	else if (Qt::RightButton == event->button()) {button = 3;}

	this->getEventQueue()->mouseButtonRelease(float(event->x()*m_scaleX), float(event->y()*m_scaleY), button);
}

void osg_widget::wheelEvent(QWheelEvent* event)
{
	int delta = event->delta();
	osgGA::GUIEventAdapter::ScrollingMotion motion = delta > 0 ?
				osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN;
	this->getEventQueue()->mouseScroll(motion);
}

bool osg_widget::event(QEvent* event)
{
	bool handled = QGLWidget::event(event);
	return handled;
}

void osg_widget::brownian_move()
{
	for  (size_t i = 0; i < m_group->getNumChildren()-1; ++i)
	{
		osg::ref_ptr<osg::PositionAttitudeTransform> transform = dynamic_cast<osg::PositionAttitudeTransform*>(m_group->getChild(unsigned(i+1)));

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(-10, 10);

		float x = dis(gen);
		float y = dis(gen);
		float z = dis(gen);

		auto pos = transform->getPosition() + osg::Vec3(x,y,z);

		if(std::pow(pos.x(),2)+std::pow(pos.y(),2)+std::pow(pos.z(),2) < std::pow(m_radiusCells - m_radiusMolecule,2))
		{
			transform->setPosition(pos);
		}
	}
}
