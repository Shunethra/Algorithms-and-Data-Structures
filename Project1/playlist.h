#include<iostream>
#include<string>
#include <cwctype>
#include<fstream>

using namespace std;

#include <vector>

class playlist{
    private:
    vector<string> entry;           // vector to store the songs in the playlist
    
    public:
    playlist();                     //constructor                       
    ~playlist();                    //destructor
    void addSong(string a);         //function to add the entries of a song into the entry vector
    void playSong(int p);           // function to play a particular song p from the entry vector 
    void eraseSong(int e);          // function to erase/delete a particular song s from the entry vector
    int searchEntry(string s);      // function to find particular entries of song and compare it with another song
};