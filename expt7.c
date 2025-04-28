#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n\n***MAIN MENU***");
		printf("\n1.Create a list");
		printf("\n2.Display list");
		printf("\n3.Add a node at end");
		printf("\n4.Exit");
		printf("\n\nEnter your option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: start = create_ll(start);
				printf("\n LINKED LIST CREATED");
				break;
			case 2: start = display(start);
				break;
			case 3: start = insert_end(start);
				break;
		}
	}while(option != 4);
	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data: ");
	scanf("%d", &num);
	while(num != -1)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		if(start == NULL)
		{
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr -> next != NULL)
				ptr = ptr -> next;
				ptr -> next = new_node;
				new_node->next = NULL;
		}
		printf("\n Enter the data: ");
		scanf("%d",&num);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t %d", ptr -> data);
		ptr = ptr -> next;
	}
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("\n Enter the data: ");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr -> next != NULL)
		ptr = ptr->next;
		ptr->next = new_node;
		return start;
}
	

