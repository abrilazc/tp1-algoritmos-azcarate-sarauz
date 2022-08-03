#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "fisica.h"
#include "polilinea.h"

#define RADIONAVE
#define DT 1/JUEGO_FPS
void colision_rebote(float pos[2], float v[2], size_t dim[2]){
    if(pos[0]<=0||pos[0]>=dim[0]){
        v[0]=-v[0];
    }
    else if(pos[1]<=0||pos[1]>=dim[1]){
        v[1]=-v[1];
    }
}

void acelerar(float v[2], float angulo){
    v[0]=v[0]+NAVE_ACELERACION*cos(angulo)*DT;
    v[1]=v[1]+NAVE_ACELERACION*sin(angulo)*DT;
}

static double angulo(float dx, float dy){
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


void gravedad(float v[2], bool planeta_infinito, float pos[2], float pos_g[2]){

    if(planeta_infinito){
        v[1]= v[1]- G*DT;
    }

    else{
        float dx=pos[0]-pos_g[0];
        float dy=pos[1]-pos_g[1];
        double ang=angulo(dx, dy);
        v[0]=v[0]+G*cos(ang)*DT;
        v[1]=v[1]+G*sin(ang)*DT;
    }
}

void mover(float pos[2],float v[2]){
    pos[0]=pos[0]+v[0]*DT;
    pos[1]=pos[1]+v[1]*DT;
}

void rotar_nave(polilinea_t *polilinea, double *angulo, bool horario){
{
    double delta_angulo;
    if(horario){
        *angulo-=NAVE_ROTACION_PASO;
        delta_angulo=-NAVE_ROTACION_PASO;
        }
    else{
        *angulo+=NAVE_ROTACION_PASO;
        delta_angulo=NAVE_ROTACION_PASO;
    }
    float x,y;
    polilinea_rotar(polilinea, *angulo);
}

}

static double dist_puntos(double ax, double ay, double bx, double by){
    return sqrt(pow(bx-ax,2)+pow(by-ay,2));
}

static double calc_alfa(double px, double py, double ax, double ay, double bx, double by){
    return ((px-ax)*(bx-ax)+(py-ay)*(by-ay))/pow(dist_puntos(ax,ay,bx,by),2);
}

static double encontrar_dist_segmento(double px, double py, double ax, double ay, double bx, double by){
    double alfa =calc_alfa(px, py, ax, ay, bx,by);
    if (alfa <= 0)
        return dist_puntos(ax, ay, px, py);
    else if (alfa >= 1)
        return dist_puntos(bx, by, px, py);
    else
        return dist_puntos(ax+alfa*(bx-ax),ay+alfa*(by-ay),px,py);
}

bool colision(const float polilinea[][2], size_t n, float pos[2], float radio){ //retorna true si chocó
    double dist, distMin;
    distMin=encontrar_dist_segmento(pos[0], pos[1], polilinea[0][0],polilinea[0][1],polilinea[1][0],polilinea[1][1]);
    for(size_t i = 1; i < n-1; i++){
        dist=encontrar_dist_segmento(pos[0], pos[1], polilinea[i][0],polilinea[i][1],polilinea[i+1][0],polilinea[i+1][1]);
        if(dist<distMin){
            distMin=dist;
            if(distMin<radio)
                return true;
        }
    }
    return false;
}