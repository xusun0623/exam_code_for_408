#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int weight;
    struct treeNode* left, * right;
}TNode;

/**
 * 创建二叉树
 */
void create(TNode* node, int c[], int pos, int length) {
    if (pos < length) {//填入数据
        node->weight = c[pos];
        if (pos * 2 + 1 < length) node->left = (TNode*)malloc(sizeof(TNode));
        if (pos * 2 + 2 < length) node->right = (TNode*)malloc(sizeof(TNode));
        create(node->left, c, pos * 2 + 1, length);
        create(node->right, c, pos * 2 + 2, length);
    }
}

int getWPL(TNode* root, int depth) {
    if (root != NULL) {
        int leftWeight = 0;
        int rightWeight = 0;
        if (root->left != NULL)leftWeight = getWPL(root->left, depth + 1);
        if (root->right != NULL)rightWeight = getWPL(root->right, depth + 1);
        return depth * root->weight + leftWeight + rightWeight;
    }
    else return 0;
}

int main() {
    TNode* t = (TNode*)malloc(sizeof(TNode));
    int c[] = { 54,4654,7565,234,436546,876876,353,757,2,345,23,445,1,235,0,6346 };
    create(t, c, 0, 16);
    int i = getWPL(t, 0);
    printf("%d", i);
    return 0;
}