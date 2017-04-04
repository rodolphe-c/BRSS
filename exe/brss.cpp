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
#include <QFileDialog>

#include "brss/brss.hpp"
#include "../src/main_window.hpp"

int main( int argc, char** argv )
{
	QApplication application( argc, argv );
	application.setAttribute(Qt::AA_EnableHighDpiScaling);
	application.setApplicationName(QApplication::tr("BRSS"));
	application.setOrganizationName("BRSS");
	application.setOrganizationDomain("https://github.com/rodolphe-c/BRSS");
	application.setApplicationVersion(QString::fromStdString(brss::version()));

	if (application.arguments().count() > 1)
	{
		main_window window (application.arguments().at(1).toStdString());

		window.setWindowTitle("BRSS");
		window.setWindowIcon(QIcon(":/img/brss128.png"));
		window.show();

		return(application.exec());
	}
	else
	{
		auto fileName = QFileDialog::getOpenFileName
		(
			nullptr, QObject::tr("Sélectionner un programme"),
			QDir::currentPath(), QObject::tr("Programme (*.mcl)")
		);

		main_window window (fileName.toStdString());
		window.setWindowTitle("BRSS");
		window.setWindowIcon(QIcon(":/img/brss128.png"));
		window.show();

		return( application.exec() );
	}
}
