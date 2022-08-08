#include "pantalla.h"
#include <string.h>

#define POS_BASE {388, 218}
#define POS_P1 {663, 473}
#define POS_P2 {671, 145}
#define POS_P3 {110, 79}
#define POS_P4 {204, 455}
#define POS_P5 {111,307}
#define POS_ESTRELLA {457, 364}

//pantallas

void cargar_pantalla_inicio(nave_t *nave){
    float pos[2]=POS_BASE;
    nave_posicion_set(nave, pos);
}

void pantalla_inicio_mostrar(nave_t *nave,figura_t ***figuras, SDL_Renderer *renderer){
    float f=1;
    float planetas[7][2]={
        POS_BASE,
        POS_P1,
        POS_P2,
        POS_P3,
        POS_P4,
        POS_P5,
        POS_ESTRELLA
    };

    //figura_t **figura_base=figura[4];
    //figura_t **figura_planeta=figura[3];
    //figura_t **figura_nave=figura[2];
    float centro_grav[2];
    centro_grav[0]=planetas[6][0];
    centro_grav[1]=planetas[6][1];
    computar_posicion(nave, centro_grav);
    colision_rebote(nave);
    render_nave(nave,renderer, figuras, f);
    //bool aceleracion=false;
    dibujar_planetas(planetas,renderer,figuras);
    texto(nave, figuras, renderer);
}


/*
void cargar_nivel(nave_t *nave, nivel_t *nivel, figura_t ***figuras){//quizas saco ***figuras

    float centro_grav[2]=NULL;
    float escala=1;
    bool inf=get_tipo_infinito(nivel);

    
    //iteraciones 
    
    while(1){
       
        size_t cantidad_combustible=get_combustible(nivel);
        size_t cantidad_torretas=get_torretas(nivel);
        bool reactor_nivel=get_reactor(nivel);
        size_t cantidad_balas=get_balas(lista_balas);

        //SDL:
            //chequear botones;
            //fondo negro;
 
        estado_nave(nave);

        if(inf){
            centro_grav[2]={0,-ALTO}
            escala=obtener_escala();
            acomodar_camara();
            polilinea_extendida();//dibuja la pollinea en 3 posiciones consecutivas
            iteracion_nave_nivel_inf(nave,nivel);
        }else{
            escala=obtener_escala();
            iteracion_nave_nivel_no_inf(nave,nivel);
        }

        //dibujar texto

        if(cantidad_combustible!=0) iteracion_combustible(); 
        if(cantidad_torretas!=0) iteracion_torretas();
        if(reactor_nivel) iteracion_nivel();
        if(cantidad_balas!=0) iteracion_balas();
    }
}
*/
//fisicas nave
void estado_nave(nave_t *nave, float pos_g[2]){
    computar_posicion(nave, pos_g);
    combustible_usar(nave);
    //revisa direccion
    //revisa velocidad
    //revisa posicion
    //revisa combustible
    //chequear puntos
    //chequear vidas
}

//iteraciones inicio
void dibujar_planetas(float planeta[7][2], SDL_Renderer *renderer, figura_t ***figuras){
    
    dibujar_figura(renderer,figuras[4],"BASE",planeta[0],1);
    dibujar_figura(renderer,figuras[3],"ESTRELLA",planeta[6],1);
    dibujar_figura(renderer,figuras[3],"PLANETA1",planeta[1],1);
    dibujar_figura(renderer,figuras[3],"PLANETA2",planeta[2],1);
    dibujar_figura(renderer,figuras[3],"PLANETA3",planeta[3],1);
    dibujar_figura(renderer,figuras[3],"PLANETA4",planeta[4],1);
    dibujar_figura(renderer,figuras[3],"PLANETA5",planeta[5],1);
    
    
}
/*void iteracion_nave_inicio(nave_t *nave,float planeta[7][2]){
    iteraciones_colisiones_inicio(nave,planeta);
    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteraciones_colisiones_inicio(nave_t nave, float planeta[7][2]){
    
    if(0<posicion[0]<VENTANA_ANCHO || 0<posicion[1]<VENTANA_ALTO){
        rebotar(nave);
    }
    float radio=6;

    if(colision(posicion,planeta[6],radio)){
        perder_vida(nave);
        set_posicion(nave,planeta[0]);
    }

    for(size_t i=1,i<6,i++){
        if(colision(posicion,planeta[i],radio)){
            nombre_nivel nombre=i-1;
            nivel_t *nivel=llamar_nivel(nombre);
            cargar_nivel(nave,nivel,figuras);
            return;// NULL;
        }
    }
}

//iteraciones niveles
void iteracion_nave_nivel_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteracion_nave_nivel_no_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}*/

//sirve para iterar contra COMNUSTIBLE si este no es 0
void interseccion_lista_nave(nave_t *nave,size_t *cantidad, lista_t *lista,figura_t **figuras,char *nombre){
    lista_iter_t *lista_iter;
    lista_iter=lista_iter_crear(lista);
    
    for(size_t i=0;i<(*cantidad);i++){
        float posicion_objeto[2];
        float posicion_nave[2]; 
        float r=1681;//radio de colision
        
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_objeto);
        nave_posicion_get(nave,posicion_nave);
        
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
        

        if(colision(puntos_polilinea, puntos, posicion_nave, r)){//posi=posicion_nave
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
void dibujar_lista(figura_t **figuras, lista_t *lista,char *nombre,SDL_renderer *renderer){
    size_t cantidad=lista_largo(lista);
    lista_iter_t *liter;
    float direccion;
    float posicion[2];
    float origen[2]={0,0};
    liter=lista_iter_crear(lista);
    for(size_t i=0;i<cantidad,i++){
        objeto_t *objeto=lista_iter_ver_actual(liter);
        objeto_a_direccion(objeto,direccion);
        objeto_a_posicion(objeto,posicion);
        rotar_puntos(posicion,origen,direccion);
        dibujar_figura(renderer,figuras,nombre,posicion);
        lista_iter_avanzar(liter);
    }
    lista_iter_destruir(liter);
}

/*
void iteracion_torretas(figura_t ***figuras,nivel_t nivel){
    figura_t **torretas=figuras[];//posiciones(lista_torretas)
    float posicion_torretas[cantidad_torretas][2]=get_posicion_torretas(nivel);
    for(size_t i=0;i<cantidad_torretas;i++){
        if(interseccion(nave_pos,alcance_torretas[i])){//interseccion=colision
            //si puede hacer una bala:
            //dibujar_torreta_disparando;
            crear_nodo_bala(lista_bala);
            cantidad_balas++;
            //dibujar
        }else{
            dibujar_figura(renderer,torretas,"TORRETAS",posicion_torretas[i]);
        }
    }
}
void iteracion_nivel(figura_t ***figuras,nivel_t nivel){
    figura_t **reactor=figuras[];
    float posicion_reactor[2]=get_posicion_reactor(nivel);
    dibujar_figura(renderer,reactor,"REACTOR",posicion_reactor);
}
void iteracion_balas(figura_t ***figuras,nivel_t nivel){
    float balas_pos[cantidad_balas][2]=posiciones(lista_balas);
    //dibujar
    for(size_t j=0;j<cantidad_balas;j++){
        if(interseccion(nave_pos,balas_pos[i])){
            //pierde_vida;
            cantidad_torretas=cantidad(lista_torretas);
            torretas_pos=posiciones(lista_torretas);
            //dibujar
        }
    }

    if(cantidad_torretas!=0){
        for(size_t i=0;i<cantidad_torretas;i++){
            for(size_t j=0;j<cantidad_balas;j++){
                if(interseccion(torretas_pos[j],balas_pos[i])){
                    quitar_nodo(lista_torretas,torretas_pos[j]);
                    cantidad_torretas=cantidad(lista_torretas);
                    torretas_pos=posiciones(lista_torretas);
                    //dibujar
                }
            }
        }
    }

    for(size_t j=0;j<cantidad_balas;j++){
        size_t vida_bala=lista_balas->nodo_actual->vida;
        if(vida_bala>5){
            quitar_nodo//bala?
        }else{
            lista_balas->nodo_actualvida++;
        }
    }  
}
*/

//static void dibujar_letras(char *texto, float posicion[2]){}

polilinea_t *simbolo_vida_crear(){
    const float simbolo_pol[][2]= {{8, 0}, {-1, 6}, {-4, 4}, {-4, 2}, {-2, 0}, {-4, -2}, {-4, -4}, {-1, -6}, {8, 0}};
    polilinea_t *simbolo_vida=polilinea_crear(simbolo_pol,9,color_crear(false,true,false));
    polilinea_rotar(simbolo_vida,3.0*PI/2);
    return simbolo_vida;
}

static void renderizar_vidas(nave_t *nave, SDL_Renderer *renderer){
    
    float posicion_vidas[3][2]={{VENTANA_ANCHO*(1.0/10), VENTANA_ALTO*(9.0/10)},{VENTANA_ANCHO*(1.35/10), VENTANA_ALTO*(9.0/10)},{VENTANA_ANCHO*(1.7/10), VENTANA_ALTO*(9.0/10)}};
    polilinea_t *vida=simbolo_vida_crear();
    size_t cant_vidas=vidas_get(nave);
    for(size_t i=0;i<cant_vidas;i++){
        dibujar_polilinea(renderer, vida, posicion_vidas[i],2);
    }

    polilinea_destruir(vida);
}   

void texto(nave_t *nave, figura_t ***figuras, SDL_Renderer *renderer){
    //uint8_t vidas=vidas_get(nave);
    //float pos[2]={VENTANA_ALTO*MARGEN_ALTURA, VENTANA_ANCHO-VENTANA_ANCHO*MARGEN_ANCHO};
    
    renderizar_vidas(nave, renderer);
     
} 