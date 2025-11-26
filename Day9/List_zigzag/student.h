
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    if(ls.mSize==0) return;
    node* p1 = mHeader->next;
    node* p2 = ls.mHeader->next;
    while(p2!=ls.mHeader){
        if(p1==mHeader) break;
        node* next_p1 = p1->next;
        node* next_p2 = p2->next;
        p1->next = p2;
        p2->prev = p1;
        p2->next = next_p1;
        next_p1->prev = p2;
        p1 = next_p1;
        p2 = next_p2;
    }
    if(p2!=ls.mHeader){
        mHeader->prev->next = p2;
        p2->prev =  mHeader->prev;
        node* ls_last = ls.mHeader->prev;
        ls_last->next = mHeader;
        mHeader->prev = ls_last;
    }
    mSize += ls.mSize;
    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;
    ls.mSize = 0;
    
}

#endif
