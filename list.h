typedef struct node node;

struct node{
  int data;
  struct node* next;
  struct node* parent;
  struct node *leftChild;
  struct node *rightChild;
};
