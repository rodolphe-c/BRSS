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


#include <QApplication>
#include <QMainWindow>

#include "test.hpp"

#include "../src/osg_widget.hpp"

int main( int argc, char** argv )
{
	version();

	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication application( argc, argv );
	QMainWindow window;

	osg_widget* widget = new osg_widget(2,2);

	window.setWindowTitle("BRSS");
	window.setCentralWidget(widget);
	window.show();

	return( application.exec() );
}
