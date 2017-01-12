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


#include <QMouseEvent>
#include <QWheelEvent>

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

	osg::Cylinder* cylinder    = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f, 0.5f );
	osg::ShapeDrawable* sd = new osg::ShapeDrawable( cylinder );
	osg::Geode* geode = new osg::Geode;
	geode->addDrawable(sd);

	osg::Camera* camera = new osg::Camera;
	camera->setViewport( 0, 0, this->width(), this->height() );
	camera->setClearColor( osg::Vec4( 0.4f, 0.4f, 0.6f, 1.f ) );
	double aspectRatio = double( this->width()) / double( this->height() );
	camera->setProjectionMatrixAsPerspective( 30, aspectRatio, 1, 1000);
	camera->setGraphicsContext( m_window );

	m_viewer->setCamera(camera);
	m_viewer->setSceneData(geode);

	osgGA::TrackballManipulator* manipulator = new osgGA::TrackballManipulator;
	manipulator->setAllowThrow( false );
	this->setMouseTracking(true);
	m_viewer->setCameraManipulator(manipulator);
	m_viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
	m_viewer->realize();

}

void osg_widget::initializeGL()
{
	osg::ref_ptr<osg::Geode> geode = dynamic_cast<osg::Geode*>(m_viewer->getSceneData());
	osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();

	osg::ref_ptr<osg::Material> material = new osg::Material;
	material->setAlpha(osg::Material::FRONT_AND_BACK, 0.1f);
	stateSet->setAttributeAndModes( material.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	osg::ref_ptr<osg::BlendFunc> bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA,osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
	stateSet->setAttributeAndModes(bf.get());
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
		this->update();
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
