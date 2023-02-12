// C++ driver program

#include <stdio.h>

extern "C" {
    void asmFunc(void);
};

int main(void) {
    asmFunc();
    // printf("Returned from asmFunc\n");
}