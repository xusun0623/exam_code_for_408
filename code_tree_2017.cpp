#include<stdio.h>
#include <stdlib.h>
typedef struct node {
    char data[10];
    struct node* left, * right;
}BTree;

void midQuation(BTree* T) {
    if (T != NULL && T->data[0] != '@') {
        char t = T->data[0];
        bool flag = false;
        flag = (t == '+' || t == '-' || t == '*' || t == '/');
        if (flag)printf("(");
        if (T->left != NULL)midQuation(T->left);
        for (int i = 0;T->data[i] != '\0';i++) {
            printf("%c", T->data[i]);
        }
        if (T->right != NULL)midQuation(T->right);
        if (flag)printf(")");
    }
}

void createTree(BTree* node, char c[], int pos, int length) {
    if (pos < length) {//填入数据
        node->data[0] = c[pos];
        node->data[1] = '\0';
        node->left = (BTree*)malloc(sizeof(BTree));
        node->right = (BTree*)malloc(sizeof(BTree));
        createTree(node->left, c, pos * 2 + 1, length);
        createTree(node->right, c, pos * 2 + 2, length);
    }
}

int main() {
    BTree* a = (BTree*)malloc(sizeof(BTree));
    createTree(a, "*+*abc-@@@@@@@d@@@@@@@@@@@@@@@@", 0, 31);
    midQuation(a);
    return 0;
}