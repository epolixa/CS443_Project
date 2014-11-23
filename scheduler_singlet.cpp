#include <string>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

// data that each course has and why
typedef struct s_node
{
  string name;              // name of the course
  vector<string> prereqs;   // stores a vector of strings which are keys to the course's prereqs in a hashmap
  int max_chain;            // the longest chain which this course starts, initialized to 0
  int total_of_chains;      // value is equal to how many courses require this course as a prereq in some way, initialized to 0
  bool is_taken;            // indicates whether or not this class has been taken, initialized to false
} t_course;

// map of courses
map<string, t_course*> courses;

void print_and_exit(string str)
{
    cout << str << endl;
    exit(0);
}

// find the chain values of courses by using their prereqs and building up
void chain_checker(t_course *course)
{
    unsigned int i=0;
    t_course *temp;
    for(; i<course->prereqs.size(); i++)
    {
        temp = courses[course->prereqs[i]];
        temp->total_of_chains++;
        if(temp->max_chain < course->max_chain+1)
            temp->max_chain = course->max_chain+1;
        chain_checker(temp);
    }
}

bool can_take(t_course *course)
{
    unsigned int i=0;
    for(; i<course->prereqs.size(); i++)
        if(!courses[course->prereqs[i]]->is_taken)
            return false;
    return true;
}

int main(int argc, char** argv)
{
    int i,j;
    ifstream case_file;
    string line;
    string token;
    size_t pos;
    vector<pair<string, double> > maxheap;
    vector< vector< string > > schedule;
    bool found_course;
    clock_t start, finish;

    // beginning of the timer to check how long it takes to create a schedule
    start = clock();

    // checks to see if enough values where inputted at run time
    if(argc != 2)
        print_and_exit("Not enough arguments given, run as ./scheduler test_case_textfile");

    // tries to open and then checks if the file is valid, else it produces a helpful error and exits
    case_file.open(argv[1]);
    if(!case_file.is_open())
        print_and_exit("Invalid file");

    // takes the input file and creates a map with course name as the key and the course as the value
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

    // finds the values of all courses max_chain and total_of_chains values
    for(map<string, t_course*>::iterator it = courses.begin(); it != courses.end(); ++it)
    {
        chain_checker(courses[it->first]);
    }

    // pushes all map values with name and ranking into maxheap vector
    for(map<string, t_course*>::iterator it = courses.begin(); it != courses.end(); ++it)
    {
        maxheap.push_back(make_pair(it->first, (double)it->second->max_chain + (double)it->second->total_of_chains/1000));
    }

    // sorts maxheap vector into a max heap
    sort(maxheap.begin(), maxheap.end(), [](std::pair<string, double> const & lhs, std::pair<string, double> const & rhs) {
            return lhs.second > rhs.second;
           });

    // easiest checks to see if a set of courses can create a legal study plan to graduate
    for(vector<pair<string, double> >::iterator it = maxheap.begin(); it != maxheap.end(); ++it)
    {
        i = 0;
        double chain_size = it->second;
        if(chain_size > 9)
            print_and_exit("Schedule cannot be created due to there being a prereq chain greater than 8");
        if(chain_size < 8 && i>5)
            print_and_exit("Schedule cannot be created due to there being more than 5 classes with prereq chains of 8");
        if(chain_size < 8)
            break;
        i++;
    }

    // builds the schedule
    for(i=0; i<8; i++)
    {
        schedule.push_back(vector <string> (5));
        for(j=0; j<5; j++)
        {
            found_course = false;
            for(vector<pair<string, double> >::iterator it = maxheap.begin(); it != maxheap.end(); ++it)
            {
                if(can_take(courses[it->first]))
                {
                    schedule[i][j] = it->first;
                    found_course = true;
		    courses[it->first]->is_taken=true;
                    maxheap.erase(it);
                    break;
                }
            }
	    
	    // if a course cannot be found after looping through the entire list of courses there cannot be a valid schedule be created
            if(!found_course)
                print_and_exit("Could not create a course");
        }
    }

    // prints out the schedule
    for(i=0; i<8; i++)
    {
        cout << "Semester" << i+1 << ":" << schedule[i][0] << ", " << schedule[i][1] << ", "
        << schedule[i][2] << ", " << schedule[i][3] << ", " << schedule[i][4] << endl;
    }

    // time which the program finishes
    finish = clock();

    cout << "It took " << (finish-start)/(double) CLOCKS_PER_SEC << " seconds to build a schedule" << endl;

}
