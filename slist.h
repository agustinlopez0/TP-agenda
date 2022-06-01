#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef struct {
    char *nombre, *direccion, *telefono, *mail, *aliasTelegram, *usuarioInstagram;
} Contacto;

typedef struct _SNodo{
    Contacto dato;
    struct _SNodo *sig;
} Nodo;

typedef Nodo *Agenda;

/**************Prototipos*************/

/**
 * Para acceder a las funciones principales
 */
void menu(Agenda agenda);

/**
 * Crea una agenda
 */
Agenda crear_agenda();

/**
 * Recolecta los datos del contacto que pide nuevoContacto y los junta en un struct
 */
Contacto juntarDatos();

/**
 * Agrega un nuevo conatcto
 */
Agenda nuevoContacto(Agenda agenda, Contacto contacto);

/**
 * Muestra todos los contactos 
 */
void muestraContactos(Agenda agenda);

/**
 * Devuelve los contactos de la lista buscando por nombre
 */
Agenda buscaContactosNombre(Agenda agenda, char *cadena);

/**
 * Devuelve los contactos de la lista buscando por telefono
 */
Agenda buscaContactosTelefono(Agenda agenda, char *telefono);

/**
 * Elimina el contacto pasandole el nombre
 */
Agenda eliminarContactoNombre(Agenda agenda, char *nombre);

/**
 * Elimina todos los contactos de la agenda
 */
Agenda eliminarTodosContactos(Agenda agenda);

/**
 * Recibe elimina en memoria con sus paramtris
 */
void freeNodo(Nodo *nodoAEliminar);

/**
 * Elimina todos los contactos de la agenda sin mostrar salida
 */
Agenda salida(Agenda agenda);

/**
 * Un abrazo
 */
void saludar();

#endif