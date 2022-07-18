movimiento de nave:
getchar+tabla de busqueda sobre wasd o sistema similar
otras teclas pueden habilitar el escudo y el propulsr (y sus funciones respectivas).

TDA nave

typedef struct{
	poligono_t ...;
	float direccion[2]; //A:Cambiar por angulo?
	float posicion[2];
	float velocidad[2];
	float aceleracion[2]; //A:G va a depender del nivel, y si acelera va a depender de la direccion
	bool propulsor;
	char vidas;//se comienza con 3 vidas, usar cualquier tipo de dato bajo. Es poco probable superar 50... hay topee de vidas? A: Yo lo cambiaria por unit8_t
	int combustible;//se comienza con 10000 y se gasta demasiado. A: Tanto combustible como puntos capaz podrian ser uint? Supongo que no habria forma de tener negativos ahí
	int puntos;//se comienza con 0 y cada 10000 vuelve a 0.
	bool escudo;
	bool bala;//asumiendo que solo puede tener una bala a la vez

TDA torreta
	poligono_t ...;
	float posicion;// tiene que estar sobre la superfiecie
	float direccion;// tiene que ser normal a la superficie
	bool vive;
	bool bala;
	
TDA bala
	poligono_t ...; //si el poligono es una recta hacia atras
	float velocidad; //A: seria velocidad[2]
	float posicion; //posicion adecuado para interseccion. A: posicion[2]
	float tiempo_disponible;
	bool vive;
	
TDA planeta
	poligono_t ...;
	tipo...  ciclico o redondo //A: creo que se usaria el bool infinito que viene puesto en el archivo

TDA pantalla (o lista o enum): //A:como typedef enum?
	inicial o planeta o pelea nave,
	
	
	
funciones:

ES MUY POSIBLE QUE HAYA QUE HACER UNA FUNCION INTERSECCION ENTRE POLILINEAS //A: poner en fisica.c

contador de vida:

si puntos > 10000 --- + 1 vida
si la nave toca superficie ---- - 1 vida & resetea posicion (depende nivel) ¿tiene que tocar el poligono de la nave el poligono de la superficie? polignave==poligplaneta
si la nave toca proyectil ---- - 1 vida & resetea posicion (depende nivel) ¿tiene que tocar el poligono de la nave el poligono del disparo? //Á: se podria usar la misma funcion para si choca contra una bala o terreno
polignave==poligproyectil
si comb < 0 ---- - 1 vida & resetea posicion (depende nivel)

contador de combustible:

if ( escudo==true && distancia(barril<distancia_escudo)
	combustile +3000
if (escudo==true) //ver de combinar con el anterior if
	combustible -300/segundo
//otra opcion es hacer una funcion escudo que verifique lo primero, haga las otras funciones del escudo y al final reste el combustible.	

if (propulsor==true)
	combustible -250/segundo
//para esta tambien puede haber una funcion propulsor que afecte la aceleracion y cantidad de combustible.
	
contador de puntos:

tambien, puede ser secuencial varias veces o solo activarse en eventos, prefiero por eventos:

%%%%%%%%%%%%%%%%%%
mata nave? si ---> +100 chequeo si llega a 10000

mas profundo:
bool nave_enemiga(dato) si:
	bool nave_cerca (nave nuestra, nave enemiga)
	aca con que las posiciones esten cerca a un criterio nuestro alcnaza. La pregunta es ¿como se colocan las naves enemigas en el mapa? -> si vienen de prefabrica en un lugar especifico, se labura distinto el primer bool.
	si es verdad:
		se cambia de nivel
		
bool estas_en_el_nivel_de_naves -> cambia a si.//posible error, esto se decide con lista.
while(mi nave no sea alcanzada por un proyectil || la del oponente tampoco)
	esto sigue
cagó fuego mi nave? pierdo 1 vida
cagó fuego el otro? +100
vuelvo a la posicion original del mapa, contador del reactor, se reseta?
%%%%%%%%%%%%%%%%%%%%%%%%%%

si mato torreta gano 250, ni idea como poner esto

%%%%%%%%%%%%%%%%%%%%%%%%%

si cummplo reactor ¿no me da?

%%%%%%%%%%%%%%%%%%%%%%

si mato todas las torretas paso el nivel ¿me da el puntaje del mapa o el puntaje del mapa es la suma de las torretas?


Disparo torreta

si la torreta esta viva && no tiene una bala en el cielo && itnerseccion vista con nave, entocnes dispara.
esto suponiendo que tenemos una lsita predefinida de torretas, no pueden tener mas de una bala en el aire a la vez.

mover vista:

si el nivel es ciclico && nave toca el margen, la velocidad del cambio de vista podria ser un poco mayor a la de la nave





