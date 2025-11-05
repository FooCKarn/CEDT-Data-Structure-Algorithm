#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    T *tmp = new T[b+1];
    for(int i=0;i<=b;i++){
        tmp[i]=(top());
        pop();
    }
    for(int i=b;i>=0;i--){
        if(i>=a) push(tmp[i]);
        push(tmp[i]);
    }
}

#endif