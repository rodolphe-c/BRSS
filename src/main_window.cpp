#include "main_window.hpp"
#include "ui_main_window.h"

#include <QDebug>

main_window::main_window(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window)
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

	connect(&timer, SIGNAL(timeout()), this, SLOT(drawPlot()));
	timer.start(10);
}

main_window::~main_window()
{
	delete ui;
}

void main_window::drawPlot()
{
	cpt = fmin(cpt+0.1, 50);
	ui->plot->graph(0)->addData(cpt,cos(cpt));
	ui->plot->graph(1)->addData(cpt,-cos(cpt));
	ui->plot->rescaleAxes();
	ui->plot->replot();
	if(cpt >= 50.0)
	{
		timer.stop();
	}
}
