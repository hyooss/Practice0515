#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}node;

typedef struct stackType {
    int length;
    node* top;
}stackType;

int main(void) {
    stackType* stack=NULL;
    node*newNode1;
    node*newNode2;
    node*newNode3;

    //스택의 초기화
    stack=(stackType*)malloc(sizeof(stackType));
    stack->length=0;
    stack->top=NULL;

    //push
    //새로 삽입하는 노드가 스택의 맨 위의 데이터
    //top은 항상 새로운 노드를 가리킴
    //새로운 노드는 첫번째 노드로 삽입

    //push 10
    newNode1=(node*)malloc(sizeof(node));
    newNode1->data=10;
    newNode1->link=NULL;
    stack->top=newNode1;

    //push 20
    newNode2=(node*)malloc(sizeof(node));
    newNode2->data=20;
    newNode2->link=NULL;
    stack->top=newNode2;
    ㅣㅣㅣ호료로호ㅓ

    //push 30
    newNode3=(node*)malloc(sizeof(node));
    newNode3->data=30;
    newNode3->link=NULL;
    stack->top=newNode3;

    return 0;
}