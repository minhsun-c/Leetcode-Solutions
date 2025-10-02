#define MAX(a, b) (a > b ? a : b)
int maxProfit(int* prices, int pricesSize, int fee) {
    int buy = INT_MIN, sell = 0;
    for (int i=0; i<pricesSize; i++) {
        buy = MAX(buy, sell - prices[i]);
        sell = MAX(sell, prices[i] + buy - fee);
    }
    return sell;
}