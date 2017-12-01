#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>

// prototypes
void aName(void);

int main(void)
{
    aName();
    return 0;
}
void aName(void)
{   
    char* path = "/home/jharvard/Dropbox/lool.html";
    //int rootLength = strlen(path);

    struct stat buf;

    if (stat(path, &buf) == -1)
    {
        printf("404 Not Found\n");
    }
    else
    {   
        printf("!File does Exist!\n");
        if (access(path, R_OK) == 0)
        {
            printf("!File is readble!\n");
        }
        else
        {
            printf("403 Forbidden\n");
        }
    }
}