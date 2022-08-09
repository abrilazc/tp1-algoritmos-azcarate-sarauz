#include <stddef.h>
#include <stdio.h>
#include "game.h"
#include "config.h"
#include "polilinea.h"
#include "nivel.h"


void calcular_escala_inf(float posicion_nave_y, float *escala){
    if(posicion_nave_y > VENTANA_ALTO * MARGEN_ALTURA)
        *escala = VENTANA_ALTO * MARGEN_ALTURA / posicion_nave_y;
    if(*escala < ESCALA_MINIMA)
        *escala = ESCALA_MINIMA;

}

void calcular_centro_inf(const float escala,const float posicion_nave_x, float *centro){
    if((posicion_nave_x - *centro) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x - VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
    else if((*centro - posicion_nave_x) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x + VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
}

void calcular_escala(figura_t **figuras, planeta_nombre *planeta_actual,float *escala, float *centro){
    polilinea_t *pol_planeta=(polilinea_fig(figuras[*planeta_actual]))[0];
    size_t n=polilinea_cantidad_puntos(pol_planeta);
    float x,y;
    float planeta_x_min, planeta_x_max;
    float planeta_y_min, planeta_y_max;
    polilinea_obtener_punto(pol_planeta,0,&planeta_x_min,&planeta_y_min);
    planeta_x_max=planeta_x_min;
    planeta_y_max=planeta_y_min;
    for(size_t i=1;i<n;i++){
        polilinea_obtener_punto(pol_planeta,i,&x,&y);
        
        if(x<planeta_x_min){
            planeta_x_min=x;
        }
        else if(x>planeta_x_max){
            planeta_x_max=x;
        }
        if(y<planeta_y_min){
            planeta_y_min=y;
        }
        else if(y>planeta_y_max){
            planeta_y_max=y;
        }
        else
            continue;
    }
    float planeta_alto=planeta_y_max-planeta_y_min;
    float planeta_ancho=planeta_x_max-planeta_x_min;
    *escala = VENTANA_ALTO * 1.0 / planeta_alto;
    if((VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min)) < *escala)
        *escala = VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min);
    *centro = (planeta_x_max+planeta_x_min)/2.0;
    printf("centro:%.2f ancho:%.2f alto:%.2f \n" ,*centro, planeta_ancho,planeta_alto);
}


escala = VENTANA_ALTO * 1.0 / planeta_alto;
if(VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min) < escala)
    escala = VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min);
centro = (planeta_ancho + planeta_x_min) / 2;

int main(void){
   
    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;
    //bool pantalla_inicio_ingreso=true;
    //bool nivel_inicio=true;
    //size_t cantidad_niveles=cantidad_figuras[1];
   // nivel_t **niveles=crear_niveles(figuras[1], cantidad_niveles);
    //nave_t *nave=nave_crear(figuras[2]);
    planeta_nombre planeta_actual=NIVEL1NE;
    //float velocidad[2]={0,0};
    //float posicion[2] ={VENTANA_ANCHO/2,VENTANA_ALTO/2};
    float centro=VENTANA_ANCHO/2;
    float escala=1;
    calcular_escala(figuras[3], &planeta_actual,&escala,&centro);
    

    return 1;
}

//float **puntero=polilinea_caracter('a');

//polilinea_t *polilinea=polilinea_crear();