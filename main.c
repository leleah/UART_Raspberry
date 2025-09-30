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

    return 0;
}
