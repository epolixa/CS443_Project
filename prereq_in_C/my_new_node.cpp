#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"

t_node* new_node(char* type, char* name, t_node* left, t_node* right)
{
  t_node * n =(t_node*) malloc( sizeof *n);
  n->type = type;
  n->name = name;
  n->right = right;
  n->left = left;
  return n;
}
