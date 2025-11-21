  bool cmp(vector<int> &v1 , vector<int> &v2){
        if(v1[1]!=v2[1])
            //ascending
            return v1[1]<v2[1];
        //sort in desce
        return v1[0]>v2[0];    
        
    }
class Solution {
public:
  
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin() , intervals.end() , cmp);

        int first=-1;
        int second=-1;
        int result=0;
        for(int i=0;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];


            if(l<=first) continue;
            if(l>second){
                first=r-1;
                second=r;
                result+=2;
            }
            else{
                first=second;
                result+=1;
                second=r;
            }

        }
        return result;
        
    }
};