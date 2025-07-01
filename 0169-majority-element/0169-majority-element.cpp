class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a;
        int count=0;
        for(auto b:nums){
            if(count==0) a=b;
            if(b==a) count++;
            else count--;
        }
        return a;
    }
};