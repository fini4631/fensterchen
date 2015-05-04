#ifndef BUW_CIRCLE_HPP
#define BUW_CIRCLE_HPP

#include "color.hpp"
#include "point2D.hpp"
#include "window.hpp"

class Circle {

private:
	Color color_;
	point2D center_;
	double radius_;

public:
	Circle(); // Default Konstructor
	Circle(point2D const & center); 
	Circle(point2D const& center, double const& radius);
	Circle(point2D const& center, double const& radius, Color const& color);
	~Circle(); // Destructor

	void center(point2D const& center); //setzt Mittelpunkt
	point2D center(); // gibt Mittelpunkt

	void radius(double const& radius); // setzt radius
	double radius(); // gibt radius

	void draw(Window & win); // zeichnet Kreis
	void draw(Window & win, Color const& color);

	double circumference();

	bool is_inside(double const& x, double const& y); //Prüfung, Mauszeiger innerhalb

	void color(Color const& color); // setzt Farbe
	Color color(); // gibt Farbe
};

#endif