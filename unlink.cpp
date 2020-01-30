#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    FILE* file = fopen("2",  "r");
    char buff[1024];
    if (file != nullptr) {
        unlink("2"); // unlink函数删除目录项，并且减少一个链接数。如果链接数达到0并且没有任何进程打开该文件，该文件内容才被真正删除。如果在unlilnk之前没有close，那么依旧可以访问文件内容。

        sleep(5);
        while ((fgets(buff, 1024, file)) != NULL) {
            printf("fgets %s\n", buff);
        }
    }

    while(1){}
}
