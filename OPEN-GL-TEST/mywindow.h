/*
 * mywindow.h
 *
 *  Created on: 11 ����. 2021 �.
 *      Author: ����� ������
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

class mywindow: public Window {
protected:
	double seconds{0.0};
	double hours {0.0};
	double minutes {0.0};
	void draw_clock();

public:

	static constexpr int WINDOW_WIDTH=1024;
	static constexpr int WINDOW_HEIGHT=720;

	virtual void render();
	virtual void setupGL();
	virtual void update();

public:
	mywindow();
	virtual ~mywindow() = default;
};

#endif /* MYWINDOW_H_ */
