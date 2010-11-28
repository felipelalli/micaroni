#ifndef USUARIO_H
#define USUARIO_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/seguranca/util/TipoUsuario.h"
#include "biblia/seguranca/util/ArqUsuario.h"
using namespace biblia::seguranca::util;


namespace biblia{
	
	namespace seguranca{


		class Usuario: public Objeto{

			private:

				ChaveSeguranca* pChaveSeguranca;
				
				ArqUsuario* pArqUsuario;
				biblia::armazenamento::volatil::Lista* pUsuarios;
				TipoUsuario* pUsuarioInvalido;

			public:

				Usuario::Usuario(ChaveSeguranca* chaveSeguranca);
				Usuario::~Usuario();

				void Usuario::carrega();

				bool Usuario::entrarSenha (const char* qualUsuario,long senha);
				bool Usuario::entrarSenha (int qualUsuario,long senha);		
				const TipoUsuario& Usuario::logarUsuario(long senha)const;
				
				
				const int Usuario::quantosUsuarios()const;
				const TipoUsuario& Usuario::tipoUsuario(int qualUsuario) const ;
				
				const biblia::armazenamento::volatil::Lista& Usuario::usuarios() const;
				
		};
	}
}
#endif

