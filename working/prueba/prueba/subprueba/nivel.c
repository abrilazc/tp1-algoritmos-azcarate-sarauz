#include "nivel.h"

struct vector{
    float x,y,z;
};
struct objeto{
    float posicion[2];
    float direccion;
};
struct reactor{
    bool estar;
    float posicion[2];
    float direccion;
    float tiempo;
};

struct nivel{
    figura_t *figura;
    bool infinito;
    lista_t *combustible;
    lista_t *torreta;
    reactor_t *reactor;
};


//Tablas de busqueda, arreglos estaticos y getters
//Cantidades
const size_t cantidad_combustible(planeta_nombre nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=2,
    [NIVEL1R]=0,
    [NIVEL1NW]=4,
    [NIVEL1SW]=3
    };
    return cantidad[nombre];
}
const size_t cantidad_torretas(planeta_nombre nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=4,
    [NIVEL1R]=0,
    [NIVEL1NW]=8,
    [NIVEL1SW]=6
    };
    return cantidad[nombre];
}
const bool cantidad_reactores(planeta_nombre nombre){
    static const bool cantidad[]={
    [NIVEL1NE]=0,
    [NIVEL1SE]=0,
    [NIVEL1R]=1,
    [NIVEL1NW]=0,
    [NIVEL1SW]=0
    };
    return cantidad[nombre];
}
//Nombres
const char* nombre_asignado(planeta_nombre nombre){
    static const char* asignacion[]={
    [NIVEL1NE]="NIVEL1NE",
    [NIVEL1SE]="NIVEL1SE",
    [NIVEL1R]="NIVEL1R",
    [NIVEL1NW]="NIVEL1NW",
    [NIVEL1SW]="NIVEL1SW"
    };
    return asignacion[nombre];
}
//Posiciones
vector_t *posicion_combustible(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][8]={
    [NIVEL1NE]={
        {.x=1064,.y=13,.z=0},
        {.x=1685,.y=113,.z=0}},
    [NIVEL1SE]={
        {.x=482,.y=94,.z=0},
        {.x=1751,.y=247,.z=0}},
    [NIVEL1R]={
        {0,0,0}},
    [NIVEL1NW]={
        {.x=188,.y=429,.z=9},
        {667,600,0},
        {1054,404,0},
        {574,344,0}},
    [NIVEL1SW]={
        {.x=820,.y=46,.z=0},
        {1196,68,0},
        {1602,46,0}}
    };

    *cantidad=cantidad_combustible(nombre);

    return vectores[nombre];
}
vector_t *posicion_torreta(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][8]={
    [NIVEL1NE]={
        {.x=916,.y=75,.z=-0.66},
        {.x=1425,.y=159,.z=0.66}},
    [NIVEL1SE]={
        {.x=423,.y=195,.z=-0.66},
        {.x=806,.y=215,.z=-0.33},
        {.x=1254,.y=153,.z=0.66},
        {.x=1587,.y=223,.z=2.23}},
    [NIVEL1R]={
        {0,0,0}},
    [NIVEL1NW]={
        {.x=257,.y=440,.z=0.66},
        {719,674,2.23},
        {985,565,0},
        {1125,417,3.8},
        {.x=862,.y=163,.z=3.8},
        {.x=626,.y=323,.z=2.23},
        {.x=505,.y=331,.z=3.8},
        {.x=378,.y=296,.z=2.23}},
    [NIVEL1SW]={
        {.x=70,.y=46,.z=0},
        {506,12,0},
        {952,12,0},
        {.x=1385,.y=12,.z=0},
        {.x=757,.y=210,.z=3.14},
        {.x=1161,.y=210,.z=3.14}}
    };
   
    *cantidad=cantidad_torretas(nombre);

    return vectores[nombre];
}

//Crear
//niveles
nivel_t *crear_nivel(figura_t **figuras,planeta_nombre nombre){
    nivel_t *nivel=malloc(sizeof(nivel_t));
    if(nivel==NULL) return NULL;
    
    figura_t *figura=cargar_nombre(figuras,(char *)nombre_asignado(nombre));
    
    nivel->figura=figura;
    nivel->infinito=infinito_fig(figura);
    nivel->combustible=lista_combustible(nombre);
    nivel->torreta=lista_torreta(nombre);
    nivel->reactor=crear_reactor(nombre);

    return nivel;
}
nivel_t **crear_niveles(figura_t **figuras, size_t cantidad){
    
    nivel_t **conjunto_niveles=malloc(sizeof(nivel_t*)*cantidad);
    if(conjunto_niveles==NULL) return NULL;

    for(size_t i=0;i<cantidad;i++){
        //figura_t *figura=conjunto_niveles[i];
        conjunto_niveles[i]=crear_nivel(figuras,i);//ke
    }
    return conjunto_niveles;
}
//combustible, torreta y reactor
lista_t *lista_combustible(planeta_nombre planeta){
    lista_t *l_combustible=lista_crear();
    armar_lista_combustible(l_combustible,planeta);
    return l_combustible;
}
lista_t *lista_torreta(planeta_nombre planeta){
    lista_t *l_torreta=lista_crear();
    armar_lista_torreta(l_torreta,planeta);
    return l_torreta;
}
reactor_t *crear_reactor(planeta_nombre planeta){
    if(!cantidad_reactores(planeta)) return NULL;
    reactor_t *nuevo=malloc(sizeof(reactor_t));
    if(nuevo==NULL) return NULL;

    nuevo->estar=true;
    nuevo->posicion[0]=815;
    nuevo->posicion[1]=309;
    nuevo->direccion=0;
    nuevo->tiempo=25;

    return nuevo;
}

//Admin
objeto_t *crear_objeto(vector_t *referencia, size_t fila){
    
    objeto_t *objeto=malloc(sizeof(objeto_t));
    if(objeto==NULL) return NULL;

    float posicion[2];
    float direccion;

    posicion[0]=(referencia[fila]).x;
    posicion[1]=(referencia[fila]).y;
    direccion=(referencia[fila]).z;
   

    objeto->posicion[0]=posicion[0];
    objeto->posicion[1]=posicion[1];
    objeto->direccion=direccion;
    
    return objeto;
}
void armar_lista_combustible(lista_t *lista, planeta_nombre planeta){
    
    objeto_t *objeto=NULL;
    int cantidad=0;
    size_t fila=0;
    float posicion[2]={0,0};
    float direccion=0;

    vector_t *referencia=posicion_combustible(planeta,&cantidad);//unica diferencia
  
    while(fila<cantidad){
        objeto=crear_objeto(referencia,fila);
        lista_insertar_primero(lista,objeto);
        objeto_a_posicion(objeto,posicion);
        objeto_a_direccion(objeto,&direccion);
        
        fila++;
    }
}
void armar_lista_torreta(lista_t *lista, planeta_nombre planeta){
    
    objeto_t *objeto=NULL;
    int cantidad=0;
    size_t fila=0;
    float posicion[2]={0,0};
    float direccion=0;

    vector_t *referencia=posicion_torreta(planeta,&cantidad);//unica diferencia
  
    while(fila<cantidad){
        objeto=crear_objeto(referencia,fila);
        lista_insertar_primero(lista,objeto);
        objeto_a_posicion(objeto,posicion);
        objeto_a_direccion(objeto,&direccion);
        fila++;
    }
}
//Seteos o reseteos
void decremento_reactor(reactor_t *reactor){
    (reactor->tiempo)-=1/(JUEGO_FPS*25);
}



//CARGAS
//nivel
nivel_t *cargar_datos_nivel(nivel_t **niveles,planeta_nombre nombre){
    nivel_t *nivel=niveles[nombre];
    return nivel;
}
//getter externo
bool get_infinito(nivel_t *nivel){
    return nivel->infinito;
}
/*reactor_t *get_reactor_nivel(nivel_t *nivel){
    reactor_t reactor=nivel->reactor;
    return reactor;
}*/
size_t get_cantidad_torretas(nivel_t *nivel){
    return lista_largo(nivel->torreta);
}
size_t get_cantidad_combustible(nivel_t *nivel){
    return lista_largo(nivel->combustible);
}
lista_t *get_lista_torreta(nivel_t *nivel){
    lista_t *torreta=nivel->torreta;
    return torreta;
}
lista_t *get_lista_combustible(nivel_t *nivel){
    lista_t *combustible=nivel->combustible;
    return combustible;
}
figura_t *get_figura_nivel(nivel_t *nivel){
  figura_t *figura=nivel->figura;
  return figura;
}
void objeto_a_posicion(objeto_t *objeto,float *posicion){
    posicion[0]=objeto->posicion[0];
    posicion[1]=objeto->posicion[1];
}
void objeto_a_direccion(objeto_t *objeto,float *direccion){
    *direccion=objeto->direccion;
}
//reactor
bool check_reactor_nivel(nivel_t *nivel){
    reactor_t *reactor=nivel->reactor;
    if(reactor==NULL) return false;
    return true;
}
void get_posicion_reactor(nivel_t *nivel, float *posicion){
    reactor_t *reactor=nivel->reactor;
    posicion[0]=reactor->posicion[0];
    posicion[1]=reactor->posicion[1];
}
float get_direccion_reactor(nivel_t *nivel){
    reactor_t *reactor=nivel->reactor;
    float direccion=reactor->direccion;
    return direccion;
}
float get_tiempo(nivel_t *nivel){
    reactor_t *reactor=nivel->reactor;
    float tiempo=reactor->tiempo;
    return tiempo;
}

//DESTRUIR
//lista_destruir
void destruir_cosa(objeto_t *objeto){
    free(objeto);
}
void destruir_bien(void *objeto){
    destruir_cosa(objeto);
}
void destruir_reactor(reactor_t *reactor){
    free(reactor);
}
//nivel
void destruir_nivel(nivel_t *nivel){
    lista_destruir(nivel->combustible,destruir_bien);
    lista_destruir(nivel->torreta,destruir_bien);
    destruir_reactor(nivel->reactor);
    free(nivel);
}
void destruir_niveles(nivel_t **niveles, size_t cantidad_niveles){
    for(size_t i=0;i<cantidad_niveles;i++){
        destruir_nivel(niveles[i]);
    }
    free(niveles);
}