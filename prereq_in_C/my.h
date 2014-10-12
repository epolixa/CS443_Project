#include <stdio.h>
#include <string>
//#include "node.h"
#ifndef NULL
   #define NULL ( (void *))
#endif

/*void my_char (char);
void my_str (char *); // No vriables declaration
void my_int (int) ;  // No recursion, no pointers
void my_num_base (int, char *);
void my_alpha ();
void my_digits();
int my_strlen(char *);
int  my_revstr (char *);
int my_strpos(char *, char );
int my_strrpos(char *, char);
void * xmalloc(unsigned int);
char * my_vect2str(char**);
char **my_str2vect(char*);
/*preject description:*/
/*my second assignment mainly deals with strings
almost every method has an substitute method that controls the length of the 
operating string, like my_strcmp, my_strcpy and my_strconcat.
Also, we have methods similar to the previous methods my_strpos and my_strrpos
this time it can return a string that points to the rest of the strings

 cs392 makes me suffer both mentally and phyiscally.
I in panic and couldn't sleep well at night!
I stay in front of computer for long time and gain weight!
*/
char* my_strdup(char*); //ok
int my_strcmp(char*, char*); //ok
char* my_strcpy(char*,   char*); //ok
char* my_strconcat(char*, char*); //ok
char* my_strfind(char*, char); //ok
int my_strlen(char*); //ok
void my_char(char);  //ok
void my_str(char*);  //ok

//for others to finish
char * get_left(char*);
char * get_right(char*);
bool is_and_expression(char*);
bool is_or_expression(char*);
bool is_unit_expression(char*);