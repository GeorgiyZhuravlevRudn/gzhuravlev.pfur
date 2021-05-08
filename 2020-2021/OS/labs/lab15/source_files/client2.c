#include "common.h"
#define MESSAGE "not yet\n"

int main()
{
    int writefd;
    int msglen;

    printf("FIFO Client 2...\n");

    if((writefd = open(FIFO_NAME, O_WRONLY))==-1)
    {
        printf("can't open");
        return 1;
    }

    msglen = strlen(MESSAGE);
    int n=0;
    while(n<5){
        if(write(writefd, MESSAGE, msglen) != msglen)
        {
            printf("can't write");
            return 2;
        }
        printf("next message will appear in 5 seconds\n");
        sleep(5);
        n++;
        }

        close(writefd);
        return 0;
}
