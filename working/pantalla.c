#include "pantalla.h"
#include <string.h>

#define POS_BASE {388, 218}
#define POS_P1 {663, 473}
#define POS_P2 {671, 145}
#define POS_P3 {110, 79}
#define POS_P4 {204, 455}
#define POS_P5 {111,307}
#define POS_ESTRELLA {457, 364}

void listas(nave_t *nave,nivel_t **niveles,figura_t ***figuras, SDL_Renderer *renderer, planeta_nombre planeta_actual, float escala);
//pantallas

void pos_planetas(size_t n, float posicion[2]){
    float planetas[7][2]={
        POS_BASE,
        POS_P1,
        POS_P2,
        POS_P3,
        POS_P4,
        POS_P5,        
        POS_ESTRELLA
    };
    posicion[0]=planetas[n][0];
    posicion[1]=planetas[n][1];
}

static bool colisiones_inicio(nave_t *nave,nivel_t **niveles, float planeta_pos[7][2], planeta_nombre *planeta_actual);
void cargar_pantalla_inicio(nave_t *nave,nivel_t **niveles,figura_t ***figuras, planeta_nombre planeta_actual,bool spawn){
    float pos[2];
    if(spawn){
        printf("SPAWN EN BASE\n");
        pos[0]=388;
        pos[1]=218;
        pos_planetas(0,pos);
        vidas_reiniciar(nave);

        //destruir_niveles(niveles,CANTIDAD_NIVELES);
        //niveles=crear_niveles(figuras[1],CANTIDAD_NIVELES);
    }
    else {
        printf("SPAWN EN PLANETA\n");
        if(planeta_actual==4)
            pos_planetas(3,pos);
        else if(planeta_actual==2)
            pos_planetas(5,pos);
        else
            pos_planetas(planeta_actual+1,pos);
    pos[0]+=2*RADIONAVE;
    }
    
    float v[2]={0,0};
    nave_posicion_set(nave, pos);
    nave_velocidad_set(nave,v);
}

void salir_nivel(nave_t *nave,nivel_t **niveles,figura_t ***figuras,planeta_nombre planeta_actual,bool spawn,lista_t *lista, lista_t *lista2){
    nivel_t *nivel=cargar_datos_nivel(niveles, planeta_actual);
    lista_t *torreta=get_lista_torreta(nivel);
    if(get_nivel_pasado(nivel) && lista_largo(torreta)){
       puntos_planeta(nave,planeta_actual);
    }
    lista_destruir(lista,liquidar_municion);
    lista_destruir(lista2,liquidar_municion);
    cargar_pantalla_inicio(nave,niveles,figuras, planeta_actual, spawn);
}

void cargar_nivel(nave_t *nave, nivel_t **niveles, planeta_nombre planeta_actual){
    float posicion[2]={VENTANA_ANCHO/2,VENTANA_ALTO*0.9};
    float velocidad[2]={0,0};
    nave_posicion_set(nave, posicion);
    nave_velocidad_set(nave, velocidad);
    //nivel_t *nivel=cargar_datos_nivel(niveles, planeta_actual);
    
}
void planeta_finito(nave_t* nave,nivel_t **niveles, SDL_Renderer *renderer, figura_t ***figuras, planeta_nombre *planeta_actual, float *f, float *centro, bool *inicio){
    calcular_escala(figuras[1],*planeta_actual,f, centro);
    if(colision_rebote_ni(nave, inicio))
        {
            cargar_pantalla_inicio(nave,niveles,figuras,*planeta_actual,false);
        }
    float position[2]={( - *centro + VENTANA_ANCHO / 2 / (*f))*(*f),0.0};
    render_nave(nave, renderer, figuras,1);
    printf("func_render_ni\n");
    if(*planeta_actual==NIVEL1R){
        printf("NIVEL1R");
        dibujar_figura(renderer,figuras[1], "NIVEL1R",position,*f);
    }
    if(*planeta_actual==NIVEL1NW){
        printf("NIVEL1NW");
        dibujar_figura(renderer,figuras[1], "NIVEL1NW",position,*f);
    }
}

void planeta_infinito(nave_t* nave,nivel_t **niveles, SDL_Renderer *renderer, figura_t ***figuras, planeta_nombre *planeta_actual, float *f, float *centro, bool *inicio){
    float posicion_nave[2];
    
    polilinea_t *planeta_pol=polilinea_fig(figuras[1][*planeta_actual])[0];
    nave_posicion_get(nave, posicion_nave);
    *f = 1;
    if(posicion_nave[1] > VENTANA_ALTO * MARGEN_ALTURA)
        *f = VENTANA_ALTO * MARGEN_ALTURA / posicion_nave[1];
    if(*f < ESCALA_MINIMA)
        *f= ESCALA_MINIMA;

    if((posicion_nave[0] - *centro) * (*f)> VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave[0] - VENTANA_ANCHO / 2 * MARGEN_ANCHO /(*f);
    else if((*centro - posicion_nave[0]) * (*f)> VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave[0] + VENTANA_ANCHO / 2 * MARGEN_ANCHO /(*f);
    float camara[2]={0,0};
    
    
    float min[2];
    float max[2];
    min_max(figuras[1], *planeta_actual, min,max);
    
    if((((posicion_nave[0]-*centro)*(*f)))>(VENTANA_ANCHO/2* MARGEN_ANCHO)){
        *centro=(posicion_nave[0]-VENTANA_ANCHO/2*MARGEN_ANCHO/(*f));
    }
    else if(((*centro-posicion_nave[0])*(*f))>VENTANA_ANCHO/2* MARGEN_ANCHO){
        *centro=(posicion_nave[0]+VENTANA_ANCHO/2*MARGEN_ANCHO/(*f));
    }
    
    if((posicion_nave[0]>max[0])){
        posicion_nave[0]-=max[0];
        nave_posicion_set(nave,posicion_nave);
        *centro-=max[0];
    }
    else if((posicion_nave[0]<min[0])){
        posicion_nave[0]+=max[0];
        nave_posicion_set(nave,posicion_nave);
        *centro+=max[0];
    }
    float pos_aux[2]={posicion_nave[0]+(-*centro)+VENTANA_ANCHO/2,posicion_nave[1]};
    nave_posicion_set(nave,pos_aux);
    render_nave(nave,renderer, figuras,1);
    nave_posicion_set(nave, posicion_nave);
    camara[0]=(-(*centro+VENTANA_ANCHO/2/(*f)))*(*f);
    if(*planeta_actual==NIVEL1NE){
        printf("NIVEL1NE: CENTRO: %.2f ESCALA: %.2f",*centro, *f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro-max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro+max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
    }
    if(*planeta_actual==NIVEL1SE){
        printf("NIVEL1SE: CENTRO: %.2f ESCALA: %.2f",*centro, *f);
        //dibujar_figura(renderer,figuras[1], "NIVEL1NE",camara,*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro-max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro+max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);

    }
    if(*planeta_actual==NIVEL1SW){
        printf("NIVEL1SW: MIN=(%.2f,%.2f) MAX=(%.2f,%.2f)",min[0],min[1],max[0],max[1]);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro-max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro+max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
    }
    if(posicion_nave[1]>=VENTANA_ALTO){
            *inicio=true;
            cargar_pantalla_inicio(nave,niveles,figuras,*planeta_actual,false);
    }
    
}

bool pantalla_inicio_mostrar(nave_t *nave,figura_t ***figuras, nivel_t **niveles, SDL_Renderer *renderer, float *f, planeta_nombre *planeta_actual){
    *f=1;
    
    float planetas[7][2]={
        POS_BASE,
        POS_P1,
        POS_P2,
        POS_P3,
        POS_P4,
        POS_P5,        
        POS_ESTRELLA
    };


    float centro_grav[2];
    centro_grav[0]=planetas[6][0];
    centro_grav[1]=planetas[6][1];
    computar_posicion(nave, centro_grav);
    colision_rebote(nave);
    render_nave(nave,renderer, figuras, *f);
    dibujar_planetas(planetas,renderer,figuras);
    texto(nave, figuras, renderer);
    return !colisiones_inicio(nave,niveles,planetas,planeta_actual);
}
void pantalla_nivel(nave_t *nave, figura_t ***figuras,nivel_t **niveles, SDL_Renderer *renderer, bool *goto_inicio, planeta_nombre *planeta_actual, float *f, float *centro){
    float posicion[2];
    nave_posicion_get(nave, posicion);

    computar_posicion(nave, NULL);
    //nivel_t *nivel=cargar_datos_nivel(niveles,*planeta_actual);
    
    
    
    if(*planeta_actual==NIVEL1R||*planeta_actual==NIVEL1NW){
        planeta_finito(nave,niveles, renderer, figuras, planeta_actual,f, centro, goto_inicio);
        listas(nave,niveles,figuras,renderer,*planeta_actual,*f);
    }
    else{
        planeta_infinito(nave,niveles, renderer, figuras, planeta_actual,f, centro, goto_inicio);
        listas(nave,niveles,figuras,renderer,*planeta_actual,*f);
    }    
        
    texto(nave, figuras, renderer);
}

//fisicas nave
void estado_nave(nave_t *nave, float pos_g[2]){
    computar_posicion(nave, pos_g);
    combustible_usar(nave);
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

static bool colisiones_inicio(nave_t *nave,nivel_t **niveles, float planeta_pos[7][2], planeta_nombre *planeta_actual){
    float posicion[2];
    nave_posicion_get(nave, posicion);
    for(size_t i=1;i<7;i++){
        if(dist_puntos(planeta_pos[i],posicion)<RADIONAVE){
            if(i==6){
                //choque contra estrella
                break;
            }
            else if(i==3)
                *planeta_actual=4;
            else if(i==5)
                *planeta_actual=2;
            else
                *planeta_actual=i-1;
            cargar_nivel(nave,niveles, *planeta_actual);
            return true;
        }
    }
    return false;
}


//sirve para iterar contra COMBUSTIBLE si este no es 0
//cambiar a bool
bool interseccion_lista_nave(nave_t *nave,size_t *cantidad, lista_t *lista,figura_t **figuras,char *nombre){
    lista_iter_t *lista_iter;
    lista_iter=lista_iter_crear(lista);
    
    for(size_t i=0;i<(*cantidad);i++){
        float posicion_objeto[2];
        float posicion_nave[2]; 
        float r=100;//radio de colision
        
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_objeto);
        nave_posicion_get(nave,posicion_nave);
        
        figura_t *figura=cargar_nombre(figuras,nombre);
        size_t cantidad_poli=cantidad_poli_fig(figura);
        
        polilinea_t **polilineas=polilinea_fig(figura);
        
/*        size_t numero_poli=0;
        
        polilinea_t *polilinea=get_polilinea(polilineas,numero_poli,cantidad_poli);
        size_t puntos=polilinea_cantidad_puntos(polilinea);
*/        
        for(size_t j=0; j<cantidad_poli;j++){
            polilinea_t *polilinea=polilinea_clonar(get_polilinea(polilineas,j,cantidad_poli));//polilinea_clonar(polilineas[i]);
            //polilinea_trasladar(polilinea, posicion_objeto);
            size_t puntos=polilinea_cantidad_puntos(polilinea);
            
            float puntos_polilinea[puntos][2];

            for(size_t g=0; g<puntos;g++){
                polilinea_obtener_punto(polilinea, g, &puntos_polilinea[g][0], &puntos_polilinea[g][1]);
            }

            if(colision(puntos_polilinea, puntos, posicion_nave, r)){//posi=posicion_nave
                if(!strcmp(nombre,"TORRETA")){
                    //disparar
                    lista_iter_destruir(lista_iter);
                    return true;
                }
                objeto_t *dest=lista_iter_borrar(lista_iter);
                lista_iter_destruir(lista_iter);
                destruir_cosa(dest);
                (*cantidad)--;
                return true;
            }
            polilinea_destruir(polilinea);
        }
        lista_iter_avanzar(lista_iter);
    }
    lista_iter_destruir(lista_iter);
    return false;
}
//dibuja los elementos asociados a la lista
void dibujar_lista(figura_t **figuras, lista_t *lista,char *nombre,SDL_Renderer *renderer, float escala, float origen[2]){
    size_t cantidad=lista_largo(lista);
    lista_iter_t *liter;
    float direccion;
    float posicion[2];
    //float origen[2]={0,0}; se agregò como parametro
    liter=lista_iter_crear(lista);
    for(size_t i=0;i<cantidad;i++){
        objeto_t *objeto=lista_iter_ver_actual(liter);
        objeto_a_direccion(objeto,&direccion);
        objeto_a_posicion(objeto,posicion);
        //rotar_punto(posicion,origen,direccion);
        posicion[0]-=origen[0];
        posicion[1]-=origen[1];
        dibujar_figura_bis(renderer,figuras,nombre,posicion,escala,direccion);
        lista_iter_avanzar(liter);
    }
    lista_iter_destruir(liter);
}
//cuenta intersecciones entre listas, si cualquier punto de la lista  1 alcanza las poliines del 2, destruye a este ultimo.
size_t interseccion_lista_lista(lista_t *lista, lista_t *lista_2,size_t *cantidad_2){
    size_t intersecciones=0;
    
    lista_iter_t *lista_iter;
    lista_iter_t *lista_iter_2;
    
    size_t cantidad=lista_largo(lista);
    float posicion_lista[2];
    float posicion_lista_2[2]; 
    float r=100;//radio de colision
    
    for(size_t i=0;i<cantidad;i++){
        bool pasar=false;
        lista_iter=lista_iter_crear(lista);
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_lista);    

        for(size_t j=0;j<(*cantidad_2) || pasar==true;j++){
            lista_iter_2=lista_iter_crear(lista_2);
            objeto_t *objeto_2=lista_iter_ver_actual(lista_iter_2);
            objeto_a_posicion(objeto_2,posicion_lista_2);
            size_t puntos=sizeof(objeto_2)/sizeof(float);

            if(colision(&posicion_lista_2, puntos, posicion_lista, r)){
                objeto_t *dest=lista_iter_borrar(lista_iter);
                (*cantidad_2)--;
                lista_iter_destruir(lista_iter_2);
                destruir_cosa(dest);
                intersecciones++;
                pasar=true;
            }else{
                lista_iter_avanzar(lista_iter_2);
            }
        }
        lista_iter_destruir(lista_iter);
    }
    return intersecciones;
}
//verifica si la nave se cruzó con las lineas del planeta
bool interseccion_nave_polilinea(nave_t *nave,figura_t **figuras,planeta_nombre nombre){
    float posicion_nave[2]; 
    nave_posicion_get(nave,posicion_nave);
    float r=50;

    figura_t *figura=figuras[nombre];
    size_t cantidad_poli=cantidad_poli_fig(figura);
    
    polilinea_t **polilineas=polilinea_fig(figura);
    
    for(size_t i=0;i<cantidad_poli;i++){
        polilinea_t *polilinea=polilineas[i];
        size_t puntos=polilinea_cantidad_puntos(polilinea);    
        float puntos_polilinea[puntos][2];

        for(size_t g=0; g<puntos;g++){
            polilinea_obtener_punto(polilinea, g, &puntos_polilinea[g][0], &puntos_polilinea[g][1]);
        }

        if(colision(puntos_polilinea, puntos, posicion_nave, r)){//posi=posicion_nave
            return true;
        } 
    }
    return false;
}


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


void listas(nave_t *nave,nivel_t **niveles,figura_t ***figuras, SDL_Renderer *renderer, planeta_nombre planeta_actual, float escala){
    nivel_t *nivel=cargar_datos_nivel(niveles, planeta_actual);
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
    
    float origen[]={VENTANA_ANCHO/2,VENTANA_ALTO*MARGEN_ALTURA};

    bool salir_nivel=false;

    //float posi[]={1667,113};
    printf("cantidad original: %zd\n", cantidad_torretas);

    //revisar choque borde:
   
    //void nave_polilinea(nave_t *nave,nivel_t *niveles,figura_t *figuras,planeta_nombre planeta_actual,bala_t *balas_propias, bala_t *balas_enemigas,float origen[2]);
    /*
    if(interseccion_nave_polilinea(nave,figuras[5],planeta_actual)){
        if(!vidas_decrementar(nave)){
            salir_nivel(nave,niveles,figuras,planeta_actual,true,balas_propias,balas_enemigas);
        }

        nave_posicion_set(nave,origen);
    }
*/
    //void combustible_while(size_t cantidad_combustible,figuras_t **figuras,lista_t *combustible,SDL_Render *renderer, float escala, nave_t nave)

    if(cantidad_combustible!=0){//y el escudo activado
        dibujar_lista(figuras[5],combustible,"COMBUSTIBLE",renderer,escala,origen); 
        if(interseccion_lista_nave(nave,&cantidad_combustible, combustible,figuras[5], "COMBUSTIBLE")&& escudo_get(nave)){
            combustible_cargar(nave);
            //eliminar de la lista xd xd xd
        }
    }
    
    if(cantidad_torretas!=0){
        dibujar_lista(figuras[6],torreta,"TORRETA",renderer,escala,origen);
        if(interseccion_lista_nave(nave,&cantidad_torretas, torreta,figuras[6], "TORRETA")){
            if(cantidad_ataques<MAX_BAL_ENEM){
                size_t numero_torreta=cantidad_torretas;
                lista_iter_t *lista_iter=lista_iter_crear(torreta);
                for(size_t i=0;i<(numero_torreta);i++){
                    lista_iter_avanzar(lista_iter);
                }   
                objeto_t *orig=lista_iter_ver_actual(lista_iter);
                float posicion_d[2];
                float direccion_d;
                objeto_a_posicion(orig,posicion_d);
                objeto_a_direccion(orig,&direccion_d);
                disparo(balas_enemigas,posicion_d,direccion_d);
            }
            cantidad_torretas=lista_largo(torreta);
        }
        
        size_t bajas=0;
        float nave_pos[2];
        nave_posicion_get(nave, nave_pos);
        if(cantidad_balas!=0){
            bajas=interseccion_lista_lista(balas_propias, torreta,&cantidad_torretas);
            printf("%zd bajas enemigas\n",bajas);
        }
        size_t i=0;
        while(i<bajas){
            i++;
            puntos_torreta(nave);
        }
    }
    
    if(cantidad_ataques!=0){
        trayectoria_disparo(balas_enemigas);
        dibujar_lista(figuras[2],balas_enemigas,"DISPARO",renderer,escala,origen);
        if(interseccion_lista_nave(nave,&cantidad_ataques,balas_enemigas,figuras[2],"DISPARO")){
            if(!vidas_decrementar(nave)){
                salir_nivel=true;
            }
        nave_posicion_set(nave,origen);    
        }
    }
    if(cantidad_reactores(planeta_actual)){
        if(check_reactor_nivel(nivel)){
            if(get_tiempo(nivel)>0){
                float posicion_r[2];
                float direccion_r=0;
                get_posicion_reactor(nivel,posicion_r);
                direccion_r=get_direccion_reactor(nivel);
                dibujar_figura_bis(renderer,figuras[7],"REACTOR",posicion_r,escala,direccion_r);
                float posicion_texto[]={VENTANA_ANCHO/2,VENTANA_ALTO* MARGEN_ALTURA};
                numero_a_polilinea(get_tiempo(nivel),renderer,posicion_texto,true,true,true,escala*10);
                decremento_reactor(nivel);
            }else if(!vidas_decrementar(nave)){
                salir_nivel=true;
            }else{
                nave_posicion_set(nave,origen);
                set_reactor_off(nivel);
            }
        }
    }
    if(get_disparar(nave) && cantidad_balas<MAX_BAL_PROP){
        float pos_nave[2];
        nave_posicion_get(nave,pos_nave);
        disparo(balas_propias,pos_nave,direccion_get(nave));
    }
    if(lista_largo(balas_propias)!=0){
        dibujar_lista(figuras[2],balas_propias,"DISPARO",renderer,escala,origen);
        trayectoria_disparo(balas_propias);
        //destruir_disparos(balas_propias);
    }
    if(salir_nivel){
        lista_destruir(balas_propias,liquidar_municion);
        lista_destruir(balas_enemigas,liquidar_municion);
    }
    



}