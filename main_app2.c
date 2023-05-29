#include <stdio.h>
#include <stdlib.h>

// Aplicația 12.2: Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate 
// elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare.
// Exemplu:
// n=5
// permutarile care respecta conditia sunt:
// 3 2 1 4 5
// 4 2 1 3 5
// 4 3 1 2 5
// 5 2 1 3 4
// 5 3 1 2 4
// 5 4 1 2 3

#define SIZE_STACK 100
int stack[SIZE_STACK] = {0};

int succesor(int stack[], int k, int n){
    if(stack[k] < n)
    {
        stack[k]++;
        return 1;
    }
    return 0;
}

int valid(int stack[], int k, int n){
    for(int i = 1; i < k; i++)
    {
        if(stack[i] == stack[k])
        {
            return 0;
        }

    }
    return 1;
}

int eSolutie(const int n, const int k){
    if(n == k)
    {
        for(int i = 1; i < n/2 + 1; i++)
        {
            if(stack[i] < stack[i+1])
            {
                return 0;
            }
        }
        for(int i = n/2+1; i < k; i++)
        {
            if(stack[i] > stack[i+1])
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void print_solutie(int stack[], int k){
    for(int i = 1; i <= k; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void back(const int n){
    int k = 1, numar_solutii = 0;
    stack[k] = 0;
    while(k >= 1)
    {
        if(succesor(stack, k, n))
        {
            if(valid(stack, k, n))
            {
                if(eSolutie(n, k))
                {
                    print_solutie(stack,k);
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
    printf("Numarul de solutii este -> %d\n", numar_solutii);
}

int main(void){
    int n;
    printf("Dati numarul n -> ");
    if(scanf("%d", &n) != 1)
    {
        fprintf(stderr, "Eroare la cititrea numarului n!\n");
        exit(-1);
    }
    back(n);
    return 0;
}