class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int , int>mp;
        for(int x: bills){
            mp[x]++;
            if(x==10){
                if(mp[5]==0) return false;
                mp[5]--;
             

            }
            else if(x==20){

                if(mp[10]>0 && mp[5]>0) {
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3){
                    mp[5]--;
                    mp[5]--;
                    mp[5]--;
                }
                else{
                    return false;
                }

            }
        }
        return true;
    }
};