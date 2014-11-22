#include <stdio.h>
#include <string>
// here I define what a node is and its data domain
typedef struct s_node
{
  string course_name;
  string prereq_list;   // prereq_list stores all the prerequisites of the current course
  int width;		    // width is the length of the prereq_list
  int max_depth;        // the maximum depth of the current course, an integer that is initialized as 0, will be updated
  int num_reqs;         // the sum of each chain's length of the current course, an integer that is initialized as 0, will be updated

  //char* next_list;
} course;

void gr(string,string);
void sort_by_max_depth(course**, int);
void sort_by_num_requs(course**, int);
