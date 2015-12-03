#include <stdio.h>
int lengthOfLastWord(char* s) {
/*    if(s == NULL) return 0;
        int begin = 0;
        int end = 0;
        int cur = 0;
                    
       while(s[cur] != '\0') {
            while(s[cur] == ' ') 
                cur++;
            if(s[cur] != '\0') begin = cur;
            while(s[cur] != ' ' && s[cur] != '\0') 
                cur++;
            end = cur - 1;
       }
       
      return begin == 0 ? 0 : (end - begin + 1);     
*/
    int len = 0;
        while (*s) {
            if (*s++ != ' ') len++;
            else if (*s && *s != ' ') len = 0;
        }
    return len;
}

int main() {
    char *s = "a ";
    int len = lengthOfLastWord(s);
    printf("len : %d", len);
    return 0;
}
