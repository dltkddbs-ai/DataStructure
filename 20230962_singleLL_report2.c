#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[20];
    struct Contact* next;
} Contact;

void addContact(Contact** head, char name[], char phone[]) {
    Contact* newNode = (Contact*)malloc(sizeof(Contact));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Contact* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void searchContact(Contact* head, char name[]) {
    Contact* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름 : %s\n", current->name);
            printf("전화번호 : %s\n", current->phone);
            return;
        }
        current = current->next;
    }

    printf("%s 연락처를 찾을 수 없습니다.\n", name);
}


void deleteContact(Contact** head, char name[]) {
    Contact* current = *head;
    Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {

            if (prev == NULL) {
                *head = current->next;
            }
            else {
                prev->next = current->next;
            }

            free(current);
            printf("%s 연락처가 삭제되었습니다.\n", name);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("%s 연락처를 찾을 수 없습니다.\n", name);
}


void printContacts(Contact* head) {
    if (head == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }

    printf("\n===== 전화번호부 =====\n");

    Contact* current = head;

    while (current != NULL) {
        printf("이름 : %s, 전화번호 : %s\n",
            current->name,
            current->phone);
        current = current->next;
    }

    printf("=====================\n");
}


void freeList(Contact* head) {
    Contact* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Contact* phoneBook = NULL;

    
    addContact(&phoneBook, "Kim", "010-1111-1111");
    addContact(&phoneBook, "Lee", "010-2222-2222");
    addContact(&phoneBook, "Park", "010-3333-3333");


    printContacts(phoneBook);

  
    searchContact(phoneBook, "Lee");
    deleteContact(&phoneBook, "Lee");
   
    printContacts(phoneBook);
    freeList(phoneBook);

    return 0;
}