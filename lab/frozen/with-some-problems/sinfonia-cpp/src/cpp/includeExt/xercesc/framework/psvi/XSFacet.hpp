/*
 * Copyright 2003,2004 The Apache Software Foundation.
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
 * $Log: XSFacet.hpp,v $
 * Revision 1.2  2005/01/21 20:27:12  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:00  fernandofernandes
 * no message
 *
 * Revision 1.7  2004/09/08 13:56:08  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.6  2003/12/01 23:23:26  neilg
 * fix for bug 25118; thanks to Jeroen Witmond
 *
 * Revision 1.5  2003/11/21 17:29:53  knoaman
 * PSVI update
 *
 * Revision 1.4  2003/11/14 22:47:53  neilg
 * fix bogus log message from previous commit...
 *
 * Revision 1.3  2003/11/14 22:33:30  neilg
 * Second phase of schema component model implementation.  
 * Implement XSModel, XSNamespaceItem, and the plumbing necessary
 * to connect them to the other components.
 * Thanks to David Cargill.
 *
 * Revision 1.2  2003/11/06 15:30:04  neilg
 * first part of PSVI/schema component model implementation, thanks to David Cargill.  This covers setting the PSVIHandler on parser objects, as well as implementing XSNotation, XSSimpleTypeDefinition, XSIDCDefinition, and most of XSWildcard, XSComplexTypeDefinition, XSElementDeclaration, XSAttributeDeclaration and XSAttributeUse.
 *
 * Revision 1.1  2003/09/16 14:33:36  neilg
 * PSVI/schema component model classes, with Makefile/configuration changes necessary to build them
 *
 */

#if !defined(XSFACET_HPP)
#define XSFACET_HPP

#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
 * This represents all Schema Facet components with the exception 
 * of Enumeration and Pattern Facets, which are represented by the 
 * XSMultiValueFacet interface.
 * This is *always* owned by the validator /parser object from which
 * it is obtained.  
 */

// forward declarations
class XSAnnotation;

class XMLPARSER_EXPORT XSFacet : public XSObject
{
public:

    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    /** @name Constructors */
    //@{

    /**
      * The default constructor 
      *
      * @param  facetKind
      * @param  lexicalValue
      * @param  isFixed
      * @param  annot
      * @param  xsModel
      * @param  manager     The configurable memory manager
      */
    XSFacet
    (
        XSSimpleTypeDefinition::FACET facetKind
        , const XMLCh* const          lexicalValue
        , bool                        isFixed
        , XSAnnotation* const         annot
        , XSModel* const              xsModel
        , MemoryManager* const        manager = XMLPlatformUtils::fgMemoryManager
    );

    //@};

    /** @name Destructor */
    //@{
    ~XSFacet();
    //@}

    //---------------------
    /** @name XSFacet methods */

    //@{

    /**
     * @return An indication as to the facet's type; see <code>XSSimpleTypeDefinition::FACET</code>
     */
    XSSimpleTypeDefinition::FACET getFacetKind() const;

    /**
     * @return Returns a value of a constraining facet. 
     */
    const XMLCh *getLexicalFacetValue() const;

    /**
     * Check whether a facet value is fixed. 
     */
    bool isFixed() const;

    /**
     * @return an annotation
     */
    XSAnnotation *getAnnotation() const;

    //@}

    //----------------------------------
    /** methods needed by implementation */

    //@{

    //@}
private:

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XSFacet(const XSFacet&);
    XSFacet & operator=(const XSFacet &);

protected:

    // -----------------------------------------------------------------------
    //  data members
    // -----------------------------------------------------------------------
    XSSimpleTypeDefinition::FACET fFacetKind;
    bool                          fIsFixed;
    const XMLCh*                  fLexicalValue;
    XSAnnotation*                 fAnnotation;
};

inline XSSimpleTypeDefinition::FACET XSFacet::getFacetKind() const
{   
    return fFacetKind;
}

inline const XMLCh* XSFacet::getLexicalFacetValue() const
{
    return fLexicalValue;    
}

inline bool XSFacet::isFixed() const
{
    return fIsFixed;
}

inline XSAnnotation* XSFacet::getAnnotation() const
{
    return fAnnotation;
}


XERCES_CPP_NAMESPACE_END

#endif
