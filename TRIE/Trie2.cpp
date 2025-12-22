//raw code without any functions
code link: https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=SUBMISSION

code:
#include <bits/stdc++.h> 
class Trie{

    public:
    Trie* child[26];
    int endCnt;
    int prefixCnt;

    Trie(){
        // Write your code here.
        for(int i=0;i<26;i++)child[i]=nullptr;
        endCnt=0;
        prefixCnt=0;
    }

    void insert(string &word){
        // Write your code here.
        Trie* node=this;
        for(char &ch:word){
            if(node->child[ch-'a']==nullptr){
                node->child[ch-'a']=new Trie();
            }
            node=node->child[ch-'a'];
            node->prefixCnt++;
        }
        node->endCnt++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Trie* node=this;
        for(char &ch:word){
            if(node->child[ch-'a']==nullptr){
                return 0;
            }
            node=node->child[ch-'a'];
        }
        return node->endCnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Trie* node=this;
        for(char &ch:word){
            if(node->child[ch-'a']==nullptr){
                return 0;
            }
            node=node->child[ch-'a'];
        }
        return node->prefixCnt;
    }

    void erase(string &word){
        // Write your code here.
        Trie* node=this;
        for(char &ch:word){
            if(node->child[ch-'a']==nullptr){
                return;
            }
            node=node->child[ch-'a'];
            node->prefixCnt--;
        }
        node->endCnt--;
    }
};
