#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// Estructura para representar un vehículo
struct Vehiculo {
    int tipo; // 1 para carro, 2 para moto
    int valor; // 1000 para carro, 500 para moto
    int valor_vehiculo; // Valor almacenado en el nodo
    Vehiculo *sig;
};

Vehiculo *cab, *aux;

int  valor = 0, 
valor_vehiculo = 0, 
valor_temp = 0;

// Funcion para insertar un vehículo en la pila
int insertar() {
    aux = (struct Vehiculo *) malloc(sizeof(struct Vehiculo));
    printf("Ingrese el tipo de vehiculo (1 carro, 2 moto): ");
    scanf("%d", &aux->tipo);
    if (aux->tipo == 1) {
        aux->valor = 1000;
    } if (aux->tipo == 2) {
        aux->valor = 500;
    }
    if (aux->tipo != 1 && aux->tipo != 2) {
        printf ("Tipo de vehiculo no valido");
    }
    if (cab == NULL) {
        cab = aux;
        cab->sig = NULL;
    } else {
        aux->sig = cab;
        cab = aux;
    }
    valor += valor_temp; 
    aux = NULL;
    free(aux);
}

// Funcion para eliminar un vehículo de la pila
int eliminar() {
    int tipo;
    printf("Ingrese el tipo de vehiculo a eliminar (1 carro, 2 moto): ");
    scanf("%d", &tipo);
    Vehiculo *temp = cab;

    while (temp != NULL && temp->tipo!= tipo) {
        temp = temp->sig;
        if (temp->tipo == (tipo == 1))
        {
            valor_vehiculo += 100;
        }
        if (temp->tipo == (tipo == 2))
        {
            valor_vehiculo += 50;
        }
        valor_temp += valor + valor_vehiculo;
    }
    if (cab == NULL || temp == NULL) {
        printf("No se encontró ningún vehículo del tipo deseado en el parqueadero\n");
        return 0;
    }
    free(temp);
}

// Funcion para mostrar los vehículos de la pila
int mostrar() {
    int num;
    aux = cab;
    while (aux != NULL) {
        num++;
        printf ("\nVehiculo#: %d\n", num);
        printf ("Tipo: %d\n", aux->tipo);
        printf ("Valor: %d\n", aux->valor);
        aux = aux->sig; 
    }
    return 0;
}

// Funcion para calcular el total
int calcular_total() {
    Vehiculo *temp = cab;
    int total = 0;
    int total_values = 0;
    while (temp!= NULL) {
        total_values += temp->valor + valor_vehiculo + valor_temp;
        temp = temp->sig;
    }
    total = total_values;
    return total;
}

int main() { 
    int opc, num = 0;
    printf ("-----------------------------------------------------------------\n");
    printf ("-----------------------------------------------------------------");
    printf ("\n\t\tBienvenido al programa de pilas\n");
    printf ("Este es un parqueadero en sistema L.I.F.O (Last In, First out)\n");
    printf ("-----------------------------------------------------------------\n");
    printf ("-----------------------------------------------------------------\n");
    do {
        printf ("\n\tMenu\n");
        printf ("\n1. Insertar\n");
        printf ("2. Eliminar\n");
        printf ("3. Mostrar\n");
        printf ("4. Calcular total\n");
        printf ("5. Salir\n");
        printf ("Ingrese una opcion: ");
        scanf ("%d", &opc);
        switch (opc) {
            case 1: 
                insertar();
                num = 0;
                aux = cab;
                while (aux != NULL) {
                    num++;
                    aux = aux->sig; 
                }   
                printf ("\nSe encuentran un total de %d en el parqueadero\n", num);
                break;
            case 2:
                eliminar();
                num = 0;
                aux = cab;
                while (aux != NULL) {
                    num++;
                    aux = aux->sig; 
                }   
                printf ("\nSe encuentran un total de %d en el parqueadero\n", num);
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf ("El total recaudado es: %d\n", calcular_total()); calcular_total();
                break;
            case 5:
                printf (" ");
                printf ("\n\tGracias por usar el programa\n");
                printf (" ");
                break;
            default:
                printf ("Opcion no valida\n");
        }
    } while (opc != 5);
    return 0;
}