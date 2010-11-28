/**
 * $RCSfile: Principal.cpp,v $
 * $Date: 2005/03/11 22:03:32 $
 * $Revision: 1.9 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#include <biblia/mais/allegro/Allegro.h>
using namespace biblia::mais::allegro;

#include <biblia/basico/Excecao.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/miniaplicacao/MiniAplicacao.h"
using namespace biblia::dinamicas::sinfonia::miniaplicacao;

#include "biblia/dinamicas/sinfonia/demonstracao/Demonstracao.h"
using namespace biblia::dinamicas::sinfonia::demonstracao;

/* CPPDOC_BEGIN_EXCLUDE */
int main(int argc, char *argv[]) {

	Debug::toArquivoBasico("debug.txt", true);
#ifdef _DEBUG
	Debug::setNivel(INFO);
#else
	Debug::setNivel(WARN);
#endif

	try {
		Debug::msg(ERRO, "Iniciou o programa.");

		delete (MiniAplicacao*) &(new MiniAplicacao())->executa();

		Debug::msg(ERRO, "Finalizou o programa.");
		return 0;
	} catch (const Excecao& e) {
		Debug::msg(ERRO, string()
			+ "Principal:: A Exce��o " + typeid(e).name()
			+ " foi lan�ada: " + e);
	} catch (const exception& e) {
		Debug::msg(ERRO, string()
			+ "Principal:: Uma exception " + typeid(e).name()
			+ " foi lan�ada: " + e.what());
	} //catch (...) {
	//	Debug::msg(ERRO, "Principal:: Uma exce��o desconhecida foi lan�ada!");
	//}

	return 56;

} END_OF_MAIN();
/* CPPDOC_END_EXCLUDE */
