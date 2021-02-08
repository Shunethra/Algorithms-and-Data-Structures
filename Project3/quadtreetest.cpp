#include<iostream>
#include<string>
#include <cwctype>

#include<fstream>

using namespace std;
#include "quadtree.cpp"

//int counter;

int main(){
   
    quadTree t1;
    string city;
    char semicolon;
    double latitude;
    double longitude;
    int pop;
    int cost;
    int salary;
    string dirvariable;
    string attrvariable;

    int result = 0;
    int searchResult =0;
    int q_maxResult;
	int sizeResult = 0;
    int empty;
    int q_minResult = 0;
    int q_totalResult = 0;
    int no_of_lines = 0;

    string line;
    string line2;
    string line3;
    string input;
    double value = 0;
    double array[5];

    while (getline(cin, line)) { // to read the number of lines in the file
        no_of_lines++;
        
    }
    //cout<<"lines"<<no_of_lines<<endl;
    cin.clear();
    cin.seekg(0, std::ios_base::beg);

    // loop through the lines to read the inputs  
    for (int i = 0; i < no_of_lines; i++) {
        //getline(cin,line3," ")
        cin>>input;
        //cout<<"input "<<input<<endl;
        //cout<<"entered"<<endl;

        if (input == "size") {
            //cout<<"size:"<<input<<"end"<<endl;
            //getline(cin,input,'\n');
            //cin>>empty;
            //cout<<"entered"<<endl;
			sizeResult=t1.treeSize();
        cout<<"tree size "<<sizeResult<<endl;
        }
         
        else if (input == "i") {
            //cout<<"entered input"<<endl;
        getline(cin,input,' ');
        getline(cin,input,';');
        city = input;
        //cout<<"city"<<city<<endl;
        getline(cin,input, ';');
        latitude = stof(input);
        //cout<<"latitude: "<<latitude<<endl;
        getline(cin,input,';');
        longitude = stof(input);
        //cout<<"longitude "<<longitude<<endl;
        getline(cin,input,';');
        pop = stoi(input);
        //cout<<"pop "<<pop<<endl;
        getline(cin,input,';');
        cost = stoi(input);
        //cout<<"cost "<<cost<<endl;
        getline(cin,input,'\n');
        salary = stoi(input);
        //cout<<"sal "<<salary<<endl;
        
        result = t1.insertRoot(city,latitude, longitude, pop, cost, salary);
            if(result){
                cout<<"success "<<endl;
                //counter++;
            }
            else{
                cout<<"failure "<<endl;
            }
            //getline(cin,input,'\n');
        }
        
        else if (input == "print") {
            t1.printTree();
            cout<<endl;
        }

        else if (input == "s") {
            getline(cin,input, ';');
            latitude = stof(input);
            //cout<<"latitude: "<<latitude<<endl;
            getline(cin,input,'\n');
            longitude = stof(input);
            // cin>> longitude;
            // cin>> semicolon;
            // cin>> latitude;
            searchResult = t1.searchTree(latitude, longitude);
            //cout<<"after\n";
            if(searchResult == 0){
                cout<<"not found"<<endl;    
            }
        }
        else if(input == "q_max"){
            getline(cin,input, ';');
            latitude = stof(input);
            //cout<<"latitude: "<<latitude<<endl;
            getline(cin,input, ';');
            longitude = stof(input);
            //cout<<"longitude: "<<longitude<<endl;
            getline(cin,input, ';');
            dirvariable = input;
            //cout<<"dir "<<dirvariable<<"hello"<<endl;
            //getline(cin,input,'\n');
            cin>>attrvariable;
            //cout<<attrvariable<<"end"<<endl;
            //cout<<"attr"<<attr<<"hello"<<endl;
            // dirvariable= "NW";
            //attrvariable ="p";
           
            q_maxResult = t1.maxTree(latitude,longitude,dirvariable,attrvariable);
            //cout<<"entered"<<endl;
            if(q_maxResult == 0){
                cout<<"failure"<<endl;
            }
            else{
                cout<<"max "<<q_maxResult<<endl;
            }
        }

        else if (input == "q_min"){
            getline(cin,input, ';');
            latitude = stof(input);
            //cout<<"latitude: "<<latitude<<endl;
            getline(cin,input, ';');
            longitude = stof(input);
            //cout<<"longitude: "<<longitude<<endl;
            getline(cin,input, ';');
            dirvariable = input;
            //cout<<"dir "<<dirvariable<<"hello"<<endl;
            //getline(cin,input,'\n');
            cin>>attrvariable;
            q_minResult = t1.minTree(latitude,longitude,dirvariable,attrvariable);
            if(q_minResult == 0){
                cout<<"failure"<<endl;
            }
            else{
                cout<<"min "<<q_minResult<<endl;
            }
        }
        else if (input == "q_total"){
            getline(cin,input, ';');
            latitude = stof(input);
            //cout<<"latitude: "<<latitude<<endl;
            getline(cin,input, ';');
            longitude = stof(input);
            //cout<<"longitude: "<<longitude<<endl;
            getline(cin,input, ';');
            dirvariable = input;
            cin>>attrvariable;
            q_totalResult = t1.totalTree(latitude,longitude,dirvariable,attrvariable);
            if(q_totalResult == 0){
                cout<<"failure"<<endl;
            }
            else{
                cout<<"total "<<q_totalResult<<endl;
            }
        }
        else if(input == "clear"){
            t1.clear();
            /*if(counter == 0){
                cout<<"success"<<endl;
            }*/
        }
        //getline(cin,input,'\n');
    }
    return 0;
 }
