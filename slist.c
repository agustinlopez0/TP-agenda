#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Agenda crear_agenda(){
    return NULL;
}

void menu(Agenda agenda){
    int bandera = 1, opcion, validacion;
    char cadena[20];
    while(bandera){
        printf("\n\nElija una opcion del menu:\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
        218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,
        196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
        printf("%c 1. Crea un nuevo contacto                       %c\n", 179, 179);
        printf("%c 2. Mostrar todos los contactos                  %c\n", 179, 179);
        printf("%c 3. Buscar un contacto por su nombre             %c\n", 179, 179);
        printf("%c 4. Buscar un contacto por su numero de telefono %c\n", 179, 179);
        printf("%c 5. Eliminar contacto por nombre                 %c\n", 179, 179);
        printf("%c 6. Eliminar todos los contactos                 %c\n", 179, 179);
        printf("%c 7. Salir                                        %c\n", 179, 179);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
        192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,
        196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
        printf("\n\nIngrese un numero: ");
        scanf("%i", &opcion);
        printf("\n");
        switch(opcion){
            case 1:
                agenda = nuevoContacto(agenda, juntarDatos());
                break;
            case 2:
                muestraContactos(agenda);
                break;
            case 3:
                printf("Ingrese la cadena de caracteres que quiere encontrar: ");
                scanf("%s", cadena);
                printf("\n");
                muestraContactos(buscaContactosNombre(agenda, cadena));
                break;
            case 4:
                printf("Ingrese el numero de telefono que quiere encontrar: ");
                scanf("%s", cadena);
                printf("\n");
                muestraContactos(buscaContactosTelefono(agenda, cadena));
                break;
            case 5:
                printf("Ingrese el nombre del contacto que desea eliminar: ");
                scanf("%s", cadena);
                printf("\n");
                agenda = eliminarContactoNombre(agenda, cadena);
                break;
            case 6:
                agenda = eliminarTodosContactos(agenda);
                break;
            case 7:
                printf("Realmente desea salir del programa?\n1. Si\n2. No\nOpcion: ");
                scanf("%i", &validacion);
                if(validacion == 1){
                    bandera = 0;
                    agenda = salida(agenda);
                    saludar();
                }
                break;
            default:   
                printf("Opcion invalida, vuelva a intentarlo");
        }
    }
}




Contacto juntarDatos(){
    
    Contacto datos_contacto;
    char temp[256];

    printf("Ingrese nombre del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.nombre = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.nombre, temp);
    
    
    printf("Ingrese direccion del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.direccion = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.direccion, temp);

    
    printf("Ingrese telefono del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.telefono = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.telefono, temp);

    
    printf("Ingrese mail del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.mail = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.mail, temp);

    
    printf("Ingrese alias de telegram del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.aliasTelegram = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.aliasTelegram, temp);

    
    printf("Ingrese usuario de instagram del Contacto: ");
    getchar();
    scanf("%[^\n]", temp);
    datos_contacto.usuarioInstagram = malloc(sizeof(char)*strlen(temp) + 1);
    strcpy(datos_contacto.usuarioInstagram, temp);

    return datos_contacto;
}

Agenda nuevoContacto(Agenda agenda, Contacto contacto) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->dato = contacto;
    nuevoNodo->sig = NULL;

    if(agenda == NULL)
        return nuevoNodo;

    Nodo *nodo = agenda;
    for(;nodo->sig != NULL; nodo = nodo->sig){
        if(!strcmp(nodo->dato.nombre, nuevoNodo->dato.nombre)){
            printf("\n\nEl nombre que ha ingresado ya ha sido usado.\n");
            return agenda;
        }
    }
    nodo->sig = nuevoNodo;

    return agenda;
}

void muestraContactos(Agenda agenda){
    if(agenda == NULL)
        printf("No se encontro ningun contacto");
    else{
        Nodo *nodo = agenda;
        printf("Lista de contactos: \n");
        for (; nodo != NULL; nodo = nodo->sig){
            printf("| %-20s| %-20s| %-20s| ", nodo->dato.nombre, nodo->dato.direccion, nodo->dato.telefono);
            printf(" %-20s| %-20s| %-20s|\n", nodo->dato.mail, nodo->dato.aliasTelegram, nodo->dato.usuarioInstagram);
        }
        free(nodo);
    }
    
}

Agenda buscaContactosNombre(Agenda agenda, char *cadena){
    Agenda nuevaAgenda = crear_agenda();
    Nodo *nodo = agenda;

    for(;nodo != NULL; nodo = nodo->sig)
        if(strstr(nodo->dato.nombre, cadena) != NULL)
            nuevaAgenda = nuevoContacto(nuevaAgenda, nodo->dato);
    free(nodo);
    return nuevaAgenda;
}

Agenda buscaContactosTelefono(Agenda agenda, char *telefono){
    Agenda nuevaAgenda = crear_agenda();
    Nodo *nodo = agenda;

    for(;nodo != NULL; nodo = nodo->sig)
        if(strstr(nodo->dato.telefono, telefono) != NULL)
            nuevaAgenda = nuevoContacto(nuevaAgenda, nodo->dato);
    
    free(nodo);
    return nuevaAgenda;
}

Agenda eliminarContactoNombre(Agenda agenda, char *nombre){
    
    Nodo *nodo = agenda;
    Nodo *nodoAEliminar;
    int bandera = 0, validacion;    
    
    if(agenda == NULL){
        printf("\nNo hay contactos para eliminar, la agenda esta vacia :(");
        return NULL;
    }

    if(nodo->sig == NULL && strcmp(nodo->dato.nombre, nombre)==0){
        printf("Realmente desea eliminar el contacto?\n1. Si\n2. No\nConfirmacion: ");
        scanf("%i", &validacion);
        if(validacion == 1){
            printf("\nEl contacto %s ha sido eliminado\n",nodo->dato.nombre);
            freeNodo(nodo);
            return NULL;
        } else {
            printf("No se ha eliminado el contacto");
            return agenda;
        }
    }
    
    for(;nodo->sig != NULL; nodo = nodo->sig){
        if(bandera == 0 && strcmp(nodo->dato.nombre, nombre) == 0){
            printf("Realmente desea eliminar el contacto?\n1. Si\n2. No\nConfirmacion: ");
            scanf("%i", &validacion);
            if(validacion == 1){
                printf("\nEl contacto %s ha sido eliminado\n",nodo->dato.nombre);
                nodoAEliminar = nodo;
                nodo = nodo->sig;
                freeNodo(nodoAEliminar);
                return nodo;
            } else {
                printf("No se ha eliminado el contacto");
                return agenda;
            }
        } else if(strcmp(nodo->sig->dato.nombre,nombre)==0){
            printf("Desea eliminar el contacto?\n1. Si\n2. No\nConfirmacion: ");
            scanf("%i", &validacion);
            if(validacion == 1){
                printf("\nEl contacto %s ha sido eliminado\n",nodo->sig->dato.nombre);
                nodoAEliminar = nodo->sig;
                if(nodo->sig->sig == NULL){
                    nodo->sig = NULL;
                } else{ 
                    nodo->sig = nodo->sig->sig;
                }
                freeNodo(nodoAEliminar);
                return agenda;
            } else {
                printf("No se ha eliminado el contacto");
                return agenda;
            }
        }
        bandera++;
    }
    printf("\nNo existe un contacto con dicho nombre\n");
    return agenda;
}


Agenda eliminarTodosContactos(Agenda agenda){
    Nodo *nodoAEliminar;

    int validacion;
    printf("Realmente quiere borrar todos los contactos?\n1. Si\n2. No\nOpcion: ");
    scanf("%i", &validacion);
    if(validacion != 1)
        return agenda;
    
    printf("%s", agenda != NULL ? "\nTodos los contactos fueron eliminados" : "\nNo hay contactos para eliminar, la agenda esta vacia :(");

    while(agenda != NULL){
        nodoAEliminar = agenda;
        agenda = agenda->sig;
        freeNodo(nodoAEliminar);
    }
    return NULL;
}

Agenda salida(Agenda agenda){
    Nodo *nodoAEliminar;
    while(agenda != NULL){
        nodoAEliminar = agenda;
        agenda = agenda->sig;
        freeNodo(nodoAEliminar);
    }
    return NULL;
}

void freeNodo(Nodo *nodoAEliminar){
    free(nodoAEliminar->dato.nombre);
    free(nodoAEliminar->dato.direccion);
    free(nodoAEliminar->dato.telefono);
    free(nodoAEliminar->dato.mail);
    free(nodoAEliminar->dato.aliasTelegram);
    free(nodoAEliminar->dato.usuarioInstagram);
    free(nodoAEliminar);
}


void saludar(){
    printf("Fin del programa :D");
}

// funcion que estabamos haciendo hasta que descubrimos que existe strstr
//  pero no queriamos borrar por lo que costo
//
// int incluye(char cadena1[], char cadena2[]){
//     int j = 0, bandera = 0;
//     for(int i = 0; i < strlen(cadena2) - 1; i++){
//         printf("%s",cadena1);
//         if(cadena1[j++] == cadena2[i])
//             bandera ++;
//         else if(bandera){
//             bandera=0;        
//             i -= bandera ;
//         }
//         if(cadena1[j++] != cadena2[i])
//             j=0;
//         if (bandera == strlen(cadena1))
//             return 1;
//     }
//     return 0;
// }