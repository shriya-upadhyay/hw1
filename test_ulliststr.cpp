#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr dat;
dat.push_back("a");
cout << dat.get(0) << endl;
dat.pop_front();
cout << dat.size() << endl;

dat.push_back("b");
cout << dat.size() << endl;
cout << dat.back() << endl;
dat.push_front("c");
dat.pop_front();
dat.pop_back();
dat.push_back("d");
cout << dat.front() << endl;
}
