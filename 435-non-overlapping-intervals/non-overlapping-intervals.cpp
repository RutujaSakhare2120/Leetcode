bool cmp(vector<int>&v1 , vector<int>&v2) {return v1[0]<v2[0];}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort using first point
        int n=intervals.size();
        int ans=0;
        sort(intervals.begin() , intervals.end() , cmp);
        int lastEndEle=intervals[0][1];
        for(int i=1;i<n;i++){
            if(lastEndEle>intervals[i][0]){
                //overlap
                ans++;
                lastEndEle=min(lastEndEle , intervals[i][1]);
            }
            else{
                lastEndEle=intervals[i][1];
            }

        }

 return ans;

        
    }
};