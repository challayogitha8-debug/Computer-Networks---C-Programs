#include <stdio.h>

int main() {
    int w, i, f, frames[50];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);

    printf("Enter %d frames: ", f);
    for (i = 1; i <= f; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\nWith Sliding Window Protocol, the frames will be sent "
           "in the following manner (assuming no corruption of frames):\n\n");

    printf("After sending %d frames at each stage, the sender waits "
           "for acknowledgement from the receiver.\n\n", w);

    for (i = 1; i <= f; i++) {
        printf("%d ", frames[i]);

        if (i % w == 0) {
            printf("\nAcknowledgement of above frames sent is received by sender.\n\n");
        }
    }
    if (f % w != 0) {
        printf("\nAcknowledgement of above frames sent is received by sender.\n");
    }

    return 0;
}