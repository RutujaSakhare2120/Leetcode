class Solution {
public:
    int smallestNumber(int n) {
        int m=0;
        if(n==1) return 1;
       while(m<11){
        if(n>=pow(2 , m)) m++;
        else break;
       }
       return pow(2 , m)-1;
        
    }
};