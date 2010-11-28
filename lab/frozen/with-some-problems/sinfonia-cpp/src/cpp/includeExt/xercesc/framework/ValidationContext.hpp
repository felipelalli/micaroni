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
 * $Log: ValidationContext.hpp,v $
 * Revision 1.2  2005/01/21 20:27:09  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:15:55  fernandofernandes
 * no message
 *
 * Revision 1.3  2004/09/08 13:55:58  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.2  2003/11/24 05:10:26  neilg
 * implement method for determining member type of union that validated some value
 *
 * Revision 1.1  2003/11/12 20:28:16  peiyongz
 * Stateless Grammar: ValidationContext
 *
 * $Id: ValidationContext.hpp,v 1.2 2005/01/21 20:27:09 felipelalli Exp $
 *
 */

#if !defined(VALIDATION_CONTEXT_HPP)
#define VALIDATION_CONTEXT_HPP

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/RefHashTableOf.hpp>
#include <xercesc/util/NameIdPool.hpp>
#include <xercesc/util/XMemory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLRefInfo;
class DTDEntityDecl;
class DatatypeValidator;

class XMLPARSER_EXPORT ValidationContext : public XMemory
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
    virtual ~ValidationContext(){};
    //@}

    // -----------------------------------------------------------------------
    /** @name The ValidationContext Interface */
    // -----------------------------------------------------------------------
    //@{

    /**
      * IDRefList
      *
      */
    virtual RefHashTableOf<XMLRefInfo>*  getIdRefList() const = 0;

    virtual void                         setIdRefList(RefHashTableOf<XMLRefInfo>* const) = 0;

    virtual void                         clearIdRefList() = 0;

    virtual void                         addId(const XMLCh * const ) = 0;

    virtual void                         addIdRef(const XMLCh * const ) = 0;

    virtual void                         toCheckIdRefList(bool) = 0;

    /**
      * EntityDeclPool
      *
      */
    virtual const NameIdPool<DTDEntityDecl>* getEntityDeclPool() const = 0;

    virtual const NameIdPool<DTDEntityDecl>* setEntityDeclPool(const NameIdPool<DTDEntityDecl>* const) = 0;    
           
    virtual void                             checkEntity(const XMLCh * const ) const = 0 ;

    /**
      * Union datatype handling
      *
      */

    virtual DatatypeValidator * getValidatingMemberType() const = 0 ;
    virtual void setValidatingMemberType(DatatypeValidator * validatingMemberType) = 0 ;

    //@}

   
protected :
    // -----------------------------------------------------------------------
    /**  Hidden Constructors */
    // -----------------------------------------------------------------------
    //@{
    ValidationContext(MemoryManager* const memMgr = XMLPlatformUtils::fgMemoryManager)
    :fMemoryManager(memMgr)
    {
    };
    //@}

    // -----------------------------------------------------------------------
    //  Data members
    //
    //  fMemoryManager
    //      Pluggable memory manager for dynamic allocation/deallocation.
    // -----------------------------------------------------------------------
    MemoryManager*                    fMemoryManager;

private :
    // -----------------------------------------------------------------------
    /** name  Unimplemented copy constructor and operator= */
    // -----------------------------------------------------------------------
    //@{
    ValidationContext(const ValidationContext& );
    ValidationContext& operator=(const ValidationContext& );
    //@}

};

XERCES_CPP_NAMESPACE_END

#endif

