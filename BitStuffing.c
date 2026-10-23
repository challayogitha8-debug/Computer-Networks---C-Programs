#include <stdio.h>
#include <string.h>

int main() {
    char in[50], st[100], de[100];
    int i, count = 0, j = 0, k = 0;

    printf("Enter the binary string to stuff: ");
    scanf("%49s", in);

    printf("\nStuffing...\n");
    strcpy(st, "01111110");
    j = strlen(st);
    for (i = 0; in[i] != '\0'; i++) {
        st[j++] = in[i];

        if (in[i] == '1') {
            count++;
            if (count == 5) {
                st[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    strcpy(&st[j], "01111110");

    printf("String after stuffing: %s\n", st);

    printf("\nDestuffing...\n");
    count = 0;

    for (i = 8; i < (int)strlen(st) - 8; i++) {
        de[k++] = st[i];

        if (st[i] == '1') {
            count++;
            if (count == 5) {
                if (st[i + 1] == '0') {
                    i++;
                }
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    de[k] = '\0';

    printf("String after destuffing: %s\n", de);

    return 0;
}