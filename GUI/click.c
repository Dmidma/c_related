#include <spl/gwindow.h>
#include <spl/gevents.h>


int main(void)
{
	GWindow window = newGWindow(320, 240);

	while (true)
	{
		GEvent event = getNextEvent(MOUSE_EVENT);

		if (event != NULL)
		{
			if (getEventType(event) == MOUSE_CLICKED)
			{
				printf("%.0f, %0.f\n", getX(event), getY(event));
			}
		}
	}

	closeGWindow(window);
}