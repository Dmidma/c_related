#include <spl/gwindow.h>

int main(void)
{
    GWindow window = newGWindow(320, 240);
    
    pause(5000);
    
    closeGWindow(window);
    
    return 0;
}
