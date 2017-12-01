/**
 *
 * Hidri Oussema
 * d.oussema.g@gmail.com
 *
 * This is an implementation and usage of a Tree.
 */

#include <stdio.h>


// definition of a node
typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}node;




int main(void)
{
	


	return 0;
}

/**
 * insertValues function will add values into
 * @param tree [tree can be empty, NULL]
 * until the user enters q.
 */
void insertValues(node** tree)
{
	// variable to hold inputed value
	int inputValue = 0;

	// to break the loop, the user must enter 'q'
	// else it will add values to the tree
	while (1)
	{	
		// clearing screen
		system("clear");
		
		printf("To quit enter 'q'\n");

		printf("Value: ");
		scanf("%d", &inputValue);

		// if the user printed 'q' then break from loop
		if (inputValue == 'q')
		{
			break;
		}

		// create a tree node
		node* elem = createNode(inputValue);

		// adding the root
		if (*tree == NULL)
		{
			(*tree) = elem;
		}
		//
		else
		{
				char place;
			// ask the user for left or right
			printf("Right or Left ?\nEnter R\L:");

			scanf("%c", &place);

			if (place == 'r' || place == 'R')
			{	

				(*tree)->
			}

			scanf()
		}
	}
}

/**
 * createNode will creat a node, give it the value
 * @param  value 
 * and @return the address of the node.
 */
node* createNode(int value)
{
	node* elem = malloc(sizeof(node));
	elem->value = value;
	elem->right = NULL;
	elem->left = NULL;

	return elem;
}