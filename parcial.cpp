#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Producto
struct Producto {
  int id;
  char nombre[100];
  int cantidad;
  float precio_unidad;
  Producto *siguiente; // puntero
};

// Funcion para verificar si el id ya existe en el inventario
int El_fbi_o_que(struct Producto *usted, int id) {
  struct Producto *actual = usted;
  while (actual != NULL) {
    if (actual->id == id) {
      return 1; // El ID ya existe
    }
    actual = actual->siguiente;
  }
  return 0; // El ID no existe
}

// Funcion para registrar un nuevo producto al final de la cola
void registrar(struct Producto **usted) {
  int numProductos, num = 0;
  printf("Cuantos productos va a registrar? ");
  scanf("%d", &numProductos);
  while (num < numProductos) {
    struct Producto *nuevo_producto =
        (struct Producto *)malloc(sizeof(struct Producto) * numProductos);
    if (nuevo_producto == NULL) {
      printf("Error al asignar memoria para el nuevo producto.\n");
      return;
    }

    int id;
    do {
      printf("\nIngrese el ID del producto: ");
      scanf("%d", &id);
      if (El_fbi_o_que(*usted, id)) {
        printf("El ID ya existe. Intente nuevamente.\n");
      }
    } while (El_fbi_o_que(*usted, id));

    nuevo_producto->id = id;

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevo_producto->nombre);
    printf("Ingrese la cantidad de unidades disponibles: ");
    scanf("%d", &nuevo_producto->cantidad);
    printf("Ingrese el precio por unidad: ");
    scanf("%f", &nuevo_producto->precio_unidad);

    nuevo_producto->siguiente = NULL;

    // Agregar al final de la cola
    if (*usted == NULL) {
      *usted = nuevo_producto;
    } else {
      struct Producto *actual = *usted;
      while (actual->siguiente != NULL) {
        actual = actual->siguiente;
      }
      actual->siguiente = nuevo_producto;
    }
    num++;
  }
}

// Funcion para mostrar todos los productos en el inventario
void mostrar(struct Producto *usted) {
  printf("\nInventario:\n");
  struct Producto *actual = usted;
  while (actual != NULL) {
    printf("ID: %d, Nombre: %s, Cantidad: %d, Precio por unidad: $%.2f\n",
           actual->id, actual->nombre, actual->cantidad, actual->precio_unidad);
    actual = actual->siguiente;
  }
}

// Funcion para buscar y mostrar información de un producto por su id
void me_perdi(struct Producto *usted, int id) {
  struct Producto *actual = usted;
  while (actual != NULL) {
    if (actual->id == id) {
      printf("\nInformación del producto con ID %d:\n", id);
      printf("Nombre: %s\n", actual->nombre);
      printf("Cantidad: %d\n", actual->cantidad);
      printf("Precio por unidad: $%.2f\n", actual->precio_unidad);
      return;
    }
    actual = actual->siguiente;
  }
  printf("Producto con ID %d no encontrado.\n", id);
}

// Funcion para eliminar un producto por su ID
void eliminar_producto(struct Producto **usted, int id) {
  struct Producto *actual = *usted;
  struct Producto *anterior = NULL;

  while (actual != NULL) {
    if (actual->id == id) {
      if (anterior == NULL) {
        // El producto a eliminar es el primero en la lista
        *usted = actual->siguiente;
      } else {
        anterior->siguiente = actual->siguiente;
      }
      free(actual);
      printf("Producto con ID %d eliminado correctamente.\n", id);
      return;
    }
    anterior = actual;
    actual = actual->siguiente;
  }

  printf("Producto con ID %d no encontrado.\n", id);
}

// Funcion para calcular el promedo
float promedio(struct Producto *usted) {
  float suma_precios = 0;
  int total_productos = 0;
  struct Producto *actual = usted;
  while (actual != NULL) {
    suma_precios += actual->precio_unidad;
    total_productos++;
    actual = actual->siguiente;
  }
  return suma_precios / total_productos;
}

// Funcion para calcular el promedio de precios
float valtotal(struct Producto *usted) {
  float total = 0;
  struct Producto *actual = usted;
  while (actual != NULL) {
    total += actual->cantidad * actual->precio_unidad;
    actual = actual->siguiente;
  }
  return total;
}

// Función para vender un producto
void bonice(struct Producto *usted, int vender, int can_compra) {
  struct Producto *producto = usted;
  while (producto != NULL) {
    if (producto->id == vender) {
      if (producto->cantidad >= can_compra) {
        float total_pagar = can_compra * producto->precio_unidad;
        producto->cantidad -= can_compra;
        printf("Producto vendido: %s (ID: %d)\n", producto->nombre,
               producto->id);
        printf("Cantidad vendida: %d\n", can_compra);
        printf("Total a pagar: $%.2f\n", total_pagar);
      } else {
        printf("No hay suficientes existencias para vender.\n");
      }
      return;
    }
    producto = producto->siguiente;
  }
  printf("Producto con ID %d no encontrado.\n", vender);
}

// Funcion para liberar la memoria asignada
void me_libere(struct Producto *usted) {
  struct Producto *actual = usted;
  while (actual != NULL) {
    struct Producto *temp = actual;
    actual = actual->siguiente;
    free(temp);
  }
}

int main() {
  struct Producto *usted = NULL;
  int opcion = 0;

  do {
    printf("\n1. Registrar productos\n");
    printf("2. Mostrar el inventario\n");
    printf("3. Buscar un producto\n");
    printf("4. Eliminar producto\n");
    printf("5. Promedio de precios\n");
    printf("6. Valor total de precios\n");
    printf("7. Vender productos\n");
    printf("8. Salir\n");
    printf("Seleccione una Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      registrar(&usted);
      break;
    case 2:
      mostrar(usted);
      break;
    case 3: {
      printf("Ingrese el ID del producto a buscar: ");
      int id_buscar;
      scanf("%d", &id_buscar);
      me_perdi(usted, id_buscar);
      break;
    }
    case 4: {
      int id_eliminar;
      printf("\nIngrese el ID del producto a eliminar: ");
      scanf("%d", &id_eliminar);
      eliminar_producto(&usted, id_eliminar);
      break;
    }
    case 5: {
      float precio_promedio = promedio(usted);
      printf("Precio promedio por unidad: $%.2f\n", precio_promedio);
      break;
    }
    case 6: {
      float val_total = valtotal(usted);
      printf("Valor total del inventario: $%.2f\n", val_total);
      break;
    }
    case 7: {
      int vender;
      printf("Ingrese el ID del producto a vender: ");
      scanf("%d", &vender);
      int comprar;
      printf("Ingrese la cantidad de unidades a comprar: ");
      scanf("%d", &comprar);
      bonice(usted, vender, comprar);
      break;
    }
    case 8:
      me_libere(usted);
      printf("Hasta luego\n");
      break;
    default:
      printf("Opcion invalida. Intente nuevamente.\n");
      break;
    }
  } while (opcion != 8);

  return 0;
}