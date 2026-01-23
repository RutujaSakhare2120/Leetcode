class Solution {
public:
    int reverseDigit(int n){
        int ans=0;
        while(n>0){
            int last=n%10;
            ans=10*ans+last;
            n/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int>s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int n=reverseDigit(nums[i]);
            s.insert(n);
        }

        return s.size();

    }
};