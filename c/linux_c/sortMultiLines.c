#include <stdio.h>
#include <string.h>

#define MAXLINES 50

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right, int (*comp)(void *, void *));

int main() {
    int nlines;
    int numeric = 0;

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if((nlines = readlines(ineptr, MAXLINES)) >= 0) {
       // qsort((void **) lineptr, 0, nlines - 1,
       // (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        wirtelines(lineprt, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for(i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}


//void qsort(char *lineptr[], int left, int right) {

//}
