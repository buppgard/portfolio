/*---COP 3530 Project 1: Gator AVL---
 * Author: Benjamin Uppgard
 * Date: 09/29/2023
 *
 */

#pragma once

#include <string>
#include <vector>

using namespace std;

class GatorAVL {

    struct StudentNode {
        unsigned int _studentID;
        string _studentName;
        int _balanceFactor;
        StudentNode* _leftChild;
        StudentNode* _rightChild;

        StudentNode(unsigned int studentID, string studentName = "") {
            _studentID = studentID;
            _studentName = studentName;
            _leftChild = nullptr;
            _rightChild = nullptr;
        }
        StudentNode& operator=(const StudentNode& rhs) {
            _studentID = rhs._studentID;
            _studentName = rhs._studentName;
            return *this;
        }
    };

    StudentNode* _root;

public:

    GatorAVL();
    ~GatorAVL();
    bool InsertStudent(unsigned int studentID, string& studentName);
    bool Remove(unsigned int studentID);
    bool SearchID(unsigned int studentID);
    bool SearchName(string studentName);
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    void PrintLevelCount();
    bool RemoveInOrder(unsigned int n);
    vector <unsigned int> InOrder();

private:

    StudentNode* InsertNode(StudentNode* root, unsigned int studentID, string& studentName);
    StudentNode* FindID(StudentNode* root, unsigned int targetID);
    StudentNode* RotateRight(StudentNode* root);
    StudentNode* RotateLeft(StudentNode* root);
    StudentNode* RotateRightLeft(StudentNode* root);
    StudentNode* RotateLeftRight(StudentNode* root);
    unsigned int NodeHeight(StudentNode* root);
    void UpdateBalanceFactor(StudentNode* root);
    StudentNode* DeleteNode(StudentNode* root, unsigned int studentID,StudentNode* parent = nullptr, bool direction = 0);
    void PrintNodesInOrder(StudentNode* root, bool& first);
    void PrintNodesPostOrder(StudentNode* root, bool& first);
    void PrintNodesPreOrder(StudentNode* root, bool& first);
    StudentNode* NthNode(StudentNode* root, unsigned int& n);
    void FindName(StudentNode* root, string& studentName, string& output, bool& first);
    void InOrderHelper(StudentNode* root, vector<unsigned int>& output);
};

