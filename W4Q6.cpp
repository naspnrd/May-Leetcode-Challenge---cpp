 Counting Bits -0 338

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

	code:
class Solution {
public:
    vector<int> countBits(int num) {
//         vector<int> result;
//         //int* result = new int[num+1];
//         int p = 1 ;// keep count of indices of power of 2
//         int po = 1;
        
//         //result[0] = 0;
//         result.push_back(0);
        
//         for(int i=1; i<=num; i++){
//             if(i==po){
//                 result.push_back(1);
//             po <<= 1;
//             //po = po*pow(2,1);  
//             p = 1;
//           }
//            else{
//             result.push_back(result[p]+1);
//             p++;
//          }
//        }
//     return result;
        
        // memoization technique of dp remember what we have calculated before and use that for other solution 
        vector <int> result(num+1,0);
        
        for(int i = 1; i<= num;i++)
            result[i] = result[i >> 1] + i%2;
        return result;
    }
};