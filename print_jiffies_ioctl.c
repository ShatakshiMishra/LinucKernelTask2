#include "head.h"
#define RD_DATA _IOR('a','b',int32_t*)
int main()
{
        int fd,num;
        int32_t val;
        printf( "\n ioctl character device driver ops from user space");
        fd=open("/dev/jiffies_driver",O_RDWR);
        if(fd<0)
        {
                printf( "\n cannot open device file\n");
                return 0;
        }
printf("reading from driver \n");
 ioctl(fd,RD_DATA,(int32_t*)&val);
 printf("val of jiffies  = %d\n",val);
 printf("closing driver\n");
 close(fd);
return 0;
}
