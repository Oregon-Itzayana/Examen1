#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int opc=0;
    char ***vuelo=NULL;
    vuelo=IniciarMatriz();
    do
    {
        printf("MENU:\n");
        printf("1.Reservar Boleto\n2.Cancelacion de boleto \n3.Mostrar Asientos\nOtro numero. Salir");
        printf("\nIngrese el numero de la opcion que desea elegir: ");
        scanf("%d",&opc);

        if(opc==1)
        {
            Reserva(vuelo);
        }
        else if(opc==2)
        {
            Cancelar(vuelo);
        }
        else if (opc==3)
        {
            PrintMatriz(vuelo);
        }
        else
            opc=0;
        
    } while (opc!=0);
    limpiar(vuelo);
    return 0;
}