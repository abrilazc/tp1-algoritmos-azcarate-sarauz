2/8
En físicas y polilinea:
chequear rotar y traladar nave y polilinea. Andan raro.
Rotar nave tienen disitnos nombres en fisica.c y fisica.h
----------------------------------------------------
1/8
Cargar tipos de datos, 2 maneras:

POR NOMBRE: bien clarito, pero largo:

figura_t **memoria=crear_figuras(f);
figura_t **figuras_icono=cargar_tipo(memoria,ICONO);
figura_t **figuras_nivel=cargar_tipo(memoria,NIVEL);
figura_t **figuras_sprite=cargar_tipo(memoria,SPRITE);
figura_t **figura_planeta=cargar_tipo(memoria,PLANETA);
figura_t **figura_base=cargar_tipo(memoria,BASE);
figura_t **figura_combustible=cargar_tipo(memoria,COMBUSTIBLE);
figura_t **figura_torreta=cargar_tipo(memoria,TORRETA);
figura_t **figura_reactor=cargar_tipo(memoria,REACTOR);

....................................................

SINTETICA: forma corta pero poco clara de "que es cada indice":

define MAX_TIPOS 8

figura_t **memoria=crear_figuras(f);
figura_t ***lista_figuras=malloc(sizeof(lista_figuras **)*8);
for(size_t i=0;i<MAX_TIPOS;i++){
lista_figuras[i]=cargar_tipo(i);
}

--------------------------------------------------------------------
DINAMICA DE CARGA DEL JUEGO:

//Borrador
iniciar juego
    cargar todo a memoria;
    cargar tipo niveles (copia);
    cargar tipo planeta (copia);

dibujar_inicio
    dibujar base;
    dibujar estrella;
    dibujar planeta;

iteraciones:
    tecla
    nave: direccion,aceleracion, velocidad, posicion, combustible,
    colision contra:
        paredes: cambia direccion velociddad colision
        sol: pierde una vida, vuelve a base
        planeta: carga planeta contra el que choco

planeta:
    carga elementos
    dibuja
    acomoda camara
    empieza iteraciones

    iteraciones planeta:
    tecla
    nave: aceleracion, velocidad, posicion, direccion, combustible,
    torreta: cantidad y cuales siguen.
    tanque: cantidad y cuales siguen.
    reactor: si sigue estando.
    colisiones:
        Escudo:
            tanque: recarga combustible
        Nave:
            borde pantalla:
                tipo no infinito:
                    cualquier borde:
                        funcion_cambiar nivel: chequear si terminó el nivel e ir a pantalla principal
                tipo infinito:
                    borde superior:
                        acomodar pantalla (hasta cota maxima);
                        cota maxima: funcion cambiar nivel
                    borde lateral:
                        acomodar pantalla
            polilinea planeta:
                pierde una vida y regresa a la posicion inicial si tiene vidas todavia;
                la funcion perder vida debe chequear que tenga vidas todavia
             disparo:
                pierde una vida y regresa a la posicion inicial si tiene vidas todavia;
                la funcion perder vida debe chequear que tenga vidas todavia
        Torreta: disparo;
        Reactor: disparo;
--------------------------------------------------------------------
BORRAR:

ej 4
figuras.txt
funciones.c y .h
generico abru (este dejemoslo de borrador).
polilinea tengo que hacerle una comparacion con la que tengo aca y a funciones tambien
----------------------------------------------------------------------
Cargo nivel.c y nivel.h: les falta hacer correcciones, en general, pero para hacer los otros TDA sirve.
--------------------------------------------------------------------------
FIN DE CARGA DEL DIA




------------------------------
28/7 (o antes)

movimiento de nave:
getchar+tabla de busqueda sobre wasd o sistema similar
otras teclas pueden habilitar el escudo y el propulsr (y sus funciones respectivas).

TDA nave

deftype struct{
	poligono_t ...;
	float direccion[2];
	float posicion[2];
	float velocidad[2];
	float aceleracion[2];
	bool propulsor;
	char vidas;//se comienza con 3 vidas, usar cualquier tipo de dato bajo. Es poco probable superar 50... hay topee de vidas?
	int combustible;//se comienza con 10000 y se gasta demasiado.
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
	float velocidad;
	float posicion; //posicion adecuado para itnereseccion
	float tiempo_disponible;
	bool vive;
	
TDA planeta
	poligono_t ...;
	tipo...  ciclico o redondo

TDA pantalla (o lista o enum):
	inicial o planeta o pelea nave,
	
	
	
funciones:

ES MUY POSIBLE QUE HAYA QUE HACER UNA FUNCION INTERSECCION ENTRE POLILINEAS

contador de vida:

si puntos > 10000 --- + 1 vida
si la nave toca superficie ---- - 1 vida & resetea posicion (depende nivel) ¿tiene que tocar el poligono de la nave el poligono de la superficie? polignave==poligplaneta
si la nave toca proyectil ---- - 1 vida & resetea posicion (depende nivel) ¿tiene que tocar el poligono de la nave el poligono del disparo?
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





