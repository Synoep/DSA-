class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int c1,c2;
        for(auto z:nums){
            if(z==c1) count1++;
            else if(z==c2) count2++;
            else if(count1==0) c1=z,count1=1;
            else if(count2==0) c2=z,count2=1;
            else count1--,count2--;
        }
        count1=0,count2 = 0;
        for (auto z:nums) {
            if (z==c1) count1++;
            else if (z==c2) count2++;
        }
        vector<int> ans;
        if(count1>nums.size()/3) ans.push_back(c1);
        if(count2>nums.size()/3) ans.push_back(c2);
        return ans;
    }
};