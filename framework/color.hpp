#ifndef BUW_COLOR_HPP
#define BUW_COLOR_HPP

struct Color
{
	double r_;
	double g_;
	double b_;


	Color(double const& x) : 
		r_(x),
		g_(x),
		b_(x) {}


	Color(double const& r, double const& g, double const& b) :
		r_(r),
		g_(g),
		b_(b) {}

	Color() :
		r_(0),
		g_(0),
		b_(0) {}
};
#endif