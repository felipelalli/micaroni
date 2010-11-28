/*
 * $RCSfile: TipoUsuario.h,v $
 * $Date: 2004/04/21 02:00:05 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/Criptografia.h"
using namespace biblia::seguranca;

namespace biblia{

	namespace seguranca{

		namespace util{

			class TipoUsuario{

				private:

					ChaveSeguranca* pChaveSeguranca;

					long pSenha;
					biblia::armazenamento::volatil::Lista* pPermissoes;
					char pNomeUsuario[200];

					int pCodigoRecuperacao;

				public:
					TipoUsuario(ChaveSeguranca* chaveSeguranca,long senha, const biblia::armazenamento::volatil::Lista& permissoes,const char* nomeUsuario);
					TipoUsuario(const TipoUsuario&);

					~TipoUsuario();

					/*indica se o usuario tem permissao para uma determinada opção do menu*/
					bool temPermissao(int qualOpcao)const;
					/*verifica se a senha passada com parâmetro está correta*/
					bool senhaCorreta(long)const;
					/*retorna a senha do usuário*/
					long senha()const;
					/*altera a senha do usuário*/
					void alteraSenha(long senha);
					/*Eh considerado usuário inválido aquele que possuir a Lista de permissoes vazia*/
					bool invalido()const;
					bool ehUsuario(const char* nomeUsuario) const;
					const char* usuario() const;

					void TipoUsuario::codigoRecuperacao(char** buffer,int* tamanho);
					bool TipoUsuario::codigoCorreto (const char* codigo);

					int TipoUsuario::qtsPermissoes() const {return this->pPermissoes->size();}
			};
		}
	}
}

#endif