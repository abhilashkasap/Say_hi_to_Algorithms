#include<iostream>
using namespace std;
static int counter;
struct input
{
	char ch;
	int freq;
	int left;
	int right;
};
void swap(int &a,int &b)
{
	
	int temp=a;
	a=b;
	b=a;
}
void heapswap(input &ob1,input &ob2)
{
	
	input ob3 =  ob2;
	ob2=ob1;
	ob1=ob3;
}
void heapify(input heap[],int i,int size)
{
	
	int l= 2*i+1;
	int r= 2*i+2;
	int min = i;
	if(l<size&&heap[l].freq<heap[i].freq)
	min=l;
	if(r<size&&heap[r].freq<heap[min].freq)
	min=r;
	if(min!=i)
	{
		heapswap(heap[i],heap[min]);
		heapify(heap,min,size);
		
	}
}
void buildheap(input heap[],int size)
{
	
	int index = size/2;
	for(int i=index;i>=0;i--)
	{
		
		heapify(heap,i,size);
	}
}

void huffman_code(input heap[],int size)
{
	buildheap(heap,size);
	counter = size;
	int n=size;
	for(int i=0;i<3;i++)
	{     cout<<"run"<<endl;
	       input l = heap[0];
	       heapswap(heap[0],heap[size-1]);
	       size=size-1;
	       heapify(heap,0,size);
	       input r = heap[0];
	       heapswap(heap[0],heap[size-1]);
	       size = size-1;
	       heapify(heap,0,size);
	       heap[size].freq= l.freq;
	       heap[size].freq+= r.freq;
	       heap[size].ch='$';
	       heap[size].left= ++counter;
	       heap[size].right=++counter;
	       heapswap(l,heap[heap[size].left]);
	       heapswap(r,heap[heap[size].right]);
	       heap[size-1]=heap[size];
	       heapswap(heap[0],heap[size-1]);
	       heapify(heap,0,size);
	       
		
	}
	
	
	
}

void findcode(char c,input heap[])
{
	int i=0;int code=0;
	while(heap[i].ch!=c)
	{
		if(heap[i].ch=='$')
		 {
		 	code=code*10+1;
		 	
		 	i=heap[i].right;
		 }
		cout<<"running"<<endl;
	}
	
	cout<<"Code for d = "<<code<<endl;
	
}
int main()
{
  input heap[50]={ {'a',45,-1,-1},{'b',13,-1,-1},{'c',12,-1,-1},{'d',16,-1,-1},{'e',9,-1,-1},{'f',5,-1,-1}}	;
  
 huffman_code(heap,6);
 cout<<"done";
 /*findcode('d',heap);*/
 for(int i=0;i<50;i++)
 {
 	
 	cout<<heap[i].ch<<endl;
 	cout<<heap[i].freq<<endl;
 	cout<<heap[i].left<<endl;
 	cout<<heap[i].right<<endl;
 	cout<<endl;
 }
  return 0;
	
}

