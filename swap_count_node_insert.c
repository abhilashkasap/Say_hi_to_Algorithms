#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<malloc.h>
static int c;
struct list
{

    int data;
    struct list *next;
};
struct list *head= NULL;
void createlist()
{

struct list *new_node = (struct list *)malloc(sizeof(struct list ));
new_node->next=NULL;
printf(" Enter data :");
scanf("%d",&new_node->data);
if(head==NULL)
    head=new_node;
else
{

    struct list *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

   temp->next=new_node;
}
printf(" Node inserted !!!");
}
void display()
{
     int c=1;
    struct list *temp=head;
    while(temp!=NULL)
        {printf("node= %d data = %d ",c++, temp->data); temp=temp->next;}
    printf("Data displayed !!");
}

void modifyhead()
{

     struct list *temp=head;
     if(temp==NULL)
     {

         printf("List empty !!! Head is pointing to NULL");

     }
     else
     {


         head = head->next;

         free(temp);
         printf("Data deleted !!");

     }
}
void bubblesort()
{

     struct list *temp = head;
      struct list *temp2=head;
      while(temp!=NULL)
      {

           temp2=head;
           while(temp2->next!=NULL)
           {

               if(temp2->next->data<temp2->data)
               {
                   c++;
                   int d=temp2->data;
                   temp2->data=temp2->next->data;
                   temp2->next->data= d;
               }
               temp2=temp2->next;
           }
           temp=temp->next;
      }
      printf("Sorted !!");
}
int main()
{
    int choice;
    while(1)
    {


    printf("\nLinked list menu");
    printf("\n1. Insert Data \n2. Merge two list \n3. Display \n5. Bubble sort and count swap \n6. Modify head \n4. Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {

        case 1: createlist();
         break;
        case 2: 
        break;
        case 3: display();;
        break;
        case 5:{
			c=0;
		bubblesort();
		printf("\n No of swaps required : %d",c);
		break;
		}
        
        case 6: modifyhead();
        break;
        case 4: exit(0);
        default: printf("Wrong choice ! try again");
    }


    }
    return 0;
}
