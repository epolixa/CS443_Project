#include <stdlib.h>
#include "my.h"
#include "node.h"

/*pre:takes a string
post:return a new pointer that points to the a copy of the given string
*/

char* my_strdup(char* str1)
{
  int length =0;
  int i= 0;

  if(str1== NULL)
    {
      // my_str("Can't Duplicate NULL! \n");
      return NULL;
    }
  length = my_strlen(str1);
  char * str2= (char*) malloc( (length+1)* sizeof(char)); 
  while (i<length)
    {
      str2[i]= str1[i];
      i++;
    }

  str2[i]='\0';
  return str2;

}
