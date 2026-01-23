class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<long long > temp(n);
        for(int i=0;i<n;i++){
            temp[i]=nums[i];
        }


        set<pair<long long , int>>minSet;

        vector<int>prevIdx(n);
        vector<int>nextIdx(n);

        for(int i=0;i<n;i++){
            prevIdx[i]=i-1;
            nextIdx[i]=i+1;
        }

        int badPair=0;
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]) badPair++;
            minSet.insert({temp[i]+temp[i+1] , i});

        }
        int operation=0;

        while(badPair>0){
         int first=minSet.begin()->second;
         int second=nextIdx[first];

         minSet.erase(minSet.begin());

         
         int firstLeft=prevIdx[first];
         int secondRight=nextIdx[second];

        if (temp[first] > temp[second]) badPair--;


         if(firstLeft>=0){
            if(temp[firstLeft]<=temp[first] && temp[firstLeft]>(temp[first]+temp[second])  ) badPair++;
            else if(temp[firstLeft]>temp[first] && temp[firstLeft]<=(temp[first]+temp[second])) badPair--;
         }

           if(secondRight<n){
            if(temp[secondRight]>=temp[second] && temp[secondRight]<(temp[first]+temp[second])) badPair++;
            else if( temp[secondRight]<temp[second] && temp[secondRight]>=(temp[first]+temp[second])) badPair--;
         }
         if(firstLeft>=0){
            minSet.erase({temp[first]+temp[firstLeft]  ,firstLeft });
         minSet.insert({temp[first]+temp[firstLeft]+temp[second] , firstLeft});
         }
        
     if(secondRight<n){
        
         minSet.erase({temp[second]+temp[secondRight]  ,second });
         minSet.insert({temp[second]+temp[secondRight]+temp[first] , first});
          prevIdx[secondRight]=first;

     }
      nextIdx[first]=secondRight;
     temp[first]+=temp[second];
     
    
    

     operation++;
         


        }

        return operation;
    }
};