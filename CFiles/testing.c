#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char buff[] = "Hello World!\n";
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write(fd, buff, strlen(buff));
    close(fd);
    return 0;
}