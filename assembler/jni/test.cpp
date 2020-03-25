#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

#define LOG_TAG "TEST"
#define debug(fmt, args...)  do {__android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args);} while(0)

int function(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    printf("a %d\n", a);
    debug("%d\n", b);
    return a+b+c+d+e+f+g+h+i+j;
    // return i+j;
}

int main(int argc, char *argv[]) {
    // int a = 1;
    // int j = 10;
    int r = function(1,2,3,4,5,6,7,8,9,10);
    printf("%d\n", r);
    return 0;
}
