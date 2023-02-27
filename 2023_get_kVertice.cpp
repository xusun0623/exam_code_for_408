#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 4

typedef struct {                // 图的定义
    int numVertices, numEdges;  // 图中实际的顶点数和边数
    char VerticesList[MAXV];    // 顶点表，MAXV为已定义常量
    int Edge[MAXV][MAXV];       // 邻接矩阵
} MGraph;

int printVertices(MGraph* G) {
    int count = 0, indegree = 0, outdegree = 0;
    // 遍历无向图统计所有点的出度和入度
    for (int i = 0; i < G->numVertices; i++) {
        indegree = 0;   // i的入度
        outdegree = 0;  // i的出度
        for (int j = 0; j < G->numVertices; j++) {
            outdegree += G->Edge[i][j];
            indegree += G->Edge[j][i];
        }
        if (outdegree > indegree) {
            printf("K顶点的个数为：%d\n", i);
            count++;
        }
    }
    return count;
}

int main() {
    MGraph* m = new MGraph();
    m->numVertices = 4;
    m->numEdges = 5;
    for (int i = 0; i < 4; i++) {
        m->VerticesList[i] = 'a' + i;
    }
    /**
     * m->Edge
     * [0,1,0,1]
     * [0,0,1,1]
     * [0,0,0,1]
     * [0,0,0,0]
    */
    m->Edge[0][1] = 1;
    m->Edge[0][3] = 1;
    m->Edge[1][2] = 1;
    m->Edge[1][3] = 1;
    m->Edge[2][3] = 1;
    printVertices(m);
    return 0;
}
