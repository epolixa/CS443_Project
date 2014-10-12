#include "my.h"
#include "node.h"

//pre: takes a string and a char
//post: find the position of that char and return the rest of the string

char * my_strfind( char * str, char c)
{
  if( str== NULL)
    return NULL;
  while (str[0]!= '\0')
    {
      if(str[0] == c)
	return str;
      str++;
    }
  return NULL;
}
