#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma GCC optimize("O3")

void backtrack(char* s, int start, int segment, char* current, int currLen, char** result, int* returnSize) {
    int sLen = strlen(s);

    // If 4 segments found and string fully consumed
    if (segment == 4) {
        if (start == sLen) {
            current[currLen - 1] = '\0'; // Overwrite trailing dot
            result[*returnSize] = (char*)malloc((currLen) * sizeof(char));
            strcpy(result[*returnSize], current);
            (*returnSize)++;
        }
        return;
    }

    int num = 0;
    for (int len = 1; len <= 3 && start + len <= sLen; len++) {
        // Leading zero constraint: segment length > 1 starting with '0' is invalid
        if (len > 1 && s[start] == '0') break;

        num = num * 10 + (s[start + len - 1] - '0');
        if (num > 255) break;

        // Copy digits to buffer
        for (int i = 0; i < len; i++) {
            current[currLen + i] = s[start + i];
        }
        current[currLen + len] = '.';

        backtrack(s, start + len, segment + 1, current, currLen + len + 1, result, returnSize);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    int len = strlen(s);

    // An IPv4 string must have length between 4 and 12 digits
    if (len < 4 || len > 12) return NULL;

    // Allocate results array (max 19 valid combinations possible)
    char** result = (char**)malloc(20 * sizeof(char*));
    char current[16]; // Max IP length is 15 ("255.255.255.255") + null terminator

    backtrack(s, 0, 0, current, 0, result, returnSize);

    return result;
}