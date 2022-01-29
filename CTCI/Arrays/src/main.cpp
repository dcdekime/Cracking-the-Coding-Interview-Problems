#include <iostream>
#include "ArrayProblems.h"


void run_isUnique_tests(const ArrayProblems& arrayObj)
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

void run_checkPermutation_tests(const ArrayProblems& arrayObj)
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

void run_URLify_tests(const ArrayProblems& arrayObj)
{
  std::string inputStr = "Mr John Smith    ";
  int trueLength = 13;

  std::cout << "Original String: " << inputStr << std::endl;
  std::cout << std::endl;

  arrayObj.URLify(inputStr, trueLength);
  std::cout << "URLified String: " << inputStr << std::endl;
}

void run_PalindromePermutation_tests(const ArrayProblems& arrayObj)
{
  std::string inputStr = "Tact Coa";
  std::cout << "PalindromePermutation returned: " << arrayObj.palindromePermutation(inputStr) ? "True" : "False" << std::endl;
}


int main()
{
    const ArrayProblems arrayProblemsObj;
    
    // run array tests
    run_isUnique_tests(arrayProblemsObj);
    
    run_checkPermutation_tests(arrayProblemsObj);
    
    run_URLify_tests(arrayProblemsObj);
    
    run_PalindromePermutation_tests(arrayProblemsObj);
    
    return 0;
}
