
bool compare(string a,string b){
    return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {	
        vector<string>v;
        for(int i:nums)v.push_back(to_string(i));
        sort(v.begin(),v.end(),compare);
        string result;
        for(int i=0;i<v.size();i++)  result+=v[i];
        return result[0]=='0'? "0" :result;
    }
};