class Solution {
public:
    string generateTag(string caption) {
        int n=caption.size();
        string s="#";
        bool f=true;
        for(int i=0;i<n;i++){
            if(caption[i]==' '){
                continue;
            }
            if(f){
                 s+=(char)tolower(caption[i]);
                 f=false;
            }
            else{
                if(caption[i-1]==' ') s+=(char)toupper(caption[i]);
                else s+=(char)tolower(caption[i]);
            }
        }
        return s.substr(0,100);

    }
};