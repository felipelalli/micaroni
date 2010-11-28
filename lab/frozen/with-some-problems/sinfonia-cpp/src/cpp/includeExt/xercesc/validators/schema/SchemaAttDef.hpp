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
 * $Log: SchemaAttDef.hpp,v $
 * Revision 1.3  2005/01/21 20:28:01  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:47  fernandofernandes
 * no message
 *
 * Revision 1.14  2004/09/20 14:47:13  amassari
 * Mark some methods as deprecated
 *
 * Revision 1.13  2004/09/08 13:56:56  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.12  2004/01/29 11:52:31  cargilld
 * Code cleanup changes to get rid of various compiler diagnostic messages.
 *
 * Revision 1.11  2003/12/24 17:42:03  knoaman
 * Misc. PSVI updates
 *
 * Revision 1.10  2003/12/17 20:50:35  knoaman
 * PSVI: fix for annotation of attributes in attributeGroup/derived types
 *
 * Revision 1.9  2003/11/24 05:13:41  neilg
 * update method documentation
 *
 * Revision 1.8  2003/11/21 22:34:46  neilg
 * More schema component model implementation, thanks to David Cargill.
 * In particular, this cleans up and completes the XSModel, XSNamespaceItem,
 * XSAttributeDeclaration and XSAttributeGroup implementations.
 *
 * Revision 1.7  2003/10/10 16:25:40  peiyongz
 * Implementation of Serialization/Deserialization
 *
 * Revision 1.6  2003/05/18 14:02:07  knoaman
 * Memory manager implementation: pass per instance manager.
 *
 * Revision 1.5  2003/05/16 21:43:21  knoaman
 * Memory manager implementation: Modify constructors to pass in the memory manager.
 *
 * Revision 1.4  2003/02/06 13:51:55  gareth
 * fixed bug with multiple attributes being validated by the same union type.
 *
 * Revision 1.3  2003/01/29 19:47:16  gareth
 * added DOMTypeInfo and some PSVI methods
 *
 * Revision 1.2  2002/11/04 14:49:41  tng
 * C++ Namespace Support.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:46  peiyongz
 * sane_include
 *
 * Revision 1.6  2001/08/10 12:34:25  knoaman
 * Fix compilation error.
 *
 * Revision 1.5  2001/08/09 15:23:16  knoaman
 * add support for <anyAttribute> declaration.
 *
 * Revision 1.4  2001/07/31 15:26:54  knoaman
 * Added support for <attributeGroup>.
 *
 * Revision 1.3  2001/05/11 17:17:41  tng
 * Schema: DatatypeValidator fixes.  By Pei Yong Zhang.
 *
 * Revision 1.2  2001/05/11 13:27:34  tng
 * Copyright update.
 *
 * Revision 1.1  2001/02/27 18:48:22  tng
 * Schema: Add SchemaAttDef, SchemaElementDecl, SchemaAttDefList.
 *
 */
#if !defined(SCHEMAATTDEF_HPP)
#define SCHEMAATTDEF_HPP

#include <xercesc/util/XMLString.hpp>
#include <xercesc/framework/XMLAttDef.hpp>
#include <xercesc/util/ValueVectorOf.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/validators/datatype/UnionDatatypeValidator.hpp>
#include <xercesc/validators/schema/PSVIDefs.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class DatatypeValidator;
class QName;
class ComplexTypeInfo;
//
//  This class is a derivative of the core XMLAttDef class. This class adds
//  any Schema specific data members and provides Schema specific implementations
//  of any underlying attribute def virtual methods.
//
class VALIDATORS_EXPORT SchemaAttDef : public XMLAttDef
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructors
    // -----------------------------------------------------------------------
    SchemaAttDef(MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);
    SchemaAttDef
    (
          const XMLCh* const           prefix
        , const XMLCh* const           localPart
        , const int                    uriId
        , const XMLAttDef::AttTypes    type = CData
        , const XMLAttDef::DefAttTypes defType = Implied
        , MemoryManager* const         manager = XMLPlatformUtils::fgMemoryManager
    );
    SchemaAttDef
    (
          const XMLCh* const           prefix
        , const XMLCh* const           localPart
        , const int                    uriId
        , const XMLCh* const           attValue
        , const XMLAttDef::AttTypes    type
        , const XMLAttDef::DefAttTypes defType
        , const XMLCh* const           enumValues = 0
        , MemoryManager* const         manager = XMLPlatformUtils::fgMemoryManager
    );
    SchemaAttDef
    (
          const SchemaAttDef*                   other
    );
    virtual ~SchemaAttDef();

    // -----------------------------------------------------------------------
    //  Implementation of the XMLAttDef interface
    // -----------------------------------------------------------------------
    virtual const XMLCh* getFullName() const;
    virtual void reset();


    // ----------------------------------------------------------------------
    // Partial implementation of PSVI
    // The values these methods return are only accurate until the DOMAttr
    // is created that uses the values. After this a clean up method is called
    // and the SchemaAttDef may be used again.
    // note that some of this information has dependancies. For example,
    // if something is not valid then the information returned by the other 
    // calls may be meaningless
    // See http://www.w3.org/TR/xmlschema-1/ for detailed information
    // ----------------------------------------------------------------------

    /** 
     * The appropriate case among the following:
     * 1 If it was strictly assessed, then the appropriate case among the following:
     * 1.1 If it was valid as defined by Attribute Locally Valid (3.2.4), then valid;
     * 1.2 otherwise invalid.
     * 2 otherwise notKnown.
     * @deprecated
     */
    PSVIDefs::Validity getValidity() const;

    /**
     * The appropriate case among the following:
     * 1 If it was strictly assessed, then full;
     * 2 otherwise none.
     * @deprecated
     */
    PSVIDefs::Validation getValidationAttempted() const;

    /**
     * @return the complexity. Always simple for attrs
     * @deprecated
     */
    PSVIDefs::Complexity getTypeType() const;

    /**
     * The target namespace of the type definition.
     * @deprecated
     */
    const XMLCh* getTypeUri() const;

    /**
     * The {name} of the type definition, if it is not absent. 
     * @deprecated
     */
    const XMLCh* getTypeName() const;

    /**
     * true if the {name} of the type definition is absent, otherwise false.
     * @deprecated
     */
    bool getTypeAnonymous() const;

    /**
     * If this method returns true and validity is VALID then the next three 
     * produce accurate results
     * @return true if the element is validated using a union type
     * @deprecated
     */
    bool isTypeDefinitionUnion() const;

    /**
     * The {target namespace} of the actual member type definition.
     * @deprecated
     */
    const XMLCh* getMemberTypeUri() const;

    /**
     * @return true if the {name} of the actual member type definition is absent, otherwise false.
     * @deprecated
     */
    bool getMemberTypeAnonymous() const;

    /**
     * @return the {name} of the actual member type definition, if it is not absent. 
     * @deprecated
     */
    const XMLCh* getMemberTypeName() const;

    /*
     * @deprecated
     */
    virtual const XMLCh* getDOMTypeInfoUri() const;
    /*
     * @deprecated
     */
    virtual const XMLCh* getDOMTypeInfoName() const;
    
    

    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    unsigned int getElemId() const;
    QName* getAttName() const;
    DatatypeValidator* getDatatypeValidator() const;
    ValueVectorOf<unsigned int>* getNamespaceList() const;
    const SchemaAttDef* getBaseAttDecl() const;
    SchemaAttDef* getBaseAttDecl();
    PSVIDefs::PSVIScope getPSVIScope() const;

    /*
     * @deprecated
     */
    ComplexTypeInfo* getEnclosingCT() const;

    // -----------------------------------------------------------------------
    //  Setter methods
    // -----------------------------------------------------------------------
    void setElemId(const unsigned int newId);
    void setAttName
    (
        const XMLCh* const        prefix
       ,const XMLCh* const        localPart
       ,const int                 uriId = -1
    );
    void setDatatypeValidator(DatatypeValidator* newDatatypeValidator);
    /*
     * @deprecated
     */
    void setAnyDatatypeValidator(DatatypeValidator* newDatatypeValidator);
    void setBaseAttDecl(SchemaAttDef* const attDef);
    void setPSVIScope(const PSVIDefs::PSVIScope toSet);

    /*
     * @deprecated
     */
    void setMembertypeValidator(const DatatypeValidator* newDatatypeValidator);
    void setNamespaceList(const ValueVectorOf<unsigned int>* const toSet);
    void resetNamespaceList();
    /*
     * @deprecated
     */
    void setValidity(PSVIDefs::Validity valid);
    /*
     * @deprecated
     */
    void setValidationAttempted(PSVIDefs::Validation validation);
    void setEnclosingCT(ComplexTypeInfo* complexTypeInfo);
    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(SchemaAttDef)

private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    SchemaAttDef(const SchemaAttDef&);
    SchemaAttDef& operator=(const SchemaAttDef&);

    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fElemId
    //      This is the id of the element (the id is into the element decl
    //      pool) of the element this attribute def said it belonged to.
    //      This is used later to link back to the element, mostly for
    //      validation purposes.
    //
    //  fAttName
    //      This is the name of the attribute.
    //
    //  fDatatypeValidator
    //      The DatatypeValidator used to validate this attribute type.
    //
    //  fAnyDatatypeValidator
    //      Tempory storage for the DatatypeValidator used to validate an any
    //
    //  fMemberTypeValidator
    //      Tempory storage used when the validator being used is of union type.
    //      This stores the actual member validator used to validate.
    //
    //  fNamespaceList
    //      The list of namespace values for a wildcard attribute
    //
    //  fValidity
    //      After this attr has been validated this is its validity
    //
    //  fValidation
    //      The type of validation that happened to this attr
    //
    //  fBaseAttDecl
    //      The base attribute declaration that this attribute is based on
    //      NOTE: we do not have a notion of attribute use, so in the case
    //      of ref'd attributes and inherited attributes, we make a copy
    //      of the actual attribute declaration. The fBaseAttDecl stores that
    //      declaration, and will be helpful when we build the XSModel (i.e
    //      easy access the XSAnnotation object).
    // -----------------------------------------------------------------------
    unsigned int                 fElemId;
    QName*                       fAttName;
    DatatypeValidator*           fDatatypeValidator;
    DatatypeValidator*           fAnyDatatypeValidator;
    const DatatypeValidator*     fMemberTypeValidator;
    ValueVectorOf<unsigned int>* fNamespaceList;
    PSVIDefs::Validity           fValidity;
    PSVIDefs::Validation         fValidation;
    PSVIDefs::PSVIScope          fPSVIScope;
    SchemaAttDef*                fBaseAttDecl;
};


// ---------------------------------------------------------------------------
//  SchemaAttDef: Getter methods
// ---------------------------------------------------------------------------
inline unsigned int SchemaAttDef::getElemId() const
{
    return fElemId;
}


inline QName* SchemaAttDef::getAttName() const
{
    return fAttName;
}

inline DatatypeValidator* SchemaAttDef::getDatatypeValidator() const
{
    return fDatatypeValidator;
}

inline void SchemaAttDef::setValidity(PSVIDefs::Validity valid) {
    fValidity = valid;
}

inline void SchemaAttDef::setValidationAttempted(PSVIDefs::Validation validation) {
    fValidation = validation;
}


inline const XMLCh* SchemaAttDef::getTypeName() const {
    if(fAnyDatatypeValidator) 
        return fAnyDatatypeValidator->getTypeLocalName();
    else if(fDatatypeValidator)
        return fDatatypeValidator->getTypeLocalName();

    //its anySimpleType if we have not done validation on it
    if(getValidationAttempted() == PSVIDefs::NONE)
        return SchemaSymbols::fgDT_ANYSIMPLETYPE;


    return 0;
}

inline PSVIDefs::Complexity SchemaAttDef::getTypeType() const {
    return PSVIDefs::SIMPLE;
}

inline const XMLCh* SchemaAttDef::getTypeUri() const {
    if(fAnyDatatypeValidator) 
        return fAnyDatatypeValidator->getTypeUri();
    else if(fDatatypeValidator) 
        return fDatatypeValidator->getTypeUri();

    //its anySimpleType if we have not done validation on it
    if(getValidationAttempted() == PSVIDefs::NONE)
        return SchemaSymbols::fgURI_SCHEMAFORSCHEMA;

    return 0;
}


inline const XMLCh* SchemaAttDef::getMemberTypeName() const {
    if(fMemberTypeValidator) 
        return fMemberTypeValidator->getTypeLocalName();
    return 0;
}

inline const XMLCh* SchemaAttDef::getMemberTypeUri() const {
    if(fMemberTypeValidator) 
        return fMemberTypeValidator->getTypeUri();
    return 0;
}

inline PSVIDefs::Validity SchemaAttDef::getValidity() const {
    return fValidity;
}

inline PSVIDefs::Validation SchemaAttDef::getValidationAttempted() const {
    return fValidation;
}

inline const XMLCh* SchemaAttDef::getDOMTypeInfoName() const {
    if(fValidity != PSVIDefs::VALID)
        return SchemaSymbols::fgDT_ANYSIMPLETYPE;
    if(getTypeAnonymous() || getMemberTypeAnonymous())
        return 0;
    if(fMemberTypeValidator)
        return getMemberTypeName();

    return getTypeName();
}

inline const XMLCh* SchemaAttDef::getDOMTypeInfoUri() const {
    if(fValidity != PSVIDefs::VALID)
        return SchemaSymbols::fgURI_SCHEMAFORSCHEMA;
    if(getTypeAnonymous() || getMemberTypeAnonymous())
        return 0;
    if(fMemberTypeValidator)
        return getMemberTypeUri();
    return getTypeUri();
}

inline bool SchemaAttDef::getTypeAnonymous() const {
    if(fAnyDatatypeValidator) 
        return fAnyDatatypeValidator->getAnonymous();
    else if(fDatatypeValidator)
        return fDatatypeValidator->getAnonymous();

    return false;
}

inline bool SchemaAttDef::getMemberTypeAnonymous() const {
    if(fMemberTypeValidator) 
        return fMemberTypeValidator->getAnonymous();

    return false;
}

inline bool SchemaAttDef::isTypeDefinitionUnion() const {
   if(fAnyDatatypeValidator && fAnyDatatypeValidator->getType() == DatatypeValidator::Union ||
      fDatatypeValidator && fDatatypeValidator->getType() == DatatypeValidator::Union)
       return true;
    return false;
}

inline ValueVectorOf<unsigned int>*
SchemaAttDef::getNamespaceList() const {
    return fNamespaceList;
}

inline ComplexTypeInfo* SchemaAttDef::getEnclosingCT() const
{
    return 0;
}

inline SchemaAttDef* SchemaAttDef::getBaseAttDecl()
{
    return fBaseAttDecl;
}

inline const SchemaAttDef* SchemaAttDef::getBaseAttDecl() const
{
    return fBaseAttDecl;
}

inline PSVIDefs::PSVIScope SchemaAttDef::getPSVIScope() const
{
    return fPSVIScope;
}

// ---------------------------------------------------------------------------
//  SchemaAttDef: Setter methods
// ---------------------------------------------------------------------------
inline void SchemaAttDef::setElemId(const unsigned int newId)
{
    fElemId = newId;
}

inline void SchemaAttDef::setDatatypeValidator(DatatypeValidator* newDatatypeValidator)
{
    fDatatypeValidator = newDatatypeValidator;
}

inline void SchemaAttDef::setAnyDatatypeValidator(DatatypeValidator* newDatatypeValidator)
{
    fAnyDatatypeValidator = newDatatypeValidator;
}

inline void SchemaAttDef::setMembertypeValidator(const DatatypeValidator* newDatatypeValidator)
{
    fMemberTypeValidator = newDatatypeValidator;
}

inline void SchemaAttDef::resetNamespaceList() {

    if (fNamespaceList && fNamespaceList->size()) {
        fNamespaceList->removeAllElements();
    }
}

inline void SchemaAttDef::setNamespaceList(const ValueVectorOf<unsigned int>* const toSet) {

    if (toSet && toSet->size()) {

        if (fNamespaceList) {
            *fNamespaceList = *toSet;
        }
        else {
            fNamespaceList = new (getMemoryManager()) ValueVectorOf<unsigned int>(*toSet);
        }
    }
    else  {
        resetNamespaceList();
    }
}

inline void SchemaAttDef::reset() {
    if(fAnyDatatypeValidator && fAnyDatatypeValidator->getType() == DatatypeValidator::Union)
        ((UnionDatatypeValidator *)fAnyDatatypeValidator)->reset();
    else if(fDatatypeValidator && fDatatypeValidator->getType() == DatatypeValidator::Union)
        ((UnionDatatypeValidator *)fDatatypeValidator)->reset();
    fAnyDatatypeValidator = 0;
    fMemberTypeValidator = 0;
    fValidity = PSVIDefs::UNKNOWN;
    fValidation = PSVIDefs::NONE;    
}

inline void SchemaAttDef::setEnclosingCT(ComplexTypeInfo*)
{
}

inline void SchemaAttDef::setBaseAttDecl(SchemaAttDef* const attDef)
{
    fBaseAttDecl = attDef;
}

inline void SchemaAttDef::setPSVIScope(const PSVIDefs::PSVIScope toSet)
{
    fPSVIScope = toSet;
}

XERCES_CPP_NAMESPACE_END

#endif
