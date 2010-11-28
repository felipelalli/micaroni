/*
 * $RCSfile: VariavelEmArquivoResultadoGrafico.h,v $
 * $Date: 2005/01/20 21:29:47 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_VARIAVELEMARQUIVORESULTADOGRAFICO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
#define AFX_VARIAVELEMARQUIVORESULTADOGRAFICO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/visual/util/ComponenteFixo.h"
using namespace biblia::visual::util;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
		// FIXME? copiado hard-coded
		// sempre atualizar quando mudar a classe
		// VariavelEmArquivo. :/
		template<> class VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >
				:public VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >
		{
			private:
				Arquivo* VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >::pArquivo;
				bool VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >::pMudou;
				biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >::pConteudo;

				/**
				 * Proibido.
				 */
				VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >(
						const VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >&)
					:VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >(""){}

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

				VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >(
						std::string id, biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> valorInicial = biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>(),
						ResolvedorDeNomes& r = ResolvedorAlphaNumerico::singleton())
					:VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >(id),
					 pConteudo(valorInicial),
					 pMudou(false), pArquivo(NULL)
				{
					VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >::criaDiretorioBase();
					std::string nome = VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >::base()
							+ "ResultadoGrafico)(" + r.resolve(id) + ").dat";

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

				virtual ~VariavelEmArquivo<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >() {
					delete this->pArquivo;
				}

				// VariavelEterna:

				/**
				 * Retorna o conteúdo.
				 */
				virtual const biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>& valor() const {
					return this->pConteudo;
				}

				/**
				 * Retorna o conteúdo para ser modificado.
				 */
				virtual biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>& pegaValorPraMudar() {
					this->pMudou = true;
					return this->pConteudo;
				}

				/**
				 * Muda o valor.
				 */
				virtual VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >& muda(
						const biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo>& c)
				{
					this->pConteudo.limpa();
					for (int i = 0; i < c.tamanho(); i++) {
						this->pConteudo.adiciona(c[i]);
					}

					this->pMudou = true;

					return *this;
				}

				virtual VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >& restaura() {
					this->pArquivo->comecaLer();
					this->pConteudo.limpa();

					while (!this->pArquivo->fimDeArquivo()) {
						std::string linha = this->pArquivo->leLinha();

						if (!this->pArquivo->fimDeArquivo()) {
							if (linha.size() > 0) {
								this->pConteudo.adiciona(ComponenteFixo(linha));
							}
						}
					}

					this->pArquivo->terminaLer();
					return *this;
				}

				virtual VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >& destroi() {
					this->arquivo().fecha();
					ArquivoBasico::apaga(this->arquivo()
							.caminho().c_str());

					return *this;
				}

				// Executavel:
				virtual VariavelEterna<biblia::armazenamento::volatil::carcacas::Lista<ComponenteFixo> >& salva() {
					if (this->pMudou) {
						this->pArquivo->comecaEscrever();
						for (int i = 0; i < this->pConteudo.tamanho(); i++) {
							this->pArquivo->io() << this->pConteudo[i]
									.emString() + "\n";
						}

						this->pArquivo->terminaEscrever();
					}

					this->pMudou = false;
					return *this;
				}
		};
	}
  }
}

#endif // !defined(AFX_VARIAVELEMARQUIVORESULTADOGRAFICO_H__2EC83409_E4C3_42FE_92B6_154CE2EE6883__INCLUDED_)
