#include <stdlib.h>
typedef struct LinkedListNode {
    struct LinkedListNode *next;
    struct LinkedListNode *prev;    
    void *data;
} LinkedListNode;

LinkedListNode *head = NULL;
LinkedListNode *tail = NULL;

