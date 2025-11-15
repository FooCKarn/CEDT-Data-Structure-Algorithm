#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(!ptr) return 0;
  size_t L = process(ptr->left);
  size_t R = process(ptr->right);
  size_t S = ((ptr->left == nullptr) ^ (ptr->right==nullptr))? 1:0;
  return S+L+R;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
  return 0;
}

#endif
