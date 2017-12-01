#include <spl/gevents.h>
#include <spl/gwindow.h>
#include <spl/gobjects.h>


int main(void)
{
	GWindow window = newGWindow(320, 240);

	GOval circle = newGOval(0, 0, 50, 50);

	add(window, circle);

	while (true)
	{
		GEvent event = getNextEvent(MOUSE_EVENT);

		if (event != NULL)
		{
			if (getEventType(event) == MOUSE_MOVED)
			{
				double x = getX(event) - getWidth(circle) / 2;
				double y = getY(event) - getWidth(circle);
				setLocation(circle, x, y);
			}
		}
	}
}