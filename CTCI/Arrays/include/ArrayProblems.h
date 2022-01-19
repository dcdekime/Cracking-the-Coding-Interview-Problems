#ifndef ArrayProblems_h
#define ArrayProblems_h

#include <array>
#include <string>
#include <vector>

struct Parameters
{
    static const int MAX_ASCII_VALUES = 128;
};

class ArrayProblems
{
public:
    ArrayProblems(); 
        
    bool isUnique(const std::string& inputString); // ctci problem 1_1
    bool checkPermutation(const std::string& str1, const std::string& str2); // ctci problem 1_2
    std::string URLify(std::string& input); // ctci problem 1_3
    bool palindromePermutation(std::string& input); // ctci problem 1_4
    bool oneAway(std::string& str1, std::string& str2); // ctci problem 1_5
    std::string stringCompression(std::string& input); // ctci problem 1_6
    void rotateMatrix(std::vector<std::vector<int>>& originalMatrix); // ctci problem 1_7
    void zeroMatrix(std::vector<std::vector<int>>& originalMatrix); // ctci problem 1_8
    bool stringRotation(std::string& str1, std::string& str2); // ctci problem 1_9
};

#endif /* ArrayProblems_h */
