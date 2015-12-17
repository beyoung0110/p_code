#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    false, 
    true
} bool;

typedef struct trieNode* TrieNode;
struct trieNode {
    TrieNode    trieNode;   // child node
    int         trieNum;    // child node number.
    int         prefixNum;  // words number that begin with this value.
    char        value;      // value of the node.
    bool        isWord;     // contains current value is a word.
};

TrieNode initTrieNode() {
    TrieNode trieNodeNew    = (TrieNode) malloc(sizeof(struct trieNode));
    trieNodeNew->trieNode   = (TrieNode) malloc(26*sizeof(struct trieNode));
    trieNodeNew->trieNum    = 0;
    trieNodeNew->prefixNum  = 0;
    trieNodeNew->value      = 0x0;
    trieNodeNew->isWord     = false;
    return trieNodeNew;
}
void buildTrieTree(char* nextValues, TrieNode parentNode) {
    bool needAddNew = true;
    int i = 0;
    if(nextValues == NULL || (strncmp(nextValues, "", 1) == 0 )) {
        if(parentNode == NULL) {
            return;
        } else {
           parentNode->isWord = true;
           return;
        }
    }

    int num = parentNode->trieNum;
    for(i = 0; i < num; i++) {
        if(parentNode->trieNode[num].value == nextValues[0]) {
            needAddNew = false;
            parentNode->trieNode[i].prefixNum++;
            buildTrieTree(&nextValues[1], &parentNode->trieNode[i]);
        }
    }

    if (needAddNew) {
        parentNode->trieNum++;
        parentNode->trieNode[num].prefixNum = 1;
        parentNode->trieNode[num].value = nextValues[0];
        parentNode->trieNode[num].trieNode = (TrieNode) malloc(26*sizeof(struct trieNode));
        buildTrieTree(&nextValues[1], &parentNode->trieNode[num]);
    }
    return ;
}

//void findPrefixNumInTrieTree(char* input, TrieNode* trieTree) {
//}

int main() {
    int num = 0;
    char *input = NULL;
    TrieNode root = NULL;

    root = initTrieNode(); 

    scanf("%d", &num);
    while(num > 0) {
        scanf("%s", input);
        buildTrieTree(input, root);
        num--;
    }

    scanf("%s", input);
/*    char *input1 = "fs";
    char *input2 = "fsd";
    TrieNode root = NULL;
    root = initTrieNode(); 
    buildTrieTree(input1, root);
    buildTrieTree(input2, root);
*/
    //    findPrefixNumInTrieTree(input, trieTree);

    return 0;
}


