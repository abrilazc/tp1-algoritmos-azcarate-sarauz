#include "nivel.h"

int main(void){

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


    return 1;
}


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