#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adj[MAX_VERTICES];
    int vertexCount;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertexCount) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertexCount = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adj[source];
    graph->adj[source] = newNode;

    newNode = createNode(source);
    newNode->next = graph->adj[destination];
    graph->adj[destination] = newNode;
}

bool bfs(struct Graph* graph, int source, int destination) {
    bool vis[MAX_VERTICES] = { false };
    int parent[MAX_VERTICES];
    for (int i = 0; i < graph->vertexCount; i++) {
        parent[i] = -1;
    }

    struct Node* queue = createNode(source);
    vis[source] = true;

    while (queue != NULL) {
        int cur = queue->data;
        queue = queue->next;

        if (cur == destination) break;

        struct Node* temp = graph->adj[cur];
        while (temp != NULL) {
            int neighbor = temp->data;
            temp = temp->next;

            if (!vis[neighbor]) {
                vis[neighbor] = true;
                parent[neighbor] = cur;
                struct Node* newNode = createNode(neighbor);
                newNode->next = queue;
                queue = newNode;
            }
        }
    }

    int cur = destination;
    int distance = 0;

    while (parent[cur] != -1) {
        printf("%d -> ", cur);
        cur = parent[cur];
        distance++;
    }

    return distance;
}

bool dfsUtil(struct Graph* graph, int source, int destination, bool vis[]) {
    if (source == destination) return true;

    vis[source] = true;

    struct Node* temp = graph->adj[source];
    while (temp != NULL) {
        int neighbor = temp->data;
        temp = temp->next;

        if (!vis[neighbor]) {
            bool isConnected = dfsUtil(graph, neighbor, destination, vis);
            if (isConnected) return true;
        }
    }

    return false;
}

bool dfsStack(struct Graph* graph, int source, int destination) {
    bool vis[MAX_VERTICES] = { false };
    vis[source] = true;

    struct Node* stack = createNode(source);

    while (stack != NULL) {
        int cur = stack->data;
        stack = stack->next;

        if (cur == destination) return true;

        struct Node* temp = graph->adj[cur];
        while (temp != NULL) {
            int neighbor = temp->data;
            temp = temp->next;

            if (!vis[neighbor]) {
                vis[neighbor] = true;
                struct Node* newNode = createNode(neighbor);
                newNode->next = stack;
                stack = newNode;
            }
        }
    }

    return false;
}

bool dfs(struct Graph* graph, int source, int destination) {
    bool vis[MAX_VERTICES] = { false };
    vis[source] = true;

    return dfsUtil(graph, source, destination, vis);
}

int main() {
    int v, e, source, destination;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    struct Graph* graph = createGraph(v);

    printf("Enter %d edges (source destination): \n", e);
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter source and destination: ");
    scanf("%d %d", &source, &destination);

    printf("possible: %d\n", dfsStack(graph, source, destination));

    return 0;
}
