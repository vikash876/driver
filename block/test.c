#include <stdio.h>
#include <fcntl.h>


void main()
{
    char *dev = "/dev/sda";
    int fd;
    char buffer[20];
    int i;

    fd = open(dev, O_RDONLY);
    if(fd == -1) {
        printf("Could not open device file\n");
    }
    lseek(fd, 510, SEEK_SET);
    read(fd, buffer, 2);
    for(i=0;i<2;i++)
    printf("%x ", buffer[i]);
}
