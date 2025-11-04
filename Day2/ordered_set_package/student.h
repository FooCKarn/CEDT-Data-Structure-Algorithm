#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for(auto x:A){
        if(s.find(x)==s.end()){
            v.push_back(x);
            s.insert(x);
        }
    }
    for(auto x:B){
         if(s.find(x)==s.end()){
            v.push_back(x);
            s.insert(x);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s,TmpB;
    for(auto G:B){
        TmpB.insert(G);
    }
    for(auto x:A){
        if(s.find(x)==s.end()&&TmpB.find(x)!=TmpB.end()){
            v.push_back(x);
        }
    }
    return v;
}
