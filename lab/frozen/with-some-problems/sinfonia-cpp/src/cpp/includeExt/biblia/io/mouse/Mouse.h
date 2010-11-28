#ifndef AGES_BIBLIA_IO_MOUSE_H
#define AGES_BIBLIA_IO_MOUSE_H


#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;


namespace biblia{

	namespace io{

		namespace mouse{

			class Mouse: public Executavel{

				protected:
										
					//EVENTOS
					bool pMoveuMouse;
					bool pMoveuRodinha;

					bool pPressionouBotaoEsquerdo;
					bool pLiberouBotaoEsquerdo;

					bool pPressionouBotaoCentral;
					bool pLiberouBotaoCentral;

					bool pPressionouBotaoDireito;
					bool pLiberouBotaoDireito;


					//ESTADOS
					int  pPosX;
					int  pPosY;
					int  pPosicaoRodinha;
					bool pBotaoEsquerdo;
					bool pBotaoDireito;
					bool pBotaoCentral;

					

				public:
					Mouse::Mouse();
					virtual Mouse::~Mouse();

					//EVENTOS
					bool Mouse::moveuMouse();					
					bool Mouse::moveuRodinha();

					bool Mouse::pressionouBotaoEsquerdo();
					bool Mouse::liberouBotaoEsquerdo();

					bool Mouse::pressionouBotaoCentral();
					bool Mouse::liberouBotaoCentral();

					bool Mouse::pressionouBotaoDireito();
					bool Mouse::liberouBotaoDireito();


					//ESTADOS
					int  Mouse::posX();
					int  Mouse::posY();
					int  Mouse::posicaoRodinha();
					bool Mouse::botaoEsquerdoPressionado();
					bool Mouse::botaoCentralPressionado();
					bool Mouse::botaoDireitoPressionado();					
										
					

					void Mouse::limpa();
					virtual Executavel& Mouse::executa()=0;
			};

		}
	}
}

#endif
