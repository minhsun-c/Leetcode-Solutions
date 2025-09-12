int maxProfit(int* prices, int pricesSize) {
    int m = 0, sum = 0;
    for (int i=0; i<pricesSize-1; i++) {
        int diff = prices[i+1] - prices[i];
        if (diff + sum < diff) sum = diff;
        else sum += diff;

        if (sum > m) m = sum;
    }
    return m;
}