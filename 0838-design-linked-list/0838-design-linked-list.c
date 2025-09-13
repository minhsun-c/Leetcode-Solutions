// struct LNode {
//     int val;
//     struct LNode *next;
// };

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *ll = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    ll -> next = NULL;
    return ll;
}

MyLinkedList* create(int val) {
    MyLinkedList *ll = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    ll -> next = NULL;
    ll -> val = val;
    return ll;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    for (int i=0; obj && i<=index; i++) {
        obj = obj -> next;
    }
    return (obj) ? obj -> val : -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *node = create(val);
    node -> next = obj -> next;
    obj -> next = node;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *node = create(val);
    while (obj -> next) obj = obj -> next;
    obj -> next = node;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *node = create(val);
    for (int i=0; obj && i<index; i++) {
        obj = obj -> next;
    }
    if (obj) {
        node -> next = obj -> next;
        obj -> next = node;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    for (int i=0; obj && i<index; i++) {
        obj = obj -> next;
    }
    if (obj && obj -> next) {
        obj -> next = obj -> next -> next;;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *node;
    while (obj) {
        node = obj;
        obj = obj -> next;
        free(node);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/