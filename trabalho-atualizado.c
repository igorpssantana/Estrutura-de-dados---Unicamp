#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// SEDEP - Sistema de Entrada e Descarga em Portos
// Software desenvolvido como trabalho da disciplina de Estrutura de Dados I
// Membros do grupo: Igor Paulo dos Santos Santana - 198643, Elias Matias Custódio - 247056, Matheus Siqueira Fernandes - 231147.

/* -----------------------------------------------------------------------------
CLASSES PADRÕES DAS ESTRUTURAS DE DADOS A SEREM ULTILIZADAS
------------------------------------------------------------------------------*/
typedef struct no_ld {
	int dado;
	struct no_ld *esq, *dir;
} Tno_ld;

struct no_ls {
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

typedef struct no_pilha {
	int dado;
	struct no_pilha *prox;
}  Tno_pilha;


/* -----------------------------------------------------------------------------
CLASSES DO PROJETO
------------------------------------------------------------------------------*/

typedef struct container{

 	int id;

 	char tipo[4];

} Container;

typedef struct no_c{

    Container *dado;

    struct no_c *prox;

}No_c;

typedef struct fila{

    struct no_c *inicio, *fim;

} Fila;

typedef struct matriz{
    Container *area[3][3];
} Matriz;

typedef struct patio{

	short int id;

  int topo;

	Matriz *camadas[3]; // Pilha de matrizes

} Patio;

typedef struct lista{

  short int dado;

	struct lista *prox;

} Lista;

typedef struct registro{

	short int Id;
	short int qtd;
  int tipo;
	Lista *ids;
  struct registro *prox;

} Registro;

/*----------------------------------------------------------
  DECLARAÇÕES
-----------------------------------------------------------*/
int Inicializa_patio(Patio **empresa);
int inicializa (Fila *f);
int imprimir_Siglas();
int Insere_Container(Fila *f, char *valor, Registro **log, int emp_id);
int imprimir_Fila(Fila *f);
int Inserir_fim_LS (Tno_ls **inicio, int info);
int Criar_Container(Container **novo, char *carga, int emp_id);
int imprimir_Fila(Fila *f);
int Transferencia(Fila *f, Patio **patio);
int Verifica_camada_cheia(Patio *p);
int ConfereLog(Registro *log);
int Fecha_lote(Registro **log, int qtd);
int Adiciona_id(Lista **lista, int id);
int Salva_log(Registro **log, int id, int tipo);
int Inicializar_Reg (Registro **inicio);
int imprime_topo(Patio *p);
int Despachar_container(Fila *f, int numId, Patio *p);
int remove_container(Fila *f, Patio **p,Registro **log);
int libera_fila(Fila *f);

/* -----------------------------------------------------------------------------
VARIÁVEIS GLOBAIS
------------------------------------------------------------------------------*/

int w = 100, x = 200, y = 300, z = 400;

int main()
{
  int q, erro, flag, i, emp, emp_s;
  char valor[4];

  Patio *empresa, *empresa2, *empresa3, *empresa4;

  Inicializa_patio(&empresa);
  Inicializa_patio(&empresa2);
  Inicializa_patio(&empresa3);
  Inicializa_patio(&empresa4);

  empresa->id = 1;
  empresa2->id = 2;
  empresa3->id = 3;
  empresa4->id = 4;

  Fila chegada;

  inicializa(&chegada);

  Fila saida;

  inicializa(&saida);

  Registro *historico;
  Inicializar_Reg(&historico);

	do {
    //system("clear");
    printf("SISTEMA DE ENTRADA E DESCARGA EM PORTOS - SEDEP");
		printf("\n\nOpcoes: \n\n");
		printf("1 -> Alocar container\n");
		printf("2 -> Alocar containers\n");
		printf("3 -> Transferencia para pátio\n");
		printf("4 -> Histórico de movimentações \n");
		printf("5 -> Alocar container para remoção\n");
		printf("6 -> Alocar vários containers para remoção\n");
    printf("7 -> Listar fila\n");
		printf("8 -> Remove container(s)\n");
		printf("9 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1:
        q=1;
        getchar();
        if(chegada.inicio == NULL){
            printf("\nDigite o id da empresa: ");
            scanf("%d", &emp);
        }

        getchar();
        printf("\nDigite a sigla da carga: ");
        imprimir_Siglas();
        fgets(valor,4,stdin);

        erro = Insere_Container(&chegada, valor, &historico, emp);
        Fecha_lote(&historico,q);
        if(erro == 0)
            printf("Alocação na fila bem sucedida !!!\n ");

        getchar();
        break;
        case 2:
        q=0;

        if(chegada.inicio == NULL){
          printf("\nDigite o id da empresa: ");
          scanf("%d", &emp);
        }

        do{
          flag = 0;
          getchar();
          printf("\nDigite a sigla da carga: ");
          imprimir_Siglas();
          fgets(valor,4,stdin);

          erro = Insere_Container(&chegada, valor, &historico, emp);

          getchar();

          if(erro == 0)
              printf("Alocação na fila bem sucedida !!!\n ");
          else
              printf("Erro de alocação !!!\n");

          strcpy(valor,"");
          q++;
          printf("Deseja inserir mais: 1-SIM 2-NÃO\n");
          scanf("%d", &flag);
        } while(flag != 2);
        Fecha_lote(&historico,q);
        getchar();
      break;
      case 3:

        if(emp == 1){
            erro= Transferencia(&chegada, &empresa);
           switch (erro){
          case 0:
            printf("Containers Tranferidos com sucesso\n");
            break;
          case 1:
            printf("Pilha Vazia\n");
            break;
          case 2:
            printf("Pátio inexistente\n");
            break;
          case 3:
            printf("Pátio cheio\n");
            break;
          case 4:
            printf("Pátio cheio e com containers não alocados\n");
            break;

          default:
            break;
        }
        getchar();
        break;
        }
        else if(emp == 2){
            erro= Transferencia(&chegada, &empresa2);
           switch (erro){
          case 0:
            printf("Containers Tranferidos com sucesso\n");
            break;
          case 1:
            printf("Pilha Vazia\n");
            break;
          case 2:
            printf("Pátio inexistente\n");
            break;
          case 3:
            printf("Pátio cheio\n");
            break;
          case 4:
            printf("Pátio cheio e com containers não alocados\n");
            break;

          default:
            break;
        }
        getchar();
        break;
        }
        else if(emp == 3){
            erro= Transferencia(&chegada, &empresa3);
           switch (erro){
          case 0:
            printf("Containers Tranferidos com sucesso\n");
            break;
          case 1:
            printf("Pilha Vazia\n");
            break;
          case 2:
            printf("Pátio inexistente\n");
            break;
          case 3:
            printf("Pátio cheio\n");
            break;
          case 4:
            printf("Pátio cheio e com containers não alocados\n");
            break;

          default:
            break;
        }
        getchar();
        break;
        }
        else if (emp == 4){
            erro= Transferencia(&chegada, &empresa4);
           switch (erro){
          case 0:
            printf("Containers Tranferidos com sucesso\n");
            break;
          case 1:
            printf("Pilha Vazia\n");
            break;
          case 2:
            printf("Pátio inexistente\n");
            break;
          case 3:
            printf("Pátio cheio\n");
            break;
          case 4:
            printf("Pátio cheio e com containers não alocados\n");
            break;

          default:
            break;
        }
        getchar();
        break;
        }

        case 4:
        erro= ConfereLog(historico);
        getchar();
        break;

        case 5:

        printf("\nDigite o id da empresa:");
        scanf("%d", &emp_s);

        switch(emp_s){

            case 1:

            q=1;

            imprime_topo(empresa);
            printf("\nDigite o ID do container a ser Removido: ");
            scanf("%d",&q);
            erro = Despachar_container(&saida,q,empresa);
            switch (erro)
            {
            case 0:
              printf("Container adicionado a lista\n");
              break;
            case 1:
              printf("Não é possível escolher o container informado\n");
              break;
            }
            getchar();
            break;

          case 2:

            q=1;

              imprime_topo(empresa2);
              printf("\nDigite o ID do container a ser Removido: ");
              scanf("%d",&q);
              erro = Despachar_container(&saida,q,empresa2);
              switch (erro)
            {
            case 0:
              printf("Container adicionado a lista\n");
              break;
            case 1:
              printf("Não é possível escolher o container informado\n");
              break;
            }
              getchar();
              break;

          case 3:

              q=1;

              imprime_topo(empresa3);
              printf("\nDigite o ID do container a ser Removido: ");
              scanf("%d",&q);
              erro = Despachar_container(&saida,q,empresa3);
            switch (erro) {
              case 0:
                printf("Container adicionado a lista\n");
                break;
              case 1:
                printf("Não é possível escolher o container informado\n");
                break;
            }
              getchar();
              break;

          case 4:
              q=1;

              imprime_topo(empresa4);
              printf("\nDigite o ID do container a ser Removido: ");
              scanf("%d",&q);
              erro = Despachar_container(&saida,q,empresa4);
              switch (erro)
            {
            case 0:
              printf("Container adicionado a lista\n");
              break;
            case 1:
              printf("Não é possível escolher o container informado\n");
              break;
            }
              getchar();
              break;

        }
        getchar();
        break;

    case 6:
        printf("\nDigite o id da empresa:");
        scanf("%d", &emp_s);

        switch(emp_s){

            case 1:
            do{

            flag = 0;

            q=1;

            imprime_topo(empresa);
            printf("\nDigite o ID do container a ser Removido: ");
            scanf("%d",&q);
            erro = Despachar_container(&saida,q,empresa);
            if(erro == 0)
                printf("Container adicionado a lista\n");
            else
                printf("Não é possível escolher o container informado\n");


            printf("Deseja inserir mais: 1-SIM 2-NÃO\n");
            scanf("%d", &flag);

            }while (flag != 2);

            getchar();
            break;

          case 2:

            do{

            flag = 0;

            q=1;

            imprime_topo(empresa2);
            printf("\nDigite o ID do container a ser Removido: ");
            scanf("%d",&q);
            erro = Despachar_container(&saida,q,empresa2);
            if(erro == 0)
                printf("Container adicionado a lista\n");
            else
                printf("Não é possível escolher o container informado\n");
            printf("Deseja inserir mais: 1-SIM 2-NÃO\n");
            scanf("%d", &flag);
            }while (flag != 2);

            getchar();
            break;

          case 3:

              do{

            flag = 0;

            q=1;

            imprime_topo(empresa3);
            printf("\nDigite o ID do container a ser Removido: ");
            scanf("%d",&q);
            erro = Despachar_container(&saida,q,empresa3);
            if(erro == 0)
                printf("Container adicionado a lista\n");
            else
                printf("Não é possível escolher o container informado\n");
            printf("Deseja inserir mais: 1-SIM 2-NÃO\n");
            scanf("%d", &flag);
            }while (flag != 2);

            getchar();
            break;

          case 4:
              do{

            flag = 0;

            q=1;

            imprime_topo(empresa4);
            printf("\nDigite o ID do container a ser Removido: ");
            scanf("%d",&q);
            erro = Despachar_container(&saida,q,empresa4);
            if(erro == 0)
                printf("Container adicionado a lista\n");
            else{
                printf("Não é possível escolher o container informado\n");
                printf("Deseja inserir mais: 1-SIM 2-NÃO\n");
                scanf("%d", &flag);
              }
            }while (flag != 2);

            getchar();
            break;
        }
        getchar();
            break;
      case 7:
        printf("\n1 - Entrada\t 2 - Saida\n");
        scanf("%d",&q);
        switch(q){
          case 1:
            erro= imprimir_Fila(&chegada);
            break;
          case 2:
            erro= imprimir_Fila(&saida);
            break;
        }
        getchar();
        break;

      case 8:

        switch(emp_s){
            case 1:
                erro = remove_container(&saida,&empresa,&historico);
                getchar();
                break;

            case 2:
                erro = remove_container(&saida,&empresa2,&historico);
                getchar();
                break;
            case 3:
                erro = remove_container(&saida,&empresa3,&historico);
                getchar();
                break;

            case 4:
                erro = remove_container(&saida,&empresa4,&historico);
                getchar();
                break;
            default:
                printf("\n Opcao nao valida\n");
                getchar();
                break;
        }

			case 9: break;
			default: printf("\n\n Opcao nao valida\n");
		getchar();    /* Limpa o buffer de entrada */
		}
	} while ((q != 9) );

}

/* -----------------------------------------------------------------------------
FUNÇÕES - SISTEMA DE ENTRADA E DESCARGA EM PORTOS - SEDEP
------------------------------------------------------------------------------*/
int inicializa (Fila *f){
    (*f).inicio = NULL;
    (*f).fim = NULL;
}

int verifica_vazio(Fila f){
    if(f.fim==NULL){
        return 0;
    }else{
        return 1;
    }
}

int libera_fila(Fila *f){
  int erro = verifica_vazio(*f);
  No_c *aux;

  if(erro==0){
      return 1;
  }else{
    do{
      aux = (*f).inicio;
      (*f).inicio = (*f).inicio->prox;
      free(aux);
    }while((*f).inicio!=NULL);
  }
  inicializa(f);
  return 0;
}


/*--------------------------------------------------------------
    Funções para cadastro de containers
--------------------------------------------------------------*/


int Criar_Container(Container **novo, char *carga, int emp_id){

    Container *no;

    no = (Container *) malloc (sizeof(Container));


    if(emp_id  == 1){
      no->id = w;
      w++;
    }
    else if (emp_id  == 2){
      no->id = x;
      x++;
    }


    else if (emp_id  == 3){
      no->id = y;
      y++;
    }

    else{
      no->id = z;
      z++;
    }


    if(emp_id  == 1 && w == 200)
      w = 100;

    else if (emp_id  == 1 && x == 300)
      x = 200;

    else if (emp_id  == 1 && y == 400)
      y = 300;

    else if (emp_id  == 1 && z == 500)
      z = 400;

    strcpy(no->tipo,carga);
    *novo = no;
    return 0;
}



int Insere_Container(Fila *f, char *valor, Registro **log, int emp_id){

    int erro = verifica_vazio(*f);

    Container *novo_c;

    Criar_Container(&novo_c, valor, emp_id);
    Salva_log(log,novo_c->id,1);
    No_c *no_novo;
    no_novo = (No_c *) malloc(sizeof(No_c));
    no_novo->dado = novo_c;
    no_novo->prox = NULL;

    if(erro == 0){
        (*f).inicio = no_novo;
        (*f).fim = no_novo;
    }else{
        (*f).fim->prox = no_novo;
        (*f).fim = no_novo;
    }
    return 0;
}

int remover(Fila *f){
    int erro = verifica_vazio(*f);
    No_c *aux;
    if(erro==0){
        return 1;
    }else{
        aux = (*f).inicio;
        (*f).inicio = (*f).inicio->prox;
        free(aux);
    }
}

int Transferencia(Fila *f, Patio **patio){
  Matriz *aux;
  int erro,j,k;
  if(f==NULL){
    return 1;//Fila vazia
  }

  if(*patio==NULL){
    return 2;//Pátio inexistente
  }

  erro = Verifica_camada_cheia(*patio);
  if(erro == 0 && (*patio)->topo<2){
    (*patio)->topo++;
  }else{
    if(erro == 0 && (*patio)->topo==2){
      return 3;//Patio cheio
    }
  }

  do{
    aux = (*patio)->camadas[(*patio)->topo];
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        if((*aux).area[j][k]->id==1){
          if(f->inicio != NULL){
            (*aux).area[j][k] = f->inicio->dado;
            remover(f);
          }
        }
      }
    }

    erro = Verifica_camada_cheia(*patio);
    if(erro == 0 && (*patio)->topo<2){
      (*patio)->topo++;
    }else{
      if(erro == 0 && (*patio)->topo==2){
        return 4;//Patio cheio e com containers não alocados
      }
    }
  }while(f->inicio!=NULL);

  erro = Verifica_camada_cheia(*patio);
  if(erro == 2 && (*patio)->topo>0){
    (*patio)->topo--;
  }

  inicializa(f);
  return 0;
}



/*--------------------------------------------------
  Funções Pátio
---------------------------------------------------*/




int Inicializa_patio(Patio **empresa){
  Patio *emp;
  Container *c;
  c = (Container*) malloc(sizeof(Container));
  c->id=1;
  strcpy(c->tipo,"AAA");

  Matriz *m1,*m2,*m3;

  m1 = (Matriz*) malloc(sizeof(Matriz));
  m2 = (Matriz*) malloc(sizeof(Matriz));
  m3 = (Matriz*) malloc(sizeof(Matriz));


  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      m1->area[j][k]=c;
    }
  }

  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      m2->area[j][k]=c;
    }
  }

  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      m3->area[j][k]=c;
    }
  }

  emp = (Patio *) malloc(sizeof(Patio));

  emp->camadas[0] = m1;
  emp->camadas[1] = m2;
  emp->camadas[2] = m3;

  emp->topo = 0;

  *empresa = emp;
}


int imprimir_Siglas(){

    printf("\nELT - Eletrônicos\n");
    printf("MTC - Material de construção\n");
    printf("MED - Medicamento\n");
    printf("ALM - Alimentos\n");
    printf("MOV - Móveis\n");

    return 0;
}

int imprimir_Fila(Fila *f){

    No_c *aux;

    aux = f->inicio;

    if (f == NULL)
        return 1; // Fila está vazia !!!
    else{
        while(aux != NULL){
            printf("Id do container: %d\n", aux->dado->id);
            aux = aux->prox;
        }
        return 0;
    }
}




/*------------------------------------------------------------
    Funções Log
-------------------------------------------------------------*/




int Verifica_camada_cheia(Patio *p){
  Matriz *aux;
  int count = 0;
  if(p==NULL){
    return 2;//Patio inexistente
  }
  aux = p->camadas[p->topo];
  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      if(aux->area[j][k]->id==1){
        count++;
      }
    }
  }
  if(count>0){
    if(count==9){
      return 2;//Camada Totalmente Livre
    }else{
      return 1;//Camada parcialmente Livre
    }
  }
  return 0;
}

int ConfereLog(Registro *log){
  Registro *aux;
  Lista *numId;
  if(log==NULL){
    return 1;//Patio inexistente
  }
  aux=log;
  numId = aux->ids;
  printf("\n");
  do{
    numId = aux->ids;
    switch(aux->Id){
      case 1:
        printf("Empresa Coca-cola\t");
        break;
      case 2:
        printf("Empresa Guarana-Jesus\t");
        break;
      case 3:
        printf("Empresa Itubaina\t");
        break;
      case 4:
        printf("Empresa Pepsi\t");
        break;
      default:
        printf("Empresa não cadastrada\t");
        break;
    }
    switch(aux->tipo){
      case 1:
        printf("Tipo: Entrada\t");
        break;
      case 2:
        printf("Tipo: Saida\t");
        break;
      default:
        break;
    }
    printf("Quantidade: %d\n",aux->qtd);
    printf("Id(s) do(s) container(s): ");
    do{
      printf("%d\t ",numId->dado);
      numId = numId->prox;
    }while(numId!=NULL);
    aux = aux->prox;
    printf("\n\n");
  }while(aux!=NULL);
  return 0;
}

int Inicializar_Reg (Registro **inicio)
{
	*inicio= NULL;

	return 0; /* sem erro */
}

int Salva_log(Registro **log, int id, int tipo){
  Registro *no_novo, *percorre, *aux;

  no_novo = (Registro *) malloc(sizeof(Registro));
  no_novo->Id = (int) floor((id/100));
  no_novo->qtd = 0;
  no_novo->ids = NULL;
  no_novo->prox = NULL;
  no_novo->tipo = tipo;

  if (*log==NULL)
  {
    Adiciona_id(&(no_novo->ids),id);
    *log = no_novo;
  }
  else
  {
    percorre = *log;
    aux = *log;
    while(percorre->prox != NULL){
      percorre = percorre -> prox;
    }
    if(percorre->qtd!=0){
      Adiciona_id(&(no_novo->ids),id);
      percorre->prox = no_novo;
    }else{
      Adiciona_id(&(percorre->ids),id);
      free(no_novo);
    }
  }
  return 0;
}

int Adiciona_id(Lista **lista, int id){
  Lista *no_novo, *percorre;

  /* Criacao do novo no - Alocacao de memoria */
  no_novo = (Lista *) malloc(sizeof(Lista));
  no_novo->dado = id;
  no_novo->prox = NULL;

  if (*lista==NULL)
  {
      /* lista vazia. */
      *lista = no_novo;
  }
  else   /* lista nao vazia */
  {
      percorre = *lista;
      while (percorre->prox != NULL)
      {
          percorre = percorre -> prox;
      }
      percorre->prox = no_novo;
  }
  return 0;
}

int Fecha_lote(Registro **log, int qtd){
  Registro *percorre;

  if(*log == NULL){
    return 1; //Lista Vazia
  }else{
    percorre = *log;
    while (percorre->prox != NULL || percorre->qtd!=0)
    {
      percorre = percorre -> prox;
    }
    if(percorre->qtd==0){
      percorre->qtd = qtd;
    }else{
      return 2;//Todos os Lotes Fechados.
    }
  }
}



/*-----------------------------------------------------------
  Remover lote
-----------------------------------------------------------*/




int Despachar_container(Fila *f, int numId, Patio *p){
  Matriz *aux;
  Container *c = NULL;
  int erro = verifica_vazio(*f);

  aux = p->camadas[p->topo];
  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      if(aux->area[j][k]->id==numId){
        c=aux->area[j][k];
      }
    }
  }

  if(c==NULL){
    return 1;//Container informado não existe;
  }

  No_c *no_c;
  no_c = (No_c *) malloc(sizeof(No_c));
  no_c->dado = c;
  no_c->prox = NULL;

  if(erro == 0){
      (*f).inicio = no_c;
      (*f).fim = no_c;
  }else{
      (*f).fim->prox = no_c;
      (*f).fim = no_c;
  }
  return 0;
}

int imprime_topo(Patio *p){
  Matriz *aux;
  if(p==NULL){
    return 2;//Patio inexistente
  }
  printf("\n");
  aux = p->camadas[p->topo];
  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      if(aux->area[j][k]->id!=1){
        printf("Id: %d\n",aux->area[j][k]->id);
      }
    }
  }
  return 0;
}

int remove_container(Fila *f, Patio **p,Registro **log){
  Matriz *aux;
  Container *c,*t;
  int j,k,erro,h,q=0;

  if(f==NULL){
    printf("\n Fila para remoção está vazia !\n");
    return 1;//Fila inexistente
  }
  if(p==NULL){
    printf("\n Não há containers alocados no patio !\n");
    return 2;//Patio inexistente
  }
  t = (Container*) malloc(sizeof(Container));
  t->id=1;
  strcpy(t->tipo,"AAA");
  do{
    h=0;
    aux = (*p)->camadas[(*p)->topo];
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        if(f->inicio != NULL){
          if((*aux).area[j][k]->id==f->inicio->dado->id){
            h=1;
            c=(*aux).area[j][k];
            Salva_log(log,c->id,2);
            q++;
            free(c);
            remover(f);
            (*aux).area[j][k] = t;
          }
        }
      }
    }
    erro = Verifica_camada_cheia(*p);
    if(erro == 2 && (*p)->topo>0){
      (*p)->topo--;
    }else{
      if(erro == 2 && (*p)->topo==0){
        if(q>0){
          Fecha_lote(log,q);
        }
        return 3;//Patio zerado
      }
    }
    if(h==0){
      libera_fila(f);
      return 4;//Valor não encontrado;
    }
  }while(f->inicio!=NULL);
  Fecha_lote(log,q);
  inicializa(f);
  return 0;
}
