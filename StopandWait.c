 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 1, j = 1;
    int noframes = 5;
    int x;

    printf("\nNumber of frames is %d\n", noframes);
    srand(time(NULL));

    while (noframes > 0) {
        printf("\nSending frame %d", i);

        x = rand() % 10;
        if (x % 2 == 0) {
            printf("\nFrame %d lost. Resending frame %d", i, i);
        }

        printf("\nACK received for frame %d\n", j);

        noframes--;
        i++;
        j++;
    }

    printf("\nEnd of Stop and Wait Protocol\n");

    return 0;
}