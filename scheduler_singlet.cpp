#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

typedef struct s_node
{
  string name;              // name of the course
  vector<string> prereqs;   // stores a vector of strings which are keys to the course's prereqs in a hashmap
  int max_chain;            // the longest chain which this course starts, initialized to 0
  int total_of_chains;      // value is equal to how many courses require this course as a prereq in some way, initialized to 0
  bool is_taken;            // indicates whether or not this class has been taken, initialized to false
} t_course;

void print_and_exit(string str)
{
    cout << str << endl;
    exit(0);
}

int main(int argc, char** argv)
{
    ifstream case_file;
    map<string, t_course*> courses;
    string line;
    string token;
    char *buffer;
    size_t pos;

    if(argc != 2)
        print_and_exit("Not enough arguments given, run as ./scheduler test_case_textfile");

    case_file.open(argv[1]);
    if(!case_file.is_open())
        print_and_exit("Invalid file");

    while(!case_file.eof())
    {
        t_course* course = new t_course();
        getline(case_file, line);
        if(line.size() > 0)
        {
            pos = line.find(',');
            course->name = line.substr(0, pos);
            line.erase(0, pos+1);
            while(pos != string::npos)
            {
                pos = line.find(',');
                course->prereqs.push_back(line.substr(0, pos));
                line.erase(0, pos+1);
            }
            course->max_chain = 0;
            course->total_of_chains = 0;
            course->is_taken = false;
            courses[course->name] = course;
        }
    }
    for(map<string, t_course*>::iterator it = courses.begin(); it != courses.end(); ++it)
    {
        cout << it->first;
        for(int i=0; i<it->second->prereqs.size(); i++)
        {
            cout << "   " << it->second->prereqs[i];
        }
        cout << endl;
    }
}
