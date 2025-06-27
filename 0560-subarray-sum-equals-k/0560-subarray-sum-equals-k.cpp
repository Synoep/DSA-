class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,total=0;
        // mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) total+=1;
            int req=sum-k;
            if(mp.find(req)!=mp.end()) total+=mp[req];
            if(mp.find(sum)!=mp.end()) mp[sum]+=1;
            else mp[sum]=1;
        }
        return total;
    }
};