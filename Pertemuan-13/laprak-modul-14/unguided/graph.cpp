#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    
    while (P != NULL) {
        if (P->info == X) {
            return;
        }
        P = P->Next;
    }
    
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        newNode->Next = G.first;
        G.first = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2) {
    adrEdge edge1 = new ElmEdge;
    edge1->Node = N2;
    edge1->Next = N1->firstEdge;
    N1->firstEdge = edge1;
    
    adrEdge edge2 = new ElmEdge;
    edge2->Node = N1;
    edge2->Next = N2->firstEdge;
    N2->firstEdge = edge2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "Tidak terhubung";
        } else {
            while (E != NULL) {
                cout << E->Node->info;
                if (E->Next != NULL) {
                    cout << ", ";
                }
                E = E->Next;
            }
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
        
    stack<adrNode> st;
    st.push(N);
    
    while (!st.empty()) {
        adrNode current = st.top();
        st.pop();
        
        if (current->visited == 0) {
            cout << current->info << " ";
            current->visited = 1;
            
            adrEdge E = current->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    st.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
        
    queue<adrNode> q;
    N->visited = 1;
    q.push(N);
    
    while (!q.empty()) {
        adrNode current = q.front();
        q.pop();
        cout << current->info << " ";
        
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}