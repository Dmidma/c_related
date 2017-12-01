#define _XOPEN_SOURCE
#include <stdlib.h>

#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>
#include <time.h>

#define LIMIT 3

int main(void)
{
	GWindow window = newGWindow(400, 600);

	GOval circle = newGOval(0, 110, 20, 20);
	setColor(circle, "BLACK");
	setFilled(circle, true);
	add(window, circle);

	srand48((long int) time(NULL));

	double v = drand48() * LIMIT;
	while (v == 0.0)
	{
		v = drand48() * LIMIT;
	}

	double xVelocity = v;
	double yVelocity = LIMIT;

	while (true)
	{
		move(circle, xVelocity, yVelocity);
		pause(10);

		if (getX(circle) + getWidth(circle) >= getWidth(window))
		{
			xVelocity = -xVelocity;
		}
		else if (getX(circle) <= 0)
		{
			xVelocity = -xVelocity;
		}

		if (getY(circle) + getWidth(circle) >= getHeight(window))
		{
			yVelocity = -yVelocity;
		}
		else if (getY(circle) <= 0)
		{
			yVelocity = -yVelocity;
		}
	}
}