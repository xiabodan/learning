#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <netdb.h>
#include "a.h"

int myintvar = 5;

int __attribute__ ((visibility ("hidden")))  func0 () {
// int func0 () {
      return ++myintvar;
}
 
int func1 (int i) {
    printf("func1 addr %p\n", func1);
    printf("getaddrinfo addr %p\n", getaddrinfo);
    return func0() * i;
}

int main() {
    return 0;
}
