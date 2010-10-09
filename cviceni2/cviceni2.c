#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10
#define SEC 1

void* print_name( void* arg ) {
	int i;
	for( i=0; i<MAX; i++ ) {
		printf( "This is thread %d\n", pthread_self() );
		sleep(SEC);
	}
	return(0);
}

int main(int argc, char *argv[]) {
	int first_t, second_t;

	pthread_attr_t attr;

	pthread_attr_init( &attr );
	pthread_attr_setdetachstate(
			&attr, PTHREAD_CREATE_JOINABLE );

	pthread_create( &first_t, &attr, &print_name, NULL );
	pthread_create( &second_t, &attr, &print_name, NULL );

	pthread_join( first_t, NULL );
	pthread_join( second_t, NULL );
	return EXIT_SUCCESS;
}
