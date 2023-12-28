// Graph Implementation //
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node Node;

int getInput();
void getEdges(int , int(*)[]);
void FormAdjencyList(Node **, int, int, int(*)[]);
void DeleteNodes(int, Node**);
void DisplayAdjencyList(int, Node**);

int main()
{
    int n, edgeSize;
    printf("how many vertices are there = ");
    n = getInput();
    Node *nodes[n];
    for(int i=0; i<n; i++)
        nodes[i] = NULL;
    printf("Enter the no. of edges = ");
    edgeSize = getInput();
    int edges[edgeSize][2];
    getEdges(edgeSize, edges);
    FormAdjencyList(nodes, n, edgeSize,edges);
    DisplayAdjencyList(n, nodes);
    DeleteNodes(n, nodes);
    return 0;
}
int getInput()
{
    int n;
    scanf("%d",&n);
    return n;
}
void getEdges(int size, int edges[size][2])
{
    printf("Enter the edges : \n");
    for(int i=0; i<size; i++)
    {
        scanf("%d %d",&edges[i][0],&edges[i][1]);
    }
}
void FormAdjencyList(Node **nds, int size, int es, int edges[es][2])
{
    for(int i=0; i<es; i++)
    {
        if(nds[edges[i][0]-1] == NULL)
        {
            nds[edges[i][0]-1] = (Node*) calloc(1, sizeof(Node));
            nds[edges[i][0]-1]->value = edges[i][1];
            nds[edges[i][0]-1]->next = NULL;
        }
        else
        {
            Node *node = (Node*) calloc(1, sizeof(Node));
            node->value = edges[i][1];
            node->next = nds[edges[i][0]-1];
            nds[edges[i][0]-1] = node;
        }
        if(nds[edges[i][1]-1] == NULL)
        {
            nds[edges[i][1]-1] = (Node*) calloc(1, sizeof(Node));
            nds[edges[i][1]-1]->value = edges[i][0];
            nds[edges[i][1]-1]->next = NULL;
        }
        else
        {
            Node *node = (Node*) calloc(1, sizeof(Node));
            node->value = edges[i][0];
            node->next = nds[edges[i][1]-1];
            nds[edges[i][1]-1] = node;
        }
    }
}
void DisplayAdjencyList(int size, Node **nds)
{
    for(int i=0; i<size; i++)
    {
        Node *node = nds[i];
        while(node != NULL)
        {
            printf("%d\t", node->value);
            node = node->next;
        }
        printf("\n");
    }
}
void DeleteNodes(int size, Node **nodes)
{
    for(int i=0; i<size; i++)
    {
        while(nodes[i] != NULL)
        {
            Node *node = nodes[i];
            nodes[i] = nodes[i]->next;
            free(node);
        }
    }
}

