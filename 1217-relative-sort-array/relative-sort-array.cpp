class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr2.size();
      map<int , int>m;
        int a=0;
        for(int i=0;i<arr1.size();i++){
            m[arr1[i]]++;
        }
        for(int i=0;i<n;i++){
           if(m.find(arr2[i])!=m.end()){
            while(m[arr2[i]]>0){
                arr1[a]=arr2[i];
                a++;
                m[arr2[i]]--;
            }
            m.erase(arr2[i]);
           }
        }

        if(m.size()>0){
           while(m.size()>0){
             while(m.begin()->second>0){
                arr1[a]=m.begin()->first;
                a++;
                 m.begin()->second--;
            }
             m.erase(m.begin());
           }
        }
        return arr1;
    }
};