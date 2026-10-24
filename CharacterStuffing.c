#include <stdio.h>
#include <string.h>

int main() {
    int i, j, n, m;
    char a[50], b[150], c[100];

    printf("Enter the string in upper case to transmit: ");
    scanf("%49s", a);

    n = strlen(a);

    printf("\nStuffing...\n");
    strcpy(b, "DLESTX");
    j = strlen(b);

    i = 0;
    while (i < n) {
        if (a[i] == 'D' &&
            a[i + 1] == 'L' &&
            a[i + 2] == 'E') {

            b[j++] = 'D';
            b[j++] = 'L';
            b[j++] = 'E';
        }

        b[j++] = a[i++];
    }

    b[j] = '\0';
    strcat(b, "DLEETX");

    printf("Frame after stuffing: %s\n", b);

    m = strlen(b);

    printf("\nDestuffing...\n");
    printf("Length of stuffed frame = %d\n", m);

    i = 6;   
    j = 0;
    while (i < m - 6) {
        if (b[i] == 'D' &&
            b[i + 1] == 'L' &&
            b[i + 2] == 'E' &&
            b[i + 3] == 'D' &&
            b[i + 4] == 'L' &&
            b[i + 5] == 'E') {

            c[j++] = 'D';
            c[j++] = 'L';
            c[j++] = 'E';
            i += 6;
        } else {
            c[j++] = b[i++];
        }
    }

    c[j] = '\0';

    printf("Frame after destuffing: %s\n", c);

    return 0;
}