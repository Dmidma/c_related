/**
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This an implementation and usage of Singly Linked Lists.
 * This example will handle sorted lists.
 */

#include <stdio.h>
#include <stdlib.h>


// definition of a node
typedef struct node
{
	int value;
	struct node* next;
}node;


// prototypes
void print_list(node* list);
void remove_from_list(node** list, int value);
void remove_all_list(node* list);
void add_to_list(node **list, int value);


int main(int argc, char** argv)
{

	// head of the list
	node* head = NULL;

	restart:
	// prints menu
	printf("Menu:\n");
	printf("1. Add value to the list\n");
	printf("2. remove value from the list\n");
	printf("3. printf list\n");
	printf("4. exit\n");

	int choice = 0;

	while (choice <= 0 || choice > 4)
	{
		scanf("%d", &choice);
	}

	// clearing screen
	system("clear");

	switch (choice)
	{
		case 1:
			printf("value: \n");
			int enter;
			scanf("%d", &enter);
			add_to_list(&head, enter);
		break;
		case 2:
			printf("value: \n");
			scanf("%d", &enter);
			
			// print the previous list
			printf("Previous list:\n");
			print_list(head);
			printf("\n");

			remove_from_list(&head, enter);

			// print the new list
			printf("new list:\n");
			print_list(head);
			printf("\n");

			// enter 'q' to go back to menu
			char goback = 0;
			while (goback != 'q')
			{
				scanf("%c", &goback);
			}
		break;
		case 3:
			printf("List:\n");
			print_list(head);
			printf("\n");
			
			// enter 'q' to go back to menu
			goback = 0;
			while (goback != 'q')
			{
				scanf("%c", &goback);
			}
		break;
		case 4:
			remove_all_list(head);
			return 0;
		break;
	}

	// clearing screen and go back to menu
	system("clear");
	goto restart;
}

/**
 * link_node() links linkedTo to a createm element
 * which will contain @param value.
 */
void link_node(node** linkedTo, int value)
{	
	// create a node and give it the value
	node* elem = malloc(sizeof(node));
	if (elem == NULL)
	{
		printf("Unable to create node\n");
		return;
	}
	elem->value = value;
	if ((*linkedTo) != NULL)
	{		
		elem->next = (*linkedTo)->next;
	}
	else
	{
		elem->next = NULL;	
	}
	// set the linkedTo to point to the created element
	*linkedTo = elem;	
}

/**
 * add_to_list() adds @param value to @param list keeping the list sorted.
 */
void add_to_list(node **list, int value)
{
	if ((*list) == NULL || (*list)->value > value)
	{
		link_node(list, value);
	}
	else
	{
		add_to_list(&(*list)->next, value);
	}
}

/**
 * @function print_list() prints @param list recursively.
 */
void print_list(node* list)
{
	if (list != NULL)
	{
		printf("%d|", list->value);
		print_list(list->next);
	}
}

/**
 * @function remove_from_list() removes @param value from @param list
 * if it exists already in the list.
 * If multiple values exist, the function will remove the first occurence.
 */
void remove_from_list(node** list, int value)
{	

	// we exist the function if the list is empty
	if ((*list) == NULL)
	{
		return;
	}

	// if the value is the head of the list
	if ((*list)->value == value)
	{	
		// head of the list is the next element
		node* tofree = *list;
		*list = (*list)->next;

		// free the wanted value
		free(tofree);
	}
	else
	{
		// find the wanted value in the list
		node* tofree = *list;
		do
		{	
			tofree = tofree->next;

			// exit if we reach the end of the list
			if (tofree == NULL)
			{
				return;
			}
		}
		while (tofree->value != value);

		// trackers of list
		node* follo = *list;
		node* prev = *list;

		while (follo != tofree->next)
		{
			follo = follo->next;
		}
		while (prev->next != tofree)
		{
			prev = prev->next;
		}

		// link the new list and free the other node
		prev->next = follo;
		free(tofree);
	}
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