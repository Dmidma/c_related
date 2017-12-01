#include <stdio.h>
#include <string.h>

#include <spl/gwindow.h>
#include <spl/gevents.h>
#include <spl/ginteractors.h>


int main(void)
{
	GWindow window = newGWindow(320, 240);

	GCheckBox checkbox = newGCheckBox("I agree");
	setActionCommand(checkbox, "check");

	addToRegion(window, checkbox, "SOUTH");

	while (true)
	{
		GActionEvent event = waitForEvent(ACTION_EVENT);

		if (getEventType(event) == WINDOW_CLOSED)
		{
			break;
		}

		if (strcmp(getActionCommand(event), "check") == 0)
		{
			if (isSelected(checkbox))
			{
				printf("checkbox was checked\n");
			}
			else
			{
				printf("checkbox was unchecked\n");	
			}
		}
	}

	closeGWindow(window);
	return 0;
}