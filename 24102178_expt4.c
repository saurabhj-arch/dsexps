#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
	int add_item;
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else{
		if(front==-1)
			front = 0;
		printf("Insert the element in queue: ");
		scanf("%d",&add_item);
		rear = rear+1;
		queue[rear] = add_item;
	}
}
void delete(){
	if(front == -1||front > rear){
		printf("Queue Underflow\n");
		return;
	}
	else{
		printf("Element deleted from queue is: %d\n",queue[front]);
		front = front+1;
	}
}
void display(){
	int i;
	if(front == -1)
		printf("Queue is empty\n");
	else{
		printf("Queue is: \n");
		for(i = front; i<=rear;i++)
			printf("%d",queue[i]);
		printf("\n");
	}
}
int main()
{
	int choice;
	while(1){
		printf("1.Insert element to queue\n");
		printf("2.Delete element from queue\n");
		printf("3.Display all elements of queue\n");
		printf("4.Quit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			default:
				exit(1);
				break;
		}
	}
	return 0;
}

