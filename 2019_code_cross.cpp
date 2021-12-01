#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

//通过数组创建链表
void create(node* n, int length, int pos, int data[]) {
    if (pos < length) {
        n->data = data[pos];//赋给struct中的data
        node* next = (node*)malloc(sizeof(node));//动态分配下一个节点地址
        n->next = next;//对下一个节点采用递归构建
        create(n->next, length, pos + 1, data);//递归，pos位置+1
    }
    else {
        n->data = -1;//最后一个节点使用-1作为标识
    }
}

void cross_sort(node* n, int length) {
    //对后半部分就地逆置
    node* mid = n;
    node* start = n;
    int i;
    for (i = 0;i < length / 2;i++)mid = mid->next;//找到中间节点
    //从中间开始逆置链表
    node* s, * t;
    s = mid->next;
    mid->next = NULL;
    while (s->data != -1) {
        //将s节点摘下来
        t = s;
        s = s->next;
        //将摘下来的节点头插到mid节点之后
        t->next = mid->next;
        mid->next = t;
    }
    node* tmp = mid;
    mid = mid->next;//后移
    tmp->next = NULL;
    i++;
    while (i++ < length && mid != NULL) {
        node* p, * q;
        //使用p、q暂存start和mid节点
        p = start->next;
        q = mid->next;
        //将mid指针所指节点单独摘下来，注意：要将尾巴(next)甩掉，不然结果不对
        mid->next = NULL;
        //插到start节点后面
        start->next = mid;
        mid->next = p;
        //同时移动start和end指针
        start = p;
        mid = q;
    }
    mid = NULL;
}

int main() {
    node* a = (node*)malloc(sizeof(node));
    int d[] = { 1,2,3,4,5,6,7,8 };
    create(a, 8, 0, d);
    cross_sort(a, 8);
    return 0;
}