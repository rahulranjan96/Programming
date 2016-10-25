#include<iostream>
using namespace std;

typedef struct Node{
	int v;
	struct Node* next;
	struct Node* prev; 
}node;

void insert(node *s,int v)
{
	node *s1 = new node[1];
	s1->v=v;
	s1->prev=s;
	s1->next=s->next;
	if(s->next!=NULL)
		s->next->prev=s1;
	s->next=s1;
}
void print(node *g)
{
	while(g!=NULL)
	{
		cout<<g->v;
		cout<<" ";
		g=g->next;
	}
	cout<<"\n";
}

typedef struct Queue{
	int key;
	struct Queue* next;
	struct Queue* prev;
}queue;

queue *head=NULL;
queue *tail=NULL;

void enqueue(queue *a,int key)
{
  queue *b=new queue[1];
  b->key=key;
  if(a->next==NULL)
  {
    b->next=a->next;
    b->prev=a;
    a->next=b;
    head=b;
  }
  else
  {
    b->next=a->next;
    b->prev=a;
    a->next->prev=b;
    a->next=b;
  }
}
int dequeue(queue *a)
{
   if(head!=tail)
   {
   	int val=head->key;
   	queue *temp=head->prev;
   	delete(temp->next);
   	temp->next=NULL;
   	head=temp;
   	return val;
   }
   else return -1;
}

void print_queue(queue *a)
{
	while(a->next!=NULL)
	{
		cout<<a->next->key<<" ";
		a=a->next;
	}
	cout<<"\n";
}

void bfs(node **g,int s,int *dist,int *color,int *parent)
{
  queue *Q=new queue[1];
  Q->key=0;
  Q->next=NULL;
  Q->prev=NULL;
  head=Q;
  tail=Q;
  node *temp=NULL;
  int x;
  color[s]=1;
  parent[s]=-1;
  enqueue(Q,s);
  print_queue(Q);
  while((x=dequeue(Q))!=-1)
  {
  	
     temp=g[x]->next;
     while(temp!=NULL)
     {
        if(color[temp->v]==0)
        	{
        		enqueue(Q,temp->v);
        		dist[temp->v]=dist[x]+1;
        		color[temp->v]=1;
        		parent[temp->v]=x;
        	}
        	temp=temp->next;
        	
     }
     color[x]=2;;
     print_queue(Q);
  }

}
int main()
{
	int n,t;
	cout<<"Enter number of vertex in graph:";
	cin>>n;
	cout<<"Enter number of edges:";
	cin>>t;
	node **g=new node*[n];
	for(int i=0;i<n;i++)
		g[i]=new node[1];
	for(int i=0;i<n;i++)
		{
			g[i]->v=i;
			g[i]->next=NULL;
			g[i]->prev=NULL;
		}
		int v1,v2,c;
		while(t--)
		{
           	cin>>v1>>v2;
           	insert(g[v1],v2);    
           	insert(g[v2],v1);    // additional code for undirected graph
           
		}
		int s;
		int *dist=new int[n];
		int *color=new int[n];
		int *parent=new int[n];
		for(int i=0;i<n;i++)
   	        {
   	        	dist[i]=0;
   	        	color[i]=0;
   	        	parent[i]=0;
   	        }
  	   for(int i=0;i<n;i++)
    	   	print(g[i]);
        cout<<"Enter source vertex:";
		cin>>s;
		bfs(g,s,dist,color,parent);
        for(int i=0;i<n;i++)
			cout<<dist[i]<<" ";
		cout<<"\n";
		for(int i=0;i<n;i++)
			cout<<parent[i]<<" ";
		cout<<"\n";

		return 0;
}
//Sample Input:Number of vertices=8,Number of edges=9
/*
0 1
1 2
2 3
3 4
3 5
4 5
4 7
5 6
6 7
*/
