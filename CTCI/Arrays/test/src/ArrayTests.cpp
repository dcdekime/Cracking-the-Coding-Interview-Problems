#include "ArrayTests.h"

ArrayTests::ArrayTests() : mArrayProblemsObj(ArrayProblems::getInstance()) {};

ArrayTests& ArrayTests::getInstance()
{
    static ArrayTests instance;
    return instance;
}

void ArrayTests::runUnitTests()
{
    run_isUnique_tests();
    run_checkPermutation_tests();
    run_URLify_tests();
    run_PalindromePermutation_tests();
    run_OneAway_tests();
    run_StringCompression_tests();
    run_RotateMatrix_tests();
    run_ZeroMatrix_tests();
    run_StringRotation_tests();
}

void ArrayTests::run_isUnique_tests()
{
    // test case 1
    std::string testString1 = "abcdefghijkl";
    // test case 2
    std::string testString2 = "potato";


    std::string test1 = mArrayProblemsObj.isUnique(testString1) ? "Passed" : "Failed";
    std::string test2 = mArrayProblemsObj.isUnique(testString2) ? "Failed" : "Passed";

    std::cout << "IsUnique test case 1:  " << test1 << std::endl;
    std::cout << "IsUnique test case 2:  " << test2 << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_checkPermutation_tests()
{
    // test case 1
    std::string testString1 = "potato";
    std::string testString2 = "ptoaot";
    
    // test case 2
    std::string testString3 = "potato";
    std::string testString4 = "carrot";


    std::string test1 = mArrayProblemsObj.checkPermutation(testString1, testString2) ? "Passed" : "Failed";
    std::string test2 = mArrayProblemsObj.checkPermutation(testString3, testString4) ? "Failed" : "Passed";

    std::cout << "checkPermutation test case 1:  " << test1 << std::endl;
    std::cout << "checkPermutation test case 2:  " << test2 << std::endl;
    std::cout << std::endl;
    
}

void ArrayTests::run_URLify_tests()
{
    std::string inputStr = "Mr John Smith    ";
    std::string expectedStr = "Mr%20John%20Smith";
    int trueLength = 13;
    
    mArrayProblemsObj.URLify(inputStr, trueLength);
    
    std::string resultStatement = inputStr == expectedStr ? "Passed" : "Failed";
    std::cout << "URLifiedString Tests: " << resultStatement << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_PalindromePermutation_tests()
{
    std::string inputStr = "Tact Coa";
    std::string resultStatement = mArrayProblemsObj.palindromePermutation(inputStr) ? "Passed" : "Failed";
    std::cout << "PalindromePermutation Tests: " << resultStatement << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_OneAway_tests()
{
    // test case 1
    std::string testStr1 = "pale";
    std::string testStr2 = "ple";
    std::string res1 = mArrayProblemsObj.oneAway(testStr1, testStr2) ? "Passed" : "Failed";

    std::cout << "OneAway test case 1: " << res1 << std::endl;

    // test case 2 -> should fail
    std::string testStr3 = "pale";
    std::string testStr4 = "bake";
    std::string res2 = mArrayProblemsObj.oneAway(testStr3, testStr4) ? "Failed" : "Passed";

    std::cout << "OneAway test case 2: " << res2 << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_StringCompression_tests()
{
    // aabcccccaaa -> a2b1c5a3
    std::string testInput1 = "aabcccccaaa";
    std::string testInput2 = "bbcqqqdddddzzzxxx";
    std::string expected = "b2c1q3d5z3x3";
    
    std::string res = mArrayProblemsObj.stringCompression(testInput2) == expected ? "Passed" : "Failed";

    std::cout << "StringCompression Tests: " << res << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_RotateMatrix_tests()
{
    std::vector<std::vector<int>> testMatrix {{1, 2, 3},
                                              {4, 5, 6},
                                              {7, 8, 9}};
    
    std::vector<std::vector<int>> expectedMatrix {{7, 4, 1},
                                                  {8, 5, 2},
                                                  {9, 6, 3}};
    
    mArrayProblemsObj.rotateMatrix(testMatrix);
    bool result = true;
    
    for (int i=0; i < testMatrix.size(); i++)
    {
        for (int j=0; j < testMatrix[0].size(); j++)
        {
            if (testMatrix[i][j] != expectedMatrix[i][j])
            {
                result = false;
                break;
            }
        }
    }
    
    std::string resultStatement = result ? "Passed" : "Failed";
    std::cout << "RotateMatrix Tests: " << resultStatement << std::endl;
    std::cout << std::endl;
}

void ArrayTests::run_ZeroMatrix_tests()
{
    std::vector<std::vector<int>> testMatrix {{1, 0, 3},
                                              {4, 5, 6},
                                              {7, 8, 9}};
    
    std::vector<std::vector<int>> expectedMatrix {{0, 0, 0},
                                                  {4, 0, 6},
                                                  {7, 0, 9}};
    
    mArrayProblemsObj.zeroMatrix(testMatrix);
    bool result = true;
    
    for (int i=0; i < testMatrix.size(); i++)
    {
        for (int j=0; j < testMatrix[0].size(); j++)
        {
            if (testMatrix[i][j] != expectedMatrix[i][j])
            {
                result = false;
                break;
            }
        }
    }
    
    std::string resultStatement = result ? "Passed" : "Failed";
    std::cout << "ZeroMatrix Tests: " << resultStatement << std::endl;
    std::cout << std::endl;
    
}

void ArrayTests::run_StringRotation_tests()
{
    
}

