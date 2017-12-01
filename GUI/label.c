#include <ctype.h>

#include <spl/gobjects.h>
#include <spl/gwindow.h>
#include <spl/gevents.h>


int main(void)
{
	GWindow window = newGWindow(320, 240);

	GLabel label = newGLabel("");

	setFont(label, "SansSerif-36");
	//add(window, label);


	GLabel label2 = newGLabel("Hello");
	setFont(label2, "SansSerif-36");
	add(window, label2);
	setLocation(label2,100 ,100);

	char* size[] = {"SansSerif-40", "SansSerif-42", "SansSerif-44", "SansSerif-46", "SansSerif-48","SansSerif-50"};

	while (true)
	{
		for (int i = 0; i < 6; i++)
		{
			setFont(label2, size[i]);
			pause(50);
			add(window, label2);
		}

		for (int i = 5; i >= 0; i--)
		{
			setFont(label2, size[i]);
			pause(50);
			add(window, label2);
		}
	}

	

	for (int i = 50; i >= 0; i--)
	{
		char s[3];

		sprintf(s, "%i", i);

		setLabel(label, s);

		double x = (getWidth(window) - getWidth(label)) / 2;
		double y = (getHeight(window) - getHeight(label)) / 2;
		setLocation(label, x, y);

		pause(100);
	}

	// wait for click before closing the window
	waitForClick();

	closeGWindow(window);
	return 0;
}