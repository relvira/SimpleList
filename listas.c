a/* ========================================== */
/* = AUTOR: RAFAEL DE ELVIRA				= */
/* = PRACTICA: MANEJO DE LISTAS DINAMICAS	= */
/* ========================================== */
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int dato;
	struct nodo *sig;
};
struct nodo *lista;


/* ============================ */
/* = PROTOTIPADO DE FUNCIONES = */
/* ============================ */

int MENU();
void INICIALIZAR (struct nodo **);
int ESVACIA (struct nodo *);
void INSERTAR_PILA(struct nodo **, int);
void RELLENAR_PILA_BUCLE(struct nodo **, int);
void listar(struct nodo *);
int EXTRAER(struct nodo **);
void INSERTAR_COLA(struct nodo **, int);
struct nodo * BUSCAR(struct nodo *, int);
int EXTRAER_NODO(struct nodo **, int);

// AUN POR TERMINAR
struct nodo * BUSCAR_ORDEN(struct nodo *, int);
void INSERTAR_ORDEN(struct nodo **, int);


void main()
{
	int op=0; int l=0; int i=0; int v=0; int cola;
	int fin=1; int tope=0; int pila=0; int extraido;
	int buscanodo=0; struct nodo *existe; int extraenodo;
	int insorden;

	system("cls");

	/* ========================== */
	/* = INICIALIZAMOS LA LISTA = */
	/* ========================== */

	INICIALIZAR(&lista);

	while(fin!=0)
	{
		op = MENU();
		switch(op)
		{
			case 1:
				/* ================================== */
				/* = RELLENAMOS COMO PILA  EN BUCLE = */
				/* ================================== */
				printf("Insertar tope: ");
				scanf("%d", &tope);
				RELLENAR_PILA_BUCLE(&lista, tope);
				break;

			case 2:
				/* ======================== */
				/* = RELLENAMOS COMO PILA = */
				/* ======================== */

				printf("Insertar valor: ");
				scanf("%d", &pila);
				INSERTAR_PILA(&lista, pila);
				break;

			case 3:
				/* ========================================= */
				/* = COMPROBAR SI LA ESTRUCTURA ESTA VACIA = */
				/* ========================================= */
				if (ESVACIA (lista))
				{
					printf("\nLA LISTA ESTA VACIA \n");
				}
				else
				{
					printf("\nLA LISTA ESTA LLENA \n");
				}
				system("pause");
				break;

			case 4:
				/* ========================== */
				/* = LISTAMOS LA ESTRUCTURA = */
				/* ========================== */

				listar(lista);
				system("pause");
				break;

			case 5:
				/* ===================================== */
				/* = EXTRAE EL PRIMER NODO DE LA LISTA = */
				/* ===================================== */
				if(ESVACIA(lista))
				{
					printf("\n Lo siento, la lista esta vacia ");
				}
				else
				{
					extraido = EXTRAER(&lista);
					printf("Se ha extraido el nodo: %d", extraido);
				}
				system("pause");
				break;

			case 6:
				/* ======================== */
				/* = RELLENAMOS COMO COLA = */
				/* ======================== */

				printf("Insertar valor: ");
				scanf("%d", &cola);
				INSERTAR_COLA(&lista, cola);
				break;
			
			case 7:
				/* ===================================================== */
				/* = BUSCAMOS UN NODO CUANDO LA LISTA NO ESTA EN ORDEN = */
				/* ===================================================== */
				printf("Introduce nodo a buscar: ");
				scanf("%d", &buscanodo);
				existe = BUSCAR(lista,buscanodo);
				if(existe)
				{
					printf("Encontrado ! vale: %d \n", (*existe).dato);
				}
				else
				{
					printf("No existe!! \n");
				}
				system("pause");
				break;

			case 8:
				/* ======================================== */
				/* = EXTRAER NODO INTRODUCIDO POR TECLADO = */
				/* ======================================== */
				printf("Introduce nodo a extraer: ");
				scanf("%d", &extraenodo);
				if(EXTRAER_NODO(&lista,extraenodo)==0)
				{
					printf("Nodo no encontrado!!! \n");
				}
				else
				{
					printf("Nodo %d ELIMINADO \n", extraenodo);
				}
				system("pause");
				break;
			case 9:
				/* ======================= */
				/* = INSERTAMOS EN ORDEN = */
				/* ======================= */

				printf("Insertar valor: ");
				scanf("%d", &insorden);
				INSERTAR_ORDEN(&lista, insorden);
				system("pause");
				break;

			case 10:
				/* ================================================== */
				/* = BUSCAMOS UN NODO CUANDO LA LISTA ESTA ORDENADA = */
				/* ================================================== */
				printf("Introduce nodo a buscar: ");
				scanf("%d", &buscanodo);
				existe = BUSCAR_ORDEN(lista,buscanodo);
				if(existe)
				{
					printf("Encontrado ! vale: %d \n", (*existe).dato);
				}
				if(existe==0)
				{
					printf("Nodo no encontrado!!!! :( \n");
				}
				system("pause");
				break;
			case 11:
				fin = 0;
				break;

			default:
				fin = 0;
				break;
		}
	}
	system("pause");
}


/* =========================== */
/* = DESARROLLO DE FUNCIONES = */
/* =========================== */

int MENU()
{
	/* ==================== */
	/* = PUT COMMENT HERE = */
	/* ==================== */
	int op=0; 
	system("cls");
	printf("1. Rellenar Lista dinamica como PILA en bucle\n");
	printf("2. insertar Lista como PILA\n");
	printf("3. Comprobar si la lista esta vacia\n");
	printf("4. Listar Lista\n");
	printf("5. Extraer PRIMER nodo\n");
	printf("6. Insertar en lista como COLA\n");
	printf("7. Buscar nodo\n");
	printf("8. Extraer nodo\n");
	printf("9. Insertar en orden\n");
	printf("10. Buscar en orden\n");
	printf("11. Salir\n\n");
	printf("Introduce opcion: ");
	scanf("%d", &op);
	return(op);
}

void INICIALIZAR (struct nodo **p)
{
	*p=NULL;
}

int ESVACIA (struct nodo *p)
{
	return (p==NULL);
}

void INSERTAR_PILA(struct nodo **p, int N)
{
	struct nodo *aux;
	aux = (struct nodo *) malloc(sizeof(struct nodo));
	(*aux).dato=N;
	(*aux).sig= *p;
	*p = aux;
}

void RELLENAR_PILA_BUCLE(struct nodo **p, int N)
{
	int k=0;
	while(k<N)
	{
		struct nodo *aux;
		aux = (struct nodo *) malloc(sizeof(struct nodo));
		(*aux).dato=k;
		(*aux).sig= *p;
		*p = aux;
		k++;
	}
}

void listar(struct nodo *p)
{
	while(p!=NULL)
	{
		printf("\nValor de este nodo: %d \n", (*p).dato);
		p=(*p).sig;
	}
}

int EXTRAER(struct nodo **p)
{
	struct nodo *aux; int numero;
	aux = *p; 
	*p = (*aux).sig;
	numero = (*aux).dato;
	free(aux);
	return(numero);
}

void INSERTAR_COLA(struct nodo **p, int N)
{
	struct nodo *aux, *aux2;
	aux = (struct nodo *) malloc(sizeof(struct nodo));
	(*aux).dato = N; 
	(*aux).sig = NULL;

		if(*p==NULL)
		{
			*p = aux;
		}
		else
		{
			aux2 = *p;
			while((*aux2).sig!=NULL)
			{
				aux2 = (*aux2).sig;
			}
			(*aux2).sig = aux;
		}
}

struct nodo *BUSCAR(struct nodo *p, int N)
{
	while((p!=NULL) && (*p).dato!=N)
	{
		p = (*p).sig;
	}
	return(p);
}

int EXTRAER_NODO(struct nodo **p, int N)
{
	struct nodo *aux1, *aux2;
	if(ESVACIA(*p))
	{
		return(0);
	}
	else
	{
		if(((*(*p)).sig==NULL)||((*(*p)).dato==N))
		{
			if((*(*p)).dato==N)
			{
				EXTRAER(p);
				return(1);
			}
			else
			{
				return(0);
			}
		}
		else
		{
			aux2 = *p; 
			aux1 = (*(*p)).sig;
			while((aux1!=NULL)&&((*aux1).dato!=N))
			{
				aux2=aux1; aux1=(*aux1).sig;
			}
			if(aux1==NULL)
			{
				return(0);
			}
			else
			{
				(*aux2).sig=(*aux1).sig;
				free(aux1);
				return(1);
			}
		}
	}
}



void INSERTAR_ORDEN(struct nodo **p, int N)
{
	struct nodo *aux, *aux1, *aux2;
	aux = (struct nodo *)malloc(sizeof(struct nodo));
	(*aux).dato=N;
	printf("Valor introducido: %d \n", (*aux).dato);
	if(ESVACIA(*p))
	{
		INSERTAR_PILA(p,N);
		//INSERTAR_COLA(p,N);
	}
	else
	{
		if(((*(*p)).sig)==NULL)
		{
			INSERTAR_COLA(p,N);
		}
		else
		{
			aux2 = *p;
			aux1 = (*aux2).sig; // AUX2 ES *P ASI QUE NOS AHORRAMOS METER (*(*p)).
			while(((*aux1).sig!=NULL)&&((*aux1).dato<N))
			{
				aux2 = aux1;
				aux1 = (*aux1).sig;
			}
			if(aux1==NULL)
			{
				INSERTAR_COLA(p,N);
			}
			else
			{
				(*aux).sig=aux1;
				(*aux2).sig=aux;
			}
		}
	}
}


struct nodo *BUSCAR_ORDEN(struct nodo *p, int N)
{
	while((p!=NULL) && (*p).dato<N)
	{
		p = (*p).sig;
	}
	if((*p).dato==N)
	{
		return(p);
	}
	else
	{
		return(0);
	}
}

