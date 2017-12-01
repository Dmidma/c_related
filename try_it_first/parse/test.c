#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>

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
    // all to lowercase, just in case   
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
    char* root = "/home/jharvard/Dropbox";
    int rootLength = strlen(root);
	


	char* request_target = "/lool.html?q=WhatsUp";
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
		pathLength = rootLength + requestLength + 1;
		queryLength = 1;
	}
	// '?' is the last charcter in the request_target
	else if (wantedIndex == (requestLength - 1))
	{
		pathLength = rootLength + requestLength;
		queryLength = 1;
	}
	// '?' somewhere in the middle
	else	
	{
		pathLength = rootLength + wantedIndex + 1; 
		queryLength = requestLength - wantedIndex + 1;
	}

	char path[pathLength];
	char query[queryLength];
	
	// first thing first, copying the root to path
	int i = 0;
    for(; i < rootLength; i++)
    {
        path[i] = root[i];
    }
	
	// if the request_target does not contain a '?'
	if (wantedIndex == -1)
    {   
        for (int j = 0; j < requestLength; j++)
        {
            path[i] = request_target[j];
            i++;
        }
        path[pathLength - 1] = '\0';
        strcpy(query, "\0");
        
	}
	// if the '?' is the last character in request_target
	else if (wantedIndex == (requestLength - 1))
	{
		for (int j = 0; j < (requestLength - 1); j++)
		{
		    path[i] = request_target[j];
		    i++;
		}
		path[pathLength - 1] = '\0';
		strcpy(query, "\0");
	}
	else
	{   
	    for (int j = 0; j < wantedIndex; j++)
		{
		    path[i] = request_target[j];
		    i++;
		}
		path[pathLength - 1] = '\0';
		int j = 0;
		for (int i = wantedIndex + 1; i < requestLength; i++)
		{
			query[j] = request_target[i];
			j++;
		}
		query[j] = '\0';
	}
    
    struct stat* buf = malloc(sizeof(struct stat));
    
    if (stat(path, buf) == -1)
    {
        printf("404 Not Found\n");
    }
    else
    {
        free(buf);        
        printf("!GOOOOOD!\n");
        if (access(path, R_OK) == 0)
        {
            printf("!GOOOOOD!\n");
        }
        else
        {
            printf("403 Forbidden\n");
        }
    }
    
    
    // extension part =D
    int periodIndex = -1;
    for (int k = 0; k < pathLength; k++)
    {
        if (path[k] == '.')
        {
            periodIndex = k;
            break;
        }
    }
    int extensionLength = 0;
    if (periodIndex == -1)
    {
        printf("501 Not Implemented\n");
    }
    else
    {
        extensionLength = pathLength - periodIndex;
    }
    
    char extension[extensionLength];
    
    for (int k = periodIndex + 1, i = 0; k < pathLength; k++)
    {
        extension[i] = path[k];
        i++;
    }
    extension[extensionLength - 1] = '\0';
    
    printf("%s\n", extension);
    
    
    
    /*
	printf("%s\n", path);
	printf("%s\n", query);
	*/
}
