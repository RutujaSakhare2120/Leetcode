class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int , int>m;
        vector<int>ans;

        for(int i=0;i<digits.size();i++){
            m[digits[i]]++;
        }

        for(int i=100 ;i<=999;i+=2){

         int x=i;

         int a=x%10;
         x/=10;
         if(m.find(a)!=m.end()){
            m[a]--;
            if(m[a]==0) m.erase(a);
         }
         else continue;
         int b=x%10;
         x/=10;
         if(m.find(b)!=m.end()){
            m[b]--;
            if(m[b]==0) m.erase(b);
         }
          else {
            m[a]++;
            continue;
          }
         int c=x;
         if(m.find(c)!=m.end()){
            m[c]--;
            if(m[c]==0) m.erase(c);
         }
         else{
            m[a]++;
            m[b]++;
            continue;
         }



         ans.push_back(i);
         m[a]++;
         m[b]++;
         m[c]++;
        


        }
        return ans;
    }
};