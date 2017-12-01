#include <stdio.h>
#include <string.h>

#include <spl/gevents.h>
#include <spl/ginteractors.h>
#include <spl/gwindow.h>

int main(void)
{
	GWindow window = newGWindow(320, 240);

	GLabel left = newGLabel("0");
	addToRegion(window, left, "SOUTH");

	GSlider slider = newGSlider(0, 100, 50);
	setActionCommand(slider, "slide");
	addToRegion(window, slider, "SOUTH");

	GLabel right = newGLabel("100");
	addToRegion(window, right, "SOUTH");

	while (true)
	{
		GActionEvent event = waitForEvent(ACTION_EVENT);
		if (getEventType(event) == WINDOW_CLOSED)
		{
			break;
		}

		if (strcmp(getActionCommand(event), "slide") == 0)
		{
			printf("Slider was slid to %i\n", getValue(slider));
		}
	}

	closeGWindow(window);
	return 0;
}