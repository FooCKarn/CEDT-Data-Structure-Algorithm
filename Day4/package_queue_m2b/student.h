#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    if (pos >= mSize) return;
    if (pos == 0) return;

    size_t idx = (mFront + pos) % mCap;
    T tmp = mData[idx];

    for (size_t k = pos; k > 0; k--) {
        size_t cur = (mFront + k) % mCap;
        size_t prev = (mFront + k - 1) % mCap;
        mData[cur] = mData[prev];
    }

    mData[mFront] = tmp;
}


#endif
