#include<stdio.h> // binary tree full node+ ancestor+ child without zig-zag using array 

#include<process.h>
int tree[100];   
static int last;
int find(int data)
{
	int i;
	for(i=0;i<last;i++)
     if(tree[i]==data)
	 return i;	
}

int main()
{  int k;
for(k=0;k<100;k++)
tree[k]=99999;// 99999 as null value
   int data;  
    while(1)
    {
	
	int c;
	printf(" Binary tree options ");
	printf("\n 1. Insert node \n 2. Display \n 3. No of full nodes in tree \n 4. Ancestor of node \n 5. Child of a tree \n 6. Exit");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				printf("Enter Data :");
			     scanf("%d",&data);
				 tree[last++]=data;
				 printf("\n Data inserted !!");
				 break;	
				
			}
		case 2:
			{
				printf("Displaying Data :\n");
				int i;
				for(i=0;i<last;i++)
				printf("\n%d",tree[i]);
				break;
			}
		case 3: 
		    {
		    	int i;
		    	for(i=0;i<=last/2;i++)
		    	{
		    		int l,r;
		    		l= 2*i+1;
		    		r=2*i +2;
		    		if(tree[l]!=99999&&tree[r]!=99999)
		    		printf(" \n %d",tree[i]);
				}
				break;
			}
		case 4: 
		    {
		    int index;	
		    printf("\n Enter data for the node :");
		    scanf("%d",&data);
		    index= find(data);
		    while(index>=0)
		    {
		         if(index%2==0)
		         index=(index-2)/2;
		         else
		         index= (index-1)/2;
		         if(index>=0)
		         printf("\n%d",tree[index] );
		         
			}
			break;
			}
		case 5:
			{
				int index;	
		    printf("\n Enter data for the node :");
		    scanf("%d",&data);
		    index= find(data);
		    int l,r;
		    l=2*index+1;
		    r= 2*index+2;
		    printf(" \nLeft child of the node is %d",tree[l]);
		    printf(" \nRight child of the node is %d",tree[r]);
		    
		    break;
			}
		case 6:
			exit(0);
		default: printf("\n Wrong choice !");
				
				
				
			}
	}
	
}
