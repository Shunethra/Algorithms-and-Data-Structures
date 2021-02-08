#include<iostream>
#include<string>
#include <cwctype>

#include<fstream>

using namespace std;

int counter=0;

struct quadTreeNode{
    //friend class quadTree;
    string city;
    double latitude;
    double longitude;
    int population;
    int cost;
    int salary;
	
    //quadTreeNode* root;
    quadTreeNode* NE;
    quadTreeNode* NW;
    quadTreeNode* SW;
    quadTreeNode* SE;

	
	public:
    quadTreeNode();
    //~quadTreeNode();
    bool insertNode(string a, double x, double y, int pop, int cost, int sal);
    quadTreeNode* newNode(string a, double x, double y,int pop, int cost, int sal);
    void printNode();
    int searchNode(double x, double y);
    int findMaxNode(double x, double y, string direction, string attr);
    int findMax(string attr);
    int findMinNode(double x, double y, string direction, string attr);
    int findMin(string attr);
    int findTotalNode(double x, double y, string direction, string attr);
    int findTotal(string attr);
    void clearNode();
	//int counterNode();
};

class quadTree{
    quadTreeNode* root;
    int size;
	
	
	//private: 
	//int counter;
	
    public:
    quadTree();
    bool insertRoot(string a, double x, double y, int pop, int cost, int sal);
    quadTreeNode* newRoot(string a,double x, double y,int pop, int cost, int sal);   // create only one for the root
    void sizeTree();
    void printTree();
    int searchTree(double x, double y);
    int maxTree(double x, double y, string direction, string attr);
    int minTree(double x, double y, string direction, string attr);
    int totalTree(double x, double y, string direction, string attr);
    void clear();
	int treeSize();
	//int counter();
};