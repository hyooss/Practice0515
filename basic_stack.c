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

void linked_stack_display(stackType*stack) {
    //display
    node*nptr=stack->top;
    printf("Linked Stack=[");
    while (nptr != NULL) {
        printf("%d ",nptr->data);
        nptr=nptr->link;
        if (nptr != NULL) {
            printf(" | ");
        }
        printf("]\n");
    }
}

int linked_stack_pop(stackType*stack) {
    //pop 연산
    //top이 가리키는 노드를 삭제
    int popItem;
    node*nptr=stack->top; //삭제 노드
    if (nptr == NULL) {//스택이 비어있음
        printf("Stack is empty\n");
        return -1;
    }
    //삭제 다음 노드를 가리킴
    stack->top=stack->top->link; //nptr->link;
    popItem=nptr->data;
    free(nptr);
    stack->length--;
    return popItem;
}

void linked_stack_push(stackType*stack,int item) {
    //push
    //새로 삽입하는 노드가 스택의 맨 위의 데이터
    //top은 항상 새로운 노드를 가리킴
    //새로운 노드는 첫번째 노드로 삽입

    node*newNode=(node*)malloc(sizeof(node));
    newNode->data=item;
    newNode->link=stack->top;
    stack->top=newNode;
    stack->length++;

}

void linked_stack_menu(stackType*stack) {
    int menu,item,popItem;
    while(1) {
        printf("Linked Stack 1.Push, 2.Pop, 3.Display, 4.Exit\n");
        printf("Input menu?");
        scanf("%d",&menu);

        if(menu==1) {
            printf("Push item?");
            scanf("%d",&item);
            linked_stack_push(stack,item);
        }
        else if(menu==2) {
            popItem=linked_stack_pop(stack);
            if (popItem>=0) {
                printf("Pop item: %d\n",popItem);
            }
        }
        else if(menu==3) {
            linked_stack_display(stack);
        }
        else if(menu==4) {
            printf("Exit\n");
            break;
        }
        else {
            printf("Menu error");
        }
    }
}

stackType* linked_stack_init(stackType* stack) {
    //스택의 초기화
    stack=(stackType*)malloc(sizeof(stackType));
    stack->length=0;
    stack->top=NULL;
    return stack;
}

int main(void) {
    stackType* stack=linked_stack_init();
    linked_stack_menu(stack);
    free(stack);

    return 0;
}