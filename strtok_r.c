#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mymutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mymutex2 = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_mutex_t mymutex3 = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

void *thread_function(void *arg) {
    int i = *(int*)(arg);
    printf("thread_function %d.\n", i);
    if (i == 1) {
        pthread_mutex_lock(&mymutex);
        printf("mymutex lock success 1.\n");
        pthread_mutex_unlock(&mymutex);
        pthread_mutex_destroy(&mymutex);
        int r = pthread_mutex_lock(&mymutex);
        printf("mymutex lock success 2 %d.\n", r);
    }
    if (i == 2) {
        pthread_mutex_lock(&mymutex2);
        printf("mymutex2 lock success 1.\n");
        pthread_mutex_lock(&mymutex2);
        printf("mymutex2 lock success 2.\n");
        pthread_mutex_unlock(&mymutex2);
    }
    if (i == 3) {
        pthread_mutex_lock(&mymutex3);
        printf("mymutex3 lock success 1.\n");
        pthread_mutex_lock(&mymutex3);
        printf("mymutex3 lock success 2.\n");
        pthread_mutex_unlock(&mymutex3);
    }
    return NULL;
}

int main(void) {
    pthread_t tids1;
    pthread_t tids2;
    pthread_t tids3;
    int i = 1, j = 2, k = 3;

    if (pthread_create(&tids1, NULL, thread_function, &i) ) {
        printf("error creating thread.");
        abort();
    }
    if (pthread_create(&tids2, NULL, thread_function, &j) ) {
        printf("error creating thread.");
        abort();
    }
    if (pthread_create(&tids3, NULL, thread_function, &k) ) {
        printf("error creating thread.");
        abort();
    }

    if (pthread_join(tids1, NULL)) {
        printf("error joining thread %d\n.", tids1);
        abort();
    }
    if (pthread_join(tids2, NULL)) {
        printf("error joining thread %d\n.", tids2);
        abort();
    }
    if (pthread_join(tids3, NULL)) {
        printf("error joining thread %d\n.", tids3);
        abort();
    }
    // printf("\nmyglobal equals %d\n",myglobal);
    return 0;
}

int func() {
    char v11[100] = "/data/data/com.netmarble.sknightsgb/files/Resources/GameSettings.txt";
    char *v37[1024];
    char *v38[1024];
    char* v13;
    char *v36 = NULL;
    int v12 = 0;

    printf("----\n");

    v37[0] = strtok_r(v11, "/", &v36);
    printf("v37[0] :%s\n", v37[0]);
    do {
        v13 = strtok_r(0, "/", &v36);
        printf("v13 :%s\n", v13);
        v37[v12++ + 1] = v13;
    } while (v13);

    printf("v11 :%s\n", v11);

    return 0;
}

// #include <stdio.h>
// #include <string.h>
// 
// int main(void)
// {
//     int j,in = 0;
//     char buffer[100] = "Fred male 25,John male 62,Anna female 16";
//     char *p[20];
//     char *buf = buffer;
//     char *outer_ptr = NULL;
//     char *inner_ptr = NULL;
//     while ((p[in] = strtok_r(buf, ",", &outer_ptr)) != NULL)
//     {
//         buf = p[in];
//         while ((p[in] = strtok_r(buf, " ", &inner_ptr)) != NULL)
//         {
//             in++;
//             buf = NULL;
//         }
//         buf = NULL;
//     }
//     printf("Here we have %d strings\n", in);
//     for (j = 0; j < in; j++)
//     {
//         printf(">%s<\n", p[j]);
//     }
//     return 0;
// }

