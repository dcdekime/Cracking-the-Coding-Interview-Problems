#ifndef ArrayProblems_h
#define ArrayProblems_h

#include <array>
#include <string>
#include <vector>
#include <unordered_map>

struct Parameters
{
    static const int MAX_ASCII_VALUES = 128;
};

class ArrayProblems
{
public:
    ArrayProblems();
    
    static ArrayProblems& getInstance();
        
    bool isUnique(const std::string& inputString);                              // ctci problem 1.1
    bool checkPermutation(const std::string& str1, const std::string& str2);    // ctci problem 1.2
    void URLify(std::string& charArr, int trueLength);                          // ctci problem 1.3
    bool palindromePermutation(const std::string& inputStr);                    // ctci problem 1.4
    bool oneAway(const std::string& str1, const std::string& str2);             // ctci problem 1.5
    std::string stringCompression(const std::string& inputStr);                 // ctci problem 1.6
    void rotateMatrix(std::vector<std::vector<int>>& matrix);                   // ctci problem 1.7
    void zeroMatrix(std::vector<std::vector<int>>& matrix);                     // ctci problem 1.8
    bool stringRotation(std::string& str1, std::string& str2);                  // ctci problem 1.9
};

#endif /* ArrayProblems_h */
