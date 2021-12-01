#include <stdio.h>
#include <stdlib.h>
#define MAXV 5
typedef struct {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;
int IsExistEL(MGraph G) {
    int oddCount = 0;
    for (int i = 0;i < G.numVertices;i++) {
        int tmpOdd = 0;
        for (int j = 0;j < G.numVertices;j++) {//遍历每一行，将个数统计出来
            tmpOdd += G.Edge[i][j];
        }
        if (tmpOdd % 2 == 1) {//如果个数是奇数，就将oddCount+1
            oddCount++;
            if (oddCount > 2) {
                return 0;
            }
        }
    }
    if (oddCount == 0 || oddCount == 2)return 1;
    else return 0;
}
void setG(MGraph* g, int a[]) {
    for (int i = 0;i < MAXV * MAXV;i++) {
        g->Edge[i / 5][i % 5] = a[i];
    }
}
int main() {
    MGraph G;
    G.numVertices = 5;
    int a[] = {
        1,1,0,0,1,//
        1,0,1,0,1,//
        0,1,0,1,1,//
        0,0,1,0,1,//
        0,0,0,1,0,//
    };
    setG(&G, a);
    int i = IsExistEL(G);
    printf("%d", i);
    return 0;
}
// 