#include<iostream>

#include<string>

#include <cwctype>

#include<fstream>

#include "playlist.h"

using namespace std;

#include <vector>


int main() {
  playlist p1;                                       // object p1 created of the class playlist
  int no_of_lines = 0;
  string line;
  string line2;
  string input;
  string song;
  int songNumber;
  
  while (getline(cin, line)) {                      // to read the number of lines in the file
    no_of_lines++;
  }
  cin.clear();                                      
  cin.seekg(0, std::ios_base::beg);                 

  // loop through the lines to read the inputs  
  for (int i = 0; i < no_of_lines; i++) {           
    cin >> input;

    if (input == "i") {
      getline(cin, line2, ' ');
      getline(cin, line2);                        // to read the string 
      p1.addSong(line2);                          // calls addSong function
    } 
    else if (input == "p") {
      cin >> songNumber;
      p1.playSong(songNumber);                    // calls playSong function
    } 
    else if (input == "e") {
      cin >> songNumber;
      p1.eraseSong(songNumber);                   // calls eraseSong function
    }
  }
}