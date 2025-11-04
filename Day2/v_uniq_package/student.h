#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<set>
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  std::set<T> s;
  size_t j = 0;
  T *tmp = new T[mSize]();
  for(int i = 0;i<mSize;i++){
    auto x = mData[i];
    if(s.find(x)==s.end()){
      s.insert(x);
      tmp[j++] = x;
    }
  }
  delete [] mData;
    mData = tmp;
    mSize = j;
    mCap = mSize;
}

#endif
