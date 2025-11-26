#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<algorithm>
// you can also include anything else here

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  size_t sz = queries.size();
  std::vector<size_t> r;
  std::vector<int> tmp;
  for(auto x : data){
    tmp.push_back(x.second);
  }
  std::sort(tmp.begin(),tmp.end());
  for(auto x : queries){
    int it1 = std::lower_bound(tmp.begin(),tmp.end(),x.first) - tmp.begin();
    int it2 = std::upper_bound(tmp.begin(),tmp.end(),x.second) - tmp.begin();
    r.push_back(it2-it1);
  }
  
  return r;
}

#endif