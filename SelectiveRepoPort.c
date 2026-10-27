#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Enter the number of frames: ");
    scanf("%d", &n);

    int received[n];

    printf("\nSending frames...\n");

    for (i = 0; i < n; i++)
    {
        printf("Frame %d received successfully? (1 = Yes, 0 = No): ", i + 1);
        scanf("%d", &received[i]);

        if (received[i] == 1)
        {
            printf("Acknowledgement received for frame %d.\n", i + 1);
        }
        else
        {
            printf("Frame %d lost. It will be retransmitted.\n", i + 1);
        }
    }

    printf("\nRetransmitting lost frames...\n");

    for (i = 0; i < n; i++)
    {
        if (received[i] == 0)
        {
            printf("Retransmitting frame %d...\n", i + 1);

            received[i] = 1;

            printf("Acknowledgement received for frame %d.\n", i + 1);
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}