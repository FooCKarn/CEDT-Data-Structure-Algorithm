#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT,MappedT,CompareT>
CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  using Node = typename CP::map_bst<KeyT,MappedT,CompareT>::node;
  auto rec = [&](auto&& self, Node* r) -> std::pair<Node*,Node*> {
    if (!r) return {nullptr, nullptr};

    if (mLess(r->data.first, val)) {                  
      auto [L2, R] = self(self, r->right);
      r->right = L2;
      if (r->right) r->right->parent = r;
      r->parent = nullptr;
      return {r, R};
    } else {                                          
      auto [L, R2] = self(self, r->left);
      r->left = R2;
      if (r->left) r->left->parent = r;
      r->parent = nullptr;
      return {L, r};
    }
  };

  auto [L, R] = rec(rec, mRoot);

  CP::map_bst<KeyT,MappedT,CompareT> result;
  mRoot = L;
  if (mRoot) mRoot->parent = nullptr;

  result.mRoot = R;
  if (result.mRoot) result.mRoot->parent = nullptr;

  return result;
}

#endif
