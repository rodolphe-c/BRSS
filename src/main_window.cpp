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

#include <cmath>

#include <QVBoxLayout>

#include "main_window.hpp"

main_window::main_window(std::string const & f, QWidget *parent) :
	QMainWindow(parent),
	filename(f),
	time(QTime::currentTime())
{
	setWindowState(Qt::WindowMaximized);

	center = new QFrame(this);
	osg = new osg_widget(f, this);
	plot = new molecule_plot(osg, this);

	osg->setMinimumHeight(200);
	osg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);



	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(osg);
	layout->addWidget(plot);
	center->setLayout(layout);
	setCentralWidget(center);


	QTimer * timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(draw()));
	timer->start();
}

main_window::~main_window()
{}

void main_window::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);
}

void main_window::draw()
{
	double elapsed = time.elapsed()/1000.0;
	// update molecule
	if (elapsed-lastElapsed >= 0.01)
	{
		lastElapsed = elapsed;
		t+=10;
		osg->brownian_move();
		plot->update(double(t));
	}
	if (elapsed-lastDraw >= 1.0)
	{
		lastDraw = elapsed;
		plot->replot();
	}
	osg->update();
}
