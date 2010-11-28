/**
 * $RCSfile: TecladoAllegro.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.8 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_TECLADOALLEGRO_H__5B829E55_F563_4A44_86B0_F39CD67CB8E0__INCLUDED_)
#define AFX_TECLADOALLEGRO_H__5B829E55_F563_4A44_86B0_F39CD67CB8E0__INCLUDED_

#include <allegro/keyboard.h>

#include <biblia/fluxo/Thread.h>
#include <biblia/fluxo/Semaforo.h>
#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include <biblia/tempo/Intervalo.h>
#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/tempo/unidades/Milissegundo.h>
using namespace biblia::tempo::unidades;

#include <biblia/armazenamento/volatil/primitivos/Inteiro.h>
using namespace biblia::armazenamento::volatil::primitivos;

#include "biblia/dinamicas/sinfonia/ModificadorDeEstado.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventosBloqueavel.h"
using namespace biblia::dinamicas::sinfonia;

#include "biblia/dinamicas/sinfonia/util/Lock.h"
using namespace biblia::dinamicas::sinfonia::util;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/* CPPDOC_BEGIN_EXCLUDE */
	void evento_tecla(int scancode);
	/* CPPDOC_END_EXCLUDE */

	/**
	 * Gera eventos especiais para modificar estados
	 * relativos a cada tecla, quando ela é solta ou pressionada.
	 * <p>
	 * Cada tecla deve ser declarada
	 * como um estado separadamente nas definições dos estados
	 * da {@link Sinfonia}, seguindo as seguintes regras:
	 * <br>devem pertencer ao grupo <b>Sinfonia.Reservados.Teclas.</b>
	 * e conter o seguinte nome: <b>tecla</b> seguido pelo número
	 * da tecla correspondente na lista abaixo, como por exemplo:
	 * "<b>tecla9</b>" (I), "<b>tecla56</b>" (F10) etc.
	 * <p>
	 * Além do Evento que modifica a tecla específica, será lançado
	 * também um Evento que modifica o estado
	 * "<b>Sinfonia.Reservados.Teclas.ultima tecla pressionada</b>"
	 * (para qualquer tecla que for pressionada) e
	 * "<b>Sinfonia.Reservados.Teclas.ultima tecla solta</b>"
	 * (para qualquer tecla que for solta). O Estado
	 * "<b>Sinfonia.Reservados.Teclas.ultima tecla ascii</b>" guardará
	 * a última tecla ASCII que foi pressionada.
	 * <p>
	 * Sempre que for possível, utilize o estado
	 * "<b>Sinfonia.Reservados.Teclas.ultima tecla ascii</b>" porque
	 * ele utiliza o "keypress" e "readkey" que são subordinados
	 * ao sistema. Por exemplo: se for pressionado a tecla "~" e depois
	 * "a" o estado <b>ultima tecla ascii</b> só será modificado após
	 * ser pressionado a tecla "a", e o resultado será "ã", diferente
	 * dos outros estados que são modificados instantaneamente quando
	 * qualquer tecla for pressionada.
	 * <p>
	 * Todos os
	 * estados usados devem estar previamente definidos na {@link Sinfonia}.
	 * Se alguma tecla for pressionada ou solta e seu estado não estiver
	 * previamente definido ou associado a algum acontecimento,
	 * o evento será ignorado.
	 * <p>
	 * Esta classe é um GeradorDeEventosBloqueavel, i. e., a cada
	 * evento lançado para fora ela é bloqueada até que seja desbloqueada.
	 * Para desbloqueá-la e receber o próximo evento basta lançar um
	 * evento com o nome definido em {@link #ESTADO_DE_BLOQUEIO}
	 * (Sinfonia.Reservados.Teclas.bloqueado) passando Valor(false)
	 * como parâmetro no campo principal.
	 * <p>
	 * <b><font size=+1>Índice das Teclas</font></b><pre>
KEY_A                 1
KEY_B                 2
KEY_C                 3
KEY_D                 4
KEY_E                 5
KEY_F                 6
KEY_G                 7
KEY_H                 8
KEY_I                 9
KEY_J                 10
KEY_K                 11
KEY_L                 12
KEY_M                 13
KEY_N                 14
KEY_O                 15
KEY_P                 16
KEY_Q                 17
KEY_R                 18
KEY_S                 19
KEY_T                 20
KEY_U                 21
KEY_V                 22
KEY_W                 23
KEY_X                 24
KEY_Y                 25
KEY_Z                 26
KEY_0                 27
KEY_1                 28
KEY_2                 29
KEY_3                 30
KEY_4                 31
KEY_5                 32
KEY_6                 33
KEY_7                 34
KEY_8                 35
KEY_9                 36
KEY_0_PAD             37
KEY_1_PAD             38
KEY_2_PAD             39
KEY_3_PAD             40
KEY_4_PAD             41
KEY_5_PAD             42
KEY_6_PAD             43
KEY_7_PAD             44
KEY_8_PAD             45
KEY_9_PAD             46
KEY_F1                47
KEY_F2                48
KEY_F3                49
KEY_F4                50
KEY_F5                51
KEY_F6                52
KEY_F7                53
KEY_F8                54
KEY_F9                55
KEY_F10               56
KEY_F11               57
KEY_F12               58
KEY_ESC               59
KEY_TILDE             60
KEY_MINUS             61
KEY_EQUALS            62
KEY_BACKSPACE         63
KEY_TAB               64
KEY_OPENBRACE         65
KEY_CLOSEBRACE        66
KEY_ENTER             67
KEY_COLON             68
KEY_QUOTE             69
KEY_BACKSLASH         70
KEY_BACKSLASH2        71
KEY_COMMA             72
KEY_STOP              73
KEY_SLASH             74
KEY_SPACE             75
KEY_INSERT            76
KEY_DEL               77
KEY_HOME              78
KEY_END               79
KEY_PGUP              80
KEY_PGDN              81
KEY_LEFT              82
KEY_RIGHT             83
KEY_UP                84
KEY_DOWN              85
KEY_SLASH_PAD         86
KEY_ASTERISK          87
KEY_MINUS_PAD         88
KEY_PLUS_PAD          89
KEY_DEL_PAD           90
KEY_ENTER_PAD         91
KEY_PRTSCR            92
KEY_PAUSE             93
KEY_ABNT_C1           94
KEY_YEN               95
KEY_KANA              96
KEY_CONVERT           97
KEY_NOCONVERT         98
KEY_AT                99
KEY_CIRCUMFLEX        100
KEY_COLON2            101
KEY_KANJI             102

KEY_MODIFIERS         103

KEY_LSHIFT            103
KEY_RSHIFT            104
KEY_LCONTROL          105
KEY_RCONTROL          106
KEY_ALT               107
KEY_ALTGR             108
KEY_LWIN              109
KEY_RWIN              110
KEY_MENU              111
KEY_SCRLOCK           112
KEY_NUMLOCK           113
KEY_CAPSLOCK          114
     * </pre>
	 *
	 * @see Evento
	 */
	class TecladoAllegro: public GeradorDeEventosBloqueavel {
		friend void evento_tecla(int scancode);
		
		private:
			static TecladoAllegro* singleton;
			static UniversoDeTempo* pTempo;

			bool pLiga;
			bool pAcabou;
			Semaforo pEsperaAcabar;

		protected:
			/**
			 * Use {@link #unicaInstancia} ao invés desse
			 * construtor.
			 */
			TecladoAllegro(const MediadorDeEstados&);

			class CapturaUltimaTeclaASCII:public Executavel {
				private:
					TecladoAllegro* pTA;

				public:
					CapturaUltimaTeclaASCII(TecladoAllegro*);

					// Executavel:
					Executavel& executa();
			};

		public:
			/**
			 * Define "Sinfonia.Reservados.Teclas.bloqueado"
			 */
			static Valor ESTADO_DE_BLOQUEIO;

			virtual ~TecladoAllegro();

			/**
			 * Deve ser deletado uma única vez durante
			 * toda a aplicação.
			 */
			static TecladoAllegro* criaTecladoAllegro(
					const MediadorDeEstados&, const UniversoDeTempo&);

			/**
			 * Só pode ser chamado depois de ser defindo
			 * pela função {@link #criaTecladoAllegro}.
			 */
			static TecladoAllegro* unicaInstancia();

			static const UniversoDeTempo& tempo();

			/**
			 * Verifica se este TecladoAllegro está
			 * executando.
			 */
			virtual const bool& ligado() const;

			// GeradorDeEventos:
			/**
			 * Deve ser executado em Thread uma única vez.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop();
	};
   }
  }
 }
}

#endif // !defined(AFX_TECLADOALLEGRO_H__5B829E55_F563_4A44_86B0_F39CD67CB8E0__INCLUDED_)
