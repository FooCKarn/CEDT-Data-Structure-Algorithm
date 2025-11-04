#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
      size_t pos = position - begin();
      size_t len = last - first;
      ensureCapacity(mSize + len);
      for(size_t i = mSize;i > pos;i--) {
        mData[i + len - 1 ] = mData[i-1];
      }
      for(size_t i = 0 ;i<len;i++){
        mData[pos+i] = *(first+i);
      }
      mSize += len;
}

#endif
