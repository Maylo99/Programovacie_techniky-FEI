/*
Meno a priezvisko:Michal Hájek 104463

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie03.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

void prependNode(List* list, const int val) {
    Node* n_Node = new Node;
    n_Node->data = val;
    n_Node->next = list->first;
    list->first = n_Node;
}

void printList(const List* list) {
    Node* tmp = list->first;
    while (tmp) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}


void swapPointers(int** a, int** b)
{
    int* c = (*a);
    (*a) = (*b);
    (*b) = c;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}
*/

void insertionSort(int* data, const size_t length) {
    
    for (size_t i = 0; i < length - 1; i++) {
        if (length == 0 || length == 1)break;
        int j = i + 1;
        int tmp = data[j];
        while (j > 0 && tmp > data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    } 
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
        {"Juraj", "Anabela", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", "Anabela", nullptr}
        {"Andrej", nullptr} -> {"Andrej", nullptr}
        {nullptr} -> {nullptr}

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char* data[]) {
    int i = 0, k = 0;
    int v;
    const char* pomocne[] = { "JURO" };
    while (data[i] != NULL) 
    {
        if (data[i] == NULL)break;
        while (data[k] != NULL){
            if (data[k] == NULL)break;
            v = strcmp(data[i], data[k]);
            if (v > 0) 
                { 
                pomocne[0] = data[i];
                data[i] = data[k];
                data[k] = pomocne[0];
               // swap(data[i], data[k]); 
                }
            k++;
        }
        i++;
        k = 0;
    }
}

//------------------- ------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3, vystup: 3->2->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/
void insertionSort(List* list) {
    
    Node* tmp = new Node;
    tmp = list->first;
    Node* tmp2 = new Node;
    tmp2 = list->first;
    tmp2 = tmp2->next;
    Node* pomocna = new Node;

    while(tmp){
        while(tmp2){
            if (tmp->data<tmp2->data)
            {
                pomocna->data = tmp->data;
                pomocna->next = tmp->next;
                tmp->data = tmp2->data;
                tmp->next = tmp2->next;
                tmp2->data = pomocna->data;
                tmp2->next = pomocna->next;
            }
            tmp2 = tmp2->next;
        }
        tmp2 = list->first;
        tmp = tmp->next;
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' sa nemeni.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli)
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli)

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10}
        output pred vykonanim funkcie: {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20}
        output po vykonani funkcie:    {20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20}
*/
void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high)
{
    size_t first_left = low;     
    size_t first_right = middle; 
    size_t index = low;   
    int pl = 0, pr = 0;

    while (first_left < middle && first_right < high) {
        if (input[first_left] >= input[first_right])
        {
            output[index] = input[first_left];
            ++index;
            ++first_left;
        }
        else if (input[first_left] < input[first_right])
        {
            output[index] = input[first_right];
            ++index;
            ++first_right;
        }
    }
    if (first_left < middle)pl = 1;
    if (first_right < high)pr = 1;
    while (pl==1|| pr==1)
    {
        if (pl == 1) {
            output[index] = input[first_left];
            ++index;
            ++first_left;
            if (first_left == middle)pl = 0;
        }
        else if(pr==1)
        {
            output[index] = input[first_right];
            ++index;
            ++first_right;
            if (first_right == high)pr = 0;
        }
        if (pl == 0 && pr == 0)break;
    }
}
      
//void merge_rekurzia(int low, int high, int* data, size_t length, int* output)
//{
//    if (low < high) {
//        int middle = low + (high - low) / 2;
//
//        merge_rekurzia(low, middle, data, length, output);
//        merge(output, data, low, middle, length);
//        merge_rekurzia(middle + 1, high, data, length, output);
//
//        merge(output, data, low, middle, length);
//    }
//}
//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}

    POZNAMKA:
        Pri implementacii top-down bude vhodne vytvorit a zavolat rekurzivnu funkciu.
*/ 
void mergeSort(int* data, const size_t length)
{
    int* tmpArray = new int[length];

    int* input = data;
    int* output = tmpArray;
    bool needCopyToOrigin = false;
    for (size_t step = 1; step < length; step *= 2) {
        for (size_t i = 0; i < length; i += 2 * step) {
            size_t low = i;
            size_t middle = min(i + step, length);
            size_t high = min(i + 2 * step, length);
            merge(output, input, low, middle, high);
        }
        swapPointers(&input, &output);
        needCopyToOrigin = !needCopyToOrigin;
    }

    if (needCopyToOrigin) {
        std::memcpy(data, tmpArray, length * sizeof(int));
    }
    delete[] tmpArray;
 }



//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
   /* List* zoznam = new List;
    zoznam->first = nullptr;
    Node* n_Node = new Node;
    n_Node->next = nullptr;*/
   /* int data[16] = { 11, 10, 11, 12,  7,  6,  4000,  99,  8,  4,  2,  1, 10, 110, 1500, 10 };*/


    //1.)
    //  int data[10] = { 1,5,4,2,3,6,7,8,9,10 };
    /*insertionSort(data, 16);
    for (int i=0;i<16;i++){cout << data[i]<< " "; }*/

    //2.)
    /*const char* mena[] = { "Juraj", "Anabela", "Peter", "Andrej", nullptr };
    insertionSort(mena);
    for (int i = 0; i < 4; i++) {
        cout << mena[i];
    }*/

    //3.)
    /*for (int i=5;i>0;i--){
    prependNode(zoznam,i);
    }
    prependNode(zoznam,3);
   
    printList(zoznam);
    insertionSort(zoznam);
    printList(zoznam);*/



    //4.)
    

    //5.)
    /*mergeSort(data, 16);
    for (int i = 0; i <16; i++)
    {
        cout << data[i]<<" ";
    }*/
    
    return 0;
}
