#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

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
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtMiddle(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    // If list is empty or we insert at the beginning
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Locate the node after which the new node is to be inserted
    struct node *current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    struct node *last = head;
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted the first element.\n");
}

void deleteAtMiddle(int data) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the data was not found
    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from linked list
    if (prev == NULL) {
        head = current->next; // The node to delete is the head
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Deleted the element %d.\n", data);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    struct node *current = head;
    struct node *prev = NULL;

    // If the list contains only one node
    if (current->next == NULL) {
        free(current);
        head = NULL;
        printf("Deleted the last element.\n");
        return;
    }

    // Traverse to the last node
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Unlink the last node
    prev->next = NULL;
    free(current);
    printf("Deleted the last element.\n");
}

int searchData(int data) {
    struct node *p = head;
    while (p != NULL) {
        if (p->data == data) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int main() {
    int ch;
    int data;
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
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", &data);
                insertAtMiddle(data);
                break;
            case 3:
                printf("\nEnter the value to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                printf("\nEnter the value to delete: ");
                scanf("%d", &data);
                deleteAtMiddle(data);
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printList();
                break;
            case 8:
                printf("\nEnter the value to search: ");
                scanf("%d", &data);
                k = searchData(data);
                if (k == 1) {
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
