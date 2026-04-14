#include <stdio.h>

int main() {
    char* str = (char*)malloc(101 * sizeof(char));  // 최대 100자 + '\0'
    char stack[100];
    int top = -1;

    printf("문자열 입력: ");
    fgets(str, 101, stdin);

    // 개행 문자 제거
    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '\n') {
            str[len] = '\0';
            break;
        }
        len++;
    }

    // push (문자열을 스택에 저장)
    for (int i = 0; str[i] != '\0'; i++) {
        stack[++top] = str[i];
    }

    // pop (역순 출력)
    printf("거꾸로 출력: ");
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    // 메모리 해제
    free(str);

    return 0;
}
