#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct { 
    int x; // nums2 value (the multiplier)
    int y; // nums1 value (the element to sum)
} Node;

// Comparison function for qsort: Sort DESCENDING by nums2 (x)
static int cmp_sort(const void *a, const void *b) {
    return ((Node *)b)->x - ((Node *)a)->x; 
}

// --- Simplified Min-Heap Implementation for ONLY nums1 values (y) ---
// Using a simple array-based Min-Heap for k largest elements.
// In a real environment, you'd use a robust library or a slightly cleaner custom implementation.
// For simplicity, we'll keep the required functionality minimal here.

// MAXN must be large enough (e.g., 100005)

#define MAXN 100005
static int heap_values[MAXN]; // Heap stores only nums1 values
static int size = 0;

static void heapifyUp(void) {
    int cur = size - 1;
    while (cur > 0) {
        int p = (cur - 1) / 2;
        // Min-Heap property: parent <= child
        if (heap_values[cur] < heap_values[p]) {
            int t = heap_values[cur];
            heap_values[cur] = heap_values[p];
            heap_values[p] = t;
            cur = p;
        } else break;
    }
}

static void heapifyDown(void) {
    int cur = 0;
    while (true) {
        int l = 2 * cur + 1, r = 2 * cur + 2;
        int s = cur;
        if (l < size && heap_values[l] < heap_values[s]) s = l;
        if (r < size && heap_values[r] < heap_values[s]) s = r;
        if (s == cur) break;
        
        int t = heap_values[cur];
        heap_values[cur] = heap_values[s];
        heap_values[s] = t;
        cur = s;
    }
}

// Pushes a new nums1 value (v) onto the Min-Heap
bool heap_push(int v) {
    if (size >= MAXN) return false; 
    heap_values[size++] = v;
    heapifyUp();
    return true;
}

// Pops the minimum element (root)
int heap_pop(void) {
    if (size == 0) return 0;
    int ret = heap_values[0];                  
    heap_values[0] = heap_values[--size];
    if (size > 0) heapifyDown();
    return ret;
}

// --- Main Function ---

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    long long current_sum = 0;
    long long max_score = 0;
    
    // 1. Prepare and Sort Pairs
    Node *arr = (Node*)malloc(sizeof(Node) * nums1Size);
    if (!arr) return 0;

    for (int i = 0; i < nums1Size; ++i) {
        arr[i].x = nums2[i]; // Multiplier
        arr[i].y = nums1[i]; // Element to sum
    }
    
    // Sort descending by nums2 (arr[i].x)
    qsort(arr, nums1Size, sizeof(Node), cmp_sort);

    // Reset heap state
    size = 0;

    // 2. Iterate and Maintain Max-K Sum with Min-Heap
    for (int i = 0; i < nums1Size; ++i) {
        
        // Add current nums1 value to the sum and the Min-Heap
        int num1_val = arr[i].y;
        heap_push(num1_val);
        current_sum += num1_val;

        // If heap size exceeds k, remove the smallest element (the root)
        if (size > k) {
            int smallest_num1 = heap_pop(); 
            current_sum -= smallest_num1;
        }

        // If we have exactly k elements, calculate the score
        if (size == k) {
            // The multiplier is the current nums2 value (arr[i].x), 
            // which is guaranteed to be the minimum for all elements currently in the heap.
            long long current_score = current_sum * (long long)arr[i].x; 
            max_score = MAX(max_score, current_score);
        }
    }

    free(arr);
    return max_score;
}