#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


// definition of a node
typedef struct node
{
	bool isWord;
	char value;
	struct node* next;
	struct node* child;
}node;

unsigned int wordsNbr = 0;
bool toCheck = true;

// prototypes
node* add_to_list(node** list, char value);
void remove_all_list(node* list);
unsigned int size(void);
node* followIt(node* dic, node* toFollow);
node* nodeToFree(node* dic);
bool check(node* dic, char* word);
node* findNodeInRow(char alpha, node* dic);
bool unload(node* dic);




int main(void)
{
	FILE* dicFile = fopen("large", "r");
	if (dicFile == NULL)
	{
		printf("Could not open file.\n");
		return 1;
	}

	// head of dictionary
	node* dic = NULL;

	// keep track of the last modification
	node* cursor; 

	int c = fgetc(dicFile);
	// first character in the dictionary
	cursor = add_to_list(&dic, c);

	bool newWord = false;

	// iterate over the rest
	for (c = fgetc(dicFile); c != EOF; c = fgetc(dicFile))
	{
		
		if (c == '\n')
		{
			cursor->isWord = true;
			wordsNbr++;
			cursor = dic;
			newWord = true;
		}
		else
		{	
			if (newWord)
			{
				cursor = add_to_list(&dic, c);
				newWord = false;
			}
			else
			{
				cursor = add_to_list(&(cursor->child), c);
			}
		}
	}

	printf("%d\n", size());

	unload(dic);

	fclose(dicFile);
}




/**
 * add_to_list() adds @param value to @param list keeping the list sorted.
 * It links element to the next node and child node.
 */
node* add_to_list(node** list, char value)
{
	
	
	// list is empty
	if (*list == NULL)
	{
		
		// create a node and give it the value
		node* elem = malloc(sizeof(node));
		if (elem == NULL)
		{
			printf("Unable to create node\n");
			return NULL;
		}
		elem->isWord = false;
		elem->value = value;
		elem->next = NULL;
		elem->child = NULL;


		// set the list to point to the created element
		*list = elem;

		return elem;
	}
	else
	{
		
		// inserting at the head of the list
		if ((*list)->value > value)
		{
			
			// create a node and give it the value
			node* elem = malloc(sizeof(node));
			if (elem == NULL)
			{
				printf("Unable to create node\n");
				return NULL;
			}
			elem->isWord = false;
			elem->value = value;
			elem->next = NULL;
			elem->child = NULL;




			elem->next = *list;
			*list = elem;

			return elem;
		}

		// inserting at the middle/end 
		else
		{
			// trackers of list
			node* follo = *list;
			node* prev = *list;
			
			// find the right place to insert the new node
			while (follo != NULL && follo->value <= value)
			{
				// exit when finding occurence
				if (follo->value == value)
				{
					return follo;
				}
				
				follo = follo->next;
			}
			while (prev->next != follo)
			{
				prev = prev->next;
			}

			// create a node and give it the value
			node* elem = malloc(sizeof(node));
			if (elem == NULL)
			{
				printf("Unable to create node\n");
				return NULL;
			}
			elem->isWord = false;
			elem->value = value;
			elem->next = NULL;
			elem->child = NULL;



			// insert the node in its right place
			prev->next = elem;
			elem->next = follo;

			return elem;
		}
	}

	return NULL;
}


/**
 * @function remove_all_list() removes all the elements in @param list
 * recursively.
 */
void remove_all_list(node* list)
{
	if (list != NULL)
	{
		remove_all_list(list->next);
		free(list);
	}
}


unsigned int size(void)
{
	if(toCheck)
	{
		return wordsNbr;
	}
	else
	{
		return false;
	}
}


/**
 * nodeToFree() determines the node that will be freed.
 */
node* nodeToFree(node* dic)
{

	while (dic->child != NULL ||
		dic->next != NULL)
	{	
		if (dic->child == NULL && 
			dic->next == NULL)
		{
			return dic;
		}
		else if (dic->next == NULL &&
			dic->child != NULL)
		{
			dic = dic->child;
		}
		else
		{
			dic = dic->next;
		}
	}

	return dic;
}


/**
 * followIt() will find the node int @param dic, that points to 
 * @param toFollow.
 */
node* followIt(node* dic, node* toFollow)
{
	while (dic->next != toFollow ||
		dic->child != toFollow)
	{
		if (dic->next == toFollow || 
			dic->child == toFollow)
		{
			return dic;
		}
		else if (dic->next == NULL &&
			dic->child != NULL)
		{
			dic = dic->child;
		}
		else
		{
			dic = dic->next;
		}
	}
	
	return dic;
}


bool unload(node* dic)
{
	
	// if the dic contains one node
	if (dic->next == NULL && 
		dic->child == NULL)
	{
		free(dic);
		return true;
	}
	
	node* freeNow = dic;
	node* follower = dic;

	// we repeat until the dictionary is unloaded
	while (1)
	{
		// find Tom & Jerry
		freeNow = nodeToFree(freeNow);
		follower = followIt(dic, freeNow);
		
		// exit if one of the pointers fail to point
		if (freeNow == NULL ||
			follower == NULL)
		{
			return false;
		}
		
		// dictionary contains only two nodes
		if ((freeNow == dic || follower == dic) && 
			(((freeNow->next == NULL && freeNow->child == NULL) && 
				(follower->next == NULL || follower->child == NULL)) || 
			((follower->next == NULL && follower->child == NULL) && 
				(freeNow->next == NULL || freeNow->child == NULL))))
		{
			free(freeNow);
			free(follower);
			return true;
		}
		else
		{
			if (follower->next == freeNow)
			{
				follower->next = NULL;
			}
			else
			{
				follower->child = NULL;
			}


			free(freeNow);
			
			// to make the function easier
			freeNow = follower;
		}
	}

	return false;
}


bool check(node* dic, char* word)
{
	node* findIt = dic;

	for (int i = 0, n = strlen(word); i < n; i++)
	{
		findIt = findNodeInRow(word[i], findIt);
		if (findIt == NULL)
		{
			return false;
		}
		else
		{
			findIt = findIt->child;
		}
	}
	
	return true;
}


/**
 * findNodeInRow() will find @param alpha in @param dic
 * iterating over the nodes that points to next nodes.
 */
node* findNodeInRow(char alpha, node* dic)
{
	if (dic != NULL)
	{
		while (dic != NULL)
		{
			if (dic->value == alpha)
			{
				return dic;
			}
			else
			{
				dic = dic->next;
			}
		}
	}

	return NULL;
}