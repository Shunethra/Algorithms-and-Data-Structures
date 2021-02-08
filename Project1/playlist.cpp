#include <iostream>

using namespace std;

#include "playlist.h"

// constructor
playlist::playlist() {
    // left empty
}

// destructor
playlist::~playlist() {
  entry.clear();
}

// function to find a particular song and compare it with another song
int playlist::searchEntry(string songmatch) {

  for (auto x: entry) {

    if (x.compare(songmatch) == 0) {                               // string compare function used

      return 0;
    }
  }

  return 1;
}

// function to add the entries of a song into the entry vector
void playlist::addSong(string a) {
  string search = a;
  int result = searchEntry(search);

  if (result == 0) {
    cout << "can not insert " << search << endl;
  } 
  else {
    entry.push_back(search); 
    cout << "success" << endl;
  }
}

// function to play a particular song p from the entry vector 
void playlist::playSong(int p) {
  int number = p;

  //Case1: index must not be 0 or less than 0 
  if (number <= 0) {
    cout << "could not play " << number << endl;
  }
  //Case 2: index should not exceed the size of the vector 
  else if (number > entry.size()) {
    cout << "could not play " << number << endl;
  } 
  else {
    //Case 3: else case
    cout << "played " << number << " " << entry[number - 1] << endl;
  }
}

// function to erase/delete a particular song from the entry vector
void playlist::eraseSong(int e) {
  int number = e;

  // Case1: index must not be 0 or less than 0 
  if (number <= 0) {
    cout << "could not erase " << number << endl;
  }
  //Case 2: index should not exceed the size of the vector 
  else if (number > entry.size()) {
    cout << "could not erase " << number << endl;
  } 
  //Case 3: else case
  else {
    entry.erase(entry.begin() + (number - 1));
    cout << "success" << endl;
  }
}