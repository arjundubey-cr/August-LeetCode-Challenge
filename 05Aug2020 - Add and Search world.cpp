class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
    TrieNode *root;
    
    void addWordToTrie(string word) {
        auto cur = root;
        
        for (auto ch : word) {
            if (!cur->children.count(ch))
                cur->children[ch] = new TrieNode();
            
            cur = cur->children[ch];
        }
        
        cur->isWord = true;
    }
    
    bool searchTrie(TrieNode* cur, int i, string word) {
        if (i == word.length())
            return cur->isWord;
        
        if (word[i] != '.') {
			// normal letter
            if (!cur->children.count(word[i]))
                return false;

            return searchTrie(cur->children[word[i]], i + 1, word);   
        }
        
        for (auto it : cur->children) {
            if (searchTrie(it.second, i + 1, word))
                return true;               
        }
        
        return false;
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        addWordToTrie(word);
    }
    
    bool search(string word) {
        return searchTrie(root, 0, word);
    }
};
