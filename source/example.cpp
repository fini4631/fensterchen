#include <fensterchen.hpp>

int main(int argc, char* argv[])
{
  Window win(glm::ivec2(800,800));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

    auto t = win.getTime();
	auto m = win.mousePosition();
    /*
	float x1(0.5 + 0.5 * std::sin(t));
    float y1(0.5 + 0.5 * std::cos(t));

    float x2(0.5 + 0.5 * std::sin(2.0*t));
    float y2(0.5 + 0.5 * std::cos(2.0*t));

    float x3(0.5 + 0.5 * std::sin(t-10.f));
    float y3(0.5 + 0.5 * std::cos(t-10.f));

    win.drawPoint(x1, y1, 1.0, 0.0, 0.0);
    win.drawPoint(x2, y2, 0.0, 1.0, 0.0);
    win.drawPoint(x3, y3, 0.0, 0.0, 1.0);

    auto m = win.mousePosition();
    win.drawLine(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.drawLine(0.0f, m.y, 0.01f, m.y, 0.0, 0.0, 0.0);
    win.drawLine(0.99f, m.y,1.0f, m.y, 0.0, 0.0, 0.0);

    win.drawLine(m.x, 0.0f, m.x, 0.01f, 0.0, 0.0, 0.0);
    win.drawLine(m.x, 0.99f,m.x, 1.0f, 0.0, 0.0, 0.0);
	*/

	point2D p(0.5,0.5);
	point2D p2(0.2, 0.6);
	point2D p3(0.7, 0.6);

	Color blue(0.0, 0.0, 1.0);
	Color red(1.0, 0.0, 0.0);
	Color green(0.0, 0.6, 0.4);
	Color black(0.0, 0.0, 0.0);
	Color (0.0, 1.0, 0.0);

	Circle c(p,0.2,green);
	Circle c2(p2, 0.1, red);

	c.draw(win);
	c2.draw(win);

	rectangle r(p2, 0.3, 0.2, black);
	rectangle r2(p3, 0.2, 0.5, Color(0.0, 1.0, 0.0));
	r.draw(win);
	r2.draw(win);

	if (c2.is_inside(m.x, m.y))
	{
		c2.draw(win, blue);
	}
	if (r.is_inside(m.x, m.y))
	{
		r.draw(win, blue);
	}
	if (c.is_inside(m.x, m.y))
	{
		c.draw(win, blue);
	}
	if (r2.is_inside(m.x, m.y))
	{
		r2.draw(win, blue);
	}


    win.update();
  }

  return 0;
}
