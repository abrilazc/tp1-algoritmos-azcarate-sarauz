#include "polilinea.h"

//tipos de datos
struct polilinea{
    float (*puntos)[2];
    color_t color;
    size_t n;
};

//creacion
polilinea_t *polilinea_crear_vacia(size_t n,color_t color){
	
	polilinea_t *vacia_polilinea= malloc(sizeof(polilinea_t));
    if(!vacia_polilinea)return NULL;
    
    vacia_polilinea->puntos=malloc(sizeof(float)*n*2); 
    if(!vacia_polilinea->puntos){
    	free(vacia_polilinea);
        return NULL;
    }
    
	vacia_polilinea->n=n;
    vacia_polilinea->color=color;
	
    return vacia_polilinea;
}
polilinea_t *polilinea_crear(const float puntos[][2], size_t n,color_t color){
	
	polilinea_t *nueva_polilinea=polilinea_crear_vacia(n,color);
    
    if(!nueva_polilinea) return NULL;
    
    memcpy(nueva_polilinea->puntos,puntos,n*sizeof(float)*2);

    return nueva_polilinea;
}

//setear
bool polilinea_setear_punto(polilinea_t *polilinea, size_t pos, float x, float y){

	if(pos>(polilinea->n)-1) return false;
	
	polilinea->puntos[pos][0]=x;
	polilinea->puntos[pos][1]=y;
	
	return true;
}
polilinea_t *polilinea_clonar(const polilinea_t *polilinea){
    polilinea_t *nueva_polilinea=polilinea_crear((const float (*) [2])polilinea->puntos,polilinea->n,polilinea->color);
    if(!nueva_polilinea) return NULL;
    return nueva_polilinea;
}
//hay que hacer ajuste dependiendo para que se use
bool polilinea_setear_color(polilinea_t *polilinea, color_t color) {
    uint8_t r, g, b;
    color_a_rgb(color, &r, &g, &b);
    printf("POLILINEA COLOR: (%d, %d, %d)\n", r, g, b);
    return true;
}
/*void polilinea_trasladar(polilinea_t *polilinea, double traslacion[2]){
    float x,y;
    for(size_t i=0; i<polilinea->n; i++){
        x = polilinea->puntos[i][0];
        y = polilinea->puntos[i][1];
        polilinea->puntos[i][0] = traslacion[0];
        polilinea->puntos[i][1] = traslacion[1];
        }
}
void polilinea_rotar(polilinea_t *polilinea, double angulo){
    float x,y;
    for(size_t i=0; i<polilinea->n; i++){
        x = polilinea->puntos[i][0];
        y = polilinea->puntos[i][1];
        polilinea->puntos[i][0] = x*cos(angulo) - y*sin(angulo);
        polilinea->puntos[i][1] = x*sin(angulo) + y*cos(angulo);
        }
}
*/

//getter
size_t polilinea_cantidad_puntos(const polilinea_t *polilinea){
	return polilinea->n;
}
bool polilinea_obtener_punto(const polilinea_t *polilinea, size_t pos, float *x, float *y){

	if(pos>(polilinea->n)-1) return false;

	*x=polilinea->puntos[pos][0];
	*y=polilinea->puntos[pos][1];
	
	return true;
}

//destruccion
void polilinea_destruir(polilinea_t *polilinea){
	free(polilinea->puntos);
	free(polilinea);
}