#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define LNOM 20 //maximo largo de el nombre con el /0
#define MASCARAR 0x04   //bin 00000100
#define MASCARAG 0x02   //bin 00000010
#define MASCARAB 0x01   //bin 00000001
#define MASCARAINF 0x40 //bin 01000000
#define MASCARATIPO 0x0e//bin 00001110
#define MASCARACOLOR 0xe000 //bin 1110000000000000
#define MASCARAN 0x03ff //bin 0000001111111111

typedef uint8_t color_t;



typedef struct {
    float (*puntos)[2];
    color_t color;
    size_t n;
} polilinea_t;

polilinea_t *polilinea_crear_vacia(size_t t){
    printf("POLILINEA N=%zd\n", t);
    polilinea_t *p = malloc(sizeof(polilinea_t));
    if (p==NULL) 
        return NULL;
    p->puntos=malloc(t*sizeof(float)*2);
    if(p->puntos==NULL){
        free(p);
        return NULL;    
    }
    p->n=t;
    return p;
}

void polilinea_destruir(polilinea_t *polilinea){
    free(polilinea->puntos);
    free(polilinea);
}

typedef enum {
    ICONO,
    NIVEL,
    SPRITE,
} figura_tipo_t;

char *tipos_de_figura[]={
    [ICONO]="Icono",
    [NIVEL]="Nivel",
    [SPRITE]="Sprite",
};

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    return tipos_de_figura[figura];
}

color_t color_crear(bool r, bool g, bool b){
    return (r<<2) | (g<<1) | b;
}

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){
    *r=((c&MASCARAR)>>2)*255;
    *g=((c&MASCARAG)>>1)*255;
    *b=((c&MASCARAB))*255;
}

bool polilinea_setear_color(polilinea_t *polilinea, color_t color) {
    uint8_t r, g, b;
    polilinea->color = color;
    color_a_rgb(color, &r, &g, &b);
    printf("POLILINEA COLOR: (%d, %d, %d)\n", r, g, b);
    return true;
}

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){

    if(fread(nombre, sizeof(char), LNOM, f)!=LNOM){
        return false;
    }
    uint8_t caracteristica;

    if(fread(&caracteristica, sizeof(uint8_t), 1, f)!=1){
        return false;
    }
    *infinito=false;
    if(caracteristica&MASCARAINF)
        *infinito=true;
    
    *tipo=((caracteristica&MASCARATIPO)>>1);
    uint16_t cantpol;
    if(fread(&cantpol, sizeof(uint16_t), 1, f)!=1){
        return false;
    }
    *cantidad_polilineas=cantpol;
    return true;
}

bool polilinea_setear_punto(polilinea_t *polilinea, size_t pos, float x, float y) {

    if(pos>=polilinea->n){
        return false;
    }

    *(polilinea->puntos[pos])=x;
    *(polilinea->puntos[pos]+1)=y;

    printf("POLILINEA[%zd] = (%.2f, %.2f)\n", pos, x, y);

    if(x==*(polilinea->puntos[pos])&&y==*(polilinea->puntos[pos]+1)) 
        return true;
    return false;

}

polilinea_t *leer_polilinea(FILE *f){

    uint16_t encabezado;

    if(fread(&encabezado,sizeof(uint16_t), 1, f)!=1){
        return NULL;
    }

    color_t color=color_crear((encabezado>>13)& MASCARAR,(encabezado>>13)& MASCARAG,(encabezado>>13)& MASCARAB); 
    size_t n=encabezado & MASCARAN;
    printf("Numero de puntos %zd\n", n);
    polilinea_t *p = polilinea_crear_vacia(n);
    if(p==NULL)
        return NULL;
    polilinea_setear_color(p,color);
    
    float pos[2];

    for(size_t i=0; i<n;i++){
        if(fread(pos, 2, sizeof(float), f)!=sizeof(float)){
            polilinea_destruir(p);
            return NULL;
        }
            
        if(!polilinea_setear_punto(p, i, pos[0], pos[1])){
            polilinea_destruir(p);
            return NULL;    
        }
}
    return p;
    
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse \"%s\"\n", argv[1]);
        return 1;
    }

    int figura = 0;
    while(1) {
        figura++;

        char nombre[20];
        bool infinito;
        figura_tipo_t tipo;
        size_t cantidad_polilineas;

        if(! leer_encabezado_figura(f, nombre, &tipo, &infinito, &cantidad_polilineas))
            break;

        printf("FIGURA \"%s\", TIPO: %s, INFINITO: %d, POLILINEAS: %zd\n", nombre, figura_tipo_a_cadena(tipo), infinito, cantidad_polilineas);

        for(size_t i = 0; i < cantidad_polilineas; i++) {
            polilinea_t *p = leer_polilinea(f);
            if(p == NULL) {
                fprintf(stderr, "Error en el archivo");
                fclose(f);
                return 1;
            }
            polilinea_destruir(p);
        }
    }

    fclose(f);

    return 0;
}
