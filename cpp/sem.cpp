#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
sem_t sem;


/*function:获取当前时间，精确到毫秒
 * */
int64_t getTimeMsec()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


void* func_sem_wait(void* arg)
{
  printf("set wait\n");
  sem_wait(&sem);
  printf("sem wait success\n");
  int *running = (int*)arg;
  printf("func_sem_wait running\n");
  printf("%d\n", *running);
}

void* func_sem_timedwait(void* arg)
{
  timespec timewait;
  timewait.tv_sec = getTimeMsec() / 1000 + 2;
  timewait.tv_nsec = 0;
  printf("sem_timedwait\n");
  int ret = sem_timedwait(&sem, &timewait);
  printf("sem_timedwait,ret=%d\n", ret);
  printf("func_sem_timedwait running\n");
}

void* func_sem_post(void* arg)
{
  printf("func_sem_post running\n");
  printf("sem post\n");
  int *a = (int*)arg;
  *a = 6;
  sem_post(&sem);
  sem_post(&sem);
}

int main()
{
  sem_init(&sem, 0, 0);
  pthread_t thread[3];
  int a = 5;

  pthread_create(&(thread[0]), NULL, func_sem_wait, &a);
  printf("thread func_sem_wait\n");

  pthread_create(&(thread[2]), NULL, func_sem_timedwait, &a);
  printf("thread func_sem_timedwait\n");

  sleep(4);

  pthread_create(&(thread[1]), NULL, func_sem_post, &a);
  printf("thread func_sem_post\n");

  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);
  pthread_join(thread[2], NULL);
  sem_destroy(&sem);
}

