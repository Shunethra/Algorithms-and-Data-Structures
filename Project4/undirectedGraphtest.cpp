#include<iostream>
#include<string>
#include<regex>
#include<iterator>
#include<bits/stdc++.h>
#include<cmath>

#include "undirectedGraph.cpp"

using namespace std;



int main(){
    graph g1;
    string city1;
    string city2;
    double d;

    string input;
    int no_of_lines = 0;
    int result = 0;
    int insertResult = 0;
    int setResult = 0;
    double dResult = 0;
    double shortestResult = 0;
    double printResult = 0;
    string searchResult;

    string line;
    char semicolon;


    //cout<<"no_of_lines: "<<no_of_lines<<endl;
    while (getline(cin, line)) { // to read the number of lines in the file
        no_of_lines++;
        
    }
    cout<<"no_of_lines"<<no_of_lines<<endl;
    cin.clear();
    cin.seekg(0, std::ios_base::beg);

    // loop through the lines to read the inputs  
    int i = 0;
    while (i < no_of_lines) {
    //for (int i = 0; i < no_of_lines-1; i++) {
        //cout<<"loop "<<i<<endl;
        cin>>input;
        //cout<<"input "<<input<<endl;
        //cout<<"entered"<<endl;

        if (input == "i") {
            getline(cin,input,' ');
            //getline(cin,input);
            cin>>input;
            city1 = input;
           //cout<<"city:"<<city1<<"X"<<endl;
			insertResult=g1.insertNode(city1);
            if(insertResult == 1){
                cout<<"success"<<endl;
            }
            else{
                cout<<"failure"<<endl;
            }
        }
         
        if (input == "setd") {
            //cout<<"entered input"<<endl;
        getline(cin,input,' ');
        getline(cin,input,';');
        city1 = input;
        //cout<<"city1:"<<city1;
        getline(cin,input, ';');
        city2 = input;
        //cout<<"city2:"<<city2<<endl;
        getline(cin,input,'\n');
        d = stod(input);
        //cout<<"distance"<<d<<endl;
        
        setResult = g1.setd(city1,city2,d);
        //cout<<"setResult"<<setResult<<endl;
            if(setResult == 1){
                cout<<"success "<<endl;
                //counter++;
            }
            else{
                cout<<"failure "<<endl;
            }
        }

        if(input == "s"){
            getline(cin,input,' ');
            cin>>input;
            city1 = input;
            searchResult = g1.search(city1);
            if(searchResult == "error"){
                cout<<"not found"<<endl;
            }
            else{
                cout<<"found "<<searchResult<<endl;
            }
        }

        if(input == "d"){
            getline(cin,input,' ');
            getline(cin,input,';');
            city1 = input;
            cin>>input;
            // city1 = input;
            // cin>>semicolon;
            // cin>>input;
            city2 = input;
            // cout<<"distance"<<d<<endl
            dResult = g1.findDistance(city1,city2);
            if(dResult == -1){
                cout<<"failure"<<endl;
            }
            else{
                cout<<"direct distance "<<city1<<" to "<<city2<<" "<<dResult<<endl;
            }
        }

        if(input == "degree"){
            getline(cin,input,' ');
            cin>>input;
            city1 = input;
            result = g1.findDegree(city1);
            if(result == -1){
                cout<<"not found"<<endl;
            }
            else{
            cout<<"degree of "<<city1<<" "<<result<<endl;
            }
            
        }

        if(input == "graph_nodes"){
            //cout<<"eneterd"<<endl;
            result = g1.graph_nodes();
            cout<<"number of nodes "<<result<<endl;
        }

        if(input == "graph_edges"){
            
            result = g1.graph_edges();
            cout<<"number of edges "<<result<<endl;
        }
        
        if(input == "clear"){
            g1.clear();
        }
        if(input == "shortest_d"){
            getline(cin,input,' ');
            getline(cin,input,';');
            city1 = input;
            cin>>input;
            // city1 = input;
            // cin>>semicolon;
            // cin>>input;
            city2 = input;
            //cout<<"city2 is"<<city2<<endl;
            shortestResult = g1.findShortDist(city1,city2);
            //cout<<"shortest result:"<<shortestResult<<endl;
            if(shortestResult == -1){
                cout<<"failure"<<endl;
            }
            else if( shortestResult ==  2000000000 ){
                cout<<"failure"<<endl;
            }
            else{
                cout<<"shortest distance "<<city1<<" to "<<city2<<" "<<shortestResult<<endl;
            }
        }
        if(input == "print_path"){
			//cout<<"entered"<<endl;
            getline(cin,input,' ');
            getline(cin,input,';');
            city1 = input;
			//cout<<"city1:"<<city1<<";"<<endl;
            cin>>input;
            // city1 = input;
            // cin>>semicolon;
            // cin>>input;
            city2 = input;
			//cout<<"city2:"<<city2<<";"<<endl;
            printResult = g1.printPath(city1,city2);
			//cout<<"print:"<<printResult<<endl;
            if(printResult == 0){
                cout<<"failure"<<endl;
            }
            else if(printResult == -1){
                cout<<city1<<endl;
            }
        }
        //cout<<"i: "<<i<<endl;
        i++;
    }
    //return 0;
   // cout<<"Oh no!"<<endl;
 }