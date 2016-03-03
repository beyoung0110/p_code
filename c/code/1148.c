#include<stdlib.h>
#include<stdio.h>

int main() {
    char input[100];
    int num;

    scanf("%d", &num);
    while(num > 0) {
        scanf("%s", input);
        num--;
    }

    return 0;
}
