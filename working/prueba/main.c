#include "nivel.h"
#include "game.h"
#include "fisica.h"
#include "nave.h"
//#include "lista.h"

polilinea_t *get_polilinea(polilinea_t **polilineas,size_t numero_poli,size_t cantidad_poli){
    
    if(numero_poli>cantidad_poli) return NULL;
    
    polilinea_t *polilinea=polilineas[numero_poli];
    if(polilinea==NULL) printf("null\n");
    
    return polilinea;
}
//fuerzo posicion nave: nave_t nave,
void interseccion_lista_nave(float posi[2],size_t *cantidad, lista_t *lista,figura_t **figuras,char *nombre){
    lista_iter_t *lista_iter;
    lista_iter=lista_iter_crear(lista);
    
    for(size_t i=0;i<(*cantidad);i++){
        float posicion_objeto[2];
        //float posicion_nave[2]; posi
        float r=10000;//radio de colision
        
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_objeto);
        //get_posicion(nave,&posicion_nave);
        
        figura_t *figura=cargar_nombre(figuras,nombre);
        size_t cantidad_poli=cantidad_poli_fig(figura);
        
        polilinea_t **polilineas=polilinea_fig(figura);
        size_t numero_poli=0;
        
        polilinea_t *polilinea=get_polilinea(polilineas,numero_poli,cantidad_poli);
        size_t puntos=polilinea_cantidad_puntos(polilinea);
        
        polilinea_trasladar(polilinea, posicion_objeto);
        
        float puntos_polilinea[puntos][2];

        for(size_t g=0; g<puntos;g++){
            polilinea_obtener_punto(polilinea, g, &puntos_polilinea[g][0], &puntos_polilinea[g][1]);
        }
        

        if(colision(puntos_polilinea, puntos, posi, r)){//posi=posicion_nave
            objeto_t *dest=lista_iter_borrar(lista_iter);
            (*cantidad)--;
            lista_iter_destruir(lista_iter);
            destruir_cosa(dest);
            return;
        }
        lista_iter_avanzar(lista_iter);
    }
    lista_iter_destruir(lista_iter);
}


/*void dibujar_lista(size_t cantidad, float posicion[2], lista_iter_t *lista){
    for(size_t i=0;i<cantidad;i++){
        //direccion=get_direccion
        //dibujar
    }
    figura_t **combustible=figuras[];
    float posicion_combustible[cantidad_combustible][2]=get_posicion_combustible(nivel);
    for(size_t i=0;i<cantidad_combustible,i++){
        dibujar_figura(renderer,combustible,"COMBUSTIBLE",posicion_combustible[i]);
    }    //falta colision (nave,tanque) 
}*/

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
    
    //cargo nivel
    nivel_t *nivel=cargar_nivel(niveles,NIVEL1NE);
    
    //inicializo variables
    lista_t *combustible=get_lista_combustible(nivel);
    //lista_t *torreta=get_lista_torreta(nivel);
    
    //veo tamaños
    size_t cantidad_combustible= get_cantidad_combustible(nivel);
    //size_t cantidad_torretas= get_cantidad_torretas(nivel);

/*  if(cantidad_torretas!=0){
        lista_iter_t *torretas_iter=lista_iter_crear(torretas);
    }*/

    //char combustible_txt[20]="COMBUSTIBLE";
    //char *torreta_txt[20]="TORRETA";
    
    //ITERADOR
    float posi[]={1667,113};
    printf("cantidad original: %zd\n", cantidad_combustible);
    interseccion_lista_nave(posi,&cantidad_combustible, combustible,figuras[5], "COMBUSTIBLE");
    printf("cantidad cambiada: %zd\n", cantidad_combustible);
    
    /*
    if(cantidad_combustible!=0){
    posi[0]=1064;
    posi[1]=12;
    
    interseccion_lista_nave(posi,&cantidad_combustible, combustible,figuras[5], "COMBUSTIBLE");
    printf("cantidad cambiada: %zd\n", cantidad_combustible);
    }
    
    if(cantidad_combustible!=0){
    posi[0]=5;
    posi[1]=5;
    interseccion_lista_nave(posi,&cantidad_combustible, combustible,figuras[5], "COMBUSTIBLE");
    printf("cantidad cambiada: %zd\n", cantidad_combustible);
    }
    */
    //pantalla_inicio(nave,figuras,nivel_t **niveles);
    
    destruir_figuras(figuras,cantidad_figuras);
    destruir_niveles(niveles,cantidad_niveles);
    nave_destruir(nave);
    //destruir_nave(nave);

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