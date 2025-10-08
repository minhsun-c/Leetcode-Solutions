/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TNode {
    struct TNode *next[26]; 
    bool end;
};

typedef struct Trie{
    struct TNode *root;
} Trie;

struct TNode* nodeCreate() {
    struct TNode *node = (struct TNode *)malloc(sizeof(struct TNode));
    for (int i=0; i<26; i++) 
        node->next[i] = NULL;
    node->end = false;
    return node;
}

Trie* trieCreate() {
    Trie *obj = (Trie *)malloc(sizeof(Trie));
    obj->root = NULL;
    return obj;
}

void trieInsert(Trie* obj, char* word) {
    struct TNode **ptr = &(obj->root);
    int len = strlen(word);
    for (int i=0; i < len; i++) {
        if (! *ptr) *ptr = nodeCreate();
        ptr = &((*ptr)->next[word[i] - 'a']);
        if (i == len - 1) {
            if (! *ptr) *ptr = nodeCreate();
            (*ptr)->end = true; 
        }
    }
}

bool trieSearch(Trie* obj, char* word) {
    struct TNode *ptr = (obj->root);
    int len = strlen(word);
    for (int i=0; i < len; i++) {
        if (!ptr) return false;
        ptr = ptr->next[word[i] - 'a'];
    }
    return (ptr && ptr->end);
}

bool trieStartsWith(Trie* obj, char* prefix) {
    struct TNode *ptr = (obj->root);
    int len = strlen(prefix);
    for (int i=0; i < len; i++) {
        if (!ptr) return false;
        ptr = ptr->next[prefix[i] - 'a'];
    }
    return ptr != NULL;
}

void nodeFree(struct TNode *root) {
    if (!root) return;
    for (int i=0; i<26; i++) nodeFree(root->next[i]);
    free(root);
}

void trieFree(Trie* obj) {
    nodeFree(obj->root);
    free(obj);
}

// --- assume your trie code is present above ---
// (TNode, Trie, nodeCreate, trieCreate, trieInsert, trieFree, etc.)

static char *xstrdup(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = (char *)malloc(n);
    if (p) memcpy(p, s, n);
    return p;
}

// Return node at end of prefix, or NULL if prefix doesn't exist in trie
static struct TNode* getPrefixNode(Trie *obj, const char *prefix) {
    struct TNode *ptr = obj->root;
    for (const char *p = prefix; *p; ++p) {
        if (!ptr) return NULL;
        ptr = ptr->next[*p - 'a'];
    }
    return ptr;
}

// DFS from `node`, appending letters to `buf` (len current length), pushing up to 3 results
static void dfsCollect(struct TNode *node, char *buf, int len,
                       char **row, int *taken) {
    if (!node || *taken >= 3) return;

    if (node->end) {
        // buf currently holds a full word
        row[*taken] = xstrdup(buf);
        (*taken)++;
        if (*taken >= 3) return;
    }

    for (int i = 0; i < 26 && *taken < 3; ++i) {
        if (node->next[i]) {
            buf[len] = (char)('a' + i);
            buf[len + 1] = '\0';
            dfsCollect(node->next[i], buf, len + 1, row, taken);
        }
    }
}

char*** suggestedProducts(char** products, int productsSize,
                          char* searchWord, int* returnSize,
                          int** returnColumnSizes) {
    // 1) Build trie with all products
    Trie *tr = trieCreate();
    for (int i = 0; i < productsSize; ++i) {
        trieInsert(tr, products[i]);
    }

    int L = (int)strlen(searchWord);
    *returnSize = L;

    // Allocate result containers
    int *colSizes = (int *)malloc(sizeof(int) * L);
    *returnColumnSizes = colSizes;

    char ***ans = (char ***)malloc(sizeof(char **) * L);

    // Work buffer to hold current prefix/word. Max product length can be large,
    // but we only need to extend from the current prefix while DFSing.
    // To be safe for constraints, allocate enough:
    int maxBuf = 3100; // >= max product len
    char *buf = (char *)malloc(maxBuf);

    // 2) For each prefix of searchWord…
    for (int i = 0; i < L; ++i) {
        // Build current prefix string
        memcpy(buf, searchWord, i + 1);
        buf[i + 1] = '\0';

        // Find node at end of prefix
        struct TNode *prefNode = getPrefixNode(tr, buf);

        // Collect up to 3 words in lexicographic order via DFS
        int taken = 0;
        char **row = (char **)malloc(sizeof(char *) * 3); // at most 3
        if (prefNode) {
            // buf currently holds the prefix; dfsCollect will extend it
            dfsCollect(prefNode, buf, i + 1, row, &taken);
        }
        // Shrink to exact size if fewer than 3
        if (taken < 3) {
            row = (char **)realloc(row, sizeof(char *) * taken);
        }

        ans[i] = row;
        colSizes[i] = taken;
    }

    free(buf);
    trieFree(tr); // safe: suggestions were strdup'ed

    return ans;
}
