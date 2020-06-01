 Permutation in String - 567

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

 

Constraints:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].

code:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        if (s1 == "") 
            return true;

        int pchars[26] = {0};
        
        for(char c : s1)
            pchars[c - 'a'] += 1;
        
        int start = 0;
        
        for(int i = 0; i < s1.length();i++)
            pchars[s2[i] - 'a'] -= 1;
        
        bool match = true;
        
        for(char c : pchars)
        {
            if(c != 0)
            {
                match = false;
                break;
            }
        }
        if(match)
            return true;
        start++;
        
        while(start <= s2.length() - s1.length())
        {
            int idx1 = s2[start - 1] - 'a';
            int idx2 = s2[start + s1.length()-1] -'a';
            pchars[idx1]++;
            pchars[idx2]--;
            
            match = true;
            
        for(char c : pchars)
            {
                if(c != 0)
                {
                    match = false;
                    break;
                }
            }
            if(match)
                return true;
            start++;
        }
    return false;
    }
};