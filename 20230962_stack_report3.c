#include <stdio.h>
#include <ctype.h> // isdigit(), isalpha() 사용
#include <string.h> 
#define MAX 100



int infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // '(' 제거
        }
        else {  // 연산자
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    // 👉 변환된 후위표기식 바로 계산
    return evaluatePostfix(postfix);
}
int main(void) {
    char infix[MAX];
    char postfix[MAX];
    int result;

    printf("중위표기식 입력 : ");
    scanf("%s", infix);

    result = infixToPostfix(infix, postfix);

    printf("후위표기식 : %s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);

    return 0;
}