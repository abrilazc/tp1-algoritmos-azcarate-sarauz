#include "caracteres.h"

float *caracteres[][2]={
	['a']=caracter_a,
	['b']=caracter_b,
	['c']=caracter_c,
	['d']=caracter_d,
	['e']=caracter_e,
	['f']=caracter_f,
	['g']=caracter_g,
	['h']=caracter_h,
	['i']=caracter_i,
	['j']=caracter_j,
	['k']=caracter_k,
	['l']=caracter_l,
	['m']=caracter_m,
	['n']=caracter_n,
	['o']=caracter_o,
	['p']=caracter_p,
	['q']=caracter_q,
	['r']=caracter_r,
	['s']=caracter_s,
	['t']=caracter_t,
	['u']=caracter_u,
	['v']=caracter_v,
	['w']=caracter_w,
	['x']=caracter_x,
	['y']=caracter_y,
	['z']=caracter_z,
	['1']=caracter_1,
	['2']=caracter_2,
	['3']=caracter_3,
	['4']=caracter_4,
	['5']=caracter_5,
	['6']=caracter_6,
	['7']=caracter_7,
	['8']=caracter_8,
	['9']=caracter_9,
	['0']=caracter_0,
	['x']=caracter_x,
	['y']=caracter_y,
	['z']=caracter_z,
	[' ']=caracter_espacio
};


float **polilinea_caracter(char caracter){
	return caracteres[caracter];
}

const size_t cantidad_filas(char caracter){
    static const size_t tam_caracter[]={
	['a']=sizeof(caracter_a)/(2*sizeof(float)),
	['b']=sizeof(caracter_b)/(2*sizeof(float)),
	['c']=sizeof(caracter_c)/(2*sizeof(float)),
	['d']=sizeof(caracter_d)/(2*sizeof(float)),
	['e']=sizeof(caracter_e)/(2*sizeof(float)),
	['f']=sizeof(caracter_f)/(2*sizeof(float)),
	['g']=sizeof(caracter_g)/(2*sizeof(float)),
	['h']=sizeof(caracter_h)/(2*sizeof(float)),
	['i']=sizeof(caracter_i)/(2*sizeof(float)),
	['j']=sizeof(caracter_j)/(2*sizeof(float)),
	['k']=sizeof(caracter_k)/(2*sizeof(float)),
	['l']=sizeof(caracter_l)/(2*sizeof(float)),
	['m']=sizeof(caracter_m)/(2*sizeof(float)),
	['n']=sizeof(caracter_n)/(2*sizeof(float)),
	['o']=sizeof(caracter_o)/(2*sizeof(float)),
	['p']=sizeof(caracter_p)/(2*sizeof(float)),
	['q']=sizeof(caracter_q)/(2*sizeof(float)),
	['r']=sizeof(caracter_r)/(2*sizeof(float)),
	['s']=sizeof(caracter_s)/(2*sizeof(float)),
	['t']=sizeof(caracter_t)/(2*sizeof(float)),
	['u']=sizeof(caracter_u)/(2*sizeof(float)),
	['v']=sizeof(caracter_v)/(2*sizeof(float)),
	['w']=sizeof(caracter_w)/(2*sizeof(float)),
	['x']=sizeof(caracter_x)/(2*sizeof(float)),
	['y']=sizeof(caracter_y)/(2*sizeof(float)),
	['z']=sizeof(caracter_z)/(2*sizeof(float)),
	['1']=sizeof(caracter_1)/(2*sizeof(float)),
	['2']=sizeof(caracter_2)/(2*sizeof(float)),
	['3']=sizeof(caracter_3)/(2*sizeof(float)),
	['4']=sizeof(caracter_4)/(2*sizeof(float)),
	['5']=sizeof(caracter_5)/(2*sizeof(float)),
	['6']=sizeof(caracter_6)/(2*sizeof(float)),
	['7']=sizeof(caracter_7)/(2*sizeof(float)),
	['8']=sizeof(caracter_8)/(2*sizeof(float)),
	['9']=sizeof(caracter_9)/(2*sizeof(float)),
	['0']=sizeof(caracter_0)/(2*sizeof(float)),
	['x']=sizeof(caracter_x)/(2*sizeof(float)),
	['y']=sizeof(caracter_y)/(2*sizeof(float)),
	['z']=sizeof(caracter_z)/(2*sizeof(float)),
	[' ']=sizeof(caracter_espacio)/(2*sizeof(float))
    };
    return tam_caracter[caracter];
}


bool numero_a_polilinea(int numero,SDL_Renderer *renderer, float posicion[2], float escala){
	char palabra[10];
	SDL_itoa(numero,palabra,10);//pasa el numero a palabra
	return palabra_a_polilinea(renderer,palabra,posicion,direccion);
}
bool palabra_a_polilinea(SDL_Renderer *renderer,char *palabra, float posicion[2], float escala){
	char *letra;
	polilinea_t *polilinea;
	float espacio[]={6,0};
	while((letra=getchar(palabra))!='\0'){
		polilinea=letra_a_polilinea(letra);
		dibujar_polilinea(renderer, polilinea,posicion+espacio,escala);
	}
	return true;
}
polilinea_t *letra_a_polilinea(char caracter){
	size_t cantidad=cantidad_filas(caracter);
	float **matriz=polilinea_caracter(caracter);
	polilinea_t *polilinea=polilinea_crear(matriz,cantidad_filas,0);
	return polilinea;
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

