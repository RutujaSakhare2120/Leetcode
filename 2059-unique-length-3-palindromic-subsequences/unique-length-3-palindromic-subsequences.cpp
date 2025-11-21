class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);

        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(first[idx]==-1) first[idx]=i;
            last[idx]=i;
        }
        int count=0;
        for(int i=0;i<26;i++){
            int L=first[i];
            int R=last[i];
            if(L==-1 || R==-1 || R-L<2) continue;
            unordered_set<char>helper;
            for(int j=L+1;j<R;j++){
                helper.insert(s[j]);
              
            }

            count+=helper.size();


        }
        return count;
    }
};