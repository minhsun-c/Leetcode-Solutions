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

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/