class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9){
            digits[n-1]++;
        }
        else{
            bool flag= true;
            int i=n-1;
            while(flag && i>=0){
                if(digits[i]==9){
                    digits[i]=0;
                    i--;
                }
                else flag=false;
            }
            if(i>=0) digits[i]++;
            else digits.insert(digits.begin(),1);
        }

        return digits;
    }
};