#include "circle.hpp"

circle::print()
{
	w.clear();
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		w.draw(x0 + x, y0 + y);
		w.draw(x0 + y, y0 + x);
		w.draw(x0 - y, y0 + x);
		w.draw(x0 - x, y0 + y);
		w.draw(x0 - x, y0 - y);
		w.draw(x0 - y, y0 - x);
		w.draw(x0 + y, y0 - x);
		w.draw(x0 + x, y0 - y);

		if (err <= 0)
		{
			y += 1;
			err += 2*y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2*x + 1;
		}
	}
}
