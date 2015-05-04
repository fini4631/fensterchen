#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include "Rectangle.hpp"
#include "point2D.hpp"
#include "color.hpp"
#include "window.hpp"

rectangle::rectangle() :
lmup_{point2D()},
color_{Color()},
x_(0.1),
y_(0.1) {}

rectangle::rectangle(point2D const& point) :
lmup_{point},
color_{ Color() },
x_(0.1),
y_(0.1) {}

rectangle::rectangle(point2D const& point,Color const& color) :
lmup_{point},
color_{color},
x_(0.1),
y_(0.1) {}

rectangle::rectangle(point2D const& point, double const& x, double const& y) :
lmup_{point},
color_{Color()},
x_(x),
y_(y) {}

rectangle::rectangle(point2D const& point, double const& x, double const& y, Color const& color) :
lmup_{point},
color_{color},
x_(x),
y_(y) {}

rectangle::~rectangle()
{
	std::cout << "Rectangle zerstoert" << std::endl;
}

void rectangle::color(Color const& color)
{
	color_ = color;
}

Color rectangle::color()
{
	return color_;
}
void rectangle::left_upper_point(point2D const& point)
{
	lmup_ = point;
}
point2D rectangle::left_upper_point()
{
	return lmup_;
}
void rectangle::length_x(double const& x)
{
	x_ = x;
}
void rectangle::length_y(double const& y)
{
	y_ = y;
}
double rectangle::length_x()
{
	return x_;
}
double rectangle::length_y()
{
	return y_;
}

void rectangle::draw(Window & win)
{
	point2D p1(lmup_);
	point2D p2(p1.x(), p1.y() - y_);
	point2D p3(p1.x() + x_, p1.y());
	point2D p4(p3.x(), p2.y());
	win.drawLine(p1.x(), p1.y(), p2.x(), p2.y(), color_.r_, color_.g_, color_.b_);
	win.drawLine(p1.x(), p1.y(), p3.x(), p3.y(), color_.r_, color_.g_, color_.b_);
	win.drawLine(p2.x(), p2.y(), p4.x(), p4.y(), color_.r_, color_.g_, color_.b_);
	win.drawLine(p3.x(), p3.y(), p4.x(), p4.y(), color_.r_, color_.g_, color_.b_);
}
void rectangle::draw(Window & win, Color const& color)
{
	point2D p1(lmup_);
	point2D p2(p1.x(), p1.y() - y_);
	point2D p3(p1.x() + x_, p1.y());
	point2D p4(p3.x(), p2.y());
	win.drawLine(p1.x(), p1.y(), p2.x(), p2.y(), color.r_, color.g_, color.b_);
	win.drawLine(p1.x(), p1.y(), p3.x(), p3.y(), color.r_, color.g_, color.b_);
	win.drawLine(p2.x(), p2.y(), p4.x(), p4.y(), color.r_, color.g_, color.b_);
	win.drawLine(p3.x(), p3.y(), p4.x(), p4.y(), color.r_, color.g_, color.b_);
}

double rectangle::circumference()
{
	return 2 * x_ + 2 * y_;
}

bool rectangle::is_inside(double const& x, double const& y)
{
	point2D p1(lmup_);
	point2D p2(p1.x() + x_, p1.y() - y_);
	if ((x >= p1.x() && x <= p2.x()) && (y <= p1.y() && y >= p2.y()))
		return true;
	else
		return false;
}