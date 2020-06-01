Sort Characters By Frequency - 451

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

code:

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char , int> count;
        
        for(int i = 0;i < s.size() ; i++)
            count[s[i]] ++;
        
        vector<pair<char,int>> vec_count(count.begin(),count.end());
        sort(vec_count.begin(),vec_count.end(),[](pair<char,int>& p1 , pair<char,int>& p2 )
             {
                 return p1.second > p2.second;
             });
        string result="";
        // for(pair<char,int> p : vec_count)
        // {
        //     for(int i = 0; i<p.second;i++)
        //         result += p.first;
        // }
        for (auto pair:vec_count) {
            result.append(pair.second, pair.first);
        }
        return result;
    }
};