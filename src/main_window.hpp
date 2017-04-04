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

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QFrame>

#include "../src/osg_widget.hpp"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	explicit main_window(std::string const &, QWidget *parent = 0);
	~main_window();

public slots:
	void draw();

protected:
	void resizeEvent(QResizeEvent* event);

private:
	std::string filename;

	QFrame * center;

	osg_widget * osg;
	QwtPlot * plot;

	//update loop
	QTime time;
	double lastElapsedOsg = 0;
	double lastElapsedPlot = 0;
};

#endif // MAIN_WINDOW_HPP
