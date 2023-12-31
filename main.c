/* 
 * File:   main.c
 * Author: kadayif
 *
 * Created on 30 Kasım 2022 Çarşamba, 11:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "genericSearch.h"
//#define TEST_SIZE (199137)
#define TEST_SIZE (11)
/*
 * 
 */
int main(int argc, char** argv) {
    Graph g;
    struct searchInfo *s;
    int i;

    g = graphCreate(15);
    
    graphAddEdge(g, 0, 1);
    graphAddEdge(g, 0, 4);
    graphAddEdge(g, 2, 4);
    graphAddEdge(g, 1, 2);
    graphAddEdge(g, 2, 5);
    graphAddEdge(g, 5, 8);
    graphAddEdge(g, 7, 8);
    graphAddEdge(g, 5, 3);
    graphAddEdge(g, 9, 6); 
    graphAddEdge(g, 11,13);
    graphAddEdge(g, 10, 14);
    graphAddEdge(g, 11, 12);
    graphAddEdge(g, 3, 9);
    graphAddEdge(g, 3, 7);
    graphAddEdge(g, 8, 11);
    graphAddEdge(g, 3, 10);
    sortSuccessors(g,0);  // 0 means decreasing order, 1 means increasing order
    printGraph(g);
    
    s = searchInfoCreate(g);
    dfs(s, 2);   
    printSearchInfo(s);
    printPathForward(s,0);
    printPathBackward(s,0);
   // searchInfoDestroy(s);
   // graphDestroy(g);
    
  //  printf("Tamam...\n");
  //  printf("Tamam...\n");
    return (EXIT_SUCCESS);
}

