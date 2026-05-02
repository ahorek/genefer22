#include <stdio.h>
#include <pthread.h>

static __thread int tls_counter = 0;

static void* worker(void* arg)
{
    tls_counter++;

    printf(
        "thread %lu: tls_counter = %d\n",
        (unsigned long)pthread_self(),
        tls_counter
    );

    tls_counter++;

    printf(
        "thread %lu: tls_counter = %d\n",
        (unsigned long)pthread_self(),
        tls_counter
    );

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}