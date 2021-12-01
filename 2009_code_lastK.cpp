#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* link;
}NODE;

void create(NODE* p, int a[], int pos, int length) {
    if (pos < length) {
        p->data = a[pos];
        p->link = (NODE*)malloc(sizeof(NODE));
        p->link->data = NULL;//用0作为结束标志
        create(p->link, a, pos + 1, length);
    }
}

int getLastK(NODE* p, int k) {
    NODE* p_fast = p, * p_slow = p;
    while (--k && p_fast->link != NULL)p_fast = p_fast->link;
    p_fast = p_fast->link;
    while (p_fast->data) {
        p_slow = p_slow->link;
        p_fast = p_fast->link;
    }
    return p_slow->data;
}

int main() {
    NODE p;
    create(&p, (int[]) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 0, 10);
    int ret = getLastK(&p, 7);
    return 0;
}