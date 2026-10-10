int abs(int a) {
    return (a > 0) ? a : -a; 
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
    // diff[v] means how many of those have diffence of v
    int diff[100001];
    memset(diff, 0, sizeof(diff));

    int k = k1 + k2;
    
    int max_id = 0;
    for (int i=0; i<nums1Size; i++) {
        int df = abs(nums1[i] - nums2[i]);
        diff[df] ++;
        max_id = max(max_id, df);
    }

    for (int i=max_id; i>0 && k>0; i--) {
        int move = k > diff[i] ? diff[i] : k;
        diff[i] -= move;
        diff[i-1] += move;
        k -= move;
    }

    long long ans = 0;
    for (long long i=1; i<=max_id; i++) {
        ans += i*i * (long long) diff[i];
    }

    return ans;
}