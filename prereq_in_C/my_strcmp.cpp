#include "my.h"

// pre: takes two strings, str1 and str2
// post: return an integer that is the comparesion of str1 and str2

int my_strcmp(char * str1, char * str2)
{
  if(str1 == NULL && str2 == NULL)
    return 0;
  if(str1 == NULL && str2 !=NULL)
    return -1;
  if(str2 == NULL && str1 !=NULL)
    return 1;

  while ((*str1) == (*str2))
    {
      if( *str1 == 0)
	return 0;
      str1++;
      str2++;
    }
  return (*str1)- (*str2);
}