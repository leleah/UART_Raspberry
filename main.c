#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
int fd;
int main()
{
fd=open("/dev/ttyS0",O_RDWR);
   if(fd<0)
    {
        printf("file isn't open");
        return 0;
    }
    else
        {
            printf("file open succesfully");
            return 1;
        }
const char tx_data[]="12,1000,255";
write(fd,tx_data,srtlen(tx_data));
close(fd);
    return 0;
}
