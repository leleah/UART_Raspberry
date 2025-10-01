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
    const char *chipname = "gpiochip0";
    int line_num =5;
    struct gpiod_chip *chip;
    struct gpiod_line *line;

    chip=gpiod_chip_open_by_name(chipname);
    if(!chip)
    {
        printf("Failed chip\n");
        return 1;
    }
    printf("chip open\n");
    line=gpiod_chip_get_line(chip,line_num);
    if(!line)
    {
        printf("Failed line\n");
        return 1;
    }
    printf("line open\n");

    if(gpiod_line_request_output(line,"blink",0)<0)
    {
        printf("request line failed\n");
        gpiod_chip_close(chip);
        return 1;
    }

fd=open("/dev/ttyS0",O_RDWR | O_NONBLOCK);
   if(fd<0)
    {
        printf("file isn't open\r\n");
        return 0;
    }
    else
        {
            printf("file open succesfully\r\n");


char tx_data[]="12,1000,255\r\n";
write(fd,tx_data,strlen(tx_data));
char rx_data[100];
for (int i=0; i<100; i++)
{
    gpiod_line_set_value(line,1);
    //read(fd,rx_data,sizeof(rx_data));
    int pos=0;
    char line[pos];
    if(line[pos]<sizeof(line)-1)
    {
        if(line[pos]='\n')
        {
            line[pos]='\0';
        }
        line[pos++]=rx_data[i];
    }
/*printf("%d\r\n",line[pos]);
printf("%s\r\n",rx_data);*/
sleep(1);
}
read(fd,rx_data,sizeof(rx_data));
gpiod_line_set_value(line,0);
//printf("%d\n\r",read(fd,rx_data,sizeof(rx_data)));
//perror("read");
printf("%s\r\n",rx_data);
close(fd);
    return 0;
}
}
