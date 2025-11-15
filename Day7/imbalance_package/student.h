int dfs(node* n, int &bestImb, KeyT &bestKey) const {
  if (!n) return -1;               
  int lh = dfs(n->left,  bestImb, bestKey);
  int rh = dfs(n->right, bestImb, bestKey);
  int imb = (lh > rh ? lh - rh : rh - lh);  
  const KeyT &k = n->data.first;
  if (imb > bestImb || (imb == bestImb && mLess(k, bestKey))) {
    bestImb = imb;
    bestKey = k;
  }
  return (lh > rh ? lh : rh) + 1;    
}

KeyT getValueOfMostImbalanceNode() const {
  KeyT bestKey = mRoot->data.first;
  int  bestImb = -1;
  dfs(mRoot, bestImb, bestKey);
  return bestKey;
}
