#include <stdio.h>
#include <stdlib.h>

int* citire_matrice(const int numar_linii, const int numar_coloane)
{
    int valoare;
    int* matrice = NULL;
    //Alocarea dinamica a matricei;
    if((matrice = (int*)malloc(numar_linii*numar_coloane*sizeof(int))) == NULL)
    {
        fprintf(stderr, "Eroare la alocarea memoriei pentru matrice!\n");
        exit(-1);
    }

    //Citirea matrice;
    for(int i = 0; i < numar_linii; i++)
    {
        for(int j = 0; j < numar_coloane; j++)
        {
            //Citirea elementului;
            if(scanf("%d", &valoare) != 1)
            {
                fprintf(stderr, "Eroare la citirea elementului!\n");
                exit(-1);
            }
            *(matrice + i*numar_coloane + j) = valoare;
        }
    }

    return matrice;
}

void scriere_matrice_fisier_binar(const int* matrice, const int numar_linii, const int numar_coloane, const char* File)
{
    FILE *f;

    //Deschidere fisier binar;
    if((f = fopen(File, "wb")) == NULL)
    {
        fprintf(stderr, "Eroare la deschiderea fierului binar!\n");
        exit(-1);
    }

    //Scrierea numarului de linii si coloane;
    fwrite(&numar_linii, 4, 1, f);
    fwrite(&numar_coloane, 4, 1, f);

    //Scriere elemente;
    for(int i = 0; i < numar_linii; i++)
    {
        for(int j = 0; j < numar_coloane; j++)
        {
            if(fwrite((matrice + i*numar_coloane + j), 4, 1, f) != 1)
            {
                fprintf(stderr, "Eroare la scrierea elementelor in fisierul binar!\n");
                exit(-1);
            }
        }
    }

    //Inchidere fisier binar;
    if(fclose(f) != 0)
    {
        fprintf(stderr, "Eroare la inchiderea fisierului binar!\n");
        exit(-1);
    }
}

void citire_afisare_binar(const char* File)
{
    FILE *f = NULL;
    if((f = fopen(File, "rb")) == NULL)
    {
        fprintf(stderr, "Eroare la deschiderea fisierlui binar pentru citire!\n");
        exit(-1);
    }

    int valoare_curenta, numar_linii, numar_coloane;
    
    //Citirea numarului de linii;
    if(fread(&numar_linii, 4, 1, f) != 1)
    {
        fprintf(stderr, "Eroare la citirea numarului de linii din fisierul binar!\n");
        exit(-1);
    }

    if(fread(&numar_coloane, 4, 1, f) != 1)
    {
        fprintf(stderr, "Eroare la citirea numarului de coloane din fisierul binar!\n");
        exit(-1);
    }

    for(int i = 0; i < numar_linii; i++)
    {
        for(int j = 0; j < numar_coloane; j++)
        {
            if(fread(&valoare_curenta, 4, 1, f) != 1)
            {
                fprintf(stderr, "Eroare la citirea elementului din fisierul binar!\n");
                exit(-1);
            }
            printf("%d ", valoare_curenta);
        }
        printf("\n");
    }

    //Inchidere fisier binar;
    if(fclose(f) != 0)
    {
        fprintf(stderr, "Eroare la inchiderea fisierului binar!\n");
        exit(-1);
    }
}

int main(int argc, char** argv)
{
    int numar_linii, numar_coloane;

    //printf("Dati numarul de linii si de coloane -> ");
    if(scanf("%d%d", &numar_linii, &numar_coloane) != 2)
    {
        fprintf(stderr, "Eroare la citirea dimensiunilor matricilor!\n");
        exit(-1);
    }

    //Citire date;
    int* matrice = citire_matrice(numar_linii, numar_coloane);

    //Scriere date;
    scriere_matrice_fisier_binar(matrice, numar_linii, numar_coloane, argv[1]);
    citire_afisare_binar(argv[1]);

    //Eliberare memorie matrice;
    free(matrice);
    return 0;
}