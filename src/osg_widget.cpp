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

#include <QMouseEvent>
#include <QWheelEvent>

#include <osg/Group>
#include <osgViewer/GraphicsWindow>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/Camera>
#include <osg/BlendFunc>

#include "osg_widget.hpp"

osg_widget::osg_widget(QWidget *parent, double const scaleX, double const scaleY):
	QGLWidget(parent),
	m_window
	(
		new osgViewer::GraphicsWindowEmbedded( this->x(), this->y(),this->width(), this->height() )
	),
	m_scaleX(scaleX),
	m_scaleY(scaleY)
{

	m_viewer =new osgViewer::Viewer;

	group = new osg::Group;

	// Cellule
	osg::ref_ptr<osg::Sphere> sphere    = new osg::Sphere( osg::Vec3( 0.f, 0.f, 0.f ), 20.0);
	osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable( sphere );
	osg::ref_ptr<osg::Geode> cellule = new osg::Geode;
	cellule->addDrawable(sd);
	group->addChild(cellule);

	// Enzymes
	for  (size_t k = 0; k < 10; ++k)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				osg::ref_ptr<osg::Geode> enzyme = new osg::Geode;
				osg::ref_ptr<osg::ShapeDrawable> obj = new osg::ShapeDrawable;

				auto mat = osg::Matrix::translate(-10.0, -10.0, -10.0);
				auto pos = osg::Vec3(float(i)*2.f+1.f, float(j)*2.f+1.f, float(k)*2.f+1.f) * mat;

				obj->setShape(new osg::Sphere(pos, 1.f));
				obj->setColor(osg::Vec4(float(j%2)+1,float(j%2),0.f,1.f));
				enzyme->addDrawable(obj.get());

				group->addChild(enzyme);
			}
		}
	}

	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setViewport( 0, 0, this->width(), this->height() );
	camera->setClearColor( osg::Vec4( 0.4f, 0.4f, 0.6f, 1.f ) );
	double aspectRatio = double( this->width()) / double( this->height() );
	camera->setProjectionMatrixAsPerspective( 30, aspectRatio, 1, 1000);
	camera->setGraphicsContext( m_window );

	m_viewer->setCamera(camera.get());
	m_viewer->setSceneData(group.get());

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
		material->setAlpha(osg::Material::FRONT_AND_BACK, 0.1f);
		stateSet->setAttributeAndModes( material.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
		osg::ref_ptr<osg::BlendFunc> bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA,osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
		stateSet->setAttributeAndModes(bf.get());
	}

	//Enzymes
	for  (size_t i = 0; i < group->getNumChildren()-1; ++i)
	{
		osg::ref_ptr<osg::Group> geode = dynamic_cast<osg::Geode*>(group->getChild(unsigned(i+1)));
		osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
		osg::Material* material = new osg::Material;
		material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
		stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
		stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );
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
	for  (size_t i = 0; i < group->getNumChildren()-1; ++i)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 360);

		osg::ref_ptr<osg::Group> geode = dynamic_cast<osg::Geode*>(group->getChild(unsigned(i+1)));

		osg::ref_ptr<osg::MatrixTransform> transformation1 = new osg::MatrixTransform;
		//transformation1->setMatrix (osg::Matrix::rotate( TODO )));
		transformation1->addChild(geode);
	}
}
