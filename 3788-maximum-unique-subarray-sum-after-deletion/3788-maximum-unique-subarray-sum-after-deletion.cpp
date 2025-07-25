class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        vector<int>temp(s.begin(),s.end());
        sort(temp.begin(),temp.end(),greater<int>());
        int ans=temp[0];
        for(int i=1; i<temp.size(); i++){
            if(temp[i]>0){
                ans+=temp[i];
            }
        }
        return ans;
    }
};