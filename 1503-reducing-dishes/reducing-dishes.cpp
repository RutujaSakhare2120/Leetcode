class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        //1.sort
        //2.suffixSum
        //3.consider from first +ve ele in suffix array as idx for sorted array
        sort(satisfaction.begin() , satisfaction.end());
        int n=satisfaction.size();
        vector<int>suffix(n);
        suffix[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
         suffix[i]=satisfaction[i]+suffix[i+1];
        }


        int idx=-1;
        for(int i=0;i<n;i++){
            if(suffix[i]>0){
                 idx=i;
                 break;
            } 
        }
        int m=1;
        int ans=0;
        if(idx==-1) return 0;
        for(int i=idx;i<n;i++){
          ans+=(m*satisfaction[i]);
          m++;
        }
       return ans;
    }
};