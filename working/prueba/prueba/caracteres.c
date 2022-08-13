#include "caracteres.h"


#define CARACTER_ANCHO 6
#define CARACTER_ALTO 6

#define MAX_CARACTER 50
#define MAX_CARACTERES 42

struct caracter{
	char letra;
	const float (*polilinea)[2];
	size_t cantidad;
};

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

cater_t caracteres[] = {
		[A]= { 'A', caracter_a, (sizeof(caracter_a)/sizeof(caracter_a[0][0])/2)},
		[B]= { 'B', caracter_b, (sizeof(caracter_b)/sizeof(caracter_b[0][0])/2)},
		[C]= { 'C', caracter_c, (sizeof(caracter_c)/sizeof(caracter_c[0][0])/2)},
		[D]= { 'D', caracter_d, (sizeof(caracter_d)/sizeof(caracter_d[0][0])/2)},
		[E]= { 'E', caracter_e, (sizeof(caracter_e)/sizeof(caracter_e[0][0])/2)},
		[F]= { 'F', caracter_f, (sizeof(caracter_f)/sizeof(caracter_f[0][0])/2)},
		[g]= { 'G', caracter_g, (sizeof(caracter_g)/sizeof(caracter_g[0][0])/2)},
		[H]= { 'H', caracter_h, (sizeof(caracter_h)/sizeof(caracter_h[0][0])/2)},
		[I]= { 'I', caracter_i, (sizeof(caracter_i)/sizeof(caracter_i[0][0])/2)},
		[J]= { 'J', caracter_j, (sizeof(caracter_j)/sizeof(caracter_j[0][0])/2)},
		[K]= { 'K', caracter_k, (sizeof(caracter_k)/sizeof(caracter_k[0][0])/2)},
		[L]= { 'L', caracter_l, (sizeof(caracter_l)/sizeof(caracter_l[0][0])/2)},
		[M]= { 'M', caracter_m, (sizeof(caracter_m)/sizeof(caracter_m[0][0])/2)},
		[N]= { 'N', caracter_n, (sizeof(caracter_n)/sizeof(caracter_n[0][0])/2)},
		[O]= { 'O', caracter_o, (sizeof(caracter_o)/sizeof(caracter_o[0][0])/2)},
		[P]= { 'P', caracter_p, (sizeof(caracter_p)/sizeof(caracter_p[0][0])/2)},
		[Q]= { 'Q', caracter_q, (sizeof(caracter_q)/sizeof(caracter_q[0][0])/2)},
		[R]= { 'R', caracter_r, (sizeof(caracter_r)/sizeof(caracter_r[0][0])/2)},
		[S]= { 'S', caracter_s, (sizeof(caracter_s)/sizeof(caracter_s[0][0])/2)},
		[T]= { 'T', caracter_t, (sizeof(caracter_t)/sizeof(caracter_t[0][0])/2)},
		[U]= { 'U', caracter_u, (sizeof(caracter_u)/sizeof(caracter_u[0][0])/2)},
		[V]= { 'V', caracter_v, (sizeof(caracter_v)/sizeof(caracter_v[0][0])/2)},
		[W]= { 'W', caracter_w, (sizeof(caracter_w)/sizeof(caracter_w[0][0])/2)},
		[X]= { 'X', caracter_x, (sizeof(caracter_x)/sizeof(caracter_x[0][0])/2)},
		[Y]= { 'Y', caracter_y, (sizeof(caracter_y)/sizeof(caracter_y[0][0])/2)},
		[Z]= { 'Z', caracter_z, (sizeof(caracter_z)/sizeof(caracter_z[0][0])/2)},

		[CERO]= { '0', caracter_0, (sizeof(caracter_0)/sizeof(caracter_0[0][0])/2)},
		[UNO]= { '1', caracter_1, (sizeof(caracter_1)/sizeof(caracter_1[0][0])/2)},
		[DOS]= { '2', caracter_2, (sizeof(caracter_2)/sizeof(caracter_2[0][0])/2)},
		[TRES]= { '3', caracter_3, (sizeof(caracter_3)/sizeof(caracter_3[0][0])/2)},
		[CUATRO]= { '4', caracter_4, (sizeof(caracter_4)/sizeof(caracter_4[0][0])/2)},
		[CINCO]= { '5', caracter_5, (sizeof(caracter_5)/sizeof(caracter_5[0][0])/2)},
		[SEIS]= { '6', caracter_6, (sizeof(caracter_6)/sizeof(caracter_6[0][0])/2)},
		[SIETE]= { '7', caracter_7, (sizeof(caracter_7)/sizeof(caracter_7[0][0])/2)},
		[OCHO]= { '8', caracter_8, (sizeof(caracter_8)/sizeof(caracter_8[0][0])/2)},
		[NUEVE]= { '9', caracter_9, (sizeof(caracter_9)/sizeof(caracter_9[0][0])/2)},

		[DERECHA]= { '>', caracter_derecha, (sizeof(caracter_derecha)/sizeof(caracter_derecha[0][0])/2)},
		[IZQUIERDA]= { '<', caracter_izquierda, (sizeof(caracter_izquierda)/sizeof(caracter_izquierda[0][0])/2)},
		[ARRIBA]= { '^', caracter_arriba, (sizeof(caracter_arriba)/sizeof(caracter_arriba[0][0])/2)},
		[ABAJO]= { 'v', caracter_abajo, (sizeof(caracter_abajo)/sizeof(caracter_abajo[0][0])/2)},
		[ESPACIO]= { ' ', caracter_espacio, (sizeof(caracter_espacio)/sizeof(caracter_espacio[0][0])/2)},
};


void dibujar_letra(SDL_Renderer *renderer,char caracter, float posicion[2], bool r, bool ge, bool b){
    
	size_t cant_punt=sizeof(caracteres)/sizeof(caracteres[0]);
    float escala=1;
	for(size_t i=0;i<cant_punt;i++){
		if(caracter==caracteres[i].letra){
		polilinea_t* polilinea = polilinea_crear(caracteres[i].polilinea, caracteres[i].cantidad, color_crear(r, ge, b));
		dibujar_polilinea(renderer,polilinea,posicion,escala);
		polilinea_destruir(polilinea);
		}
    }
}

void palabra_a_polilinea(SDL_Renderer *renderer,char *palabra, float posicion[2],  bool r, bool ge, bool b){
	size_t i=0;
	posicion[0]+=ESP_LET;
	while(palabra[i]!='\0'){
		dibujar_letra(renderer, palabra[i],posicion,r,ge,b);
	}
}

void numero_a_polilinea(int numero,SDL_Renderer *renderer, float posicion[2],  bool r, bool ge, bool b){
	char palabra[10];
	SDL_itoa(numero,palabra,10);//pasa el numero a palabra
	palabra_a_polilinea(renderer,palabra,posicion, r,ge,b);
}
