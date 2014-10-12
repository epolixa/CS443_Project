#include <stdio.h>
#include <string.h>
#include "my.h"
#include "node.h"

bool check(t_node* tree, char**list)
{
		if ( is_and_node(tree)== true )
			{
				bool result;
				result = (check(tree->left,list)) && (check(tree->right,list));
				return result;
			}
		if ( is_or_node(tree)== true )
			{
				bool result;
				result = (check(tree->left,list)) || (check(tree->right,list));
				return result;
			}
		if ( is_unit(tree) == true)
			{
				return ( taken(tree->name,list) );
			}
		return false;
}