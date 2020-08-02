class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if(word.length()==1)
            return true;
        
        vector<int> store;
        
        for(int i=0;i<word.length();i++)
        {
           if(word[i]>='A' && word[i]<='Z')
               store.push_back(i);
        }
        
        if(store.size()==0)
            return true;
        
        if(store[0]!=0)
            return false;
        else if(store.size()==word.length()||store.size()==1)
            return true;
        
        return false;
    }
};
