#include "fisica.h"


//Angulares

static float angulo(float dx, float dy){
        if(dx >=0 && dy >= 0){
            return atan(dy/dx);
        }
        else if(dx >= 0 && dy < 0){
            return atan(dy/dx)+2*PI;
        }
        else if(dx < 0 && dy >= 0){
            return PI-atan(dy/dx);
        }
        else{
            return tan(dy/dx)+PI;
        }
}

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
        float ang=angulo(dx, dy);
        v[0]+=G*cos(ang)*DT;
        v[1]+=G*sin(ang)*DT;
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

static float dist_puntos(float ax, float ay, float bx, float by){
    return sqrt(pow(bx-ax,2)+pow(by-ay,2));
}

static float calc_alfa(float px, float py, float ax, float ay, float bx, float by){
    return ((px-ax)*(bx-ax)+(py-ay)*(by-ay))/pow(dist_puntos(ax,ay,bx,by),2);
}

static float encontrar_dist_segmento(float p[2], float a[2], float b[2]){
    float alfa =calc_alfa(p[0], p[1], a[0], a[1], b[0],b[1]);
    if (alfa <= 0)
        return dist_puntos(p[0], p[1], a[0], a[1]);
    else if (alfa >= 1)
        return dist_puntos(b[0], b[1], p[0], p[1]);
    else
        return dist_puntos(a[0]+alfa*(b[0]-a[0]),a[1]+alfa*(b[1]-a[1]),p[0],p[1]);
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