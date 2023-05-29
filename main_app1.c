#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Aplicația 12.1: Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din 
// n cifre care contin exact k cifre de 1.

#define SIZE_STACK 100
int stack[SIZE_STACK] = {-1};

int succesor(int stack[], int k, int size_array){
    if(stack[k] < size_array){
        stack[k]++;
        return 1;
    }
    return 0;
}

int eSolutie(int stack[], int array[], int size_array, int k, int p, int cifre1){
    if(k == p)
    {
        int numar_cifre1 = 0;

        int numarul_creat = 0;
        for(int i = 1; i <= k; i++)
        {
            numarul_creat = numarul_creat*10 + array[stack[i]-1];
            if(array[stack[i]-1] == 1)
            {
                numar_cifre1++;
            }
        }
        if(numar_cifre1 == cifre1)
        {
            if(numarul_creat == 1 && p > 1)
            {
                return 0;
            }
            else if(numarul_creat < pow(10,p-1))
            {
                return 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

void print_solutie(int stack[], int array[], int k){
    for(int i = 1; i <= k; i++)
    {
        printf("%d", array[stack[i]-1]);
    }
    printf("\n");
}

void back(int array[], int size_array, int p, int cifre1){ // p = numarul de cifre de 1;
    int k = 1, numar_solutii = 0;
    stack[k] = 0;
    while(k >= 1)
    {
        if(succesor(stack, k, size_array))
        {
            if(eSolutie(stack, array, size_array, k, p,cifre1))
            {
                print_solutie(stack, array, k);
                numar_solutii++;
            }
            else if(k < p)
            {
                k++;
                stack[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
    printf("Numarul de solutii este -> %d\n", numar_solutii);
}

int main(void){
    int n, k;
    printf("Cititi numerele n si k -> ");
    if(scanf("%d%d", &n,&k) != 2)
    {
        fprintf(stderr, "Eroare la citirea numerelor n si k!\n");
        exit(-1);
    }
    
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    back(array, size, n, k);
    return 0;
}