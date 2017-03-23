#include<stdio.h>// reverse level order and height of the tree
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
void reverse_level_order(struct tree* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) 
        print(root, i);
}
 
 int height(struct tree* node)
{
    if (node==NULL)
        return 0;
    else
    {
       
        int lheight = height(node->l);
        int rheight = height(node->r);
 
       
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void print(struct tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        print(root->l, level-1);
        print(root->r, level-1);
    }
}

void main()
{
int choice;
while(1)
    {


    printf("Tree menu");
    printf("\n1. Insert Data \n2. Print Reverse Level Order \n3. Exit \n4. Height of tree ");
    scanf("%d",&choice);
    switch(choice)
    {

        case 1: insertnode();
         break;
        case 2: reverse_level_order(head);
        break;
        case 3: exit(0);
        break;
        case 4: {
			
		int l;l=height(head);printf("Height = %d",l);break;
	}

        default: printf("Wrong choice ! try again");
    }


    }
}
