#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>

#include <QMainWindow>
#include <QTimer>

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
	void drawPlot();

private:
	Ui::main_window *ui;
	QTimer timer;
	std::thread t;
	QVector<double> x, y;
	double cpt;
};

#endif // MAIN_WINDOW_HPP
