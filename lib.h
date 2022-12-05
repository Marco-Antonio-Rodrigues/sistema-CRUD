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
aluno* remover_aluno(aluno *raiz, int matricula);

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

// função que realiza a troca entre duas disciplinas
void troca(disciplina** vet, int i, int j);

// particiona e retorna o índice do pivô
int particiona(disciplina** vet, int inicio, int fim);

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int pivo(disciplina** vet, int inicio, int fim);

// ordena as disciplinas em ordem decrescente pelo valor da nota
void quick_sort(disciplina** vet, int inicio, int fim);

// busca o aluno na arvore e retorna a struct aluno
aluno* buscar_dados_aluno(aluno* raiz,int matricula);

// Ler o arquivo texto e ja preenche a arvore
void read_banco_de_dados(FILE *banco_de_dados);

void in_ordem(aluno* aux, FILE *backup);

// salva a arvore no arquivo texto
void write_banco_de_dados(FILE *backup);

// explicando banco_de_dados.txt
// 1   --primeira linha do arquivo fala quantos alunos tem
// 511354 --primeira linha do aluno/matricula
// marco --nome
// 85994189459 --numero telefone
// marco@gmail.com --email
// 1230 -- numero da residencia
// rua_sebastiao -- rua do endereco
// 638888 -- cep do endereco
// 2 --quantidade de disciplinas
// 17 -- primeira linha da disciplina/codigo
// estrutura_de_dados -- nome da disciplina
// 10.000000 -- nota final da disciplina
// 18 --codigo
// laboratorio_de_programacao --nome da disciplina
// 9.000000 --nota final da disciplina
//aqui ou poderia ter mais uma disciplina se fosse 3 ou comecaria outro aluno se a primeira linhha fosse 2
#endif