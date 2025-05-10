//Adam Koziana
#include <iostream>
using namespace std;

void Create(int len, int array[], int newArray[]) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] > 0 && array[i] <= 4095) {
            bool appear = false;
            for (int j = 0; j < count; j++) {
                if (array[i] == newArray[j]) {
                    appear = true;
                    break;
                }
            }
            if (!appear) {
                newArray[count] = array[i];
                count++;
            }
        }
    }
    newArray[count] = -1;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (newArray[i] > newArray[j]) {
                int temp = newArray[i];
                newArray[i] = newArray[j];
                newArray[j] = temp;
            }
        }
    }
}
void Add(int num, int array[]){
    if (num > 0 && num <= 4095){
        bool appear = false;
        for (int j = 0; array[j] != (-1); j++) {
            if (array[j] == num) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            int i = 0;
            while (array[i] != (-1)){
                i++;
            }
            array[i]=num;
            array[i+1]=(-1);
        }
    }
    int temp;
    for (int i=0; array[i]!=(-1);i++) {
        for (int j = i + 1; array[j] != -1; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void Complement(int array[], int resultArray[]) {
    const int universe = 4095;
    int count = 0;
    for (int i = 1; i <= universe; i++) {
        bool appear = false;
        for (int j = 0; array[j] != -1; j++) {
            if (array[j] == i) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            resultArray[count] = i;
            count++;
        }
    }
    resultArray[count] = -1;
    int temp;
    for (int i = 0; resultArray[i] != -1; i++) {
        for (int j = i + 1; resultArray[j] != -1; j++) {
            if (resultArray[i] > resultArray[j]) {
                temp = resultArray[i];
                resultArray[i] = resultArray[j];
                resultArray[j] = temp;
            }
        }
    }
}
void Union(int array1[], int array2[], int uniArray[]){
    int count = 0;
    for (int a1 = 0; array1[a1]!=(-1);a1++){
        bool appear = false;
        for (int i = 0; i < count; i++) {
            if (uniArray[i] == array1[a1]) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            uniArray[count] = array1[a1];
            count++;
        }
    }
    for (int a2 = 0; array2[a2]!=(-1);a2++){
        bool appear = false;
        for (int i = 0; i < count; i++) {
            if (uniArray[i] == array2[a2]) {
                appear = true;
            }
        }
        if (!appear) {
            uniArray[count] = array2[a2];
            count++;
        }
    }
    uniArray[count]=(-1);
    //sortowanie
    int temp;
    for (int i=0; uniArray[i]!=(-1);i++) {
        for (int j = i + 1; uniArray[j] != -1; j++) {
            if (uniArray[i] > uniArray[j]) {
                temp = uniArray[i];
                uniArray[i] = uniArray[j];
                uniArray[j] = temp;
            }
        }
    }
}
void Intersection(int array1[], int array2[], int interArray[]){
    int count = 0;
    for (int i = 0; array1[i] != -1; i++) {
        bool appear = false;
        for (int j = 0; array2[j] != -1; j++) {
            if (array1[i] == array2[j]) {
                appear = true;
                break;
            }
        }
        if (appear) {
            interArray[count] = array1[i];
            count++;
        }
    }
    interArray[count] = -1;
    int temp;
    for (int i = 0; interArray[i] != -1; i++) {
        for (int j = i + 1; interArray[j] != -1; j++) {
            if (interArray[i] > interArray[j]) {
                temp = interArray[i];
                interArray[i] = interArray[j];
                interArray[j] = temp;
            }
        }
    }
}
void Difference(int array[], int negArray[], int diffArray[]){
    int count = 0;
    for (int i = 0; array[i] != (-1); i++) {
        bool appear = false;
        for (int j = 0; negArray[j] != (-1); j++) {
            if (array[i] == negArray[j]) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            diffArray[count]=array[i];
            count++;
        }
    }
    diffArray[count] = (-1);
    int temp;
    for (int i = 0; diffArray[i] != -1; i++) {
        for (int j = i + 1; diffArray[j] != -1; j++) {
            if (diffArray[i] > diffArray[j]) {
                temp = diffArray[i];
                diffArray[i] = diffArray[j];
                diffArray[j] = temp;
            }
        }
    }
}
void Symmetric(int array1[], int array2[], int symArray[]){
    int count = 0;
    for (int i = 0; array1[i] != (-1); i++) {
        bool appear = false;
        for (int j = 0; array2[j] != (-1); j++) {
            if (array1[i] == array2[j]) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            symArray[count]=array1[i];
            count++;
        }
    }
    for (int i = 0; array2[i] != (-1); i++) {
        bool appear = false;
        for (int j = 0; array1[j] != (-1); j++) {
            if (array2[i] == array1[j]) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            symArray[count]=array2[i];
            count++;
        }
    }
    symArray[count] = (-1);
    int temp;
    for (int i=0; symArray[i]!=(-1);i++) {
        for (int j = i + 1; symArray[j] != -1; j++) {
            if (symArray[i] > symArray[j]) {
                temp = symArray[i];
                symArray[i] = symArray[j];
                symArray[j] = temp;
            }
        }
    }
}
void MinMax(int array[], int *min, int &max){
    if (array[0] != (-1)){
        *min = array[0];
        max = array[0];
        for (int i = 0; array[i] != (-1); i++){
            if (*min>array[i]) *min = array[i];
            if (max<array[i]) max = array[i];
        }
    }
}
void Cardinality(int array[], int *power){
    int i=0;
    while (array[i]!=(-1)) i++;
    *power=i;
}
bool Subset(int arrayIn[], int arrayCont[]) {
    int size1 = 0;
    while (arrayIn[size1] != -1) {
        size1++;
    }
    int size2 = 0;
    while (arrayCont[size2] != -1) {
        size2++;
    }
    for (int i = 0; i < size1; i++) {
        bool appear = false;
        for (int j = 0; j < size2; j++) {
            if (arrayIn[i] == arrayCont[j]) {
                appear = true;
                break;
            }
        }
        if (!appear) {
            return false;
        }
    }
    return true;
}
bool Equal(int array1[], int array2[]) {
    int size1 = 0;
    while (array1[size1] != -1) {
        size1++;
    }
    int size2 = 0;
    while (array2[size2] != -1) {
        size2++;
    }
    if (size1 != size2) {
        return false;
    }else{
        return Subset(array1,array2);
    }
}
bool Empty(int array[]){
    if (array[0]==(-1)) return true;
    else return false;
}
bool Nonempty(int array[]){
    if (array[0]==(-1)) return false;
    else return true;
}
bool Element(int ele, int array[]){
    for (int i = 0; array[i] != (-1); i++){
        if (array[i]==ele) return true;
    }
    return false;
}
double Arithmetic(int array[]){
    if (array[0]==(-1)) return 0.0;
    double sum = 0.0;
    double count = 0.0;
    for (int i = 0; array[i] != (-1); i++){
        sum += array[i];
        count += 1;
    }
    return sum/count;
}
double Harmonic(int array[]){
    if (array[0]==(-1)) return 1.0;
    double sum = 0;
    int count = 0;
    while (array[count] != (-1)){
        sum = sum + (1.0/array[count]);
        count++;
    }
    return count/sum;
}
void Properties(int array[], char op[], double &ari, double *harm, int &min, int *max, int &car){
    for (int i = 0; op[i] != 0; i++){
        if (op[i] == 'a') ari = Arithmetic(array);
        if (op[i] == 'h') *harm = Harmonic(array);
        if (op[i] == 'm') MinMax(array, &min, *max);
        if (op[i] == 'c') Cardinality(array, &car);
    }
}