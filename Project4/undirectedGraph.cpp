#include<iostream>
#include<string>
#include<regex>
#include<iterator>
#include<bits/stdc++.h>
#include<cmath>
//#include<stdio>

#include "undirectedGraph.h"

using namespace std;

adjacencyNode::adjacencyNode(){
    distance = 0;
    adjacencyName = ""; 
    parent = ""; 
    shortestDist = 2000000000;
    next = NULL;
    minExtracted = false;
}

Node::Node(){
    adjacencyHead = NULL;
    next = NULL;
    name = "";
    parentNode = "";
    degree = 0;
    shortestDistNode =  2000000000;
    minExtractedNode = false;
}
graph::graph(){
    length = 0;
    //pathArray = new string[length];
    graphHead = NULL;
    nodesNo = 0;
    edgeNo = 0;
}


int graph::insertNode(string city){
    //cout<<city<<endl;
    Node* makeNode = new Node;
    Node* last = graphHead;
    if(graphHead == NULL){
        makeNode->name = city;
        makeNode->degree = 0;
        makeNode->adjacencyHead = NULL;
        makeNode->next = NULL;
        graphHead = makeNode; //TODO:parent/min extracted/shortest distance initialization
        nodesNo++;
        //cout<<"entered"<<endl;
        return 1;
        
    }
    else{
        while( last !=NULL ){
             string lastName= last->name;
            if( (lastName.compare(city)) == 0 ){
             //cout<<"equal"<<endl;
            return 0;

            }
            last = last->next;
            
        }
        makeNode->name = city;
        //adjacency list not declared
        makeNode->next = graphHead;
        graphHead = makeNode;
        //makeNode->next = NULL;
        // while( last !=NULL ){
        //      string lastName= last->name;
        //     if( (lastName.compare(city)) == 0 ){
        //      //cout<<"equal"<<endl;
        //     return 0;

        //     }
        //     last = last->next;
            
        // }
        // cout<<"name: "<<makeNode->name<<endl;
        // last = makeNode;
        nodesNo++;
        //cout<<"nodes:"<<nodesNo<<endl;
        return 1;
    }
    return 0;
}

int graph::setd(string city1, string city2, double d){
    int counter = 0;
    int setdResult = 0;
    //cout<<"entered"<<endl;
    // if graph is empty
    if(graphHead == NULL){
        //cout<<"entered head is null"<<endl;
        return 0;
        //cout<<"entered head is null"<<endl;
    }
    Node* last = graphHead;
    // error condition
    while( last != NULL ){
        //cout<<"loop count"<<endl;
        string lastName = last->name;
    
        //cout<<"city 1="<<city1<<" lastname="<<lastName<<endl;
        //remove(lastName.begin(), lastName.end(),' ');
        //cout<<"last size"<<lastName.size();
        //cout<<"city 1 size"<<city1.size();
        if( (city1 == lastName)){
            counter++;
        
        }
        if( (city2 == lastName) ){
            counter++;
            //cout<<" ottawa found"<<endl;
        }
        last = last->next;
    }
    //cout<<"counter: "<<counter<<endl;
    // if both cities are present, then:
    if(counter == 2){
        Node* last = graphHead;
        //cout<<"entered countered"<<endl;
        while( last !=NULL ){
            //cout<<"no of loops"<<endl;
        string lastName = last->name;
        if( (city1.compare(lastName)) == 0 ){
            //cout<<"entered1 "<<endl;
            
            setdResult = last->adjacencysetd(city2,d);
            if(setdResult == 1){
                last->degree = last->degree + 1;
                edgeNo++;
            }
        }
        if( city2.compare(lastName) == 0 ){
            //cout<<"entered 2"<<endl;
            setdResult = last->adjacencysetd(city1,d);
            if(setdResult == 1){
                last->degree = last->degree + 1;
                //edgeNo++;
            }
        }
        last = last->next;
        }
        return setdResult;    // check this statement later
    }
    return 0;
}

int Node::adjacencysetd(string city, double d){
    adjacencyNode* adjNode = new adjacencyNode;
    adjacencyNode* last = adjacencyHead;
    if(adjacencyHead == NULL){
        adjNode->adjacencyName = city;
        adjNode->distance = d;
        adjNode->next = NULL;
        adjacencyHead = adjNode;
        return 1;
    }
    else{
        adjNode->adjacencyName = city;
        adjNode->distance = d;
        adjNode->next = adjacencyHead;
        adjacencyHead = adjNode;
        // while( last->next !=NULL ){
        //     last = last->next; 
        // }
        // last->next = adjNode;
        return 1;
        // adjNode->adjacencyName = city;
        // adjNode->next = NULL;
        // while( last->next !=NULL ){
        //     last = last->next; 
        // }
        // last->next = adjNode;
        // return 1;
    }
    return 0;
}


string graph::search(string city){
    string error ="error";
    if(graphHead == NULL){
        return error;
    }
    else{
        Node* last = graphHead;
        while( last !=NULL ){
             string lastName = last->name;
            if( (lastName.compare(city)) == 0 ){
                return lastName;
            }
            last = last->next;
        }
        return error;
    }
}

double graph::findDistance(string city1, string city2){
    int counter = 0;
    if(graphHead == NULL){
        return -1;
    }
    else{
        Node* last = graphHead;
        while( last != NULL ){
        //cout<<"loop count"<<endl;
        string lastName = last->name;
    
        //cout<<"city 1="<<city1<<" lastname="<<lastName<<endl;
        //remove(lastName.begin(), lastName.end(),' ');
        //cout<<"last size"<<lastName.size();
        //cout<<"city 1 size"<<city1.size();
        if( (city1 == lastName)){
            counter++;
        
        }
        if( (city2 == lastName) ){
            counter++;
            //cout<<" ottawa found"<<endl;
        }
        last = last->next;
        }
        if(counter == 2){
            last = graphHead; 
            //cout<<"entered "<<endl;
            while( last != NULL ){
            //cout<<"no of loops"<<endl;
            string lastName = last->name;
            if( lastName == city1 ){ 
                //cout<<"enetred"<<endl;
                return last->adjacencyDistance(city2);
            }
            if( city2.compare(lastName) == 0 ){
                last->adjacencyDistance(city1);
            }
            last = last->next;
            }
        }
        else if( counter < 2){
            return -1;                            // newly added
        }
    }
}

double Node::adjacencyDistance(string city){
    
    if(adjacencyHead == NULL){
        //cout<<" head 0"<<endl;
        return -1;
    }
    
    else{
        adjacencyNode* last = adjacencyHead;
        while( last != NULL ){
        //cout<<"loop count"<<endl;
        string lastName = last->adjacencyName;
    
        //cout<<"city 1="<<city1<<" lastname="<<lastName<<endl;
        //remove(lastName.begin(), lastName.end(),' ');
        //cout<<"last size"<<lastName.size();
        //cout<<"city 1 size"<<city1.size();
        if( city == lastName ){
            //cout<<" entered hhh"<<endl;
            double d = last->distance;
            //cout<<"d: "<<last->distance<<" city "<<last->adjacencyName<<endl;
            return d;
        }
        
        last = last->next;
        }
        return -1;
    }

}

int graph::findDegree(string city){
    if(graphHead == NULL){
        return -1;
    }
    else{
        Node* last = graphHead;
         while( last != NULL ){
        //cout<<"loop count"<<endl;
        string lastName = last->name;

        if( (city == lastName)){
            int d = last->degree;
            //cout<<"d: "<<d<<endl;
            return d;
        }
        
        last = last->next;
        }
        return -1;
    }
}

int graph::graph_nodes(){
    //cout<<"nodesNo"<<nodesNo<<endl;
    return nodesNo;
}

int graph::graph_edges(){
    // int sum =0;
    // Node* last = graphHead;
    // while( last != NULL ){
    //     //cout<<"loop count"<<endl;
    //     int degNo = last->degree;
    //     sum = sum + degNo;
    //     cout<<"sum: "<<sum<<endl;
        
    //     last = last->next;
    // }
    //return sum;
    return edgeNo;
}

void graph::clear(){
    int sum = 0;
    if(graphHead == NULL){
        //cout<<"success"<<endl;
    }
    else{
        Node* current = graphHead;
        Node* temp;
        while(current != NULL){
            graphHead->clearNode();
            temp = current->next;
            current->degree = 0;
            sum = sum + current->degree;
            delete current;
            nodesNo = nodesNo - 1;
            current = temp;
        }
        graphHead = NULL;
    }
    if( (nodesNo == 0) && (sum == 0)){
        edgeNo = 0;
        cout<<"success"<<endl;
    }
}

void Node::clearNode(){
    if(adjacencyHead != NULL){
        adjacencyNode* current2 = adjacencyHead;
        adjacencyNode* temp2;
         while( current2 != NULL ){
            temp2 = current2->next;
            delete current2;
            current2 = temp2;
        }
        adjacencyHead = NULL;
    }
}

double graph::findShortDist(string city1,string city2){
    int counter = 0;
    double infinity =  2000000000;
    Node* last = graphHead;
    double shortDist = 0;
    if( graphHead == NULL){
        return -1;
    }
    if(city1 == city2){
        return 0;
        //cout<<"shortest distance "<<city1<<" to "<<city2<<" "<<shortDist<<endl;//TODO: If same city then print shortest distance = 0
    }
    while(last != NULL){
        string lastName = last->name;
        
        if( (lastName.compare(city1)) == 0 ){
            counter++;
        }
        if( (lastName.compare(city2)) == 0 ){
            counter++;
        }
        last = last->next;
    }
    if(counter == 2){
       //cout<<"success- it entered counter = 2"<<endl;
        last = graphHead;
        while(last != NULL){    //initialization
            string lastName = last->name;
            if( (lastName.compare(city1)) == 0 ){           // TODO: reinitialize the shortest distance - DONE
                //cout<<"initialization"<<endl;
                last->parentNode = "";
                last->shortestDistNode = 0;
                last->minExtractedNode = false;
                //cout<<last->name<<" "<<last->shortestDistNode<<endl;
            }
            else{
            last->shortestDistNode = infinity;
            last->minExtractedNode = false;
            }
            last->sourceDist(city1);
            last = last->next;
        }

        Node* pointerMin = graphHead;
        while( pointerMin != NULL){
            extractMinimum();
            //cout<<"extract min"<<endl;
            pointerMin = pointerMin->next;
        }
        



        //relaxGraph();
        Node* current = graphHead;
        while(current != NULL){
            string currentName = current->name;
            if( (currentName.compare(city2)) == 0 ){   // to find shortest distance
            //cout<<"city "<<current->name<<" "<<current->shortestDistNode<<endl;
                return current->shortestDistNode;
                // last->parentNode = "";
                // last->shortestDistNode = 0;
            }
            current = current->next;
        }                                                       // TODO: take shortest d of the dest node
    }
    return -1;
}
int Node::sourceDist(string city1){
    //cout<<"entered source"<<endl;
    double infinity =  2000000000;
    adjacencyNode* last = adjacencyHead;
    while(last != NULL){
        string lastName = last->adjacencyName;
        if( (lastName.compare(city1)) == 0 ){
            last->parent = "";
            last->shortestDist = 0;
            last->minExtracted = false;
            //last->minExtracted = false;       
        }
        else{
        last->shortestDist = infinity;
        last->minExtracted = false;
        }
        last = last->next;    
    }
} 


void graph::relaxNode(string Vertex_name, double u){

    //Node *Temp_vertex = new Node; 
   // adjacencyNode *Temp_adj = new adjacencyNode; 

    Node* Temp_vertex = graphHead;
    while(Temp_vertex != NULL){

        if(Temp_vertex->name == Vertex_name){
            adjacencyNode* Temp_adj = Temp_vertex->adjacencyHead; 

            while(Temp_adj != NULL){
                if(Temp_adj->minExtracted == true){
                    Temp_adj = Temp_adj->next; 
                    continue; 
                }
                double edgeWeight = Temp_adj->distance;
                //cout<<"edge weight: "<<edgeWeight<<endl;
                double v = Temp_adj->shortestDist;
                 if( v > (u + edgeWeight)){
                     v = u + edgeWeight;
                    Temp_adj->parent = Vertex_name;              //  update parents
                    Temp_adj->shortestDist = v;
                    //cout<<v<<" > "<<u<<" + "<<edgeWeight<<endl;
                 
                    Update_Verticies(Temp_adj->adjacencyName,Temp_adj->shortestDist,Temp_adj->parent);  
                 }              
                Temp_adj = Temp_adj->next; 
            }
            break;                              // try taking this later if u want to compile
        }

        Temp_vertex = Temp_vertex->next; 
    } 

}

void graph::Update_Verticies(string city_name, double shortest_distance, string parent_name){
    //cout<<"enetered updated"<<endl;
         Node* last = graphHead;
         while( last != NULL ){
 
            if(last->name == city_name){
                //cout<<"entered updated 2"<<endl;
                last->shortestDistNode = shortest_distance;             // if it doesn't work, then think of updating the adjacency list also
                last->parentNode = parent_name; 
                //cout<<last->name<<" = "<<city_name<<" break"<<endl;
                //break;
                //cout<<" !!!!"<<endl;
            }
            //cout<<last->name<<" = "<<city_name<<" not break"<<endl;
            adjacencyNode* adjLast = last->adjacencyHead;
            while(adjLast != NULL){
                if(adjLast->adjacencyName == city_name){
                    adjLast->shortestDist = shortest_distance;             
                    adjLast->parent = parent_name;  
                }
                adjLast = adjLast->next;
            }
        
        last = last->next;
        }
}

double graph::extractMinimum(){   // fnction to be called from findShortdist func
//cout<<"entered extract min"<<endl;
    Node* last = graphHead;
    //adjacencyNode* adjLast = new adjacencyNode;
    string minDistNode = "";
    double minDist =  2000000000;
    double distNodeValue ; 
    // while(last != NULL){
        Node* tempMin = graphHead;
        while( tempMin != NULL){
            distNodeValue = tempMin->shortestDistNode; 
            //cout<<"city: "<<tempMin->name<<" shortestdist "<<tempMin->shortestDistNode<<endl;
            //cout<<"distNodeValue"<<distNodeValue<<endl;
            if(tempMin->minExtractedNode == false){         // if minextracted is still in false , only then find min
            //cout<<"came"<<endl;
                if( distNodeValue < minDist){
                    //cout<<" came 2"<<endl;
                    minDist = distNodeValue;
                    minDistNode = tempMin->name;
                    //cout<<"min Node: "<<minDistNode<<" shortest d "<<minDist<<endl;

                }
                    //TODO: Have a loop to itterate through inner and set min extracted to false.
            }
            tempMin = tempMin->next;
        }
        //cout<<"min Node: "<<minDistNode<<" shortest d "<<minDist<<endl;
        Node* last2 = graphHead;
        string check = "";
        if( check != minDistNode){
            while(last2 != NULL){
                    if( last2->name == minDistNode){
                        last2->minExtractedNode = true;
                    }
                    adjacencyNode* adjLast = last2->adjacencyHead;
                    while( adjLast != NULL){
                        if( adjLast->adjacencyName == minDistNode){
                            adjLast->minExtracted = true;
                        }
                        adjLast= adjLast->next;
                    }
            
                last2 = last2->next;
            }
        } 
        relaxNode(minDistNode,minDist);
        //cout<<"finished relax node"<<endl;
        //last = last->next;

    //return minDist;
    //relaxGraph->(minDist);
}


int graph::printPath(string city1, string city2){
	//cout<<"enetred"<<endl;
    length = 0;
    //int arraySize = nodesNo;
    pathArray = new string[nodesNo+1];
    int count = 0;

    int j = 0;
    double shortestResult;
    Node* last = graphHead;
    while(last != NULL){
        string lastName = last->name;

        if( (lastName.compare(city1)) == 0 ){
            //cout<<"enter"<<endl;
            count++;
        }
        if( (lastName.compare(city2)) == 0 ){
            count++;
        }
        last = last->next;
    }
    //cout<<count<<endl;
    if(count != 2){
        return 0;
    }
    if( count == 2){
        if(city1 == city2){
            return -1;
        }
    }
    
    
    while( j < nodesNo){
        pathArray[j] = "";
        j++;
    }
    shortestResult = findShortDist(city1,city2);
	//cout<<"shortResult"<<shortestResult<<endl;
    if( shortestResult == -1){
        //cout<<"im here"<<endl;
        return 0;
    }
    if(shortestResult ==  2000000000){
        return 0;
    }
   // findParent(pathArray,city1,city2);
    //int i = length;

    // for(int i= arraySize; i>= 0; i--){
    //     if(pathArray[i] == ""){
    //         //cout<<"its empty"<<endl;
    //     }
    //     else{
    //         //cout<<"its not empty"<<endl;
    //         cout<<pathArray[i]<<" ";
    //     }
    // }

    findParent(city1,city2);

    int i = nodesNo;
    //cout<<"i:"<<i<<endl;
    while( i >= 0 ){
        //cout<<"hey"<<endl;
        if(pathArray[i] == ""){
           //cout<<" skip"<<endl;
           //i--;
           //continue;
        }
        else{
            //cout<<"came"<<endl;
            cout<<pathArray[i];
            cout<<" ";
        //i--;
        }
        i--;
    }
    cout<<endl;
}

void graph::findParent(string city1, string city2){
    //length = length + 1;
    Node* last = graphHead;

    

    //cout<<"entered"<<endl;
    while( last!= NULL ){
        //cout<<"while"<<endl;
        string lastName = last->name;
        if( (lastName.compare(city2)) == 0 ){
            //cout<<"last name:"<<lastName<<endl;
            //cout<<"entered "<<endl;
            pathArray[length] = last->name;
            //cout<<"array:"<<pathArray[length]<<endl;
            
            //cout<<";"<<last->name<<";"<<endl;;
            string parentCity = last->parentNode;
            if( parentCity == ""){
                //cout<<"entered else"<<endl;
                break;
            }
            else{
                length = length + 1;
                //cout<<"e"<<endl;
                //cout<<parentCity<<" ";
                findParent(city1,parentCity);
                

            }
            
        }   
        last = last->next;     
    }
    //return pathArray;
    //return 0;
}