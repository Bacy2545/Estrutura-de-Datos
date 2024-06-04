#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcmp para comparar char
// sprintf similar a String

struct pasajero {
    char nombre[50];
    struct pasajero *sig;
};

struct nodo {
    double PrecioViaje;
    int destino, altura, num = 0;
    char MatriculaEmbarcacion, NombreEmbarcacion[10], id[15];
    int dia, mes, year;
    int CapacidadEmbarcacion;
    struct pasajero *pasajeros;
    struct nodo *izq, *der, *sig;
};

struct nodo *raiz = NULL, *aux, *aux2, *aux3; 

int obtenerAltura(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(char a, char b) {
    return (a > b) ? a : b;
}

struct nodo* rotarDerecha(struct nodo *y) {
    struct nodo *x = y->izq;
    struct nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

struct nodo* rotarIzquierda(struct nodo *x) {
    struct nodo *y = x->der;
    struct nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

int obtenerBalance(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izq) - obtenerAltura(n->der);
}

struct nodo* insertar(struct nodo* nodo) {
    if (nodo == NULL) {
        return aux;
    }

    if (aux->id < nodo->id) {
        nodo->izq = insertar(nodo->izq);
    } else if (aux->id > nodo->id) {
        nodo->der = insertar(nodo->der);
    } else {
        return nodo;
    }

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && aux->id < nodo->izq->id) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->id > nodo->der->id) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && aux->id > nodo->izq->id) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->id < nodo->der->id) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

int RegistrarViaje() {
    int destino;
    int dia, 
    mes, 
    year;
    char matricula;

    aux = (struct nodo*)malloc(sizeof(struct nodo));
    printf("\nA donde se dirige?\n");
    printf("\t1. Argentina($147150)         2. Brasil($76541)\n");
    printf("\t3. Chile($134520)             4. Ecuador($24177)\n");
    printf("\t5. Paraguay($103808)          6. Peru($26810)\n");
    printf("\t7. Uruguay($134926)           8. Tour($5900)\n");
    printf("Opcion: ");
    scanf("%d", &aux->destino);
    
    destino = aux->destino;
    if (destino == 1) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 147150 + 15000;
    }
    if (destino == 2) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 76541 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Brasil");
    } 
    if (destino == 3) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 134520 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Chile");
    } 
    if (destino == 4) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 24177 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Ecuador");
    } 
    if (destino == 5) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 103808 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Paraguay");
    }
    if (destino == 6) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 26810 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Peru");
    }
    if (destino == 7) { 
        printf("\nSe le agregara un valor adicional de $15000\n"); 
        aux->PrecioViaje = 134926 + 15000;
        //sprintf(aux->NombreEmbarcacion, "Uruguay");
    } 
    if (destino == 8) { 
        aux->PrecioViaje = 5900;
        //sprintf(aux->NombreEmbarcacion, "Viaje turistico");
    }
    if (destino < 1 || destino > 8) {
    printf("La opción ingresada no es válida.\n");
    return 1;
    }
    
    printf("\nLa matricula del embarque es: ");
    scanf("%s", &aux->MatriculaEmbarcacion);
    
    printf("\nDigite la fecha del viaje (dia/mes/año): ");
    scanf("%d %d %d", &aux->dia, &aux->mes, &aux->year);
    if (aux->mes == 2 && (aux->dia < 1 || aux->dia > 28)) {
    if (aux->year % 4 == 0) {
        if (aux->year % 100 == 0) {
            if (aux->year % 400 == 0) {
                if (aux->dia < 1 || aux->dia > 29) {
                    printf("La fecha ingresada no es válida.\n");
                    return 1;
                }
            } else {
                if (aux->dia < 1 || aux->dia > 28) {
                    printf("La fecha ingresada no es válida.\n");
                    return 1;
                }
            }
        } else {
            if (aux->dia < 1 || aux->dia > 29) {
                printf("La fecha ingresada no es válida.\n");
                return 1;
            }
        }
    } else {
        if (aux->dia < 1 || aux->dia > 28) {
            printf("La fecha ingresada no es válida.\n");
            return 1;
        }
    }
    } else if (aux->mes == 4 || aux->mes == 6 || aux->mes == 9 || aux->mes == 11) {
        if (aux->dia < 1 || aux->dia > 30) {
            printf("La fecha ingresada no es válida.\n");
            return 1;
        }
    } else {
        if (aux->dia < 1 || aux->dia > 31) {
            printf("La fecha ingresada no es válida.\n");
            return 1;
        }
    }
    
    printf("\nDigite la capacidad maxima del embarque: ");
    scanf("%d", &aux->CapacidadEmbarcacion);

    printf("\nIntroduzca el nombre de la embarcacion: ");
    scanf("%s", aux->NombreEmbarcacion);

    dia = aux->dia;
    mes = aux->mes;
    year = aux->year;
    matricula = aux->MatriculaEmbarcacion;
    
    sprintf(aux->id, "%.2s-%04d%02d%02d", &matricula, year, mes, dia);
    printf("\nEl identificador es: %s\n", aux->id);
    printf("\nViaje registrado con exito.\n");

    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;
    raiz = insertar(raiz);
    return 0;
}

struct nodo* buscarViaje(struct nodo* nodo, char* id) {
    if (nodo == NULL || strcmp(nodo->id, id) == 0) {
        return nodo;
    }

    if (strcmp(id, nodo->id) < 0) {
        return buscarViaje(nodo->izq, id);
    } else {
        return buscarViaje(nodo->der, id);
    }
}

int BuscarViaje() {
    char id[15];
    printf("\nDigite el identificador del viaje: ");
    scanf("%s", id);

    struct nodo* resultado = buscarViaje(raiz, id);

    if (resultado != NULL) {
        printf("\nViaje encontrado:\n");
        printf("ID: %s\n", resultado->id);
        printf("Destino: %d\n", resultado->destino);
        printf("Precio: %.2f\n", resultado->PrecioViaje);
        printf("Matricula: %s\n", &resultado->MatriculaEmbarcacion);
        printf("Nombre del viaje: %s\n", resultado->NombreEmbarcacion);
        printf("Fecha: %02d/%02d/%04d\n", resultado->dia, resultado->mes, resultado->year);
        printf("Capacidad: %d\n", resultado->CapacidadEmbarcacion);
    } else {
        printf("\nViaje no encontrado.\n");
    }

    return 0;
}

int listarViajes(struct nodo* nodo) {
    if (nodo != NULL) {
        listarViajes(nodo->izq);
        printf("\nViaje:\n");
        printf("ID: %s\n", nodo->id);
        printf("Destino: %d\n", nodo->destino);
        printf("Precio: $%.2f\n", nodo->PrecioViaje);
        printf("Matricula: %s\n", &nodo->MatriculaEmbarcacion);
        printf("Nombre del viaje: %s\n", nodo->NombreEmbarcacion);
        printf("Fecha: %02d/%02d/%04d\n", nodo->dia, nodo->mes, nodo->year);
        printf("Capacidad: %d\n", nodo->CapacidadEmbarcacion);
        listarViajes(nodo->der);
    }
    return 0;
}

int ListarViaje() {
    if (raiz == NULL) {
        printf("\nNo hay viajes registrados.\n");
    } else {
        printf("\nLista de todos los viajes:\n");
        listarViajes(raiz);
    }
    return 0;
}

struct nodo* nodoConValorMinimo(struct nodo* nodo) {
    struct nodo* actual = nodo;

    while (actual->izq != NULL) {
        actual = actual->izq;
    }

    return actual;
}

struct nodo* eliminarNodo(struct nodo* raiz, char* id) {
    if (raiz == NULL) {
        return raiz;
    }

    if (strcmp(id, raiz->id) < 0) {
        raiz->izq = eliminarNodo(raiz->izq, id);
    } else if (strcmp(id, raiz->id) > 0) {
        raiz->der = eliminarNodo(raiz->der, id);
    } else {
        if ((raiz->izq == NULL) || (raiz->der == NULL)) {
            struct nodo *temp = raiz->izq ? raiz->izq : raiz->der;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            struct nodo* temp = nodoConValorMinimo(raiz->der);
            strcpy(raiz->id, temp->id);
            raiz->destino = temp->destino;
            raiz->PrecioViaje = temp->PrecioViaje;
            strcpy(&raiz->MatriculaEmbarcacion, &temp->MatriculaEmbarcacion);
            raiz->dia = temp->dia;
            raiz->mes = temp->mes;
            raiz->year = temp->year;
            raiz->CapacidadEmbarcacion = temp->CapacidadEmbarcacion;
            raiz->der = eliminarNodo(raiz->der, temp->id);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + mayor(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    int balance = obtenerBalance(raiz);

    if (balance > 1 && obtenerBalance(raiz->izq) >= 0) {
        return rotarDerecha(raiz);
    }

    if (balance > 1 && obtenerBalance(raiz->izq) < 0) {
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->der) <= 0) {
        return rotarIzquierda(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->der) > 0) {
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }

    return raiz;
}

int EliminarViaje() {
    char id[15];
    printf("\nDigite el identificador del viaje a eliminar: ");
    scanf("%s", id);

    raiz = eliminarNodo(raiz, id);

    if (raiz == NULL) {
        printf("\nEl viaje no fue encontrado o el árbol está vacío.\n");
    } else {
        printf("\nViaje eliminado con éxito.\n");
    }

    return 0;
}

int RegistrarPasajero() {
    char id[15];
    struct nodo *viaje = NULL;

    printf("\nIngrese el identificador del viaje: ");
    scanf("%s", id);

    
    viaje = buscarViaje(raiz, id);

    if (viaje == NULL) {
        printf("No se encontró un viaje con el identificador %s.\n", id);
        return 1;
    }

    struct pasajero *nuevoPasajero = (struct pasajero *)malloc(sizeof(struct pasajero));
    printf("\nIngrese el nombre del pasajero: ");
    scanf("%s", nuevoPasajero->nombre);
    nuevoPasajero->sig = NULL;

    printf("\nIngrese el nombre del pasajero: ");

    // Añadir el pasajero a la lista de pasajeros del viaje
    if (viaje->pasajeros == NULL) {
        viaje->pasajeros = nuevoPasajero;
        printf("\nIngrese el nombre del pasajero: ");
    } else {
        struct pasajero *temp = viaje->pasajeros;
        while (temp->sig != NULL) {
            temp = temp->sig;
            printf("\nIngrese el nombre del pasajero: ");
        }
        temp->sig = nuevoPasajero;
    }

    printf("\nIngrese el nombre del pasajero: ");

    if (viaje->num >= viaje->CapacidadEmbarcacion) {
        printf("El viaje ya ha alcanzado su capacidad máxima.\n");
        return 1;
    }

    printf("\nIngrese el nombre del pasajero: ");

    viaje->num++;
    printf("Pasajero registrado con éxito en el viaje %s.\n", id);

    return 0;
}

int listarPasajero() {
    char id[15];
    struct nodo *viaje = NULL;

    printf("\nIngrese el identificador del viaje: ");
    scanf("%s", id);

    // Buscar el viaje en el árbol AVL
    viaje = buscarViaje(raiz, id);

    if (viaje == NULL) {
        printf("No se encontró un viaje con el identificador %s.\n", id);
        return 1;
    }

    printf("\nLista de pasajeros del viaje %s:\n", id);
    if (viaje->pasajeros == NULL) {
        printf("No hay pasajeros registrados en este viaje.\n");
    } else {
        struct pasajero *temp = viaje->pasajeros;
        while (temp != NULL) {
            printf("Nombre: %s\n", temp->nombre);
            temp = temp->sig;
        }
    }

    return 0;
}

int main() {
    int opcion = 0;

    do {
        printf("\n\tMENU\n");
        printf("1. Registrar viaje\n");
        printf("2. Buscar un viaje por identificador\n");
        printf("3. Listar todos los viajes\n");
        printf("4. Eliminar un viaje por identificador\n");
        printf("5. Registrar un pasajero en un viaje\n");
        printf("6. Listar todos los pasajeros de un viaje\n");
        printf("7. Salir\n");

        printf("\nDigite la opcion que desea realizar: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                RegistrarViaje();
                break;
            case 2:
                BuscarViaje();
                break;
            case 3:
                ListarViaje();
                break;
            case 4:
                EliminarViaje();
                break;
            case 5:
                RegistrarPasajero();
                break;
            case 6:
                listarPasajero();
                break;
            case 7:
                printf("\nGracias por usar nuestro programa... Saliendo\n");
                break;
            default:
                printf("\nLa opción que digitaste no se encuentra disponible, por favor digite la opción nuevamente:\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}