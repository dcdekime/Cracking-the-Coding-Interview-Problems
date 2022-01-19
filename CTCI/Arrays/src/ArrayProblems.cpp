#include "ArrayProblems.h"

ArrayProblems::ArrayProblems()
{
    
}

/*  Problem Source: Cracking the Coding Interview - 1.1 Is Unique

    Problem Description: Implement an algorithm to determine if a string has all unique characters.
                         What if you cannot use additional data structures?

    Approach:
        1) Assume input string is ASCII -> 128 alphanumeric values
        2) Create boolean array of length 128 filled with false values
        3) Iterate through input string and update array index value to true when a character is seen
        4) If current character has already been set to true -> there is a redundancy -> return false
        5) Otherwise return true
*/

bool ArrayProblems::isUnique(const std::string& inputString)
{
    std::array<bool, Parameters::MAX_ASCII_VALUES> characterChecker;
    characterChecker.fill(false);

    if (inputString.length() > 128)
    {
        return false;
    }

    for (const char& currChar : inputString)
    {
        int ind = (int) currChar;
        if (!characterChecker[ind])
        {
            characterChecker[ind] = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

/*  Problem Source: Cracking the Coding Interview - 1.2 Check Permutation

    Problem Description: Given two strintgs, write a method to decide if one is a permutation of the other


    Approach:
        1) initialize array of ints 128 long
        2) iterate through each character in first input string and add 1 to array index
        3) iterate through each character in second input string and subtract 1 from array value
        4) if any array value is less than 0 -> return false
        5) if lengths of two input strings don't match -> return false
*/

bool ArrayProblems::checkPermutation(const std::string& str1, const std::string& str2)
{
    std::array<int,128> characterCount;
    characterCount.fill(0);
    
    if (str1.length() != str2.length())
    {
        return false;
    }
    
    for (auto& charVal : str1)
    {
        characterCount[charVal]++;
    }
    
    for (auto& charVal : str2)
    {
        characterCount[charVal]--;
        
        if (characterCount[charVal] < 0)
        {
            return false;
        }
    }
    
    return true;
}


