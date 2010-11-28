/*
 * $RCSfile: DadosXML.h,v $
 * $Date: 2004/07/13 21:13:33 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DADOS_XML
#define DADOS_XML

#include <stdlib.h>
#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/superbonus/dados/Dados.h"

#define PRECISAO_PADRAO_SW 8

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class DadosXML:public Objeto {

			private:
				Dados* DadosXML::pDados;

			public:
				DadosXML::DadosXML(Dados* = NULL);
				virtual DadosXML::~DadosXML();
				DadosXML& DadosXML::define(Dados*);

				Dados& DadosXML::dados();

				virtual bool DadosXML::leString(const char* caminho,char* buffer);
				virtual int DadosXML::leInt(const char* caminho);
				virtual long DadosXML::leLong(const char* caminho);
				virtual double DadosXML::leDouble(const char* caminho);
				virtual biblia::armazenamento::volatil::Lista* DadosXML::leLista(const char* caminho);

				virtual DadosXML& DadosXML::limitaPor(
						const char* caminho, int quantosRegistros);

				virtual DadosXML& DadosXML::grava(const char* caminho, biblia::armazenamento::volatil::Lista* oQue);
				virtual DadosXML& DadosXML::grava(const char* caminho, char* oQue);
				virtual DadosXML& DadosXML::grava(const char* caminho, const int oQue);
				virtual DadosXML& DadosXML::grava(const char* caminho, const long oQue);
				virtual DadosXML& DadosXML::grava(const char* caminho, const double oQue,
			        				  int precisao = PRECISAO_PADRAO_SW);

				virtual DadosXML& DadosXML::adiciona(const char* caminho, biblia::armazenamento::volatil::Lista* lista) {
					//char debug[200];
					biblia::armazenamento::volatil::Lista* resultado = this->leLista(caminho);

					for (int i = 0; i < lista->size(); i++) {
						char* novo = (char*) malloc(sizeof(char) * 5000);
						strcpy(novo, (char*) (*lista)[i]);
						resultado->add(novo);

					//	sprintf(debug, "leu: lista[%d]=`%s'",
					//		i, (char*)(*lista)[i]);

					}
					this->grava(caminho, resultado);

					for (int j = 0; j < resultado->size(); j++) {
						free((*resultado)[j]);
					}


					delete resultado;


					return *this;
				}

				virtual int DadosXML::incInt(const char* caminho, int quanto = 1) {
					int resultado = this->leInt(caminho) + quanto;
					this->grava(caminho, resultado);
					return resultado;
				}

				virtual int DadosXML::decInt(const char* caminho, int quanto = 1) {
					int resultado = this->leInt(caminho) - quanto;
					this->grava(caminho, resultado);
					return resultado;
				}

				virtual long DadosXML::incLong(const char* caminho, long quanto = 1L) {
					long resultado = this->leLong(caminho) + quanto;
					this->grava(caminho, resultado);
					return resultado;
				}

				virtual long DadosXML::decLong(const char* caminho, long quanto = 1L) {
					long resultado = this->leLong(caminho) - quanto;
					this->grava(caminho, resultado);
					return resultado;
				}

				virtual double DadosXML::incDouble(const char* caminho, double quanto = 1.0) {
					double resultado = this->leDouble(caminho) + quanto;
					this->grava(caminho, resultado);
					return resultado;
				}

				virtual double DadosXML::decDouble(const char* caminho, double quanto = 1.0) {
					double resultado = this->leDouble(caminho) - quanto;
					this->grava(caminho, resultado);
					return resultado;
				}
		};
	  }
	}
  }
}

#endif
