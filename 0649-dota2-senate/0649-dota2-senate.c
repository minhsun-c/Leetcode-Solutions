typedef struct queue {
    int q[10005];
    int front, end, size;
} queue_t ; 

queue_t queue[2];

void push(queue_t *obj, int val) {
    obj->q[obj->end] = val;
    obj->end = (obj->end + 1) % 10005;
    obj->size ++;
}

int pop(queue_t *obj) {
    int ret = obj->q[obj->front];
    obj->front = (obj->front + 1) % 10005;
    obj->size --;
    return ret;
}

char* predictPartyVictory(char* senate) {
    memset(queue, 0, sizeof(queue));
    int len = strlen(senate);
    for (int i=0; i<len; i++) {
        if (senate[i] == 'D') push(queue, i);
        else push(queue+1, i);
    }
    while (queue[0].size && queue[1].size) {
        int dtop = pop(queue);
        int rtop = pop(queue+1);
        if (dtop < rtop) { // d wins
            push(queue, len ++);
        } else {
            push(queue+1, len ++);
        }
    }
    return queue[0].size ? "Dire" : "Radiant";
}