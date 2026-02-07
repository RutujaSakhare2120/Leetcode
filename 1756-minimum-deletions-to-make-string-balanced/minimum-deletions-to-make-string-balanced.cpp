class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<int> leftB(n), rightA(n);

        int b = 0;
        for (int i = 0; i < n; i++) {
            leftB[i] = b;          // b's before i
            if (s[i] == 'b') b++;
        }

        int a = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightA[i] = a;         // a's after i
            if (s[i] == 'a') a++;
        }

        int count = INT_MAX;
        for (int i = 0; i < n; i++) {
            count = min(count, leftB[i] + rightA[i]);
        }

        return count;
    }
};
