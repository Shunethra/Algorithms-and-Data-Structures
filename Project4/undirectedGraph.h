#include<iostream>
#include<string>
#include<regex>
#include<iterator>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

// for .h file

struct adjacencyNode{
    string adjacencyName;
    double distance; 
    string parent; 
    double shortestDist; 
    bool minExtracted;
    adjacencyNode* next;

    adjacencyNode();

};

struct Node{
    string name;
    string parentNode;
    int degree;
    double shortestDistNode;
    bool minExtractedNode;
    
    adjacencyNode* adjacencyHead;
    Node* next;
    //minHeap Q;

    
    Node();
    int adjacencysetd(string city, double d);
    double adjacencyDistance(string city);
    void clearNode();
    int sourceDist(string city);
    int extractShortestDist(string city);
};

class graph{
    Node* graphHead;
    int nodesNo;
    int edgeNo;
    int length; 

    string* pathArray;

    public:
    graph();
    //~graph();
    int insertNode(string city);
    void relaxNode(string Vertex_name, double u);
    int setd(string city1, string city2, double d);
    string search(string city);
    double findDistance(string city1, string city2);
    int findDegree(string city);
    int graph_nodes();
    int graph_edges();
    void clear();
    double findShortDist(string city1,string city2);
    //void relaxGraph();
    double extractMinimum();
    void Update_Verticies(string city_name, double shortest_distance, string parent_name);
    int printPath(string city1, string city2);
    void findParent(string city1, string city2);
};