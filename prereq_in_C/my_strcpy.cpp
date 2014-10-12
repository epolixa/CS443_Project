#include "my.h"
#include "node.h"

//pre:  takes two strings 
//post: copy the second string to the first string and returns it

char * my_strcpy( char * str1, char * str2)
{
  if (str1 == NULL)
    return NULL;
  if (str2== NULL)
    return str1;

  char * temp= str1;
  while ( (*str1 = *str2)!= '\0')
    {
      str1++;
      str2++;
    }
     return temp;

}
