struct Node
{
    bool flag = false;
    
    Node *links[26]; // reference 

    // returns if character exists or not
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL); // 0 -> a, 1 -> b, ... , 25 -> z
    }

    // points the inserted character to its new refrence
    // example: word = apple, 'a' is inserted so, it will point a -> its new reference (trie)
    void put(char ch, Node *dummy)
    {
        links[ch - 'a'] = dummy;
    }

    // return the character's next refrence
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    // once the word is finished, set its last reference flag to true
    void setEnd()
    {
        flag = true;
    }

    // tells the last reference value is true or false
    bool isEnd()
    {
        return flag;
    }
};


class Trie {
private:
    Node *root; // every letter requires a root
public:
 
    // Initialise your data structure
    Trie() 
    {
        // everytime someone calls a constructor, he will create new trie for himself
        root = new Node();        
    }
    
    // Insert a word into the trie
    // TC = O(length of the word)
    void insert(string word) 
    {
        // dummy variable node which is initially pointing to the root
        Node *dummy = root;

        // now we want to insert every character of the word
        for(int i = 0; i < word.size(); i++)
        {
            // first we need to check if the character exists or not
            if(!dummy->containsKey(word[i]))
            {
                // if it does not exists
                // insert it and point it to a new reference
                dummy->put(word[i], new Node());
            }

            // move to the new reference trie
            dummy = dummy->get(word[i]);
        }
        
        // once the word is finished, set its last reference flag to true
        dummy->setEnd();
    }
    

    // Returns if word exists in the trie or not
    // TC = O(length of the word)
    bool search(string word) 
    {
        Node *dummy = root;

        for(int i = 0; i < word.size(); i++)
        {
            // if any character is not present, simply return false
            if(!dummy->containsKey(word[i]))
            {
                return false;
            }

            // if present get that word
            dummy = dummy->get(word[i]);
        }

        // now check if last reference is true or not, it should be true
        return dummy->isEnd();        
    }
    
    // TC = O(length of the word)
    bool startsWith(string word)
    { 
        Node *dummy = root;

        for(int i = 0; i < word.size(); i++)
        {
            // if any character is not present, simply return false
            if(!dummy->containsKey(word[i]))
            {
                return false;
            }

            // if present get that word
            dummy = dummy->get(word[i]);
        }

        // since the word is present simply return true
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
