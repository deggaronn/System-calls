#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *t1();
void *t2();
pthread_mutex_t l1;
pthread_mutex_t l2;
int main()
{
	pthread_t p1,p2;
	pthread_create(&p1,NULL,&t1,NULL);
	pthread_create(&p2,NULL,&t2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}
void *t1()
{
	pthread_mutex_lock(&l1);
	printf("t1 is working");
	sleep(1);
	pthread_mutex_lock(&l2);
}
void *t2()
{
	pthread_mutex_lock(&l2);
	printf("t2 is working");
	sleep(1);
	pthread_mutex_lock(&l1);
}

