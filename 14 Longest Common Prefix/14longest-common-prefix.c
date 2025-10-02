#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0 || strs == NULL) {
        char *empty_str = malloc(1);
        empty_str[0] = '\0';
        return empty_str;
    }
    int i = 0;
    
    while (strs[0][i] != '\0') {
        for (int j = 1; j < strsSize; j++) {
            
            if (strs[j][i] == '\0' || strs[0][i] != strs[j][i]) {
                
                char *res = (char*)malloc(i + 1);
                strncpy(res, strs[0], i);
                res[i] = '\0';
                
                return res;
            }
        }
        i++;
    }
    char *res = (char*)malloc(i + 1);
    strcpy(res, strs[0]);
    return res;
}