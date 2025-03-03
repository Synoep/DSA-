class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if( n == 1) return 1;
        int maxAns = 2;
        for(int i=0; i<n-1; i++){
            map<double, int> tangentMap;
            for(int j=0; j<n; j++){
                if(i == j)
                    continue;
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                double tangent = atan2((y2-y1),(x2-x1));
                tangentMap[tangent]++;
                maxAns = max(maxAns, tangentMap[tangent]+1);
            }
        }
        
        return maxAns;
    }
};