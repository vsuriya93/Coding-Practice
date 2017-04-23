#include<stdio.h>
#include<malloc.h>

struct node
{
 int dest;
 struct node *next;
};

struct AdjList
{
 struct node *head;
};

struct Graph
{
 int V;
 struct AdjList *array;
};

typedef struct Graph Graph;
typedef struct node node;
node * createNode(int dest)
{
 node *element=(node*)malloc(sizeof(node));
 element->dest=dest;
 element->next=NULL;
}

Graph * createGraph(int V)
{
 Graph *G=(Graph *)malloc(1*sizeof(Graph));
 G->V=V;
 G->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
 int i;
 for(i=0;i<V;i++)
 {
  G->array[i].head=NULL;
 }
 
 return G;
}

void addEdge(Graph *G,int src, int dest)
{
 node *element=createNode(dest);
 if(G->array[src].head==NULL)
 {
  G->array[src].head=element;
  return;
 }
 else
 {
  element->next=G->array[src].head;
  G->array[src].head=element;
 }
 return;
}

void printGraph(Graph *G)
{
 int i;
 for(i=0;i<G->V;i++)
 {
  node *val=G->array[i].head;
  printf("\n%d: ",i);
  while(val){
   printf("%d->",val->dest);
   val=val->next;
  }
 }
 printf("\n");
}

int main()
{
 Graph *g = createGraph(4);
 addEdge(g,0, 1);
 addEdge(g,0, 2);
 addEdge(g,1, 2);
 addEdge(g,2, 0);
 addEdge(g,2, 3);
 addEdge(g,3, 3);
 printGraph(g);
}
