#include "LinkedList_Problems.h"

LinkedListProblems::LinkedListProblems() {};

/*  Problem Source: Cracking the Coding Interview - 2.1 Remove Dups

    Problem Description: Write code to remove duplicates from an unsorted linked list
                         FOLLOW UP: How would you solve this problem if a temporary buffer
                                    is not allowed?

    Approach 1: With buffer (unordered_set)
        1)  create set to keep track of observed nodes
        
        2)  create previous node and set equal to null
        
        3)  start with given current root and iterate through each node w/ while loop
        
        4)  if node value is in set already -> set previous.next to current.next

        5)  otherwise -> set previous to current node, update current node to next node
                
             Time Complexity:    O(N)
             Space Complexity:   O(N)
 
    Approach 2: Without buffer
                
*/

// 1 -> 2 -> 3 -> 2 -> 1 -> 4
// ^    ^    ^    ^    ^    ^
// pc   pc   pc   c    c    pc

// Solution with buffer
void LinkedListProblems::removeDups(Node* root)
{
    std::unordered_set<int> nodeSet;
    Node* prev = nullptr;
    Node* currNode = root;
    
    while (currNode)
    {
        if (nodeSet.find(root->data) != nodeSet.end() && nodeSet.count(root->data) > 0)
        {
            prev->next = currNode->next;
        }
        else
        {
            prev = currNode;
            nodeSet.insert(currNode->data);
        }
        
        currNode = currNode->next;
    }
}

// Solution without buffer
//void LinkedListProblems::removeDups(Node* root)
//{
//
//}


/*  Problem Source: Cracking the Coding Interview - 2.2 Return Kth to Last

    Problem Description: Implement an algorithm to find the kth to last element of a 
                         singly linked list

    Approach 1: Recursive
        1)  create a helper function to recursively call headNode.next until null(end) is reached

        2)  use counter as an input and when terminating condition is reached -> 
            increase counter at each frame as it unwinds

        3)  if counter = K then current node is the Kth from last -> return

        Time Complexity:    O(N)
        Space Complexity:   O(N)
 
    Approach 2: Iterative
        1)  create 2 pointers (p1, p2) starting at head/root

        2)  increase p2 until it is K away from p1

        3)  move p1 and p2 simultaneously until p2 reaches end of list

        4)  if p2 = null, return p1 as it is K nodes from end
 
     
        Time Complexity:    O(N)
        Space Complexity:   O(1)
*/

// recursive solution
Node* returnKthToLast(Node* currNode, int K, int count)
{

}

Node* LinkedListProblems::returnKthToLast(Node* root)
{
    return returnKthToLast(root, )   
}


/*  Problem Source: Cracking the Coding Interview - 2.3 Delete Middle Node

    Problem Description: Implement an algorithm to delete a node in the middle.
                         (i.e. any node but the first and last node, not necessarily the exacty middle)
                         of a singly linked list, given only access to that node.
    
    EXAMPLE:
        Input: the node c from the linked list a -> b -> c -> d -> e -> f
        Output: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

    Approach 1:
        1)
 
     
        Time Complexity:    O()
        Space Complexity:   O()
*/

void LinkedListProblems::deleteMiddleNode(Node *root)
{
    
}


/*  Problem Source: Cracking the Coding Interview - 2.4 Partition

    Problem Description: Write code to partition a linked list around a value X, such that all nodes
                         less than X come before all nodes greater than or equal to X. If X is contained
                         within the list, the values of X only need to be after the elements less than X
                         (see below). The partition element X can appear anywhere in the "right partition"
                         it does not need to appear between the left and right partitions.
    
    EXAMPLE:
        Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 (partition = 5)
        Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

    Approach:
        1)
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

void LinkedListProblems::partition(Node* root, int X)
{
    
}


/*  Problem Source: Cracking the Coding Interview - 2.5 Sum Lists

    Problem Description: You have two numbers represented by linked lists, where each node contains a
                         single digit. The digits are stored in reverse order, such that the 1's digit
                         is at the head of the list. Write a function that adds the two numbers and
                         returns the suj as a linked list.
    
    EXAMPLE:
        Input: (7 -> 1 -> 6) + (5 -> 9 -> 2) That is, 617 + 295
        Output: 2 -> 1 -> 9 That is, 912

    Approach:
        1)
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

Node* LinkedListProblems::sumLists(Node *root1, Node *root2)
{
    return nullptr;
}


/*  Problem Source: Cracking the Coding Interview - 2.6 Palindrome

    Problem Description: Implement a function to check if a linked list is a palindome

    Approach:
        1)
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

bool LinkedListProblems::palindrome(Node *root)
{
    return true;
}


/*  Problem Source: Cracking the Coding Interview - 2.7 Intersection

    Problem Description: Given two singly linked lists, determine if the two lists intersect. Return the
                         intersecting node. Note that the intersection is defined based on reference, not
                         value. That is, if the kth node of the first linked list is the exact same node
                         (by reference) as the jth node of the second linked list, then they are
                         intersecting.

    Approach:
        1)
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

bool LinkedListProblems::intersection(Node* root1, Node* root2)
{
    return true;
}


/*  Problem Source: Cracking the Coding Interview - 2.8 Loop Detection
 
    Problem Description: Given a circular linked list, implement an algorithm that returns the node at the
                         beginning of the loop.
 
    DEFINITION: A circular linked list is a (corrupt) linked list in which a node's next pointer points to
                an earlier node, so as to make a loop in the linked list.
    
    EXAMPLE:
        Input: A -> B -> C -> D -> E -> C (the same C as earlier)
        Output: C

    Approach:
        1)
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

Node* LinkedListProblems::loopDetection(Node *root)
{
    return nullptr;
}
