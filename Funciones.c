#include "Funciones.h"

typedef struct Remedio{
    char Marca[45];
    char Tipo[45];
    int Stock;
    int Precio;
    int Ventas;
}Remedio;

typedef struct Equipo{
    char Nombre[45];
    int Stock;
    int Precio;
    int Uso;
}Equipo;

//función que retorna 1 si las claves son iguales y 0 si son distintas
int CmpHash(const void * key1, const void * key2) {
    const char * Key1 = key1;
    const char * Key2 = key2;
    if(strcmp(Key1, Key2)==0) return 1;
    return 0;
}

//función que retorna negativo si key1<key2, positivo si key1>key2
//y 0 si las claves son iguales
int CmpSorted(const void * key1, const void * key2) {
    const char * Key1 = key1;
    const char * Key2 = key2;
    return strcmp(Key1,Key2);
}

Remedio *CrearRemedio(char Marca[],char Tipo[],int Stock,int Precio,int Ventas){
    Remedio *Aux=(Remedio*)malloc(sizeof(Remedio));
    strcpy(Aux->Marca,Marca);
    strcpy(Aux->Tipo,Tipo);
    Aux->Stock=Stock;
    Aux->Precio=Precio;
    Aux->Ventas=Ventas;
    return Aux;
}

Equipo *CrearEquipo(char Nombre[],int Stock,int Precio,int Uso){
    Equipo* Aux=(Equipo*)malloc(sizeof(Equipo));
    strcpy(Aux->Nombre,Nombre);
    Aux->Stock=Stock;
    Aux->Precio=Precio;
    Aux->Uso=Uso;
    return Aux;
}

void ActualizarEquipo(SortedMap *Equipos,Equipo *NuevoEquipo){
    Equipo *Aux=searchSortedMap(Equipos,NuevoEquipo->Nombre);
    if(!Aux){
        insertSortedMap(Equipos,NuevoEquipo->Nombre,NuevoEquipo);
    }else{
        Aux->Stock=Aux->Stock+NuevoEquipo->Stock;
        Aux->Precio=NuevoEquipo->Precio;
        free(NuevoEquipo);
    }
}

// TE QUEDASTE AQUI
void AgregarRemedios(Map *Remedios,Map *Tipo,Remedio *NuevoRemedio){
    Remedio *Aux=searchMap(Remedios,NuevoRemedio->Marca);
    SortedMap *Aux2=searchMap(Tipo,NuevoRemedio->Tipo);
    if(!Aux2){
        Aux2=createSortedMap(CmpSorted);
        insertSortedMap(Aux2,NuevoRemedio->Marca,NuevoRemedio);
        insertMap(Tipo,NuevoRemedio->Tipo,Aux2);
    }
    if(!Aux){
        insertMap(Remedios,NuevoRemedio->Marca,NuevoRemedio);
    }
}

void Arranque(Map *Tipos,Map *Remedios,SortedMap *Equipos){
            FILE *Fp=NULL;
            Fp=fopen("Inventario.csv", "r");
            if(Fp==NULL){
                printf("\nERROR\nno se a podido encontrar el archivo de arranque(Inventario.csv) fin del programa");
                return 1;
            }
            char Nombre[45];
            char Tipo[45];
            int Stock;
            int Precio;
            int Uso;
            fscanf(Fp,"%[^\n]",&Nombre);
            fgetc(Fp);
            while(fscanf(Fp,"%[^.]",&Nombre)!=EOF){
                if(strcmp(Nombre,"remedios")==0) break;

                fscanf(Fp,"%d[^.]",&Stock);
                fgetc(Fp);

                fscanf(Fp,"%d[^.]",&Precio);
                fgetc(Fp);

                fscanf(Fp,"%d[^\n]",&Uso);
                fgetc(Fp);

                ActualizarEquipo(Equipos,CrearEquipo(Nombre,Stock,Precio,Uso));
            }

            fclose(Fp);
}
