#include <iostream>
#include <queue>
#include <vector>

#define MAXV 100 // 假设最大顶点数为100

typedef struct {
    int numberVertices, numberEdges; // 图的顶点数和边数
    char VerticesList[MAXV];         // 顶点表
    int edge[MAXV][MAXV];            // 邻接矩阵
} MGraph;

// 判断图是否有唯一的拓扑序列
int intquely(MGraph G) {
    std::vector<int> inDegree(G.numberVertices, 0);
    std::queue<int> q;

    // 计算每个顶点的入度
    for (int i = 0; i < G.numberVertices; ++i) {
        for (int j = 0; j < G.numberVertices; ++j) {
            if (G.edge[i][j] != 0) {
                inDegree[j]++;
            }
        }
    }

    // 找到所有入度为0的顶点并加入队列
    for (int i = 0; i < G.numberVertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> topoOrder;

    while (!q.empty()) {
        if (q.size() > 1) { // 入度为0的顶点不唯一
            return 0;
        }
        
        int v = q.front();
        q.pop();
        topoOrder.push_back(v);

        for (int i = 0; i < G.numberVertices; ++i) {
            if (G.edge[v][i] != 0) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    // 若拓扑排序包含了所有顶点，则说明图有唯一的拓扑序列
    return (topoOrder.size() == G.numberVertices) ? 1 : 0;
}
