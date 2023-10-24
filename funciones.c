#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

char ***IniciarMatriz()
{
    char ***vuelo=(char***)calloc(4, sizeof(char**));
    for (int i=0; i<8; i++)
    {
        *(vuelo+i)=(char**)calloc(8, sizeof(char*));
        for (int j=0; j<8;j++)
        {
            *(*(vuelo+i)+j)=(char*)calloc(2, sizeof(char));
            *(*(vuelo+i)+j)="o";
        }
    }

    return vuelo;
}
char ***CambioDisponiblidad(char ***A,int pasillo, int fila, int modificacion)
{
    if (modificacion==0)
    {
        *(*(A+fila)+pasillo)="o";
    }
    else 
    {
        *(*(A+fila)+pasillo)="x";
    }
        
    return A;
}

float Cobro(int pasillo)
{
    float precio;
    if (pasillo==0||pasillo==7)
    {
        precio=2300+(2300*.30);
    }
    else if (pasillo>1&&pasillo<6)
    {
        precio=2300-(2300*.1);
    }
    else
    {
        precio=2300;
    }

    return precio;
}
char ***Reserva(char ***A)
{
    int num_asientos, num_fila, num_pasillo;
    char input;
    float precio;
    float total=0;
    int reservar=0;
    
    do 
    {
        printf("Ingrese el numero de asientos que desea reservar:");
        scanf("%d", &num_asientos);
    }while (num_asientos<4);

    for (int i=0; i<num_asientos; i++)
    {
        printf("Ingrese el numero de fila del asiento que desea reservar: ");
        scanf("\n%d", &num_fila);
        num_fila-=1;

        printf("Ingrese la letra del pasillo del asiento que desea reservar: ");
        scanf("\n%c", &input);
        num_pasillo=input-97;

        CambioDisponiblidad(A, num_pasillo, num_fila, reservar);
        precio=Cobro(num_pasillo);
        total+=precio;
    }
    printf("Su reserva tiene un costo de $%1.2f", total);

    return A;
}

char ***Cancelar(char ***A)
{
    int num_boletos, num_fila, num_pasillo;
    char input;
    int cancelacion=1;
    
    do 
    {
        printf("Ingrese el numero de boletos que desea cancelar:");
        scanf("%d", &num_boletos);
    }while (num_boletos<4);

    for (int i=0; i<num_boletos; i++)
    {
        printf("Ingrese el numero de fila del boleto que desea cancelar: ");
        scanf("%d", &num_fila);
        num_fila-=1;

        printf("Ingrese la letra del pasillo del boleto que desea cancelar: ");
        scanf("%c", &input);
        num_pasillo=input-97;

        CambioDisponiblidad(A, num_pasillo, num_fila, cancelacion);
    }

    return A;
}

void PrintMatriz(char ***A)
{
    printf("[\t \ta\tb\tc\td\te\tf\tg\th\t]\n");
    for (int i=0; i<4; i++)
    {
        printf("[\t%d\t",i);
        for (int j=0; j<8;j++)
        {
            printf("%s\t", A[i][j]);
        }
        printf("]\n");
    }
}

char ***limpiar(char ***A)
{
    
    for (int i=0; i<8; i++)
    {
        
        for (int j=0; j<2;j++)
        {
            free(*(*(A+i)+j));
        }
        free(*(A+i));
    }
    free(A);
    return A;
}
