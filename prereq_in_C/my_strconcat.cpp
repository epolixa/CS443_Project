#include "my.h"

//pre: takes two string
//psot: a new pointer, pointing to a new combination string

char * my_strconcat( char * str1, char * str2)
{
  if(str1 ==NULL && str2 == NULL)
    return NULL;
  if(str1 == NULL && str2 !=NULL)
    return my_strdup(str2);
  if(str1 != NULL && str2 == NULL)
    return my_strdup(str1);

  int length = my_strlen(str1) + my_strlen(str2) + 1;
  int i=0;
  int j=0;
  char * one = (char*) malloc (length);
  while (i< my_strlen(str1))
    {
      one[i]= str1[i];
      i++;
    }
  while (i<length-1)
    {
      one[i]= str2[j];
      i++;
      j++;
    }
  one[i]= '\0';
  return one;
}
