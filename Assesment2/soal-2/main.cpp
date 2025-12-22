#include "MLL.h"

int main() {
    listInduk LInduk;
    createListInduk(LInduk);
    
    cout << "=== SISTEM MANAJEMEN FILM BIOSKOP ===\n" << endl;
    NodeParent genre1 = alokasiNodeParent("G001", "Action", "Film aksi dan petualangan");
    NodeParent genre2 = alokasiNodeParent("G002", "Comedy", "Film lucu dan komedi");
    NodeParent genre3 = alokasiNodeParent("G003", "Horror", "Film horor dan misteri");
    NodeParent genre4 = alokasiNodeParent("G004", "Romance", "Film romantis");
    
    insertFirstParent(LInduk, genre4);
    insertFirstParent(LInduk, genre3);
    insertFirstParent(LInduk, genre2);
    insertFirstParent(LInduk, genre1);
    
    NodeChild film1 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(genre1->L_Anak, film1);

    NodeChild film2 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(genre2->L_Anak, film2);
    NodeChild film3 = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(genre2->L_Anak, film3);
    
    NodeChild film4 = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(genre3->L_Anak, film4);
    
    NodeChild film5 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(genre4->L_Anak, film5);
    NodeChild film6 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(genre4->L_Anak, film6);
        
    cout << "\n=== PRINT STRUKTUR MLL ===" << endl;
    printStrukturMLL(LInduk);
    
    cout << "\n=== SEARCH FILM BY RATING RANGE ===" << endl;
    searchFilmByRatingRange(LInduk, 8.0, 8.5);
    
    cout << "\n=== DELETE AFTER PARENT (Horror) ===" << endl;
    NodeParent current = LInduk.first;
    NodeParent horrorNode = nullptr;
    while (current != nullptr) {
        if (current->isidata.namaGenre == "Horror") {
            horrorNode = current;
            break;
        }
        current = current->next;
    }
    
    if (horrorNode != nullptr) {
        deleteAfterParent(LInduk, horrorNode);
        printStrukturMLL(LInduk);
    }
        
    return 0;
}