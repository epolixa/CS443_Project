#include <stdio.h>
#include <string>
#include "my.h"



// here I define what a node is and its data domain
typedef struct s_node
{
  char * type;
  char * name;

  struct s_node *left;
  struct s_node *right;
} t_node;

bool is_and_node(t_node*);//ok
bool is_unit(t_node*);//ok
bool is_or_node(t_node*);//ok
bool taken(char*,char**);
t_node* new_node(char* , char* , t_node* , t_node* );  //ok
t_node* parse(char*);  //ok
bool check(t_node*, char**); //ok





