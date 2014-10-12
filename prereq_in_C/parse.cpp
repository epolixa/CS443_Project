#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"

t_node* parse(char * exp)
{		
	if (is_and_expression(exp) == true)
		{	
			t_node * temp = new_node("and",NULL,NULL,NULL);
			temp->left  = parse( get_left(exp) );
			temp->right = parse( get_right(exp));
			return temp;
		}
	if (is_or_expression(exp) == true)
		{
			t_node * temp = new_node("or",NULL,NULL,NULL);
			temp->left  = parse( get_left(exp) );
			temp->right = parse( get_right(exp));
			return temp;
        }
	if(is_unit_expression(exp) == true)
		{
			t_node * temp = new_node("unit",NULL,NULL,NULL);
			temp->name= exp;
			return temp;
		}
}
