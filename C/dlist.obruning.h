typedef struct dlistStruct
{
  int data;
  struct dlistStruct *next;
  struct dlistStruct *prev;
} DListNode;

void printList(DListNode *theList);
/* print the list items from head to tail */

void printListReverse(DListNode *theList);
/* print the list items from tail to head */

int insertAtEnd(DListNode **theList, int data);
/* return zero if successful */

int insertSorted(DListNode **theList, int data);
/* return zero if successful */

int isInList(DListNode *theList, int data);
/* return non-zero value if the value is in the list; otherwise return zero */

int deleteFromList(DListNode **theList, int data);
/* if the value isn't in the list, then do nothing and return non-zero value; otherwise delete all listnodes matching the data from the list and return zero */

void sortedInsert(DListNode **theList, DListNode *new_node);
/* this method is called by insertionSort */

void insertionSort(DListNode **theList);
/* sort the linked list */

int checkDList(int *A, DListNode *theList, int numVals, char *testName);
/* check the linked list */

int findLoops(DListNode *theList);
/* find loops in the linked list */

int checkReverse(DListNode *theList);
/* check the linked list (reverse) */

void deleteNode(DListNode **theList, DListNode *del);
/* delete a node */
