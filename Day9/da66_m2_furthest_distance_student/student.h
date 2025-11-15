#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	if(n == nullptr) return -1;
    int lh = my_recur(n->left,aux);
    int rh = my_recur(n->right,aux);
    int path = lh + rh+2;
    aux = std::max(path,aux);
    return 1 + std::max(lh,rh);
	
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	if(mRoot == nullptr) return -1;
	int mx = 0;
    my_recur(mRoot,mx);
    return mx;
}

#endif
