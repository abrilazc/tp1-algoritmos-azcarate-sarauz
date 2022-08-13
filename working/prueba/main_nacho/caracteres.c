#include "caracteres.h"

struct caracter{
    const float (*puntos)[2];
	char letra;
    size_t longitud;
};



cater_t *estructura_letra(char dato){
	static const cater_t caracteres[]={
		{caracter_a,'a', sizeof(caracter_a)/(2*sizeof(float))},
		{caracter_b,'b', sizeof(caracter_b)/(2*sizeof(float))},
		{caracter_c,'c', sizeof(caracter_c)/(2*sizeof(float))},
		{caracter_d,'d', sizeof(caracter_d)/(2*sizeof(float))},
		{caracter_e,'e', sizeof(caracter_e)/(2*sizeof(float))},
		{caracter_f,'f', sizeof(caracter_f)/(2*sizeof(float))},
		{caracter_g,'g', sizeof(caracter_g)/(2*sizeof(float))},
		{caracter_h,'h', sizeof(caracter_h)/(2*sizeof(float))},
		{caracter_i,'i', sizeof(caracter_i)/(2*sizeof(float))},
		{caracter_j,'j', sizeof(caracter_j)/(2*sizeof(float))},
		{caracter_k,'k', sizeof(caracter_k)/(2*sizeof(float))},
		{caracter_l,'l', sizeof(caracter_l)/(2*sizeof(float))},
		{caracter_m,'m', sizeof(caracter_m)/(2*sizeof(float))},
		{caracter_n,'n', sizeof(caracter_n)/(2*sizeof(float))},
		{caracter_o,'o', sizeof(caracter_o)/(2*sizeof(float))},
		{caracter_p,'p', sizeof(caracter_p)/(2*sizeof(float))},
		{caracter_q,'q', sizeof(caracter_q)/(2*sizeof(float))},
		{caracter_r,'r', sizeof(caracter_r)/(2*sizeof(float))},
		{caracter_s,'s', sizeof(caracter_s)/(2*sizeof(float))},
		{caracter_t,'t', sizeof(caracter_t)/(2*sizeof(float))},
		{caracter_u,'u', sizeof(caracter_u)/(2*sizeof(float))},
		{caracter_v,'v', sizeof(caracter_v)/(2*sizeof(float))},
		{caracter_w,'w', sizeof(caracter_w)/(2*sizeof(float))},
		{caracter_x,'x', sizeof(caracter_x)/(2*sizeof(float))},
		{caracter_y,'y', sizeof(caracter_y)/(2*sizeof(float))},
		{caracter_z,'z', sizeof(caracter_z)/(2*sizeof(float))},
		{caracter_1,'1', sizeof(caracter_1)/(2*sizeof(float))},
		{caracter_2,'2', sizeof(caracter_2)/(2*sizeof(float))},
		{caracter_3,'3', sizeof(caracter_3)/(2*sizeof(float))},
		{caracter_4,'4', sizeof(caracter_4)/(2*sizeof(float))},
		{caracter_5,'5', sizeof(caracter_5)/(2*sizeof(float))},
		{caracter_6,'6', sizeof(caracter_6)/(2*sizeof(float))},
		{caracter_7,'7', sizeof(caracter_7)/(2*sizeof(float))},
		{caracter_8,'8', sizeof(caracter_8)/(2*sizeof(float))},
		{caracter_9,'9', sizeof(caracter_9)/(2*sizeof(float))},
		{caracter_0,'0', sizeof(caracter_0)/(2*sizeof(float))},
		{caracter_espacio,' ', sizeof(caracter_espacio)/(2*sizeof(float))}
	};

    size_t cantidad=sizeof(caracteres)/sizeof(caracteres[0]);
    for(size_t i=0;i<cantidad;i++){
        if(caracteres[i].letra == dato){
        	cater_t *caracter = &caracteres[i];
            return caracter;
        }
    }
    return NULL;
}

void dibujar_letra(SDL_Renderer *renderer,char caracter, float posicion[2], color_t color){
    cater_t *literal=estructura_letra(caracter);
	size_t cant_punt=literal->longitud;
    const float matriz[cant_punt][2];
	
	for(size_t i=0;i<cant_punt-1;i++){
		matriz[i][0]=literal->puntos[0];
		matriz[i][1]=literal->puntos[1];
	}
	uint16_t r,g,b;
   	color_a_rgb(color,r,g,b);
	float escala=1;
	
    SDL_SetRenderDrawColor(renderer, r, g, b, 0x00);   
    for(size_t j=0;j<cant_punt-1;j++){
        SDL_RenderDrawLine(
            renderer,   
            (matriz[j][0]*escala+posicion[0]),
            -(matriz[j][1]*escala+posicion[1]) + VENTANA_ALTO,
            (matriz[j+1][0]*escala+posicion[0]) ,
            -(matriz[j+1][1]*escala+posicion[1]) + VENTANA_ALTO
            );
    }
}
void palabra_a_polilinea(SDL_Renderer *renderer,char *palabra, float posicion[2], color_t color){
	char *letra;
	float espacio[]={6,0}
	while((letra=getchar(palabra))!='\0'){
		polilinea=letra_a_polilinea(letra);
		dibujar_letra(renderer, letra,posicion+espacio,escala,color);
	}
}
void numero_a_polilinea(int numero,SDL_Renderer *renderer, float posicion[2], color_t color){
	char palabra[10];
	SDL_itoa(numero,palabra,10);//pasa el numero a palabra
	palabra_a_polilinea(renderer,palabra,posicion,color);
}

const float caracter_a[7][2] = {
	{0, 0},
	{0, 4},
	{2, 6},
	{4, 4},
	{4, 0},
	{4, 2},
	{0, 2}
};

const float caracter_b[12][2] = {
	{0, 3},
	{0, 6},
	{3, 6},
	{4, 5},
	{4, 4},
	{3, 3},
	{0, 3},
	{0, 0},
	{3, 0},
	{4, 1},
	{4, 2},
	{3, 3},
};

const float caracter_c[4][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
};

const float caracter_d[7][2] = {
	{0, 0},
	{0, 6},
	{2, 6},
	{4, 4},
	{4, 2},
	{2, 0},
	{0, 0}
};

const float caracter_e[7][2] = {
	{4, 0},
	{0, 0},
	{0, 3},
	{3, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const float caracter_f[6][2] = {
	{0, 0},
	{0, 3},
	{3, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const float caracter_g[7][2] = {
	{2, 2},
	{4, 2},
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 4},
};

const float caracter_h[6][2] = {
	{0, 0},
	{0, 6},
	{0, 3},
	{4, 3},
	{4, 6},
	{4, 0},
};

const float caracter_i[6][2] = {
	{0, 0},
	{4, 0},
	{2, 0},
	{2, 6},
	{4, 6},
	{0, 6},
};

const float caracter_j[4][2] = {
	{0, 2},
	{2, 0},
	{4, 0},
	{4, 6},
};

const float caracter_k[6][2] = {
	{0, 0},
	{0, 6},
	{0, 3},
	{3, 6},
	{0, 3},
	{3, 0},
};

const float caracter_l[3][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
};

const float caracter_m[5][2] = {
	{0, 0},
	{0, 6},
	{2, 4},
	{4, 6},
	{4, 0},
};

const float caracter_n[4][2] = {
	{0, 0},
	{0, 6},
	{4, 0},
	{4, 6},
};

const float caracter_o[5][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 0},
};

const float caracter_p[5][2] = {
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
};

const float caracter_q[9][2] = {
	{2, 2},
	{3, 1},
	{2, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 2},
	{3, 1},
	{4, 0},
};

const float caracter_r[7][2] = {
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
	{1, 3},
	{4, 0},
};

const float caracter_s[6][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const float caracter_t[4][2] = {
	{2, 0},
	{2, 6},
	{4, 6},
	{0, 6},
};

const float caracter_u[4][2] = {
	{0, 6},
	{0, 0},
	{4, 0},
	{4, 6},
};

const float caracter_v[3][2] = {
	{0, 6},
	{2, 0},
	{4, 6},
};

const float caracter_w[5][2] = {
	{0, 6},
	{0, 0},
	{2, 2},
	{4, 0},
	{4, 6},
};

const float caracter_x[5][2] = {
	{0, 0},
	{4, 6},
	{2, 3},
	{0, 6},
	{4, 0},
};

const float caracter_y[5][2] = {
	{0, 6},
	{2, 4},
	{4, 6},
	{2, 4},
	{2, 0},
};

const float caracter_z[4][2] = {
	{0, 6},
	{4, 6},
	{0, 0},
	{4, 0},
};

const float caracter_0[5][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 0},
};

const float caracter_1[2][2] = {
	{2, 0},
	{2, 6},
};

const float caracter_2[6][2] = {
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
	{0, 0},
	{4, 0},
};

const float caracter_3[7][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{4, 3},
	{4, 6},
	{0, 6},
};

const float caracter_4[5][2] = {
	{0, 6},
	{0, 3},
	{4, 3},
	{4, 6},
	{4, 0},
};

const float caracter_5[6][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const float caracter_6[5][2] = {
	{0, 6},
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
};

const float caracter_7[3][2] = {
	{0, 6},
	{4, 6},
	{4, 0},
};

const float caracter_8[7][2] = {
	{0, 3},
	{0, 6},
	{4, 6},
	{4, 0},
	{0, 0},
	{0, 3},
	{4, 3},
};

const float caracter_9[5][2] = {
	{4, 0},
	{4, 6},
	{0, 6},
	{0, 3},
	{4, 3},
};

const float caracter_derecha[5][2] = {
	{0, 3},
	{12, 3},
	{9, 5},
	{9, 1},
	{12, 3},
};

const float caracter_izquierda[5][2] = {
	{12, 3},
	{0, 3},
	{3, 5},
	{3, 1},
	{0, 3},
};

const float caracter_arriba[5][2] = {
	{5, -2},
	{5, 10},
	{3, 7},
	{7, 7},
	{5, 10},
};

const float caracter_abajo[5][2] = {
	{5, 10},
	{5, -2},
	{3, 1},
	{7, 1},
	{5, -2},
};

const float caracter_espacio[1][2] = {
	{0, 0},
};

