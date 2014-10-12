#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"

//this function checks whether a node is a or_node

bool is_or_node(t_node* node)
{
	if(my_strcmp(node->type,"or") == 0)
		return true;
	else 
		return false;
}
