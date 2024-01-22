// COP3530 - Data Structures and Algorithms - University of Florida - Fall 2023
// Project 02 - Simplified Page Rank - Benjamin Uppgard - 11/12/2023

#include "AdjList.h"
#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

//*** Public Functions ***//

// Constructor - Destructor
AdjList::AdjList() {
    _numVertices = 0;
    _numEdges = 0;
}

AdjList::~AdjList() {
    for(auto iter = _vertexMap.begin(); iter != _vertexMap.end(); ++iter) {
        delete iter->second;
    }
}

// Adjacency List Functions

void AdjList::InsertEdge(string from, string to) {
    // Add new vertices to the vertex map if needed
    AddToVertexMap(from);
    AddToVertexMap(to);
    // If the link doesn't already exist, add it to the list
    if (_graph[_vertexMap[to]->_index].find(_vertexMap[from]) == _graph[_vertexMap[to]->_index].end()) {
        _vertexMap[from]->_rank++;
        _graph[_vertexMap[to]->_index].insert(_vertexMap[from]);
        _numEdges++;
    }
}

map<string, float> AdjList::PageRank(int powerIterations) {
    // Calculate the current rank of each website
    unordered_map<string, float> currentRanks;
    for (auto i : _vertexMap) {
        currentRanks[i.first] = static_cast<float>(1) / _numVertices;
    }
    // Perform the desired number of power iterations
    for (int i = 1; i < powerIterations; i++) {
        unordered_map<string, float> newRanks;
        for (auto j : currentRanks) {
            float rowSum = 0;
            for (auto k : _graph[_vertexMap[j.first]->_index]) {
                rowSum += (static_cast<float>(1) / k->_rank * currentRanks[k->_name]);
            }
            newRanks[j.first] = rowSum;
        }
        currentRanks = newRanks;
    }
    // Sort the results by name
    map<string, float> sortedRanks;
    for (auto i : currentRanks)
        sortedRanks[i.first] = i.second;
    return sortedRanks;
}

void AdjList::PrintPageRank(int powerIterations) {
    map<string, float> pageRanks = PageRank(powerIterations);
    for (auto i : pageRanks)
        cout << i.first << " " << fixed << setprecision(2) << i.second << endl;
}


//**** Testing Functions ****//

void AdjList::PrintList() {
    for (auto i : _vertexMap) {
        cout << i.first << " linked from: ";
        for (auto j: _graph[i.second->_index]) {
            cout << " ";
            cout << j->_name << "(" << j->_rank << ")";
        }
        cout << endl;
    }
}

int AdjList::GetVertexMapSize() {
    return _vertexMap.size();
}

int AdjList::GetGraphSize() {
    return _graph.size();
}

int AdjList::GetNumGraphElements() {
    int numElements = 0;
    for (auto i : _graph) {
        numElements += i.size();
    }
    return numElements;
}

int AdjList::GetNumVertices() {
    return _numVertices;
}

int AdjList::GetNumEdges() {
    return _numEdges;
}


//**** Private Functions ****//

bool AdjList::AddToVertexMap(string vertexName) {
    if (_vertexMap.find(vertexName) == _vertexMap.end()) {
        _vertexMap[vertexName] = new Vertex(vertexName, _numVertices);
        _numVertices++;
        _graph.resize(_numVertices);
        return true;
    }
    else
        return false;
}
