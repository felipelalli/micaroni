/*
 * $RCSfile: InformacaoRestrita.h,v $
 * $Date: 2005/01/20 21:28:35 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_INFORMACAORESTRITA_H__21A38176_E8D6_4A14_B55D_73396D3141EA__INCLUDED_)
#define AFX_INFORMACAORESTRITA_H__21A38176_E8D6_4A14_B55D_73396D3141EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/volatil/Universo.h"
#include "biblia/armazenamento/volatil/VolatilExcecao.h"

namespace biblia {
  namespace armazenamento {
	namespace volatil {
		/**
		 * Informa��oRestrita explicita
		 * o Universo a que pertence atrav�s
		 * de gabarito.
		 * <p>
		 * � �til quando usado para receber
		 * par�metros em fun��es que necessitam
		 * de algum tipo de restri��o no par�metro.
		 * <p>
		 * Usado assim:
		 * <code>InformacaoRestrita<ClassePrincipal,
		 *       ClasseDoUniverso></code>
		 * onde ClassePrincipal � alguma classe
		 * que deriva de Informacao representando
		 * o tipo do valor que esta InformacaoRestrita
		 * guardar�. E ClasseDoUniverso � algum Universo
		 * com construtor padr�o que restd::stringe uma gama
		 * de informa��es. Se a CLasseDoUniverso for omitida,
		 * por padr�o se define que o Universo � "Todos". O
		 * Universo todos aceita qualquer Informacao.
		 *
		 * @see Informacao
		 * @see Universo
		 */
		template<class ClassePrincipal,
				 class ClasseDoUniverso = Todos>
			   class InformacaoRestrita
			:public Objeto
		{
			private:
				ClasseDoUniverso* InformacaoRestrita::pUniverso;
				const ClassePrincipal* InformacaoRestrita::pInfo;

			public:
				InformacaoRestrita<ClassePrincipal, ClasseDoUniverso>(
					const ClassePrincipal& info)
						:pUniverso(NULL), pInfo(NULL)
				{
					try {
						this->pInfo = (const ClassePrincipal*)
							dynamic_cast<const Informacao*>(&info);
					} catch (...) {
						InformacaoInvalidaExcecao e;
						e << std::string() + "InformacaoRestrita<ClassePrincipal,"
							+ "ClasseDoUniverso>("
							+ "Informacao* info)::"
							+ " Use apenas classes que"
							+ " herdam de Informa��o. A classe"
							+ " usada foi " + std::string(
								typeid(ClassePrincipal).name());

						throw e;
					}

					try {
						this->pUniverso
								= (ClasseDoUniverso*)
									dynamic_cast<Universo*>(
										NOVO ClasseDoUniverso());
					} catch (...) {
						UniversoInvalidoExcecao e;
						e << std::string() + "InformacaoRestrita<ClasseP"
							+ "rincipal, ClasseDoUniverso>("
							+ "Informacao* info)::"
							+ " Use apenas classes que"
							+ " herdam de Universo. A classe"
							+ " usada foi " + std::string(typeid(
									ClasseDoUniverso).name())
							+ ". � importante tamb�m que a classe"
							+ " tenha um construtor padr�o. Caso"
							+ " ela necessite de par�metros, use"
							+ " template.";

						throw e;
					}

					this->valida();
				}

				/**
				 * @see Universo::valida(const Informacao&)
				 */
				virtual const InformacaoRestrita<ClassePrincipal,
						ClasseDoUniverso>& valida() const
				{
					try {
						this->pUniverso->valida(*this->pInfo);
					} catch(ForaDoUniversoExcecao e) {
						if (this->pUniverso) {
							delete this->pUniverso;
							const_cast<InformacaoRestrita*>
									(this)->pUniverso = NULL;

							// isso foi necess�rio porque
							// quando se lan�a exce��o no
							// construtor o destrutor n�o
							// � executado.
						}

						throw e;
					}

					return *this;
				}

				virtual ~InformacaoRestrita<ClassePrincipal,
						ClasseDoUniverso>()
				{
					if (this->pUniverso) {
						delete this->pUniverso;
					}
				};

				virtual const ClassePrincipal& informacao() const {
					return *(this->pInfo);
				}
		};
	}
  }
}

#endif // !defined(AFX_INFORMACAORESTRITA_H__21A38176_E8D6_4A14_B55D_73396D3141EA__INCLUDED_)
