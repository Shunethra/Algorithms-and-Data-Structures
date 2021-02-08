#include<iostream>

#include<vector>

#include <cwctype>

#include<fstream>

using namespace std;

class openAddress {
  private:
    vector < int > hash;

  public:
    openAddress();
  ~openAddress();
  int hashIndex(int key, int m);
  void hashSize(int m);
  int hashInsert(int k, int n);
  int hashSearch(int k, int n);
  int hashDelete(int d, int m);
};