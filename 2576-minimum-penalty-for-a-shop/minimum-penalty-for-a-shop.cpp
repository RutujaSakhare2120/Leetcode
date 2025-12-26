class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
       vector<int> pre(n+1);//for N before nth hour
        vector<int> suf(n+1);//for Y after including nth hour
        pre[0]=0;
        for(int i=0;i<n;i++){
            // int count=0;
            // if(customers[i]=='N') count++;
            pre[i+1]=pre[i]+ ((customers[i]=='N') ? 1 :0);
        }

        suf[n]=0;
       for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+((customers[i]=='Y') ? 1 :0);
       }


       
        for(int i=0;i<=n;i++){
            pre[i]=pre[i]+suf[i];
        }
        
        int  minEle=INT_MAX;
        int minidx=0;
        for(int i=0;i<=n;i++){
             if(pre[i]<minEle){minEle=pre[i];minidx=i;}
        }
       return minidx; 
    }
};