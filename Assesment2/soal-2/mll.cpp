#include "MLL.h"

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = nullptr;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = nullptr;
}

NodeParent alokasiNodeParent(string idGenre, string namaGenre, string deskripsi) {
    NodeParent newNodeParent = new nodeParent;
    newNodeParent->isidata.idGenre = idGenre;
    newNodeParent->isidata.namaGenre = namaGenre;
    newNodeParent->isidata.deskripsi = deskripsi;
    newNodeParent->next = nullptr;
    newNodeParent->prev = nullptr;
    createListAnak(newNodeParent->L_Anak);
    return newNodeParent;
}

NodeChild alokasiNodeChild(string idFilm, string judulFilm, int durasi, int tahun, float rating) {
    NodeChild newNodeChild = new nodeChild;
    newNodeChild->isidata.idFilm = idFilm;
    newNodeChild->isidata.judulFilm = judulFilm;
    newNodeChild->isidata.durasiFilm = durasi;
    newNodeChild->isidata.tahunTerbit = tahun;
    newNodeChild->isidata.ratingFilm = rating;
    newNodeChild->next = nullptr;
    newNodeChild->prev = nullptr;
    return newNodeChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if (LInduk.first == nullptr) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if (LAnak.first == nullptr) {
        LAnak.first = LAnak.last =  nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev) {
    if (nodePrev == nullptr || nodePrev->next == nullptr) return;
    
    NodeParent nodeToDelete = nodePrev->next;
    
    if (nodeToDelete == LInduk.last) {
        LInduk.last = nodePrev;
        nodePrev->next = nullptr;
    } else {
        nodePrev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodePrev;
    }
    
    dealokasiNodeParent(nodeToDelete);
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild current = LAnak.first;
    while (current != nullptr) {
        NodeChild nextNode = current->next;
        dealokasiNodeChild(current);
        current = nextNode;
    }
    LAnak.first = nullptr;
    LAnak.last = nullptr;
}

void searchFilmByRatingRange(listInduk &LInduk, float minRating, float maxRating) {
    if (LInduk.first == nullptr) {
        cout << "List induk kosong!" << endl;
        return;
    }
    
    bool found = false;
    NodeParent currentParent = LInduk.first;
    int parentPosition = 1;
    
    while (currentParent != nullptr) {
        NodeChild currentChild = currentParent->L_Anak.first;
        int childPosition = 1;
        
        while (currentChild != nullptr) {
            float rating = currentChild->isidata.ratingFilm;
            if (rating >= minRating && rating <= maxRating) {
                found = true;
                cout << "\nData Film ditemukan pada list child dari node parent " << currentParent->isidata.namaGenre << " pada posisi ke-" << childPosition << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << currentChild->isidata.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << childPosition << endl;
                cout << "ID Film : " << currentChild->isidata.idFilm << endl;
                cout << "Durasi Film : " << currentChild->isidata.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << currentChild->isidata.tahunTerbit << endl;
                cout << "Rating Film : " << currentChild->isidata.ratingFilm << endl;
                cout << "---------------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << currentParent->isidata.idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << parentPosition << endl;
                cout << "Nama Genre : " << currentParent->isidata.namaGenre << endl;
                cout << "=================================" << endl;
            }
            currentChild = currentChild->next;
            childPosition++;
        }
        currentParent = currentParent->next;
        parentPosition++;
    }
    
    if (!found) {
        cout << "Tidak ditemukan film dengan rating antara " << minRating << " - " << maxRating << endl;
    }
}
void printStrukturMLL(listInduk &LInduk) {
    if (LInduk.first == nullptr) {
        cout << "Struktur MLL kosong!" << endl;
        return;
    }
    
    NodeParent currentParent = LInduk.first;
    int parentCount = 1;
    
    while (currentParent != nullptr) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Genre : " << currentParent->isidata.idGenre << endl;
        cout << "Nama Genre : " << currentParent->isidata.namaGenre << endl;
        
        NodeChild currentChild = currentParent->L_Anak.first;
        int childCount = 1;

        while (currentChild != nullptr) {
            cout << "- Child " << childCount << " :" << endl;
            cout << "    ID Film : " << currentChild->isidata.idFilm << endl;
            cout << "    Judul Film : " << currentChild->isidata.judulFilm << endl;
            cout << "    Durasi Film : " << currentChild->isidata.durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << currentChild->isidata.tahunTerbit << endl;
            cout << "    Rating Film : " << currentChild->isidata.ratingFilm << endl;
            
            currentChild = currentChild->next;
            childCount++;

            cout << "---------------------------" << endl;
        }
        
        cout << endl;
        currentParent = currentParent->next;
        parentCount++;
    }
}