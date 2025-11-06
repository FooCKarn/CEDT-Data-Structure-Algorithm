#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
    if (pos >= mSize) return;         
    if (pos == mSize - 1) return;   

   
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
