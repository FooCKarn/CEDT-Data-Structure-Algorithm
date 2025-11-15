#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> tmp;
    while(!a.empty()){
        std::vector<std::queue<int>> &vec = a.top();
        for(auto &q:vec){
            for(size_t i = 0;i<q.size();i++){
                int val = q.front();
                q.pop();
                if(val==from) val = to;
                q.push(val);
            }
        }
        tmp.push(a.top());a.pop();
    }
    while(!tmp.empty()){
        a.push(tmp.top());tmp.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for(auto &p:a){
         std::pair<std::priority_queue<int>, int> &val = p.second;
         if(val.second == from){
            val.second = to;
         }
         std::priority_queue<int> &pq = val.first;
         std::priority_queue<int> tmp;
         while(!pq.empty()){
            int k = pq.top();pq.pop();
            if(k==from) k = to;
            tmp.push(k);
         }
         pq.swap(tmp);
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmp;
    for(const auto &x:a){
        auto newl = x;
        for(auto &lval :newl.first){
            if(lval == from) lval = to;
        }
        std::map<int, std::pair<int, string>> &m = newl.second;
        for(auto &p:m){
            if(p.second.first==from) p.second.first = to;
        }
        auto it = m.find(from);
        if(it!=m.end()){
            auto v = it->second;
            m.erase(it);
            m.insert({to,v});
        }
        tmp.insert(newl);
    }
    a.swap(tmp);
}

#endif
