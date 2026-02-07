class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<int> rightA(n);

       

        int a = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightA[i] = a;         // a's after i
            if (s[i] == 'a') a++;
        }
        
        int ans = INT_MAX;
        int count=0;//count of left b;
        for (int i = 0; i < n; i++) {
            
            ans = min(ans, count + rightA[i]);
            if(s[i]=='b') count++;
        }

        return ans;
    }
};
