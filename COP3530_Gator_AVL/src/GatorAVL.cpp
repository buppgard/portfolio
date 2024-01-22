/*---COP 3530 Project 1: Gator AVL---
 * Author: Benjamin Uppgard
 * Date: 09/29/2023
 * Attributions: COP 3530 Lecture Videos - Amanpreet Kapoor - (InsertNode functions,
 *                                                             Node Removal functions)
 *      https://leetcode.com/prathams29/ - PrathamSingh     - (Remove in order funcitons)
 *
 */

#include "GatorAVL.h"
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

GatorAVL::GatorAVL() {
    _root = nullptr;
}

GatorAVL::~GatorAVL() {
    if (_root != nullptr) {
        //Level order iteration through tree using queue, deleting each node
        queue<StudentNode*> deletionQueue;
        deletionQueue.push(_root);
        while (!deletionQueue.empty()) {
            if (_root->_leftChild != nullptr)
                deletionQueue.push(_root->_leftChild);
            if (_root->_rightChild != nullptr)
                deletionQueue.push(_root->_rightChild);
            delete _root;
            deletionQueue.pop();
            _root = deletionQueue.front();
        }
    }
}

bool GatorAVL::InsertStudent(unsigned int studentID, string& studentName) {
    if(FindID(_root, studentID) != nullptr)
        return false;
    _root = InsertNode(_root, studentID, studentName);
    return true;
}

bool GatorAVL::Remove(unsigned int studentID) {
    StudentNode* removedNode = DeleteNode(_root, studentID);
    if(removedNode != nullptr) {
        return true;
    }
    return false;
}

void GatorAVL::PrintInOrder() {
    bool first = true;
    PrintNodesInOrder(_root, first);
    cout << endl;
}

void GatorAVL::PrintPostOrder() {
    bool first = true;
    PrintNodesPostOrder(_root, first);
    cout << endl;
}

void GatorAVL::PrintPreOrder() {
    bool first = true;
    PrintNodesPreOrder(_root, first);
    cout << endl;
}

void GatorAVL::PrintLevelCount() {
    cout << NodeHeight(_root) << endl;
}

bool GatorAVL::SearchID(unsigned int studentID) {
    StudentNode* targetStudent = FindID(_root, studentID);
    if(targetStudent != nullptr) {
        cout << FindID(_root, studentID)->_studentName << endl;
        return true;
    }
    else
        return false;
}

bool GatorAVL::SearchName(std::string studentName) {
    bool first = true;
    string results = "";
    FindName(_root, studentName, results, first);
    if(!results.empty()) {
        stringstream zeroPadder;
        zeroPadder << setw(8) << setfill('0') << results;
        results = zeroPadder.str();
        cout << results << endl;
        return true;
    }
    else
        return false;
}

bool GatorAVL::RemoveInOrder(unsigned int n) {
    n++;
    StudentNode* target = NthNode(_root, n);
    if(target != nullptr) {
        if(Remove(target->_studentID))
            return true;
    }
    return false;
}

vector<unsigned int> GatorAVL::InOrder() {
    vector<unsigned int> nodeList;
    InOrderHelper(_root, nodeList);
    return nodeList;
}


/*----PrivateFunctions----*/

//InsertStudent helper funciton
GatorAVL::StudentNode* GatorAVL::InsertNode(StudentNode* root, unsigned int studentID, string& studentName) {
    //Base case: insert the new student at the correct leaf location
    if(root == nullptr) {
        return new StudentNode(studentID, studentName);
    }
    //Insertion student ID is less than the current node. Go to the left
    if(studentID < root->_studentID) {
        root->_leftChild = InsertNode(root->_leftChild, studentID, studentName);
        UpdateBalanceFactor(root);
    }
    //Insertion student ID is greater than the current node. Go to the right
    else if (studentID > root->_studentID) {
        root->_rightChild = InsertNode(root->_rightChild, studentID, studentName);
        UpdateBalanceFactor(root);
    }
    //If balance factor is off, rebalance the tree
    if(root->_balanceFactor > 1)  {
        if (root->_leftChild->_balanceFactor > 0) {
            //Right Rotation
            root = RotateRight(root);
        }
        else if (root->_leftChild->_balanceFactor < 0) {
            //LeftRight Rotation
            root = RotateLeftRight(root);
        }
        UpdateBalanceFactor(root);
        UpdateBalanceFactor(root->_leftChild);
        UpdateBalanceFactor(root->_rightChild);
    }
    else if(root->_balanceFactor < -1) {
        if(root->_rightChild->_balanceFactor < 0) {
            //Left Rotation
            root = RotateLeft(root);
        }
        else if(root->_rightChild->_balanceFactor > 0) {
            //RightLeft Rotation
            root = RotateRightLeft(root);
        }
        UpdateBalanceFactor(root);
        UpdateBalanceFactor(root->_leftChild);
        UpdateBalanceFactor(root->_rightChild);
    }
    return root;
}

GatorAVL::StudentNode* GatorAVL::RotateRight(StudentNode* root) {
    StudentNode* leftChild = root->_leftChild;
    root->_leftChild = leftChild->_rightChild;
    leftChild->_rightChild = root;
    return leftChild;
}

GatorAVL::StudentNode* GatorAVL::RotateLeft(StudentNode* root) {
    StudentNode* rightChild = root->_rightChild;
    root->_rightChild = rightChild->_leftChild;
    rightChild->_leftChild = root;
    return rightChild;
}

GatorAVL::StudentNode* GatorAVL::RotateRightLeft(StudentNode* root) {
    root->_rightChild = RotateRight(root->_rightChild);
    return RotateLeft(root);
}

GatorAVL::StudentNode* GatorAVL::RotateLeftRight(StudentNode* root) {
    root->_leftChild = RotateLeft(root->_leftChild);
    return RotateRight(root);
}

//SearchID helper function
GatorAVL::StudentNode* GatorAVL::FindID(GatorAVL::StudentNode *root, unsigned int targetID) {
    //Base case: you've reached the bottom of a branch
    if(root == nullptr)
        return nullptr;
    //Base case" you've found the target ID
    if(root->_studentID == targetID)
        return root;
    //If the target ID is less than the root ID, go to the left
    else if (root->_studentID > targetID)
        root = FindID(root->_leftChild, targetID);
    //If the target ID is greater than the root ID, go to the right
    else if (root->_studentID < targetID)
        root = FindID(root->_rightChild, targetID);
    return root;
}

unsigned int GatorAVL::NodeHeight(GatorAVL::StudentNode *root) {
    if(root == nullptr)
        return 0;
return 1 + max(NodeHeight(root->_leftChild), NodeHeight(root->_rightChild));
}

void GatorAVL::UpdateBalanceFactor(GatorAVL::StudentNode *root) {
    root->_balanceFactor = NodeHeight(root->_leftChild) - NodeHeight(root->_rightChild);
}

//Remove helper function
GatorAVL::StudentNode* GatorAVL::DeleteNode(GatorAVL::StudentNode *root, unsigned int studentID, StudentNode* parent, bool direction) {
    if (root == nullptr)
        return nullptr;
    //Search left if needed
    if (root->_studentID > studentID) {
        StudentNode* deletedNode = DeleteNode(root->_leftChild, studentID, root, 0);
        UpdateBalanceFactor(root);
        return deletedNode;
    }
    //Search right if needed
    else if(root->_studentID < studentID) {
        StudentNode* deletedNode = DeleteNode(root->_rightChild, studentID, root, 1);
        UpdateBalanceFactor(root);
        return deletedNode;
    }
    //This is the node to be deleted
    else {
        //Condition 1: the node has no children:
        if(root->_leftChild == nullptr && root->_rightChild == nullptr) {
            //If the node is not root:
            if(parent != nullptr) {
                //If the parent is to the top right:
                if(direction == 0) {
                    parent->_leftChild = nullptr;
                }
                //If the parent is to the top left:
                else {
                    parent->_rightChild = nullptr;
                }
            }
            //If the node is root:
            else
                _root = nullptr;
            return root;
        }
        //Condition 2: the node has a right child only:
        else if(root->_leftChild == nullptr) {
            //if the node is not root:
            if(parent != nullptr) {
                if(direction == 0) {
                    parent->_leftChild = root->_rightChild;
                }
                else {
                    parent->_rightChild = root->_rightChild;
                }
            }
            //if the node is root:
            else {
                _root = root->_rightChild;
            }
            return root;
        }
        //Condition 3: the node has a left child only:
        else if(root->_rightChild == nullptr) {
            //If the node is not root:
            if(parent != nullptr) {
                if(direction == 0) {
                    parent->_leftChild = root->_leftChild;
                }
                else {
                    parent->_rightChild = root->_leftChild;
                }
            }
            //If the node is root:
            else {
                _root = root->_leftChild;
            }
            return root;
        }
        else {
            //Condition 4: The node has two children:
            //The parent is to the top right:
            if (direction == 0) {
                //If the right child is the successor:
                if (root->_rightChild->_leftChild == nullptr) {
                    //If not root:
                    if(parent != nullptr) {
                        parent->_leftChild = root->_rightChild;
                        parent->_leftChild->_leftChild = root->_leftChild;
                        UpdateBalanceFactor(parent->_leftChild);
                    }
                    else {
                        _root = root->_rightChild;
                        _root->_leftChild = root->_leftChild;
                        UpdateBalanceFactor(_root);
                    }
                }
                else {
                    //The successor is deeper down
                    StudentNode *leftMostNodeParent = root->_rightChild;
                    StudentNode *leftMostNode = leftMostNodeParent->_leftChild;
                    while (leftMostNode->_leftChild != nullptr) {
                        leftMostNodeParent = leftMostNode;
                        leftMostNode = leftMostNode->_leftChild;
                    }

                    root->_studentID = leftMostNode->_studentID;
                    root->_studentName = leftMostNode->_studentName;
                    delete leftMostNodeParent->_leftChild;
                    leftMostNodeParent->_leftChild = nullptr;
                    UpdateBalanceFactor(root);
                    UpdateBalanceFactor(root->_rightChild);
                }
            }
            //If the parent is to the top left
            if (direction == 1) {
                //If the right child is the successor
                if (root->_rightChild->_leftChild == nullptr) {
                    //If not root
                    if (parent != nullptr) {
                        parent->_rightChild = root->_rightChild;
                        parent->_rightChild->_leftChild = root->_leftChild;
                        UpdateBalanceFactor(parent->_rightChild);
                    } else {
                        _root = root->_rightChild;
                        _root->_leftChild = root->_leftChild;
                        UpdateBalanceFactor(_root);
                    }
                }
                else {
                    //The successor is deeper down
                    StudentNode *leftMostNodeParent = root->_rightChild;
                    StudentNode *leftMostNode = leftMostNodeParent->_leftChild;
                    while (leftMostNode->_leftChild != nullptr) {
                        leftMostNodeParent = leftMostNode;
                        leftMostNode = leftMostNode->_leftChild;
                    }

                    root->_studentID = leftMostNode->_studentID;
                    root->_studentName = leftMostNode->_studentName;
                    delete leftMostNodeParent->_leftChild;
                    leftMostNodeParent->_leftChild = nullptr;
                    UpdateBalanceFactor(root);
                    UpdateBalanceFactor(root->_rightChild);
                }
            }
            return root;
        }
    }
}

//PrintInOrder helper function
void GatorAVL::PrintNodesInOrder(GatorAVL::StudentNode *root, bool& first) {
    if(root == nullptr)
        return;
    PrintNodesInOrder(root->_leftChild, first);
    if(!first)
        cout << ", ";
    cout << root->_studentName;
    first = false;
    PrintNodesInOrder(root->_rightChild, first);
}

//PrintPostOrder helper function
void GatorAVL::PrintNodesPostOrder(GatorAVL::StudentNode *root, bool& first) {
    if(root == nullptr)
        return;
    PrintNodesPostOrder(root->_leftChild, first);
    PrintNodesPostOrder(root->_rightChild, first);
    if(!first)
        cout << ", ";
    cout << root->_studentName;
    first = false;
}

//PrintPreOrder helper function
void GatorAVL::PrintNodesPreOrder(GatorAVL::StudentNode *root, bool& first) {
    if(root == nullptr)
        return;
    if(!first)
        cout << ", ";
    cout << root->_studentName;
    first = false;
    PrintNodesPreOrder(root->_leftChild, first);
    PrintNodesPreOrder(root->_rightChild, first);
}

//RemoveInOrder helper function
GatorAVL::StudentNode* GatorAVL::NthNode(GatorAVL::StudentNode *root, unsigned int& n) {
    //Use a stack to iterate through the nodes in order
    stack<StudentNode*> nodeStack;
    //Base cases: if the stack is empty or you're at the end of the tree
    while(!nodeStack.empty() || root != nullptr) {
        //Push the node to the stack
        while(root != nullptr) {
            nodeStack.push(root);
            root = root->_leftChild;
        }
        //Pop the top stack element
        root = nodeStack.top();
        nodeStack.pop();
        //Decrement the counter
        n--;
        //If the counter is zero, return the node
        if (n == 0)
            break;
        root = root->_rightChild;
    }
    return root;
}

//SearchName helper function
void GatorAVL::FindName(GatorAVL::StudentNode *root, std::string &studentName, string& output, bool& first) {
    //Base case: the end of a branch
    if(root == nullptr)
        return;
    //If the name is found, push the ID to the output string
    if(root->_studentName == studentName) {
        if(!first)
            output.push_back('\n');
        output += to_string(root->_studentID);
        first = false;
    }
    //Search to the left
    FindName(root->_leftChild, studentName, output, first);
    //Keep going to the right
    FindName(root->_rightChild, studentName, output, first);
}

//Inorder traversal for testing
void GatorAVL::InOrderHelper(GatorAVL::StudentNode *root, vector<unsigned int> &output) {
    if(root == nullptr)
        return;
    InOrderHelper(root->_leftChild, output);
    output.push_back(root->_studentID);
    InOrderHelper(root->_rightChild, output);
}









