#include "slist.obruning.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  return 0;
}

void printList(SListNode *theList)
{
  SListNode * current = theList;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int insertAtEnd(SListNode **theList, int data)
{
  SListNode *currentNode, *newNode;
  newNode = (SListNode *) malloc(sizeof(SListNode));
  newNode -> data = data;
  newNode -> next = NULL;
  if (*theList == NULL)
  {
    *theList = newNode;
    return 0;
  }
  else
  {
    currentNode = *theList;
    while (currentNode -> next != NULL)
    {
      currentNode = currentNode -> next;
    }
    currentNode -> next = newNode;
    return 0;
  }
}

int insertSorted(SListNode **theList, int data)
{
  insertionSort(&(*theList));
  SListNode *curNode, *newNode;
  newNode = (SListNode *) malloc(sizeof(SListNode));
  newNode->data = data;
  newNode->next = NULL;
  if (*theList == NULL)
  {
    *theList = newNode;
    return 0;
  }
  else
  {
    curNode = *theList;
    while (curNode->next != NULL)
    {
      curNode = curNode->next;
    }
    curNode->next = newNode;
    return 0;
  }
}

int isInList(SListNode *theList, int data)
{
  SListNode *current = theList;
  while (current != NULL)
  {
    if (current -> data == data)
    {
      return 1;
    }
    current = current -> next;
  }
  return 0;
}

int deleteFromList(SListNode **theList, int data)
{
  SListNode* temp = *theList, *prev;
  while (temp != NULL && temp->data == data)
  {
    *theList = temp->next;
    free(temp);
    temp = *theList;
  }
  while (temp != NULL)
  {
    while (temp != NULL && temp->data != data)
    {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
    {
      return 0;
    }
    prev->next = temp->next;
    free(temp);
    temp = prev->next;
  }
}

void sortedInsert(SListNode **theList, SListNode *new_node)
{
  SListNode* current;
  if (*theList == NULL || (*theList)->data >= new_node->data)
  {
    new_node->next = *theList;
    *theList = new_node;
  }
  else
  {
    current = *theList;
    while (current->next != NULL && current->next->data < new_node->data)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void insertionSort(SListNode **theList)
{
  SListNode *sorted = NULL;
  SListNode *current = *theList;
  while (current != NULL)
  {
    SListNode *next = current->next;
    sortedInsert(&sorted, current);
    current = next;
  }
  *theList = sorted;
}
