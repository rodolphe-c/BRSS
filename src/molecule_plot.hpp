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


#ifndef molecule_plot_hpp
#define molecule_plot_hpp

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>

#include "osg_widget.hpp"

class molecule_plot: public QwtPlot
{
Q_OBJECT

private:
	osg_widget * target;
	std::vector<QwtPointSeriesData*> m_data;

public:
	explicit molecule_plot(osg_widget * target, QWidget *parent = 0);
	void update(double const time);

};

#endif
