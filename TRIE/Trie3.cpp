code link : https
    : // www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=SUBMISSION

      code :

#include <bits/stdc++.h>

    class Trie {
  Trie *child[26];
  bool isEnd;

public:
  Trie() {
    for (int i = 0; i < 26; i++)
      child[i] = nullptr;
    isEnd = false;
  }

  void insert(string &word) {
    Trie *node = this;
    for (char &ch : word) {
      if (node->child[ch - 'a'] == nullptr) {
        node->child[ch - 'a'] = new Trie();
      }
      node = node->child[ch - 'a'];
    }
    node->isEnd = true;
  }

  bool checkComplete(string &word) {
    Trie *node = this;

    for (char &ch : word) {
      if (node->child[ch - 'a'] != nullptr) {
        node = node->child[ch - 'a'];
        if (node->isEnd == false)
          return false;
      } else
        return false;
    }
    return true;
  }
};

string completeString(int n, vector<string> &a) {
  // Write your code here.
  Trie tr;
  for (string &s : a)
    tr.insert(s);

  string ans = "";
  int mx = 0;
  for (string &s : a) {
    if (tr.checkComplete(s)) {
      int len = s.length();
      if (len > mx) {
        mx = len;
        ans = s;
      } else if (len == mx && s < ans) {
        ans = s;
      }
    }
  }
  if (ans == "")
    return "None";
  return ans;
}