#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *value;
    int *minValue;
    int maxSize;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->value = (int *)malloc(sizeof(int));
    stack->minValue = (int *)malloc(sizeof(int));
    stack->value[0] = 0;
    stack->minValue[0] = 0;
    stack->maxSize = maxSize;
}

void minStackPush(MinStack *stack, int element) {
    if(stack->value == stack->maxSize) return;
    if(stack->minValue[0] == 0 || element < stack->minValue[stack->minValue[0]]) {
        stack->minValue[++stack->minValue[0]] = element;
    }
    stack->value[++stack->value[0]] = element;
    return ;
}

/*void minStackPop(MinStack *stack) {
    if(stack->value == 0) return;
    if(stack->value[stack->value] == stack->minValue[stack->minValue]) {
        free(stack->minValue[stack->minValue]);
        stack->minValue--;
    }
    free(stack->value[stack->value]);
    stack->value--;
}

int minStackTop(MinStack *stack) {
    return stack->value[stack->value]; 
}

int minStackGetMin(MinStack *stack) {
    return stack->minValue[stack->minValue];
}

void minStackDestroy(MinStack *stack) {
    free(stack);
}*/

int main() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    minStackCreate(stack, 10);
    minStackPush(stack, -3);
}
