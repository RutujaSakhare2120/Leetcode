class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int count1=0;
        int count2=0;
        int ans=0;
        string s=bank[0];
        for(char c:s){
            if(c=='1') count1++;
        }
        for(int i=1;i<n;i++){
            string s=bank[i];
        
            for(char p:s){
                if(p=='1') count2++;
            }

            if(count2!=0){
              ans+=(count1*count2);
              count1=count2;
              count2=0;
            }
        }
        return ans;
    }
};