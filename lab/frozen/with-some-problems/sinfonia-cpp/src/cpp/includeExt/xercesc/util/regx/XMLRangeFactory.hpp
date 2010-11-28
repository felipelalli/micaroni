/*
 * Copyright 2001-2002,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: XMLRangeFactory.hpp,v 1.3 2005/01/21 20:27:56 felipelalli Exp $
 */

#if !defined(XMLRANGEFACTORY_HPP)
#define XMLRANGEFACTORY_HPP

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/regx/RangeFactory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT XMLRangeFactory: public RangeFactory {

public:
    // -----------------------------------------------------------------------
    //  Constructors and operators
    // -----------------------------------------------------------------------
    XMLRangeFactory();
    ~XMLRangeFactory();

    // -----------------------------------------------------------------------
    //  Initialization methods
    // -----------------------------------------------------------------------
	void initializeKeywordMap();

protected:
    // -----------------------------------------------------------------------
    //  Protected Helper methods
    // -----------------------------------------------------------------------
	void buildRanges();

private:
	// -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLRangeFactory(const XMLRangeFactory&);
    XMLRangeFactory& operator=(const XMLRangeFactory&);

    bool fRangesCreated;
    bool fKeywordsInitialized;
};

XERCES_CPP_NAMESPACE_END

#endif

/**
  *	End file XMLRangeFactory.hpp
  */
