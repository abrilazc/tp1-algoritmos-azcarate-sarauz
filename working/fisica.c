#include "fisica.h"


//Angulares

void trasladar(float pos[2],float v[2]){
    pos[0]=pos[0]+v[0]*DT;
    pos[1]=pos[1]+v[1]*DT;
}

static void computar_propulsion(float velocidad[2], float direccion){
    velocidad[0]+=NAVE_ACELERACION*cos(direccion)*DT;
    velocidad[1]+=NAVE_ACELERACION*sin(direccion)*DT;
}

static void computar_gravedad(float pos[2], float v[2], float pos_g[2]){

    if(pos_g==NULL){
        double gravedad=G*DT;
        v[1]-= gravedad;
    }
        
    else{
        float dx=pos[0]-pos_g[0];
        float dy=pos[1]-pos_g[1];
        float ang=atan2(dy, dx);
        v[0]-=G*cos(ang)*DT;
        v[1]-=G*sin(ang)*DT;
    }
}

static void computar_velocidad(nave_t *nave, float pos_g[2]){
    float posicion[2];
    nave_posicion_get(nave,posicion);
    float velocidad[2];
    nave_velocidad_get(nave, velocidad);
    float direccion=direccion_get(nave);
    if(chorro_get(nave))
        computar_propulsion(velocidad, direccion);
    computar_gravedad(posicion,velocidad, pos_g);
    nave_velocidad_set(nave, velocidad);
}

void computar_posicion(nave_t *nave, float pos_g[2]){
    float posicion[2];
    nave_posicion_get(nave,posicion);
    computar_velocidad(nave, pos_g);
    float velocidad[2];
    nave_velocidad_get(nave, velocidad);
    posicion[0]+=velocidad[0]*DT;
    posicion[1]+=velocidad[1]*DT;
    nave_posicion_set(nave, posicion);
}

//Una polilinea son varios puntos. LA traslacion de una polilinea sería la traslacion de los mismos:
void trasladar_polilinea(float polilinea[][2], size_t n, float velocidad[2]){
    for(size_t i=0; i<n; i++){
        trasladar(polilinea[i],velocidad);
    }
}

//INTERACCION

void colision_rebote(nave_t *nave){
    float pos[2];
    float v[2];
    nave_posicion_get(nave, pos);
    nave_velocidad_get(nave, v);
    if(pos[0]<=0||pos[0]>=VENTANA_ANCHO){
        printf("rebote x %.2f\n",v[0]);
        v[0]=(-v[0]);
    }
    else if(pos[1]<=0||pos[1]>=VENTANA_ALTO){
        v[1]=(-v[1]);
        printf("rebote y %.2f\n",v[1]);
    }
    nave_velocidad_set(nave, v);
}
void colision_rebote_ni(nave_t *nave, bool *inicio){
    float pos[2];
    float v[2];
    nave_posicion_get(nave, pos);
    nave_velocidad_get(nave, v);
    if(pos[0]<=0||pos[0]>=VENTANA_ANCHO){
        v[0]=(-v[0]);
    }
    else if(pos[1]>=VENTANA_ALTO){
        *inicio=true;
    }
    else if(pos[1]<=0){
        v[1]=(-v[1]);
    }
    nave_velocidad_set(nave, v);
}

float dist_puntos(float a[2], float b[2]){
    return sqrt(pow(b[0]-a[0],2)+pow(b[1]-a[1],2));
}

static float calc_alfa(float px, float py, float a[2], float b[2]){
    return ((px-a[0])*(b[0]-a[0])+(py-a[1])*(b[1]-a[1]))/pow(dist_puntos(a,b),2);
}

static float encontrar_dist_segmento(float p[2], float a[2], float b[2]){
    float alfa =calc_alfa(p[0], p[1], a, b);
    if (alfa <= 0)
        return dist_puntos(p, a);
    else if (alfa >= 1)
        return dist_puntos(b, p);
    else{
        float aux[2];
        aux[0]=a[0]+alfa*(b[0]-a[0]);
        aux[1]=a[1]+alfa*(b[1]-a[1]);
        return dist_puntos(aux,p);
    }
        
}


bool colision(float polilinea[][2], size_t n, float pos[2], float radio){ //retorna true si chocó
    float dist;
    for(size_t i = 0; i < n-1; i++){
        dist=encontrar_dist_segmento(pos, polilinea[i],polilinea[i+1]);
        if(dist<radio){
            return true;
        }
    }
    return false;
}

void rotar_punto(float punto[2], float pos[2], float angulo){
    float x=punto[0]-pos[0];
    float y=punto[1]-pos[1];
    punto[0] = x*cos(angulo) - y*sin(angulo)+pos[0];
    punto[1] = x*sin(angulo) + y*cos(angulo)+pos[1];
}