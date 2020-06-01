Find All Anagrams in a String - 438

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


code:

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.size() > s.size())
            return result;
        vector<int> pchars(26,0);
        for(char c : p)
            pchars[c - 'a']++;
        
        int start= 0;
        for(int i = 0; i< p.size();i++)
            pchars[s[i] - 'a']--;
        
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
            result.push_back(start);
        start++;
        
        while(start <= s.size() - p.size())
        {
            int idx1 = s[start - 1] - 'a';
            int idx2 = s[start + p.length()-1] -'a';
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
                    result.push_back(start);
                start++;
         }
        return result;
    }
};