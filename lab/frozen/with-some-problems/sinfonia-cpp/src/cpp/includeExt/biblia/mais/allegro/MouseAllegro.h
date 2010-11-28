#ifndef BIBLIA_MOUSE_ALLEGRO_AGES_H
#define BIBLIA_MOUSE_ALLEGRO_AGES_H


#include <allegro.h>
#ifdef WIN32
#include <winalleg.h>
#endif

#include "biblia/io/mouse/Mouse.h"
using namespace biblia::io::mouse;


namespace biblia{

	namespace mais{

		namespace allegro{

			class MouseAllegro: public Mouse{

				public:
					MouseAllegro::MouseAllegro();
					MouseAllegro::~MouseAllegro();

					Executavel& MouseAllegro::executa();
			};

		}
	}
}

#endif