#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
int main()
{
    if(!open("/dev/serial0",O_RDWR))
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
