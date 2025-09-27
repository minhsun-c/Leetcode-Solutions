typedef struct {
    int stack[10005];
    int span[10005];
    int top;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));
    memset(obj->span, 0, sizeof(obj->span));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int ret = 1;
    while (obj->top >= 0 && obj->stack[obj->top] <= price) {
        ret += obj->span[obj->top];
        obj->top --;
    }
    obj->top ++;
    obj->stack[obj->top] = price;
    obj->span[obj->top] = ret;
    return ret;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/