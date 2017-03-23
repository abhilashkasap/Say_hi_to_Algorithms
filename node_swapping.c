#include<stdio.h>  //linked list node swapping without data
#include<stdlib.h>
#include<malloc.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_node()
{   struct node *new_node = (struct node *)malloc(sizeof(struct node ));
int d;
printf("\n Enter data  :");
scanf("%d",&d);
new_node->data=d;
new_node->next=NULL;
	
	if(head==NULL)
	{
		
		head=new_node;
	}
	else
	{
		struct node * temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=new_node;
		
	}
	
	printf("\n Data inserted !!!!!!!");
	
}
void display()
{
	int counter;
	counter=1;
	struct node * temp=head;
	printf("\n Printing data \n");
	while(temp!=NULL)
	{
		
		printf("\n Number of node : %d   Data :%d ",counter++,temp->data);
		temp=temp->next;
	}
	
}


void swap()
{   int x,y;
	printf("\n Enter data of nodes to be Swapped : ");
	scanf("%d%d",&x,&y);

   if (x == y) return;
 
   
   struct node *prevx = NULL, *currx = head;
   while (currx && currx->data != x)
   {
       prevx = currx;
       currx = currx->next;
   }
 
   
   struct node *prevy = NULL, *curry = head;
   while (curry && curry->data != y)
   {
       prevy = curry;
       curry = curry->next;
   }
 
   
   if (currx== NULL || curry == NULL)
       return;
 
   
   if (prevx != NULL)
       prevx->next = curry;
   else 
       head = curry;  
 
   
   if (prevy != NULL)
       prevy->next = currx;
   else  
       head = currx;
 
   
   struct node *temp = curry->next;
   curry->next = currx->next;
   currx->next  = temp;
}
 
int main()
{
	int c;
	while(1)
	{
	
	printf(" \n linked list menu \n");
	printf(" 1. Insert node \n 2. Display \n 3. Swap nodes \n 4. exit \n Input choice  :  ");
	scanf("%d",&c);
	switch(c)
	{
		
		case 1: insert_node();
		            break;
		case 2: display();
		              break;
		case 3: swap(); break;
		case 4: exit(0);
		default: printf(" \n  Wrong choice !!");
	}
}
	return 0;
}
