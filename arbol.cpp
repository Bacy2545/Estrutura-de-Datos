#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudiante {
    int id, 
    anio,
    mes,
    dia;
    char nom,
    apellido;
    struct estudiante *izq, *der;
};

struct estudiante *raiz, *aux, *aux2;

// Funcion para posicionar por id
int posicionarid() {
    /* Si el ID del nuevo nodo es menor que el ID del 
    nodo actual, la funcion se mueve a la raiz izquierda */
    if (aux->id < aux2->id) {
        if (aux2->izq!= NULL)
        {
            aux2 = aux2->izq;
            posicionarid();
        } else {
            aux2->izq = aux;
        }   
    }
    /* Si el ID del nuevo nodo es mayor que el ID del
    nodo actual, la funcion se mueve a la raiz derecha */
    else if (aux->id > aux2->id) {
        if (aux2->der!= NULL)
        {
            aux2 = aux2->der;
            posicionarid();
        } else {
            aux2->der = aux;
        }   
    }
    /* Si el ID del nuevo nodo es igual al ID del nodo actual, la
    funcion se detiene y el nuevo nodo se inserta en el lugar correcto */
    return 0;
}

// Funcion para posicionar por fecha
int posicionarfecha() {
    /* Si el año del nuevo nodo es menor que el año del 
    nodo actual, la funcion se mueve a la raiz izquierdo */
    if (aux->anio < aux2->anio) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionarfecha();
        } else {
            aux2->izq = aux;
        }   
    }
    /* Si el año del nuevo nodo es mayor que el año del
    nodo actual, la funcion se mueve a la raiz derecho */
    else if (aux->anio > aux2->anio) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionarfecha();
        } else {
            aux2->der = aux;
        }   
    }
    /* Si los años son iguales, la funcion compara los meses
    y dias de la misma manera */
    else if (aux->mes < aux2->mes) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionarfecha();
        } else {
            aux2->izq = aux;
        }   
    }
    else if (aux->mes > aux2->mes) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionarfecha();
        } else {
            aux2->der = aux;
        }   
    }
    else if (aux->dia < aux2->dia) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionarfecha();
        } else {
            aux2->izq = aux;
        }   
    }
    else if (aux->dia > aux2->dia) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionarfecha();
        } else {
            aux2->der = aux;
        }   
    }
    return 0;
}

// Funcion para recorrer el arbol en pre-orden
int preorden (struct estudiante *recursivo) {
    // Imprime el ID, nombre y fecha del nodo actual
    printf ("ID: %d\n", recursivo->id);
    printf ("Nombre: %s\n", &recursivo->nom);
    printf ("%d/%d/%d\n", recursivo->dia, recursivo->mes, recursivo->anio);
    // Si el nodo tiene raiz a la izq, se llama a la funcion recursivamente a la izq
    if (recursivo->izq!= NULL)
        preorden(recursivo->izq);
    // Si el nodo tiene raiz a la der, se llama a la funcion recursivamente a la der
    if (recursivo->der!= NULL)
        preorden(recursivo->der);
    return 0;
}

// Funcion para recorrer el arbol en in-orden
int inorden (struct estudiante *recursivo) {
    // Si el nodo tiene raiz a la izq, se llama a la funcion recursivamente a la izq
    if (recursivo->izq!= NULL)
        inorden(recursivo->izq);
    // Imprime el ID, nombre y fecha del nodo actual
    printf ("ID: %d\n", recursivo->id);
    printf ("Nombre: %s\n", &recursivo->nom);
    printf ("%d/%d/%d\n", recursivo->dia, recursivo->mes, recursivo->anio);
    // Si el nodo tiene raiz a la der, se llama a la funcion recursivamente a la der
    if (recursivo->der!= NULL)
        inorden(recursivo->der);
    return 0;
}

// Funcion para recorrer el arbol en post-orden
int postorden (struct estudiante *recursivo) {
    // Si el nodo tiene raiz a la izq, se llama a la funcion recursivamente a la izq
    if (recursivo->izq!= NULL)
        postorden(recursivo->izq);
    // Si el nodo tiene raiz a la der, se llama a la funcion recursivamente a la der
    if (recursivo->der!= NULL)
        postorden(recursivo->der);
    // Imprime el ID del nodo actual
    printf ("ID: %d\n", recursivo->id);
    printf ("Nombre: %s\n", &recursivo->nom);
    printf ("%d/%d/%d\n", recursivo->dia, recursivo->mes, recursivo->anio);
    return 0;
}

int prerecorrer() {
    if (raiz!= NULL) {
        preorden(raiz);
    }
    return 0;
}

int inrecorrer() {
    if (raiz!= NULL) {
        inorden(raiz);
    }
    return 0;
}

int postrecorrer() {
    if (raiz!= NULL) {
        postorden(raiz);
    }
    return 0;
}

int insertar() {
    aux = (struct estudiante *) malloc (sizeof(struct estudiante));
    aux2 = (struct estudiante *) malloc (sizeof(struct estudiante));
    printf ("Ingrese el id: ");
    scanf ("%d", &aux->id);
    printf ("Ingrese el nombre: ");
    scanf ("%s", &aux->nom);
    printf ("ingrese la fecha de nacimiento (dia mes anio): ");
    scanf ("%d %d %d", &aux->dia, &aux->mes, &aux->anio);
    aux->izq = aux->der = NULL; 
    if (raiz == NULL) {
        raiz = aux;
        aux = NULL;
        free(aux);
    } else {
        aux2 = raiz;
        posicionarid();
        posicionarfecha();
    }
    return 0;
}

// Funcion para eliminar un nodo del arbol
int eliminar(int id) {
    aux = raiz;
    struct estudiante *aux3 = NULL;
    while (aux!= NULL) {
        if (aux->id == id) {
            if (aux->izq == NULL && aux->der == NULL) {
                if (aux3 == NULL) {
                    raiz = NULL;
                } else {
                    if (aux3->izq == aux) {
                        aux3->izq = NULL;
                    } else {
                        aux3->der = NULL;
                    }
                }
                free(aux);
                return 0;
            }
            if (aux->izq == NULL) {
                if (aux3 == NULL) {
                    raiz = aux->der;
                } else {
                    if (aux3->izq == aux) {
                        aux3->izq = aux->der;
                    } else {
                        aux3->der = aux->der;
                    }
                }
                free(aux);
                return 0;
            }
            if (aux->der == NULL) {
                if (aux3 == NULL) {
                    raiz = aux->izq;
                } else {
                    if (aux3->izq == aux) {
                        aux3->izq = aux->izq;
                    } else {
                        aux3->der = aux->izq;
                    }
                }
                free(aux);
                return 0;
            }
            if (aux->izq!= NULL && aux->der!= NULL) {
                struct estudiante *sustituto = aux->der;
                while (sustituto->izq!= NULL) {
                    sustituto = sustituto->izq;
                }
                aux->id = sustituto->id;
                aux->nom = sustituto->nom;
                aux->anio = sustituto->anio;
                aux->mes = sustituto->mes;
                aux->dia = sustituto->dia;
                eliminar(sustituto->id);
                return 0;
            }
        }
        else if (aux->id < id) {
            aux3 = aux;
            aux = aux->der;
        }
        else {
            aux3 = aux;
            aux = aux->izq;
        }
    }
    printf ("ID no encontrado\n");
    return 0;
}

// Funcion para buscar un nodo en el arbol
int buscar() {
    aux = raiz;
    int encontrado = 0, id;
    printf("Ingrese el ID del nodo a buscar: ");
    scanf("%d", &id);
    while (aux != NULL && encontrado == 0) {
        if (aux->id == id) {
            // Si se encuentra el nodo, se imprime su informacion
            printf ("ID: %d\n", aux->id);
            printf ("Nombre: %s\n", &aux->nom);
            printf ("%d/%d/%d\n", aux->dia, aux->mes, aux->anio);
            encontrado = 1;
        }
        else if (aux->id < id) {
            aux = aux->der;
        }
        else {
            aux = aux->izq;
        }
    }
    if (encontrado == NULL) {
        printf("ID no encontrado\n");
    }
    return 0;
}

int main() { 
    int opc, id;
        do {
        printf ("\n\tMenu\n");
        printf ("\n1. Insertar\n");
        printf ("2. Eliminar\n");
        printf ("3. Buscar\n");
        printf ("4. Recorrer arbol\n");
        printf ("5. Salir\n");
        printf ("\nIngrese una opcion: ");
        scanf ("%d", &opc);
        switch (opc) {
            case 1: 
                insertar();
                break;
            case 2:
                eliminar(id);
                break;
            case 3:
                buscar();
                break;
            case 4:
                printf ("\n1. Pre-orden.\n");
                printf ("2. In-orden.\n");
                printf ("3. Post-orden.\n");
                printf ("\nIngrese una opcion: ");
                scanf ("%d", &opc);
                switch (opc) {
                    case 1:
                        prerecorrer();
                        break;
                    case 2:
                        inrecorrer();
                        break;
                    case 3:
                        postrecorrer();
                        break;
                    default:
                        printf ("Opcion no valida\n");
                }
                break;
            case 5:
                printf (" ");
                printf ("\n\tGracias por usar el programa\n");
                printf (" ");
                break;
            default:
                printf ("Opcion no valida\n");
        }
    } while (opc!= 5);
    return 0;
}