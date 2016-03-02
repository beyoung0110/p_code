#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26
typedef enum {
    false, 
    true
} bool;

typedef struct trieNode* TrieNode;
struct trieNode {
    TrieNode    trieNode[MAX];   // child node
    int         len;             // words number that begin with this value.
    bool        isWord;          // contains current value is a word.
};

TrieNode initTrieNode() {
    int i = 0;
    TrieNode trieNodeNew  = (TrieNode) malloc(sizeof(struct trieNode));
    trieNodeNew->len      = 0;
    trieNodeNew->isWord   = false;
    for(i = 0; i < MAX; i++) {
        trieNodeNew->trieNode[i] = NULL;
    }
    return trieNodeNew;
}

void buildTrieTree(const char* input, TrieNode root) {
    if (root == NULL || *input == '\0') {
        return;
    }
    TrieNode p  = root;

    while(*input != '\0') {
        int index = *input - 'a';
        if(p->trieNode[index] == NULL) {
            TrieNode trieNode = initTrieNode();
            p->trieNode[index] = trieNode; //soga!!!
        }
        p = p->trieNode[index];
        p->len++;
        input++;
    }
    p->isWord = true;
    return ;
}

int findPrefixNumInTrieTree(const char* input, TrieNode root) {
    if (root == NULL || *input == '\0') {
        return 0;
    }
    TrieNode p  = root;

    while(p != NULL && *input != '\0') {
        int index = *input - 'a';
        if(p->trieNode[index] == NULL)
            return 0;
        p = p->trieNode[index];
        input++;
    }
    return p->len;
}

void destoryTrieTree(TrieNode root) {
    int i = 0;
    for(i = 0; i < MAX; i++) {
        if(root->trieNode[i] != NULL) {
            destoryTrieTree(root->trieNode[i]);
        }
    }
    free(root);
    return;
}

int main() {
    int num     = 0;
    int len     = 0; 
    char input[100]; // should set inout[100] here.

    TrieNode root = NULL;
    root = initTrieNode(); 

    scanf("%d", &num);
    while(num > 0) {
        scanf("%s", input);
        buildTrieTree(input, root);
        num--;
    }

    scanf("%d", &num);
    while(num > 0) {
        scanf("%s", input);
        len = findPrefixNumInTrieTree(input, root);
        printf("%d\n", len);
        num--;
    }
    printf("\n");
    destoryTrieTree(root);
    return 0;
}
