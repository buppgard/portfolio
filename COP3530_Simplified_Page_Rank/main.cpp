// COP3530 - Data Structures and Algorithms - University of Florida - Fall 2023
// Project 02 - Simplified Page Rank - Benjamin Uppgard - 11/12/2023

#include <iostream>
#include <string>
#include "AdjList.h"
using namespace std;

int main() {
    AdjList linksGraph;
    int numInputs, powerIterations;
    string from, to;
    cin >> numInputs;
    cin >> powerIterations;
    for (int i = 0; i < numInputs; i++) {
        cin >> from;
        cin >> to;
        linksGraph.InsertEdge(from, to);
    }
    linksGraph.PrintPageRank(powerIterations);
}