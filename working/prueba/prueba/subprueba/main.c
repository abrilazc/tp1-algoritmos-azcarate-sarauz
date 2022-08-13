#include "nivel.h"
#include "game.h"
#include "fisica.h"
#include "nave.h"
#include "pantalla.h"
#include "bala.h"
//#include "lista.h"
// -Werror

int main(void){

    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    size_t cantidad_niveles=cantidad_figuras[1];

    printf("%zd\n", cantidad_niveles);

    //creo niveles
    nivel_t **niveles=crear_niveles(figuras[1],cantidad_niveles);
    nave_t *nave=nave_crear(figuras[2]);
    planeta_nombre planeta=NIVEL1NE;
    nivel_t *nivel=cargar_datos_nivel(niveles,planeta);
    
    //inicializo variables
    lista_t *combustible=get_lista_combustible(nivel);
    lista_t *torreta=get_lista_torreta(nivel);
    lista_t *balas_propias=lista_crear();
    lista_t *balas_enemigas=lista_crear();
    
    //ITERADOR

    size_t cantidad_combustible= get_cantidad_combustible(nivel);
    size_t cantidad_torretas= get_cantidad_torretas(nivel);
    size_t cantidad_balas=lista_largo(balas_propias);
    size_t cantidad_ataques=lista_largo(balas_enemigas);
    
    
    //float posi[]={1667,113};
    printf("cantidad original: %zd\n", cantidad_combustible);

    //revisar choque borde:
    if(interseccion_nave_polilinea(nave,figuras[5],planeta));
    if(cantidad_combustible!=0){//y el escudo activado
        if(interseccion_lista_nave(nave,&cantidad_combustible, combustible,figuras[5], "COMBUSTIBLE")){
            //ganar_combustible
            printf("carga comb");
        }
    }
    if(cantidad_torretas!=0){
        if(interseccion_lista_nave(nave,&cantidad_torretas, torreta,figuras[6], "TORRETA")){
            if(cantidad_ataques<MAX_BAL_ENEM){
                size_t numero_torreta=cantidad_torretas;
                lista_iter_t *lista_iter=lista_iter_crear(torreta);
                printf("nave apuntada por torretas\n");
                for(size_t i=0;i<(numero_torreta+1);i++){
                    lista_iter_avanzar(lista_iter);
                }   
                objeto_t *orig=lista_iter_ver_actual(lista_iter);
                float posicion_d[2];
                float direccion_d;
                objeto_a_posicion(orig,posicion_d);
                objeto_a_direccion(orig,&direccion_d);
                disparo(balas_enemigas,posicion_d,direccion_d);
                printf("se realizó disparo\n");
            }
            cantidad_torretas=lista_largo(torreta);
        }
        
        size_t bajas=0;
        if(cantidad_balas!=0){
            bajas=interseccion_lista_lista(balas_propias, torreta,&cantidad_torretas);
            printf("%zd bajas enemigas\n",bajas);
        }
        size_t i=0;
        while(i<bajas){
            i++;
            //gana puntos
            if(cantidad_torretas==0){
                //gana mas puntos
                printf("pasas nviel");
            }
        }
    }
    if(cantidad_ataques!=0){
        if(interseccion_lista_nave(nave,&cantidad_ataques,balas_enemigas,figuras[2],"DISPARO"))
        printf("nave pierde una vida");
    }
    if(cantidad_reactores(planeta)){
        if(check_reactor_nivel(nivel)){
            if(get_tiempo(nivel)>0){
                float posicion_r[2];
                float direccion_r=0;
                get_posicion_reactor(nivel,posicion_r);
                //get_inclinacion_reactor(reactor,direccion_r);
                //dibujar
                printf("%f %f %f \n",posicion_r[0],posicion_r[1],direccion_r);
            }
        }
    }
    
    destruir_disparos(balas_propias);
    destruir_disparos(balas_enemigas);

    //printf("cantidad cambiada: %zd\n", cantidad_combustible);
    
    //dibujar todo

    lista_destruir(balas_propias,liquidar_municion);
    lista_destruir(balas_enemigas,liquidar_municion);

    destruir_figuras(figuras,cantidad_figuras);
    destruir_niveles(niveles,cantidad_niveles);
    nave_destruir(nave);

    return 1;
}
    //eventos

    //localizar combustible
    //dibujar combustible 
    
    //localizar torretas  
    //destruir torretas  
    //dibujar torretas
    //dibujar torretas disparando

    //afirmar reactor
    //localizar reactor
    //destruir reactor
    //dibujar reactor
    //descontar tiempo reactor




/* AUXILIARES
float posicion_combustible[2];
float posicion_torreta[2];
float direccion_combustible;
float direccion_torreta;
*/

//prueba vieja
/*
    objeto_t *objeto=lista_iter_ver_actual(iteradora);
    objeto_a_posicion(objeto,posicion);

    printf("posicion: %f %f \n",posicion[0],posicion[1]);

    iteradora=lista_iter_borrar(iteradora);
    lista_iter_destruir(iteradora);
    cantidad= get_cantidad_torretas(nivel);
    printf("cantidad cambiada: %zd\n", cantidad);
*/


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