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

#include "main_window.hpp"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window),
	time(QTime::currentTime())
{
	ui->setupUi(this);

	cpt = 0.0;

	ui->plot->addGraph();
	ui->plot->graph(0)->setPen(QPen(Qt::green));
	ui->plot->graph(0)->addData(cpt, 1);
	ui->plot->addGraph();
	ui->plot->graph(1)->setPen(QPen(Qt::red));
	ui->plot->graph(1)->addData(cpt, -1);



	ui->plot->xAxis->setLabel("x");
	ui->plot->yAxis->setLabel("y");

	ui->plot->axisRect()->setupFullAxesBox();
	ui->plot->xAxis->setRange(0,100);
	ui->plot->yAxis->setRange(-1,1);

	QTimer * timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(draw()));
	timer->start();
}

main_window::~main_window()
{
	delete ui;
}

void main_window::draw()
{
	double elapsed = time.elapsed()/1000.0;
	if (elapsed-lastElapsed > 0.002)
	{
		lastElapsed = elapsed;
		ui->osg->brownian_move();
		/*
		cpt = fmin(cpt+0.1, 100);
		ui->plot->graph(0)->addData(cpt,cos(cpt));
		ui->plot->graph(1)->addData(cpt,-cos(cpt));

		if(cpt > 100)
		{
			ui->plot->rescaleAxes();
		}
		qDebug() << "Taille = " + QString::number(ui->plot->graph(0)->data()->size());
		*/
	}
	ui->osg->update();
	//ui->plot->replot();
}
