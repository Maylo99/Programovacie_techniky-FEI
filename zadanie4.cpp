/*
Meno a priezvisko: Michal Hájek 104463

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie04.cpp (pouzite vase udaje bez diakritiky).
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

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Hmotnost produktu a obalu. Hmotnost zabaleneho produktu je suctom obidvoch poloziek
struct Weight {
    int product; // hmotnost produktu
    int packing; // hmotnost balenia
};

void funkcia_swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data'.
    Pouzije algoritmus bubble sort.
    Poradie usporiadania je od najvacsieho prvku po najmensi.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNA PODMIENKA:
        ak 'length' > 0, tak 'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {} -> {}
*/
void bubbleSort(int* data, const size_t length) {
    int tmp[1];
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length-1; j++)
        {
            if (data[j] < data[j + 1]) 
            {
                tmp[0] = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp[0];
            }
        }
   }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' podla celkovej hmotnosti zabaleneho tovaru, t.j. podla suctu poloziek ('product' a 'packing').
    Pouzije algoritmus bubble sort.
    Poradie usporiadania je od najvacsieho prvku po najmensi (od najtazsieho zabaleneho tovaru po najlahsi zabaleny tovar).

    Podmienka porovnania struktur:
    Pri porovnavani prvkov funkcia scita hodnoty 'product' a 'packing' oboch porovnavanych struktur.
    Struktury s vacsim suctom poloziek budu po usporiadani pred strukturami s mensim suctom poloziek.

    Vzajomne usporiadanie struktur s rovnakym suctom poloziek:
    Pri bodovom hodnoteni nezalezi na vzajomnom usporiadani struktur s rovnakym suctom poloziek (aj ked hodnoty poloziek mozu byt rozne).
    Lepsie je vsak implementovat stabilne triedenie (struktury s rovnakym suctom poloziek nemenia vzajomne usporiadanie).

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNA PODMIENKA:
        ak 'length' > 0, tak 'data' ukazuje na platne pole

    PRIKLADY:
        {{10, 1}, {20, 2}, {5,2}} -> {{20, 2}, {10, 1},{5,2}} pretoze 20+2=22, 10+1=11, 5+2=7 a 22 > 11 > 7
        {} -> {}

    POZNAMKA:
        Priklady jednoducheho vytvorenia pola v testovacom kode:
        Weight baliky[] = {{10, 1}, {20, 2}, {5,2}};
        Weight baliky[] = {{.product = 10, .packing = 1}, {.product = 20, .packing = 2}, {.product = 5, .packing = 2}};
*/

void bubbleSort(Weight* data, const size_t length) {
    int x1, x2;
    Weight tmp[1];
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - 1; j++)
        {
            x1 = data[j].packing + data[j].product;
            x2= data[j+1].packing + data[j+1].product;
            if (x1<x2)
            {
                tmp->packing = data[j].packing;
                tmp->product = data[j].product;
                data[j].packing=data[j+1].packing;
                data[j].product=data[j + 1].product;
                data[j + 1].packing = tmp->packing;
                data[j + 1].product = tmp->product;
            }
        }
    }
}


//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyberie pivota a vrati jeho index.
    Pivota vyberie ako median prvkov:
      - data[low]
      - data[(high+low)/2]
      - data[high-1]

    PARAMETRE:
        [in] data - pole, v ktoreho casti s indexami 'low' ... 'high'-1, funkcia vybera pivot
        [in] low  - index prveho prvku casti pola, v ktorej funkcia hlada pivot
        [in] high - index za poslednym prvkom casti pola, v ktorej funkcia hlada pivot

    NAVRATOVA HODNOTA:
        index pivota

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole
        'low' < 'high'

    PRIKLADY:
        data: {10, 20, 2000, 30, 1000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 2
        data: {10, 20, 1000, 30, 2000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 4
        data: {10, 20, 5000, 30, 1000, 40, 2000, 50, 60, 70}, low: 2, high: 7 -> return 6

        data: {10, 20, 1000, 30, 40, 2000, 50, 5000, 60, 70}, low: 2, high: 8 -> return 5

        data: {10, 20, 1000, 2000, 30, 40, 50},               low: 2, high: 4 -> return 3
        data: {10, 20, 2000, 1000, 30, 40, 50},               low: 2, high: 4 -> return 3

        data: {10, 20, 1000, 30, 40},                         low: 2, high: 3 -> return 2
*/
size_t getPivotIndex(const int* data, const size_t low, const size_t high)
{
    size_t index;
    if (low == high - 1)return low;
    if (low == high - 2)return high - 1;

   
        if ((data[low]<= data[(high + low) / 2]&& data[(high + low) / 2]<= data[high - 1]) || 
           ( data[low] >= data[(high + low) / 2] && data[(high + low) / 2] >= data[high - 1])) 
        {
        index=(high + low) / 2;
        return index;
    }
       
    if ((data[low]<=data[high-1] &&data[high-1]<= data[(high + low) / 2] )|| (data[low] >= data[high - 1] && data[high - 1] >= data[(high + low) / 2]))
    {
         index= high - 1;
         if (data[high-1] == data[(high + low) / 2])
             index = (high + low) / 2;
         return index;
    }
    if ((data[high-1]<=data[low] && data[low]<= data[(high + low) / 2]) ||( data[high - 1] >=data[low] && data[low] >= data[(high + low) / 2]))
    {
        index= low;
        if (data[low]== data[(high + low) / 2]) 
            index= (high + low) / 2;
        return index;
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona partition (cast algoritmu quick sort) a vrati novy index pivota.
    Pouzije styl algoritmu Lomuto.
    Poradie usporiadania:
        Najprv (vlavo) budu prvky vacsie alebo rovne ako pivot,
        potom pivot,
        potom (vpravo) prvky mensie ako pivot.

    PARAMETRE:
        [in, out] data - pole, v ktoreho casti 'low' ... 'high'-1 bude vykonane partition
        [in] pivot     - index pivota (pred partition)
        [in] low       - index prveho prvku casti pola, v ktorej bude vykonany partition
        [in] high      - index za poslednym prvkom casti pola, v ktorej bude vykonany partition

    NAVRATOVA HODNOTA:
        Index pivota po vykonani partition.

    VSTUPNE PODMIENKY:
        'low' <= 'pivot' < 'high'
        (index pivota moze byt lubobolny v rozsahu 'low'...'high'-1, napriklad v pripade nahodneho vyberu pivota)
        'data' ukazuje na platne pole

    PRIKLADY:
        1. priklad:
            vstup:  data: {10, 20, 30, 40, 50, 60, 70, 80, 90}, pivot: 5, low: 2, high: 7
            vystup: data: {10, 20, 70, 60, 50, 30, 40, 80, 90}, return 3

        2. priklad:
            vstup:  data: {10, 20, 30, 40, 50, 60, 70, 50, 80, 90}, pivot: 4, low: 2, high: 8
            vystup: data: {10, 20, 50, 60, 70, 50, 30, 40, 80, 90}, return 5
*/
size_t partition(int* data, const size_t pivot, const size_t low, const size_t high)
{
    int pivot1 = data[pivot];
    funkcia_swap(&data[pivot], &data[high - 1]);
    int i = low;
    for (size_t j = low; j < high-1; j++)
    {
        if (data[j] >= pivot1 )
        {
            funkcia_swap(&data[j], &data[i]);
            i++;
        }
    }
    funkcia_swap(&data[i], &data[high - 1]);
    return i;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada cast pola 'data' (s indexami 'low' ... 'high'-1).
    Pouzije algoritmus quick sort, styl Lomuto.
    Poradie usporiadania je od najvacsieho prvku po najmensi.

    PARAMETRE:
        [in, out] data - pole, ktoreho cast funkcia usporiada
        [in] low       - index prveho prvkou casti pola, ktoru funkcia usporiada
        [in] high      - index za posledny prvok casti pola, ktoru funkcia usporiada

    VSTUPNA PODMIENKA:
        ak 'low' < 'high', tak 'data' ukazuje na platne pole

    PRIKLAD:
        data: {1, 2, 3, 4, 5, 6, 7, 8, 9}, low: 2, high: 7 -> data: {1, 2, 7, 6, 5, 4, 3, 8, 9}
*/
void quickSort(int* data, const size_t low, const size_t high)
{
    if (low < high)
    {
        size_t pivot = partition(data, getPivotIndex(data, low, high), low, high);
        quickSort(data, low, pivot);
        quickSort(data, pivot + 1, high);
  }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    //int data[6] = { 4,5,1,3,8,9 };
    // tu mozete doplnit testovaci kod
  
   //1.) 
    /* bubbleSort(data, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << data[i];
    }*/


    //2.)
    /*Weight baliky[] = { {10, 1}, {20, 2}, {5,2} };
    bubbleSort(baliky, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << baliky[i].product ;
        cout << baliky[i].packing<<" ";
    }*/

    //3.)
   //int data[] = { 10, 20, 1000, 2000, 30, 40, 50 };// low: 2, high : 8 -> return 5
   //size_t index = getPivotIndex(data, 2, 4);
   //cout << index;

    //4.)
// int  data[]= { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
//
//size_t index=partition(data,5,2,7);
//for (int i = 0; i < 9; i++) {
//    cout << data[i]<<" ";
//}
//cout << index;

    //5.)

//PRIKLAD:
//data: {1, 2, 3, 4, 5, 6, 7, 8, 9}, low : 2, high : 7->data : {1, 2, 7, 6, 5, 4, 3, 8, 9}
   /* int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quickSort(data, 2, 7);

    for (int i = 0; i < 9; i++) {
            cout << data[i]<<" ";
        }*/
    return 0;
}
