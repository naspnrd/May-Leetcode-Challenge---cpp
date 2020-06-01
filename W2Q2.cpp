Valid Perfect Square - 367

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true

Example 2:

Input: num = 14
Output: false

 

Constraints:

    1 <= num <= 2^31 - 1

     code:
	 
class Solution {
public:
    bool isPerfectSquare(int num) {
     
         for (long long i = 1; i * i <= num; i++) { 
  
            // If (i * i = n) 
            if ((num % i == 0) && (num / i == i)) { 
                return true; 
            } 
        } 
        return false; 
        
//         int unit = num % 10;
//         if(unit == 2 || unit == 3 || unit == 7 || unit == 8)
//             return false;
//         int ten = tens(num);
//          if(unit == 5)
//             {
//                 //int ten = tens(num);
//                 if(ten == 2)
//                     return true;
//             }
//             if(unit == 6)
//             {
//                 //int ten = tens(num);
//                 if(ten %2 != 0)
//                     return true;
//             }
        
//             if(unit == 1 || unit == 4 || unit == 9)
//             {
//                 //int ten = tens(num);
//                 if(ten % 2 == 0)
//                     return true;
//             }
//         if(unit == 0 && ten ==0)
//             return true;
   
//         int sum = sum_unit(num);
        
//         while(1)
//         {
//         if(sum > 9)
//             sum= sum_unit(sum);
//          else 
//              break;
//         }
        
//         if(sum == 1 || sum == 4 || sum == 7 || sum == 9)
//         {
//             return true;
//           }
        
        
    // return false;
            
}
    
    int sum_unit(int n)
    {
        int sum = 0;
    while(n)
    {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
        return sum;
    }
    
    int tens(int n)
    {
        int i=1,tens;
                while(i<=2)
                {
                    tens = n %10;
                    n /= 10;
                    i++;
                }
        return tens;
    }
};