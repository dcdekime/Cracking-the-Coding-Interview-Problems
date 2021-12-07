#include <iostream>
#include <array>
#include <string>

#define MAX_ASCII_VALUES 128

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

bool isUnique(std::string& inputString)
{
    std::array<bool, MAX_ASCII_VALUES> characterChecker;
    characterChecker.fill(false);

    if (inputString.length() > 128)
    {
        return false;
    }

    for (char& currChar : inputString)
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


int main()
{

    std::string testString1 = "abcdefghijkl";
    std::string testString2 = "potato";

    bool output = isUnique(testString1);
    std::string tfVal = output ? "true" : "false";

    std::cout << "IsUnique returned " << tfVal << std::endl;

    return 0;
}