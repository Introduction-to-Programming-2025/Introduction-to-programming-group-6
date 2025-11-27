```
void put2AtRandomPosition(unsigned ** matrix, size_t n){
    // Генерираме случайно число между 0 и n - t
    // Генериране на още една случайна стойност между 0 и n - k
    // Докато matrix[k][t] != 0
        //Генерираме ги наново
    // matrix[k][t] = 2;
}
unsigned** initializeField(){
    // Променливи за полето - динамично заделена матрица(unsigned**) и размер
    // Прочитане на размера
    // Валидиране на размера (по голям от 1)
    // Заделяме памет за отделните редове
    // Итериране по редове
        // Заделяме памет за всеки елемент от реда
        // Итериране на елементите на реда
            // Правим всяка клетка 0;
    // Извикване на функция put2AtRandomPosition за поставяне на 2 на случайна позиция
    // Връщане на матрицата
}
void shiftAllZerosToRight(unsigned** matrix, unsigned n){
    // Обхождаме всеки ред
        // Обхождаме до намиране на индекс на най-лявата 0 -zeroIndex, ако няма continue;
        // Обхождаме всеки елемент на реда
        // Ако елемента е ненулев поставяме го нa zeroIndex и zeroIndex++
}

void mergeNeiboursByRows(unsigned** matrix,, size_t n){
    // Обхождаме всеки ред
        // Обхождаме всеки елемент без последния
            // Ако елемента отдясно е равен на сегашния -> сегашния *= 2 и елемента отдясно = 0
}

void moveLeft(unsigned** matrix, size_t n){
    // Викаме shiftAllZerosToRight
    // Викаме mergeNeiboursRows
    // Викаме shiftAllZerosToRight
}

void shiftAllZerosToDown(unsigned** matrix, unsigned n){
    // Обхождаме всеки всяка колона - j
        // Обхождаме до намиране на индекс на най-горната 0 -zeroIndex
        // Обхождаме всеки елемент на колоната - i
        // Ако елемента е ненулев поставяме го нa matrix[zeroIndex][j] и zeroIndex++
}

void mergeNeiboursByCols(unsigned** matrix,, size_t n){
    // Обхождаме всяка колона
        // Обхождаме всеки елемент без последния
            // Ако елемента отдолу е равен на сегашния -> сегашния *= 2 и елемента отдолу = 0
}

void shiftAllZerosToUp(unsigned** matrix, size_t n){
    // Обхождаме всеки всяка колона - j
        // Обхождаме наобратно до намиране на индекс на най-долната 0 -zeroIndex
        // Обхождаме всеки елемент на колоната - i - наобратно
        // Ако елемента е ненулев поставяме го нa matrix[zeroIndex][j] и zeroIndex--
}

void shiftAllZerosToLeft(unsigned** matrix, size_t n){
    // Обхождаме по редове
        // Обхождаме до намиране на индекс на най-лявата 0 -zeroIndex, ако няма continue;
        // Обхождаме всеки елемент на реда - в обратен ред
        // Ако елемента е ненулев поставяме го нa zeroIndex и zeroIndex--

}
void moveRight(unsigned** matrix, size_t n){
    // викаме shiftAllZerosToLeft
    // викаме mergeNeiboursRows
    // викаме shiftAllZerosToLeft
}

void moveUp(unsigned** matrix, size_t n){
    // викаме shiftAllZerosToDown
    // викаме mergeNeiboursCols
    // викаме shiftAllZerosToDown
}

void moveDown(unsigned** matrix, size_t n){
    // викаме shiftAllZerosToUp
    // викаме mergeNeiboursCols
    // викаме shiftAllZerosToUp
}

bool hasZeros(unsigned **matrix, size_t n){
    // Обхождаме по редове
        // Обхождаме всеки елемент
            // Ако е 0 -> return true;
    // return false;
}

bool hasNeibours(unsigned** matrix, size_t n){
    // Итерираме по редове
        // Итерираме всеки елемент
            // Ако някой от елементите отляво, отдясно, отгоре или отдолу, на валидни позиции, е равен на елемента return true
    //return false;
}

void main(){
    // викаме initializeField
    // докато hasNeibours или hasZeros
        // четем от конзолата за ход
        // ако е 'L' - викаме moveLeft
        // ако е 'R' - викаме moveRight
        // ако е 'D' - викаме moveDown
        // ако е 'U' - викаме moveUp
        // ако hasZeros, put2AtRandomPosition
}
```
