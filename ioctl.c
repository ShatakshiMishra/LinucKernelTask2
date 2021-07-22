#include "head.h"
#define WR_DATA _IOW('a','a',int32_t*)
#define RD_DATA _IOR('a','b',int32_t*)
int main()
{
        int fd,num;
        int32_t val;
        printf( "\n ioctl character device driver ops from user space");
        fd=open("/dev/mydriver5",O_RDWR);
        if(fd<0)
        {
                printf( "\n cannot open device file\n");
                return 0;
        }
        printf( "Enter value to send /n");
        scanf("%d",&num);
        printf("writing value to the driver\n");
       ioctl(fd,WR_DATA,(int32_t*)&num);
printf("reading from driver \n");
 ioctl(fd,RD_DATA,(int32_t*)&val);
 printf("val = %d\n",val);
 printf("closing driver\n");
 close(fd);
return 0;
}
