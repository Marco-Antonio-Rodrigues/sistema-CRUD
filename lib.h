#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef LIB
#define LIB

typedef struct disciplina{
  int codigo_disciplina;
  char* nome_disciplina;
  float nota_final_disciplina;
}disciplina;

typedef struct endereco{
  int numero_casa;
  char* nome_rua;
  int cep;
}endereco;

typedef struct aluno{
  int matricula;
  char* nome_aluno;
  char* numero_aluno;
  char* email_aluno;
  int quantidade_disciplinas;
  endereco* endereco_aluno;
  disciplina** disciplinas;
  struct aluno  *filho_esq;
  struct aluno  *filho_dir;
}aluno;

aluno *raiz = NULL;
int quantidade_alunos = 0;

// você deverá receber como parâmetro os dados de um aluno e adicionar estes dados
// em uma Árvore Binária de Busca. Você deve considerar a matrícula do aluno como chave 
// única do nó a ser inserido;
void cadastrar_aluno(int matricula,char* nome,char* numero, char* email,int quantidade_disciplinas, disciplina **disciplinas,endereco* endereco_aluno);

// você deve receber como parâmetro a matrícula de um aluno e remover a nó da Árvore
// Binária de Busca que contenha esta matrícula.
// retorna o aluno removido
aluno remover_aluno(int matricula);

// você deve receber como parâmetro a matrícula de um aluno e encontrar o nó da
// Árvore Binária de Busca que contenha esta matrícula. Após encontrar o nó, você deve perguntar 
// qual dos dados pessoais definidos pela equipe será alterado e solicitar o novo valor para 
// realizar a alteração. Note que esta função permite que seja alterado apenas os dados pessoais do aluno.
void editar_aluno(int matricula);

// você deve receber como parâmetro a matrícula de um aluno e encontrar o nó
// da Árvore Binária de Busca que contenha esta matrícula. Após encontrar o nó, você deve 
// apresentar os dados pessoais do aluno, assim como o conjunto de disciplinas e notas finais 
// que o aluno tenha cursado. As disciplinas e notas devem ser apresentadas em ordem decrescente 
// de notas e portanto você deve aplicar um algoritmo de ordenação(obrigatoriamente) para 
// ordenar o vetor, antes de imprimi-lo.
void imprimir_aluno(int matricula);

// busca o aluno na arvore e retorna a struct aluno
aluno* buscar_dados_aluno(aluno* raiz,int matricula);

// Ler o arquivo texto e ja preenche a arvore
void read_banco_de_dados(FILE *banco_de_dados);

void in_ordem(aluno* aux, FILE *backup);

// salva a arvore no arquivo texto
void write_banco_de_dados(FILE *backup);

#endif