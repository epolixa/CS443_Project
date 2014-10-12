#include <stdio.h>
#include <string>
#include "my.h"
#include "node.h"

bool taken(char* course, char**list)
{
	for(int i =0; list[i]!= NULL; i++)
	{
		if (my_strcmp(course,list[i]) == 0)
			return true;
	}
	return false;
}