class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>v1(2);
        vector<int>v2(2);
        v1=edges[0];
        v2=edges[1];
        for(int i=0;i<2;i++){
            if(v1[0]==v2[i]) return v1[0];

        }

       return v1[1];
    }
};