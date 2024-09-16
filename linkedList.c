#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
    struct node *p = head;
    printf("\n[ ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
}

void insertAtBegin(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    if (lk == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    lk->data = data;
    lk->next = head;
    head = lk;
}

void insertAtMiddle(int data) {
    printf("Working!");
}

void insertAtEnd(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    struct node *last = head;
    if (lk == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    lk->data = data;
    lk->next = NULL;
    
    if (head == NULL) {
        head = lk;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = lk;
    
}

void deleteAtBegin() {
    printf("Working!");
}

void deleteAtMiddle(int data) {
    printf("Working!");
}

void deleteAtEnd() {
    printf("Working!");
}

int searchData(int Data) {
    struct node *p = head;
    while (p != NULL) {
        if(p->data == Data){
        	return 1;
		}
        p = p->next;
    }
    return 0;
}

int main() {
    int ch;
    int Data;
    int k = 0;
    do {
        printf("\nLinked List Operations: ");
        printf("\n1. Insertion at Beginning\n2. Insertion at Middle\n3. Insertion at End");
        printf("\n4. Deletion at Beginning\n5. Deletion at Middle\n6. Deletion at End");
        printf("\n7. Show the List\n8. Search the Element\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &Data);
                insertAtBegin(Data);
                break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", &Data);
                insertAtMiddle(Data);
                break;
            case 3:
                printf("\nEnter the value to insert: ");
                scanf("%d", &Data);
                insertAtEnd(Data);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                printf("\nEnter the value to delete: ");
                scanf("%d", &Data);
                deleteAtMiddle(Data);
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printList();
                break;
            case 8:
                printf("\nEnter the value to search: ");
                scanf("%d", &Data);
                k = searchData(Data);
                if(k == 1){
                	printf("\nElement found!\n");
				} else {
					printf("\nElement Not found!\n");
				}
                break;
            case 9:
                printf("\nExiting......\n");
                break;
            default:
                printf("Invalid Request made! Try again.\n");
        }
    } while (ch != 9);

    return 0;
}
