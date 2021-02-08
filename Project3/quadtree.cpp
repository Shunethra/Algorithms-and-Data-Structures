#include<iostream>
#include<string>
#include <cwctype>
#include "quadtree.h"

#include<fstream>

using namespace std;
//#include "quadtree.h"

//int counter=0;

quadTreeNode::quadTreeNode(){
    NE = NULL;
    NW = NULL;
    SW = NULL;
    SE = NULL;
    city = '0';
	
}

quadTree:: quadTree(){
    root = NULL;
    size = 0;
	counter = 0;
}

//int quadTree::counter(counter){
	//return counterNode(counter);
//}
	
quadTreeNode* quadTreeNode::newNode(string a, double x, double y, int pop, int cost, int salary){
     quadTreeNode* makeNode = new quadTreeNode;
     makeNode->city = a;
     makeNode->latitude = x;
     makeNode->longitude = y;
     makeNode->population = pop;
     makeNode->cost = cost;
     makeNode->salary = salary;

     makeNode->NE = NULL;
     makeNode->NW = NULL; 
     makeNode->SW = NULL;
     makeNode->SE = NULL;
     return makeNode;
}

quadTreeNode* quadTree::newRoot(string a, double x, double y, int pop, int cost, int salary){
     quadTreeNode* makeRoot = new quadTreeNode;
     makeRoot->city = a;
     makeRoot->latitude = x;
     makeRoot->longitude = y;
     makeRoot->population = pop;
     makeRoot->cost = cost;
     makeRoot->salary = salary;

     makeRoot->NE = NULL;
     makeRoot->NW = NULL;
     makeRoot->SW = NULL; 
     makeRoot->SE = NULL;
     return makeRoot;
}

int quadTree::treeSize(){
	return counter;
}
bool quadTree::insertRoot(string a, double x, double y, int pop, int cost, int salary){
    if(root == NULL){
        root = newRoot(a,x,y,pop,cost,salary);
		counter++;
		//cout<<"string ="<<a<<endl;
        return true;
    }
    else {
        int result = root->insertNode(a,x,y,pop,cost,salary);
        if(result == 1){
			counter++;
			//cout<<"string ="<<a<<endl;
			return true;
        }
        else{
            return false;
        }
    }
}

bool quadTreeNode::insertNode(string a, double x, double y, int pop, int cost, int sal){
    if( (x==latitude) && (y== longitude)){
        return false;
    }
        // north east
        if( (x >= latitude) && (y > longitude) ){
            if(NE == NULL){
                NE = newNode(a,x,y,pop,cost,sal);
                return true;
            }
            else{
                return NE->insertNode(a,x,y,pop,cost,sal);
            }
        
        }
        // north west
        else if( (x < latitude) && (y >= longitude) ){
            if(this->NW == NULL){
                this->NW = newNode(a,x,y,pop,cost,sal);
                return true;
            }
            else{
                return NW->insertNode(a,x,y,pop,cost,sal);
            }
        }

        // south west
        else if( (x <= latitude) && (y < longitude) ){
            if(this->SW == NULL){
                this->SW = newNode(a,x,y,pop,cost,sal);
                return true;
            }
            else{
                return SW->insertNode(a,x,y,pop,cost,sal);
            }
        }

        // south east
        else if( (x > latitude) && (y <= longitude) ){
            if(this->SE == NULL){
                this->SE = newNode(a,x,y,pop,cost,sal);
                return true;
            }
            else{
                return SE->insertNode(a,x,y,pop,cost,sal);
            }
        } 
}                                                                         

void quadTree::printTree(){
    if(root == NULL){
        //cout<<"no elements to print"<<endl;
    }
    else{
        root->printNode();
        
    }
}

void quadTreeNode::printNode(){
        if(NE != NULL){
        NE->printNode();
        }
        if(NW != NULL){
        NW->printNode();
        }
        cout<<city<<" ";
        //if()
        if(SW != NULL){
        SW->printNode();
        }
        if(SE != NULL){
        SE->printNode();
        }
}

int quadTree::searchTree(double x, double y){
    if(counter == 0){
        return 0;
    }
    if(root == NULL){
        return 0;
    }
    else{
        return root->searchNode(x,y);
    }
}

int quadTreeNode::searchNode(double x, double y){
    if((x == latitude) && (y == longitude)){
        cout<<"found "<<city<<endl;
        return 1;
    }
    else if( (x >= latitude) && (y > longitude) ){
            if(NE == NULL){
                return 0;
            }
            else{
                return NE->searchNode(x,y); 
            }
        
        }
        // north west
        else if( (x < latitude) && (y >= longitude) ){
            if(NW == NULL){
                return 0;
            }
            else{
                return NW->searchNode(x,y);
            }
        }

        // south west
        else if( (x <= latitude) && (y < longitude) ){
            if(SW == NULL){
                return 0;
            }
            else{
                return SW->searchNode(x,y);
            }
        }

        // south east
        else if( (x > latitude) && (y <= longitude) ){
            if(SE == NULL){
                return 0;
            }
            else{
                return SE->searchNode(x,y);
            }
        }
        return 0;
}

int quadTree::maxTree(double x, double y, string direction, string attr){
    if(root == NULL){
        return 0;
    }
    else{
        return root->findMaxNode(x,y,direction,attr);
    }
}

int quadTreeNode::findMaxNode(double x, double y, string direction, string attr){
    if((x == latitude) && (y == longitude)){
        if(direction == "NE"){
            if(NE == NULL){
                return 0;
            }
            return NE->findMax(attr);
        }
        else if(direction == "NW"){
            if(NW == NULL){
                return 0;
            }
            return NW->findMax(attr);
        }
        else if(direction == "SW"){
            if(SW == NULL){
                return 0;
            }
            return SW->findMax(attr);
        }
        else if(direction == "SE"){
            if(SE == NULL){
                return 0;
            }
            return SE->findMax(attr);
        }
    }
    else if( (x >= latitude) && (y > longitude) ){
            if(NE == NULL){
                return 0;
            }
            else{
                return NE->findMaxNode(x,y,direction,attr); 
            }
        
        }
        // north west
        else if( (x < latitude) && (y >= longitude) ){
            if(NW == NULL){
                return 0;
            }
            else{
                return NW->findMaxNode(x,y,direction,attr);
            }
        }

        // south west
        else if( (x <= latitude) && (y < longitude) ){
            if(SW == NULL){
                return 0;
            }
            else{
                return SW->findMaxNode(x,y,direction,attr);
            }
        }

        // south east
        else if( (x > latitude) && (y <= longitude) ){
            if(SE == NULL){
                return 0;
            }
            else{
                return SE->findMaxNode(x,y,direction,attr);
            }
        }
        return 0;


}

int quadTreeNode::findMax(string attr){

    int Max = 0;
    int NE_Max = 0; //do this for all directions ;
    int NW_Max = 0;
    int SW_Max = 0;
    int SE_Max = 0;
    
    

    if(attr == "p"){
         Max = population;
        }
    else if(attr == "r"){
        Max = cost;
    }
    else if(attr == "s"){
        Max = salary;
    }
        //do for all the other 3 directions

    if (NE!=NULL){           
        NE_Max = NE->findMax(attr);
        if(NE_Max > Max){
            Max = NE_Max;
        }
    } 
    else if(NW != NULL){
        NW_Max = NW->findMax(attr);
        if(NW_Max > Max){
            Max = NW_Max;
        }
    }
    else if (SW !=NULL){
        SW_Max = SW->findMax(attr);
        if(SW_Max > Max){
            Max = SW_Max;
        }
    }
    else if(SE != NULL){
        SE_Max = SE->findMax(attr);
        if(SE_Max > Max){
            Max = SE_Max;
        }
    }
    return Max;
        //compare it with the 4 directions
        // using bottom to top approach
 
}

int quadTree::minTree(double x, double y, string direction, string attr){
    if(root == NULL){
        return 0;
    }
    else{
        return root->findMinNode(x,y,direction,attr);
    }
}

int quadTreeNode::findMinNode(double x, double y, string direction, string attr){
    if((x == latitude) && (y == longitude)){
        if(direction == "NE"){
            if(NE == NULL){
                return 0;
            }
            return NE->findMin(attr);
        }
        else if(direction == "NW"){
            if(NW == NULL){
                return 0;
            }
            return NW->findMin(attr);
        }
        else if(direction == "SW"){
            if(SW == NULL){
                return 0;
            }
            return SW->findMin(attr);
        }
        else if(direction == "SE"){
            if(SE == NULL){
                return 0;
            }
            return SE->findMin(attr);
        }
    }
    else if( (x >= latitude) && (y > longitude) ){
            if(NE == NULL){
                return 0;
            }
            else{
                return NE->findMinNode(x,y,direction,attr); 
            }
        
        }
        // north west
        else if( (x < latitude) && (y >= longitude) ){
            if(NW == NULL){
                return 0;
            }
            else{
                return NW->findMinNode(x,y,direction,attr);
            }
        }

        // south west
        else if( (x <= latitude) && (y < longitude) ){
            if(SW == NULL){
                return 0;
            }
            else{
                return SW->findMinNode(x,y,direction,attr);
            }
        }

        // south east
        else if( (x > latitude) && (y <= longitude) ){
            if(SE == NULL){
                return 0;
            }
            else{
                return SE->findMinNode(x,y,direction,attr);
            }
        }
        return 0;
}

int quadTreeNode::findMin(string attr){
    int Min = 0;
    int NE_Min = 0; //do this for all directions ;
    int NW_Min = 0;
    int SW_Min = 0;
    int SE_Min = 0;


    if(attr == "p"){
        
         Min = population;
        }
    else if(attr == "r"){
        Min = cost;
    }
    else if(attr == "s"){
        Min = salary;
    }
        //do for all the other 3 directions

    if (NE!=NULL){            
        NE_Min = NE->findMax(attr);
        if(NE_Min < Min){
            Min = NE_Min;
        }
    } 
    else if(NW != NULL){
        NW_Min = NW->findMax(attr);
        if(NW_Min < Min){
            Min = NW_Min;
        }
    }
    else if (SW !=NULL){
        SW_Min = SW->findMax(attr);
        if(SW_Min < Min){
            Min = SW_Min;
        }
    }
    else if(SE != NULL){
        SE_Min = SE->findMax(attr);
        if(SE_Min < Min){
            Min = SE_Min;
        }
    }
    return Min;
}

int quadTree::totalTree(double x, double y, string direction, string attr){
    if(root == NULL){
        return 0;
    }
    else{
        return root->findTotalNode(x,y,direction,attr);
    }
}

int quadTreeNode::findTotalNode(double x, double y, string direction, string attr){
    if((x == latitude) && (y == longitude)){
        if(direction == "NE"){
            if(NE == NULL){
                return 0;
            }
            return NE->findTotal(attr);
        }
        else if(direction == "NW"){
            if(NW == NULL){
                return 0;
            }
            return NW->findTotal(attr);
        }
        else if(direction == "SW"){
            if(SW == NULL){
                return 0;
            }
            return SW->findTotal(attr);
        }
        else if(direction == "SE"){
            if(SE == NULL){
                return 0;
            }
            return SE->findTotal(attr);
        }
    }
    else if( (x >= latitude) && (y > longitude) ){
            if(NE == NULL){
                return 0;
            }
            else{
                return NE->findTotalNode(x,y,direction,attr); 
            }
        
        }
        // north west
        else if( (x < latitude) && (y >= longitude) ){
            if(NW == NULL){
                return 0;
            }
            else{
                return NW->findTotalNode(x,y,direction,attr);
            }
        }

        // south west
        else if( (x <= latitude) && (y < longitude) ){
            if(SW == NULL){
                return 0;
            }
            else{
                return SW->findTotalNode(x,y,direction,attr);
            }
        }

        // south east
        else if( (x > latitude) && (y <= longitude) ){
            if(SE == NULL){
                return 0;
            }
            else{
                return SE->findTotalNode(x,y,direction,attr);
            }
        }
        return 0;
}

int quadTreeNode::findTotal(string attr){
    int sum = 0;
    int NE_sum = 0;
    int NW_sum = 0;
    int SW_sum = 0;
    int SE_sum = 0;

    if(attr == "p"){
        sum = population;
    }
    else if(attr == "r"){
        sum = cost;
    }
    else if(attr == "s"){
        sum = salary;
    }
    if(NE != NULL){
        sum = sum + NE->findTotal(attr);
    }
    if(NW != NULL){
        sum = sum + NW->findTotal(attr); 
    }
    if(SW != NULL){
        sum = sum + SW->findTotal(attr);
    }
    if(SE != NULL){
        sum = sum + SE->findTotal(attr);
    }
    return sum;
}



void quadTree::clear(){
    if(counter == 1){
        root = NULL;
        counter= counter-1;
    }
    if(counter == 0){
        root = NULL;
		cout<<"success"<<endl;
    }
    else{
        root->clearNode();
        root = NULL;
	cout<<"success"<<endl;		
    }
}

void quadTreeNode::clearNode(){
    if(NE != NULL){
        NE->clearNode();
        delete NE;
        }
        if(NW != NULL){
        NW->clearNode();
        delete NW;
        }
        if(SW != NULL){
        SW->clearNode();
        delete SW;
        }
        if(SE != NULL){
        SE->clearNode();
        delete SE;
        }
        counter = counter-1;
}