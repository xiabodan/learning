#include <pthread.h>
#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pthread_mutex_t mymutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mymutex2  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mymutex3  = PTHREAD_MUTEX_INITIALIZER;

int test() {
    int a = 100;
    int *b = &a;
    std::cout << "\n " << b;
    std::cout << "\n ";
}

int main() {
    std::set<pthread_mutex_t*> myset;

    myset.insert(&mymutex);
    myset.insert(&mymutex2);
    myset.insert(&mymutex3);

    for (std::set<pthread_mutex_t*>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << "\n " << *it;
    int fd = open("./mytest.cpp1", O_WRONLY|O_CREAT);
    test();
    std::cout << "\n " << getppid();
    std::cout << "\n ";
    while(1) {
        sleep(1);
    }
    return 0;
}
