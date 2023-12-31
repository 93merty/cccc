/* 
 * File:   graph.h
 * Author: kadayif
 *
 * Created on 30 Kasım 2022 Çarşamba, 11:18
 */

/* 
 * File:   graph.h
 * Author: kadayif
 *
 * Created on 28 Kasım 2022 Pazartesi, 09:54
 */

/* basic directed graph type */

struct graph {
    int n;              /* number of vertices */
    int m;              /* number of edges */
    struct successors {
        int d;          /* number of successors */
        int len;        /* number of slots in array */
        int isSorted; /* true if list is already sorted */
        int list[];    /* actual list of successors starts here */
    } *alist[];
};

typedef struct graph *Graph;

/* create a new graph with n vertices labeled 0..n-1 and no edges */
Graph graphCreate(int n);

/* free all space used by graph */
void graphDestroy(Graph);

/* add an edge to an existing graph */
/* doing this more than once may have unpredictable results */
void graphAddEdge(Graph, int source, int sink);

/* return the number of vertices/edges in the graph */
int graphVertexCount(Graph);
int graphEdgeCount(Graph);

/* return the out-degree of a vertex */
int graphOutDegree(Graph, int source);

/* return 1 if edge (source, sink) exists), 0 otherwise */
int graphHasEdge(Graph, int source, int sink);

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
/* no particular order is guaranteed */
void graphForeach(Graph g, int source,
        void (*f)(Graph g, int source, int sink, void *data),
        void *data);

void printGraph(Graph g);

void sortSuccessors(Graph g, int increasing);