#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Graph 
{
    int vertices;
    int adj[MAX][MAX];
    int isDirected;
};
void initGraph(struct Graph* g, int vertices, int isDirected) 
{
    g->vertices = vertices;
    g->isDirected = isDirected;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}
void addVertex(struct Graph* g) 
{
    if (g->vertices == MAX) {
        printf("Cannot add more vertices.\n");
        return;
    }

    g->vertices++;
    for (int i = 0; i < g->vertices; i++) {
        g->adj[i][g->vertices - 1] = 0;
        g->adj[g->vertices - 1][i] = 0;
    }
    printf("Vertex %d added successfully.\n", g->vertices - 1);
}
void addEdge(struct Graph* g, int src, int dest) {
    if (src >= g->vertices || dest >= g->vertices) {
        printf("Invalid vertex number!\n");
        return;
    }

    g->adj[src][dest] = 1;

    if (!g->isDirected)
        g->adj[dest][src] = 1;

    printf("Edge added successfully between %d and %d.\n", src, dest);
}
void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] && !visited[i])
            DFSUtil(g, i, visited);
    }
}
void DFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(g, startVertex, visited);
    printf("\n");
}
void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void displayGraph(struct Graph* g) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++)
            printf("%d ", g->adj[i][j]);
        printf("\n");
    }
}
int main() 
{
    struct Graph g;
    int ch, src, dest, startVertex, vertices, type;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter graph type (0 = Undirected, 1 = Directed): ");
    scanf("%d", &type);

    initGraph(&g, vertices, type);
    while (1) 
    {
        printf("Enter 1 to add vertex, 2 to add edge, 3 to display graph, 4 to display DFS traversal, 5 to display BFS traversal and 0 to exit the program:\n");
        scanf("%d", &ch);

        switch (ch) 
        {
        case 1:
            addVertex(&g);
            break;

        case 2:
            printf("Enter source vertex: ");
            scanf("%d", &src);
            printf("Enter destination vertex: ");
            scanf("%d", &dest);
            addEdge(&g, src, dest);
            break;

        case 3:
            displayGraph(&g);
            break;

        case 4:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &startVertex);
            DFS(&g, startVertex);
            break;

        case 5:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &startVertex);
            BFS(&g, startVertex);
            break;

        case 0:
            printf("Exiting....\n");
            exit(0);

        default:
            printf("ERROR. Invalid input Try again.\n");
        }
    }

    return 0;
}
