/*
 * $RCSfile: InformacaoRestrita.h,v $
 * $Date: 2005/01/20 21:28:35 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * InformaçãoRestrita explicita
		 * o Universo a que pertence através
		 * de gabarito.
		 * <p>
		 * É útil quando usado para receber
		 * parâmetros em funções que necessitam
		 * de algum tipo de restrição no parâmetro.
		 * <p>
		 * Usado assim:
		 * <code>InformacaoRestrita<ClassePrincipal,
		 *       ClasseDoUniverso></code>
		 * onde ClassePrincipal é alguma classe
		 * que deriva de Informacao representando
		 * o tipo do valor que esta InformacaoRestrita
		 * guardará. E ClasseDoUniverso é algum Universo
		 * com construtor padrão que restd::stringe uma gama
		 * de informações. Se a CLasseDoUniverso for omitida,
		 * por padrão se define que o Universo é "Todos". O
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
							+ " herdam de Informação. A classe"
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
							+ ". É importante também que a classe"
							+ " tenha um construtor padrão. Caso"
							+ " ela necessite de parâmetros, use"
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

							// isso foi necessário porque
							// quando se lança exceção no
							// construtor o destrutor não
							// é executado.
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
