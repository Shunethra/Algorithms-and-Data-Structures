#include<iostream>

#include<vector>

#include <cwctype>

#include<fstream>

#include "unorderedht.h"

using namespace std;

// function to define the size of the hash table of size m
int hashTable::hashSize(int m) {
  int size = m;
  int i = 0;
  while (i < size) {
    hash.push_back(NULL);     // initializes vector nodes with null 
    i++;
  }
  return 1;
}

// function to calculate key % size of hash table
int hashTable::hashIndex(int key, int m) {
  return key % m;
}

// function to insert key k into hash table of size n
int hashTable::hashInsert(int k, int n) {

  int index = hashIndex(k, n);

  int searchResult = hashSearch(k, n);
  // if element already in the hash table
  if (searchResult != (-1)) {
    return -1;
  }
  if ((hash.at(index)) == NULL) {
    Node * valueNode = new Node;
    valueNode-> key = k;
    valueNode -> next = NULL;
    hash.at(index) = valueNode;
  } else {
    Node * valueNode = new Node;
    valueNode -> next = NULL;
    valueNode -> key = k;
    valueNode -> next = hash.at(index); 
    hash.at(index) = valueNode;
  }
  return 1;

}

// function to search a key k in the hash table of size n
int hashTable::hashSearch(int k, int n) {
  int index = hashIndex(k, n);
  Node * current = hash.at(index);
  while (current != NULL) {

    if (current -> key == k) {
      return index;
    }
    current = current -> next;
  }
  return -1;
}

// function to delete a key k in the hash table of size m
int hashTable::hashDelete(int d, int m) {
  int index = hashIndex(d, m);
  Node * current = hash.at(index);
  Node * previous = NULL;
  int searchResult = hashSearch(d, m);

  // if element to delete is not found in the hash table
  if (searchResult == -1) {
    return 0;
  }
  // inserts into hash table if next node is equal to null
  if (current -> next == NULL) {
    hash.insert(hash.begin() + index, NULL);
  } else {
    while ((current -> next != NULL) && (current -> key != d)) {
      previous = current;
      current = current -> next;
    }
    if (current -> key == d) {
      if (previous == NULL) {
        Node * nextCurrent = current -> next;
        delete current;
        hash.at(index) = nextCurrent;

      } else {
        Node * nextCurrent = current -> next;
        delete current;
        previous -> next = nextCurrent;

      }
    }
  }
  return 1;

}