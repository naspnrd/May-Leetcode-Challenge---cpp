First Unique Character in a String - 387

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 

   code:
class Solution {
public:
    int firstUniqChar(string s) {
        // for(int i=0;i<s.size();i++)
        // {
        //     int j=i;
        //     while(j<s.size())
        //     {
        //         if(s[i]==s[j])
        //             continue;
        //         else
        //         {
        //             return i;
        //         }
        //         j++;
        //     }
        // }
        // return -1;
        map<char,int>m;
        
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
       // return m.size();
        for(int i=0;i<s.size();i++)
        {       if(m[s[i]]==1)
            {
                return i;
                 //break;
            }
        }
        
        return -1;        
    }
};
