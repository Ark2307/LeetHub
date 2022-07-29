struct TrieNode{
    
    TrieNode *link[26] ;
    bool flag = 0 ;
    
    TrieNode *get(char ch){
        return link[ch - 'a'] ;
    }
    
    void put(char ch){
        link[ch - 'a'] = new TrieNode() ;
    }
    
    bool containsKey(char ch){
        return (link[ch - 'a'] != NULL) ;
    }
    
    void setEnd(){
        flag = 1 ;
    }
    
    bool isEnd(){
        
        return flag ;
        
    }
    
};


class MagicDictionary {

    
public:
    
    TrieNode *root = new TrieNode() ;
    void insert(string &str){

        TrieNode *node = root ;
        for(auto it: str){

            if(!node->containsKey(it)){
                node->put(it) ;
            }
            node = node->get(it) ;
        }

        node->setEnd() ;
    }
    
    void buildDict(vector<string> dictionary) {
        
        delete root ;
        root = new TrieNode() ;
        
        for(auto it : dictionary){
            insert(it) ;
        }
        
    }

    bool recurSol(string str , TrieNode *node , int i , int count , int n){
        if(n == i){
            if(count == 1 && node->isEnd()){
                return 1 ;
            }
            
            return 0 ;
        }
        
        bool res = 0 ;
        for(int j = 0 ; j < 26 ; j++){
            
            if(res)
                break ;
            
            char c = (j + 'a') ;
            
            if((str[i] == c) && (node->containsKey(c)) && count <= 1){
                
                res |= recurSol(str , node->get(c) , i + 1 , count , n) ;
                
            }
            
            else if(str[i] != c && node->containsKey(c) && count == 0){
                
                res |= recurSol(str , node->get(c) , i + 1 , count + 1 , n) ;
                
            }
        }
        return res ;
        
    }
    
    bool search(string searchWord) {
        TrieNode *node = root ;
        int n = searchWord.size() ;
        return recurSol(searchWord , node , 0 , 0 , n) ;
        
    }
};

