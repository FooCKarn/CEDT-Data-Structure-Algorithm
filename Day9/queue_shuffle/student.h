#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	size_t newCap = mSize + items.size();
	T* newData = new T[newCap]();
	size_t idx = pos;
	size_t l = items.size();
	size_t idx1 = pos, idx2 = 0;
	for(int i = 0;i<pos;i++){
		size_t tmp = (mFront+i)%mCap;
		newData[i] = mData[tmp];
	}
	while(idx1<mSize||idx2<l){
		if(idx2<l) {
			newData[idx++] = items[idx2++];
		}
		if(idx1<mSize) {
			size_t tmp1 = (mFront+idx1)%mCap;
			newData[idx++] = mData[tmp1];
			idx1++;
		}
	}
	delete [] mData;
	mData = newData;
	mSize = newCap;
	mCap = newCap;
	mFront = 0;
}

#endif
