/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "./arbol_binario.h"


//Funcion para crear un nuevo arbol binario
ARBOL_BINARIO* nuevo_arbol_binario(int tamanio_dato, void* dato, int(*funcion_ordenar)(void*, void*)){
    ARBOL_BINARIO* nuevo=(ARBOL_BINARIO*)malloc(sizeof(ARBOL_BINARIO));
    if(!nuevo) return NULL;
    
    nuevo->dato=malloc(tamanio_dato);
    if(!nuevo->dato){
        free(nuevo);
        return NULL;
    }
    
    memcpy(nuevo->dato, dato, tamanio_dato);
    nuevo->izquierda= NULL;
    nuevo->derecha=NULL;
    nuevo->padre=NULL;
    nuevo->tamanio_dato=tamanio_dato;
    nuevo->funcion_ordenar=funcion_ordenar;
    
    return nuevo;
}
//Funcion para obtener el primer elemento en orden IN-ORDEN
ARBOL_BINARIO* primero_arbol_binario(ARBOL_BINARIO* arbol){
    if(!arbol) return NULL;
    while (arbol->izquierda) {
        arbol=arbol->izquierda;
    }
    return arbol;
}

//FUncion para obtener el ultimo elemento en orden IN-ORDEN
ARBOL_BINARIO* ultimo_arbol_binario(ARBOL_BINARIO* arbol){
    if(!arbol) return NULL;
    while (arbol->derecha) {
        arbol=arbol->derecha;
    }
    return arbol;
}

//Funcion para agregar un nuevo nodo al arbol
void insertar_arbol_binario(void* dato, ARBOL_BINARIO* arbol){
    if(!arbol || !dato) return;
    
    int funcion_ordenar=arbol->funcion_ordenar(dato,arbol->dato);
    if(funcion_ordenar < 0){
        if(arbol->izquierda){
            insertar_arbol_binario(dato, arbol->izquierda);
        }else{
            arbol->izquierda=nuevo_arbol_binario(arbol->tamanio_dato, dato, arbol->funcion_ordenar);
            arbol->izquierda->padre=arbol;
        }
    }else if(funcion_ordenar >0){
        if(arbol->derecha){
            insertar_arbol_binario(dato, arbol->derecha);
        }else{
            arbol->derecha=nuevo_arbol_binario(arbol->tamanio_dato, dato, arbol->funcion_ordenar);
            arbol->derecha->padre=arbol;
        }
    }
}

//Funcion para encontrar el siguiente lemento en IN-ORDEN
ARBOL_BINARIO* siguiente_arbol_binario(ARBOL_BINARIO* nodo){
    if(!nodo) return NULL;
    if(nodo->derecha){
        return primero_arbol_binario(nodo->derecha);
    }
    ARBOL_BINARIO* padre=nodo->padre;
    while (padre && nodo==padre->derecha) {
        nodo=padre;
        padre=padre->padre;
    }
    return padre;
}

//Funcion para encontrar eñ ultimo elemeto en IN-ORDEN
ARBOL_BINARIO* anterior_arbol_binario(ARBOL_BINARIO* nodo){
    if(!nodo) return NULL;
    if(nodo->izquierda){
        return ultimo_arbol_binario(nodo->izquierda);
    }
    ARBOL_BINARIO* padre=nodo->padre;
    while (padre && nodo == padre->izquierda) {
        nodo=padre;
        padre=padre->padre;
    }
    return padre;
}

//Funcion para buscar un elemento dentro del arbol
ARBOL_BINARIO* busqueda_binaria_arbol_binario(void* dato, ARBOL_BINARIO* arbol){
    if(!arbol || !dato) return NULL;
    
    int funcion_ordenar=arbol->funcion_ordenar(dato,arbol->dato);
    if(funcion_ordenar == 0){
        return arbol;
    }else if( funcion_ordenar < 0){
        return busqueda_binaria_arbol_binario(dato, arbol->izquierda);
    }else {
        return busqueda_binaria_arbol_binario(dato, arbol->derecha);
    }
}

//Funcion para retornar la raiz de un elemento
ARBOL_BINARIO* buscar_raiz(ARBOL_BINARIO* nodo){
    if(!nodo) return NULL;
    while (nodo->padre) {
        nodo=nodo->padre;
    }
    return nodo;
}

char* get_carnet(){
    return "          mu18006";
}

