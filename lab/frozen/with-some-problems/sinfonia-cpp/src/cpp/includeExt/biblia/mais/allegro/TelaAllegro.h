/*
 * $RCSfile: TelaAllegro.h,v $
 * $Date: 2005/01/20 21:29:02 $
 * $Revision: 1.14 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_TELAALLEGRO_H__ABE0FC72_7833_4DA6_8AB7_323CE4FDCB06__INCLUDED_)
#define AFX_TELAALLEGRO_H__ABE0FC72_7833_4DA6_8AB7_323CE4FDCB06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <allegro.h>
#ifdef WIN32
#include <winalleg.h>
#endif

#include "biblia/io/monitor/TelaComFundo.h"
#include "biblia/io/monitor/MonitorExcecao.h"
#include "biblia/mais/MaisExcecao.h"
#include "biblia/mais/allegro/Allegro.h"
#include "biblia/mais/allegro/drs/drs.h"
#include "biblia/visual/cores/Magenta.h"
#include "biblia/fluxo/Semaforo.h"

using namespace biblia::io::monitor;
using namespace biblia::fluxo;

namespace biblia {
  namespace mais {
	namespace allegro {

		class ImagemAllegro; // pois ela usa ele e vice-versa.

		/**
		 * A TelaAllegro utiliza o método DRS
		 * para controlar sua atualização, por isso
		 * é uma TelaComFundo.
		 *
		 * @see biblia::io::monitor::TelaComFundo
		 * @see biblia::io::monitor::Tela
		 */
		class TelaAllegro: public TelaComFundo {
			/*
			 * Friend é usado porque em Java
			 * uma classe do mesmo pacote pode acessar
			 * o protected da outra.
			 */
			friend class Allegro;

			private:
				static long TelaAllegro::instancias;
				Imagem* TelaAllegro::pBuffer;
				Imagem* TelaAllegro::pFundoOriginal;
				ImagemAllegro* TelaAllegro::pFundo;
				bool TelaAllegro::pInicializada;
				Semaforo* TelaAllegro::pLimpa;
				Semaforo* TelaAllegro::pDesenha;

			protected:
				TelaAllegro::TelaAllegro(
						const Tamanho& resolucao);

			public:
				virtual TelaAllegro::~TelaAllegro();
				virtual TelaAllegro& TelaAllegro::sincroniza(bool);

				/* Imagem */
				virtual Imagem& TelaAllegro::cola(
						const Imagem& origem,
						Ponto aonde = Ponto(0, 0),
						Ponto deOnde = Ponto(0, 0),
						Tamanho = Tamanho(0, 0));

				virtual bool TelaAllegro::sabeDesenhar(
						const Geometrico&) const;

				virtual Imagem& TelaAllegro::desenha(
						const Geometrico&);

				virtual Imagem& TelaAllegro::pixel(
						const Ponto&, const Cor&);

				virtual const Cor& TelaAllegro::pixel(
						const Ponto&) const;

				virtual Imagem& TelaAllegro
						::tornaInvisivel(const Cor&);

				virtual Imagem& TelaAllegro
						::tornaOpaca(const Cor&);

				virtual const std::deque<Cor>&
						TelaAllegro::invisiveis() const;

				virtual Imagem& TelaAllegro
						::operator=(const Imagem&);

				/* Tela */
				virtual Tela& TelaAllegro::limpa();
				virtual Tela& TelaAllegro::desenha();
				virtual Tela& TelaAllegro::inicializa();

				virtual Tela& TelaAllegro::finaliza();
				virtual bool TelaAllegro::inicializada() const;

				/* TelaComFundo */
				virtual const Imagem& TelaAllegro
						::fundo() const;

				virtual const bool TelaAllegro
						::fundoDefinido() const;

				virtual const Imagem& TelaAllegro
						::fundoOriginal() const;

				virtual TelaComFundo& TelaAllegro
						::defineFundo(Imagem* fundoOriginal);

				virtual TelaComFundo& TelaAllegro
						::redefineFundo(const Imagem&);

				virtual TelaComFundo& TelaAllegro
						::redefineFundo();

				virtual TelaComFundo& TelaAllegro
						::restauraFundo(Area = Area(
									   Ponto(0, 0),
									   Tamanho(0, 0)));

				virtual TelaComFundo& TelaAllegro
						::mesclaNoFundo(
							const ImagemPosicionada&);
		};
	}
  }
}

#endif // !defined(AFX_TELAALLEGRO_H__ABE0FC72_7833_4DA6_8AB7_323CE4FDCB06__INCLUDED_)
