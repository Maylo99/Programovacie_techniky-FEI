//Meno a priezvisko: Michal Hájek 104463

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//--------------------------------------------------------------------------------------------------
//POMOCNE FUNKCIE:
//--------------------------------------------------------------------------------------------------
void printList(const List* list) {
    Node* tmp = list->first;
    while (tmp) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

Node* createNode(const int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na zaciatok zoznamu

    PRIKLADY:
        list={} a val=0 ... zoznam po vykonani funkcie ... {0}
        list={-3} a val=1 ... zoznam po vykonani funkcie ... {1,-3}
        list={6,6,6,8} a val=10 ... zoznam po vykonani funkcie ... {10,6,6,6,8}
*/

void prependNode(List* list, const int val) {
    Node* n_Node = new Node;
    n_Node->data = val;
    n_Node->next = list->first;
    list->first = n_Node;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na koniec zoznamu

    PRIKLADY:
        list={} a val=7 ... zoznam po vykonani funkcie ... {7}
        list={0} a val=1 ... zoznam po vykonani funkcie ... {0,1}
        list={1,2,3,4,5} a val=6 ... zoznam po vykonani funkcie ... {1,2,3,4,5,6}
*/

void appendNode(List* list, const int val) {
    Node* n_Node = new Node;
    n_Node->next = nullptr;
    n_Node->data = val;
    //musi skoncit na poslednom uzle nie za ním!
    if (list->first == nullptr)//ak je zoznam prazdny
    {
        list->first = n_Node;
    }
    else
    {
        Node* tmp = list->first;
        while (tmp->next)//zarucim ze bude ukazovat na posledny uzol
        {
            tmp = tmp->next;
        }
        tmp->next = n_Node;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),
    ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.

    PARAMETRE:
        [in] data - vstupne pole cisiel
        [in] n - dlzka vstupneho pola

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci vsetky hodnoty zo vstupneho pola 'data' (v zachovanom poradi).
        V pripade prazdneho pola (dlzka 0), funkcia vrati prazdny zoznam (prazdny zoznam je taky, kde smernik 'first'
        ukazuje na 'nullptr'). V pripade neplatnej dlzky (ak je parameter 'n' zaporny), funkcia vrati 'nullptr'.

    PRIKLADY:
        data={1} a n=1 ... vrati zoznam ... {1}
        data={7,6,41,2} a n=4 ... vrati zoznam ... {7,6,41,2}
        data={3,2,1} a n=0 ... vrati zoznam ... {}
        data={6,3,9,10} a n=-7 ... vrati ... 'nullptr'
*/

List* createListFromArray(const int* data, const int n) {
    List* list = new List;
    list->first = nullptr;

    Node* n_Node = new Node;
    n_Node->next = nullptr;

    if (n == 0)
    {
        return list;
    }
    if (n < 0)
    {
        return nullptr;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            appendNode(list, data[i]);
        }
        return list;
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'. Symetricky zoznam ma
    tvar 0,1,2,...val...2,1,0.

    PARAMETRE:
        [in] val - hodnota uzla podla, ktoreho sa vytvori novy symetricky zretazeny zoznam (uzol v strede zoznamu).

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci prvky v takom poradi, aby bol symetricky. V pripade 'val'<0, funkcia vrati
        'nullptr'.

    PRIKLADY:
        val=-31 ... vrati ... nullptr
        val=0 ... vrati zoznam ... {0}
        val=1 ... vrati zoznam ... {0,1,0}
        val=2 ... vrati zoznam ... {0,1,2,1,0}
        val=3 ... vrati zoznam ... {0,1,2,3,2,1,0}
        val=4 ... vrati zoznam ... {0,1,2,3,4,3,2,1,0}
        val=6 ... vrati zoznam ... {0,1,2,3,4,5,6,5,4,3,2,1,0}
*/

List* createSymmetricList(const int val) {
    List* list = new List;
    list->first = nullptr;

    if (val < 0)
    {
        return nullptr;
    }
    else
    {
        for (int i = val - 1; -1 < i; i--)
        {
            if (i == val - 1) { prependNode(list, val); }
            prependNode(list, i);
            appendNode(list, i);
        }
    }
    return list;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    RETURN:
        Result::SUCCESS, ak bol prvy uzol vymazany
        Result::FAILURE, ak nebol prvy uzol vymazany (vstupny zoznam bol prazdny)

    PRIKLADY:
        list={} ... funkcia vrati Result::FAILURE
        list={5} ... zoznam po vykonani funkcie ... {} a vrati Result::SUCCESS
        list={10,10,10} ... zoznam po vykonani funkcie ... {10,10} a vrati Result::SUCCESS
        list={3,2,1} ... zoznam po vykonani funkcie ... {2,1} a vrati Result::SUCCESS
*/

Result removeFirstNode(List* list) {
    if (list->first) {
        Node* tmp = list->first->next;
        delete list->first;
        list->first = tmp;
        return Result::SUCCESS;
    }
    return Result::FAILURE;
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla, ktory sa hlada

    RETURN:
        Funkcia vrati prvy uzol, ktory obsahuje hodnotu 'val'. Ak sa taky uzol v zozname nenachadza alebo je vstupny
        zoznam prazdny, vtedy funkcia vrati 'nullptr'.

    PRIKLADY:
        list={}, val=10 ... funkcia vrati 'nullptr'
        list={2}, val=3 ... funkcia vrati 'nullptr'
        list={1,2,3,4,5,6}, val=-1 ... funkcia vrati 'nullptr'
        list={1}, val=1 ... funkcia vrati uzol s hodnotou 1
        list={5,9,18}, val=9 ... funkcia vrati uzol s hodnotou 9
*/

Node* findNodeInList(List* list, const int val) {
    Node* tmp = list->first;
    while (tmp) {
        if (tmp->data == val) { return tmp; }
        tmp = tmp->next;
        if (tmp == NULL)return nullptr;
        if (tmp->data == val) { return tmp; }
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
    rovnake hodnoty uzlov v rovnakom poradi).

    PARAMETRE:
        [in] list1 - prvy zretazeny zoznam
        [in] list2 - druhy zretazeny zoznam

    RETURN:
        'true' - ak su vstupne zoznamy rovnake
        'false' - ak vstupne zoznamy nie su rovnake

    PRIKLADY:
        list1={1}
        list2={}
        Funkcia vrati 'false'.

        list1={}
        list2={5,3}
        Funkcia vrati 'false'.

        list1={}
        list2={}
        Funkcia vrati 'true'.

        list1={1}
        list2={1}
        Funkcia vrati 'true'.

        list1={4,-9,2}
        list2={4,-9,2}
        Funkcia vrati 'true'.

        list1={3,2,1}
        list2={1,2,3}
        Funkcia vrati 'false'.

        list1={2}
        list2={7,4,5}
        Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
    Node* tmp = new Node;
    tmp->next = list1->first;
    Node* tmp2 = new Node;
    tmp2->next = list2->first;

    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp->data != tmp2->data) {
            return false;
        }

        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    if (tmp || tmp2)
        return false;
    if (tmp == NULL && tmp2 == NULL) {
        return true;
    }
}


//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam prekopirovanim vsetkych hodnot uzlov vstupneho zoznamu 'list' v obratenom
    poradi.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam

    RETURN:
        Zretazeny oznam, ktory vznikne prekopirovanim hodnot uzlov vstupneho zoznamu 'list' v obratenom poradi.

    PRIKLADY:
        list={} ... funkcia vrati ... {} t.j. prazdny zoznam
        list={1} ... funkcia vrati ... {1}
        list={5,6} ... funkcia vrati ... {6,5}
        list={8,14,2,3} ... funkcia vrati ... {3,2,14,8}
*/

List* copyListReverse(List* list) {
    List* new_list = new List;
    new_list->first = nullptr;
    Node* n_Node = new Node;
    n_Node->next = nullptr;
    int val = 0;

    n_Node->next = list->first;
    while (n_Node != NULL)
    {
        n_Node = n_Node->next;
        if (n_Node == nullptr)break;
        val = n_Node->data;
        prependNode(new_list, val);
    }

    return new_list;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyhlada predchodcu zadaneho uzla 'node' vo vstupnom zretazenom zozname 'list'. Uzol 'node' je vzdy
    existujucim uzlom vstupneho zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] node - uzol zretazeneho zoznamu 'list', ktoreho predchodcu hladame

    RETURN:
        Uzol, ktory je predchodcom uzla 'node' v zozname 'list'. V pripade hladania predchodcu prveho uzla zoznamu,
        funkcia vrati 'nullptr'.

    PRIKLADY:
        list={4}
        node=4
        Funkcia vrati 'nullptr'.

        list={1,2,3,4,5}
        node=1
        Funkcia vrati 'nullptr'.

        list={-2,-3,56,4,41}
        node=-3
        Funkcia vrati uzol s hodnotou -2.

        list={10,54,69,82,6}
        node=6
        Funkcia vrati uzol s hodnotou 82.
*/

Node* findPreviousNode(List* list, Node* node) {
    Node* n_Node = new Node;
    n_Node->next = nullptr;
    Node* tmp = new Node;
    tmp->next = list->first;

    if (tmp->data == node->data)return nullptr;
    while (tmp != NULL)
    {
        if (tmp->data == node->data) {
            return n_Node;
        }
        n_Node->data = tmp->data;
        tmp = tmp->next;
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zduplikuje vsetky uzly vstupneho zoznamu 'list', ktore obsahuju kladnu hodnotu.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    PRIKLADY:
        list={} ... po vykonani funkcie ... {}
        list={3} ... po vykonani funkcie ... {3,3}
        list={-1,1} ... po vykonani funkcie ... {-1,1,1}
        list={-8,-9,-13} ... po vykonani funkcie ... {-8,-9,-13}
        list={1,0,-2,3,-4} ... po vykonani funkcie ... {1,1,0,-2,3,3,-4}
*/

void duplicatePositiveNodes(List* list) {
    Node* tmp = list->first;
    Node* n_Node = nullptr;
    while (tmp!=NULL) {
        if (tmp->data > 0) {
            n_Node = createNode(tmp->data);
            n_Node->next = tmp->next;
            tmp->next = n_Node;
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------


int main(int argc, char** argv) {
    /*List* zoznam = new List;
    zoznam->first = nullptr;
    List* zoznam2 = new List;
    zoznam2->first = nullptr;
    Node* n_Node = new Node;
    n_Node->next = nullptr;

    const int data[10] = { 5,-1,3,0,5,6,3,8,9,7 };*/

    //1.)
    //prependNode(zoznam, 8);
    //prependNode(zoznam, 1);
    // printList(zoznam);

    //2.)
    /*appendNode(zoznam, 1);
    appendNode(zoznam, 2);
    appendNode(zoznam, 3);
    appendNode(zoznam, 4);

    printList(zoznam);*/

    //3.)
    //int n = -5;
    //zoznam=createListFromArray(data, n);
    //printList(zoznam);
    //

    //4.)
    /*  int val = 4;
      zoznam = createSymmetricList(val);
      printList(zoznam);*/

    //5.)
    /*for (int i = 0; i < 1; i++) {
        prependNode(zoznam, i);
    }
    
    if (Result::SUCCESS == removeFirstNode(zoznam)) { cout << "S"; }
    if (Result::FAILURE == removeFirstNode(zoznam)) { cout << "F"; };
    printList(zoznam);*/

    //6.)
    //appendNode(zoznam, 2);
    /*for (int i = 0; i < 0; i++) {
        appendNode(zoznam, i);
    }

     n_Node=findNodeInList(zoznam,2);
    cout << n_Node->data;*/

    //7.
    /* for (int i = 0; i < 0; i++) {
         prependNode(zoznam, i);
     }
     for (int i = 0; i <0; i++) {
         prependNode(zoznam2, i);

     }
     if (true == areListsEqual(zoznam, zoznam2)) { cout << "rovnake"; }
     if (false == areListsEqual(zoznam, zoznam2)) { cout << "rozdielne"; }*/


    //8.)
    /*for (int i = 0; i < 0; i++) {
       appendNode(zoznam, i);
    }
    printList(zoznam);

    List* z2 = new List;
    z2->first = nullptr;
    z2=copyListReverse(zoznam);
    printList(z2);*/

    //9.)
    /*  for (int i = 0; i < 0; i++) {
          appendNode(zoznam, i);
      }
      n_Node->data = 0;
      n_Node=findPreviousNode(zoznam, n_Node);*/

    //10.)
    /* for (int i = -2; i < 5; i++) {
         appendNode(zoznam, i);
     }
     printList(zoznam);
     duplicatePositiveNodes(zoznam);
     printList(zoznam);*/
    return 0;
}