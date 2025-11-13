//brute force approach


class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int prev=0;
        while(true){
            for(int i=0;i<s.size()-1;i++){
                if(s[i]=='1' && s[i+1]=='0'){
                    int j=i+1;
                    while(j<s.size() && s[j]!='1'){
                        j++;
                    }
                    if(j<s.size()){
                        s[j-1]='1';
                        s[i]='0';
                    }else{
                        s[s.size()-1]='1';
                        s[i]='0';
                    }
                    prev++;
                }
            }
            if(prev>ans){
                ans=prev;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
//optimized approach
class Solution {
public:
    int maxOperations(string s) {
        int c1=0,ans=0;
        bool flag=true;
        for(auto it:s){
            if(it=='1'){
                c1++;
                flag=false;
            }
            else if(it=='0' && flag==false){
                flag=true;
                ans+=c1;
            }
        }
        return ans;
    }
};