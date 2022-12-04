#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

aluno* buscar_dados_aluno(aluno* raiz, int matricula){
    if(raiz == NULL){
        return NULL; //vazia
    }else if(matricula == raiz->matricula){
        return raiz; //encontrei :D
    }else if(matricula<raiz->matricula){ //buscar no lado esq
        if(raiz->filho_esq != NULL){
            return buscar_dados_aluno(raiz->filho_esq,matricula);
        }else{//esq esta vazia
            return raiz; //pai do elemento que não foi encontrado
        }
    }else{//buscar no lado dir
        if(raiz->filho_dir != NULL){
            return buscar_dados_aluno(raiz->filho_dir,matricula);
        }else{//dir esta vazia
            return raiz; //pai do elemento que não foi encontrado
        }
    }
}

void cadastrar_aluno(int matricula,char* nome,char* numero, char* email,int quantidade_disciplinas, disciplina **disciplinas,endereco* endereco_aluno){//ok
    aluno* aux = buscar_dados_aluno(raiz, matricula);
    if(aux == NULL || aux->matricula != matricula){// vazia ou eu posso adicionar
        aluno* novo_aluno = malloc (sizeof(aluno));
        novo_aluno->matricula = matricula;
        novo_aluno->nome_aluno = malloc(sizeof(char)*200);
        novo_aluno->numero_aluno = malloc(sizeof(char)*200);
        novo_aluno->email_aluno = malloc(sizeof(char)*200);

        strcpy(novo_aluno->nome_aluno,nome);
        strcpy(novo_aluno->numero_aluno,numero);
        strcpy(novo_aluno->email_aluno,email);
        novo_aluno->endereco_aluno = endereco_aluno;
        novo_aluno->quantidade_disciplinas = quantidade_disciplinas;
        novo_aluno->disciplinas = disciplinas;
        novo_aluno->filho_esq = NULL;
        novo_aluno->filho_dir = NULL;
        quantidade_alunos++;
        if(aux == NULL){ //add na raiz
            raiz = novo_aluno;
        }else{
            if(matricula < aux->matricula){
                aux->filho_esq = novo_aluno;
            }else{
                aux->filho_dir = novo_aluno;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso havera chaves duplicadas
        printf("Cadastro inválido. Chave duplicada\n");
    }
}

aluno* remover_aluno(aluno *raiz, int matricula) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover_aluno
        if(raiz->matricula == matricula) {
            // remove nós folhas (nós sem filhos)
            if(raiz->filho_esq == NULL && raiz->filho_dir == NULL) {
                free(raiz);
                quantidade_alunos--;
                printf("Elemento folha removido: %d !\n", matricula);
                return NULL;
            }
            else{
                // remover_aluno nós que possuem dois 2 filho
                if(raiz->filho_esq != NULL && raiz->filho_dir != NULL){
                    aluno *aux = raiz->filho_esq; // subárvore à filho_esq
                    while(aux->filho_dir != NULL)
                        aux = aux->filho_dir; // obtêm o nó mais a filho_dir
                    raiz->matricula = aux->matricula;
                    aux->matricula = matricula;
                    printf("Elemento trocado: %d !\n", matricula);
                    raiz->filho_esq = remover_aluno(raiz->filho_esq, matricula);
                    return raiz;
                }
                else{
                    // remover_aluno nós que possuem apenas 1 filho
                    aluno *aux;
                    if(raiz->filho_esq != NULL)
                        aux = raiz->filho_esq;
                    else
                        aux = raiz->filho_dir;
                    free(raiz);
                    quantidade_alunos--;
                    printf("Elemento com 1 filho removido: %d !\n", matricula);
                    return aux;
                }
            }
        } else {
            if(matricula < raiz->matricula)
                raiz->filho_esq = remover_aluno(raiz->filho_esq, matricula);
            else
                raiz->filho_dir = remover_aluno(raiz->filho_dir, matricula);
            return raiz;
        }
    }
}

void editar_aluno(int matricula){ 
    aluno * aluno_editado = buscar_dados_aluno(raiz , matricula);
     if(aluno_editado->matricula != matricula){
        printf("\nAluno não encontrado");
    }else{
        while (1){
            printf("\nDigite o que deseja acessar\n");
            int comando = 0, sub_comando = 0;
            printf("\n1-Aluno\n2- Disciplinas\n3- Sair\n");
            scanf("%i", &comando);
            if (comando == 1){
                printf("\nDigite o que deseja acessar: \n");
                printf("\n1-Matricula\n2-Nome\n3-Num.TEL \n4-Email \n5-Num.Casa \n6-Rua \n7- CEP\n8-Sair\n");
                scanf("%i", &sub_comando);
                if(sub_comando==1){
                    printf("\nDigite a nova matricula: ");
                    scanf("%i", &aluno_editado -> matricula);
                    printf("\nMatricula Atualizada\n");
                }else if(sub_comando==2){
                    printf("\nDigite o novo nome: ");
                    scanf("%s", aluno_editado -> nome_aluno);
                    printf("\nNome Atualizado");
                }else if(sub_comando==3){
                    printf("\nDigite o novo numero de telefone: ");
                    scanf("%s", aluno_editado -> numero_aluno);
                    printf("\nNumero de Tel Atualizado");
                }else if(sub_comando==4){
                    printf("\nDigite o novo email: ");
                    scanf("%s", aluno_editado -> email_aluno);
                    printf("\nEmail Atualizado");
                }else if(sub_comando==5){
                    printf("\nDigite o novo numero da casa: ");
                    scanf("%i", &aluno_editado -> endereco_aluno-> numero_casa);
                    printf("\nNumero da casa Atualizado");
                }else if(sub_comando==6){
                    printf("\nDigite o novo nome da rua: ");
                    scanf("%s", aluno_editado -> endereco_aluno-> nome_rua);
                    printf("\nNome da rua atualizado");
                }else if(sub_comando==7){
                    printf("\nDigite o novo numero do cep: ");
                    scanf("%i", &aluno_editado -> endereco_aluno-> cep);
                    printf("\nCEP atualizado\n");
                }else if(sub_comando==8){
                    break;
                }
            }else if(comando==2){
                int y;
                for(y=0; y<aluno_editado->quantidade_disciplinas;y++){
                    printf("\n%i-%s",y,aluno_editado->disciplinas[y]->nome_disciplina);
                }
                printf("\nEscolha a Disciplina: ");
                scanf("%i", &y);
                printf("\nDigite o que deseja acessar: \n");
                printf("\n1-Codigo da disciplina\n2-Nome da disciplina\n3-Nota da Disciplina\n");
                scanf("%i", &sub_comando);
                if(sub_comando==1){
                    printf("\nDigite o novo Cod. Da Disc: ");
                    scanf("%i", &aluno_editado->disciplinas[y]->codigo_disciplina);
                    printf("\nCod. Atualizado");
                    
                }else if(sub_comando==2){
                    printf("\nDigite o novo nome da Disc: ");
                    scanf("%s", aluno_editado -> disciplinas[y] -> nome_disciplina);
                    printf("\nNome Atualizado");
                }else if(sub_comando==3){
                    printf("\nDigite a nova nota da Disc: "); 
                    scanf("%f", &aluno_editado->disciplinas[y]->nota_final_disciplina);
                    printf("\nNota Atualizada");
                }
            }else if(comando ==3){
                break;
            }
            
        }
    }
}

// função que realiza a troca entre duas disciplinas
void troca(disciplina** vet, int i, int j){
	disciplina* aux = malloc(sizeof(disciplina));
    aux->nome_disciplina = malloc(sizeof(char)*200);

    aux->codigo_disciplina = vet[i]->codigo_disciplina;
    aux->nota_final_disciplina = vet[i]->nota_final_disciplina;
    strcpy(aux->nome_disciplina,vet[i]->nome_disciplina);
    
    vet[i]->codigo_disciplina = vet[j]->codigo_disciplina;
    vet[i]->nota_final_disciplina = vet[j]->nota_final_disciplina;
    strcpy(vet[i]->nome_disciplina,vet[j]->nome_disciplina);

    vet[j]->codigo_disciplina = aux->codigo_disciplina;
    vet[j]->nota_final_disciplina = aux->nota_final_disciplina;
    strcpy(vet[j]->nome_disciplina,aux->nome_disciplina);
}

// particiona e retorna o índice do pivô
int particiona(disciplina** vet, int inicio, int fim){
    float pivo, pivo_indice;
    int i;
	
	pivo = vet[fim]->nota_final_disciplina; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++){
		// verifica se o elemento é <= ao pivô
		if(vet[i] ->nota_final_disciplina >= pivo){
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int pivo(disciplina** vet, int inicio, int fim){
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(disciplina** vet, int inicio, int fim){
	if(inicio <fim){
		// função particionar retorna o índice do pivô
		int pivo_indice = pivo(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}


void imprimir_aluno(int matricula){
    aluno* aluno_impresso = buscar_dados_aluno(raiz, matricula);
    if(aluno_impresso->matricula != matricula){
        printf("\nAluno não encontrado");
    }else{
        printf("\nMatricula:%i",aluno_impresso -> matricula);
        printf("\nNome:%s", aluno_impresso ->nome_aluno);
        printf("\nNumero do Aluno:%s", aluno_impresso->numero_aluno);
        printf("\nEmail: %s", aluno_impresso->email_aluno);
        printf("\nQuantidades de disciplinas: %i",aluno_impresso->quantidade_disciplinas);
        printf("\nCEP do aluno:  %i", aluno_impresso->endereco_aluno->cep);
        printf("\nNome da rua: %s", aluno_impresso->endereco_aluno->nome_rua);
        printf("\nNumero da casa: %i", aluno_impresso->endereco_aluno->numero_casa);
        quick_sort(aluno_impresso->disciplinas,0,(aluno_impresso->quantidade_disciplinas)-1);
        for(int i = 0; i < aluno_impresso->quantidade_disciplinas ;i++){
            printf("\n%i",aluno_impresso->disciplinas[i]->codigo_disciplina);
            printf("\n%s",aluno_impresso->disciplinas[i]->nome_disciplina);
            printf("\n%f",aluno_impresso->disciplinas[i]->nota_final_disciplina);
        }
    }
}
void read_banco_de_dados(FILE *banco_de_dados){//ok
    int aux, matricula, codigo_disciplina;
    float nota_final_disciplina;
    char nome[200], numero[200], email[200],nome_disciplina[200] ;  
    fscanf(banco_de_dados,"%i",&aux);
    for(int i = aux; 0 < i;i--){
        int quantidade_disciplinas = 0;
        fscanf(banco_de_dados,"%i",&matricula);
        fscanf(banco_de_dados,"%s",nome);
        fscanf(banco_de_dados,"%s",numero);
        fscanf(banco_de_dados,"%s",email);
        endereco* endereco = malloc(sizeof(endereco));
        endereco->nome_rua = malloc(sizeof(char)*200);
        fscanf(banco_de_dados,"%i",&endereco->numero_casa);
        fscanf(banco_de_dados,"%s",endereco->nome_rua);
        fscanf(banco_de_dados,"%i",&endereco->cep);

        fscanf(banco_de_dados,"%i",&quantidade_disciplinas);
        disciplina** disciplinas = malloc(sizeof(disciplina*)*quantidade_disciplinas);//ponteiro de disciplina
        for(int y = 0; y < quantidade_disciplinas;y++){
            disciplinas[y] = malloc(sizeof(disciplina));
            disciplinas[y]->nome_disciplina = malloc(sizeof(char)*200);
            fscanf(banco_de_dados,"%i",&disciplinas[y]->codigo_disciplina);
            fscanf(banco_de_dados,"%s",disciplinas[y]->nome_disciplina);
            fscanf(banco_de_dados,"%f",&disciplinas[y]->nota_final_disciplina);
        }
        cadastrar_aluno(matricula,nome,numero,email,quantidade_disciplinas,disciplinas,endereco);
    }
}

void in_ordem(aluno* aux, FILE *backup){
    if(aux == NULL){
        return;
    }else{
        in_ordem(aux->filho_esq,backup);
        fprintf(backup,"\n%i",aux->matricula);
        fprintf(backup,"\n%s",aux->nome_aluno);
        fprintf(backup,"\n%s",aux->numero_aluno);
        fprintf(backup,"\n%s",aux->email_aluno);
        fprintf(backup,"\n%i",aux->endereco_aluno->numero_casa);
        fprintf(backup,"\n%s",aux->endereco_aluno->nome_rua);
        fprintf(backup,"\n%i",aux->endereco_aluno->cep);
        fprintf(backup,"\n%i",aux->quantidade_disciplinas);
        for(int i = 0; i< aux->quantidade_disciplinas ;i++){
            fprintf(backup,"\n%i",aux->disciplinas[i]->codigo_disciplina);
            fprintf(backup,"\n%s",aux->disciplinas[i]->nome_disciplina);
            fprintf(backup,"\n%f",aux->disciplinas[i]->nota_final_disciplina);
        }
        in_ordem(aux->filho_dir,backup);
    }
}
void write_banco_de_dados(FILE *backup){
    fprintf(backup,"%i",quantidade_alunos);
    in_ordem(raiz, backup);
}

int main(){
    FILE* banco_de_dados = fopen("banco_de_dados.txt","r");
    FILE* backup = fopen("backup.txt","w");
    read_banco_de_dados(banco_de_dados);
    int matricula, menu;
    
    while (1){
        printf("\n------MENU------\n\n1 - adicionar aluno\n2 - editar aluno \n3 - remover aluno\n4 - ver aluno\n5 - sair\n\n");
        scanf("%i",&menu);
        
        if(menu == 1){ //adicionar aluno ok
            int aux, matricula, codigo_disciplina ,quantidade_disciplinas;
            float nota_final_disciplina;
            char nome[200], numero[200], email[200],nome_disciplina[200] ;  
            endereco* endereco_aluno = malloc(sizeof(endereco_aluno));
            endereco_aluno->nome_rua = malloc(sizeof(char)*200);

            printf("\nDigite a matricula: "); scanf("%i",&matricula);
            printf("\nDigite o nome: "); scanf("%s",nome);
            printf("\nDigite o numero: "); scanf("%s",numero);
            printf("\nDigite o email: "); scanf("%s",email);
            printf("\nDigite o numero da casa: "); scanf("%i",&endereco_aluno->numero_casa);
            printf("\nDigite o nome da rua: "); scanf("%s",endereco_aluno->nome_rua);
            printf("\nDigite o cep: "); scanf("%i",&endereco_aluno->cep);
            printf("\nDigite a quantidade de disciplinas: "); scanf("%i",&quantidade_disciplinas);
            disciplina** disciplinas = malloc(sizeof(disciplina)*quantidade_disciplinas);
            for(int y = 0; y < quantidade_disciplinas;y++){
            disciplinas[y] = malloc(sizeof(disciplina));
            disciplinas[y]->nome_disciplina = malloc(sizeof(char)*200);
            printf("\nDigite o codigo da disciplina: "); scanf("%i",&disciplinas[y]->codigo_disciplina);
            printf("\nDigite o nome da disciplina: "); scanf("%s",disciplinas[y]->nome_disciplina);
            printf("\nDigite a nota final da disciplina: "); scanf("%f",&disciplinas[y]->nota_final_disciplina);
        }
            cadastrar_aluno(matricula,nome,numero,email,quantidade_disciplinas,disciplinas,endereco_aluno);
        
        }else if(menu == 2){//editar aluno 
            printf("\nDigite a matricula: ");
            scanf("%i",&matricula);
            editar_aluno(matricula);
        }else if(menu == 3){//remover aluno
            printf("\nDigite a matricula: ");
            scanf("%i",&matricula);
            remover_aluno(raiz,matricula);
        }else if(menu == 4){//ver aluno
            printf("\nDigite a matricula: ");
            scanf("%i",&matricula);
            imprimir_aluno(matricula);
        }else if(menu == 5){//sair
            printf("\nFazendo Backup...encerrando sessao.\n");
            break;
        }
    menu = 0;
    }
    write_banco_de_dados(backup);
    fclose(banco_de_dados); fclose(backup);
  return 0;
}