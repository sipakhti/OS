#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
int size = 0;

void push(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
    return;
}

int pop()
{
    if (head == NULL) return -1;
    int data = tail->data;
    delete(tail);
    return data;
}

Node* search(int data)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == data) return curr;
        curr = curr->next;
    }
    return NULL;
}

void deleteNode(Node *node)
{
    if (node == NULL) return;
    if (node->prev != NULL) node->prev->next = node->next;
    if (node->next != NULL) node->next->prev = node->prev;
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;
    size--;
    free(node);
    return;
}



void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main(int argc, char** argv)
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    pop();
    print();
    printf("Hello World\n");
    return 0;
}