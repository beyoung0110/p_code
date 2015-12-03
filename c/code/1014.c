#include <stdio.h>

struct trieNode {
    TrieNode* trieNode;
    int trieNum;
    int prefix;
    char value;
    bool isWord;
} TrieNode

int main() {
    char* input;
    TrieNode* trieTree;
    int num = 0;

    trieTree = (TreeNode *) malloc(sizeof(TrieNode));

    scanf("%d", &num);
    while(num >= 0) {
        scanf("%s", input);
        buildTrieTree(input, trieTree);
    }

    while(input) {
        findPrefixNumInTrieTree(input, trieTree);
    }

    return 0;
}

void buildTrieTree(char* input, TrieNode* trieTree) {
    if(intput == NULL) {
        if(trieTree == NULL) {
            return;
        } else {
           trieTree->isWord = true;
        }
    }

    int num = trieTree->trieNum - 1;
    while(num >= 0){
        if(trieTree->trieNode[num].value == *input) {
            trieTree->trieNode[num]->prefix++;
            buildTrieTree(&input[num+1], &trieTree[num]);
        }
        num--;
    }

    TrieNode *trieNodeNew = (TreeNode *) malloc(sizeof(TrieNode));
    trieNodeNew->trieNode = NULL;
    trieNodeNew->trieNum  = 0;
    trieNodeNew->prefix   = 1;
    trieNodeNew->value    = *input;
    trieNodeNew->isWord   = false;

    trieTree->trieNode[trieTree->trieNum++] = trieNodeNew;
    buildTrieTree(&input[num+1], &trieTree[num])
    
}

void findPrefixNumInTrieTree(char* input, TrieNode* trieTree) {

}
