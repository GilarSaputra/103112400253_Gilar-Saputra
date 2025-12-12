#include <iostream>
using namespace std;
#include "graph.h"

int main() {
    Graph G; 
    CreateGraph(G);
    
    InsertNode(G, 'H');
    InsertNode(G, 'G');
    InsertNode(G, 'F');
    InsertNode(G, 'E');
    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');
    
    adrNode nodeA = G.first;
    adrNode nodeB = G.first->Next;
    adrNode nodeC = G.first->Next->Next;
    adrNode nodeD = G.first->Next->Next->Next;
    adrNode nodeE = G.first->Next->Next->Next->Next;
    adrNode nodeF = G.first->Next->Next->Next->Next->Next;
    adrNode nodeG = G.first->Next->Next->Next->Next->Next->Next;
    adrNode nodeH = G.first->Next->Next->Next->Next->Next->Next->Next;

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeB, nodeE);
    ConnectNode(nodeC, nodeF);
    ConnectNode(nodeC, nodeG);
    ConnectNode(nodeD, nodeH);
    ConnectNode(nodeE, nodeH);
    ConnectNode(nodeF, nodeH);
    ConnectNode(nodeG, nodeH);
    
    cout << "=== Graph ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Print DFS ===" << endl;
    PrintDFS(G, nodeA);
    
    cout << "=== Print BFS ===" << endl;
    PrintBFS(G, nodeA);
    return 0;
}