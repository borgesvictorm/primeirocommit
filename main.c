#include <stdio.h>
#define CAP 10

struct Lista{
  int tamanho;
  int elementos[CAP];
};
typedef struct Lista Lista;

int inserir(int valor, int index, Lista* lista){
  if(lista->tamanho == CAP)
    return 1; // indicar erro de capacidade
  if(index < 0 || index > lista->tamanho)
    return 2; // indicar erro de índice
  // apontador i ajuda no processo de empurrar os valores para o fundo da lista
  int i = lista->tamanho;
  // empurra os valores para o fundo da lista
  while(i != index){
    lista->elementos[i] = lista->elementos[i-1];
    i--;
  }
  lista->elementos[i] = valor;
  lista->tamanho++;
  return 0; //indicar o sucesso da inserção
}

int busca(int valor, Lista* lista){
  int i;
  // percorrer todas os valores da lista
  for(i=0 ; i<lista->tamanho ; i++){
    if(valor == lista->elementos[i]){
      return i; // retorna a posição na qual a informação está contida
    }
  }
  return -1; // simboliza que não existe informação
}


void printLista(Lista* lista){
  printf("\n----------------------------------\n");
  int i = 0;
  while(i < CAP){ // percorre todas as posições do arranjo
    if(i < lista->tamanho)
      printf("%d-",lista->elementos[i]);
    else
      printf("@-");
    i++;
  }
  printf("\n----------------------------------\n\n\n");
}

void initLista(Lista* lista){
  lista->tamanho = 0;
  int i = 0;
  while(i < CAP){ // percorre todas as posições do
    lista->elementos[i] = 0;
    i++;
  }
}

int main(void) {
  Lista* lista01 = (Lista*) malloc(sizeof(Lista));
  initLista(lista01);
  printLista(lista01);
  
  inserir(15, 0, lista01);
  inserir(10, 0, lista01);
  inserir(9, 0, lista01);
  inserir(7, 0, lista01);
  inserir(3, 0, lista01);
  inserir(5, 0, lista01);
  printLista(lista01);

  int posicao = busca(23, lista01);
  if(posicao == -1)
    printf("O valor nao esta na lista!");
  else
    printf("O valor 23 esta na pos %d\n",posicao);

  return 0;
}

