#ifndef BUW_RECTANGLE_HPP
#define BW_RECTANGLE_HPP

#include "point2D.hpp"
#include "color.hpp"
#include "window.hpp"

class rectangle
{
public:
	rectangle(); // Default Konstrucktor
	rectangle(point2D const& point);
	rectangle(point2D const& point, Color const& color);
	rectangle(point2D const& point, double const& x, double const& y);
	rectangle(point2D const& point, double const& x, double const& y, Color const& color);
	~rectangle(); // Destrucktor

	void color(Color const& color); // setzt Farbe
	Color color(); // gibt Farbe

	void left_upper_point(point2D const& point);
	point2D left_upper_point();

	void length_x(double const& x); // setzt Länge y
	void length_y(double const& y); // setzt Länge y
	double length_x(); // gibt Länge x
	double length_y(); // gibt Länge y

	void draw(Window & win);
	void draw(Window & win, Color const& color);

	double circumference();
	bool is_inside(double const& x, double const& y); //Prüfung, Mauszeiger innerhalb

private:
	point2D lmup_;
	Color color_;
	double x_;
	double y_;

};


#endif 
