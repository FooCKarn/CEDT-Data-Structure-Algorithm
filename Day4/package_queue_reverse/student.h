#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
      int len = b - a + 1;
      for (int i = 0; i < len / 2; ++i) {
          size_t l = (mFront + a + i) % mCap;
          size_t r = (mFront + b - i) % mCap;
          T tmp = mData[l];
          mData[l] = mData[r];
          mData[r] = tmp;
      }

}

#endif
