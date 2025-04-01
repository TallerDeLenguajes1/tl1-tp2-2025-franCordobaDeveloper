#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct compu {
    int velocidad;  // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;  // Año de fabricación (valor entre 2015 y 2025)
    int cantidad_nucleos;  // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;  // Tipo de procesador (apuntador a cadena de caracteres)
};

// Prototipo de Funciones
void cargarCompu(struct compu pcs[], int cantidad);

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);


int main()
{   
    struct compu pcs[5];
    srand(time(NULL));

    cargarCompu(pcs, 5);
    
    listarPCs(pcs, 5);

    printf("--- PC mas Vieja --- \n");
    mostrarMasVieja(pcs, 5);

    printf("--- PC mas veloz --- \n");
    mostrarMasVeloz(pcs, 5);

    return 0;
}

void cargarCompu(struct compu pcs[], int cantidad) 
{
    
    
    char *tipos[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    for (int i = 0; i < cantidad; i++)
    {
        pcs[i].velocidad = 1 + rand() % (3 - 1 + 1);
        pcs[i].anio = 2015 + rand() % ( 2025 - 2015 + 1);
        pcs[i].cantidad_nucleos = 1 + rand() % 8;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    
    }
    
}

void listarPCs(struct compu pcs[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("----- Listando pc[%d] -----\n", i+1);
        printf("Tipo de CPU: %s \n", pcs[i].tipo_cpu);
        printf("Velocidad de Procesamiento: %d GHz \n", pcs[i].velocidad);
        printf("Anio de Creacion: %d \n", pcs[i].anio);
        printf("Cantidad de Nucleo: %d \n", pcs[i].cantidad_nucleos);
        printf("\n");
    }
    
}

void mostrarMasVieja(struct compu pcs[], int cantidad)
{
    struct compu pcVieja = pcs[0];

    for (int i = 0; i < cantidad; i++)
    {
        if(pcVieja.anio > pcs[i].anio) {
            pcVieja = pcs[i];
        }
    }
    printf("Tipo de CPU: %s \n", pcVieja.tipo_cpu);
    printf("Velocidad de Procesamiento: %d GHz \n", pcVieja.velocidad);
    printf("Anio de Creacion: %d \n", pcVieja.anio);
    printf("Cantidad de Nucleo: %d \n", pcVieja.cantidad_nucleos);
    printf("\n");

}

void mostrarMasVeloz(struct compu pcs[], int cantidad)
{
    struct compu compuMasVeloz = pcs[0];

    for (int i = 0; i < cantidad; i++)
    {
        if(compuMasVeloz.velocidad < pcs[i].velocidad) {
            compuMasVeloz = pcs[i];
        }
    }

    printf("Tipo de CPU: %s \n", compuMasVeloz.tipo_cpu);
    printf("Velocidad de Procesamiento: %d GHz \n", compuMasVeloz.velocidad);
    printf("Anio de Creacion: %d \n", compuMasVeloz.anio);
    printf("Cantidad de Nucleo: %d \n", compuMasVeloz.cantidad_nucleos);
    printf("\n");
    
}
