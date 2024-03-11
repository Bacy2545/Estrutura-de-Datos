// Akil Yamid Barona Chalare
// Miguel Angel Cabuyales
#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un paciente
struct Paciente {
    char nombre[10], apellido[10];
    int numeroDocumento;
};

// Función para registrar un paciente
void registrarPaciente(struct Paciente pacientes[], int *totalPacientes) {
    int numpacientes, numeros=0;
    printf("Cuantos pacientes quiere registrar?\n");
    printf("Dijite el numero de pacientes a registrar: ");
    scanf("%d", &numpacientes);
    while (numeros<numpacientes)
    {
        if (*totalPacientes < 100) { // Límite de pacientes
            printf("\nIngrese el nombre del paciente: ");
            scanf("%s", pacientes[*totalPacientes].nombre);
            printf("Ingrese el número de documento: ");
            scanf("%d", &pacientes[*totalPacientes].numeroDocumento);
            (*totalPacientes)++;
            numeros++;
        
        printf("Pacientes registrados con éxito.\n");
        } 
        else {
            printf("No se pueden registrar más pacientes. La cola está llena.\n");
        }
    }   
}

// Función para mostrar los pacientes registrados
void mostrarPacientes(struct Paciente pacientes[], int totalPacientes) {
    printf("Pacientes registrados:\n");
    for (int i = 0; i < totalPacientes; i++) {
        printf("%d. Nombre: %s, Documento: %d\n", i + 1, pacientes[i].nombre, pacientes[i].numeroDocumento);
    }
}

int main() {
    struct Paciente pacientes[100]; // Arreglo de pacientes
    int totalPacientes = 0; // Contador de pacientes registrados

    int opcion;
    do {
        printf("\nMenú:\n");
        printf("1. Registrar paciente\n");
        printf("2. Mostrar pacientes\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarPaciente(pacientes, &totalPacientes);
                break;
            case 2:
                mostrarPacientes(pacientes, totalPacientes);
                break;
            case 3:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
    return 0;
}
