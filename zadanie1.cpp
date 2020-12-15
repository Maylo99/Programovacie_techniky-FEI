//Meno a priezvisko: Michal Hájek 104463

#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Bod v rovine
struct Point {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Usecka v rovine
struct Line {
    Point start; // zaciatocny bod
    Point end;   // koncovy bod
};

// Student
struct Student {
    char *name; // meno studenta
    int year;   // rocnik studia
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

// Matematicka funkcia
enum class Operation {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};

// Vstup pre matematicky vypocet funkcie s dvoma parametrami
struct CalculationInput {
    int operand1; // prvy parameter
    int operand2; // druhy parameter
    Operation operation; // funkcia
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytlaci obsah pola na standardny vystup.
    V implementacii musi byt pouzity 'std::cout'.

    Format tlace:
    - prvky pola (cisla) su oddelene jednou medzerou
    - pred prvym prvkom je gulata otvaracia zatvorka (medzi zatvorkou a cislom nesmie byt medzera)
    - za poslednym prvkom je gulata zatvaracia zatvorka (medzi cislom a zatvorkou nesmie byt medzera)

    PARAMETRE:
        [in] data   - pole cisiel
        [in] length - dlzka pola 'data'

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        prazdne pole: ()
        jednoprvkove pole: (10)
        2 prvkove pole:    (10 20)
        10 prvkove pole:   (8 -5 100000 2 1 2 4 5 -20 345)
*/
void printArray(const int *data, size_t length) {
    std::cout << "(";
    for (size_t i = 0; i < length; i++) {
        if (i != length - 1) {
            std::cout << data[i] << " ";
        } else {
            std::cout << data[i];
        }
    }
    std::cout << ")";
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Zo standardneho vstupu nacita dve cele cisla (typu 'int') a vrati ich sucet.
    V implementacii musi byt pouzity 'std::cin'.

    NAVRATOVA HODNOTA:
        sucet cisiel nacitanych zo standardneho vstupu

    VSTUPNE PODMIENKY:
        Textovy vstup zadany na standardny vstup programu obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov zadanych na standardny vstup.

    PRIKLADY:
        Ak je na standardny vstup zadany text "10 20\n" (bez uvodzoviek), tak funkcia vrati 30.
        Ak je na standardny vstup zadany text " 10 \n 20 \n" (bez uvodzoviek), tak funkcia vrati 30.
*/
int sumOfTwoNumbersFromConsole() {
    int pom = 0, sucet = 0;
    for (int i = 0; i < 2; i++) {
        std::cin >> pom;
        sucet = sucet + pom;
    }
    return sucet;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'text' obsahuje velke pismeno, inak vrati 'false'.

    PARAMETER:
        [in] text - textovy retazec ukonceny '\0'

    NAVRATOVA HODNOTA:
        'true'  - ak 'text' obsahuje aspon jedno velke pismeno
        'false' - ak 'text' neobsahuje ani jedno velke pismeno (plati aj pre prazdny retazec)

    POZNAMKA:
        Pri implementacii pouzite funkciu 'std::isupper'.
*/
bool containsUpperCase(const char *text) {
    int length_of_input_string = strlen(text);
    for (int i = 0; i < length_of_input_string; i++) {
        if (std::isupper(static_cast <unsigned char> (text[i]))) {
            return true;
        }
    }
    std::cout << "\n";
    return false;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'data' obsahuje stupajucu postupnost, inak vrati 'false'.

    PARAMETRE:
        [in] data   - pole hodnot
        [in] length - pocet prvkov pola 'data'

    NAVRATOVA HODNOTA:
        'true' - ak 'data' obsahuje stupajucu postupnost hodnot, alebo pocet prvkov pola je mensi ako 2
        'false' - v opacnom pripade

    PRIKLADY:
        data = {10, 11, 15, 20} => vysledok je 'true'
        data = {10, 15, 15, 20} => vysledok je 'false'
        data = {10, 11, 15, 12} => vysledok je 'false'
        data = {10}             => vysledok je 'true'
        data = {}               => vysledok je 'true'
*/
bool isAscending(const int *data, size_t length) {
    int tmp = length - 1;
    if (length < 2) {
        return true;
    }
    for (int i = 0; i < tmp; i++) {
        if (data[i] >= data[i + 1]) {
            return false;
        }
    }
    return true;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Posunie hodnoty pola 'data' o 1 miesto vyssie. Hodnotu posledneho prvku presunie na zaciatok.

    PARAMETRE:
        [in,out] data - pole hodnot, ktore bude preusporiadane
        [in] length   - pocet prvkov pola 'data'

    PRIKLADY:
        {10, 20, 30, 40, 50} => {50, 10, 20, 30, 40}
        {10} => {10}
        {} => {}
*/
void shiftUp(int *data, size_t length) {
    int *tmp = new int[length];

    for (size_t i = 0; i < length; i++) {
        tmp[i] = data[i];
    }
    for (size_t i = 0; i < length; i++) {
        if (i == 0) {
            data[i] = tmp[length - 1];
        } else {
            data[i] = tmp[i - 1];
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Preusporiada pole 'data' tak, ze jeho prvky budu v opacnom poradi.

    PARAMETRE:
        [in, out] data - pole hodnot, ktore bude preusporiadane
        [in] lenght    - pocet prvkov pola 'data'

    PRIKLADY:
        {10, 20, 30, 40, 50} => {50, 40, 30, 20, 10}
        {10, 20, 30, 40} => {40, 30, 20, 10}
        {10} => {10}
        {} => {}

*/
void reverse(int *data, size_t length) {
    int pom;
    size_t x = length;
    for (size_t i = 0; i < x / 2; i++) {
        pom = data[i];
        data[i] = data[length - 1 - i];
        data[length - 1 - i] = pom;
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati dlzku usecky 'line'

    PARAMETER:
        [in] line - usecka

    NAVRATOVA HODNOTA:
        dlzka usecky 'line'

    PRIKLAD:
        line:
            start:
                x = 10
                y = 20
            end:
                x = 100
                y = 50
        return 94.868329805
*/
double length(const Line *line) {
    return sqrt(pow((line->end.x - line->start.x), 2) + pow((line->end.y - line->start.y), 2));
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati dlzku usecky 'line'

    PARAMETER:
        [in] line - usecka

    NAVRATOVA HODNOTA:
        dlzka usecky 'line'

    PRIKLAD:
        line:
            start:
                x = 10
                y = 20
            end:
                x = 100
                y = 50
        return 94.868329805
*/
double length(const Line &line) {
    return sqrt(pow((line.end.x - line.start.x), 2) + pow((line.end.y - line.start.y), 2));
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvori noveho studenta s menom 'name' a rocnikom studia 'year'.
    Vrati smernik na vytvoreneho studenta.

    PARAMETRE:
        [in] name - meno studenta (textovy retazec ukonceny '\0')
        [in] year - rocnik v ktorom student studuje

    NAVRATOVA HODNOTA:
        vytvoreny student
*/
Student *createStudent(const char *name, int year) {
    Student *ptr = new Student;
    char *meno = new char;
    strcpy(meno, name);
    ptr->name = meno;
    ptr->year = year;
    return ptr;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vypocita celociselny matematicky vypocet zadany parametrom 'input'.
    Vysledok ulozi do 'output'.

    PARAMETRE:
        [in] input   - vstupne udaje pre matematicky vypocet
        [out] output - vystupna hodnota vypoctu (v pripade moznosti vypoctu)

    NAVRATOVA HODNOTA:
        Result::SUCCESS - ak je mozne vypocitat vyslednu hodnotu
        Result::FAILURE - ak nie je mozne vypocitat vyslednu hodnotu (v pripade delenia nulou)

    VYSTUPNE PODMIENKY:
        - Vysledok vypoctu je celociselny.
        - Ak je mozne vykonat vypocet, tak sa vysledok ulozi do 'output' a funkcia vrati 'Result::SUCCESS',
          inak (v pripade delenia nulou) sa hodnota 'output' nemeni a funkcia vrati 'Result::FAILURE'.
*/
Result calculate(int *output, const CalculationInput *input) {

    switch (input->operation) {
        case Operation::PLUS:
            *output = input->operand1 + input->operand2;
            std::cout << *output;
            return Result::SUCCESS;
            break;
        case Operation::MINUS:
            *output = input->operand1 - input->operand2;
            std::cout << *output;
            return Result::SUCCESS;
            break;
        case Operation::MULTIPLY:
            *output = input->operand1 * input->operand2;
            std::cout << *output;
            return Result::SUCCESS;
            break;
        case Operation::DIVIDE:
            if (input->operand2 == 0)
                return Result::FAILURE;
            *output = input->operand1 / input->operand2;
            std::cout << *output;
            return Result::SUCCESS;
            break;
        default:
            break;
    }
    return Result::FAILURE;
}
//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv) {
    //int data[] = {1};
    // char retazec[] = "caute";
    // char retazec1[] = "tee";

    //1.
    // printArray(data, 5);
    // tu mozete doplnit testovaci kod


    //2.
    //std:: cout << (sumOfTwoNumbersFromConsole());


    //3.
    // if (true == containsUpperCase(retazec1)) {
    //     std::cout << "true-obsahuje aspon jedno velke pismeno";
    //  }
    // if (false == containsUpperCase(retazec1)) {
    //   std::cout << "false-neobsahuje ani jedno velke pismeno";
    // }

    //4.
    //if (true == isAscending(data, 5)) {
    //  std::cout << "True- is ascending";
    //}
    // else
    //{
    //      std::cout << "false- is not ascending";
    // }

    // 5.
    //shiftUp(data, 1);
    //printArray(data, 1);

    //6.
    // reverse(data, 5);
    // printArray(data,5);

    //7.
    //const Line usecka{ {10,20}, {100,50} };
    // std:: cout<<length(&usecka);

    //8.)
    //const Line usecka{ {10,20}, {100,50} };
    //std::cout << length(usecka);

    //9.
    //   Student *novy = createStudent("Michal", 4);
    //  std::cout << novy->name;
    //  std::cout << novy->year;

    //10.
    return 0;
}