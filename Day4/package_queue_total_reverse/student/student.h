#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"


template <typename T>
void CP::queue<T>::reverse() {
  aux != aux;
}

template <typename T>
const T& CP::queue<T>::front() const {
  return mData[ aux ? (mFront + mSize - 1) % mCap : mFront ];
}

template <typename T>
const T& CP::queue<T>::back() const {
  return mData[ aux ? mFront : (mFront + mSize - 1) % mCap ];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  if (!aux) {
    mData[(mFront + mSize) % mCap] = element;
  } else {
    mFront = (mFront + mCap - 1) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  if (!aux) {
    mFront = (mFront + 1) % mCap;
  } else {
  }
  mSize--;
}

#endif
