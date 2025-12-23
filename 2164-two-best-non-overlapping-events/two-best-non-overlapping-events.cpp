class Solution {
public:
    static bool comp(vector<int>&v1 , vector<int>&v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
      

        //sort based on starting point

        sort(events.begin() ,  events.end() ,comp);

        //precompute
         

        vector<int>best(n);
        best[n-1]=events[n-1][2];

        for(int i=n-2;i>=0;i--){
            best[i]=max(events[i][2] , best[i+1]);
        }

        //search first nonoverlapping using binary search
        int maxsum=0;
     
        for(int i=0;i<n;i++){
            int ans=n;
           
            int left=i+1;
            int right=n-1;

            
            while(left<=right){
                int mid=left+(right-left)/2;
                if(events[mid][0]>events[i][1]) {
                ans=mid;
                right=mid-1;}
                else left=mid+1;
            }
          
            

            int sum=events[i][2];
            if(ans<n) sum+=best[ans];
         
            maxsum=max(maxsum , sum);


        }

        return maxsum;
           
    }
};