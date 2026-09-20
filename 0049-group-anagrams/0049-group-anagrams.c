/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct item {
    unsigned char cnt[26];
    int idx;
};


int cmp(const void *a, const void *b) {
    unsigned char *_a = ((struct item *) a) -> cnt;
    unsigned char *_b = ((struct item *) b) -> cnt;
    return memcmp(_a, _b, sizeof(unsigned char) * 26);
}

void build_arr(char **strs, int size, struct item *arr) {
    for (int i=0; i<size; i++) {
        arr[i].idx = i;
        memset(arr[i].cnt, 0, sizeof(arr[i].cnt));
        for (char *c = strs[i]; *c; c ++) {
            arr[i].cnt[(*c) - 'a'] ++;
        }
    }
}

void insert(char ***ans, int gid, int id, char *str, int size) {
    if (id == 0) {
        ans[gid] = malloc(size * sizeof(char *));
    } 
    int sl = strlen(str);
    ans[gid][id] = str;
} 

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    struct item arr[strsSize];
    build_arr(strs, strsSize, arr);
    qsort(arr, strsSize, sizeof(struct item), cmp);
    
    // init 
    char ***ans = malloc(sizeof(char **) * strsSize);
    int gid = -1;
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    memset(*returnColumnSizes, 0, sizeof(int) * strsSize);

    // iter
    unsigned char prev[26];
    memset(prev, -1, sizeof(prev));
    for (int i=0; i<strsSize; i++) {
        if (memcmp(prev, arr[i].cnt, sizeof(prev)) != 0) {
            gid ++;
            (*returnColumnSizes)[gid] = 1;
            memcpy(prev, arr[i].cnt, sizeof(prev));
        } else {
            (*returnColumnSizes)[gid] ++; 
        }
        insert(ans, gid, (*returnColumnSizes)[gid]-1, strs[arr[i].idx], strsSize);
    }

    // result
    *returnSize = gid + 1;
    return ans;
}