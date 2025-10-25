// Author Amit Kr. Rai
// Asumming that our trie will take input in small letters [a-z]

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*Assuming alhphabet is [a-z]*/
struct trienode {
  int words;                 // # of words
  int prefixes;              // # of words having this prefix
  struct trienode *ref[26];  // all possible refrences
};

/*Creating Root Node*/
struct trienode *initialize() {
  struct trienode *p;
  p = (struct trienode *)malloc(sizeof(struct trienode));
  p->words = 0;
  p->prefixes = 0;
  for (int i = 0; i < 26; i++) p->ref[i] = NULL;
  return p;
}

/*Adding Words*/
void addwords(struct trienode *root, char *word, int k, int wordlen) {
  if (k == wordlen)
    root->words++;
  else {
    int temp = word[k];
    temp -= 97;
    if (root->ref[temp] == NULL) {
      root->ref[temp] = initialize();
    }
    root->ref[temp]->prefixes++;
    addwords(root->ref[temp], word, k + 1, wordlen);
  }
}

/*Counting Given Word*/
int countwords(struct trienode *root, char *word, int k, int wordlen) {
  if (k == wordlen)
    return root->words;
  else {
    int temp = word[k];
    temp -= 97;
    if (root->ref[temp] == NULL)
      return 0;
    else
      return countwords(root->ref[temp], word, k + 1, wordlen);
  }
}

/*Counting Words Having Same Prefix */
int countprefixes(struct trienode *root, char *prefix, int k, int prefixlen) {
  if (k == prefixlen)
    return root->prefixes;
  else {
    int temp = prefix[k];
    temp -= 97;
    if (root->ref[temp] == NULL)
      return 0;
    else
      return countprefixes(root->ref[temp], prefix, k + 1, prefixlen);
  }
}

int main() {
  struct trienode *root;
  root = initialize();
  addwords(root, "tree", 0, 4);
  addwords(root, "tree", 0, 4);
  addwords(root, "treek", 0, 5);
  addwords(root, "trie", 0, 4);
  // addwords(root,"assoc",0,5);
  // addwords(root,"all",0,3);
  // addwords(root,"algo",0,4);
  // addwords(root,"also",0,4);
  // addwords(root,"also",0,4);
  cout << "Prefix @ Root = " << root->prefixes << "Words @ Root = " << root->words << endl;
  cout << "count tree = " << countwords(root, "tree", 0, 4) << endl;
  cout << "countp tree = " << countprefixes(root, "tree", 0, 4) << endl;
  // cout<<"countp tr = "<<countprefixes(root,"tr",0,2)<<endl;
  // cout<<"countp al = "<<countprefixes(root,"al",0,2)<<endl;
  // cout<<"count = "<<countwords(root,"tree",0,4)<<endl;
  // cout<<"count also = "<<countwords(root,"also",0,4)<<endl;
  return 0;
}
