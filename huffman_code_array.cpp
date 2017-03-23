#include<iostream>
#define INFI 99999
static int c=0;
using namespace std;
struct node
{
	
	char ch;
	int freq;
	int left;
	int right;
	
};
int firstmin(node array[],int size)
{
	
	int min = array[0].freq;
	int index= 0;
	for(int i=0;i<size;i++)
	{
		
		if(array[i].freq<min)
		{
			min=array[i].freq;
			index=i;
		}
	}
	

	return index;
	
}


int huffman(node array[],int size)
{
	c= size-1;
	int n=size-1;int root;
	for(int i=0;i<n;i++)
	{
		array[++c].ch='$';
	int temp = firstmin(array,size);
	 array[c].left=temp;
	 array[c].freq=array[temp].freq;
	 array[temp].freq=INFI;
		temp=firstmin(array,size);
		array[c].right=temp;
	 array[c].freq+=array[temp].freq;
	 array[temp].freq=INFI;
		size+=1;
		
		root=c;
		
	}
	return c;
}
void printcode(node heap[],int root,int freq)
{
	
	if(heap[root].ch!='$')
	{
		cout<<" Code for "<<heap[root].ch<<" = "<<freq<<endl;
		
		return;
	}
	else
	{
		
		int leftfreq=freq*10+0;
		int rightfreq=freq*10+1;
		printcode(heap,heap[root].left,leftfreq);
		printcode(heap,heap[root].right,rightfreq);
	}
}
int main()
{
	
	node heap[50]={ {'a',45,-1,-1},{'b',13,-1,-1},{'c',12,-1,-1},{'d',16,-1,-1},{'e',9,-1,-1},{'f',5,-1,-1}}	;
	int r=huffman(heap,6);
	printcode(heap,r,0);
}
