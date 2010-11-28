/*
 * $RCSfile: BidimensionalImpl.h,v $
 * $Date: 2003/05/29 21:03:15 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BIDIMENSIONALIMPL_H__888DC144_D463_4104_9896_77B32C9CCA2A__INCLUDED_)
#define AFX_BIDIMENSIONALIMPL_H__888DC144_D463_4104_9896_77B32C9CCA2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Bidimensional.h"

namespace biblia {
  namespace visual {

	class BidimensionalImpl:
			public Bidimensional,
			public Objeto
	{
		private:
			Area BidimensionalImpl::pArea;

		public:
			BidimensionalImpl::BidimensionalImpl(const Area&);
			virtual BidimensionalImpl::~BidimensionalImpl();

			// Bidimensional:
			virtual Area BidimensionalImpl
					::areaQueOcupa() const;
	};
  }
}

#endif // !defined(AFX_BIDIMENSIONALIMPL_H__888DC144_D463_4104_9896_77B32C9CCA2A__INCLUDED_)
