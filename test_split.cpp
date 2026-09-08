/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Node* n5 = new Node{5, nullptr};
  Node* n4 = new Node{4, n5};
  Node* n3 = new Node{3, n4};    
  Node* n2 = new Node{2, n3};
  Node* n1 = new Node{1, n2};
  
  Node* in = n1;
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);

  Node* oddsH = odds;
  Node* evensH = evens;

  // Print odds
  cout << "Odds: ";
  while (odds != nullptr) {
    cout << odds->value << " ";
    odds = odds->next;
  }
  cout << endl;

  // Print evens
  cout << "Evens: ";
  while (evens != nullptr) {
    cout << evens->value << " ";
    evens = evens->next;
  }
  cout << endl;

  // free memory
  while (oddsH != nullptr) {
    Node* tmp = oddsH;
    oddsH = oddsH->next;
    delete tmp;
  }

  while (evensH != nullptr) {
    Node* tmp = evensH;
    evensH = evensH->next;
    delete tmp;
  }
  
  return 0;
}