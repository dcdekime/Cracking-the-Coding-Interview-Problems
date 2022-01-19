#include <iostream>
#include "ArrayProblems.h"


void run_isUnique_tests(ArrayProblems& arrayObj)
{
    
    // test case 1
    std::string testString1 = "abcdefghijkl";
    // test case 2
    std::string testString2 = "potato";


    std::string test1 = arrayObj.isUnique(testString1) ? "Passed" : "Failed";
    std::string test2 = arrayObj.isUnique(testString2) ? "Failed" : "Passed";

    std::cout << "IsUnique test case 1:  " << test1 << std::endl;
    std::cout << "IsUnique test case 2:  " << test2 << std::endl;
    std::cout << std::endl;
}

void run_checkPermutation_tests(ArrayProblems& arrayObj)
{
    // test case 1
    std::string testString1 = "potato";
    std::string testString2 = "ptoaot";
    
    // test case 2
    std::string testString3 = "potato";
    std::string testString4 = "carrot";


    std::string test1 = arrayObj.checkPermutation(testString1, testString2) ? "Passed" : "Failed";
    std::string test2 = arrayObj.checkPermutation(testString3, testString4) ? "Failed" : "Passed";

    std::cout << "checkPermutation test case 1:  " << test1 << std::endl;
    std::cout << "checkPermutation test case 2:  " << test2 << std::endl;
    std::cout << std::endl;
    
}

void run_URLify_tests(ArrayProblems& arrayObj)
{
    
}


int main()
{
    ArrayProblems arrayProblemsObj;
    
    // run array tests
    run_isUnique_tests(arrayProblemsObj);
    
    run_checkPermutation_tests(arrayProblemsObj);
    
    run_URLify_tests(arrayProblemsObj);
    

    return 0;
}
