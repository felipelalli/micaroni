#ifndef F&F_FUN_1999
#define F&F_FUN_1999

///////////////
// INCLUSÂES //
///////////////
#include <stdio.h>
#include <string.h>

////////////////
// DEFINIÄÂES //
////////////////
// Boleanos:
#ifndef VERDADEIRO
#define VERDADEIRO 1
#endif
#ifndef FALSO
#define FALSO 0
#endif
#ifndef INDEFINIDO
#define INDEFINIDO -1
#else
#error Definicao INDEFINIDO Duplicada!
#endif

// Graus de Vers‰es:
#define VERSAO_LIVRE        1 // Dom°nio p£blico -: uso de patrocinadores
#define VERSAO_LICENCIADA   2 // Copyright(c) -: C¢pia Licenciada
#define VERSAO_DEMONSTRACAO 4 // Falta partes importantes -: tentaá∆o
#define VERSAO_SHAREWARE    8 // Funciona por um tempo û -: atasana usu†rio
#define VERSAO_BETA        16 // Èltima fase de testes -: dom°nio p£blico
#define VERSAO_ALPHA       32 // Fase de testes -: dom°nio p£blico
#define VERSAO_TESTE       64 // Fase de testes -: fase de programaá∆o
#define VERSAO_COMPACTA   128 // Partes mais importantes -: livre

#ifndef MAX_NOME_PRODUTO_FUN
#define MAX_NOME_PRODUTO_FUN 32
#else
#error Definiá∆o MAX_NOME_PRODUTO_FUN Duplicada!
#endif

#ifndef MAX_NOME_AUTOR
#define MAX_NOME_AUTOR 32
#else
#error Definiá∆o MAX_NOME_PRODUTO_FUN Duplicada!
#endif

///////////
// TIPOS //
///////////

#ifndef ARQUIVO
typedef
  FILE* ARQUIVO;
#else
#error Tipo ARQUIVO Duplicado!
#endif

#ifndef BYTE
typedef
  unsigned char BYTE;
#else
#error Tipo BYTE Duplicado!
#endif

#ifndef BOLEANO
typedef
  char BOLEANO;
#else
#error Tipo BOLEANO Duplicado!
#endif

#ifndef POSICAO
typedef
  fpos_t POSICAO;
#else
#error Tipo POSICAO Duplicado!
#endif

#ifndef CODIGO
typedef
  unsigned long int CODIGO;
#else
#error Tipo CODIGO Duplicado!
#endif

#ifndef DATA_SIMPLES
typedef
  struct DATA_SIMPLES
  {
    BYTE dia;
    BYTE mes;
    unsigned int ano;
  } DATA_SIMPLES;
#else
#error Tipo DATA_SIMPLES Duplicado!
#endif

#ifndef VERSAO_SIMPLES
typedef
  struct VERSAO_SIMPLES
  {
    BYTE versao;
    BYTE mudanca;
    unsigned int revisao;
  } VERSAO_SIMPLES;
#else
#error Tipo VERSAO_SIMPLES Duplicado!
#endif

//////////////////////
// CLASSE PRINCIPAL //
//////////////////////
#ifndef ObjFun
class ObjFun
{
  private:
    // Vers∆o:
    VERSAO_SIMPLES cversao;

    // Grau da vers∆o:
    BYTE cgrau;

    // Produto:
    CODIGO cnumero_de_serie;
    char cproduto[MAX_NOME_PRODUTO_FUN];
    char cautor[MAX_NOME_AUTOR];
    DATA_SIMPLES cdata;

  protected:
    // Definiá‰es:
    ObjFun& versao(const BYTE&, BYTE = 0, unsigned int = 0);
    ObjFun& grau(const BYTE&);
    ObjFun& data(const BYTE&, const BYTE&, const unsigned int&);
    ObjFun& data(DATA_SIMPLES);
    ObjFun& numero_de_serie(const CODIGO&);
    ObjFun& nome(char*);
    ObjFun& autor(char*);

  public:
    // Construtor:
    ObjFun(BYTE = 1, BYTE = 0, unsigned int = 0);

    // Verificaá‰es/retornos:
    BYTE grau() const;
    VERSAO_SIMPLES versao() const;
    CODIGO numero_de_serie() const;
    DATA_SIMPLES data() const;
    void data(BYTE*, BYTE*, unsigned int*) const;
    void versao(BYTE*, BYTE* = NULL, unsigned int* = NULL) const;
    char* nome() const;
    char* autor() const;
};
#else
#error Classe ObjFun Duplicada!
#endif

#endif
