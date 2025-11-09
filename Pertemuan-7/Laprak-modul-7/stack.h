#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack {
    int info[20];
    int top;
};

// Soal 1
void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Soal 2
void pushAscending(Stack &S, int x);

// Soal 3
void getInputStream(Stack &S);

#endif