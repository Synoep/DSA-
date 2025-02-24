class AllOne {
    map<string,int>mp;
    set<pair<int,string>>s;
public:
    AllOne(){}
    
    void inc(string key) {
        int i=mp[key];
        mp[key]++;
        s.insert({i+1,key});
        if(i>0) s.erase({i,key});
    }
    
    void dec(string key) {
        int i=mp[key];
        mp[key]--;
        if(i>1) s.insert({i-1,key});
        s.erase({i,key});
    }
    
    string getMaxKey() {
        if(!s.empty()){
        auto it=s.end();
        it--;
        return it->second;
        }
        return "";
    }
    
    string getMinKey() {
        if(!s.empty()){
        auto it=s.begin();
        return it->second;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */