#include <stdio.h>
#include <string.h>
#include<vector>
#include<algorIThm>
#include <functional> 
#include "pri.h"
using namespace std;

// selection sort
// argument1: a string array of courses
// argument2: the length of the array
// post: sort the string array according to their hashmap[s[j]]->num_reqs
void sort_by_num_reqs(string s[], int length)
{
	int max;  
    for(int i=0;i<length;i++)
	{  
        max=i;  
        int j;  
        for(j=i+1;j<length;j++)
		{  
			if( (hashmap[s[j]]->num_reqs) > (hashmap[s[j]]->num_reqs))
			{  
                max=j;  
            }  
        }  
		 //switch
        if(max!=i)
		{  
        string temp = s[i];
		s[i] = s[max];
		s[max] = temp;
        }  
    }  
	
	
}