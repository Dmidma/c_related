#include <stdio.h>
#include <string.h>

#include <spl/gevents.h>
#include <spl/gwindow.h>
#include <spl/ginteractors.h>

int main(void)
{
	GWindow window = newGWindow(320, 240);

	GButton button = newGButton("Button");
	setActionCommand(button, "click");

	addToRegion(window, button, "SOUTH");

	while (true)
	{
		GActionEvent event = waitForEvent(ACTION_EVENT);

		if (getEventType(event) == WINDOW_CLOSED)
		{
			break;
		}

		if (strcmp(getActionCommand(event), "click") == 0)
		{
			printf("button was clicked\n");
		}
	}

	closeGWindow(window);
	return 0;
}
