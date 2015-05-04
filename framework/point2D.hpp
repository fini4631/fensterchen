#ifndef BUW_POINT2D_HPP
#define BUW_POINT2D_HPP

#include "window.hpp"
#include "color.hpp"

class point2D
{
public:
	point2D(); // Default Konstructor
	point2D(double const& x, double const& y); // Konstructor mit Parameter
	~point2D(); // Detructor

	void x(double const& x); // setzt x
	void y(double const& y); // setzt y
	double x(); // gibt x
	double y(); // gibt y

	void translate(double const& x, double const& y); // verändert psition
	void rotate(double  const& r); // rotiert Punkt um den Punkt (0,0)

private:
	double x_;
	double y_;
};


#endif