/**************************************************
 * File: LeastClassrooms.cpp                      *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Given a list of lectures (intervals)  *
 *    find the smallest number of classrooms that *
 * can schedules the classes.                     *
 **************************************************/
#include "DeadlineJob.hpp"

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

// a function to help us sort by defining "less than" between two
//  intervals. In this case, we define "less than" to be based
//  only on the finish time of the Intervals (jobs).
bool compareByDeadline(const DeadlineJob &t1, const DeadlineJob &t2)
{
  return t1.deadline() < t2.deadline();
}

int main(int argc, char *argv[])
{
  // pull in filename from command prompt. 
  string fName = argv[1];

  // build input stream from filename
  ifstream ifile(fName);

  list<DeadlineJob> tasks; // list of all jobs

  DeadlineJob task; // next job in input file

  // for each job read from input file, add that job to list of all jobs
  ifile>>task;
  while(ifile)
    {
      tasks.push_back(task);

      ifile>>task;
    }

  for( DeadlineJob i: tasks)
  {
    cout << i;
    cout << endl;
  }

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  tasks.sort(compareByDeadline); // sort the provided tasks (by deadline)


  
  int currTime = 0;
  int maxLateness = 0;

  // go through each provided DeadlineJob (in order of deadline)
  for (DeadlineJob &dj : tasks)
    {
      dj.start() = currTime;
      currTime = dj.start() + dj.length();

      int lateness = max (0, currTime-dj.deadline());
      if (lateness > maxLateness)
	maxLateness = lateness; 
    }

  for( DeadlineJob i: tasks)
    {
      cout << i;
      cout << endl;
    }
    
  cout << "MaxLateness =  " << maxLateness << endl;


  
  return 0;
}
