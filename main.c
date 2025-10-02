#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <gpiod.h>
int fd;
int main()
{
fd=open("/dev/ttyS0",O_RDWR | O_NONBLOCK);
   if(fd<0)
    {
        printf("file isn't open\r\n");
        return 0;
    }
    else
    {
        printf("file open succesfully\r\n");


char tx_data[]="12,1000,255\r\n\0";
usleep(500);

tcflush(fd, TCIFLUSH); //clean old data

write(fd,tx_data,strlen(tx_data));

char rx_data[100];
int byte,count=0;
char line[100];

while(1)
{
    byte = read(fd,&rx_data[count],1);
    if(byte>0)
    {
        count++;
        if(count>=strlen(tx_data))
        {
            break;
        }
    }


}
printf("RX-buffer=%s\r\n",rx_data);
sleep(1);

close(fd);
    return 0;
}
}
