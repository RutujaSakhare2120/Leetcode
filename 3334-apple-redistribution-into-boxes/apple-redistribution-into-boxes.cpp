class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();

        int sumA=0;
        for(int x:apple) sumA+=x;
        int sumC=0;
        for(int x:capacity) sumC+=x;

        if(sumA>sumC) return 0;

      
        sort(capacity.begin() , capacity.end());

     

        int j=m-1;
        int sum=0;
        while(j>=0){

            sum+=capacity[j];
           
            if(sum>=sumA) return m-j;
             j--;

        }


       
        return 0;

  
        
    }
};