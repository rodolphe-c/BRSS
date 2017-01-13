// Copyright � 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

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


#ifndef osg_widget_hpp
#define osg_widget_hpp

#include <QGLWidget>

#include <osg/Node>
#include <osg/Geode>
#include <osg/Group>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <osg/MatrixTransform>

class osg_widget: public QGLWidget
{
Q_OBJECT

public:
	explicit osg_widget(QWidget *parent = 0, double const scaleX = 2.0, double const scaleY = 2.0);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);
	bool event(QEvent* event);

public slots:
	void brownian_move();

private:
	osg::ref_ptr<osgViewer::Viewer> m_viewer;
	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_window;
	double m_scaleX, m_scaleY;

	osg::ref_ptr<osg::Group> group;

	osgGA::EventQueue* getEventQueue() const;

};

#endif
