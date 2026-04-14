#define MAX 100
#include <stdio.h>

int main() {
    typedef struct Stack {
        int data[MAX];
        int top;
	} Stack;
    
    
    Stack s;
    initStack(&s);

    char* str = (char*)malloc(101 * sizeof(char));

    printf("문자열을 입력하세요: ");
    fgets(str, 101, stdin);

    int valid = 1;  // 유효 여부 체크

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // 여는 괄호 → push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // 닫는 괄호 → 검사
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                valid = 0;
                break;
            }

            char top = pop(&s);

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                valid = 0;
                break;
            }
        }
    }

    // 스택이 비어있지 않으면 짝 안 맞음
    if (!isEmpty(&s)) {
        valid = 0;
    }

    if (valid)
        printf("유효한 괄호\n");
    else
        printf("유효하지 않은 괄호\n");

    free(str);
    return 0;
}