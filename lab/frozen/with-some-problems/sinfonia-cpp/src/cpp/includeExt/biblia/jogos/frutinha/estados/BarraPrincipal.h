/*
 * $RCSfile: BarraPrincipal.h,v $
 * $Date: 2004/07/01 21:11:28 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef BARRA_PRINCIPAL_TROPCIAL_H
#define BARRA_PRINCIPAL_TROPCIAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Subidor.h"
using namespace biblia::util;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class BarraPrincipal : public Objeto{
					private:
						double pValorMaximoAcumulado;
						double pValorMinimoAcumulado;
						double pValorInicialAcumulado;
						int    pApostaMinimaConcorreAcumulado;

						int pPremio;
						VariavelEmArquivo<int> pCreditos;
						VariavelEmArquivo<int> pCreditosAtual;
						VariavelEmArquivo<int> pAposta;
						VariavelEmArquivo<double> pAcumulado;
						VariavelEmArquivo<bool> pVisivel;
						bool pCreditosInsuficientes;

						Subidor pSubidor;

						void BarraPrincipal::pSalvar();

					public:
						BarraPrincipal::BarraPrincipal();
						virtual BarraPrincipal::~BarraPrincipal();

						virtual BarraPrincipal& BarraPrincipal::setCreditos (int    creditos);
						virtual BarraPrincipal& BarraPrincipal::setCreditosAtual (int    creditos);
						virtual BarraPrincipal& BarraPrincipal::setAposta   (int    aposta);
						virtual BarraPrincipal& BarraPrincipal::setPremio   (int    aposta);
						virtual BarraPrincipal& BarraPrincipal::setAcumulado(double acumulado);
						virtual BarraPrincipal& BarraPrincipal::addAcumulado(double acumulado);

						virtual BarraPrincipal& BarraPrincipal::visivel (bool visivel);
						virtual BarraPrincipal& BarraPrincipal::normalizaCreditos();
						virtual BarraPrincipal& BarraPrincipal::deuCreditosInsuficientes();

						/**
						 * Créditos real / final.
						 */
						virtual const int& BarraPrincipal::creditos () const;

						/**
						 * Créditos que sobe, que aparecerá na tela.
						 */
						virtual const int& BarraPrincipal::creditosAtual () const;
						virtual const bool BarraPrincipal::consomeCreditosInsuficientes();

						virtual const int& BarraPrincipal::aposta   () const;
						virtual const int& BarraPrincipal::premio   () const;
						virtual const double& BarraPrincipal::acumulado() const;
						virtual double BarraPrincipal::acumuladoSubindo();
						virtual const bool& BarraPrincipal::visivel() const;

						virtual const double& BarraPrincipal::valorInicialAcumulado() const;
						virtual const double& BarraPrincipal::valorMinimoAcumulado() const;
						virtual const double& BarraPrincipal::valorMaximoAcumulado() const;

						virtual void BarraPrincipal::setValorInicialAcumulado(double valor);
						virtual void BarraPrincipal::setValorMinimoAcumulado(double valor);
						virtual void BarraPrincipal::setValorMaximoAcumulado(double valor);

						virtual const bool BarraPrincipal::concorreAcumulado (int aposta) const;
						virtual const bool BarraPrincipal::estaCreditando() const;
				};			
			}
		}
	}
}

#endif