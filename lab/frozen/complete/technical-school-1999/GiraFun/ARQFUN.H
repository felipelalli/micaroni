// Felipe Micaroni Lalli - F&F Fun Ago/1999 - felipe.lalli@sigmabbs.com.br
#ifndef ARQFUN_F&F_FUN
#define ARQFUN_F&F_FUN

///////////////
// INCLUSOES //
///////////////
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////
// DEFINI€åES //
////////////////
// Limites:
#ifndef TAMANHO_DO_NOME_DO_ARQUIVO_ARQFUN
#define TAMANHO_DO_NOME_DO_ARQUIVO_ARQFUN 14
#endif
#ifndef TAMANHO_DO_NOME_DA_VERSAO_ARQFUN
#define TAMANHO_DO_NOME_DA_VERSAO_ARQFUN 8
#endif
#ifndef TAMANHO_DO_MODO_ARQFUN
#define TAMANHO_DO_MODO_ARQFUN 5
#endif
#ifndef TAMANHO_DA_EXTENCAO_ARQFUN
#define TAMANHO_DA_EXTENCAO_ARQFUN 5
#endif
#ifndef BUFFER_ARQFUN
#define BUFFER_ARQFUN 1000000
#endif
// Arquivo tempor rio:
#ifndef NOMETEMP_ARQFUN
#define NOMETEMP_ARQFUN "~arqfun~.tmp"
#endif

// VersÆo:
#ifndef VERSAO_ARQFUN
#define VERSAO_ARQFUN "1.0"
#endif

// Boleanos:
#ifndef VERDADEIRO
#define VERDADEIRO 1
#endif
#ifndef FALSO
#define FALSO 0
#endif
#ifndef INDEFINIDO
#define INDEFINIDO -1
#endif

// Padräes:
#ifndef MODO_PADRAO
#define MODO_PADRAO "ab+"
#endif
#ifndef MODO_LEITURA
#define MODO_LEITURA "r"
#endif
#ifndef MODO_GRAVACAO "ab+"
#define MODO_GRAVACAO
#endif

///////////
// TIPOS //
///////////

#ifndef ARQUIVO
typedef
  FILE* ARQUIVO;
#endif

#ifndef BYTE
typedef
  char BYTE;
#endif

#ifndef BOLEANO
typedef
  unsigned char BOLEANO;
#endif

#ifndef POSICAO
typedef
  fpos_t POSICAO;
#endif

//////////////////////
// CLASSE PRINCIPAL //
//////////////////////
class ArqFun
{
  protected:
    // Guarda o nome do arquivo:
    char cnomearq[TAMANHO_DO_NOME_DO_ARQUIVO_ARQFUN];
    // Guarda as informa‡äes do arquivo:
    FILE* carquivo;
    // Verifica se o arquivo j  est  aberto:
    BOLEANO caberto;
    // Guarda o modo em que o arquivo est  aberto:
    char cmodo[TAMANHO_DO_MODO_ARQFUN]; // Ex.: "ab+"
    // Numero do arquivo (handle)
    int chandle;
    // Se o arquivo ‚ tempor rio
    BOLEANO ctemporario;

  public:
    // Construtores e destrutor:
    ArqFun();
   ~ArqFun();
    ArqFun(const char*, char* = MODO_PADRAO);

    // Abrir/Fechar arquivo:
    BOLEANO abre (const char*, char* = MODO_PADRAO); // Nome e Modo de Abert.
    BOLEANO fecha(); // Fecha o arquivo e o exclui caso seja tempor rio

    // Opera‡äes com o arquivo:
    ArqFun& operator++ (int); // objeto++ -> inca cposicao
    ArqFun& operator++ ();    // ++objeto -> inca cposicao
    ArqFun& operator-- (int); // objeto-- -> deca cposicao
    ArqFun& operator-- ();    // --objeto -> deca cposicao
    ArqFun& operator=  (const char*); // atribui objeto = "nomearq.*"
    // Compara‡äes com a posi‡Æo atual do arquivo:
    BOLEANO operator== (const POSICAO&) const;
    BOLEANO operator>  (const POSICAO&) const;
    BOLEANO operator<  (const POSICAO&) const;
    BOLEANO operator<= (const POSICAO&) const;
    BOLEANO operator>= (const POSICAO&) const;
    // Compara‡Æo byte a byte:
    BOLEANO operator== (const ArqFun&) const;
    BOLEANO operator!= (const ArqFun&) const;
    // Compara com o tamanho do arquivo:
    BOLEANO operator>  (const ArqFun&) const;
    BOLEANO operator<  (const ArqFun&) const;
    BOLEANO operator<= (const ArqFun&) const;
    BOLEANO operator>= (const ArqFun&) const;

    // Verifica‡äes e defini‡äes:
    BOLEANO aberto() const; // Verifica se o arquivo est  aberto
    FILE* arquivo() const; // Retorna o arquivo (carquivo FILE*)
    const char* nome() const; // Retorna um apontador para o nome do arquivo
    const char* extencao() const; // Retorna um apont. p/ a exten‡Æo do arq
    BOLEANO posicao(const POSICAO&); // Modifica a posi‡Æo do cursor no arq
    POSICAO posicao() const; // Retorna a posi‡Æo do cursor atual no arq
    void temporario(const BOLEANO&); // Define se o arquivo ‚ tempor rio
    BOLEANO temporario() const; // Retorna se o arquivo ‚ tempor rio
    BOLEANO eof() const; // Fim de Arquivo (EOF)
    int handle() const; // Devolve o valor handle do arquivo
    POSICAO tamanho() const; // Devolve o tamanho do arquivo

    // Fun‡äes auxiliares:
    BOLEANO compara(BYTE*, BYTE*, const POSICAO&) const;
};

#endif