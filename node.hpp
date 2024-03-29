#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
  bool isNode;
  map<char, Node*> children;
  Node(): isNode(false) {}
  ~Node()
  {
    for(auto itr = children.begin(); itr != children.end(); itr++)
    {
      delete itr->second;
    }
  }
  bool insert(int position, string value)
  {
    if(position == value.length())
    {
      if(isNode){return false;}
      isNode = true;
      return true;
    }
    Node** temp = &(children[value[position]]);
    if(!(*temp))
    {
      *temp = new Node;
    }
    return (*temp)->insert(position+1, value);
  }
  Node* search(string word, int position)
  {
    if(position == word.length())
    {
      return this;
    }
    Node **temp = &(children[word[position]]);
    if(!(*temp))
    {
      return nullptr;
    }
    return (*temp)->search(word, position+1);
  }
  void delet(string value, int position)
  {
    if(position == value.length())
    {
      return;
    }
    Node** temp = &(children[value[position]]);
    if(!(*temp))
    {
      return;
    }
    (*temp)->delet(value, position+1);
    if((*temp)->children.empty())
    {
      delete *temp;
      *temp = nullptr;
    }
    else
    {
      (*temp)->isNode = false;
    }
  }
  void print(vector<char> &values, int lev, int exp)
  {
    if(lev == exp)
    {
      for(auto it = children.begin(); it != children.end(); it++)
      {
        values.push_back(it->first);
      }
      return;
    }
    for(auto it = children.begin(); it != children.end(); it++)
    {
      if(it->second)
      {
        it->second->print(values, lev+1, exp);
      }
    }
  }
  void printwds(vector<char> &vals)
  {
    for(auto it = children.begin(); it !=  children.end(); it++)
    {
      if(it->second)
      {
        vals.push_back(it->first);
        if(it->second->isNode)
        {
          for(char &i : vals)
          {
            cout << i;
          }
          cout << endl;
        }
        it->second->printwds(vals);
        vals.pop_back();
      }
    }
  }
  friend class Trie;
};

#endif
