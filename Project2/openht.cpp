#include<iostream>

#include<vector>

#include <cwctype>

#include<fstream>

#include "openht.h"

using namespace std;

// constructor
openAddress::openAddress() {
  // constructor left empty
}

// destructor
openAddress::~openAddress() {
  hash.clear();
}

// function to define the size of the hash table of size m
void openAddress::hashSize(int m) {
  int i = 0;
  int size = m;
  hash.clear();
  while (i < size) {
    hash.push_back(-1);
    i++;
  }
  cout << "success" << endl;

}

// function to calculate key % size of hash table
int openAddress::hashIndex(int key, int m) {
  return key % m;
}

// function to insert key k into hash table of size n
int openAddress::hashInsert(int k, int n) {

  int size = n;
  int Key_value = k;
  int counter = 0;
  int searchResult = hashSearch(Key_value, size);
  if (searchResult != -2) {
    return -2;
  }

  int index = hashIndex(Key_value, size);
  while ((hash[index] != -1) && (hash[index] != Key_value)) {
    if (hash[index] == -3) {       // -3 is placed when an element was deleted before
      hash[index] = Key_value;
      return 1;
    }
    index++;
    // error condition 
    if (index > size) {
      return -2;
    }
    // if index reaches the end of the hash table
    if (index == size) {
      index = 0;
    }
    index %= size;
    // error condition
    if (counter >= size) {
      return -2;
    }
    counter++;
  }

  hash[index] = Key_value;
  return 1;
}

// function to search a key k in the hash table of size n
int openAddress::hashSearch(int k, int n) {
  int keyValue = k;
  int size = n;
  int i = 0;
  int index = hashIndex(keyValue, size);
  while ((hash[index] != -1) && (i < size)) {

    if (hash[index] == keyValue) {
      return index;
    }
    index++;
    // error condition
    if (index > size) {
      return -2;
    }
    // if index reaches the end of the hash table
    if (index == (size)) {
      index = 0;
    }
    index %= size;
    i++;
  }

  return -2;
}

// function to delete a key d in the hash table of size m
int openAddress::hashDelete(int d, int m) {
  int keyValue = d;
  int size = m;
  int searchResult = hashSearch(keyValue, size);
  // if element not found in the hash table
  if (searchResult == -2) {             
    return 0;
  } else {
    // -3 for delete
    hash[searchResult] = -3;            
    return 1;
  }
}