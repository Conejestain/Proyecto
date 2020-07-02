#include "Funciones.h"

int main(){

    short opcion;
    do{
        printf("1-Crear informe de dia\n");
        printf("2-Acceder a medicinas\n");
        printf("3-Acceder a equipo medico\n");
        printf("4-Añadir inventario\n");
        printf("5-Cerrar programa\n");
        scanf("%di",opcion);
        if(opcion==1){
            //se crea informe del dia

        }
        if(opcion==2){
            system("cls");
            fflush(stdin);
            //se accede a medicinas
            printf("1-Buscar la marca de medicina \n");
            printf("2-Mostrar medicinas por tipo \n");
            printf("3-Mostrar todas las medicinas\n");
            printf("4-Volver\n");
            scanf("%di ",opcion);
            if(opcion==1){
                //busca medicina por
            }
            if(opcion==2){
            }
            if(opcion==3){
            }
            if(opcion==4){
            }
            opcion=2;
        }
        if(opcion==3){
            system("cls");
            fflush(stdin);
            printf("1-Buscar equipo por nombre\n");
            printf("2-Mostrar todo el equipo\n");
            printf("3-Volver\n");
            scanf("%di",opcion);
            if(opcion==1){

            }
            if(opcion==2){

            }
            if(opcion==3){

            }
            opcion=3;
        }
        if(opcion==4){
            system("cls");
            fflush(stdin);
            //añadir inventario
            printf("1-Añadir medicina");
            printf("2-Actualizar equipo");
            scanf("%di",opcion);
            if(opcion=1){

            }
            if(opcion=2){

            }
            opcion=4;
        }
        if(opcion==5){
            system("cls");
            fflush(stdin);
            //funcion de actualizar inventario
        }
    }while(opcion==5);
    return 0;
}
