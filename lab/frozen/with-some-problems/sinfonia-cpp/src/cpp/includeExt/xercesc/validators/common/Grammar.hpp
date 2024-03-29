/*
 * Copyright 2001,2004 The Apache Software Foundation.
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
 * $Log: Grammar.hpp,v $
 * Revision 1.3  2005/01/21 20:27:57  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:41  fernandofernandes
 * no message
 *
 * Revision 1.11  2004/09/08 13:56:51  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.10  2004/01/29 11:51:21  cargilld
 * Code cleanup changes to get rid of various compiler diagnostic messages.
 *
 * Revision 1.9  2003/10/29 16:19:47  peiyongz
 * storeGrammar()/loadGrammar added
 *
 * Revision 1.8  2003/10/14 15:19:24  peiyongz
 * Implementation of Serialization/Deserialization
 *
 * Revision 1.7  2003/09/22 19:47:14  neilg
 * change Grammar::putElemDecl(XMLElementDecl, bool) so that it does not require the Grammar object to be const.  Also, mark findOrAddGrammar as being dangerous in multithreaded situations
 *
 * Revision 1.6  2003/07/31 17:07:33  peiyongz
 * Grammar embed grammar description
 *
 * Revision 1.5  2003/05/15 18:48:27  knoaman
 * Partial implementation of the configurable memory manager.
 *
 * Revision 1.4  2002/11/04 14:54:58  tng
 * C++ Namespace Support.
 *
 * Revision 1.3  2002/07/11 18:17:43  knoaman
 * Grammar caching/preparsing - initial implementation.
 *
 * Revision 1.2  2002/07/05 17:08:10  tng
 * [Bug 10119] Grammar::getGrammarType need a const modifier
 *
 * Revision 1.1.1.1  2002/02/01 22:22:38  peiyongz
 * sane_include
 *
 * Revision 1.6  2001/09/14 14:50:22  tng
 * Schema: Fix some wildcard bugs, and some retrieving qualified/unqualified element decl problems.
 *
 * Revision 1.5  2001/05/28 20:56:18  tng
 * Schema: Move getTargetNamespace as virtual function in base class Grammar
 *
 * Revision 1.4  2001/05/11 13:27:18  tng
 * Copyright update.
 *
 * Revision 1.3  2001/05/03 20:34:40  tng
 * Schema: SchemaValidator update
 *
 * Revision 1.2  2001/04/19 18:17:31  tng
 * Schema: SchemaValidator update, and use QName in Content Model
 *
 * Revision 1.1  2001/03/21 21:56:27  tng
 * Schema: Add Schema Grammar, Schema Validator, and split the DTDValidator into DTDValidator, DTDScanner, and DTDGrammar.
 *
 */



#if !defined(GRAMMAR_HPP)
#define GRAMMAR_HPP

#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/framework/XMLEntityDecl.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>

#include <xercesc/internal/XSerializable.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLGrammarDescription;

//
// This abstract class specifies the interface for a Grammar
//

class VALIDATORS_EXPORT Grammar : public XSerializable, public XMemory
{
public:

    // -----------------------------------------------------------------------
    //  Class Specific Types
    //
    //  DTDGrammarType    - Indicate this Grammar is built from a DTD.
    //  SchemaGrammarType - Indicate this Grammar is built from a Schema.
    //
    //  TOP_LEVEL_SCOPE - outermost scope level (i.e. global) of a declaration.
    //                    For DTD, all element decls and attribute decls always
    //                    have TOP_LEVEL_SCOPE.  For schema, it may varies if
    //                    it is inside a complex type.
    //
    //  UNKNOWN_SCOPE   - unknown scope level.  None of the decls should have this.
    //
    // -----------------------------------------------------------------------
    enum GrammarType {
        DTDGrammarType
      , SchemaGrammarType
      , UnKnown
    };

    enum {
         UNKNOWN_SCOPE = -2
       , TOP_LEVEL_SCOPE = -1
    };

    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    virtual ~Grammar(){};

    // -----------------------------------------------------------------------
    //  Virtual Getter methods
    // -----------------------------------------------------------------------
    virtual GrammarType getGrammarType() const =0;
    virtual const XMLCh* getTargetNamespace() const =0;
    virtual bool getValidated() const = 0;

    // Element Decl

    // this method should only be used while the grammar is being
    // constructed, not while it is being used
    // in a validation episode!
    virtual XMLElementDecl* findOrAddElemDecl
    (
        const   unsigned int    uriId
        , const XMLCh* const    baseName
        , const XMLCh* const    prefixName
        , const XMLCh* const    qName
        , unsigned int          scope
        ,       bool&           wasAdded
    ) = 0;

    virtual unsigned int getElemId
    (
        const   unsigned int    uriId
        , const XMLCh* const    baseName
        , const XMLCh* const    qName
        , unsigned int          scope
    )   const = 0;

    virtual const XMLElementDecl* getElemDecl
    (
        const   unsigned int    uriId
        , const XMLCh* const    baseName
        , const XMLCh* const    qName
        , unsigned int          scope
    )   const = 0;

    virtual XMLElementDecl* getElemDecl
    (
        const   unsigned int    uriId
        , const XMLCh* const    baseName
        , const XMLCh* const    qName
        , unsigned int          scope
    ) = 0;

    virtual const XMLElementDecl* getElemDecl
    (
        const   unsigned int    elemId
    )   const = 0;

    virtual XMLElementDecl* getElemDecl
    (
        const   unsigned int    elemId
    ) = 0;

    // Notation
    virtual const XMLNotationDecl* getNotationDecl
    (
        const   XMLCh* const    notName
    )   const=0;

    virtual XMLNotationDecl* getNotationDecl
    (
        const   XMLCh* const    notName
    )=0;

    // -----------------------------------------------------------------------
    //  Virtual Setter methods
    // -----------------------------------------------------------------------
    virtual XMLElementDecl* putElemDecl
    (
        const   unsigned int    uriId
        , const XMLCh* const    baseName
        , const XMLCh* const    prefixName
        , const XMLCh* const    qName
        , unsigned int          scope
        , const bool            notDeclared = false
    ) = 0;

    virtual unsigned int putElemDecl
    (
        XMLElementDecl* const elemDecl
        , const bool          notDeclared = false
    )   = 0;

    virtual unsigned int putNotationDecl
    (
        XMLNotationDecl* const notationDecl
    )   const=0;

    virtual void setValidated(const bool newState) = 0;

    // -----------------------------------------------------------------------
    //  Virtual methods
    // -----------------------------------------------------------------------
    virtual void reset()=0;

    virtual void                    setGrammarDescription( XMLGrammarDescription*) = 0;
    virtual XMLGrammarDescription*  getGrammarDescription() const = 0;

    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(Grammar)

	static void     storeGrammar(XSerializeEngine&        serEng
                               , Grammar* const           grammar);

	static Grammar* loadGrammar(XSerializeEngine& serEng);

protected :
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    Grammar(){};

private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    Grammar(const Grammar&);
    Grammar& operator=(const Grammar&);
};

XERCES_CPP_NAMESPACE_END

#endif
