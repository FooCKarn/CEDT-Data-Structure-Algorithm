#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(!n) return 0;
  return 1+process(n->left)+process(n->right);
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  std::pair<KeyT,MappedT> ret = mRoot->data;  
  left.clear();
  right.clear();
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  if(left.mRoot) left.mRoot->parent = nullptr;
  if(right.mRoot) right.mRoot->parent = nullptr;
  left.mSize = process(left.mRoot);
  right.mSize = process(right.mRoot);
  mRoot->right = nullptr;
  mRoot->left = nullptr;
  mSize = 1;
  return ret;
}

#endif

