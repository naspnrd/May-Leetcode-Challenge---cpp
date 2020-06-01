Single Element in a Sorted Array - 540

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

 

Constraints:

    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5

     code:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       // int res = 0;
       //  for(int i =0;i<nums.size();i++)
       //  {
       //      res = res ^ nums[i];
       //  }
       //  return res;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right)
        {
            int mid = left + (right - left)/2;
            // aa bb cc d ee   
            if(mid %2 == 0)
            {
                if(nums[mid] == nums[mid-1])
                    right = mid - 2;
                else if(nums[mid] == nums[mid+1])
                    left = mid + 2;
                else
                    return nums[mid];
            }
            else
            {
                    //example: aa bb cc d ee
                if(nums[mid] == nums[mid-1])
                    left = mid + 1;
                    //example: aa b cc dd ee
               else if(nums[mid] == nums[mid+1])
                    right = mid - 1;
            }
        }
        
//         // int non_repeated = INT_MIN;
        
// //         for(int i=0;i<nums.size();i=i+2)
// //         {
            
// //             if(nums[i] == nums[i+1])
// //                 continue;
// //             else
// //             {
// //                 non_repeated = nums[i];
// //                 break;
// //             }
// //         }
// //         return non_repeated;

        return nums[left];
    }
};
	 