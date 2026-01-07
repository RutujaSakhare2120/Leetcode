class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        int n=chars.size();
       int i=0;
        while(i<n){
            char ch=chars[i];
            int count=0;
            while(i<n && chars[i]==ch ){
                count++;
                i++;
            }

            if(count==1){
             chars[idx++]=ch;
            }
            else if(count>1){
              chars[idx++]=ch;
              string c=to_string(count);
              for(char a:c){
                chars[idx++]=a;
              }

            }
        }

        chars.resize(idx);

        return idx;
    }
};