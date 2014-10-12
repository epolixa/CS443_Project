#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"
// this function checks whether the node is a leaf node
bool is_unit(t_node* node)
{
	if(my_strcmp(node->type, "unit") == 0)
		return true;
	else 
		return false;
}