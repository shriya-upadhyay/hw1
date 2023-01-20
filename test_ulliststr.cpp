#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
//initalizes new ULListStr
ULListStr dat;
//tries pushing back
dat.push_back("a");
//tries getting a value from index 0
cout << dat.get(0) << endl;
//tries popping front
dat.pop_front();
//tries getting size of list
cout << dat.size() << endl;

//tries pushing back
dat.push_back("b");
//tries printing size of list
cout << dat.size() << endl;
//tries printing last element in the list
cout << dat.back() << endl;
//tries pushing front
dat.push_front("c");
//tries popping front
dat.pop_front();
//tries popping back
dat.pop_back();
//tries pushing back
dat.push_back("d");
//tries printing first element of array
cout << dat.front() << endl;

} 

