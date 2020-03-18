#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <sys/types.h>
#include <unistd.h>

static int childProcess(void *arg) {
    char *argVec[10];                               //参数数组
    char *envVec[] = {"环境参数1","环境参数2",NULL};  //环境变量数组
    printf("childProcess %d exec\n", getpid());
    execve("./exec", argVec,envVec);
}


static int childProcess1(void *arg) {
    char* env = getenv("MY_ENV");
    printf("childProcess %d env:%s\n", getpid(), env);
    // setenv("MY_ENV", "helloword", 1);
    exit(0);
}

int main(void) {

    volatile pid_t resultPid = vfork();
    // volatile pid_t resultPid = fork();
    if (resultPid == 0) {
        childProcess(NULL);
    }

    sleep(1);

    volatile pid_t resultPid1 = vfork();
    // volatile pid_t resultPid1 = fork();
    if (resultPid1 == 0) {
        childProcess1(NULL);
    }

    char* env = getenv("MY_ENV");
    printf("main process %d env:%s\n", getpid(), env);
    assert(resultPid != 0);  /* childProcess never returns */
    assert(resultPid1 != 0);  /* childProcess never returns */
    return 0;
}
