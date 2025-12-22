
// insert
// check
// starts with

class Trie {
private:
  Node *root;

public:
  // Initilize trie
  Trie() { root = new Node(); }

  // Insert a new word into the trie
  void insert(string word) {
    Node *node = root;

    for (int i = 0; i < word.length(); i++) {
      // if not contains a character , add it
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      // move to next node
      node = node->get(word[i]);
    }
    // After traversing all nodes , set end
    node->setEnd();
  }

  // Check if the word is in the trie or not
  bool search(string word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      // if not contains return false
      if (!node->containsKey(word[i])) {
        return false;
      }
      // move to next node
      node = node->get(word[i]);
    }
    // check if last node,marks end of word
    return node->isEnd();
  }

  // Check if there is any word in the trie that starts with the given prefix
  bool startsWith(string prefix) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      // if not contains return false
      if (!node->containsKey(word[i])) {
        return false;
      }
      // move to next node
      node = node->get(word[i]);
    }
    // The prefix is found in the Trie
    return true;
  }
};

// struct Node for Trie
struct Node {
  // Array to store  links to child node
  Node *links[26];
  bool flag = false;

  bool containsKey(char ch) {
                                return links[ch-'a']!=NULL);
  }

  void put(char ch, Node *node) {
    // links[ch-'a']=node;
    links[ch - 'a'] = node;
  }

  Node *get(char ch) { return links[ch - 'a']; }

  void setEnd() { flag = true; }

  void isEnd() { return flag; }
};

// what is a Trie Data structure

//	Short code -> nisritha github code

code link : https
    : // www.naukri.com/code360/problems/implement-trie_631356?leftPanelTabValue=SUBMISSION

      with only one class

      /*
                      Your Trie object will be instantiated and called as such:
                      Trie* obj = new Trie();
                      obj->insert(word);
                      bool check2 = obj->search(word);
                      bool check3 = obj->startsWith(prefix);
       */

      class Trie {

public:
  Trie *child[26];
  int count;
  bool isEnd;

  /** Initialize your data structure here. */
  Trie() {
    for (int i = 0; i < 26; i++)
      child[i] = nullptr;
    count = 0;
    isEnd = false;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie *node = this;
    for (char &ch : word) {
      if (!node->(ch)) {
        node->put(ch, new Trie());
      }
      node = node->get(ch);
    }
    node->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie *node = this;
    for (char &ch : word) {
      if (!node->containsKey(ch)) {
        return false;
      }
      node = node->get(ch);
    }
    return node->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie *node = this;
    for (char &ch : prefix) {
      if (!node->containsKey(ch)) {
        return false;
      }
      node = node->get(ch);
    }
    return true;
  }

  bool containsKey(char ch) { return child[ch - 'a'] != nullptr; }

  void put(char ch, Trie *node) { child[ch - 'a'] = node; }

  Trie *get(char ch) { return child[ch - 'a']; }
};