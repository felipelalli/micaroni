/*
 * $RCSfile: Interface.h,v $
 * $Date: 2004/03/30 21:09:21 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#pragma warning(disable:4290) // SLTport: C++ Exception Specification ignored
#endif

#if !defined(AFX_INTERFACE_H__29907CBE_5C33_44DA_8186_9C0F14E3DABD__INCLUDED_)
#define AFX_INTERFACE_H__29907CBE_5C33_44DA_8186_9C0F14E3DABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace biblia {
  namespace basico {

	class Interface {
		protected:
			Interface::Interface();

		public:
			virtual Interface::~Interface() {};
	};
  }
}

#endif // !defined(AFX_INTERFACE_H__29907CBE_5C33_44DA_8186_9C0F14E3DABD__INCLUDED_)
