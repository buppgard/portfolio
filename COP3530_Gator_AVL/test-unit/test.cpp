/*---COP 3530 Project 1: Gator AVL---
 * Author: Benjamin Uppgard
 * Date: 09/29/2023
 *
 */

//#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/GatorAVL.h"
#include <sstream>
#include <ostream>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("BST Insert", "[flag]"){

		GatorAVL tree;   // Create a Tree object
        string name = "Bob";
		tree.InsertStudent(3, name);
		tree.InsertStudent(2, name);
		tree.InsertStudent(1, name);
		std::vector<unsigned int> actualOutput = tree.InOrder();
		std::vector<unsigned int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);

	REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 1", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(1);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 2", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(3);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 3", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(11);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 4", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(13);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 5", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(2);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 6", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(6);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 7", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(10);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 8", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(4);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 9", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(12);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("BST Remove Case 10", "[flag]"){

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    data.Remove(8);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("Print Inorder", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);

    ostringstream oss;
    streambuf* p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintInOrder();

    cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "One, Two, Three, Four, Five, Six, Seven\n");
}

TEST_CASE("Print Preorder", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintPreOrder();

    cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "Four, Two, One, Three, Six, Five, Seven\n");
}

TEST_CASE("Print Postorder", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintPostOrder();

    cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "One, Three, Two, Five, Seven, Six, Four\n");
}

TEST_CASE("Search ID Success", "[flag]") {

GatorAVL data;

string name1 = "One";
string name2 = "Two";
string name3 = "Three";
string name4 = "Four";
string name5 = "Five";
string name6 = "Six";
string name7 = "Seven";
string name8 = "Eight";
string name9 = "Nine";
string name10 = "Ten";
string name11 = "Eleven";
string name12 = "Twelve";
string name13 = "Thirteen";
string name14 = "Fourteen";
string name15 = "Fifteen";
string name16 = "Sixteen";

data.InsertStudent(1, name1);
data.InsertStudent(2, name2);
data.InsertStudent(3, name3);
data.InsertStudent(4, name4);
data.InsertStudent(5, name5);
data.InsertStudent(6, name6);
data.InsertStudent(7, name7);

ostringstream oss;
streambuf *p_cout_streambuf = std::cout.rdbuf();
cout.rdbuf(oss.rdbuf());

REQUIRE(data.SearchID(4) == 1);

cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
REQUIRE(oss.str() == "Four\n");
}

TEST_CASE("Search ID Fail", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    REQUIRE(data.SearchID(21) == 0);

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "");
}

TEST_CASE("Search Name Success 1", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    REQUIRE(data.SearchName(name3) == 1);

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "00000003\n");
}

TEST_CASE("Search Name Success 2", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(12345678, name1);
    data.InsertStudent(23456781, name2);
    data.InsertStudent(34567812, name3);
    data.InsertStudent(45678123, name4);
    data.InsertStudent(56781234, name5);
    data.InsertStudent(67812345, name6);
    data.InsertStudent(78123456, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    REQUIRE(data.SearchName(name7) == 1);

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "78123456\n");
}

TEST_CASE("Search Name Fail", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(12345678, name1);
    data.InsertStudent(23456781, name2);
    data.InsertStudent(34567812, name3);
    data.InsertStudent(45678123, name4);
    data.InsertStudent(56781234, name5);
    data.InsertStudent(67812345, name6);
    data.InsertStudent(78123456, name7);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    REQUIRE(data.SearchName(name16) == 0);

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "");
}

TEST_CASE("Print Level Count - Empty", "[flag]") {

    GatorAVL data;

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintLevelCount();

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "0\n");
}

TEST_CASE("Print Level Count 1", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(12345678, name1);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintLevelCount();

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "1\n");
}

TEST_CASE("Print Level Count 5", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintLevelCount();

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "5\n");
}

TEST_CASE("Print Level Count 4", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    //data.InsertStudent(16, name16);

    ostringstream oss;
    streambuf *p_cout_streambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    data.PrintLevelCount();

    cout.rdbuf(p_cout_streambuf); // restore

// test your oss content...
    REQUIRE(oss.str() == "4\n");
}

TEST_CASE("Remove Inorder - First Success", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    REQUIRE(data.RemoveInOrder(0) == 1);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("Remove Inorder - Last Success", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    REQUIRE(data.RemoveInOrder(15) == 1);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("Remove Inorder - Fail", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);
    data.InsertStudent(4, name4);
    data.InsertStudent(5, name5);
    data.InsertStudent(6, name6);
    data.InsertStudent(7, name7);
    data.InsertStudent(8, name8);
    data.InsertStudent(9, name9);
    data.InsertStudent(10, name10);
    data.InsertStudent(11, name11);
    data.InsertStudent(12, name12);
    data.InsertStudent(13, name13);
    data.InsertStudent(14, name14);
    data.InsertStudent(15, name15);
    data.InsertStudent(16, name16);

    REQUIRE(data.RemoveInOrder(16) == 0);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("Insert Remove Insert", "[flag]") {

    GatorAVL data;

    string name1 = "One";
    string name2 = "Two";
    string name3 = "Three";
    string name4 = "Four";
    string name5 = "Five";
    string name6 = "Six";
    string name7 = "Seven";
    string name8 = "Eight";
    string name9 = "Nine";
    string name10 = "Ten";
    string name11 = "Eleven";
    string name12 = "Twelve";
    string name13 = "Thirteen";
    string name14 = "Fourteen";
    string name15 = "Fifteen";
    string name16 = "Sixteen";

    data.InsertStudent(1, name1);
    data.InsertStudent(2, name2);
    data.InsertStudent(3, name3);

    std::vector<unsigned int> actualOutput = data.InOrder();
    std::vector<unsigned int> expectedOutput = {1, 2, 3};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);


    data.Remove(3);

    actualOutput = data.InOrder();
    expectedOutput = {1, 2};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);

    data.InsertStudent(4, name4);

    actualOutput = data.InOrder();
    expectedOutput = {1, 2, 4};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(1 == 1);
}

TEST_CASE("Large Insert", "[flag]"){

    GatorAVL tree;   // Create a Tree object
    string name = "Bob";

    for(unsigned int i = 0; i < 10000; i++) {
        tree.InsertStudent(i, name);
    }
    vector<unsigned int> expectedOutput(10000);
    for(unsigned int i = 0; i < 10000; i++) {
        expectedOutput[i] = i;
    }

    std::vector<unsigned int> actualOutput = tree.InOrder();
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

