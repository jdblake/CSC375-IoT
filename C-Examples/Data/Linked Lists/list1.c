#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 80

// Linked list node
typedef struct node {
  int val;
  char *name;
  struct node *next;
} node;

// Head of list
node *head = NULL;

// Make a list recursively
void makeList(int n) {
  if (n > 0) {
    node *cur = malloc(sizeof(node));
    cur->val = rand() % 10000;
    cur->name = calloc(STRLEN,sizeof(char));
    sprintf(cur->name,"%05X",cur->val);
    cur->next = head;
    head = cur;
    makeList(n-1);
  }
}

// Print a list recursively
void printList(node *n) {
  if (n != NULL) {
    printf("Name: %s\tValue: %d\n",n->name,n->val);
    printList(n->next);
  }
}

// Free a list recursively
void freeList(node *n) {
  if (n != NULL) {
    freeList(n->next);
    free(n->next);
  }
}

// Main function
int main() {
  makeList(10);
  printList(head);
  freeList(head);
  free(head);
  return 0;
}
