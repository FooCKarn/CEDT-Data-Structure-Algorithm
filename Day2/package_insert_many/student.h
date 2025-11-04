#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>
using namespace std;
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  sort(data.begin(),data.end());
  T *tmp = new T[mSize+data.size()]();
  int i=0,j=0,k=0;
  while(i<mSize||j<data.size()){
    if(j<data.size()&&data[j].first==i){
      tmp[k++] = data[j++].second;
    }
    else{
      tmp[k++] = mData[i++];
    }
  }
  delete [] mData;
  mData = tmp;
  mSize = k;
  mCap = mSize;
}

#endif
