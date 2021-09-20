#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#define NUM_PHILOSOPHERS 5
#define RUNTIME 10
#define EAT_TIME 2
#define THINK_TIME 1
#define LEFT (pnum + 4) % NUM_PHILOSOPHERS
#define RIGHT (pnum + 1) % NUM_PHILOSOPHERS
pthread_mutex_t forks[NUM_PHILOSOPHERS];

int state[NUM_PHILOSOPHERS];
int p[NUM_PHILOSOPHERS] = {0, 1, 2, 3, 4};
int cnt = 0;
sem_t mutex;
sem_t S[NUM_PHILOSOPHERS];

void *philosopher(void *param);
void *philosopher_good(void *param);
void test(int pnum);
void grabFork(int pnum);
void placeFork(int pnum);

int main (int argc, char *argv[])
{
  printf("----- START OF PART 1 -----\n");
  int rtnval;
  int id[NUM_PHILOSOPHERS];
  pthread_t tid[NUM_PHILOSOPHERS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
  {
    rtnval = pthread_mutex_init(&(forks[i]), NULL);
    if (rtnval != 0)
    {
      printf("error initializing mutex\n");
      return(8);
    }
  }
  for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
  {
    id[i] = i;
    pthread_create(&(tid[i]), &attr, philosopher, &(id[i]));
  }
  sleep(RUNTIME);
  for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
  {
    pthread_kill(tid[i], 0);
  }
  printf("----- END OF PART 1 -----\n");

  printf("----- START OF PART 2 -----\n");
  int i;
  pthread_t thread_id[NUM_PHILOSOPHERS];
  sem_init(&mutex, 0, 1);
  for (i = 0; i < NUM_PHILOSOPHERS; i++)
  {
    sem_init(&S[i], 0, 0);
  }
  for (i = 0; i < NUM_PHILOSOPHERS; i++)
  {
    pthread_create(&thread_id[i], NULL, philosopher_good, &p[i]);
    if (cnt == 5)
    {
      printf("P %d, thinking for 1 secs\n", i + 1);
      sleep(THINK_TIME);
    }
  }
  sleep(50);
  for (int i = 0; i < 5; ++i)
  {
    pthread_kill(thread_id[i], 0);
  }
  printf("----- END OF PART 2 -----\n");
  return 0;
}

void *philosopher(void *param)
{
  int *myID;
  myID = (int *) param;
  int leftIdx = *myID;
  int rightIdx = (*myID + 1) % NUM_PHILOSOPHERS;
  printf("P %d start\n", *myID);
  while (1)
  {
    pthread_mutex_lock(&(forks[leftIdx]));
    usleep(1000);
    pthread_mutex_lock(&(forks[rightIdx]));
    printf("P %d, eating for %d secs\n", *myID, EAT_TIME);
    sleep(EAT_TIME);
    pthread_mutex_unlock(&(forks[leftIdx]));
    pthread_mutex_unlock(&(forks[rightIdx]));
    printf("P %d, thinking for %d secs\n", *myID, THINK_TIME);
    sleep(THINK_TIME);
  }
}

void *philosopher_good(void *param)
{
  int *myID;
  myID = (int *) param;
  int leftIdx = *myID;
  int rightIdx = (*myID + 1) % 5;
  printf("P %d start\n", *myID);
  cnt++;
  while (1)
  {
    int* i = param;
    sleep(1);
    grabFork(*i);
    sleep(0);
    placeFork(*i);
  }
}

void test(int pnum)
{
  if (state[pnum] == 1 && state[LEFT] != 0 && state[RIGHT] != 0)
  {
    state[pnum] = 0;
    sleep(2);
    if (cnt == 5)
    {
      printf("P %d, eating for 2 secs\n", pnum + 1);
      sleep(EAT_TIME);
    }
    sem_post(&S[pnum]);
  }
}

void grabFork(int pnum)
{
  sem_wait(&mutex);
  state[pnum] = 1;
  if (cnt == 5)
  {
    printf("P %d, eating for 2 secs\n", pnum + 1);
    sleep(EAT_TIME);
  }
  test(pnum);
  sem_post(&mutex);
  sem_wait(&S[pnum]);
  sleep(1);
}

void placeFork(int pnum)
{
  sem_wait(&mutex);
  state[pnum] = 2;
  if (cnt == 5)
  {
    printf("P %d, thinking for 1 secs\n", pnum + 1);
    sleep(THINK_TIME);
  }
  test(LEFT);
  test(RIGHT);
  sem_post(&mutex);
}
