#include<iostream> //works for simple graph without loops
#include<cstdlib>
using namespace std;
struct edge
{
	int d;
	edge *next;
};
struct node
{
	
	int v;
	edge *list;
	node *next;
};

node *head=NULL;

void addedge()
{
	int s;int d;
	cout<<"\n Enter source node :";
	cin>>s;
	cout<<"\n Enter Dest :";
	cin>>d;
	edge *new_edge = new edge;
	new_edge->next=NULL;
	new_edge->d=d;
	node *temp= head;
	while(temp!=NULL)
	{
		
		if(temp->v==s)
		   break;
		   else
		   temp=temp->next;
	}
	if(temp->list==NULL)
	{
		temp->list=new_edge;
	}
	else
	{
		edge *temp2 = temp->list;
		while(temp2->next!=NULL)
		  temp2=temp2->next;
		temp2->next=new_edge;
	}
	
	
	
}
void addnode()
{
	cout<<" Enter Node number : ";
	int n;
	cin>>n;
	node *new_node= new node;
	new_node->v=n;
	new_node->next=NULL;
	new_node->list=NULL;
	node *temp=head;
	if(temp==NULL)
	{
		head=new_node;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=new_node;
	}
}

int countedge()
{ 
    node *temp= head;
    int c=0;
    while(temp!=NULL)
    {
    	 edge *temp2=temp->list;
    	 while(temp2!=NULL)
    	 {
    	 	c++;
    	 	cout<<endl<<" Edge Found :"<<endl;
    	 	cout<<" S : "<<temp->v<<endl;
    	 	cout<<" D : "<<temp2->d<<endl;
    	 	temp2=temp2->next;
    	 	
		 }
		 temp=temp->next;
    	
	}
	
	return c;
  
}

int main()
{
	
	int choice;
	while(1)
	{
		
		cout<<"\n1. Add node ."<<endl;
		cout<<"2. Add edge ."<<endl;
		cout<<"3. Count Edge "<<endl;
		cout<<"4. Exit   "<<endl;
		cout<<" Enter choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: addnode();
			           break;
			case 2: addedge();
			             break;
			case 3: {
				
			int temp=countedge();
			if(temp>1)
			temp=temp/2;
			cout<<"  Total No of edge :"<<temp;
			             break;}
			case 4: exit(0);
		}
	}
}

