class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n=v.size();
        vector<int>ans;
        int left =0,right=n-1;
        while(left<right){
            if(v[left]+v[right]==target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            if(v[left]+v[right]>target) right--;
            else left++;
        }
        return ans;
    }
};