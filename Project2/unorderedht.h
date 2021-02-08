#include<iostream>

#include<vector>

#include <cwctype>

#include<fstream>

using namespace std;

struct Node {                          // class for the linkedlist
  int key;
  Node * next;
};

class hashTable {                     // class for the hashtable containing vector nodes
  private:
    vector < Node * > hash;           // vector of pointers to store the keys

  public:
  int hashSize(int m);                // function to define the size of the hash table of size m
  int hashIndex(int key, int m);      // function to calculate key % size of hash table
  int hashInsert(int k, int n);       // function to insert key k into hash table of size n
  int hashSearch(int k, int n);       // function to search a key k in the hash table of size n
  int hashDelete(int k, int m);       // function to delete a key k in the hash table of size m
};