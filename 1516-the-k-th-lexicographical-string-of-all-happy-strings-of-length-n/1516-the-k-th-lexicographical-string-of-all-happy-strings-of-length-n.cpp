class Solution {
    void gen(int n,string cur,vector<string>&v){
        if(cur.length()==n){
             v.push_back(cur);
             return;
        }
        for(char ch: {'a','b','c'}){
            if(cur.empty()||cur.back()!=ch) gen(n,cur+ch,v);
        }
    }
public:
    string getHappyString(int n, int k) {
       vector<string>v;
       gen(n, "", v);
       if(k>v.size()) return "";
       return v[k-1];   
    }
};