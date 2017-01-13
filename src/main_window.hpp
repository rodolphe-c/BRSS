#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
	class main_window;
}

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	explicit main_window(QWidget *parent = 0);
	~main_window();

public slots:
	void draw();

private:
	Ui::main_window *ui;
	QVector<double> x, y;
	double cpt;

	//update loop
	QTime time;
	double lastElapsed = 0;
};

#endif // MAIN_WINDOW_HPP
