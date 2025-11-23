bool cmp(vector<int>&v1 , vector<int>&v2) {return v1[1]<v2[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       //sort using end point
        int n=points.size();
        int ans=0;
        sort(points.begin() , points.end() , cmp);
        int lastEndEle=points[0][1];
        for(int i=1;i<n;i++){
            if(lastEndEle>=points[i][0]){
                //overlap
                ans++;
                
            }
            else{
                lastEndEle=points[i][1];
            }

        }

 return n-ans;
        
    }
};