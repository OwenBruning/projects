#include "dlist.obruning.h"
#include <stdio.h>
#include <stdlib.h>

/*int main (int argc, char *argv[])
{
  return 0;
}*/

void printList(DListNode *theList)
{
  DListNode * current = theList;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void printListReverse(DListNode *theList)
{
  if (theList == NULL)
    return;
  printListReverse(theList->next);
  printf("%d ", theList->data);
}

int insertAtEnd(DListNode **theList, int data)
{
  DListNode *currentNode, *newNode;
  newNode = (DListNode *) malloc(sizeof(DListNode));
  newNode -> data = data;
  newNode -> next = NULL;
  if (*theList == NULL)
  {
    newNode -> prev = NULL;
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
    newNode -> prev = currentNode;
    return 0;
  }
}

int insertSorted(DListNode **theList, int data)
{
  insertionSort(&(*theList));
  DListNode *curNode, *newNode;
  newNode = (DListNode *) malloc(sizeof(DListNode));
  newNode->data = data;
  newNode->next = NULL;
  if (*theList == NULL)
  {
    newNode -> prev = NULL;
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
    newNode -> prev = curNode;
    return 0;
  }
}

int isInList(DListNode *theList, int data)
{
  DListNode *current = theList;
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

int deleteFromList(DListNode **theList, int data)
{
  if ((*theList) == NULL)
    return 1;
  DListNode* current = *theList;
  DListNode* next;
  while (current != NULL)
  {
    if (current->data == data)
    {
      next = current->next;
      deleteNode(theList, current);
      current = next;
    }
    else
      current = current->next;
  }
}

void sortedInsert(DListNode **theList, DListNode *new_node)
{
  DListNode* current;
  if (*theList == NULL)
    *theList = new_node;
  else if ((*theList)->data >= new_node->data)
  {
    new_node->next = *theList;
    new_node->next->prev = new_node;
    *theList = new_node;
  }
  else
  {
    current = *theList;
    while (current->next != NULL && current->next->data < new_node->data)
      current = current->next;
    new_node->next = current->next;
    if (current->next != NULL)
      new_node->next->prev = new_node;
    current->next = new_node;
    new_node->prev = current;
  }
}

void insertionSort(DListNode **theList)
{
  DListNode *sorted = NULL;
  DListNode *current = *theList;
  while (current != NULL)
  {
    DListNode *next = current->next;
    current->prev = current->next = NULL;
    sortedInsert(&sorted, current);
    current = next;
  }
  *theList = sorted;
}

void deleteNode(DListNode **theList, DListNode *del)
{
  if (*theList == NULL || del == NULL)
    return;
  if (*theList == del)
    *theList = del->next;
  if (del->next != NULL)
    del->next->prev = del->prev;
  if (del->prev != NULL)
    del->prev->next = del->next;
  free(del);
}
