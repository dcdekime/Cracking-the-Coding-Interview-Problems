#ifndef ArrayTests_h
#define ArrayTests_h

#include "ArrayProblems.h"
#include <iostream>

class ArrayTests
{
public:
    static ArrayTests& getInstance();
    void runUnitTests();

private:
    // member functions
    ArrayTests();
    
    void run_isUnique_tests();
    void run_checkPermutation_tests();
    void run_URLify_tests();
    void run_PalindromePermutation_tests();
    void run_OneAway_tests();
    void run_StringCompression_tests();
    void run_RotateMatrix_tests();
    void run_ZeroMatrix_tests();
    void run_StringRotation_tests();
    
private:
    // member variables
    ArrayProblems& mArrayProblemsObj;
};

#endif /* ArrayTests_h */
