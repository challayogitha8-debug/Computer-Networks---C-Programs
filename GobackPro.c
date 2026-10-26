#include <stdio.h>

int main() {
    int window_size, sent = 0, ack, i;

    printf("Enter window size: ");
    scanf("%d", &window_size);

    while (1) {
        for (i = 0; i < window_size; i++) {
            printf("Frame %d has been transmitted\n", sent);
            sent++;

            if (sent == window_size) {
                break;
            }
        }

        printf("\nPlease enter the acknowledgement received: ");
        scanf("%d", &ack);

        if (ack == window_size) {
            break;
        } else {
            sent = ack;
        }
    }

    printf("\nAll frames have been successfully transmitted.\n");

    return 0;
}