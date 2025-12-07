#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, P1);
    insertLastParent(LParent, P2);
    insertLastParent(LParent, P3);
    insertLastParent(LParent, P4);
    insertLastParent(LParent, P5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1);
    insertLastChild(P1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C3);
    insertLastChild(P2->L_Child, C4);
    insertLastChild(P2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C6);

    cout << "=== Struktur Multi Linked List Setelah INSERT ===" << endl;
    printMLLStructure(LParent);

    cout << endl;
    // searchHewanByEkor(LParent, false);

    // NodeParent temp = LParent.first;
    // while (temp != NULL && temp->next != NULL) {
    //     if (temp->next->isidata.idGolongan == "G004") {
    //         deleteAfterParent(LParent, temp);
    //         break;
    //     }
    //     temp = temp->next;
    // }

    cout << "\n=== Struktur Multi Linked List Setelah DELETE G004 ===" << endl;
    printMLLStructure(LParent);

    return 0;
}