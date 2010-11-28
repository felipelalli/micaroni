/*
 * $RCSfile: VariavelEmArquivo.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_VARIAVELEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
#define AFX_VARIAVELEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/texto/ResolvedorDeNomes.h"
#include "biblia/texto/ResolvedorAlphaNumerico.h"
#include "biblia/armazenamento/eterno/VariavelEterna.h"

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace std;
using namespace biblia::basico;
using namespace biblia::io::disco;
using namespace biblia::seguranca;
using namespace biblia::texto;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
		template<class Tipo> class VariavelEmArquivo
				:public VariavelEterna<Tipo>
		{
			private:
				Arquivo* VariavelEmArquivo<Tipo>::pArquivo;
				bool VariavelEmArquivo<Tipo>::pMudou;
				Tipo VariavelEmArquivo<Tipo>::pConteudo;

				/**
				 * Proibido.
				 */
				VariavelEmArquivo<Tipo>(
						const VariavelEmArquivo<Tipo>&)
					:VariavelEterna<Tipo>("") {}

			protected:
				Arquivo& arquivo() {
					return *(this->pArquivo);
				}

			public:
				static void criaDiretorioBase() {
					if (!ArquivoBasico::existeDiretorio(Constantes::diretorioDat.c_str())) {
						ArquivoBasico::criaDiretorio(Constantes::diretorioDat.c_str());
					}

					if (!ArquivoBasico::existeDiretorio(Constantes::diretorioArqEterno.c_str())) {
						ArquivoBasico::criaDiretorio(Constantes::diretorioArqEterno.c_str());
					}
				}

				static std::string base() {
					return std::string(Constantes::diretorioArqEterno + ".et(");
				}

				VariavelEmArquivo<Tipo>(
						std::string id, Tipo valorInicial = Tipo(),
						ResolvedorDeNomes& r = ResolvedorAlphaNumerico::singleton())
					:VariavelEterna<Tipo>(id),
					 pConteudo(valorInicial),
					 pMudou(false), pArquivo(NULL)
				{
					VariavelEmArquivo<Tipo>::criaDiretorioBase();
					std::string nome = VariavelEmArquivo<Tipo>::base()
							+ r.resolve(std::string(typeid(Tipo).name()))
							+ ")(" + r.resolve(id) + ").dat";

					bool existe = ArquivoBasico
							::existeArquivoBasico(nome.c_str());

					this->pArquivo = new Arquivo(nome, false);

					if (existe) {
						this->restaura();
					} else {
						this->pMudou = true;
						this->executa();
					}
				}

				virtual ~VariavelEmArquivo<Tipo>() {
					this->executa();
					delete this->pArquivo;
				}

				// VariavelEterna:

				/**
				 * Retorna o conteúdo.
				 */
				virtual const Tipo& valor() const {
					return this->pConteudo;
				}

				/**
				 * Retorna o conteúdo para ser modificado.
				 */
				virtual Tipo& pegaValorPraMudar() {
					this->pMudou = true;
					return this->pConteudo;
				}

				/**
				 * É necessário que o Tipo tenha o operador !=
				 */
				virtual VariavelEterna<Tipo>& muda(const Tipo& c) {
					if (c != this->pConteudo) {
						this->pConteudo = Tipo(c);
						this->pMudou = true;
					}

					return *this;
				}

				virtual VariavelEterna<Tipo>& restaura() {
					this->pArquivo->comecaLer();
					this->pArquivo->io() >> this->pConteudo;
					this->pArquivo->terminaLer();
					return *this;
				}

				virtual VariavelEterna<Tipo>& destroi() {
					this->arquivo().fecha();
					ArquivoBasico::apaga(this->arquivo()
							.caminho().c_str());

					return *this;
				}

				// Executavel:
				virtual VariavelEterna<Tipo>& salva() {
					if (this->pMudou) {
						this->pArquivo->comecaEscrever();
						this->pArquivo->io() << this->pConteudo;
						this->pArquivo->terminaEscrever();
					}

					this->pMudou = false;
					return *this;
				}
		};

		// FIXME? copiado hard-coded
		// sempre atualizar quando mudar a classe
		// de cima. :/
		template<> class VariavelEmArquivo<string>
				:public VariavelEterna<string>
		{
			private:
				Arquivo* VariavelEmArquivo<string>::pArquivo;
				bool VariavelEmArquivo<string>::pMudou;
				std::string VariavelEmArquivo<string>::pConteudo;

				/**
				 * Proibido.
				 */
				VariavelEmArquivo<string>(
						const VariavelEmArquivo<string>&)
					:VariavelEterna<string>(""){}

			protected:
				Arquivo& arquivo() {
					return *(this->pArquivo);
				}

			public:
				static void criaDiretorioBase() {
					if (!ArquivoBasico::existeDiretorio(Constantes::diretorioDat.c_str())) {
						ArquivoBasico::criaDiretorio(Constantes::diretorioDat.c_str());
					}

					if (!ArquivoBasico::existeDiretorio(Constantes::diretorioArqEterno.c_str())) {
						ArquivoBasico::criaDiretorio(Constantes::diretorioArqEterno.c_str());
					}
				}

				static std::string base() {
					return std::string(Constantes::diretorioArqEterno + ".et(");
				}

				VariavelEmArquivo<string>(
						std::string id, std::string valorInicial = string(),
						ResolvedorDeNomes& r = ResolvedorAlphaNumerico::singleton())
					:VariavelEterna<string>(id),
					 pConteudo(valorInicial),
					 pMudou(false), pArquivo(NULL)
				{
					VariavelEmArquivo<string>::criaDiretorioBase();
					std::string nome = VariavelEmArquivo<string>::base()
							+ "std::string)(" + r.resolve(id) + ").dat";

					bool existe = ArquivoBasico
							::existeArquivoBasico(nome.c_str());

					this->pArquivo = new Arquivo(nome, false);

					if (existe) {
						this->restaura();
					} else {
						this->pMudou = true;
						this->executa();
					}
				}

				virtual ~VariavelEmArquivo<string>() {
					delete this->pArquivo;
				}

				// VariavelEterna:

				/**
				 * Retorna o conteúdo.
				 */
				virtual const std::string& valor() const {
					return this->pConteudo;
				}

				/**
				 * Retorna o conteúdo para ser modificado.
				 */
				virtual std::string& pegaValorPraMudar() {
					this->pMudou = true;
					return this->pConteudo;
				}

				/**
				 * Muda o valor.
				 */
				virtual VariavelEterna<string>& muda(const std::string& c) {
					if (c != this->pConteudo) {
						this->pConteudo = std::string(c);
						this->pMudou = true;
					}

					return *this;
				}

				virtual VariavelEterna<string>& restaura() {
					this->pArquivo->comecaLer();
					this->pConteudo = "";

					while (!this->pArquivo->fimDeArquivo()) {
						this->pConteudo += this->pArquivo->leLinha();

						if (!this->pArquivo->fimDeArquivo()) {
							this->pConteudo += "\n";
						}
					}

					this->pConteudo = this->pConteudo.substr(
							0, this->pConteudo.size() - 1);

					this->pArquivo->terminaLer();
					return *this;
				}

				virtual VariavelEterna<string>& destroi() {
					this->arquivo().fecha();
					ArquivoBasico::apaga(this->arquivo()
							.caminho().c_str());

					return *this;
				}

				// Executavel:
				virtual VariavelEterna<string>& salva() {
					if (this->pMudou) {
						this->pArquivo->comecaEscrever();
						this->pArquivo->io() << this->pConteudo;
						this->pArquivo->terminaEscrever();
					}

					this->pMudou = false;
					return *this;
				}
		};

	}
  }
}

#endif // !defined(AFX_VARIAVELEMARQUIVO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
