class Solution {
public: 
    void dfs(int a,int n,vector<int> &v){
        if(a<=n) v.push_back(a);
        else return;
        for(int i=0;i<=9;i++){
           dfs(a*10+i,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for(int i=1;i<=9;i++) dfs(i,n,v);
        return v;
    }
};