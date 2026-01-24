class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int , int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }

         unordered_set<int>s;
        for(auto p:m){
           int key=p.second;
           if(s.find(key)!=s.end()) return false;
           s.insert(key);
        }
        return true;
    }
};