#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[2];
int counter = 0;

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    counter++;
    printf("Thread %d has started. Counter: %d\n", thread_id, counter);
    
    // Do some work
    for (int i = 0; i < 1000; i++) {
        // Simple work
    }
    
    printf("Thread %d has finished\n", thread_id);
    return NULL;
}

int main() {
    int thread_ids[2] = {1, 2};
    int error;
    
    // Create threads
    for (int i = 0; i < 2; i++) {
        error = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (error != 0) {
            printf("Thread creation failed: %d\n", error);
            return 1;
        }
    }
    
    // Wait for threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads completed. Final counter: %d\n", counter);
    return 0;
}

