#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../AdjList.h"
#include <sstream>
#include <ostream>
#include <chrono>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("01: AdjList Insert", "[flag]"){

    // Basic test of InsertEdge() function
    // Create a test graph
    AdjList a;
    a.InsertEdge("Hello", "Josie");
    a.InsertEdge("Hello", "Julie");
    a.InsertEdge("Hello", "Candace");
    a.InsertEdge("Goodbye", "Josie");
    a.InsertEdge("Josie", "Meows");

    // Verify the data
	REQUIRE(a.GetVertexMapSize() == 6);
    REQUIRE(a.GetGraphSize() == 6);
    REQUIRE(a.GetNumGraphElements() == 5);
    REQUIRE(a.GetNumVertices() == a.GetVertexMapSize());
    REQUIRE(a.GetNumEdges() == a.GetNumGraphElements());
}

TEST_CASE("02: Print Page Rank", "[flag]"){

    // Basic test of PrintPageRank() function
    // Create a test graph
    AdjList a;
    a.InsertEdge("google.com", "gmail.com");
    a.InsertEdge("google.com", "maps.com");
    a.InsertEdge("facebook.com", "ufl.edu");
    a.InsertEdge("ufl.edu", "google.com");
    a.InsertEdge("ufl.edu", "gmail.com");
    a.InsertEdge("maps.com", "facebook.com");
    a.InsertEdge("gmail.com", "maps.com");

    // Visual check of the graph
    cout << "02: Print Page Rank" << endl;
    cout << "-------------------" << endl;
    cout << "Visual Representation of Graph: " << endl;
    a.PrintList();
    cout << endl;

    // Check the PageRank() function calculations
    map<string, float> pageRanks = a.PageRank(2);

    // Check the terminal output
    ostringstream oss;
    streambuf* p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());
    a.PrintPageRank(2);
    cout.rdbuf(p_cout_streambuf);

    // Visual check
    cout << "Page Ranks:" << endl;
    a.PrintPageRank(2);
    cout << endl;

    // Verify the terminal output
    REQUIRE(oss.str() == "facebook.com 0.20\n"
                         "gmail.com 0.20\n"
                         "google.com 0.10\n"
                         "maps.com 0.30\n"
                         "ufl.edu 0.20\n");

    // Verify the graph
    REQUIRE(a.GetVertexMapSize() == 5);
    REQUIRE(a.GetGraphSize() == 5);
    REQUIRE(a.GetNumGraphElements() == 7);
    REQUIRE(a.GetNumVertices() == a.GetVertexMapSize());
    REQUIRE(a.GetNumEdges() == a.GetNumGraphElements());
    // Verify the PageRank() calculations
    REQUIRE(pageRanks["facebook.com"] == 0.2f);
    REQUIRE(pageRanks["gmail.com"] == 0.2f);
    REQUIRE(pageRanks["google.com"] == 0.1f);
    REQUIRE(pageRanks["maps.com"] == 0.3f);
    REQUIRE(pageRanks["ufl.edu"] == 0.2f);
}

TEST_CASE("03: Stress Test (Sparse Graph)", "[flag]"){
    // Generate test website names
    int numSites = 10001;
    vector<string> siteNames;
    for(int i = 0; i < numSites; i++) {
        string name = "site" + to_string(i) + ".com";
        siteNames.push_back(name);
    }
    // Load the test sites into the adjacency matrix
    // Link each site to the site following site
    AdjList a;
    for(int i = 0; i < siteNames.size() -1; i++)
        a.InsertEdge(siteNames[i], siteNames[i +1]);

    // Verify the graph characteristics
    REQUIRE(a.GetVertexMapSize() == numSites);
    REQUIRE(a.GetGraphSize() == numSites);
    REQUIRE(a.GetNumGraphElements() == numSites - 1);
    REQUIRE(a.GetNumVertices() == a.GetVertexMapSize());
    REQUIRE(a.GetNumEdges() == a.GetNumGraphElements());

    // Run the data through 10 power iterations:
    map<string, float> pageRanks = a.PageRank(10);
    cout << "03: Stress Test (Sparse Graph)" << endl;
    cout << "------------------------------" << endl;
    cout << siteNames[203] << " " << pageRanks[siteNames[203]] << endl << endl;
}

TEST_CASE("04: Stress Test - Max Power Iterations", "[flag]"){

    // Create a test graph
    AdjList a;
    a.InsertEdge("google.com", "gmail.com");
    a.InsertEdge("google.com", "maps.com");
    a.InsertEdge("facebook.com", "ufl.edu");
    a.InsertEdge("ufl.edu", "google.com");
    a.InsertEdge("ufl.edu", "gmail.com");
    a.InsertEdge("maps.com", "facebook.com");
    a.InsertEdge("gmail.com", "maps.com");

    // Perform many power iterations
    cout << "04: Stress Test - Max Power Iterations" << endl;
    cout << "--------------------------------------" << endl;

    auto start = chrono::high_resolution_clock::now();

    a.PrintPageRank(10000);

    auto stop = chrono::high_resolution_clock ::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Calculation time (milliseconds): " << duration.count() << endl << endl;
}

TEST_CASE("05: Stress Test - Dense Graph", "[flag]"){

    // Generate 100 website names
    int numSites =  100;
    vector<string> siteNames;
    for(int i = 0; i < numSites; i++) {
        string name = "site" + to_string(i) + ".com";
        siteNames.push_back(name);
    }

    // Load the websites into the graph. Link each website to every other website
    AdjList a;
    for(auto i : siteNames) {
        for (auto j : siteNames)
            a.InsertEdge(i, j);
    }

    // Verify the data structure characteristics
    REQUIRE(a.GetVertexMapSize() == numSites);
    REQUIRE(a.GetGraphSize() == numSites);
    REQUIRE(a.GetNumGraphElements() == numSites * numSites);
    REQUIRE(a.GetNumVertices() == a.GetVertexMapSize());
    REQUIRE(a.GetNumEdges() == a.GetNumGraphElements());

    // Check PageRank() performance
    cout << "05: Stress Test - Dense Graph" << endl;
    cout << "-----------------------------" << endl;

    auto start = chrono::high_resolution_clock::now();

    map<string, float> pageRanks = a.PageRank(10);

    cout << siteNames[0] << " " << pageRanks[siteNames[0]] << endl;
    auto stop = chrono::high_resolution_clock ::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Calculation time (milliseconds): " << duration.count() << endl << endl;
}

TEST_CASE("06: Duplicate Inserts", "[flag]"){

    // Basic test of InsertEdge() function
    // Create a test graph
    AdjList a;
    a.InsertEdge("google.com", "gmail.com");
    a.InsertEdge("google.com", "gmail.com");
    a.InsertEdge("google.com", "maps.com");
    a.InsertEdge("gmail.com", "maps.com");
    a.InsertEdge("google.com", "gmail.com");


    // Verify the data
    REQUIRE(a.GetVertexMapSize() == 3);
    REQUIRE(a.GetGraphSize() == 3);
    REQUIRE(a.GetNumGraphElements() == 3);
    REQUIRE(a.GetNumVertices() == a.GetVertexMapSize());
    REQUIRE(a.GetNumEdges() == a.GetNumGraphElements());

    // Print the Ranks
    cout << "06: Duplicate Inserts" << endl;
    cout << "---------------------" << endl;
    a.PrintPageRank(2);
}



