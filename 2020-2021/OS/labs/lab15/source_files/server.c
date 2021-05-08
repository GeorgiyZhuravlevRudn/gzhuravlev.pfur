#include "common.h"

int main(){

    int readfd;
    char buff[MAX_BUFF];
    int n;

    printf("FIFO Server...\n");
    if(mkfifo(FIFO_NAME,0777)==-1){
        if(errno!=EEXIST){
            printf("impossible to create fifo\n");
            return 1;
        };
    }

    printf("Open...\n");
    if((readfd = open(FIFO_NAME,O_RDONLY))==-1){
        printf("can't open");
        return 2;
    };
    printf("opened\n");

    while((n = read(readfd,buff,MAX_BUFF))>0){
        if(write(1,buff,n)!=n){
            printf("can't open");
            return 3;
        }
    }
    close(readfd);

    if(unlink(FIFO_NAME)==-1){
        printf("can't delete");
        return 4;
    }
    return 0;
}
