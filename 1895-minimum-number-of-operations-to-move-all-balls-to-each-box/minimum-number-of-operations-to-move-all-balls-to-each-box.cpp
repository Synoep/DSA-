int leftSum(vector<int> v,int point){
    int sum = 0;
    for(int i=0;i<point;i++)
        if(v[i] ==1)  sum = sum + (point-i);
    return sum;
}
int rightSum(vector<int> v,int point,int n){
    int sum = 0;
    for(int i=point;i<n;i++)if(v[i] == 1)  sum =sum + (i-point);
    return sum;
}
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        vector<int> ans;
        int n = boxes.size();
        for(int i=0;i<n;i++){
            if(boxes[i] == '1')  v.push_back(1);
            else   v.push_back(0);
        }
        for(int i=0;i<n;i++){
            int left = leftSum(v,i);
            int right = rightSum(v,i,n);
            ans.push_back(right+left);
        }
        return ans;
    }
};