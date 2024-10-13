// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    bool equal(char first, char sec) {
        return first == sec;
    }

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freqMap;
        int palindromeLength = 0;
        int oddPalindromeCount = 0;

        for ( string& word : words) {
            string reversedWord = word;
            reverse(reversedWord.begin(), reversedWord.end());

            // if the reverse of the word exists in the map
            if (freqMap[reversedWord] > 0) 
            {
                // We found a matching reverse word, which makes a palindrome
                palindromeLength += 4;  
                freqMap[reversedWord]--; // Decrease the count of the reversed word
            } 
            else 
            {
                // If reverse word is not found, increase the frequency of the current word
                freqMap[word]++;
            }
        }

        // Check if there's a word that can be placed in the center of the palindrome -> same word
        for ( auto& entry : freqMap) 
        {
            string word = entry.first;
            if (equal(word[0], word[1]) && freqMap[word] > 0) 
            {
                palindromeLength += 2; // Add the middle palindrome character
                break; // Only one such word can be in the center
            }
        }

        return palindromeLength;
    }
};
