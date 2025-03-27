class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a:nums) mp[a]++;
        int h=nums.size()/2;
        int element=0;
        for (auto it:mp) { 
            if (it.second >h) { 
               element = it.first;
            }
        } 
        int count=0;
        if(element==0) return -1;
        int total=mp[element];
        int s=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element) count++;
            int rsize=nums.size()-(i+1);
            int lsize=i+1;
            if(count>lsize/2 &&  total-count>rsize/2) return i;

        }
        return -1;
    }
};