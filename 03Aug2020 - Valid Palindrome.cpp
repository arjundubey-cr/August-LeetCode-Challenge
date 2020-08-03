class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        if(n==0) return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i=0,j=n-1;
        while(i<n && j>=0){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else{
                if(s[i]!=s[j]) return false;
                else{
                    i++;j--;
                }
            }
        }
        return true;
    }
};
