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

aluno remover_aluno(int matricula);

void editar_aluno(int matricula){ 
    aluno * aluno_editado = buscar_dados_aluno(raiz , matricula);
    while (1){
        int comando = 0, sub_comando = 0;
        int novo_inteiro;
        float novo_float;
        char nova_str[200];
        printf("Digite o que deseja acessar");
        printf("\n1-Aluno\n2- Disciplinas\n3- Sair\n");
        scanf("%i", &comando);
        if (comando == 1){
            printf("\nDigite o que deseja acessar: \n");
            printf("\n1-Matricula\n2-Nome\n3-Num.TEL \n4-Email \n5-Num.Casa \n6-Rua \n7- CEP\n");
            scanf("%i", &sub_comando);
            if(sub_comando==1){
                printf("\nDigite a nova matricula: ");
                scanf("%i", &novo_inteiro);
                printf("\nMatricula Atualizada");
                aluno_editado -> matricula=novo_inteiro;
            }else if(sub_comando==2){
                printf("\nDigite o novo nome: ");
                scanf("%s", nova_str);
                printf("\nNome Atualizado");
                strcpy(aluno_editado -> nome_aluno,nova_str);
            }else if(sub_comando==3){
                printf("\nDigite o novo numero de telefone: ");
                scanf("%s", nova_str);
                printf("\nNumero de Tel Atualizado");
                strcpy(aluno_editado -> numero_aluno,nova_str);
            }else if(sub_comando==4){
                printf("\nDigite o novo email: ");
                scanf("%s", nova_str);
                printf("\nEmail Atualizado");
                strcpy(aluno_editado -> email_aluno , nova_str);
            }else if(sub_comando==5){
                printf("\nDigite o novo numero da casa: ");
                scanf("%i", &novo_inteiro);
                printf("\nNumero da casa Atualizado");
                aluno_editado -> endereco_aluno-> numero_casa = novo_inteiro;
            }else if(sub_comando==6){
                printf("\nDigite o novo nome da rua: ");
                scanf("%s", nova_str);
                printf("\nNome da rua atualizado");
                strcpy(aluno_editado -> endereco_aluno-> nome_rua,nova_str);
            }else if(sub_comando==7){
                printf("\nDigite o novo numero do cep: ");
                scanf("%i", &novo_inteiro);
                printf("\nCEP atualizado\n");
                aluno_editado -> endereco_aluno-> cep = novo_inteiro;
            }
        }else if(comando==2){
            int y;
            for(y=0; y<aluno_editado->quantidade_disciplinas;y++){
                printf("\n%i-%s",y,aluno_editado->disciplinas[y]->nome_disciplina);
            }
            printf("Escolha a Disciplina: ");
            scanf("%i", &y);
            printf("\nDigite o que deseja acessar: \n");
            printf("\n1-Codigo da disciplina\n2-Nome da disciplina\n3-Nota da Disciplina");
            scanf("%i", &sub_comando);
            if(sub_comando==1){
                printf("\nDigite o novo Cod. Da Disc: ");
                scanf("%i", &novo_inteiro);
                aluno_editado->disciplinas[y]->codigo_disciplina = novo_inteiro;
                printf("\nCod. Atualizado");
                
            }else if(sub_comando==2){
                printf("\nDigite o novo nome da Disc: ");
                scanf("%s", nova_str);
                strcpy(aluno_editado -> disciplinas[y] -> nome_disciplina, nova_str);
                printf("\nNome Atualizado");
            }else if(sub_comando==3){
                printf("\nDigite a nova nota da Disc: ");
                scanf("%f", &novo_float);
                aluno_editado->disciplinas[y]->nota_final_disciplina = novo_float;
                printf("\nNota Atualizada");
            }
        }else if(comando ==3){
            break;
        }
           
        
        }
        }


void imprimir_aluno(int matricula);

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
    editar_aluno(511354);
    // int escolha = 0;
    // while (1){
    //     printf("------MENU------\n\n1 - adicionar aluno\n2 - editar aluno \n3 - remover aluno\n4 - ver aluno\n5 - sair\n\n");
    //     scanf("%i",&escolha);
        
    //     if(escolha == 1){
    //         int aux, matricula, codigo_disciplina;
    //         float nota_final_disciplina;
    //         char nome[200], numero[200], email[200],nome_disciplina[200] ;  
    //         endereco* endereco_aluno;
    //         disciplina* disciplinas = malloc(sizeof(disciplina));
    //         scanf("%i",&matricula);
    //         scanf("%s",nome);
    //         scanf("%s",numero);
    //         scanf("%s",email);
    //         endereco_aluno = malloc(sizeof(endereco_aluno));
    //         endereco_aluno->nome_rua = malloc(sizeof(char)*200);
    //         scanf("%i",&endereco_aluno->numero_casa);
    //         scanf("%s",endereco_aluno->nome_rua);
    //         scanf("%i",&endereco_aluno->cep);
    //         cadastrar_aluno(matricula,nome,numero,email,0,disciplinas,endereco_aluno);
    //     }else if(escolha == 2){
    //         int matricula;
    //         printf("\nDigite a matricula: ");
    //         scanf("%i",&matricula);
    //         editar_aluno(matricula);
    //     }else if(escolha == 3){

    //     }else if(escolha == 4){

    //     }else if(escolha == 5){
    //         printf("\ntchau!");
    //         break;
    //     }
    
    // }
    write_banco_de_dados(backup);
    fclose(banco_de_dados);
    fclose(backup);
  return 0;
}