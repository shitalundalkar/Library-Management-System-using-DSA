#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    vector<string> bookTitles;

    TrieNode();
};

class TitleTrie {
public:
    TrieNode* root;
    TitleTrie();
    void insert(string title);
    void searchPrefix(string prefix);
};

#endif
