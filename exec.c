#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
    char* env = getenv("MY_ENV");
    printf("childProcess %d env :%s\n", getpid(), env);
    setenv("MY_ENV", "helloword", 1);
    // char* env1 = getenv("MY_ENV");
    // printf("childProcess %d env1:%s\n", getpid(), env1);
    return 0;
}

// int main(void) {
// 
//     // volatile pid_t resultPid = vfork();
//     volatile pid_t resultPid = fork();
//     if (resultPid == 0) {
//         childProcess(NULL);
//     }
// 
//     // volatile pid_t resultPid1 = vfork();
//     volatile pid_t resultPid1 = fork();
//     if (resultPid1 == 0) {
//         childProcess(NULL);
//     }
// 
//     char* env = getenv("MY_ENV");
//     printf("main process %d env:%s\n", getpid(), env);
//     assert(resultPid != 0);  /* childProcess never returns */
//     assert(resultPid1 != 0);  /* childProcess never returns */
//     return 0;
// }
