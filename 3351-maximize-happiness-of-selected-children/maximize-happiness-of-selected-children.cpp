class Solution {
public:
    // void decre(vector<int>& happiness){

    //     for(int i=0;i<happiness.size();i++)
    //     {  if(happiness[i]==0) continue;
    //        happiness[i]--;

    //     }

    // }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       

        sort(happiness.begin() , happiness.end());
        long long ans=0;
        int p=0;

        while(k>0){
             
             int last = (long long)happiness.back();
             if(last-p <0) {k--;p++;continue;}
            else{
               ans+=  last-p;
            } 
             p++;
             happiness.pop_back(); 
           
             k--;

        }
        return ans;
        
    }
};