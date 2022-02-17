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

    Problem Description: Given two strings, write a method to decide if one is a permutation of the other


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


/*  Problem Source: Cracking the Coding Interview - 1.3 URLify

    Problem Description: Write a method to replace all spaces in a string with '%20'. 
    You may assume that the string has sufficient space at the end to hold the additional 
    characters, and that you are given the "true" length of the string"

    EXAMPLE
    Input: ("Mr John Smith      ", 13)
    Output: "Mr%20John%20Smith"

    Approach:
        1) 
*/

void ArrayProblems::URLify(std::string& charArr, int trueLength)
{
    int spaceCount = 0;
    for (int i=0; i < trueLength; i++)
    {
        if (charArr[i] == ' ')
        {
            spaceCount++;
        }
    }

    int extraSpaces = spaceCount * 2;
    int rightPtr = trueLength + extraSpaces - 1;

    for (int leftPtr = trueLength-1; leftPtr >= 0; leftPtr--)
    {
        if (charArr[leftPtr] == ' ')
        {
            charArr[rightPtr] = '0';
            charArr[rightPtr-1] = '2';
            charArr[rightPtr-2] = '%';
            rightPtr -= 3;
        }
        else
        {
            charArr[rightPtr] = charArr[leftPtr];
            rightPtr--;
        }
    }
}


/*  Problem Source: Cracking the Coding Interview - 1.4 Palindrome Permutation

    Problem Description: Given a string, write a function to check if it is a permutation of a palindrome. 
                         A palindrome is a word or phrase that is the same forwards and backwards.
                         A permutation is a rearrangement of letters. The palindrome does not need to be 
                         limited to just dictionary words.

    EXAMPLE
    Input: Tact Coa
    Output: True (permutations: "taco cat", "atco cta", etc.)

    Approach:
        1)
*/

bool ArrayProblems::palindromePermutation(const std::string& inputStr)
{
  int strLen = 0;
  std::unordered_map<char, int> charCountMap;

  for (auto c : inputStr)
  {
    if (std::isalnum(c))
    {
      charCountMap[std::tolower(c)]++;
      strLen++;
    }
  }

  int oddCount = 0;
  for (auto item : charCountMap)
  {
    if (item.second % 2 == 1)
    {
      oddCount++;
    }
  }

  bool isOdd = strLen % 2 == 1 ? true : false;
  if ((isOdd && oddCount == 1) || (!isOdd && oddCount == 0))
  {
    return true;
  }

  return false;
}


/*  Problem Source: Cracking the Coding Interview - 1.5 One Away

    Problem Description: There are three types of edits that can be performed on strings: 
                         

    EXAMPLE
    Input: Tact Coa
    Output: True (permutations: "taco cat", "atco cta", etc.)

    Approach:
        1)
*/

bool ArrayProblems::oneAway(const std::string& str1, const std::string& str2)
{
  if (abs(int(str1.length()) - int(str2.length())) > 1)
    return false;
  
  int diffCount = 0, shortPtr = 0, longPtr = 0;

  bool lengthsEqual = str1.length() == str2.length();
  std::string shortStr = str1.length() < str2.length() ? str1 : str2;
  std::string longStr = str1.length() < str2.length() ? str2 : str1;

  while (shortPtr < shortStr.length() && longPtr < longStr.length())
  {
    if (diffCount > 1)
      return false;
    
    if (shortStr[shortPtr] != longStr[longPtr])
    {
      diffCount++;
      if (lengthsEqual)
        shortPtr++;
    }
    else
    {
      shortPtr++;
    }

    longPtr++;
  }
  
  return true;
}




std::string ArrayProblems::stringCompression(const std::string& inputStr)
{
  int charCount, leftPtr = 0;
  std::string compressedString = "";

  for (int rightPtr = 0; rightPtr <= inputStr.length(); rightPtr++)
  {
    if (rightPtr == inputStr.length() || inputStr[rightPtr] != inputStr[leftPtr])
    {
      charCount = rightPtr - leftPtr;
      compressedString += inputStr[leftPtr];
      compressedString += std::to_string(charCount);
      leftPtr = rightPtr;
      charCount = 0;
    }
  }

  return compressedString.length() < inputStr.length() ? compressedString : inputStr;
}



void ArrayProblems::rotateMatrix(std::vector<std::vector<int>>& matrix) 
{
    // edge case: not NxN or empty
    if (matrix.size() != matrix[0].size() || !matrix.size())
    {
        return;
    }
    
    // utilize two-pointer approach
    int n = matrix.size();
    for (int currentLayer=0; currentLayer < n/2; currentLayer++)
    {
        // set pointers -> rows meet in the middle thus n/2
        int first = currentLayer;
        int last = n - 1 - currentLayer;
        
        for (int i=first; i < last; i++)
        {
            // offset val
            int offset = i - first;
            
            // save top
            // keep top row fixed, move up cols
            int top = matrix[first][i];
            
            // leftCol -> topRow 
            // keep top row fixed, move up cols
            // keep left col fixed, move up rows
            matrix[first][i] = matrix[last-offset][first]; 
            
            // botRow -> leftCol
            // keep left col fixed, move up rows
            // keep bottom row fixed, move down cols
            matrix[last-offset][first] = matrix[last][last-offset];
            
            // rightCol -> botRow
            // keep bottom row fixed, move up cols
            // keep rightCol fixed, move down rows
            matrix[last][last-offset] = matrix[i][last];
            
            // topRow -> rightCol
            // keep right col fixed, down rows
            // keep top row fixed, move up cols
            matrix[i][last] = top;
        }
    }
}


