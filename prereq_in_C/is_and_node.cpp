#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"

// this function chekcs whether a node is a and_node
bool is_and_node(t_node* node)
{
	if(my_strcmp(node->type,"and") == 0)
		return true;
	else
		return false;
}