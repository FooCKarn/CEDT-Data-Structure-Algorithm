#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  for(int i = 0;i<pos.size();i++){
    erase(begin() + pos[i]-i);
  }
}

#endif
