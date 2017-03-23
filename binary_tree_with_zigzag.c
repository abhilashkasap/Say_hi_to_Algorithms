#include<stdio.h> // binary tree zig-zag +full node +child+ancestor using array

#include<process.h>

int tree[100];   static int status;
static int last;
void printindex(int i,int size)
{
	if(size==1)
{     if(tree[i]!=99999){

		printf("\n %d",tree[i]);}status++;}
	else
	{
		printindex(i+1,size-1);
		if(tree[i]!=99999){

		printf("\n %d",tree[i]);}status++;
		
	}
}
int ret_c(int n)
{   int temp;
     temp=1;
	while(n>0)
	{
		temp=temp*2;
		n--;
	}
	return temp;
}
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
	printf("\n 1. Insert node \n 2. Display \n 3. No of full nodes in tree \n 4. Ancestor of node \n 5. Child of a tree \n 6. Exit \n 7. Zig-Zag traversal");
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
		case 7:
			{
				int counter;static int index;index=0;
				counter=0;int j;
				status=0;
				for( ; status<=last;counter++)
				{   
				    int temp;
				    temp= ret_c(counter);
						if(counter%2==0)
						{
							printindex(index,temp);
							index+=temp;
							
						}
						else
						{
							while(temp>0)
							{
								if(tree[index]!=99999)

		printf("\n %d",tree[index]);status++;
								index++;
								temp--;
								
							}
						}
					}
					break;
				}
				
			
		case 6:
			exit(0);
		default: printf("\n Wrong choice !");
			}
				
				
			}
	}
	

