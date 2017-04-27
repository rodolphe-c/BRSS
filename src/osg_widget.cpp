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
#include <future>
#include <thread>

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


std::random_device rd;
std::mt19937 gen(rd());

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


bool collision(std::array<float, 3> const & pos1, float const r1,  std::array<float, 3> const & pos2, float const r2)
{
	return std::pow(pos1[0] - pos2[0],2)
		 + std::pow(pos1[1] - pos2[1],2)
		 + std::pow(pos1[2] - pos2[2],2) >= std::pow(r1 - r2, 2);
}

// Création molécule 3D
osg::ref_ptr<osg::PositionAttitudeTransform> make_molecule(brss::molecule_type const & mt, molecule const & m, osg::Vec3 const & pos)
{
	auto radius = mt.taille/2;
	auto c = mt.couleur;
	auto color = osg::Vec4(float(c[0]/255),float(c[1]/255),float(c[2]/255),1.f);

	osg::ref_ptr<osg::Geode> enzyme = buildSphere(radius, color);
	osg::ref_ptr<osg::PositionAttitudeTransform> transform = new osg::PositionAttitudeTransform;

	enzyme->setName(std::to_string(m.id));
	osg::ref_ptr<osg::StateSet> stateSet = enzyme->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON);

	transform->setPosition(pos);
	transform->addChild(enzyme.get());
	transform->setName(std::to_string(m.id));

	return transform;
}

// Rechercher une Node (molécule 3D)
osg::PositionAttitudeTransform* osg_widget::findNode(std::string const & name)
{
	for (unsigned i = 1; i < m_group->getNumChildren(); ++i)
	{
		if(m_group->getChild(i)->getName() == name)
		{
			return dynamic_cast<osg::PositionAttitudeTransform*>(m_group->getChild(i));
		}
	}
	return nullptr;
}

// Constructeur
osg_widget::osg_widget(std::string const & filename, QWidget *parent, double const scaleX, double const scaleY):
	QGLWidget(parent),
	m_window
	(
		new osgViewer::GraphicsWindowEmbedded( this->x(), this->y(),this->width(), this->height() )
	),
	m_scaleX(scaleX),
	m_scaleY(scaleY)
{
	// Compilation du programme
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
		QMessageBox::critical(this, "Echec de compilation", msg);
		exit(1);
	}

	cube = std::vector<std::vector<std::vector<std::vector<molecule>>>>(prog.dimension/10, std::vector<std::vector<std::vector<molecule>>>(prog.dimension/10, std::vector<std::vector<molecule>>(prog.dimension/10, std::vector<molecule>())));

	m_radiusCells = float(prog.dimension)/2;
	m_radiusMolecule = 5.f;


	m_viewer = new osgViewer::Viewer;

	m_group = new osg::Group;

	// Cellule
	{
		osg::ref_ptr<osg::Geode> cellule = buildSphere(m_radiusCells, osg::Vec4(1.f,1.f,1.f,0.2f), 30, 30);

		osg::ref_ptr<osg::StateSet> stateSet = cellule->getOrCreateStateSet();
		osg::ref_ptr<osg::Material> material = new osg::Material;
		material->setAlpha(osg::Material::FRONT_AND_BACK, 0.2f);
		stateSet->setAttributeAndModes( material.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
		osg::ref_ptr<osg::BlendFunc> bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA,osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
		stateSet->setAttributeAndModes(bf.get());
		stateSet->setAttributeAndModes(new osg::CullFace(osg::CullFace::FRONT));
		stateSet->setAttributeAndModes(new osg::CullFace(osg::CullFace::BACK));
		stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON);

		m_group->addChild(cellule.get());
	}

	// Création des molécules
	size_t id = 0;
	for(auto const & m : prog.molecules_index)
	{
		molecules_types.push_back(mol_type(m.get().id, m.get().taille, m.get().popinit, m.get().velocity, m.get().couleur));
		for (size_t i = 0; i < m.get().popinit; ++i)
		{
			molecules.push_back(molecule(id, m.get().id, m.get().velocity));
			id++;
		}
	}
	max_molecule = id;

	auto size = std::pow(molecules.size(), 1.f/3.f);
	size_t cpt = 0;


	// Enzymes / Molécules
	for (size_t k = 0; k < size; ++k)
	{
		for (size_t j = 0; j < size; ++j)
		{
			for (size_t i = 0; i < size; ++i)
			{
				if(cpt >= molecules.size())
				{
					break;
				}

				//Position dans la sphère
				auto mat = osg::Matrix::translate(-size*m_radiusMolecule, -size*m_radiusMolecule, -size*m_radiusMolecule);
				auto pos = osg::Vec3(float(i)*2.f*m_radiusMolecule, float(j)*2.f*m_radiusMolecule, float(k)*2.f*m_radiusMolecule) * mat;
				molecules[cpt].rpos = {{pos.x(), pos.y(), pos.z()}};
				m_group->addChild(make_molecule(prog.molecules_index[molecules[cpt].type].get(), molecules[cpt], pos).get());

				//Calcul des indices dans le cube
				mat = osg::Matrix::translate(m_radiusCells, m_radiusCells, m_radiusCells);
				pos = pos * mat;

				molecules[cpt].index = {{size_t(pos.x()/10), size_t(pos.y()/10), size_t(pos.z()/10)}};
				cube[molecules[cpt].index[0]][molecules[cpt].index[1]][molecules[cpt].index[2]].push_back(molecules[cpt]);

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
{}

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

//Gestion des evenements
bool osg_widget::event(QEvent* event)
{
	bool handled = QGLWidget::event(event);
	return handled;
}

// Les voisins d'une molécule
std::vector<molecule> osg_widget::neighbour(molecule const & mol)
{
	std::vector<molecule> mols;
	for(int i = int(mol.index[0])-1; i <= int(mol.index[0])+1; ++i)
	{
		for(int j = int(mol.index[1])-1; j <= int(mol.index[1])+1; ++j)
		{
			for(int k = int(mol.index[2])-1; k <= int(mol.index[2])+1; ++k)
			{
				if (i < 0 || j < 0 || k < 0 || i >= (m_radiusCells*2)/10 || j >= (m_radiusCells*2)/10 || k >= (m_radiusCells*2)/10)
				{
					continue;
				}
				for(auto m : cube[size_t(i)][size_t(j)][size_t(k)])
				{
					mols.push_back(m);
				}
			}
		}
	}

	return mols;
}

// Version voisin cube
void osg_widget::brownian_move()
{
	// Les nouvelles molecules
	std::vector<molecule> new_mols;

	std::vector<size_t> old_mols;

	// Pour chaque molecules
	for  (size_t i = 0; i < molecules.size(); ++i)
	{
		// Si déjà visité, on ignore
		if (molecules[i].view)
		{
			continue;
		}

		// Déplacement molécule
		std::uniform_real_distribution<float> r_0_1(0.f,1.f);
		if(molecules[i].velocity <= r_0_1(gen))
		{
			std::uniform_int_distribution<int> dis(0, 360);

			// Nouvelle trajectoire
			float distance = 10.f;
			float alpha = float(dis(gen));
			float beta = float(dis(gen));

			float x = distance * float(sin(osg::DegreesToRadians(beta)) * cos(osg::DegreesToRadians(alpha)));
			float y = distance * float(sin(osg::DegreesToRadians(alpha)) * sin(osg::DegreesToRadians(beta)));
			float z = distance * float(cos(osg::DegreesToRadians(alpha)));

			std::array<float, 3> pos1 = {{molecules[i].rpos[0] + x, molecules[i].rpos[1] + y, molecules[i].rpos[2] + z}};

			// On récupère les voisins
			auto neighbours = neighbour(molecules[i]);
			for  (size_t j = 0; j < neighbours.size(); ++j)
			{
				// Si déjà visité, on ignore
				if (neighbours[j].view)
				{
					continue;
				}

				// S'il s'agit de la même molécule => réaction unimoléculaire
				if(molecules[i].id == neighbours[j].id)
				{
					auto reactions = prog.reactions_matrix[molecules[i].type][neighbours[j].type];
					if(reactions.size() > 0)
					{
						// Sélection réaction
						auto index = size_t(rand())%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							molecules[i].view = true;
							neighbours[j].view = true;

							// Suppression de l'ancienne molécule
							size_t id1 = molecules[i].id;
							molecules.erase
							(
								std::remove_if(molecules.begin(), molecules.end(),
								[&](molecule const & m){
									return m.id == id1;
								}),
								molecules.end()
							);

							// Suppression dans la représentation cubique
							auto indexes = molecules[i].index;
							cube[indexes[0]][indexes[1]][indexes[2]].erase
							(
								std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
								[&](molecule const & m){
									return m.id == id1;
								}),
								cube[indexes[0]][indexes[1]][indexes[2]].end()
							);

							// Réaction avec 2 nouvelles molécules
							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);

								m1.rpos = pos1;
								m1.pos[0] = pos1[0]+m_radiusCells; m1.pos[1] = pos1[1]+m_radiusCells; m1.pos[2] = pos1[2]+m_radiusCells;
								m1.index[0] = size_t(m1.pos[0]/10); m1.index[1] = size_t(m1.pos[1]/10); m1.index[2] = size_t(m1.pos[2]/10);
								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);
								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;
								new_mols.push_back(m2);
								max_molecule++;
							}
							// Réaction avec 1 nouvelle molécule
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);
								m.rpos = pos1;
								m.pos[0] = pos1[0]+m_radiusCells; m.pos[1] = pos1[1]+m_radiusCells; m.pos[2] = pos1[2]+m_radiusCells;
								m.index[0] = size_t(m.pos[0]/10); m.index[1] = size_t(m.pos[1]/10); m.index[2] = size_t(m.pos[2]/10);
								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					continue;
				}

				// Si on rentre en collision avec une autre molécule
				if(collision(molecules[i].rpos, molecules_types[molecules[i].type].size/2,
						neighbours[j].rpos, molecules_types[neighbours[j].type].size/2))
				{
					auto reactions = prog.reactions_matrix[molecules[i].type][neighbours[j].type];
					if(reactions.size() > 0)
					{
						// Sélection réaction
						auto index = size_t(rand())%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							molecules[i].view = true;
							neighbours[j].view = true;

							auto indexes = molecules[i].index;
							size_t id1 = molecules[i].id;
							size_t id2 = neighbours[j].id;

							// Réaction avec 2 nouvelles molécules
							if(reactions[index].left_molecules.size() == 2)
							{
								molecules.erase
								(
									std::remove_if(molecules.begin(), molecules.end(),
									[&](molecule const & m){
										return m.id == id1 || m.id == id2;
									}),
									molecules.end()
								);

								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1 || m.id == id2;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);

								indexes = neighbours[j].index;
								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1 || m.id == id2;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);
							}
							// Réaction avec 1 nouvelle molécule
							else
							{
								auto indexes = molecules[i].index;
								// Suppression de l'ancienne molécule
								size_t id1 = molecules[i].id;
								molecules.erase
								(
									std::remove_if(molecules.begin(), molecules.end(),
									[&](molecule const & m){
										return m.id == id1;
									}),
									molecules.end()
								);

								m_group->removeChild(findNode(std::to_string(molecules[i].id)));
								// Suppression dans la représentation cubique
								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);
							}
							// Réaction avec 2 nouvelles molécules
							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);

								m1.rpos = molecules[j].rpos;
								m1.pos[0] = molecules[j].rpos[0]+m_radiusCells;
								m1.pos[1] = molecules[j].rpos[1]+m_radiusCells;
								m1.pos[2] = molecules[j].rpos[2]+m_radiusCells;
								m1.index[0] = size_t(m1.pos[0]/10);
								m1.index[1] = size_t(m1.pos[1]/10);
								m1.index[2] = size_t(m1.pos[2]/10);
								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);

								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;
								new_mols.push_back(m2);
								max_molecule++;
							}
							// Réaction avec 1 nouvelle molécule
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);

								m.rpos = molecules[j].rpos;
								m.pos[0] = molecules[j].rpos[0]+m_radiusCells;
								m.pos[1] = molecules[j].rpos[1]+m_radiusCells;
								m.pos[2] = molecules[j].rpos[2]+m_radiusCells;
								m.index[0] = size_t(m.pos[0]/10);
								m.index[1] = size_t(m.pos[1]/10);
								m.index[2] = size_t(m.pos[2]/10);
								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					else
					{
						// S'il n'y a aucune réation possible on ne se déplace pas
						pos1 = molecules[i].rpos;
					}
				}
			}

			// Si on ne sort pas de la cellule, on met à jour la position de la molécule
			if(std::pow(pos1[0],2)+std::pow(pos1[1],2)+std::pow(pos1[2],2) < std::pow(m_radiusCells - molecules_types[molecules[i].type].size/2,2))
			{
				molecules[i].rpos = pos1;
				molecules[i].pos[0] = pos1[0]+m_radiusCells;
				molecules[i].pos[1] = pos1[1]+m_radiusCells;
				molecules[i].pos[2] = pos1[2]+m_radiusCells;
				molecules[i].index[0] = size_t(molecules[i].pos[0]/10);
				molecules[i].index[1] = size_t(molecules[i].pos[1]/10);
				molecules[i].index[2] = size_t(molecules[i].pos[2]/10);
			}
		}
	}

	// On ajoute les nouvelles molécules
	for (auto const & m : new_mols)
	{
		cube[m.index[0]][m.index[1]][m.index[2]].push_back(m);
		molecules.push_back(m);
	}

	for (auto & p : molecules)
	{
		p.view = false;
	}
	// On change l'ordre des molécules
	std::random_shuffle(molecules.begin(), molecules.end());


	m_group->removeChildren(1, m_group->getNumChildren()-1);
	for(auto m : molecules)
	{
		auto pos = osg::Vec3(m.rpos[0], m.rpos[1], m.rpos[2]);
		m_group->addChild(make_molecule(prog.molecules_index[m.type].get(), m, pos).get());
	}
}

// Version Naive
/*
void osg_widget::brownian_move()
{
	std::vector<molecule> new_mols;
	for  (size_t i = 0; i < molecules.size(); ++i)
	{
		if (molecules[i].view)
		{
			continue;
		}

		std::uniform_real_distribution<float> r_0_1(0.f,1.f);
		if(molecules[i].velocity <= r_0_1(gen))
		{
			std::uniform_int_distribution<int> dis(0, 360);

			float distance = 10.f;
			float alpha = float(dis(gen));
			float beta = float(dis(gen));

			float x = distance * float(sin(osg::DegreesToRadians(beta)) * cos(osg::DegreesToRadians(alpha)));
			float y = distance * float(sin(osg::DegreesToRadians(alpha)) * sin(osg::DegreesToRadians(beta)));
			float z = distance * float(cos(osg::DegreesToRadians(alpha)));

			std::array<float, 3> pos1 = {{molecules[i].rpos[0] + x, molecules[i].rpos[1] + y, molecules[i].rpos[2] + z}};

			for  (size_t j = 0; j < molecules.size(); ++j)
			{
				if (molecules[j].view)
				{
					continue;
				}
				if(i == j)
				{
					auto reactions = prog.reactions_matrix[molecules[i].type][molecules[j].type];
					if(reactions.size() > 0)
					{
						auto index = rand()%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							molecules[i].view = true;
							molecules.erase
							(
								std::remove_if(molecules.begin(), molecules.end(),
								[&](molecule const & m){
									return m.id == molecules[i].id;
								}),
								molecules.end()
							);

							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);
								m1.rpos = pos1;
								m1.pos[0] = pos1[0]+m_radiusCells; m1.pos[1] = pos1[1]+m_radiusCells; m1.pos[2] = pos1[2]+m_radiusCells;
								m1.index[0] = int(m1.pos[0]/10); m1.index[1] = int(m1.pos[1]/10); m1.index[2] = int(m1.pos[2]/10);
								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);
								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;
								new_mols.push_back(m2);
								max_molecule++;
							}
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);
								m.rpos = pos1;
								m.pos[0] = pos1[0]+m_radiusCells; m.pos[1] = pos1[1]+m_radiusCells; m.pos[2] = pos1[2]+m_radiusCells;
								m.index[0] = int(m.pos[0]/10); m.index[1] = int(m.pos[1]/10); m.index[2] = int(m.pos[2]/10);
								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					continue;
				}

				if(collision(molecules[i].rpos, molecules_types[molecules[i].type].size/2,
						molecules[j].rpos, molecules_types[molecules[j].type].size/2))
				{
					auto reactions = prog.reactions_matrix[molecules[i].type][molecules[j].type];
					if(reactions.size() > 0)
					{
						auto index = rand()%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							molecules[i].view = true;
							molecules[j].view = true;
							if(reactions[index].left_molecules.size() == 2)
							{
								molecules.erase
								(
									std::remove_if(molecules.begin(), molecules.end(),
									[&](molecule const & m){
										return m.id == molecules[i].id || m.id == molecules[j].id;
									}),
									molecules.end()
								);
							}
							else
							{
								molecules.erase
								(
									std::remove_if(molecules.begin(), molecules.end(),
									[&](molecule const & m){
										return m.id == molecules[i].id;
									}),
									molecules.end()
								);
							}

							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);

								m1.rpos = molecules[j].rpos;
								m1.pos[0] = molecules[j].rpos[0]+m_radiusCells;
								m1.pos[1] = molecules[j].rpos[1]+m_radiusCells;
								m1.pos[2] = molecules[j].rpos[2]+m_radiusCells;
								m1.index[0] = int(m1.pos[0]/10);
								m1.index[1] = int(m1.pos[1]/10);
								m1.index[2] = int(m1.pos[2]/10);

								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);

								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;

								new_mols.push_back(m2);
								max_molecule++;
							}
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);

								m.rpos = molecules[j].rpos;
								m.pos[0] = molecules[j].rpos[0]+m_radiusCells;
								m.pos[1] = molecules[j].rpos[1]+m_radiusCells;
								m.pos[2] = molecules[j].rpos[2]+m_radiusCells;
								m.index[0] = int(m.pos[0]/10);
								m.index[1] = int(m.pos[1]/10);
								m.index[2] = int(m.pos[2]/10);

								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					else
					{
						pos1 = molecules[i].rpos;
					}
				}
			}

			if(std::pow(pos1[0],2)+std::pow(pos1[1],2)+std::pow(pos1[2],2) < std::pow(m_radiusCells - molecules_types[molecules[i].type].size/2,2))
			{
				molecules[i].rpos = pos1;
				molecules[i].pos[0] = pos1[0]+m_radiusCells;
				molecules[i].pos[1] = pos1[1]+m_radiusCells;
				molecules[i].pos[2] = pos1[2]+m_radiusCells;
				molecules[i].index[0] = int(molecules[i].pos[0]/10);
				molecules[i].index[1] = int(molecules[i].pos[1]/10);
				molecules[i].index[2] = int(molecules[i].pos[2]/10);
			}
		}
	}
	for (auto const & p : new_mols)
	{
		molecules.push_back(p);
	}
	for (auto & p : molecules)
	{
		p.view = false;
	}
	std::random_shuffle(molecules.begin(), molecules.end());
}
*/


// Version voisin parallele (BUG)
/*
void osg_widget::brownian_move_sections(size_t start, size_t blocks, std::vector<std::vector<molecule>> & matrix)
{
	std::vector<molecule> new_mols;

	for  (size_t i = 0; i < matrix[start].size(); ++i)
	{
		if (matrix[start][i].view)
		{
			continue;
		}

		std::uniform_real_distribution<float> r_0_1(0.f,1.f);
		if(matrix[start][i].velocity <= r_0_1(gen))
		{
			std::uniform_int_distribution<int> dis(0, 360);

			float distance = 10.f;
			float alpha = float(dis(gen));
			float beta = float(dis(gen));

			float x = distance * float(sin(osg::DegreesToRadians(beta)) * cos(osg::DegreesToRadians(alpha)));
			float y = distance * float(sin(osg::DegreesToRadians(alpha)) * sin(osg::DegreesToRadians(beta)));
			float z = distance * float(cos(osg::DegreesToRadians(alpha)));

			std::array<float, 3> pos1 = {{molecules[i].rpos[0] + x, molecules[i].rpos[1] + y, molecules[i].rpos[2] + z}};

			auto neighbours = neighbour(matrix[start][i]);
			for  (size_t j = 0; j < neighbours.size(); ++j)
			{
				if (neighbours[j].view)
				{
					continue;
				}
				if(matrix[start][i].id == neighbours[j].id)
				{
					auto reactions = prog.reactions_matrix[matrix[start][i].type][neighbours[j].type];
					if(reactions.size() > 0)
					{
						auto index = size_t(rand())%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							matrix[start][i].view = true;
							neighbours[j].view = true;

							size_t id1 = matrix[start][i].id;
							matrix[start].erase
							(
								std::remove_if(matrix[start].begin(), matrix[start].end(),
								[&](molecule const & m){
									return m.id == id1;
								}),
								matrix[start].end()
							);

							auto indexes = matrix[start][i].index;
							cube[indexes[0]][indexes[1]][indexes[2]].erase
							(
								std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
								[&](molecule const & m){
									return m.id == id1;
								}),
								cube[indexes[0]][indexes[1]][indexes[2]].end()
							);

							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);

								m1.rpos = pos1;
								m1.pos[0] = pos1[0]+m_radiusCells; m1.pos[1] = pos1[1]+m_radiusCells; m1.pos[2] = pos1[2]+m_radiusCells;
								m1.index[0] = size_t(m1.pos[0]/10); m1.index[1] = size_t(m1.pos[1]/10); m1.index[2] = size_t(m1.pos[2]/10);
								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);
								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;
								new_mols.push_back(m2);
								max_molecule++;
							}
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);
								m.rpos = pos1;
								m.pos[0] = pos1[0]+m_radiusCells; m.pos[1] = pos1[1]+m_radiusCells; m.pos[2] = pos1[2]+m_radiusCells;
								m.index[0] = size_t(m.pos[0]/10); m.index[1] = size_t(m.pos[1]/10); m.index[2] = size_t(m.pos[2]/10);
								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					continue;
				}

				size_t ind = start;

				if(neighbours[j].pos[0] > start * blocks)
				{
					ind = start+1;
				}
				else if(neighbours[j].pos[0] < start)
				{
					ind = start-1;
				}

				if(collision(matrix[start][i].rpos, molecules_types[matrix[start][i].type].size/2,
						neighbours[j].rpos, molecules_types[neighbours[j].type].size/2))
				{
					auto reactions = prog.reactions_matrix[matrix[start][i].type][neighbours[j].type];
					if(reactions.size() > 0)
					{
						auto index = size_t(rand())%reactions.size();
						if(r_0_1(gen) <= reactions[index].proba)
						{
							matrix[start][i].view = true;
							neighbours[j].view = true;

							auto indexes = matrix[start][i].index;
							size_t id1 = matrix[start][i].id;
							size_t id2 = neighbours[j].id;

							if(reactions[index].left_molecules.size() == 2)
							{
								matrix[start].erase
								(
									std::remove_if(matrix[start].begin(), matrix[start].end(),
									[&](molecule const & m){
										return m.id == id1;
									}),
									molecules.end()
								);

								matrix[ind].erase
								(
									std::remove_if(matrix[start].begin(), matrix[start].end(),
									[&](molecule const & m){
										return m.id == id2;
									}),
									molecules.end()
								);

								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1 || m.id == id2;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);

								indexes = neighbours[j].index;
								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1 || m.id == id2;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);
							}
							else
							{
								auto indexes = matrix[start][i].index;

								size_t id1 = matrix[start][i].id;
								matrix[start].erase
								(
									std::remove_if(matrix[start].begin(), matrix[start].end(),
									[&](molecule const & m){
										return m.id == id1;
									}),
									matrix[start].end()
								);

								cube[indexes[0]][indexes[1]][indexes[2]].erase
								(
									std::remove_if(cube[indexes[0]][indexes[1]][indexes[2]].begin(), cube[indexes[0]][indexes[1]][indexes[2]].end(),
									[&](molecule const & m){
										return m.id == id1;
									}),
									cube[indexes[0]][indexes[1]][indexes[2]].end()
								);
							}

							if(reactions[index].right_molecules.size() == 2)
							{
								auto type1 = reactions[index].right_molecules[0];
								molecule m1 (max_molecule, type1, molecules_types[type1].velocity);

								m1.rpos = neighbours[j].rpos;
								m1.pos[0] = neighbours[j].rpos[0]+m_radiusCells;
								m1.pos[1] = neighbours[j].rpos[1]+m_radiusCells;
								m1.pos[2] = neighbours[j].rpos[2]+m_radiusCells;
								m1.index[0] = size_t(m1.pos[0]/10);
								m1.index[1] = size_t(m1.pos[1]/10);
								m1.index[2] = size_t(m1.pos[2]/10);
								new_mols.push_back(m1);
								max_molecule++;

								auto type2 = reactions[index].right_molecules[1];
								molecule m2 (max_molecule, type2, molecules_types[type2].velocity);

								m2.rpos = m1.rpos;
								m2.pos = m1.pos;
								m2.index = m1.index;
								new_mols.push_back(m2);
								max_molecule++;
							}
							else
							{
								auto type = reactions[index].right_molecules[0];
								molecule m (max_molecule, type, molecules_types[type].velocity);

								m.rpos = neighbours[j].rpos;
								m.pos[0] = neighbours[j].rpos[0]+m_radiusCells;
								m.pos[1] = neighbours[j].rpos[1]+m_radiusCells;
								m.pos[2] = neighbours[j].rpos[2]+m_radiusCells;
								m.index[0] = size_t(m.pos[0]/10);
								m.index[1] = size_t(m.pos[1]/10);
								m.index[2] = size_t(m.pos[2]/10);
								new_mols.push_back(m);
								max_molecule++;
							}
						}
					}
					else
					{
						pos1 = matrix[start][i].rpos;
					}
				}
			}

			if(std::pow(pos1[0],2)+std::pow(pos1[1],2)+std::pow(pos1[2],2) < std::pow(m_radiusCells - molecules_types[molecules[i].type].size/2,2))
			{
				matrix[start][i].rpos = pos1;
				matrix[start][i].pos[0] = pos1[0]+m_radiusCells;
				matrix[start][i].pos[1] = pos1[1]+m_radiusCells;
				matrix[start][i].pos[2] = pos1[2]+m_radiusCells;
				matrix[start][i].index[0] = size_t(matrix[start][i].pos[0]/10);
				matrix[start][i].index[1] = size_t(matrix[start][i].pos[1]/10);
				matrix[start][i].index[2] = size_t(matrix[start][i].pos[2]/10);

				if(matrix[start][i].pos[0] > start*blocks)
				{
					matrix[start+1].push_back(matrix[start][i]);
					matrix[start].erase
					(
						std::remove_if(matrix[start].begin(), matrix[start].end(),
						[&](molecule const & m){
							return m.id == matrix[start][i].id;
						}),
						matrix[start].end()
					);
				}
				else if(matrix[start][i].pos[0] < start)
				{
					matrix[start-1].push_back(matrix[start][i]);
					matrix[start].erase
					(
						std::remove_if(matrix[start].begin(), matrix[start].end(),
						[&](molecule const & m){
							return m.id == matrix[start][i].id;
						}),
						matrix[start].end()
					);
				}
			}
		}
	}
	for (auto const & m : new_mols)
	{
		cube[m.index[0]][m.index[1]][m.index[2]].push_back(m);
		if(m.pos[0] > start*blocks)
		{
			matrix[start+1].push_back(m);
		}
		else if(m.pos[0] < start)
		{
			matrix[start-1].push_back(m);
		}
		else
		{
			matrix[start].push_back(m);
		}
	}

	for (auto & p : molecules)
	{
		p.view = false;
	}
	std::random_shuffle(molecules.begin(), molecules.end());
}





// Version voisin parallele
void osg_widget::brownian_move()
{
	unsigned max_threads = std::thread::hardware_concurrency();

	if (max_threads >= 3)
	{

		float blocks = float((m_radiusCells*2)/10)/max_threads;
		if (blocks == std::floor(blocks) && blocks >= 2)
		{
			std::vector<std::vector<molecule>> molecules_by_region (max_threads, std::vector<molecule>());

			for(auto m : molecules)
			{
				size_t ind = m.index[0]/size_t(blocks);
				molecules_by_region[ind].push_back(m);
			}

			for (auto v : molecules_by_region)
			{
				std::cout << v.size() << std::endl;
			}

			std::vector<std::future<void>> sections_impair;
			std::vector<std::future<void>> sections_pair;

			size_t cpt = 0;
			for(size_t i = 0; i < (m_radiusCells*2); i+= size_t(blocks)*2)
			{
				sections_pair.push_back(std::async(std::launch::async, [&](){ brownian_move_sections(cpt, blocks, molecules_by_region); }));
				cpt+=2;
			}

			for (auto & f : sections_pair)
			{
				f.wait();
			}

			cpt = 1;
			for(size_t i = size_t(blocks); i < (m_radiusCells*2); i+= size_t(blocks)*2)
			{
				sections_impair.push_back(std::async(std::launch::async, [&](){ brownian_move_sections(cpt, blocks, molecules_by_region); }));
				cpt+=1;
			}

			for (auto & f : sections_impair)
			{
				f.wait();
			}
		}
	}
}
*/
