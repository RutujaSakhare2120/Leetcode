class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());
       int minDiff=INT_MAX;
        for(int i=0;i<n-1;i++){
           minDiff=min(minDiff , (arr[i+1]-arr[i]));
        }

        for(int i=0;i<n-1;i++){
            if((arr[i+1]-arr[i])==minDiff){
                vector<int>v(2);
                v[0]=arr[i];
                v[1]=arr[i+1];
                ans.push_back(v);
            }
        }
        return ans;
        
    }
};