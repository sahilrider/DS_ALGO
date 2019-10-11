#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int dest;
	struct node *next;
}listnode;

// A structure to represent an adjacency list
typedef struct adjList
{
    listnode *head;  // pointer to head node of list
}adjlist;

typedef struct graph
{
	int v;
	adjlist *list;
}Graph;


Graph *creategraph(int vtx)
{
	Graph *graph=(Graph*)malloc(sizeof(Graph));
	graph->v=vtx;
	graph->list=(adjlist*)malloc(vtx * sizeof(adjlist));
	
	int i;
	for(i=0;i<vtx;i++)
		//graph->list[i]->head=NULL;
		graph->list[i].head=NULL;
		
	return graph;
}

void addedge(Graph *graph,int src,int desti)
{
	//source->destination
	listnode *newnode;
	newnode=(listnode*)malloc(sizeof(listnode));
	newnode->dest=desti;
	newnode->next=graph->list[src].head;
	graph->list[src].head=newnode;
	
	//destination->source
	newnode=(listnode*)malloc(sizeof(listnode));
	newnode->dest=src;
	newnode->next=graph->list[desti].head;
	graph->list[desti].head=newnode;	
}

void printgraph(Graph *graph)
{
	int i;
	int v=graph->v;
	for(i=0;i<v;i++)
	{
		printf("Adjacent vertices of vertex %d: ",i);
		listnode *ptr;
		ptr=graph->list[i].head;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->dest);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int  main()
{
	int v;
	v=5;
	//scanf("%d",&v);
	Graph *graph;
	
	graph=creategraph(v);
	
	addedge(graph, 0, 1);
    addedge(graph, 0, 4);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);
    
    printgraph(graph);
	return 0;
}
