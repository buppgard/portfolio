// COP3530 - Data Structures and Algorithms - University of Florida - Fall 2023
// Project 02 - Simplified Page Rank - Benjamin Uppgard - 11/12/2023

#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class AdjList {
    struct Vertex {
        string _name;
        float _rank;
        int _index;

        Vertex(string name, int index) : _name(name), _index(index), _rank(0) {}
    };
    vector<unordered_set<Vertex*>> _graph;
    unordered_map<string, Vertex*> _vertexMap;
    int _numVertices;
    int _numEdges;



public:
    AdjList();
    ~AdjList();
    void InsertEdge(string from, string to);
    map<string, float> PageRank(int powerIterations);
    void PrintPageRank(int powerIterations);

    // Testing Functions
    void PrintList();
    int GetVertexMapSize();
    int GetGraphSize();
    int GetNumGraphElements();
    int GetNumVertices();
    int GetNumEdges();

private:
    bool AddToVertexMap(string vertexName);

};