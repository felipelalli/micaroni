/**
 * $RCSfile: Rotulado.h,v $
 * $Date: 2005/03/17 01:18:09 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_ROTULADO_H__397ECDDC_43DB_4A0C_BCE6_34E012BE03D4__INCLUDED_)
#define AFX_ROTULADO_H__397ECDDC_43DB_4A0C_BCE6_34E012BE03D4__INCLUDED_

#include <string>
using namespace std;

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Valor.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Tudo que possui uma identifica��o, um nome.
	 * <p>
	 * Por geralmente estar associado a algo
	 * que tem um valor sem�ntico complexo,
	 * pode possuir tamb�m um coment�rio.
	 */
	class Rotulado: public Objeto {
		private:
			Valor pNome;
			string pComentario;

		protected:
			Rotulado(const Valor& nome);

		public:
			virtual ~Rotulado();

			/**
			 * Muda o nome deste Rotulado.
			 */
			virtual Rotulado& mudaNome(const Valor& nome);

			/**
			 * Nome deste Rotulado.
			 */
			virtual const Valor& nome() const;

			/**
			 * Retorna o coment�rio deste Rotulado.
			 */
			virtual const string& comentario() const;

			/**
			 * Define um novo coment�rio para este Rotulado.
			 */
			virtual Rotulado& defineComentario(const string&);

			// Objeto:
			/**
			 * Retorna o nome e seu coment�rio.
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_ROTULADO_H__397ECDDC_43DB_4A0C_BCE6_34E012BE03D4__INCLUDED_)
