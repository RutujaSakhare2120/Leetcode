class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
       vector< int>prefixN(n+1);
        vector<int>suffixY(n+1);
        prefixN[0]=0;
        suffixY[n]=0;

        for(int i=1;i<n+1;i++){
            if(customers[i-1]=='N') prefixN[i]=1+prefixN[i-1];
            else prefixN[i]=prefixN[i-1];
        }

        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y') suffixY[i]=1+ suffixY[i+1];
            else  suffixY[i]= suffixY[i+1];
        }

       vector< int>ans(n+1);
        for(int i=0;i<n+1;i++){
            ans[i]=(prefixN[i]+suffixY[i]);
        }
         
         int minVal=INT_MAX;
         int idx=-1;
        for(int i=0;i<n+1;i++){
           if(ans[i]<minVal){
            minVal=ans[i];
            idx=i;
           }
        }
        return idx;
    }
};