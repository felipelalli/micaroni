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
 * $Id: UnicodeRangeFactory.hpp,v 1.3 2005/01/21 20:27:56 felipelalli Exp $
 */

#if !defined(UNICODERANGEFACTORY_HPP)
#define UNICODERANGEFACTORY_HPP

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/regx/RangeFactory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT UnicodeRangeFactory: public RangeFactory {

public:
    // -----------------------------------------------------------------------
    //  Constructors and operators
    // -----------------------------------------------------------------------
    UnicodeRangeFactory();
    ~UnicodeRangeFactory();

    // -----------------------------------------------------------------------
    //  Initialization methods
    // -----------------------------------------------------------------------
	void initializeKeywordMap();

protected:
    // -----------------------------------------------------------------------
    //  Private Helper methods
    // -----------------------------------------------------------------------
	void buildRanges();

private:
	// -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    UnicodeRangeFactory(const UnicodeRangeFactory&);
    UnicodeRangeFactory& operator=(const UnicodeRangeFactory&);

    // -----------------------------------------------------------------------
    //  Helper methods
    // -----------------------------------------------------------------------
    unsigned short getUniCategory(const unsigned short type);

    bool fRangesCreated;
    bool fKeywordsInitialized;
};

XERCES_CPP_NAMESPACE_END

#endif

/**
  *	End file UnicodeRangeFactory.hpp
  */
