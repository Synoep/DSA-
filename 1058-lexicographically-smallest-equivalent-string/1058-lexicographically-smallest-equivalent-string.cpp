class Solution {
public:
char FindingSmallest(unordered_map<int,vector<int>>&graph,int t){
    queue<int>Q;
    int mini=INT_MAX;
    unordered_set<int>visit;
    visit.insert(t);
    Q.push(t);
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        mini=min(mini,node);
        for(auto it:graph[node]){
            if(visit.find(it)==visit.end()){
                Q.push(it);
                visit.insert(it);
            }
        }
    }
    return char(mini);
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<s1.length();i++){
            graph[s1[i]].push_back(s2[i]);
            graph[s2[i]].push_back(s1[i]);
        }
        string res="";
        for(auto it:baseStr){
            int d=it;
            res.push_back(FindingSmallest(graph,d));
        }
        return res;
    }
};