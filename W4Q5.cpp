Contiguous Array - 525

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000. 

code:

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        unordered_map<int,int> cache; //{sum,index}
        
        int count = nums[0] == 1 ? 1 :-1;
        
        cache[0] = -1;
        cache[count] = 0;
        int max_sum = 0 ;
        
        for(int i = 1;i<nums.size();i++)
        {
            count = ( nums[i] == 1 ) ?count + 1 : count -1;
            if(cache.find(count) != cache.end())
                max_sum = max(max_sum , i-cache[count]);
            else
                cache[count] = i;
        }
        return max_sum;
    }
};