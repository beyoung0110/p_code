#include <stdio.h>

struct multiChar {
    char* char1;
    char* char2;
};

char* getLocalStaticVar() {
    static char* localStaticString;
    static struct multiChar multiChar;

    if (localStaticString != NULL) {
        free(localStaticString);
    }
    localStaticString = (char *)malloc(10*sizeof(char));
    localStaticString[0] = 'a';
    localStaticString[1] = 'b';
    free(multiChar.char1);
    free(multiChar.char2);

    printf("the end\n");
    return localStaticString;
}

void main() {
    char* getVar = getLocalStaticVar();
    getVar++;
    printf("var1 : %s\n", getVar);
    char* getVar1 = getLocalStaticVar();
    printf("var2 : %s\n", getVar1);
    return;
}
