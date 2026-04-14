#include <stdio.h>
#include <stdbool.h>

#define SIZE 30  // 1. 큐 크기 30으로 변경

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} LinearQueue;

// 초기화
void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;
}

// 공백 상태
bool isEmpty(LinearQueue* q) {
    return q->rear < q->front;
}

// 포화 상태
bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;
}

// 삽입
bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->data[++(q->rear)] = value;
    return true;
}

// 삭제
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        initQueue(q);  // 2. 비었을 경우 초기화
        return -1;
    }

    int value = q->data[q->front++];

    // ⭐ 추가: 마지막 요소 삭제 후 초기화 (깔끔 처리)
    if (isEmpty(q)) {
        initQueue(q);
    }

    return value;
}

// 3. 큐 출력 함수
void display(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }

    printf("큐 상태: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// 메뉴 기반 main
int main() {
    LinearQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n--- 메뉴 ---\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            value = dequeue(&q);
            if (value != -1)
                printf("삭제된 값: %d\n", value);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}