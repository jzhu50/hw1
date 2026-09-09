#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list = ULListStr();

  list.push_back("a");
  cout << "Front: " << list.front() << endl;
  cout << "Back: " << list.back() << endl;
  cout << "Size: " << list.size() << endl;
  cout << endl;

  list.push_front("b");
  cout << "Front: " << list.front() << endl;
  cout << "Back: " << list.back() << endl;
  cout << "Size: " << list.size() << endl;
  cout << endl;

  list.pop_back();
  cout << "Front: " << list.front() << endl;
  cout << "Back: " << list.back() << endl;
  cout << "Size: " << list.size() << endl;
  cout << endl;

  list.pop_front();
  cout << "Size: " << list.size() << endl;
  cout << endl;

  return 0;
}
