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
	center = new QFrame(this);

	osg = new osg_widget(f);


	plot = new QwtPlot();
	plot->setAxisScale( QwtPlot::yLeft, 0.0, double(osg->m_molecules.size()));

	plot->setTitle("Concentration des molécules");

	for (size_t i = 0; i < osg->molecules_id.size(); ++i)
	{
		std::string name = "Curve " + std::to_string(i);
		QwtPlotCurve *curve = new QwtPlotCurve(name.c_str());
		curve->attach(plot);
	}

	showMaximized();

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
{
	delete osg;
}

void main_window::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);
	osg->setMinimumHeight(height()/2);
	plot->setMaximumHeight(height()/2);
}

void main_window::draw()
{
	double elapsed = time.elapsed()/1000.0;
	if (elapsed-lastElapsedOsg > 0.002)
	{
		lastElapsedOsg = elapsed;
		osg->brownian_move();
	}
	osg->update();

	if (elapsed-lastElapsedPlot > 1.0)
	{
		lastElapsedPlot = elapsed;
		plot->replot();
	}

}
