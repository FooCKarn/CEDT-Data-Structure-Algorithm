#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  std::vector<bool> chk(mSize,false);
  for(size_t i = 0;i<pos.size();i++){
    chk[pos[i]] = true;
  }
  size_t write_idx = 0;
  for(size_t read_idx = 0;read_idx<mSize;read_idx++){
    if(!chk[read_idx]){
      if(read_idx!=write_idx){
        size_t pos_write = (mFront+write_idx)%mCap;
        size_t pos_read = (mFront+read_idx)%mCap;
        mData[pos_write] = mData[pos_read];
      }
      write_idx++;
      }
    }
    mSize = write_idx;
}

#endif
