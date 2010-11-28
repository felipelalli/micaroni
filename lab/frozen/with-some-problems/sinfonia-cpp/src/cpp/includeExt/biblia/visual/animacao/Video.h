/*
 * $RCSfile: Video.h,v $
 * $Date: 2003/08/19 01:28:20 $
 * $Revision: 1.8 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VIDEO_H__B720600F_4861_4BDA_9701_3F0B2582B668__INCLUDED_)
#define AFX_VIDEO_H__B720600F_4861_4BDA_9701_3F0B2582B668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/Executavel.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Temporizador.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/visual/animacao/AnimacaoDeImagens.h"

using namespace biblia::fluxo;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace visual {
  	namespace animacao {

		/**
		 * Um Video possui uma {@link #animacao() anima��o}
		 * e um {@link #temporizador() const temporizador}.
		 * <p>
		 * O Video j� come�a parado (veja {@link #stop()}
		 * e {@link #parado() const}) e para iniciar
		 * � necess�rio 'pleiar' (veja {@link #play()}).
		 *
		 * @see #executa()
		 */
		class Video: public Executavel,
					 public Objeto
		{
			private:
				AnimacaoDeImagens& Video::pAnimacao;
				Cronometro Video::pCronometro;
				Temporizador* Video::pTemporizador;
				const Video* Video::pSincronizadoCom;

			protected:
				virtual Cronometro& Video::cronometro();
				virtual const Cronometro& Video::cronometro() const;
				virtual Temporizador& Video::temporizador();

			public:
				Video::Video(const Video&);
				Video::Video(AnimacaoDeImagens&,
							 const Intervalo,
							 const UniversoDeTempo&);

				/**
				 * Use isto para opera��es com o fluxo
				 * da anima��o.
				 *
				 * @see #animacao() const
				 */
				virtual AnimacaoDeImagens& Video::animacao();

				/**
				 * Use isto para capturar a imagem atual
				 * do video.
				 *
				 * * @see #animacao()
				 */
				virtual const AnimacaoDeImagens&
						Video::animacao() const;

				/**
				 * Retorna o {@link biblia::tempo::Temporizador}
				 * (somente leitura) que controla este v�deo.
				 * Para opera��o com tempo utilize as fun��es
				 * {@link #play()}, {@link #pause()} e
				 * {@link #stop()}.
				 */
				virtual const Temporizador& Video::temporizador() const;

				/**
				 * Muda o intervalo em tempo de execu��o.
				 */
				virtual Video& Video::mudaIntervalo(const Intervalo);

				virtual Video::~Video();

				/**
				 * Retorna se est� pausado ou "estopado".
				 * @see #pausado()
				 */
				virtual bool Video::parado() const;

				/**
				 * Retorna se est� pausado.
				 * @see #parado()
				 */
				virtual bool Video::pausado() const;

				virtual Video& Video::play();
				virtual Video& Video::pause();
				virtual Video& Video::stop();
				virtual Video& Video::sincronizaCom(const Video&);
				virtual Video& Video::dessincroniza();
				virtual const bool Video::sincronizado() const;

				// Executavel:

				/**
				 * Deve ser chamado de tempo em tempo
				 * para atualizar o frame atual do v�deo.
				 */
				virtual Executavel& Video::executa();
		};
	}
  }
}

#endif // !defined(AFX_VIDEO_H__B720600F_4861_4BDA_9701_3F0B2582B668__INCLUDED_)
