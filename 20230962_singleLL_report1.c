#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int searchValue1(Node* head, int val) {
    Node* current = head;
    int pos = 1;

    while (current != NULL) {
        if (current->data == val)
            return pos;

        current = current->next;
        pos++;
    }

    return -1;
}

void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            printf("찾은 값 : %d\n", val);

            if (prev != NULL)
                printf("이전 노드 값 : %d\n", prev->data);
            else
                printf("이전 노드 없음\n");

            if (current->next != NULL)
                printf("다음 노드 값 : %d\n", current->next->data);
            else
                printf("다음 노드 없음\n");

            return;
        }

        prev = current;
        current = current->next;
    }

    printf("%d을(를) 찾을 수 없습니다.\n", val);
}

void freeList(Node* head) {
    Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("모든 노드 메모리 해제 완료\n");
}

int main() {
    Node* head = NULL;

    
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    head = n1;

    printList(head);

    int pos = -1;
    int val = 30;

    pos = searchValue1(head, val);
    printf("%d의 위치는 %d번째\n", val, pos);

    searchValue2(head, val);

    freeList(head);

    return 0;
}