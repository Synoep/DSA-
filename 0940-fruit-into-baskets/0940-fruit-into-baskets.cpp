class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map <int,int> mp;
        int left=0,count=0,ans=0;
        
        for(int i=0;i<n;i++){ 
            mp[fruits[i]]++;
            count++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                count--;
                if(mp[fruits[left]]==0)
                    mp.erase(fruits[left]);
                left++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};