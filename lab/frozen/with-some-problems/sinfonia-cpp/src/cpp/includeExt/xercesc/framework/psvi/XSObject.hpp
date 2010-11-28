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
 * $Log: XSObject.hpp,v $
 * Revision 1.2  2005/01/21 20:27:13  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:01  fernandofernandes
 * no message
 *
 * Revision 1.12  2004/09/08 13:56:09  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.11  2004/05/04 19:02:40  cargilld
 * Enable IDs to work on all kinds of schema components
 *
 * Revision 1.10  2003/12/01 23:23:26  neilg
 * fix for bug 25118; thanks to Jeroen Witmond
 *
 * Revision 1.9  2003/11/25 15:10:44  jberry
 * Eliminate some compiler warnings concerning comments inside of comments
 *
 * Revision 1.8  2003/11/21 17:34:04  knoaman
 * PSVI update
 *
 * Revision 1.7  2003/11/15 21:18:39  neilg
 * fixes for compilation under gcc
 *
 * Revision 1.6  2003/11/14 22:47:53  neilg
 * fix bogus log message from previous commit...
 *
 * Revision 1.5  2003/11/14 22:33:30  neilg
 * Second phase of schema component model implementation.  
 * Implement XSModel, XSNamespaceItem, and the plumbing necessary
 * to connect them to the other components.
 * Thanks to David Cargill.
 *
 * Revision 1.4  2003/11/06 15:30:04  neilg
 * first part of PSVI/schema component model implementation, thanks to David Cargill.  This covers setting the PSVIHandler on parser objects, as well as implementing XSNotation, XSSimpleTypeDefinition, XSIDCDefinition, and most of XSWildcard, XSComplexTypeDefinition, XSElementDeclaration, XSAttributeDeclaration and XSAttributeUse.
 *
 * Revision 1.3  2003/10/24 10:59:26  gareth
 * changed C comments to C++ comments to prevent compiler warnings.
 *  (rephrased that message to eliminate compiler warnings on the message--this is recursive!)
 *
 * Revision 1.2  2003/10/10 18:37:51  neilg
 * update XSModel and XSObject interface so that IDs can be used to query components in XSModels, and so that those IDs can be recovered from components
 *
 * Revision 1.1  2003/09/16 14:33:36  neilg
 * PSVI/schema component model classes, with Makefile/configuration changes necessary to build them
 *
 */

#if !defined(XSOBJECT_HPP)
#define XSOBJECT_HPP

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/psvi/XSConstants.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
 * The XSObject forms the base of the Schema Component Model.  It contains
 * all properties common to the majority of XML Schema components.
 * This is *always* owned by the validator /parser object from which
 * it is obtained.  It is designed to be subclassed; subclasses will
 * specify under what conditions it may be relied upon to have meaningful contents.
 */

// forward declarations
class XSNamespaceItem;
class XSModel;

class XMLPARSER_EXPORT XSObject : public XMemory
{
public:

    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    /** @name Constructors */
    //@{

    /**
      * The default constructor 
      *
      * @param  compType
      * @param  xsModel
      * @param  manager     The configurable memory manager
      */
    XSObject
    (
        XSConstants::COMPONENT_TYPE compType
        , XSModel* const xsModel
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    //@};

    /** @name Destructor */
    //@{
    virtual ~XSObject();
    //@}

    //---------------------
    /** @name XSObject methods */

    //@{

    /**
     *  The <code>type</code> of this object, i.e. 
     * <code>ELEMENT_DECLARATION</code>. 
     */
    XSConstants::COMPONENT_TYPE getType() const;

    /**
     * The name of type <code>NCName</code> of this declaration as defined in 
     * XML Namespaces.
     */
    virtual const XMLCh* getName();

    /**
     *  The [target namespace] of this object, or <code>null</code> if it is 
     * unspecified. 
     */
    virtual const XMLCh* getNamespace();

    /**
     * A namespace schema information item corresponding to the target 
     * namespace of the component, if it's globally declared; or null 
     * otherwise.
     */
    virtual XSNamespaceItem *getNamespaceItem();

    /**
      * Optional.  Return a unique identifier for a component within this XSModel, to
      * optimize querying.  May not be defined for all types of component.
      * @return id unique for this type of component within this XSModel or 0
      *     to indicate that this is not supported for this type of component.
      */
    virtual unsigned int getId() const;

    //@}

    //----------------------------------
    /** methods needed by implementation */

    //@{
    /**
      * Set the id to be returned on getId().
      */
    void setId(unsigned int id);
    //@}

private:

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XSObject(const XSObject&);
    XSObject & operator=(const XSObject &);

protected:

    // -----------------------------------------------------------------------
    //  data members
    // -----------------------------------------------------------------------
    // fMemoryManager:
    //  used for any memory allocations
    // fComponentType
    //  the type of the actual component
    XSConstants::COMPONENT_TYPE fComponentType;
    XSModel*                    fXSModel;
    MemoryManager*              fMemoryManager;
    unsigned int                fId;
};

inline XSConstants::COMPONENT_TYPE XSObject::getType() const
{
    return fComponentType;
}

XERCES_CPP_NAMESPACE_END

#endif
