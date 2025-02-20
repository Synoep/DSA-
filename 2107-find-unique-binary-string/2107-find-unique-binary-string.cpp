class Solution {
    void gen(vector<string>&v, int n, string curr){
        if(curr.size()==n){
             v.push_back(curr);
              return;
        }
        gen(v,n,curr+'0');
        gen(v,n,curr+'1');        
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> v;
        gen(v,nums.size(),"");
        set<string> s(nums.begin(),nums.end());
        for(int i=0;i<v.size();i++){
            if(s.find(v[i])==s.end()) return v[i]; 
        }
      return "";
    }
};