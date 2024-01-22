#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:

    struct Node {
        T _data;
        Node* _nextNode;
        Node* _previousNode;

    };

    /*---Constructors---*/
    LinkedList();

    /*---Destructor---*/
    ~LinkedList();

    /*---Mutators---*/
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int numElements);
    void AddNodesTail(const T* data, unsigned int numElements);

    /*---Accessors---*/
    unsigned int NodeCount();
    void PrintForward();
    void PrintReverse();

private:
    Node* _headNode;
    Node* _tailNode;
    unsigned int _listSize;

};

/*-----Function Definitions-----*/

template <typename T>
LinkedList<T>::LinkedList() {
    _listSize = 0;
    _headNode = nullptr;
    _tailNode = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* currentNode = _headNode;
    Node* nextNode;
    for (unsigned int i = 0; i < _listSize; i++) {
        nextNode = currentNode->_nextNode;
        delete currentNode;
        currentNode = nextNode;
    }
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
    // Create a new node in dynamic memory
    LinkedList<T>::Node* newNode = new Node;
    // Store the data
    newNode->_data = data;
    // Set _previousNode to nullptr
    newNode->_previousNode = nullptr;
    // Set _nextNode to the address of the original head node
    newNode->_nextNode = _headNode;
    // If there is an existing head node...
    if (_listSize > 0) {
        // Set the original head node's _previousNode pointer to the new head node
        _headNode->_previousNode = newNode;
    }
    // Set the new nodes address to the head node
   _headNode = newNode;
    // Iterate the list size
   _listSize ++;
   // Set _tailNode if needed
   if (_listSize == 1)
       _tailNode = _headNode;
   if (_listSize == 2)
       _tailNode = _headNode->_nextNode;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int numElements) {
    for (unsigned int i = numElements; i > 0; i--) {
        AddHead(data[i -1]);
    }
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int numElements) {
    for (unsigned int i = 0; i < numElements; i++) {
        AddTail(data[i]);
    }
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
    // Create a new node in dynamic memory
    LinkedList<T>::Node* newNode = new Node;
    // Store the data
    newNode->_data = data;
    // Set _nextNode to nullptr
    newNode->_nextNode = nullptr;
    // Set _nextNode to the address of the original head node
    newNode->_previousNode = _tailNode;
    // If there is an existing tail node...
    if (_listSize > 0) {
        // Set the original tail node's _nextNode pointer to the new tail node
        _tailNode->_nextNode = newNode;
    }
    // Set the new nodes address to the tail node
    _tailNode = newNode;
    // Iterate the list size
    _listSize ++;
    // Set _headNode if needed
    if (_listSize == 1)
        _headNode = _tailNode;
    if (_listSize == 2)
        _headNode = _tailNode->_previousNode;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() {
    return _listSize;
}

template <typename T>
void LinkedList<T>::PrintForward() {
    Node* printNode = _headNode;
    for (unsigned int i = 0; i < _listSize; i++) {
        cout << printNode->_data << endl;
        printNode = printNode->_nextNode;
    }
}

template <typename T>
void LinkedList<T>::PrintReverse() {
    Node* printNode = _tailNode;
    for (unsigned int i = 0; i < _listSize; i++) {
        cout << printNode->_data << endl;
        printNode = printNode->_previousNode;
    }
}