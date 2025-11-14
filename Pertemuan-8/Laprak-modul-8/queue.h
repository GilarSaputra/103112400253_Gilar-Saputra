#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;
struct Queue {
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmpetyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue &Q);

#endif