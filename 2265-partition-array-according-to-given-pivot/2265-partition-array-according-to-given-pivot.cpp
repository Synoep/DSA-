class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small,large;
        int count=0;
        for(auto a:nums){
            if(a==pivot) count++;
            else if(a<pivot) small.push_back(a);
            else large.push_back(a);
        }
        for(int i=0;i<count;i++){
            small.push_back(pivot);
        }
        for(auto f: large){
            small.push_back(f);
        }
        return small;
    }
};