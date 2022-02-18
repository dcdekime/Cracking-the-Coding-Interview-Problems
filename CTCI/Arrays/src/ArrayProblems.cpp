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
 
     
     Time Complexity:    O()
     Space Complexity:   O()
*/

bool ArrayProblems::isUnique(const std::string& inputString)
{
    std::array<bool, Parameters::MAX_ASCII_VALUES> characterChecker;
    characterChecker.fill(false);

    if (inputString.length() > Parameters::MAX_ASCII_VALUES)
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
 
 
     Time Complexity:    O()
     Space Complexity:   O()
*/

bool ArrayProblems::checkPermutation(const std::string& str1, const std::string& str2)
{
    std::array<int,Parameters::MAX_ASCII_VALUES> characterCount;
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
 
 
    Time Complexity:    O()
    Space Complexity:   O()
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
 
 
    Time Complexity:    O()
    Space Complexity:   O()
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
                        
                        -insert a character
                        -remove a character
                        -replace a character
    
    Given two strings, write a function to check if they are one edit (or zero edits) away

    EXAMPLE
        pale, ple   -> true
        pales, pale -> true
        pale, bale  -> true
        pale, bake  -> false

    Approach:
        1)
 
 
    Time Complexity:    O()
    Space Complexity:   O()
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


/*  Problem Source: Cracking the Coding Interview - 1.6 String Compression

    Problem Description: Implement a method to perform basic string compression using the
                         counts of repeated characters. For example, the string aabcccccaaa
                         would become a2b1c5a3. If the "compressed" string would not become
                         smaller than the original string, your method should return the original
                         string. You can assume the string has only uppercase and lowercase letters (a-z)
                         

    EXAMPLE
    Input: aabcccccaaa
    Output: a2b1c5a3

    Approach:
        1)
 
 
    Time Complexity:    O()
    Space Complexity:   O()
*/

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


/*  Problem Source: Cracking the Coding Interview - 1.7 Rotate Matrix

    Problem Description: Given an image by an NxN matrix, where each pixel in the image is 4 bytes,
                         write a method to rotate the image by 90 degrees. Can you do this in place?
                         

    EXAMPLE
    Input:  {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}}
 
    Output: {{7, 4, 1},
             {8, 5, 2},
             {9, 6, 3}}

    Approach:
        1)
 
 
    Time Complexity:    O()
    Space Complexity:   O()
*/

void ArrayProblems::rotateMatrix(std::vector<std::vector<int>>& matrix) 
{
    // edge case: not NxN or empty
    if (matrix.size() != matrix[0].size() || !matrix.size())
    {
        return;
    }
    
    // utilize two-pointer approach
    size_t n = matrix.size();
    for (int currentLayer=0; currentLayer < n/2; currentLayer++)
    {
        // set pointers -> rows meet in the middle thus n/2
        int first = currentLayer;
        int last = int(n) - 1 - currentLayer;
        
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


/*  Problem Source: Cracking the Coding Interview - 1.8 Zero Matrix

    Problem Description: Write an algorithm such that if an element in an MxN matrix is 0, its
                         entire row and column are set to 0.
                         

    EXAMPLE
    Input:  {{1, 0, 3},
             {4, 5, 6},
             {7, 8, 9}}
 
    Output: {{0, 0, 0},
             {8, 0, 2},
             {9, 0, 3}}

    Approach:
        1)

 
    Time Complexity:    O()
    Space Complexity:   O()
*/

void helperZeroRow(std::vector<std::vector<int>>& matrix, int rowInd)
{
    for (int j=0; j < matrix[0].size(); j++)
    {
        matrix[rowInd][j] = 0;
    }
}

void helperZeroCol(std::vector<std::vector<int>>& matrix, int colInd)
{
    for (int i=0; i < matrix.size(); i++)
    {
        matrix[i][colInd] = 0;
    }
}

void ArrayProblems::zeroMatrix(std::vector<std::vector<int>>& matrix)
{
    bool firstRowZero = false;
    bool firstColZero = false;
    
    // check if first row has a zero in it
    for (int j=0; j < matrix[0].size(); j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }
    
    // check if first col has a zero in it
    for (int i=0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }
    
    // check rest of matrix starting from row 1, col 1 for zeros
    for (int i=1; i < matrix.size(); i++)
    {
        for (int j=1; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // mark 0th col of that row with 0
                matrix[0][j] = 0; // mark 0th row of that col with 0
            }
        }
    }
    
    // iterate through rows and 0th col
    for (int i=1; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            helperZeroRow(matrix, i);
        }
    }
    
    // iterate through cols and 0th row
    for (int j=1; j < matrix[0].size(); j++)
    {
        if (matrix[0][j] == 0)
        {
            helperZeroCol(matrix, j);
        }
    }
    
    // Do same thing for 0th row
    if (firstRowZero)
        helperZeroRow(matrix, 0);
    
    // Do same thing for 0th col
    if (firstColZero)
        helperZeroCol(matrix, 0);
}


/*  Problem Source: Cracking the Coding Interview - 1.9 String Rotation

    Problem Description: Assume you have a method isSubstring which checks if one word is a
                         substring of another. Given two strings, s1 and s2, write code to check
                         if s2 is a rotation of s1 using only one call to isSubstring
                         (e.g., "waterbottle" is a rotation of "erbottlewat").
                         

    EXAMPLE
    Input:  s1 = "waterbottle", s2 = "erbottlewat"
 
    Output: True -> s2 is a rotation of s1

    Approach:
        1) if in fact s2 is a rotation of s1 -> they will have equal length
        2) if we double s1 (e.g. "waterbottlewaterbottle")
           then if s2 is a rotation of s1 -> s1s1 will contain s2 ["erbottlewat"] is in s1s1
 
 
    Time Complexity:    O(N) -> depends on length of str1 and str2
    Space Complexity:   O(1)
*/

bool ArrayProblems::stringRotation(std::string& str1, std::string& str2)
{
    // make sure s1 and s2 are equal length and non-zero
    if ((str1.length() == str2.length()) && str1.length() != 0)
    {
        std::string doubleStr1 = str1 + str1;    // double length of s1
        // return isSubstring(doubleStr1, str2); //  commenting out as isSubstring doesn't exist
    }
    return false;
}

