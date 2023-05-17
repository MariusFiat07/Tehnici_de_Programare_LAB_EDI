#include <stdio.h>
#include <stdlib.h>

#define DEBUGG 0
#define SIZE_NAME 10

typedef struct{
    float value;
    char name[SIZE_NAME];
}Money_t;

int main(void){
    Money_t money_type[10] = {{500.00, "500 lei"}, {200.00, "200 lei"}, {100.00, "100 lei"}, {50.00,"50 lei"}, {10.00, "10 lei"}, {5.00, "5 lei"}, {1.00, "1 lei"}, {0.5, "0.5 lei"}, {0.1, "0.1 lei"}};

    float My_value;
    printf("Read the money balance -> ");
    if(scanf("%f", &My_value) != 1)
    {
        fprintf(stderr, "Error at My_value!\n");
        exit(-1);
    }

    #if DEBUGG == 1
        printf("My_value : %1.02f\n", My_value);
    #endif

    int index_type = 0, number_of_current_type = 0;
    while(My_value > 0.01)
    {
        number_of_current_type = My_value / money_type[index_type].value;
        if(number_of_current_type == 0)
        {
            index_type++;
        }
        else
        {
            #if DEBUGG == 1
                printf(" My_value  -> %1.02f\n", My_value);
                printf(" index_type -> %d\n", index_type);
            #endif
            printf("%d -> %s\n", number_of_current_type, money_type[index_type].name);
            My_value = My_value - number_of_current_type * money_type[index_type].value;
            
            #if DEBUGG == 1
                printf("My_value : -> %1.02f\n", My_value);
            #endif

            index_type++;
            
            number_of_current_type = 0;
        }
    }
    return 0;
}