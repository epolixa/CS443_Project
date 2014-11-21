#include <stdio.h>
#include <string.h>
#include "pri.h"
#include <iostream>
using namespace std;
/*
// from top to bottom
int get_required(course* c)
{
	if(c == NULL)
		return -1;
	else
	{
		int max = 0;
		for(int i = 0; i< c->n_width; i++)
		{
			int temp = get_required(c->next_list[i])+1;
			if (temp > max)
				max = temp;
		}
		return max;
	}
}
*/
void gr(string c, string pr){
		if(c != ""){
			if(pr != ""){
				hashmap[c].num_reqs++;
				hashmap[c].max_depth = hashmap[pr].max_depth + 1;
			}
			int i;
			for(i = 0; i < hashmap[c].width; ++i){
				gr(hashmap[c].prereq_list[i].coursename, c);
			}
		}
		return ;
}