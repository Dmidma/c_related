#include <stdio.h>
#include <string.h>

#include <spl/gevents.h>
#include <spl/ginteractors.h>
#include <spl/gwindow.h>


int main(void)
{
    GWindow window = newGWindow(320, 240);
    
    GTextField field = newGTextField(10);
    setActionCommand(field, "input");
    addToRegion(window, field, "SOUTH");
    
    while (true)
    {
        GActionEvent event = waitForEvent(ACTION_EVENT);
        
        if (getEventType(event) == WINDOW_CLOSED)
        {
            break;
        }
        
        if (strcmp(getActionCommand(event), "input") == 0)
        {
            printf("%s was inputted\n", getText(field));
        }
    }
    
    return 0;
}
