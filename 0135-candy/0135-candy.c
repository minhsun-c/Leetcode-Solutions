static inline int max(int a, int b) {
    return a > b ? a : b;
}

int candies[20000];

int candy(int* ratings, int ratingsSize) {
    for (int i=0; i<ratingsSize; i++) candies[i] = 1;

    for (int i=1; i<ratingsSize; i++) 
        if (ratings[i] > ratings[i-1])
            candies[i] =  candies[i-1] + 1;


    for (int i=ratingsSize-1; i>0; i--) 
        if (ratings[i] < ratings[i-1] && candies[i] >= candies[i-1]) 
            candies[i-1] = max(candies[i] + 1, candies[i-1]);
        
    
    
    int k = 0;
    for (int i=0; i<ratingsSize; i++) 
        k += candies[i];
    

    return k;

}