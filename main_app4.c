#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 12.4: Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
// Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
// - orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
// - culorile din fiecare steag trebuie sa fie distincte

#define SIZE_STACK 100

int stack[SIZE_STACK] = {0};

int succesor(int stack[], int k, int n){
    if(stack[k] < n){
        stack[k]++;
        return 1;
    }
    return 0;
}

int valid(char* culori[], int stack[], int k){
    for(int i = 1; i < k; i++)
    {
        if(stack[i] == stack[k])
        {
            return 0;
        }
    }
    return 1;
}

int eSolutie(char* culori[], int stack[], int k, int p){
    if(k == p){
        if(strcmp(culori[stack[p/2+1]-1],"verde") != 0 && strcmp(culori[stack[p/2+1]-1], "galben") !=0)
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

void print_solutie(char* culori[], int stack[], int k){
    for(int i = 1; i <= k; i++)
    {
        printf("%s ", culori[stack[i]-1]);
    }
    printf("\n");
}

void back(char* culori[], const int n, const int p){
    int k = 1, numar_solutii = 0;
    stack[k] = 0;
    while(k >= 1){
        if(succesor(stack, k, n))
        {
            if(valid(culori, stack, k))
            {
                if(eSolutie(culori,stack,k,p))
                {
                    print_solutie(culori, stack, k);
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
    printf("Numarul de solutii gasite este -> %d\n", numar_solutii);
}

int main(void){
    char* culori[] = {"alb", "galben", "rosu", "verde","albastru", "negru"};
    int numar_culori = 6;
    int p = 3;

    back(culori, numar_culori, p);
    return 0;
}