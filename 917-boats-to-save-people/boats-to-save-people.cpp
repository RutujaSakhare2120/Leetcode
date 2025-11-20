class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int count=0;
        sort(people.begin(), people.end(), greater<int>());

        int i=0;
        int j=n-1;
        while(i<=j){
             if(i==j && people[i]<=limit) {count++; break;}
            if(people[i]==limit) count++;
            else if(people[i]<limit){
                 if(people[i]+people[j]<=limit) {count++;
                 j--;}

                 else if(people[i]<limit) count++;
            }
            
           
            i++;
        }
       return count;
        
    }
};