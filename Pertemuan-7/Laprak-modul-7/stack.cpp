#include "stack.h"

void CreateStack(Stack &S){
    S.top = -1;
}

void Push(Stack &S, infotype x){
    S.top++;
    S.info[S.top] = x;
}

infotype Pop(Stack &S){
    if (S.top > -1) {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    } else {
        cout << "Stack Kosong";
        return -1;
    }
}


void printInfo(Stack S){
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i){
        cout << S.info[i] << " ";
    };
    cout << endl;
}

void balikStack(Stack &S){
    Stack temp;
    CreateStack(temp);
    while (S.top >= 0) {
        Push(temp, Pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, int x){
    Stack simpan;
    CreateStack(simpan);

    while (S.top >= 0 && S.info[S.top] > x){
        Push(simpan, Pop(S));
    }
    Push(S, x);
    
    while (simpan.top >= 0){
        Push(S, Pop(simpan));
    }
}

void getInputStream(Stack &S){
    char input;
    
    while (true) {
        input = cin.get();
        if (input == '\n')
            break;
        if (isdigit(input)) { 
            int angka = input - '0';
            Push(S, angka);
        }
    }
}