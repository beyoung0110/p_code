#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void myStrcpy(char* origin, char* new) {
    while( (*new = *origin) != '\0' ) {
        printf("new : %s\n", new);
        printf("origin : %s\n", origin);
        new++;
        origin++;
    }
    return;
}
int main() {
    char *str2 = "Second string";
    char *str = malloc(strlen(str2) + 1);
    myStrcpy(str2, str);
    printf("str : %s\n", str);
    free(str);
    return 0;
}
