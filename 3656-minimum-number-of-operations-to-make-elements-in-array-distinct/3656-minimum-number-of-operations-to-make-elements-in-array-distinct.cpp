class Solution {
public:
    bool f(vector<int>&v){
        int a=true;
        unordered_map<int,int>mp;
        for(auto a:v){
            mp[a]++;
            if(mp[a]>1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int count=0;
        while(!f(nums)){
            if (nums.size()>=3) {
                nums.erase(nums.begin(),nums.begin()+3);
                count++;
             }
            else if (nums.size()==0) break;
            else{
                count++;
                break;
            }
        
        }
        return count;
    }
};