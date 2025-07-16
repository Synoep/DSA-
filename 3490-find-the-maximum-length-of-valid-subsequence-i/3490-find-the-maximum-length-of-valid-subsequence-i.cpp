class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        int e=0,o=0;
        for (int num:nums){
            int p=num%2;  
            if (p ==0){
                even++;          
                e=o+1;  
            } 
            else {
                odd++;            
                o=e+1;
            }
        }
        return max({even,odd,e,o});
    }
};