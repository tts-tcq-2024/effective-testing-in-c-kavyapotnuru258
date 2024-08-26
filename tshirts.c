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
    printf("Size for 37 cm: %c\n", size(37)); // Expected output: S
    assert(size(37) == 'S');

    printf("Size for 38 cm: %c\n", size(38)); // Expected output: M
    assert(size(38) == 'M');

    printf("Size for 40 cm: %c\n", size(40)); // Expected output: M
    assert(size(40) == 'M');

    printf("Size for 42 cm: %c\n", size(42)); // Expected output: L
    assert(size(42) == 'L');

    printf("Size for 43 cm: %c\n", size(43)); // Expected output: L
    assert(size(43) == 'L');

    printf("All is well (maybe!)\n");
    return 0;
}

