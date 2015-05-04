
#include "point2D.hpp"
#include <iostream>

point2D::point2D(): 
x_(0), 
y_(0)
{}

point2D::point2D(double const& x, double const& y):
x_(x),
y_(y)
{}

point2D::~point2D()
{
	std::cout << "Punkt wurde zerstoert" << std::endl;
}

void point2D::x(double const& x) {x_ = x;}
void point2D::y(double const& y) {y_ = y;}

double point2D::x() {return x_;}
double point2D::y() {return y_;}

void point2D::translate(double const& x, double const& y)
{
	x_ += x;
	y_ += y;
}

void point2D::rotate(double const& r)
{
	double xtemp, ytemp;		
	xtemp = x_;
	ytemp = y_;
	x_ = xtemp * cos(r) - ytemp * sin(r);
	y_ = xtemp * sin(r) + ytemp * cos(r);
}

