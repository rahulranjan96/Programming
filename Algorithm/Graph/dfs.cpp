#include<iostream>
using namespace std;

int *color;
int *parent;
int t=0;
int *dt;
int *ft;

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

void DFS_VISIT(node **g,int v)
{
  
  color[v]=1;
  t++;
  dt[v]=t;
  node *temp;
  temp=g[v]->next;
  while(temp!=NULL)
  { 
    if(color[temp->v]==0)
        DFS_VISIT(g,temp->v);
      temp=temp->next;
  }
  color[v]=2;
  t++;
  ft[v]=t;
  //cout<<v<<endl;
}

void DFS(node **g,int n)
{
   for(int i=0;i<n;i++)
   {
    if(color[g[i]->v]==0)
        { 
          //cout<<g[i]->v<<endl;
          DFS_VISIT(g,g[i]->v);
        }
      /*for(int i=0;i<n;i++)
        cout<<color[i]<<" ";*/
      //cout<<endl;
    }   
}


int main()
{
	int n,m;
	cout<<"Enter number of vertex in graph:";
	cin>>n;
	cout<<"Enter number of edges:";
	cin>>m;
	node **g=new node*[n];
	for(int i=0;i<n;i++)
		g[i]=new node[1];
	for(int i=0;i<n;i++)
		{
			g[i]->v=i;
			g[i]->next=NULL;
			g[i]->prev=NULL;
		}
		int v1,v2;
		while(m--)
		{
            //cout<<m<<":";
           	cin>>v1>>v2;
           	insert(g[v1],v2);    
           	//insert(g[v2],v1);    // additional code for undirected graph
           
		}
    for(int i=0;i<n;i++)
      print(g[i]);

		color=new int[n];
		parent=new int[n];
    dt=new int[n];
    ft=new int[n];

		for(int i=0;i<n;i++)
   	        {
   	        	dt[i]=0;
              ft[i]=0;
   	        	color[i]=0;
   	        	parent[i]=0;
   	        }

  	  DFS(g,n);

     for(int i=0;i<n;i++)
      {
        cout<<dt[i]<<"/"<<ft[i]<<"\n";
      }
     /* for(int i=0;i<n;i++)
        cout<<color[i]<<" ";
        */
		return 0;
}
//Sample Input:Number of vertices=6 Number of edges=8
/*
0 1
0 3
1 3
2 1
3 2
4 2
4 5
5 5
*/