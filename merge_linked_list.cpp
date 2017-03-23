#include<iostream> //merge_linked_list
#include<process.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head1=NULL;
node *head2=NULL;
node *head3=NULL;
node * createnode(node *head,int d)
{
	node *new_node = new node;
	new_node->next=NULL;
	new_node->data=d;
	if(head==NULL)
	head=new_node;
	else
	{
		
		node *temp=head;
	     while(temp->next!=NULL)
	     temp=temp->next;
	     
	     temp->next=new_node;
	}
	
	return head;
	
}
void mergelist(node *first,node *second)
{
	
	    while(first!=NULL||second!=NULL)
	     	{
	     		if(first!=NULL&&second!=NULL)
	     		{
	     			if(first->data<=second->data)
	     			{
	     				
	     				head3=createnode(head3,first->data);
	     				first=first->next;
					 }
					 else
					 {
					 	
					 	head3=createnode(head3,second->data);
					 	second=second->next;
					 }
	     			
				 }
				 else
				 {
				 
				 if(first!=NULL)
				 {  
				 	head3=createnode(head3,first->data);
				 	first=first->next;
				 	
				 }
				 if(second!=NULL)
				 {
				 	
				 	head3=createnode(head3,second->data);
				 	second=second->next;
				 }
			}
	     		
	     		
	     		
			 }
	     
}

void display(node *head)
{
	
	while(head!=NULL)
	{
	
	cout<<" Data = "<<head->data<<endl;
	head=head->next;
}
}

int main()
{
	while(1)
	{
	
	int c;
	cout<<"  \n Menu :";
	cout<<" \n 1. Add Node to  List 1";
	cout<<" \n 2. Add node to  list 2";
	cout<<" \n 3. Display 1";
	cout<<" \n 4. Display 2";
	cout<<" \n 5. Display 3";
	cout<<" \n 6. Merge List to 3";
	cout<<" \n 7.Exit \n";
	cin>>c;
	switch(c)
	{
		
		case 1: {
			int data;
			cout<<"\n Enter data :";
			cin>>data;
			head1=createnode(head1,data);
			break;
		}
		case 2:
			{
				int data;
			cout<<"\n Enter data :";
			cin>>data;
			head2=createnode(head2,data);
			break;
				
				
			}
	    case 3:
	    	{
	    		display(head1);
	    		break;
			}
		case 4:
	    	{
	    		display(head2);
	    		break;
			}
		 case 5:
	    	{
	    		display(head3);
	    		break;
			}
		case 6:
			{
				
				mergelist(head1,head2);
				break;
			}
		case 7:
			{
				exit(0);
			}
			
	}
}
}
