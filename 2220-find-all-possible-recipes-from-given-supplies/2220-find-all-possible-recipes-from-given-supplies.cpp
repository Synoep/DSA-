class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //i can run here n2
        int n=ingredients.size();
        unordered_map<string,int> mpp;
        for(auto it:supplies){
            mpp[it]=1;
        }
        vector<string> ans;
        //set<string> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool f=true;
                for(int k=0;k<ingredients[j].size();k++){
                    if(mpp.find(ingredients[j][k]) == mpp.end()) {
                        f=false;
                        break;
                    }
                }
                if(f && (mpp.find(recipes[j]) == mpp.end())){
                    ans.push_back(recipes[j]);
                    mpp[recipes[j]]=1;
                }
            }
        }
        return ans;
    }
};