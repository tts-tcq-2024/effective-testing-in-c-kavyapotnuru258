#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms < 42) {  // Fixed condition
        sizeName = 'M';
    } else if(cms >= 42) {  // Fixed condition
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'M');  // Modified to test edge case
    assert(size(40) == 'M');
    assert(size(42) == 'L');  // Modified to test edge case
    assert(size(43) == 'L');
    printf("All is well (maybe!)\n");
    return 0;
}
