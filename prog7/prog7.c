#include<stdio.h>
#include<string.h>
int kmp_search(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    int i = 0, j = 0;
    // Build the longest prefix suffix array
    lps[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    // Search for the pattern in the text
    i = 0;
    j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; // Pattern found at index i - j
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1; // Pattern not found
}