#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#define NUMVALS 1024

typedef struct
{
  int start_index;
  int end_index;
} SortInfo;

int unsorted[NUMVALS];
int sorted[NUMVALS];

void fillArray(int size);
void* merger(void *args);
void* sorter(void *args);
void printArray(int *list, int size);

int genRand(int low, int high) //generate a random integer r such that low <= r <= high
{
  double r1, r2;
  int rtnval;
  r1 = drand48();
  r2 = (1 + high - low) * r1;
  rtnval = low + floor(r2);
  return(rtnval);
}

int main()
{
  SortInfo sortInfo1, sortInfo2;
  pthread_t tid1, tid2, tid3;
  pthread_attr_t attr; //thread attributes

  pthread_attr_init(&attr); //get default thread attributes
  fillArray(NUMVALS);
  printArray(unsorted, NUMVALS);
  sortInfo1.start_index = 0;
  sortInfo1.end_index = NUMVALS/2;
  sortInfo2.start_index = sortInfo1.end_index + 1;
  sortInfo2.end_index = NUMVALS-1;
  long secondStart = sortInfo2.start_index;
  secondStart = (long)(void*)secondStart;
  pthread_create(&tid1, &attr, sorter, &sortInfo1);
  pthread_create(&tid2, &attr, sorter, &sortInfo2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_create(&tid3, &attr, merger, &secondStart);
  pthread_join(tid3, NULL);
  printf("\n");
  printArray(sorted, NUMVALS);
  return 0;
}

void fillArray(int size) //fill the array
{
  int i;
  for (i = 0; i < size; i++)
    unsorted[i] = genRand(1,20);
}

void* merger(void *args) //merge the two sorted sub-arrays
{
  int *a = (int *)args;
  int begin = 0, mid = *a, end = NUMVALS-1;
  int i = begin, j = mid, tpos = begin;
  while (i < mid && j <= end)
  {
    if (unsorted[i] < unsorted[j])
      sorted[tpos++] = unsorted[i++];
    else
      sorted[tpos++] = unsorted[j++];
  }
  while (i < mid)
    sorted[tpos++] = unsorted[i++];
  while (j <= end)
    sorted[tpos++] = unsorted[j++];
  return NULL;
}

void* sorter(void *args) //sort the array
{
  SortInfo *params = (SortInfo*) args;
  int start = params->start_index, end = params->end_index;
  int i = start, j, itemToInsert;
  while (i <= end)
  {
    itemToInsert = unsorted[i];
    j = i-1;
    while (j >= start && itemToInsert < unsorted[j])
    {
      unsorted[j+1] = unsorted[j];
      j--;
    }
    unsorted[j+1] = itemToInsert;
    i++;
  }
  return NULL;
}

void printArray(int *list, int size) //print the array
{
  int i;
  for (i=0; i<size-1; i++)
    printf("%d, ", list[i]);
  printf("%d\n", list[i]);
}
