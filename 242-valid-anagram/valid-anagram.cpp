class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char , int>m;
        for(int i=0;i<s.size() ;i++){
            m[s[i]]++;
        }
       for(int i=0;i<t.size();i++){
        char c=t[i];
        if(m.find(c)!=m.end()) {
            m[c]--;
            if(m[c]==0) m.erase(c);
            }
        else return false;
       
       }
       if(m.size()>0) return false;

       return true;
        
    }
};