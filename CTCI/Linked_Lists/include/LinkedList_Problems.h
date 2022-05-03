#ifndef LinkedList_Problems_h
#define LinkedList_Problems_h

#include <unordered_set>
#include <unordered_map>

struct Node
{
    // constructor
    Node(int d) : data(d) {};
    Node(int d, Node* n) : data(d), next(n) {};
    
    int data;
    Node* next = nullptr;
};

class LinkedListProblems
{
public:
    LinkedListProblems();
    
    void removeDups(Node* root);                    // CTCI Problem 2.1
    Node* returnKthToLast(Node* root);              // CTCI Problem 2.2
    bool deleteMiddleNode(Node* node);              // CTCI Problem 2.3
    Node* partition(Node* root, int X);              // CTCI Problem 2.4
    Node* sumLists(Node* root1, Node* root2);       // CTCI Problem 2.5
    bool palindrome(Node* root);                    // CTCI Problem 2.6
    bool intersection(Node* root1, Node* root2);    // CTCI Problem 2.7
    Node* loopDetection(Node* root);                // CTCI Problem 2.8
};

#endif /* LinkedList_Problems_h */
