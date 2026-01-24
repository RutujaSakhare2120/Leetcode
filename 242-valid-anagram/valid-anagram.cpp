class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char , int>m;
        for(int i=0;i<s.size() ;i++){
            m[s[i]]++;
        }
         unordered_map<char , int>m1;
        for(int i=0;i<t.size() ;i++){
            m1[t[i]]++;
        }
       if(m==m1) return true;
        return false;
        
    }
};