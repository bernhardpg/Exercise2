#include <pthread.h>
#include <stdio.h>

/* ## NOTES ON MULTITHREADING
 *
 * pthread_t --> thread ID type
 * pthread_equal() --> Compare two thread IDs
 * pthread_self() --> Get thread ID of thread
 * pthread_create() --> Create thread
 *
 * pthread_join(pthread_t thread, void **rval_ptr) --> Make sure the parent thread does not execute
 *    before 'thread' is finished
 * pthread_exit(void *rval_ptr) --> Called within a thread to make kill the thread. rval_ptr is
 *    then accessable for the parent pointer through the rval_ptr in pthread_join
 * pthread_cancel() --> Cancel a thread 
 * 
 * ### MUTEX LOCKING
 * pthread_mutex_t --> Mutex type
 * pthread_mutex_init(pthread_mutex_t *restricted mutex, sometype attr) --> Init a mutex
 * pthread_mutex_lock(pthread_mutex_t *mutex) --> Locking a mutex
 * pthread_mutex_unlock(pthread_mutex_t *mutex) --> Unlock
 * pthread_mutex_destroy(pthread_mutex_t *mutex) --> Destroy a mutex
 *
 */

int i = 0;
pthread_mutex_t lock;

// Note the return type: void*
void* incrementingThreadFunction()
{
    pthread_mutex_lock(&lock);

    for (int j = 0; j < 1000000; ++j)
	++i;

    pthread_mutex_unlock(&lock);

    return NULL;
}

void* decrementingThreadFunction()
{
    pthread_mutex_lock(&lock);

    for (int j = 0; j < 1000000 - 1; ++j)
	--i;

    pthread_mutex_unlock(&lock);

    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    if (pthread_mutex_init(&lock, NULL))
    {
	printf("Error: Couldn't init mutex");
	return 1;
    }

    if (pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL))
    {
	printf("Couldn't create thread: incrementingThread\n");
	return 1;
    }
    if (pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL))
    {
	printf("Couldn't create thread: decrementingThread\n");
	return 1;
    }
    
    if (pthread_join(incrementingThread, NULL))
    {
	printf("Couldn't join thread: decrementingThread\n");
	return 1;
    }
    if (pthread_join(decrementingThread, NULL))
    {
	printf("Couldn't join thread: decrementingThread\n");
	return 1;
    }

    pthread_mutex_destroy(&lock);

    printf("The magic number is: %d\n", i);
    return 0;
}
