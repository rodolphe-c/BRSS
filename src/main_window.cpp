#include "main_window.hpp"
#include "ui_main_window.h"

#include <cmath>

#include <QDebug>

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
	ui->osg->update();
	double elapsed = time.elapsed()/1000.0;
	if (elapsed-lastElapsed > 0.10)
	{
		cpt = fmin(cpt+0.1, 100);
		ui->plot->graph(0)->addData(cpt,cos(cpt));
		ui->plot->graph(1)->addData(cpt,-cos(cpt));
		lastElapsed = elapsed;
		if(cpt > 100)
		{
			ui->plot->rescaleAxes();
		}
		qDebug() << "Taille = " + QString::number(ui->plot->graph(0)->data()->size());
	}
	ui->plot->replot();
}
