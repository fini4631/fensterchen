#define _USE_MATH_DEFINES

#include <iostream>
#include "Circle.hpp"
#include "point2D.hpp"
#include "color.hpp"
#include <cmath>

Circle::Circle() :
color_{Color()},
center_{point2D()},
radius_(0.1) {}

Circle::Circle(point2D const& center) :
color_{Color()},
center_{center},
radius_(0.1) {}

Circle::Circle(point2D const& center, double const& radius) :
color_{Color()},
center_{center},
radius_(radius) {}

Circle::Circle(point2D const& center, double const& radius, Color const& color) :
color_{color},
center_{center},
radius_(radius) {}

Circle::~Circle()
{
	std::cout << "Kreis wurde zerstoert" << std::endl;
}

void Circle::center(point2D const& center)
{
	center_ = center;
}
point2D Circle::center()
{
	return center_;
}
void Circle::radius(double const& radius)
{
	radius_ = radius;
}
double Circle::radius()
{
	return radius_;
}
void Circle::color(Color const& color)
{
	color_ = color;
}
Color Circle::color()
{
	return color_;
}

void Circle::draw(Window & win)
{
	point2D p1(center_.x(), center_.y() + radius_);
	point2D p2(0,0);
	for (int i = 1; i <= 360; i++)
	{
		p2 = p1;
		p2.translate(-center_.x(), -center_.y());
		p2.rotate((2 * M_PI) / 360);
		p2.translate(center_.x(), center_.y());
		win.drawLine(p2.x(), p2.y(), p1.x(), p1.y(), color_.r_, color_.g_, color_.b_);
		p1 = p2;
	}
}
void Circle::draw(Window & win, Color const& color)
{
	point2D p1(center_.x(), center_.y() + radius_);
	point2D p2(0, 0);
	for (int i = 1; i <= 360; i++)
	{
		p2 = p1;
		p2.translate(-center_.x(), -center_.y());
		p2.rotate((2 * M_PI) / 360);
		p2.translate(center_.x(), center_.y());
		win.drawLine(p2.x(), p2.y(), p1.x(), p1.y(), color.r_, color.g_, color.b_);
		p1 = p2;
	}
}
double Circle::circumference()
{
	return 2 * M_PI *radius_;
}

bool Circle::is_inside(double const& x, double const& y)
{
	return (sqrt(pow(center_.x() - x, 2) + pow(center_.y() - y, 2)) <= radius_);
}