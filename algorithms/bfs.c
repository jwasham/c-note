/**
 * Implementation incomplete.
 * Will come back to this.
 */

#include "bool.h"
#include "graph.h"
#include "queue.h"

bool processed[MAXV];	/* which vertices have been processed */
bool discovered[MAXV];  /* which vertices have been found */
int parent[MAXV];	/* discovery relation */

bool finished = FALSE;	/* if true, cut off search immediately */

initialize_search(graph *g)
{
    int i;                          /* counter */

    for (i=1; i<=g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}

bfs(graph *g, int start)
{
    queue q;			/* queue of vertices to visit */
    int v;				/* current vertex */
    int i;				/* counter */

    init_queue(&q);
    enqueue(&q,start);
    discovered[start] = TRUE;

    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        process_vertex(v);
        processed[v] = TRUE;
        for (i=0; i<g->degree[v]; i++)
            if (valid_edge(g->edges[v][i]) == TRUE) {
            if (discovered[g->edges[v][i]] == FALSE) {
                enqueue(&q,g->edges[v][i]);
                discovered[g->edges[v][i]] = TRUE;
                parent[g->edges[v][i]] = v;
            }
            if (processed[g->edges[v][i]] == FALSE)
                process_edge(v,g->edges[v][i]);
            }
    }
}

