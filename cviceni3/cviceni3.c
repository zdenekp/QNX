#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX 10
#define SEC1 1
#define SEC2 3

// semafor pro stridani vlaken
sem_t sem_t_count;

void* print_name( void* arg ) {
	int i;
	int sec = (int) arg;
	for( i=0; i<MAX; i++ ) {
		sem_wait( &sem_t_count );
		printf( "This is thread %d\n", pthread_self() );
		sleep( sec );
		sem_post( &sem_t_count );
	}
	return(0);
}

int main(int argc, char *argv[]) {
	int first_t, second_t;
	int sec1 = SEC1;
	int sec2 = sec2;

	pthread_attr_t attr;

	pthread_attr_init( &attr );
	pthread_attr_setdetachstate(
			&attr, PTHREAD_CREATE_JOINABLE );

	sem_init( &sem_t_count, 1, 1 );

	pthread_create( &first_t, &attr, &print_name, (void *)sec1 );
	pthread_create( &second_t, &attr, &print_name, (void *)sec2 );

	pthread_join( first_t, NULL );
	pthread_join( second_t, NULL );

	return EXIT_SUCCESS;
}
