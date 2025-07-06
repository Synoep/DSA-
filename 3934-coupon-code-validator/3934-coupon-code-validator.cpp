class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> valid;
        for(int i=0;i<code.size();i++){
            if(!code[i].empty() && 
            (businessLine[i] == "grocery" 
            || businessLine[i] == "electronics" 
            || businessLine[i]=="pharmacy" 
            || businessLine[i]=="restaurant") 
            && isActive[i]){
                bool flag = true;
                for(int j =0;j<code[i].size();j++){
                    if((code[i][j]<='z'&&code[i][j]>='a') 
                    || (code[i][j]>='A'&&code[i][j]<='Z') 
                    || (code[i][j]>='0' &&code[i][j]<='9') 
                    || code[i][j]=='_'){ continue;}
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag) valid.push_back({businessLine[i],code[i]});
            }
        }
        if(!valid.empty()) sort(valid.begin(), valid.end());
        vector<string> ans;
        for(int i=0;i<valid.size();i++){
            ans.push_back(valid[i].second);
        }
        return ans;
        
    }
};