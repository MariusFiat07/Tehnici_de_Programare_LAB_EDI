#include <stdio.h>
#include <stdlib.h>

// Aplicația 12.3: Se citesc doua numere naturale n si k, k fiind mai mic decat numarul de cifre ale numarului n. Afisati 
// cel mai mare numar care se poate forma eliminand k cifre din numarul n.
// Exemplu:
// n=3452234
// k=4
// numarul cautat este 534

#define DEBUGG 1
#define SIZE_STACK 100
int stack[SIZE_STACK] = {0};

int* creare_array_cifre(int numar, int* size){
    int index = 0;
    int* array = NULL;
    int cifra;

    while(numar)  //Aici cat timp numarul inca are cifre, le scoatem si le adaugam in array;
    {
        cifra = numar % 10; //Aici scot cifra de la coada numarului;
        (*size)++;
        array = realloc(array, (index + 1)*sizeof(int)); //Aloc memorie pentru a adauga noua cifra in array;
        if(!array)
        {
            fprintf(stderr, "Memorie insuficienta pentru a crea array-ul!\n");
            exit(-1);
        }
        array[index++] = cifra;
        numar = numar/10;
    }
    return array;
}

int succesor(int stack[], int k, int n, int p){
    if(stack[k] < n){
        stack[k]++;
        return 1;
    }
    return 0;
}

int valid(int array[], int stack[], int k){
    for(int i = 1; i < k; i++)
    {
        if(stack[i] == stack[k])
        {
            return 0;
        }
        if(array[stack[i]-1] == array[stack[k]-1])
        {
            return 0;
        }
    }
    return 1;
}

int eSolutie(const int k, const int p){
    return k == p;
}

void print_Solutie(int array[], int stack[], int k){
    for(int i = 1; i <= k; i++)
    {
        printf("%d ", array[stack[i]-1]);
    }
    printf("\n");
}

int numarul_actual(int array[], int stack[], int p){
    int numar =0;
    for(int i = 1; i <= p; i++)
    {
        numar = numar * 10 + array[stack[i]-1];
    }
    return numar;
}

void back(int array[], int n, int p){
    int k = 1, numar_solutii = 0;
    int numarul_curent = 0, maxim;
    stack[k] = 0;
    while(k >= 1)
    {
        if(succesor(stack, k, n, p))
        {
            if(valid(array, stack, k))
            {
                if(eSolutie(k, p))
                {
                    print_Solutie(array, stack, k);
                    numarul_curent = numarul_actual(array, stack, p);
                    if(numar_solutii == 0)
                    {
                        maxim = numarul_curent;
                    }
                    else
                    {
                        if(numarul_curent > maxim)
                        {
                            maxim = numarul_curent;
                        }
                    }
                    numar_solutii++;
                }
                else
                {
                    k++;
                    stack[k] = 0;
                }
            }
        }
        else
        {
            k--;
        }
    }
    //printf("Numarul de solutii gasit este -> %d\n", numar_solutii);
    printf("Cel mai mare numar format este -> %d\n", maxim);
}

void print_array(const int array[], const int size){
    for(int i = 0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void){
    int n, k;
    printf("Cititi numerele n si k -> ");
    if(scanf("%d%d", &n, &k) != 2)
    {
        fprintf(stderr, "Eroare la citirea numerelor n si k!\n");
        exit(-1);
    }

    int size_array = 0;
    int* array = creare_array_cifre(n, &size_array);
    int p = size_array - k;

    #if DEBUGG == 1
        printf("Numarul n citit este -> %d\n", n);
        printf("Numarul k citit este -> %d\n", k);
        printf("Numarul p de cifre este -> %d\n", p);
        printf("Array-ul de cifre este -> ");
        print_array(array, size_array);
    #endif

    back(array, size_array, p);

    free(array);
    return 0;
}