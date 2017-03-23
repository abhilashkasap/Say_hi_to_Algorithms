#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<process.h>
struct tree
{
    struct tree *l;
    struct tree *r;
    int data;

};
struct tree *head=NULL;
void insertnode()
{ int flag=0;
   struct tree *new_node = (struct tree*)malloc(sizeof(struct tree));
   new_node->l=NULL;
   new_node->r=NULL;
   printf("Enter Data  :");
   scanf("%d",&new_node->data);
   if(head==NULL)
   {

       head=new_node;

   }
   else
   {

       struct tree *temp=head;
       while(1)
       {

           if(temp->data>new_node->data)
           {

               if(temp->l==NULL)
               {

                temp->l=new_node;
               flag=1;
               }
               else
                temp=temp->l;
           }
           else
           {
               if(temp->r==NULL)
               {

                   temp->r=new_node;
                   flag=1;
               }
               else
                temp=temp->r;

           }
           if(flag==1)
            break;

       }

   }
 printf("Inserted !!!");
}
void inorder( struct tree *top)
{   if(top==NULL)
       return ;
       else
       {


    inorder(top->l);
    printf("%d", top->data);
    inorder(top->r);
       }

}
void main()
{
int choice;
while(1)
    {


    printf("Tree menu");
    printf("\n1. Insert Data \n2. Inorder \n3. Exit ");
    scanf("%d",&choice);
    switch(choice)
    {

        case 1: insertnode();
         break;
        case 2: inorder(head);
        break;
        case 3: exit(0);
        break;

        default: printf("Wrong choice ! try again");
    }


    }
}
