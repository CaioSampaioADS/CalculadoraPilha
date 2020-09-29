#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*---------------------- Pilha*/
typedef struct dataNodePilha{
	int id;
	
	
} DataNodePilha;


typedef struct nodePilha{
	DataNodePilha data;
	struct nodePilha *next;	
	
	
} NodePilha;

typedef struct pilha{
	int size;
	NodePilha *head;
	
	
} Pilha;


Pilha *criaPilha(){
	
	Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
	
	
	pilha->size = 0;
	pilha->head = NULL;
	
	Pilha *pilhas = pilha;
	
	return  pilhas;
	
}

bool vazioPilha(Pilha *pilha){
	return (pilha->size == 0);
	
}



void popPilha(Pilha *pilha){
	
	if(!vazioPilha(pilha)){
	
	NodePilha *pointer = pilha->head;
	pilha->head = pointer->next;
	free(pointer);
	pilha->size--;
	
	}else{
		printf("Sua pilha já está vazia | nada foi removido\n");
	}
	
}

void inserePilha(Pilha *pilha, DataNodePilha data){
	
	NodePilha *nodePilha = (NodePilha*) malloc(sizeof(NodePilha));
	
	nodePilha->data = data;
	nodePilha->next = pilha->head;
	pilha->head = nodePilha;
	pilha->size++;
	
	
}


void subistituiElementos(Pilha *pilha1, Pilha *pilha2){
	/*Não está funcionando, não consegui encontrar o erro*/	
	NodePilha *pointer = pilha1->head;
	
	if(pointer == NULL){
		
		printf("Pilha vazia\n");
	}
	while(pointer != NULL){
		DataNodePilha data;
		data.id = pointer->data.id;
		inserePilha(pilha2, data);
		pilha1->head = pointer->next;
		free(pilha1);
		pointer = pointer->next;		
	}
}

void copiaElementos(Pilha *pilha1, Pilha *pilha2){
	
	NodePilha *pointer = pilha1->head;
	
	if(pointer == NULL){
		
		printf("Pilha vazia\n");
	}
	while(pointer != NULL){
		DataNodePilha data;
		data.id = pointer->data.id;
		inserePilha(pilha2, data);
		pointer = pointer->next;		
	}
	
}


NodePilha *atPosPilha(Pilha *pilha, int index){
	
	if(index >= 0 && index <= pilha->size){
		NodePilha *node = pilha->head;
		
		int i;
		for(i =0; i < index; i++){
			node = node->next;	
		}
		
		return node;
		
		
	}else{
		
		return NULL;
	}

}
void operacaoSub(Pilha *pilha){
		
		while(1){
			NodePilha *pointer = pilha->head;
			if (pointer->next == NULL){
				break;
			}else{
				int v1, v2, soma;
				v1 = pointer->data.id;
				v2 = pointer->next->data.id;
				soma = v1 - v2;
				
				popPilha(pilha);
				popPilha(pilha);
				
				DataNodePilha data;
				data.id = soma;
				inserePilha(pilha, data);
					
			}			
		}		
}

void operacaoMult(Pilha *pilha){
		
		while(1){
			NodePilha *pointer = pilha->head;
			if (pointer->next == NULL){
				break;
			}else{
				int v1, v2, soma;
				v1 = pointer->data.id;
				v2 = pointer->next->data.id;
				int   mult = v1 * v2;
								
				popPilha(pilha);
				popPilha(pilha);
				
				DataNodePilha data;
				data.id = soma;
				inserePilha(pilha, data);
					
			}			
		}		
}

void operacaoSoma(Pilha *pilha){
		
		while(1){
			NodePilha *pointer = pilha->head;
			if (pointer->next == NULL){
				break;
			}else{
				int v1, v2, soma;
				v1 = pointer->data.id;
				v2 = pointer->next->data.id;
				soma = v1 + v2;
				
				popPilha(pilha);
				popPilha(pilha);
				
				DataNodePilha data;
				data.id = soma;
				inserePilha(pilha, data);
					
			}			
		}		
}

void ordenaPilha(Pilha *pilha){
	NodePilha *pointer;
	int tamanho = pilha->size;
	
	if(pointer == NULL){
		printf("pilha vazia\n");
	}else{
		int i;
		for(i = 0; i<tamanho-1; i++){
			pointer = pilha->head;
			int j;
			for(j= 0; j< tamanho-1-i; j++){

				if(pointer->data.id > pointer->next->data.id){
					
					int aux = pointer->data.id;
					pointer->data.id = pointer->next->data.id;
					pointer->next->data.id = aux;
					
									
				}
					pointer = pointer->next;
			
				
				
			}
			
		}
		
	}
	

	
	
}

void esvaziaPilha(Pilha *pilha){
	
	if(vazioPilha(pilha)){
		printf("Sua pilha já está vazia");
	}
	while(!vazioPilha(pilha)){
		NodePilha *pointer = pilha->head;
		pilha->head = pointer->next;
		free(pointer);
		pilha->size--;
		
	}
	
}

void printPilha(Pilha *pilha){
	NodePilha *pointer = pilha->head;
	
	if(pointer == NULL){
		
		printf("Pilha vazia\n");
	}
	
	while(pointer != NULL){
		printf("%d\n", pointer->data.id);
		pointer = pointer->next;		
	}
	
	
}


/*---------------- lista*/

typedef struct dataNode{
	Pilha *id;
	
	
} DataNode;


typedef struct node{
	DataNode data;
	struct node* next;	
	
	
} Node;

typedef struct list{
	int size;
	Node* head;
	
	
} List;

List* criaLista(){
	
	List* list = (List*) malloc(sizeof(List));
	
	
	list->size = 0;
	list->head = NULL;
	
	return list;
	
	
}

void insere(List* list, DataNode data){
	Node* node = (Node*) malloc(sizeof(Node));
	
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
	
	
}


void printList(List* list){
	Node *pointer = list->head;
	
	if(pointer == NULL){
		
		printf("Lista vazia\n");
	}
	int indice = 0;
	while(pointer != NULL){
		printf("Indice: %d  local: %d\n",indice, pointer->data.id);
		indice++;
		pointer = pointer->next;		
	}
	
	
}

bool vazio(List *list){
	return (list->size == 0);
	
}

void pop(List* list){
	
	if(!vazio(list)){
	
	
	Node *pointer = list->head;
	list->head = pointer->next;
	free(pointer);
	list->size--;
	
	}
	
}


Node* atPos(List* list, int index){
	
	if(index >= 0 && index <= list->size){
		Node *node = list->head;
		
		int i;
		for(i =0; i < index; i++){
			node = node->next;	
		}
		
		return node;
		
		
	}else{
		
		return NULL;
	}

}

void apagar(List *list, int index){
	if(index == 0){
		pop(list);
		
	}else{
		
		Node *excluir = atPos(list, index);
		if(excluir != NULL){
			 
			Node *anterior = atPos(list, index-1);
			anterior->next = excluir->next;
			
			free(excluir);
			list->size--;
		
		}else{
			printf("A pilha que esta tentando remover nao existe\n");	
		
		}
	}

}




/*---------------------------*/






int main(){
	
	int decisao;
	List *lista = criaLista();
	

	


	while(1){

		printf("====================MENU====================\n");
		printf("[1] Digite 1 para criar uma pilha\n[2] Digite 2 para visualizar suas pilhas\n[3] Difite 3 para excluir uma pila\n[4] Digite 4 para visualizar uma pilha\n[5] Digite 5 para adicionar valores em uma pilha\n[6] Digite 6 para ordenar uma pilha\n[7] Digite 7 para remover um item de uma pilha\n[8] Digite 8 para aplicar uma soma\n[9] Digite 9 para aplicar uma subtracao\n[10] Digite 10 para aplicar uma multiplicacao\n[11] Digite 11 para esvaziar uma pilha\n[12] Digite 12 para copiar elementos de uma pilha para outra\n[13] Digite 13 para subistituir os elementos de uma pilha para outra\n");
		scanf("%d", &decisao);
		
		if(decisao == 1){
			system("cls");
			
			printf("Sua pila foi criada com sucesso\n");
			Pilha *pilha;
			pilha = criaPilha();
			
			DataNode data;
			data.id = pilha;
			insere(lista, data);
			
			printf("\n");
			printList(lista);
			printf("\n");
					
		}else if(decisao == 2){
			system("cls");
			printf("Essas sao suas pilhas:\n\n");
			printList(lista);
		}else if(decisao == 3){
			system("cls");
			int indiceRemover;
			printf("\n");
			printList(lista);
			printf("\n");
			printf("Digite o indice da lista que deseja remover\n\n");
			scanf("%i", &indiceRemover);
			apagar(lista, indiceRemover);
			printf("Pilha removida com sucesso\n\n");
		}else if(decisao == 4){
			system("cls");
			printf("Escolha qual pilha deseja visualizar| digite o indice\n\n");
			printList(lista);
			int indiceMostrar;
			Node *n;
			scanf("%i", &indiceMostrar);
			n = atPos(lista, indiceMostrar);
			
			if (n != NULL){	
			printf("Os valores contidos dentro da sua pilha sao:\n\n");
			printPilha(n->data.id);
			}else{
				printf("A pilha que deseja ver não existe\n");
			}
				
		}else if(decisao == 5){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que contem a pilha que deseja inserir dados\n\n");
			int indiceInserir;
			scanf("%i", &indiceInserir);
			Node *n;
			n = atPos(lista, indiceInserir);
			float valorInserir;
			
			while(1){
				printf("Digite o valor que deseja inserir ou -1 para sair");
				scanf("%f", &valorInserir);
				if(valorInserir == -1){
					break;
				}
				
					DataNodePilha data;
					data.id = valorInserir;
					inserePilha(n->data.id, data);
							
			}
			
		}else if(decisao == 6){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que contem a pilha que deseja ordenar\n\n");
			int indiceOrdenar;
			scanf("%i", &indiceOrdenar);
			Node *n;
			n = atPos(lista, indiceOrdenar);
			ordenaPilha(n->data.id);
			
			printf("Pilha ordenada\n");
		}else if(decisao == 7){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que contem a pilha que deseja remover um item\n\n");
			int indiceRemoverTopo;
			scanf("%i", &indiceRemoverTopo);
			Node *n;
			n = atPos(lista, indiceRemoverTopo);
			popPilha(n->data.id);
			
			printf("Topo removido com sucesso\n");
			
			
		}else if(decisao == 8){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja aplicar a soma");
			int indiceRemoverTopo;
			scanf("%i", &indiceRemoverTopo);
			Node *n;
			n = atPos(lista, indiceRemoverTopo);
			
			operacaoSoma(n->data.id);
			
			printf("\nOperacao soma aplicada com sucesso\n");
			
		}else if(decisao == 9){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja aplicar a subtracao");
			int indiceRemoverTopo;
			scanf("%i", &indiceRemoverTopo);
			Node *n;
			n = atPos(lista, indiceRemoverTopo);
			
			operacaoSub(n->data.id);
			
			printf("\nOperacao de subtracao aplicada com sucesso\n");
			
		}else if(decisao == 10){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja aplicar a multiplicacao");
			int indiceRemoverTopo;
			scanf("%i", &indiceRemoverTopo);
			Node *n;
			n = atPos(lista, indiceRemoverTopo);
			
			operacaoMult(n->data.id);
			
			printf("\nOperacao de multiplicacao aplicada com sucesso\n");			
		}else if(decisao == 11){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja esvaziar a pilha contida nela\n");
			int indiceRemoverTopo;
			scanf("%i", &indiceRemoverTopo);
			Node *n;
			n = atPos(lista, indiceRemoverTopo);
			
			esvaziaPilha(n->data.id);
			
			printf("\nPilha esvaziada com sucesso\n");
			
		}else if(decisao == 12){
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja copiar os elementos da pilha contidos nela\n");
			int indicePilhaCopiar;
			scanf("%i", &indicePilhaCopiar);
			Node *n;
			n = atPos(lista, indicePilhaCopiar);
			
			printf("Digite o indice da lista que deseja colar os elementos copiados para pilha dentro dela\n");
			int indicePilhaColar;
			scanf("%i", &indicePilhaColar);
			Node *n1;
			n1 = atPos(lista, indicePilhaColar);
			
			copiaElementos(n->data.id, n1->data.id);
			
			printf("\nColagem executada com sucesso\n");
			
		}else if(decisao == 13){
			/*a substituição não está funcionando, não consegui encontrar o erro*/	
			
			system("cls");
			printf("\n");
			printList(lista);
			printf("\n");
			
			printf("Digite o indice da lista que deseja substituir os elementos da pilha contidos nela\n");
			int indicePilhaCopiar;
			scanf("%i", &indicePilhaCopiar);
			Node *n;
			n = atPos(lista, indicePilhaCopiar);
			
			printf("Digite o indice da lista que deseja colar os elementos copiados para pilha dentro dela\n");
			int indicePilhaColar;
			scanf("%i", &indicePilhaColar);
			Node *n1;
			n1 = atPos(lista, indicePilhaColar);
		
			subistituiElementos(n->data.id, n1->data.id);
			printf("\Substituicao executada com sucesso\n");
			
			
			
			
		}
	
	}
	
	return 0;
	
}
