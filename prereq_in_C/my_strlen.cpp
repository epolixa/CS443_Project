#include "my.h"
#include "node.h"
/*
pre: takes an string 
post: returns the length of that string
*/

int my_strlen(char* str)
{
  if(str == NULL)
    return -1;
  else{
  int length = 0;
  int i = 0;
  while( str[i]!= '\0')
    {
      length++;
      i++;
    }
  return length;
  }

}
