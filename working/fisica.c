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

//chequear esta funcion
/*void rotar_nave(polilinea_t *polilinea, float *angulo, bool horario){
    {
    float delta_angulo;
    if(horario){
        *angulo-=NAVE_ROTACION_PASO;
        delta_angulo=-NAVE_ROTACION_PASO;
        }
    else{
        *angulo+=NAVE_ROTACION_PASO;
        delta_angulo=NAVE_ROTACION_PASO;
    }
    //float x,y; //q uedaron cometnadas porque no se estbaan usando
    polilinea_rotar(polilinea, *angulo);
    }
}*/

//MRUV
//Falta la funcion aceleracion, a una le pusiste "acelerar" pero es muy confuso.
//cambiar gravedad a un float





/*
void computar_aceleracion(float aceleracion[2], float gravedad, bool propulsion,float direccion){
   aceleracion[0]=gravedad+propulsion*cos(direccion)*G;
   aceleracion[1]=gravedad+propulsion*sin(direccion)*G;
}
*/

//Respecto a aceleracion, un poco confuso, pero podría pasar a ser una static si reacomodamos la firma
//Propongo





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

//colision

void colision_rebote(float pos[2], float v[2], size_t dim[2]){
    if(pos[0]<=0||pos[0]>=dim[0]){
        v[0]=-v[0];
    }
    else if(pos[1]<=0||pos[1]>=dim[1]){
        v[1]=-v[1];
    }
}

//procesamiento logico

//Propongo las sigueintes funciones para reemplzar dist_puntos y calc_alfa:
/* 
static float producto_interno(const float a[2], const float b[2]){ 
    return a[0]*b[0] + a[1]*b[1] ;
}
 
static float norma(const float a[2]){
    return sqrt(producto_interno(a,a));
}
 
static void resta(float res[2], const float a[2], const float b[2]){
      for(size_t i=0; i<2 ;i++){
      res[i] = a[i]-b[i];
   }
}
 */
//Ventajas? son bien claras y genericas. Si bien tienen static se podrían ampliar.

//Para reemplazar a:

static float dist_puntos(float ax, float ay, float bx, float by){
    return sqrt(pow(bx-ax,2)+pow(by-ay,2));
}

static float calc_alfa(float px, float py, float ax, float ay, float bx, float by){
    return ((px-ax)*(bx-ax)+(py-ay)*(by-ay))/pow(dist_puntos(ax,ay,bx,by),2);
}


//Calculo distancia_segmento
/*
static float encontrar_dist_segmento(float a[2], float b[2], float p[2]){
    float r_pa[2], r_ba[2], r_pb[2], res[2];
    resta(r_pa,p,a);
    resta(r_pb,b,p);
    resta(r_ba,b,a);
 
    float alpha=producto_interno(r_pa,r_ba)/pow(norma(r_ba),2);
    if(alpha<=0)
        return norma(r_pa);
    if(alpha>=1)
        return norma(r_pb);
    else{
        res[0] = a[0]+alpha*r_ba[0];
        res[1] = a[1]+alpha*r_ba[1];
        resta(res,res,p);
    }
        return norma(res);
}
 */
//Es muy parecida a la que tenes, pero usar los elementos operacionales de antes, ademas es mas corta la firma
//La ventaja de usar este sistema es que son funciones con nombress mucho mas claros

static float encontrar_dist_segmento(float p[2], float a[2], float b[2]){
    float alfa =calc_alfa(p[0], p[1], a[0], a[1], b[0],b[1]);
    if (alfa <= 0)
        return dist_puntos(p[0], p[1], a[0], a[1]);
    else if (alfa >= 1)
        return dist_puntos(b[0], b[1], p[0], p[1]);
    else
        return dist_puntos(a[0]+alfa*(b[0]-a[0]),a[1]+alfa*(b[1]-a[1]),p[0],p[1]);
}


/*
    Esta funcion revisa si UNA polilinea tiene itnerseccion, algunas figuras tienen mas de una polilinea.
    Ese caso, va a ser un iterador externo.
    Esto debe recibir una polilinea, el punto de la nave y el radio "de contacto"
*/

//Propuesta
//en la funcion llame a nave, pero en la firma puse el float primero
/*
bool contacto_polilinea(polilinea_t polilinea, float pos[2], float radio){
 
   float n=cantidad_puntos(polilinea)
   float primer_punto[2]={0,0};
   float segundo_punto[2]={0,0};
   float nave[2] = pos[2];//posicion(nave);
   size_t i=1;
   while(i<n){
       for(size_t j=0;j<2;j++){
           primer_punto[j] = polilinea[i-1][j];
           segundo_punto[j] = polilinea[i][j];
       }
       if(distancia_al_segmento(primer_punto, segundo_punto, nave) < radio){
           return true;
       }
       i++;
   }
   return false;
}
*/ 

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