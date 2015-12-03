#include <stdio.h>

struct point {
    int x;
    int y;
};

union tag {
    int ival;
    char cval[2];
};

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int add(int x, int y) {
    x = x + y;
    return x;
}

struct point* addpoint(struct point* x, struct point* y) {
    x->x += y->x;
    x->y += y->y;
    return x;
} 

int checkSystem( )
{
   union check
   {
        int i;
        char ch;
    } c;
    c.i = 1;
    return (c.ch ==1);
}

int main(void) {
    int x = 3;
    int y = 7;
    int z = add(x, y);
    printf("x : %d, y : %d, z : %d\n", x, y, z);
    
//    struct point x1 = makepoint(3, 4);
//    struct point y1 = makepoint(5, 6);
    struct point x1 = {3, 4};
    struct point y1 = {5, 6};
    struct point* z1 = addpoint(&x1, &y1);
    printf("x1.x : %d, x1,y : %d, y1.x : %d, y1.y : %d, z1.x : %d, z1.y : %d\n", x1.x, x1.y, y1.x, y1.y, z1->x, z1->y);
  
    union tag t;
    t.cval[0] = '0';
    t.cval[1] = '1';
    printf("tag.cval[0] : %d, tag.cval[1] : %d, tag.ival : %d\n", t.cval[0], t.cval[1], t.ival);
    int isSmallEnd = checkSystem();
    printf("is small end : %d\n", isSmallEnd);
    return 0;

}
