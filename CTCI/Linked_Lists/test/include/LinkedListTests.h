#ifndef LinkedListTests_h
#define LinkedListTests_h

#include "LinkedList_Problems.h"

class LinkedListTests
{
public:
    void getInstance();
    void runUnitTests();
    
private:
    // member functions
    LinkedListTests();
    
    void run_removeDups_tests();
    
private:
    // member variables
    LinkedListProblems& mLinkedListProblemsObj;
    
}

#endif /* LinkedListTests_h */
