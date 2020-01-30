#include <stdio.h>

int global = 0;

typedef struct __attribute__((packed)) {
    char magic[4];
    char verifierDepsVersion[4];
    char dexSectionVersion[4];
    int numberOfDexFiles;
    int verifierDepsSize;
} vdexHeader_019;

int main() {
    char local = 'A';
    printf("local = %c, global = %d\n", local, global);
    printf("vdexHeader_019 sizeof %d\n", sizeof(vdexHeader_019));

    char resolved_path1[1024];
    char* real1 = realpath("~/work/java-learning/test.c", resolved_path1);
    printf("resolved_path1: %p %s %d\n", resolved_path1, resolved_path1, strlen(resolved_path1));
    printf("real1: %p %s %d\n", real1, real1, strlen(real1));

    char *resolved_path;
    char* real = realpath("~/work/java-learning/test.c", resolved_path);
    printf("resolved_path: %p %s %d\n", resolved_path, resolved_path, strlen(resolved_path));
    printf("real: %p %s %d\n", real, real, strlen(real));

    return 0;
}
