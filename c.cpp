#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
    void asmMain(void);
    char *getTitle(void);
    int readLine(char *dest, int maxLen);
};

int readLine(char *dest, int maxLen) {
    // fgets read at most maxLen-1
    char *result = fgets(dest, maxLen, stdin);
    if (result != NULL) {
        int len = strlen(result);
        if (len > 0) {
            // Wipe out the newline character at the end.
            result[len - 1] = 0;
        }
        return len;
    }
    return -1;
}

int main(void) {
    try {
        char *title = getTitle();
        printf("Calling %s:\n", title);
        asmMain();
        printf("%s terminated\n", title);
    }
    catch (...) {
        printf
        (
            "Exception occurred during program execution\n"
            "Abnormal program termination.\n"
        );
    }
}