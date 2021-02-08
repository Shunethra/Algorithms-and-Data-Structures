#include<iostream>

#include<vector>

#include <cwctype>

#include<fstream>

#include "unorderedht.h"

using namespace std;


int main() {
  hashTable h1;
  int size;
  int insert;
  int search;
  int deleteKey;
  int result = 0;

  int no_of_lines = 0;
  string line;
  string line2;
  string input;

  while (getline(cin, line)) { // to read the number of lines in the file
    no_of_lines++;
  }
  cin.clear();
  cin.seekg(0, std::ios_base::beg);

  // loop through the lines to read the inputs  
  for (int i = 0; i < no_of_lines; i++) {
    cin >> input;

    if (input == "n") {
      getline(cin, line2, ' ');
      cin >> size;
      result = h1.hashSize(size);
      if (result == 1) {
        cout << "success" << endl;
      }
    } else if (input == "i") {
      cin >> insert;
      result = h1.hashInsert(insert, size);
      if (result == 1) {
        cout << "success" << endl;
      } else {
        cout << "failure" << endl;
      }

    } else if (input == "s") {
      cin >> search;
      result = h1.hashSearch(search, size);
      if (result == -1) {
        cout << "not found" << endl;
      } else {
        cout << "found in " << result << endl;
      }
    } else if (input == "d") {
      cin >> deleteKey;
      result = h1.hashDelete(deleteKey, size);
      if (result) {
        cout << "success" << endl;
      } else {
        cout << "failure" << endl;
      }
    }
  }
  return 0;
}
