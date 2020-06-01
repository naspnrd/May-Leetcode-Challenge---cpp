Count Square Submatrices with All Ones - 1277

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

 

Constraints:

    1 <= arr.length <= 300
    1 <= arr[0].length <= 300
    0 <= arr[i][j] <= 1

code:

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        if (matrix.empty()) 
            return 0;
        int m= matrix.size();
        int n = matrix[0].size();
        
        int topleft = 0;
        int result = 0;
        
        vector<int> counts(n , 0);
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n; j++)
                if(matrix[i][j] == 1){
                int top = (i == 0) ? 0 : counts[j] ; 
                int left = (j == 0) ? 0 : counts[j - 1] ;
                counts[j] = 1 + min({top , left , topleft});
                
                result += counts[j];
                
                topleft = (j == n-1) ? 0 : top ;
                }
                else{
                    counts[j] = 0;
                }
        return result;   
    }
};