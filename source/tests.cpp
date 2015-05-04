#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES

#include <catch.hpp>
#include <cmath>

#include "point2D.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

TEST_CASE("point2D()", "[]")
{
	point2D point{};
	REQUIRE(point.x() == Approx(0.0));
	REQUIRE(point.y() == Approx(0.0));
}

TEST_CASE("point2D", "[]")
{
	point2D point{ 0.3, 0.1 };
	REQUIRE(point.x() == Approx(0.3));
	REQUIRE(point.y() == Approx(0.1));
}

TEST_CASE("point2D - traslate", "[]")
{
	point2D point{ 0.1, 0.1 };
	point.translate(0.4, -0.2);
	REQUIRE(point.x() == Approx(0.5));
	REQUIRE(point.y() == Approx(-0.1));
}
TEST_CASE("point2D - rotate", "[]")
{
	point2D point{ 0.5, 0.5 };
	point.rotate(2 * M_PI);
	REQUIRE(point.x() == Approx(0.5));
	REQUIRE(point.y() == Approx(0.5));
}

TEST_CASE("Circle()", "[]")
{
	Circle circ{};
	point2D point{ circ.center() };
	Color col{ circ.color() };
	REQUIRE(point.x() == Approx(0.0));
	REQUIRE(point.y() == Approx(0.0));
	REQUIRE(col.r_ == Approx(0.0));
	REQUIRE(col.g_ == Approx(0.0));
	REQUIRE(col.b_ == Approx(0.0));
	REQUIRE(circ.radius() == Approx(0.1));
}

TEST_CASE("Circle - is_inside", "[]")
{
	Circle circ{};
	REQUIRE(circ.is_inside(0.5, 0.5) == false);
	REQUIRE(circ.is_inside(0.0, 0.0) == true);
}

TEST_CASE("Circle - circumference", "[]")
{
	Circle circ{};
	circ.radius(0.3);
	REQUIRE(circ.circumference() == Approx(1.8849555922));
}

TEST_CASE("Rectangle()", "[]")
{
	rectangle rec{};
	point2D point{ rec.left_upper_point() };
	Color col{ rec.color() };
	REQUIRE(point.x() == Approx(0.0));
	REQUIRE(point.y() == Approx(0.0));
	REQUIRE(col.r_ == Approx(0.0));
	REQUIRE(col.g_ == Approx(0.0));
	REQUIRE(col.b_ == Approx(0.0));
	REQUIRE(rec.length_x() == Approx(0.1));
	REQUIRE(rec.length_y() == Approx(0.1));
}

TEST_CASE("Rectangle - is_inside", "[]")
{
	rectangle rec{};
	REQUIRE(rec.is_inside(0.9, 0.9) == false);
	REQUIRE(rec.is_inside(0.1, 0.0) == true);
}
TEST_CASE("Rectangle - circumference", "[]")
{
	rectangle rec{};
	REQUIRE(rec.circumference() == Approx(0.4));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
