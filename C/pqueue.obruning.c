#include "pqueue.obruning.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(PQueue *pqueue, int priority, void *data)
{
  insertionSort(&(pqueue->head));
  PQueueNode *curNode, *newNode;
  newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
  newNode->priority = priority;
  newNode->data = data;
  newNode->next = NULL;
  if (pqueue->head == NULL)
  {
    pqueue->head = newNode;
    insertionSort(&(pqueue->head));
    return 0;
  }
  else
  {
    curNode = pqueue->head;
    while (curNode->next != NULL)
    {
      curNode = curNode->next;
    }
    curNode->next = newNode;
    insertionSort(&(pqueue->head));
    return 0;
  }
}

void *dequeue(PQueue *pqueue)
{
  if (pqueue->head == NULL)
    return NULL;
  else
  {
    PQueueNode* temp = pqueue->head;
    (pqueue->head) = (pqueue->head)->next;
    free(temp);
    return temp->data;
  }
}

int printQueue(PQueue* pqueue)
{
  insertionSort(&(pqueue->head));
  PQueueNode * current = pqueue->head;
  while (current != NULL)
  {
    printf("|%d %s", current->priority, (char *)(current->data));
    current = current->next;
  }
  if (pqueue->head != NULL)
  {
    printf("|");
  }
  printf("\n");
  return 0;
}

void *peek(PQueue *pqueue)
{
  if (pqueue->head == NULL)
    return NULL;
  else
    return pqueue->head->data;
}

int getMinPriority(PQueue *pqueue)
{
  if (pqueue->head != NULL)
    return pqueue->head->priority;
  else
    return -1;
}

void sortedInsert(PQueueNode **theList, PQueueNode *new_node)
{
  PQueueNode* current;
  if (*theList == NULL || (*theList)->priority > new_node->priority)
  {
    new_node->next = *theList;
    *theList = new_node;
  }
  else
  {
    current = *theList;
    while (current->next != NULL && current->next->priority <= new_node->priority)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void insertionSort(PQueueNode **theList)
{
  PQueueNode *sorted = NULL;
  PQueueNode *current = *theList;
  while (current != NULL)
  {
    PQueueNode *next = current->next;
    sortedInsert(&sorted, current);
    current = next;
  }
  *theList = sorted;
}
