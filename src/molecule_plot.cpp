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


#include "molecule_plot.hpp"

molecule_plot::molecule_plot(osg_widget * t, QWidget *parent):
	QwtPlot(parent),
	target(t)
{
	setAxisScale( QwtPlot::yLeft, 0.0, double(target->molecules.size()));
	setTitle("Concentration des molécules");
	setAxisScale(QwtPlot::xBottom, 0, 5000);
	setAxisTitle(QwtPlot::xBottom, "Temps (ns)");
	setAxisTitle(QwtPlot::yLeft, "Molecules");

	// legend
	QwtLegend *legend = new QwtLegend;
	legend->setFrameStyle(QFrame::Box|QFrame::Sunken);
	insertLegend(legend, QwtPlot::TopLegend);

	for (auto const & m : target->molecules_types)
	{
		std::string name = "Molecule " + std::to_string(m.id);
		QwtPlotCurve *curve = new QwtPlotCurve(name.c_str());

		auto data = new QwtPointSeriesData;
		QVector<QPointF> pts;
		pts.push_back(QPointF(0.0, m.popinit));
		data->setSamples(pts);
		curve->setPen(QPen(m.color));
		curve->setData(data);
		curve->attach(this);
		m_data.push_back(data);
	}

	QwtPlotPicker* plotPicker = new QwtPlotPicker(this->xBottom, this->yLeft, QwtPicker::CrossRubberBand, QwtPicker::AlwaysOn, this->canvas());
	QwtPickerMachine* pickerMachine = new QwtPickerClickPointMachine();
	plotPicker->setStateMachine(pickerMachine);
	connect(plotPicker, SIGNAL(selected(const QPointF&)), this, SLOT(onSelected(const QPointF&)));
}

void molecule_plot::update(double const elapsed)
{
	if(elapsed > 5000)
	{
		setAxisScale(QwtPlot::xBottom, 0, elapsed);
	}
	for (size_t i = 0; i < target->molecules_types.size(); ++i)
	{
		double n = std::accumulate
		(
			target->molecules.cbegin(),
			target->molecules.cend(),
			0,
			[&](int const cpt, molecule const & m)
			{
				if(m.type == i) {return cpt+1;}
				return cpt;
			}
		);
		QVector<QPointF> pts = m_data[i]->samples();
		pts.push_back(QPointF(elapsed, n));
		m_data[i]->setSamples(pts);
	}
}
