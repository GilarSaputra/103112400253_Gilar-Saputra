#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    GraphKota G;
    createGraph(G);
    
    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bekasi");
        
    connectNode(G, "Jakarta", "Tangerang", 24);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Bogor", 42);
    
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Bogor", "Jakarta", 42);
    
    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Depok", "Bogor", 22);
    connectNode(G, "Depok", "Jakarta", 21);
    
    connectNode(G, "Tangerang", "Depok", 30);
    connectNode(G, "Tangerang", "Bekasi", 45);
    connectNode(G, "Tangerang", "Jakarta", 24);

    connectNode(G, "Bekasi", "Depok", 25);
    connectNode(G, "Bekasi", "Tangerang", 45);
    connectNode(G, "Bekasi", "Bogor", 60);
    connectNode(G, "Bekasi", "Jakarta", 16);
    
    cout << "\n REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    cout << endl;
    
    adrKota current = G.First;
    while (current != nullptr) {
        cout << "Node " << current->namaKota << " terhubung ke: ";
        adrEdge edge = current->firstEdge;
        bool first = true;
        while (edge != nullptr) {
            if (!first) {
                cout << ", ";
            }
            cout << edge->kotaTujuan->namaKota << "(" << edge->jarak << " KM)";
            edge = edge->next;
            first = false;
        }
        cout << "," << endl;
        current = current->next;
    }
        
    return 0;
}