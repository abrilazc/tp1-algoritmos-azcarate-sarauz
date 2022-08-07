#include "nivel.h"
#include "game.h"
//#include "lista.h"

int main(void){

     size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    size_t cantidad_niveles=cantidad_figuras[1];

    printf("%zd\n", cantidad_niveles);

    nivel_t **niveles=crear_niveles(figuras[1],cantidad_niveles);
    
    //cargo nivel
    nivel_t *nivel=cargar_nivel(niveles,NIVEL1NE);

    //inicializo variables
    lista_t *torreta=get_lista_torreta(nivel);
    lista_t *combustible=get_lista_combustible(nivel);
    
    float posicion_combustible[2];
    float posicion_torreta[2];
    float direccion_combustible;
    float direccion_torreta;

    lista_iter_t *torreta_iter;
    lista_iter_t *combustible_iter;

    size_t cantidad_torretas;
    size_t cantidad_combustible;

    //iterador
    cantidad_torretas= get_cantidad_torretas(nivel);
    cantidad_torretas= get_cantidad_torretas(nivel);
    
    torreta_iter=lista_iter_crear(torreta);
    combustible_iter=lista_iter_ver_actual(combustible);

    //eventos

    //localizar combustible
    //destruir combustible
    //dibujar combustible

    void iteracion_combustible(size_t cantidad, float posicion[2], lista_iter_t *lista){
    for(size_t i=0;i<cantidad;i++){
        posicion=get_posicion
    }
    figura_t **combustible=figuras[];
    float posicion_combustible[cantidad_combustible][2]=get_posicion_combustible(nivel);
    for(size_t i=0;i<cantidad_combustible,i++){
        dibujar_figura(renderer,combustible,"COMBUSTIBLE",posicion_combustible[i]);
    }    //falta colision (nave,tanque) 
}
    
    //localizar torretas  
    //destruir torretas  
    //dibujar torretas
    //dibujar torretas disparando

    //afirmar reactor
    //localizar reactor
    //destruir reactor
    //dibujar reactor
    //descontar tiempo reactor



    objeto_t *objeto=lista_iter_ver_actual(iteradora);
    objeto_a_posicion(objeto,posicion);

    printf("posicion: %f %f \n",posicion[0],posicion[1]);

    iteradora=lista_iter_borrar(iteradora);
    lista_iter_destruir(iteradora);
    cantidad= get_cantidad_torretas(nivel);
    printf("cantidad cambiada: %zd\n", cantidad);

    //pantalla_inicio(nave,figuras,nivel_t **niveles);
    
    destruir_figuras(figuras,cantidad_figuras);
    destruir_niveles(niveles,cantidad_niveles);
    //destruir_nave(nave);




    return 1;
}

//Por si hay que hacer punteros a funciones:

/*
    void armar_lista(lista_t *lista, objeto_t *objeto, planeta_nombre planeta,vector_t* funcion (planeta_nombre planeta,*(int) cantidad)){
        cantidad=0;
        size_t fila=0;
        float posicion[2]={0,0};
        float direccion=0;

        vector_t *referencia=funcion(planeta,&cantidad);
    
        while(fila<cantidad){
            combustible=crear_objeto(referencia,fila);
            lista_insertar_primero(lista,objeto);
            fila++;
        }
    }
*/

/*
    lista_t *combustible=lista_combustible(NIVEL1NW);
    lista_t *torreta=lista_torreta(NIVEL1NW);

    
    printf("largo: %zd\n",lista_largo(combustible));
    printf("largo: %zd\n",lista_largo(torreta));

    lista_destruir(combustible,destruir_bien);
    lista_destruir(torreta,destruir_bien);

    reactor_t *reactor=crear_reactor(NIVEL1R);
    printf("bool: %d\n",get_bool_nivel(reactor));
    destruir_reactor(reactor);

    char nombre[20];
    strcpy(nombre,nombre_asignado(NIVEL1SW));
    printf("%s", nombre);
*/

/*  Para probar while fila<cantidad
    objeto_a_posicion(combustible,posicion);
    objeto_a_direccion(combustible,&direccion);
    printf("%f %f %f\n",posicion[0],posicion[1],direccion);
*/



/* despues de sacar el 2° nodo no da ni NULL
    printf("anda\n");
    objeto_t *caca=NULL;
    lista_iter_t *li_combustible=lista_iter_crear(l_combustible);
    caca=lista_iter_ver_actual(li_combustible);
    objeto_a_posicion(caca,posicion);
    objeto_a_direccion(caca,&direccion);
    printf("pos 0 %f %f %f\n",posicion[0],posicion[1],direccion);

    if(lista_iter_avanzar(li_combustible)==false) printf("NULL");
    caca=lista_iter_ver_actual(li_combustible);
    objeto_a_posicion(caca,posicion);
    objeto_a_direccion(caca,&direccion);
    printf("pos 1 %f %f %f\n",posicion[0],posicion[1],direccion);

    if(lista_iter_avanzar(li_combustible)==false) printf("NULL");
    if(li_combustible==NULL) printf("cagaste");
    //caca=lista_iter_ver_actual(li_combustible);
    //objeto_a_posicion(caca,posicion);
    //objeto_a_direccion(caca,&direccion);
    //printf("%f %f %f\n",posicion[0],posicion[1],direccion);
*/