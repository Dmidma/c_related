#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototypes
const char* lookup(const char* extension);
void aName(void);

int main(void)
{
	const char* wasup = lookup("csS");

	printf("%s\n", wasup);
	aName();

	return 0;
}

const char* lookup(const char* extension)
{       
    char inter[strlen(extension) + 1];
    for (int i = 0, n = strlen(extension); i < n; i++)
    {
    	inter[i] = tolower(extension[i]);
    }
    inter[strlen(extension)] = '\0';

    if (strcmp("css", inter) == 0)
    {
    	return "text/css";
    }
    else if (strcmp("html", inter) == 0)
    {
    	return "text/html";
    }
    else if (strcmp("gif", inter) == 0)
    {
    	return "image/gif";
    }
    else if (strcmp("ico", inter) == 0)
    {
    	return "image/x-icon";
    }
    else if (strcmp("jpg", inter) == 0)
    {
    	return "image/jpeg";
    }
    else if (strcmp("js", inter) == 0)
    {
    	return "text/javascript";
    }
    else if (strcmp("png", inter) == 0)
    {	
    	return "text/javascript";
    }

    return NULL;
}




/**
	Juste saving it for now.
*/
void aName(void)
{
	char* request_target = "/hello.html";
	int requestLength = strlen(request_target);
	
	// finding the index of '?'
	int wantedIndex = -1;
	for (int i = 0; i < requestLength; i++)
	{
		if (request_target[i] == '?')
		{
			wantedIndex = i;
			break;
		}
	}

	int pathLength;
	int queryLength;
	// no '?' in the request_target'
	if (wantedIndex == -1)
	{	
		pathLength = requestLength + 1;
		queryLength = 0;
	}
	// '?' is the last charcter in the request_target
	else if (wantedIndex == (requestLength - 1))
	{
		pathLength = requestLength;
		queryLength = 0;
	}
	// '?' somewhere in the middle
	else	
	{
		pathLength = wantedIndex + 1; 
		queryLength = requestLength - wantedIndex + 1;
	}

	char path[pathLength];
	char query[queryLength];
	// if the request_target does not contain a '?'
	if (wantedIndex == -1)
    {   
    /*
        int i = 0;
        for (; i < requestLength; i ++)
        {
            path[i] = request_target[i];
        }
        path[i] = '\0';
        i = 0;
     */
     strcpy(path, request_target);
     strcpy(query, "Alouch");
	}
	// if the '?' is the last character in request_target
	else if (wantedIndex == (requestLength - 1))
	{
		strncpy(path, request_target, requestLength);
		path[pathLength - 1] = '\0';
		strcpy(query, "");
	}
	else
	{
		strncpy(path, request_target, wantedIndex);
		path[pathLength - 1] = '\0';
		int j = 0;
		for (int i = wantedIndex + 1; i < requestLength; i++)
		{
			query[j] = request_target[i];
			j++;
		}
		query[j] = '\0';
	}

	printf("%s\n", path);
	printf("%s\n", query);
}
