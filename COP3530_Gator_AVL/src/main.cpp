/*---COP 3530 Project 1: Gator AVL---
 * Author: Benjamin Uppgard
 * Date: 09/29/2023
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include "GatorAVL.h"

using namespace std;

bool isAlphaString(string& s);
bool isNumericString(string& s);

int main() {

    GatorAVL data;

    string input;
    getline(cin, input);
    int numCommands = stoi(input);

    while (numCommands > 0) {
        getline(cin, input);
        numCommands--;
        std::stringstream inputStream(input);
        string command;
        getline(inputStream, command, ' ');

        if(command == "insert") {
            string name, ID;
            getline(inputStream, name, '"');
            getline(inputStream, name, '"');
            getline(inputStream >> ws, ID);

            if(!isAlphaString(name) ||
               ID.size() != 8 ||
               !isNumericString(ID) ||
               !data.InsertStudent(stoi(ID), name)) {
                cout << "unsuccessful" << endl;
            }
            else
                cout << "successful" << endl;
        }

        else if(command == "remove") {
            string ID;
            getline(inputStream, ID);
            if(ID.size() != 8 ||
               !isNumericString(ID) ||
               !data.Remove(stoi(ID))) {
                cout << "unsuccessful" << endl;
            }
            else
                cout << "successful" << endl;
        }

        else if(command == "search") {
            string nameOrID;
            getline(inputStream, nameOrID);
            if(isNumericString(nameOrID)) {
                if (nameOrID.size() != 8 ||
                    !data.SearchID(stoi(nameOrID))) {
                    cout << "unsuccessful" << endl;
                }
            }
            else {
                string name = "";
                for(unsigned int i = 0; i < nameOrID.length(); i++) {
                    if(nameOrID[i] != '"')
                        name.push_back(nameOrID[i]);
                }
                if (!data.SearchName(name))
                    cout << "unsuccessful" << endl;
            }
        }

        else if(command == "printInorder")
            data.PrintInOrder();

        else if(command == "printPreorder")
            data.PrintPreOrder();

        else if(command == "printPostorder")
            data.PrintPostOrder();

        else if(command == "printLevelCount")
            data.PrintLevelCount();

        else if(command == "removeInorder") {
            string index;
            getline(inputStream, index);
            if(index.size() < 1 ||
               !isNumericString(index) ||
               !(stoi(index) >= 0) ||
               !data.RemoveInOrder(stoi(index))) {
                cout << "unsuccessful" << endl;
            }
            else
                cout << "successful" << endl;
        }

        else
            cout << "unsuccessful" << endl;
    }
    return 0;
}

bool isAlphaString(string& s) {
    for(char c : s) {
        if(!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

bool isNumericString(string& s) {
    for(char c : s) {
        if(!isdigit(c))
            return false;
    }
    return true;
}


