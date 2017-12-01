#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// prototypes
const char* requestVerif(const char* request_line);
const char* pathQuery(const char* request_target);
const char* pathExtension(const char* path);

int main(void)
{

	printf("%s", pathQuery("/where.php?fuckthisprogrammingstuff"));
	printf("%s", pathExtension("/9atoussfichkara.jpeg"));
	//printf("%s\n", lookup("HTML"));

	return 0;
}


const char* requestVerif(const char* request_line)
{

	// number of spaces must not exceed 2
	int nbrSpaces = 0;
	for (int i = 0, n = strlen(request_line); i < n; i++)
	{
		if (request_line[i] == ' ')
		{
			nbrSpaces++;
		}
		
		if (nbrSpaces > 2)
		{
			return "400 Bad Request\n";
		}
	}
	
	// sotring Method, request-target, and HTP-version
	char* requElems[3];

	char* token;
	char* str1;

	char toParse[strlen(request_line)];
	strcpy(toParse, request_line);
	toParse[strlen(request_line)] = '\0';

  	int j;
  	for (j = 1, str1 = toParse; ; j++, str1 = NULL)
  	{
    	token = strtok(str1, " ");
    	if (token == NULL)
      	break;	

      	requElems[j - 1] = malloc(sizeof(char) * strlen(token));
		strcpy(requElems[j - 1], token);
		requElems[j - 1][strlen(token)] = '\0';
  	}

  	// checking the CRLF
  	char CRLF[3];
  	CRLF[2] = '\0';
  	CRLF[1] = requElems[2][strlen(requElems[2]) - 1];
  	CRLF[0] = requElems[2][strlen(requElems[2]) - 2];
  	if (strcmp(CRLF, "\r\n") != 0)
  	{
    	return "400 Bad Request\n";
  	}

  	// checking the method
  	if (strcmp(requElems[0], "GET") != 0)
  	{
  		return "405 Method Not Allowed\n";
  	}

  	// request-target must start with '/'
  	if (requElems[1][0] != '/')
  	{
  		return "501 Not Implemented\n";
  	}

  	// request-target must not contains a "
  	if (strchr(requElems[1], '"') != NULL)
  	{
  		return "400 Bad Request\n";
  	}

  	if (strchr(requElems[1], '.') == NULL)
  	{
  		return "501 Not Implemented\n";
  	}

  	// checking HTTP-version
  	if (strncmp(requElems[2], "HTTP/1.1", 8) != 0)
  	{
  		return "505 HTTP Version Not Supported\n";
  	}

  	return "Fine\n";
}



const char* pathQuery(const char* request_target)
{
	// save the index of the first occurence of '?'
	int fOcc = 0;
	int n = strlen(request_target);
	for (int i = 0; i < n; i++)
	{
		if (request_target[i] == '?')
		{
			fOcc = i;
			break;
		}	
	}

	// copying only the sub-string from 0 to first occurence of '?'
	char path[fOcc];
	strncpy(path, request_target, fOcc);
	path[fOcc] = '\0';


	// copying the rest of the string 
	char* query;
	if ((n - fOcc) == 1)
	{
		query = "";
	}
	else
	{	
		query = malloc(sizeof(char) * (n - fOcc));
		for (int i = fOcc; i < n - 1; i++)
		{
			query[i - fOcc] = request_target[i + 1];
		}
		query[n - fOcc] = '\0';	
	}
	
	printf("%s\n%s", path, query);

	free(query);

	return "\n";
}


const char* pathExtension(const char* path)
{

	// iteration index
	int i;

	int n = strlen(path);
	int fOcc = 0;
	for (i = 0; i < n; i++)
	{
		if (path[i] == '.')
		{
			fOcc = i;
			break;
		}
	}

	char* extension = malloc(sizeof(char) * (n - fOcc));
	for (i = fOcc; i < n - 1; i++)
	{

		extension[i - fOcc] = path[i + 1];
	}
	extension[n - fOcc] = '\0';


	printf("%s", extension);


	free(extension);

	return "\n";
}