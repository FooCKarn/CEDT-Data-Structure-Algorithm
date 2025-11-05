#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  size_t pos = idx >= 0 ?(mFront+idx)%mCap:(mFront+mSize+idx)%mCap;
  T k = mData[pos];
  return  k;
}

#endif
