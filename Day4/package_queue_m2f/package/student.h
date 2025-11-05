#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    size_t idx = (mFront + pos) % mCap;
    for (size_t k = pos; k < mSize - 1; ++k) {
        size_t nxt = (idx + 1) % mCap;
        T tmp = mData[idx];
        mData[idx] = mData[nxt];
        mData[nxt] = tmp;
        idx = nxt;
    }
}

#endif
