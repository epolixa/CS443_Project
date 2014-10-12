#include "my.h"
#include <stdio.h>
#include <string>
/*
pre: takes an pointer to a char
post: returns the content of that char
*/

void my_str(char* str)
{
  if(str == NULL)
    return;
  else{
    while( str[0]!='\0')
      my_char(str[0]), str++;
  }
}
