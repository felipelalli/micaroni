/*
 * Copyright 1999-2004 The Apache Software Foundation.
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
 * $Log: XMLGrammarDescription.hpp,v $
 * Revision 1.2  2005/01/21 20:27:10  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:15:58  fernandofernandes
 * no message
 *
 * Revision 1.3  2004/09/08 13:55:59  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.2  2003/10/14 15:17:47  peiyongz
 * Implementation of Serialization/Deserialization
 *
 * Revision 1.1  2003/06/20 18:37:39  peiyongz
 * Stateless Grammar Pool :: Part I
 *
 * $Id: XMLGrammarDescription.hpp,v 1.2 2005/01/21 20:27:10 felipelalli Exp $
 *
 */

#if !defined(XMLGRAMMARDESCRIPTION_HPP)
#define XMLGRAMMARDESCRIPTION_HPP

#include <xercesc/util/XMemory.hpp>
#include <xercesc/validators/common/Grammar.hpp>

#include <xercesc/internal/XSerializable.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLPARSER_EXPORT XMLGrammarDescription : public XSerializable, public XMemory
{
public :
    // -----------------------------------------------------------------------
    /** @name Virtual destructor for derived classes */
    // -----------------------------------------------------------------------
    //@{
    /**
      * virtual destructor
      *
      */
    virtual ~XMLGrammarDescription();
    //@}

    // -----------------------------------------------------------------------
    /** @name The Grammar Description Interface */
    // -----------------------------------------------------------------------
    //@{     
    /**
      * getGrammarType
      *
      */
    virtual Grammar::GrammarType   getGrammarType() const = 0;
    
    /**
      * getGrammarKey
      *
      */
    virtual const XMLCh*           getGrammarKey() const = 0;    
    //@}
    
    inline MemoryManager*          getMemoryManager() const;

    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(XMLGrammarDescription)

protected :
    // -----------------------------------------------------------------------
    /**  Hidden Constructors */
    // -----------------------------------------------------------------------
    //@{
    XMLGrammarDescription(MemoryManager* const memMgr = XMLPlatformUtils::fgMemoryManager);
    //@}

private :
    // -----------------------------------------------------------------------
    /** name  Unimplemented copy constructor and operator= */
    // -----------------------------------------------------------------------
    //@{
    XMLGrammarDescription(const XMLGrammarDescription& );
    XMLGrammarDescription& operator=(const XMLGrammarDescription& );
    //@}

    // -----------------------------------------------------------------------
    //
    // fMemMgr: plugged-in (or defaulted-in) memory manager, 
    //          not owned 
    //          no reset after initialization
	//          allow derivatives to access directly
    //
    // -----------------------------------------------------------------------    
    MemoryManager* const  fMemMgr;     
};

inline MemoryManager* XMLGrammarDescription::getMemoryManager() const
{
    return fMemMgr;
}

XERCES_CPP_NAMESPACE_END

#endif
