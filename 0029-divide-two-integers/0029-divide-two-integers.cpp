




/*

    Time Complexity : O(1), Constant Operation.

    Space Complexity : O(1), Constant space.

    Solved using Math.

*/


/***************************************** Approach 2 *****************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        return dividend/divisor;
    }
};