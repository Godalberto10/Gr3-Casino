#ifndef WORDLE_HPP
#define WORDLE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>//Librerias
#include <vector>
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;
const int T_DIC = 1390;
enum Letra { CORRECTA, POSICION_INCORRECTA, INCORRECTA };//Dicionario de palabras de 5 letras
const string diccionario[T_DIC] = { "abaco", "abajo", "abiel", "abono", "abren",
	"abril", "abrir", "abuso", "acaba", "acabe", "acabo", "acaso", "acera", "acero",
	"acoso", "acota", "actas", "actor", "actos", "acuda", "acude", "acusa", "adela",
	"adese", "adora", "adoro", "afear", "afeen", "agora", "agote", "agrio", "aguas",
	"aguda", "agudo", "aguja", "ahora", "aires", "ajena", "ajeno", "alamo", "album",
	"albur", "aldea", "alega", "aleja", "alejo", "alfio", "algas", "aliar", "alija",
	"almas", "altas", "altos", "alzas", "amaba", "amado", "amaro", "amaru", "ambas",
	"ambos", "ameno", "amiga", "amigo", "ancha", "ancho", "andan", "andar", "andes",
	"angel", "anglo", "anima", "anote", "antes", "anual", "apaga", "apego", "apelo",
	"apoda", "apodo", "apoya", "apoye", "apoyo", "aptas", "aptos", "aquel", "arado",
	"arana", "arduo", "areas", "arena", "arias", "ariel", "armar", "armas", "arroz",
	"artes", "asada", "asomo", "aspes", "astro", "asuma", "asume", "ataca", "atlas",
	"atrae", "audaz", "audio", "aulas", "aurio", "autor", "autos", "avala", "avale",
	"avaro", "avila", "aviso", "ayala", "ayuda", "ayude", "azuma", "baila", "baile",
	"bajan", "bajar", "bajas", "bajos", "balas", "balsa", "bamba", "banca", "banco",
	"banda", "bando", "barba", "barco", "barda", "bares", "barra", "barre", "barro",
	"basar", "basen", "bases", "basta", "baste", "batas", "bateo", "batir", "batis",
	"bazar", "beach", "beber", "becas", "beige", "belga", "bella", "bello", "beria",
	"besar", "bocas", "bocho", "bodas", "bogue", "bolas", "boleo", "bolsa", "bolso",
	"bomba", "bonos", "borax", "borde", "bordo", "borge", "boris", "borja", "borla",
	"bosch", "botas", "boxeo", "boyas", "bravo", "brazo", "breve", "broad", "brock",
	"broma", "brown", "bruja", "bruto", "buena", "bueno", "buque", "burel", "burla",
	"burro", "busca", "busco", "busto", "cabal", "cable", "cabos", "cacao", "cairo",
	"cajal", "cajas", "calla", "calle", "calma", "calor", "camas", "campo", "canal",
	"canje", "canta", "canto", "caoba", "caona", "capas", "capaz", "capos", "caras",
	"caray", "careo", "carga", "cargo", "carha", "carla", "carne", "caros", "carpa",
	"carro", "carso", "carta", "casas", "casio", "casos", "casta", "cauce", "causa",
	"cause", "cazar", "ceder", "celda", "celos", "celta", "cemex", "cenar", "cenas",
	"censo", "cepal", "cerca", "cerda", "cerdo", "cerro", "cesan", "cesar", "cesto",
	"cetes", "cetro", "chapa", "chapo", "chara", "chase", "chato", "chavo", "checa",
	"checo", "chelo", "chepo", "chiba", "chica", "chico", "chila", "chile", "chima",
	"china", "chino", "chiva", "chivo", "chupa", "cibao", "ciclo", "cielo", "cifra",
	"cinco", "cines", "cinta", "cinto", "circo", "citan", "citar", "citas", "citen",
	"civic", "civil", "clara", "claro", "clase", "clave", "clero", "clima", "cobos",
	"cobra", "cobre", "cobro", "coche", "coece", "cofre", "coger", "cohen", "colas",
	"colin", "colmo", "color", "comas", "comer", "comun", "conde", "congo", "conos",
	"conti", "copas", "copia", "corea", "coros", "corra", "corre", "corro", "corta",
	"corte", "corto", "cosas", "coser", "costa", "costo", "cover", "crean", "crear",
	"crece", "creen", "creer", "cruce", "cruda", "crudo", "cruel", "cruza", "cubas",
	"cubra", "cubre", "cuero", "cueva", "cuida", "cuide", "culpa", "culta", "culto",
	"cunda", "cuota", "curar", "curia", "curro", "curso", "curva", "cuyas", "cuyos",
	"daban", "dadas", "dados", "dalia", "damas", "damos", "dante", "danza", "datos",
	"deban", "deben", "deber", "debes", "debut", "decir", "dedos", "dejan", "dejar",
	"dejen", "dense", "derma", "desde", "desea", "desee", "deseo", "deuda", "dicen",
	"dices", "dicha", "dicho", "dicom", "dicta", "diera", "dieta", "digan", "digna",
	"digno", "dijes", "dillo", "dimos", "diosa", "disco", "dobla", "doble", "docta",
	"dolor", "doman", "domar", "donan", "donar", "donas", "donde", "dones", "dorar",
	"dosis", "dotar", "dotes", "drama", "droga", "dudas", "duela", "duele", "duelo",
	"dulce", "dupla", "duque", "duran", "durar", "duras", "duren", "duros", "ebrio",
	"echan", "echao", "echar", "echas", "echen", "edita", "ejido", "elida", "elier",
	"elija", "ellas", "ellos", "elude", "emana", "emita", "enero", "enojo", "entes",
	"entra", "entre", "envia", "envio", "error", "estar", "estas", "estos", "estoy",
	"etapa", "etnia", "evita", "evite", "exige", "exija", "exime", "facha", "faena",
	"falda", "falla", "fallo", "falsa", "falso", "falta", "falte", "falto", "fango",
	"farsa", "fases", "fatal", "fauna", "favor", "fecha", "feliz", "femam", "feria",
	"feroz", "fetos", "fibra", "ficha", "fidel", "fijan", "fijar", "fijas", "fijos",
	"filas", "final", "finas", "finca", "fines", "finos", "firma", "firme", "fisco",
	"flaco", "flora", "flota", "flujo", "fluye", "focos", "folio", "fonda", "fondo",
	"forja", "forma", "forme", "foros", "forro", "fosas", "fotos", "frase", "freno",
	"frias", "fruta", "fruto", "fuego", "fuera", "fuere", "fuero", "fuese", "fuman",
	"funda", "funde", "furia", "gallo", "ganan", "ganar", "ganas", "ganen", "garma",
	"garza", "gasca", "gases", "gaste", "gasto", "gatos", "genes", "genio", "gente",
	"gerda", "gesto", "giran", "girar", "giras", "giros", "gises", "globo", "gocen",
	"goleo", "goles", "golfo", "golpe", "gorda", "gordo", "gorra", "gorro", "gotas",
	"goteo", "gozan", "gozar", "graba", "grado", "grana", "grano", "grato", "grave",
	"gripa", "gripe", "grita", "grito", "grupo", "guapa", "guapo", "guiar", "gusta",
	"guste", "gusto", "haber", "habla", "hable", "hablo", "habra", "hacen", "hacer",
	"haces", "hacha", "hacia", "hagan", "halen", "halla", "halle", "harto", "hasta",
	"hayan", "hayas", "hecha", "hecho", "hemos", "herir", "hielo", "hijas", "hijos",
	"hilos", "himno", "hinca", "hines", "hogar", "hojas", "hojeo", "honda", "hondo",
	"honor", "horas", "hotel", "hoyos", "huela", "huele", "hueso", "huevo", "hules",
	"humor", "hungo", "ideal", "ideas", "igual", "ilesa", "ileso", "infle", "islas",
	"jacte", "jalar", "jaque", "jarra", "jarro", "jaula", "jefes", "jerga", "joven",
	"joyas", "juega", "juego", "jugar", "junco", "junio", "junta", "junto", "justa",
	"justo", "kilos", "labor", "labra", "lados", "lagos", "lamen", "lanza", "lapso",
	"lares", "larga", "largo", "latas", "lavan", "lavar", "lazos", "leche", "lecho",
	"legal", "legar", "legue", "lejos", "lemas", "lenta", "lento", "lerma", "lerna",
	"letal", "letra", "leves", "leyes", "libre", "libro", "licor", "lidia", "liera",
	"ligar", "ligas", "ligue", "limar", "linda", "linea", "lista", "listo", "litro",
	"llama", "llame", "llamo", "llano", "llave", "llega", "llego", "llena", "lleno",
	"lleva", "lleve", "llevo", "llora", "llosa", "lobos", "local", "locos", "logra",
	"logre", "logro", "lomas", "lomos", "lotes", "lucen", "luces", "lucha", "lucho",
	"lucir", "lucro", "luego", "lugar", "lujos", "lunar", "macho", "madre", "mafia",
	"magia", "magma", "magna", "magno", "malas", "malla", "malos", "malta", "malva",
	"manda", "mando", "manga", "manos", "manso", "manto", "mapas", "marca", "marco",
	"mares", "marzo", "masas", "matar", "maten", "mayas", "mayor", "mayos", "media",
	"medio", "medir", "mejor", "mella", "mello", "menor", "menos", "menta", "mente",
	"merge", "mesas", "meses", "metal", "metan", "metas", "meten", "meter", "metro",
	"miedo", "miles", "milla", "mirar", "miras", "miren", "misas", "misma", "mismo",
	"mitad", "mitin", "mitos", "modas", "modos", "monas", "monta", "monte", "monto",
	"moral", "morir", "motor", "motos", "mover", "mozos", "mucha", "mucho", "mueca",
	"muera", "muere", "mueve", "mugre", "mujer", "multa", "mundo", "mural", "muros",
	"museo", "muslo", "mutua", "mutuo", "nacen", "nacer", "nacho", "nadar", "nadie",
	"nafta", "narco", "nariz", "narra", "nasal", "natal", "naval", "naves", "nazis",
	"necia", "nedda", "negar", "negra", "negro", "netas", "netos", "nexos", "nicho",
	"nidas", "nidos", "niega", "nieta", "nieto", "nieve", "nivel", "noble", "noche",
	"norma", "norte", "notar", "notas", "novia", "novio", "nubla", "nudos", "nuera",
	"nueva", "nueve", "nuevo", "nulas", "nunca", "obran", "obrar", "obras", "obvia",
	"obvio", "ocejo", "ochos", "ocupa", "oeste", "ojeda", "olivo", "ollas", "omiso",
	"omito", "ondas", "onzas", "opera", "opina", "opino", "opone", "optar", "orden",
	"oreja", "orina", "otras", "otros", "oxida", "ozono", "pacto", "padre", "pagan",
	"pagar", "pagos", "pague", "palas", "palco", "palma", "palos", "panel", "panes",
	"papal", "papel", "paran", "parar", "pared", "pares", "paros", "parra", "parte",
	"parto", "pasan", "pasar", "paseo", "pases", "pasos", "pasta", "pasto", "patas",
	"patio", "patos", "pausa", "pauta", "pavor", "peaje", "peces", "pecho", "pedir",
	"pegar", "pegue", "pelar", "pelea", "peleo", "pelos", "penal", "penas", "perla",
	"perro", "pesar", "pesas", "pesca", "pesos", "piano", "pican", "picos", "pidan",
	"pidas", "piden", "pieza", "pifia", "pilar", "pilas", "pinal", "pinos", "pinta",
	"pisen", "pisos", "pista", "pitas", "pitol", "pizza", "placa", "plaga", "plana",
	"plano", "plata", "plato", "playa", "plaza", "plazo", "plena", "pleno", "plomo",
	"pluma", "pobre", "pocas", "pocos", "poder", "poema", "poeta", "polar", "polen",
	"pollo", "polvo", "ponce", "ponen", "poner", "pones", "ponga", "pongo", "porte",
	"posee", "poses", "poste", "pozas", "pozos", "prado", "presa", "preso", "preta",
	"preve", "prima", "primo", "prisa", "prosa", "puche", "pudor", "pueda", "puede",
	"puedo", "pulir", "pulso", "pumas", "punta", "punto", "punzo", "puras", "purga",
	"puros", "queda", "quede", "queja", "queso", "quien", "quise", "quiso", "quita",
	"quite", "rabia", "racha", "radar", "radio", "ramas", "ramos", "rango", "rapar",
	"raros", "rasca", "ratos", "rauda", "rayas", "rayen", "rayos", "recta", "redes",
	"regia", "regio", "regla", "reina", "reino", "rejas", "reloj", "renta", "resta",
	"resto", "retos", "reyes", "ricas", "ricos", "riego", "rifar", "rifas", "rigen",
	"rigor", "risas", "risca", "ritmo", "rival", "roban", "robar", "roben", "roble",
	"robos", "robot", "rocas", "roces", "rodal", "rodea", "rodeo", "rojas", "rojos",
	"rollo", "rompe", "ronda",
	"roque", "rosas", "roses", "rubia", "rubio", "rubor", "rubro", "rudos", "rueda",
	"ruedo", "ruega", "ruego", "rugir", "ruido", "ruina", "rumbo", "rumor", "rural",
	"rusas", "rusos", "rutas", "saben", "saber", "sabes", "sabia", "sabio", "sabor",
	"sacar", "sacos", "sacra", "sacro", "saeta", "salas", "saldo", "salen", "salga",
	"salgo", "salir", "salsa", "salta", "salte", "salto", "salud", "salva", "salve",
	"salvo", "santa", "santo", "secas", "secos", "selva", "semen", "senos", "sepan",
	"seres", "seria", "serie", "serio", "sesgo", "sesos", "sexos", "sexta", "sexto",
	"siete", "sigan", "siglo", "signo", "sigue", "silla", "silos", "silva", "sirva",
	"sirve", "sitio", "sobra", "sobre", "socio", "sodas", "sodio", "solar", "solas",
	"solos", "somos", "sonda", "sorda", "soros", "suave", "suban", "suben", "subes",
	"subir", "sucia", "sucio", "sudar", "sueco", "suele", "suelo", "suena", "suero",
	"sufre", "suman", "sumar", "sumas", "sumen", "surge", "surja", "surta", "susto",
	"suyas", "suyos", "tabla", "tacho", "tacos", "tacto", "tales", "talla", "tanda",
	"tanta", "tanto", "tapar", "tapas", "tapia", "tapiz", "tarda", "tarde", "tardo",
	"tarea", "tasas", "tazas", "techo", "tecla", "tejas", "telas", "temas", "temen",
	"temor", "tener", "tenga", "tengo", "tenia", "tenis", "tenor", "tensa", "terna",
	"tesis", "texto", "tibio", "tiene", "tigre", "tinta", "tinto", "tipos", "tirar",
	"tiras", "tiros", "tirzo", "tocan", "tocar", "todas", "todos", "toman", "tomar",
	"tomas", "tomen", "tonto", "topes", "toque", "torno", "toros", "torre", "total",
	"traen", "traer", "traes", "traje", "trajo", "trama", "tramo", "trata", "trate",
	"trato", "trazo", "trece", "treta", "treto", "trigo", "tripa", "trono", "tropa",
	"trota", "trote", "tubos", "tumba", "tumor", "turbo", "turna", "turno", "tuzos",
	"ubica", "ultra", "unido", "urgen", "urnas", "usaba", "usada", "usado", "usara",
	"usted", "usura", "vacas", "vagos", "valde", "valdo", "valen", "valer", "valga",
	"valla", "valle", "valor", "vamos", "vapor", "vasco", "vasos", "vasto", "vayan",
	"veces", "vejez", "velas", "velos", "vemos", "vence", "venda", "vende", "vendo",
	"venga", "vengo", "venir", "venta", "veras", "verbo", "verde", "verla", "verlo",
	"verme", "versa", "verse", "verte", "viaja", "viaje", "vibra", "vicio", "vidas",
	"vieja", "viejo", "viene", "viera", "vigas", "vigil", "vigor", "villa", "vimos",
	"visos", "vista", "visto", "vital", "viuda", "viudo", "vivan", "vivas", "viven",
	"vivir", "vivos", "vocal", "voces", "voice", "volar", "votar", "voten", "votos",
	"vuele", "vuelo", "yendo", "yerno", "yunta", "zafra", "zagas", "zague", "zaire",
	"zalea", "zanja", "zonas", "zurda", "zurdo" 
};

class Wordle : public Juego {
private://Atributos
	double apuesta;
	bool jugarJ, acierto;
	string palabra, palabraobjetivo;
	string distribucion[5];
	Letra marcado[5];
public://metodos
	void jugar(Usuario u);
	string obtenerPalabraMarcada(Letra l[5], string palabra);
	string compruebaPalabra(string palabra, string wordle, bool& acierto);
	void mostrarDistribucion(string distrib[], int intentos);
	bool buscarPalabra(string palabra);
};
#endif