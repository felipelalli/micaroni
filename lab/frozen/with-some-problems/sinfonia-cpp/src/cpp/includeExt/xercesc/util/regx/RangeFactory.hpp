/*
 * Copyright 2001-2004 The Apache Software Foundation.
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
 * $Id: RangeFactory.hpp,v 1.3 2005/01/21 20:27:55 felipelalli Exp $
 */

#if !defined(RANGEFACTORY_HPP)
#define RANGEFACTORY_HPP

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/XMemory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT RangeFactory : public XMemory
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and destructors
    // -----------------------------------------------------------------------
    virtual ~RangeFactory();

    //-----------------------------------------------------------------------
    //  Initialization methods
    // -----------------------------------------------------------------------
    virtual void initializeKeywordMap() = 0;

    /*
     * Used by children to build commonly used ranges
     */
    virtual void buildRanges() = 0;

protected:
    // -----------------------------------------------------------------------
    //  Constructor and destructors
    // -----------------------------------------------------------------------
    RangeFactory();

private:
	// -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    RangeFactory(const RangeFactory&);
    RangeFactory& operator=(const RangeFactory&);
};

XERCES_CPP_NAMESPACE_END

#endif

/**
  *	End file RangeFactory.hpp
  */
