#include "stdio.h"
#include "stdlib.h"
#include "listapi.h"

node* Initialize(node* root, int d){
  node* retRoot;
  retRoot = malloc(sizeof(node));
  retRoot->data = d;
  retRoot->parent = NULL;
  retRoot->leftChild = NULL;
  retRoot->rightChild = NULL;
  retRoot->next = NULL;
  return retRoot;
}

void Divide(node* head){
  node* lChild = malloc(sizeof(node));
  node* rChild = malloc(sizeof(node));
/*DEFINITIONS FOR THE LEFT CHILD*/
  lChild->data = head->data+1;
  lChild->parent = head;
  lChild->leftChild = NULL;
  lChild->rightChild = NULL;
  lChild->next = NULL;
/*DEFINITIONS FOR THE RIGHT CHILD*/
  rChild->data = head->data+2;
  rChild->parent = head;
  rChild->leftChild = NULL;
  rChild->rightChild = NULL;
  rChild->next = NULL;
/*DEFINITIONS FOR THE PARENT(HEAD)*/
  head->leftChild = lChild;
  head->rightChild = rChild;
}

node* search(node* head, int d){
  for (; head!=NULL; head = head->next) {
    if(head->data == d){
      return head;
    }
  }
  return NULL;
}

node* add(node* head, int d){
  node* loc;
  loc = search(head,d);
  if(loc != NULL) return head;
  else{
    node* newHead;
    newHead = malloc(sizeof(node));
    newHead->data = d;
    newHead->next = head;
    return newHead;
  }
}

void RemoveNode(node* head){
  node* p = head;
  while (p != NULL) {
    head = head->next;
    free(p);
    p = head;
  }
}
