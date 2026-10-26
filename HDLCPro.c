#include <stdio.h>
#include <string.h>
typedef struct {
    unsigned char flag;              
    unsigned char address;           
    unsigned char control;           
    unsigned char information[256];  
    unsigned short crc;              
    unsigned char flag_end;         
} HDLC_Frame;
unsigned short calculate_crc(unsigned char *data, int length)
{
    unsigned short crc = 0xFFFF;
    int i;

    for (i = 0; i < length; i++) {
        crc = (crc >> 8) ^ (crc & 0xFF) ^ data[i];
    }

    return crc;
}
HDLC_Frame create_hdlc_frame(unsigned char address,
                             unsigned char control,
                             unsigned char *data,
                             int length)
{
    HDLC_Frame frame;

    frame.flag = 0x7E;
    frame.address = address;
    frame.control = control;
    memset(frame.information, '\0', sizeof(frame.information));
    memcpy(frame.information, data, length);
    frame.crc = calculate_crc(data, length);

    frame.flag_end = 0x7E;

    return frame;
}
void send_hdlc_frame(HDLC_Frame frame)
{
    int i;

    printf("\nSending HDLC Frame:\n");
    printf("Flag       : 0x%X\n", frame.flag);
    printf("Address    : 0x%X\n", frame.address);
    printf("Control    : 0x%X\n", frame.control);

    printf("Information: ");
    for (i = 0; i < 256 && frame.information[i] != '\0'; i++) {
        printf("%c", frame.information[i]);
    }

    printf("\nCRC        : 0x%X\n", frame.crc);
    printf("End Flag   : 0x%X\n", frame.flag_end);
}

int main()
{
    unsigned char address = 0x01;
    unsigned char control = 0x03;
    unsigned char data[] = "Hello, Yogitha Reddy!";
    int length;

    length = strlen((char *)data);

    HDLC_Frame frame =
        create_hdlc_frame(address, control, data, length);

    send_hdlc_frame(frame);

    return 0;
}