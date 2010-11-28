/**
 * $RCSfile: ScriptDinamica.h,v $
 * $Date: 2005/03/04 07:38:18 $
 * $Revision: 1.24 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_SCRIPTDINAMICA_H__C77D642D_870E_47CA_A896_F980F0711069__INCLUDED_)
#define AFX_SCRIPTDINAMICA_H__C77D642D_870E_47CA_A896_F980F0711069__INCLUDED_

#include "biblia/dinamicas/sinfonia/gde/Timer.h"
#include "biblia/dinamicas/sinfonia/gde/Animacao.h"
#include "biblia/dinamicas/sinfonia/gde/Som.h"
#include "biblia/dinamicas/sinfonia/gde/MouseBiblia.h"
#include "biblia/dinamicas/sinfonia/gde/AreaClicavel.h"
using namespace biblia::dinamicas::sinfonia::gde;

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/fluxo/Executavel.h>
#include <biblia/fluxo/Conclusivo.h>
using namespace biblia::fluxo;

#include <biblia/armazenamento/volatil/xml/NoXML.h>
#include <biblia/armazenamento/volatil/xml/GrupoXML.h>
#include <biblia/armazenamento/volatil/xml/CampoValor.h>
#include <biblia/armazenamento/volatil/xml/GrupoNo.h>
#include <biblia/armazenamento/volatil/xml/ArquivoXML.h>
using namespace biblia::armazenamento::volatil::xml;

#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include <biblia/mais/xerces/NoXMLXerces.h>
#include <biblia/mais/xerces/ArquivoXMLXerces.h>
using namespace biblia::mais::xerces;

#include <biblia/io/som/ResultadoSonoro.h>
#include <biblia/io/som/CarregadorDeSom.h>
using namespace biblia::io::som;

#include "biblia/dinamicas/sinfonia/Genesis.h"
#include "biblia/dinamicas/sinfonia/EstadoDependente.h"
#include "biblia/dinamicas/sinfonia/CondicaoImpl.h"
#include "biblia/dinamicas/sinfonia/CondicaoComposta.h"
#include "biblia/dinamicas/sinfonia/CondicaoModificadora.h"
#include "biblia/dinamicas/sinfonia/CondicaoDeComparacao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Gera uma Sinfonia definindo os estados e dinâmica a partir de
	 * um arquivo XML gerado pelo software auxiliar <code>SinfoniaScripCreator</code>.
	 * Consulte a documentação específica desse software para mais detalhes
	 * de como gerar esse arquivo.
	 *
	 * @see Genesis
	 * @see Sinfonia
	 * @see Estado
	 * @see GeradorDeEventosDependente
	 */
	class ScriptDinamica: public Genesis {
		private:
			const UniversoDeTempo& pTempo;
			ResultadoSonoro& pResultadoSonoro;
			CarregadorDeSom& pCarregadorDeSom;
			BasicoVisual& pVisual;
			Sinfonia* pSinfonia;
			string pArquivo;
			Lista<string> pGrupo;
			MapaHash<Evento*> pEventos;
			MapaHash<string> pAtributo;
			MapaHash<string> pParametro;
			MapaHash<Estado*> pEstados;
			MapaHash<Estado*> pEstadosAtuais;
			Lixeira pLixoEventosTemporarios;
			bool pRecarregando;

			virtual bool carregaEstados(string arquivo);
			virtual void percorreGruposParaEstados(NoXML* no);
			virtual void percorreGruposParaEventos(NoXML* no);
			virtual void percorreGruposParaDinamica(NoXML* no);

			/** o retorno não deve ser deletado externamente */
			virtual Estado* carregaEstadoDependente(NoXML* noEstado,
					string& atributoParaAtualizar, string& nomeParaAtualizar);

			/** o retorno deve ser deletado externamente */
			virtual Condicao* carregaCondicao(NoXML* noCondicao,
									  Lista<string>& estadosRelacionados,
									  string nomeDaSituacao);

			virtual const string grupo() const;

		protected:
			virtual const Sinfonia& sinfonia() const;
			virtual Sinfonia& sinfonia();

		public:
			/**
			 * Deve ser passado uma Sinfonia pré-criada.
			 */
			ScriptDinamica(const string& caminhoDoArquivo, 
						   BasicoVisual&,
						   ResultadoSonoro& resultadoSonoro,
						   CarregadorDeSom& carregadorDeSom);

			virtual ~ScriptDinamica();

			// Genesis:
			/**
			 * Inicia todo o processo de leitura
			 * do arquivo.
			 */
			virtual Sinfonia* geraSinfonia();

			/**
			 * @see Genesis#recarrega
			 */
			virtual Genesis& recarrega(Sinfonia*);
	};
  }
 }
}

#endif // !defined(AFX_SCRIPTDINAMICA_H__C77D642D_870E_47CA_A896_F980F0711069__INCLUDED_)
