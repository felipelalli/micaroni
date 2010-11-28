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
 * $Id: AnyURIDatatypeValidator.hpp,v 1.3 2005/01/21 20:27:58 felipelalli Exp $
 * $Log: AnyURIDatatypeValidator.hpp,v $
 * Revision 1.3  2005/01/21 20:27:58  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:43  fernandofernandes
 * no message
 *
 * Revision 1.8  2004/09/08 13:56:52  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.7  2004/01/29 11:51:22  cargilld
 * Code cleanup changes to get rid of various compiler diagnostic messages.
 *
 * Revision 1.6  2003/12/17 00:18:38  cargilld
 * Update to memory management so that the static memory manager (one used to call Initialize) is only for static data.
 *
 * Revision 1.5  2003/09/30 21:31:30  peiyongz
 * Implementation of Serialization/Deserialization
 *
 * Revision 1.4  2003/05/15 18:53:26  knoaman
 * Partial implementation of the configurable memory manager.
 *
 * Revision 1.3  2002/12/18 14:17:55  gareth
 * Fix to bug #13438. When you eant a vector that calls delete[] on its members you should use RefArrayVectorOf.
 *
 * Revision 1.2  2002/11/04 14:53:27  tng
 * C++ Namespace Support.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:40  peiyongz
 * sane_include
 *
 * Revision 1.8  2001/11/22 20:23:20  peiyongz
 * _declspec(dllimport) and inline warning C4273
 *
 * Revision 1.7  2001/09/24 15:33:15  peiyongz
 * DTV Reorganization: virtual methods moved to *.cpp
 *
 * Revision 1.6  2001/09/19 18:49:17  peiyongz
 * DTV reorganization: move inline to class declaration to avoid inline
 * function interdependency.
 *
 * Revision 1.5  2001/09/18 20:38:02  peiyongz
 * DTV reorganization: inherit from AbstractStringValidator.
 *
 * Revision 1.4  2001/08/24 17:12:01  knoaman
 * Add support for anySimpleType.
 * Remove parameter 'baseValidator' from the virtual method 'newInstance'.
 *
 * Revision 1.3  2001/08/21 18:42:53  peiyongz
 * Bugzilla# 2816: cleanUp() declared with external linkage and called
 *                          before defined as inline
 *
 * Revision 1.2  2001/08/10 16:21:19  peiyongz
 * use XMLUri instead of XMLURL
 *
 * Revision 1.1  2001/08/01 18:49:16  peiyongz
 * AnyRUIDatatypeValidator
 *
 *
 */

#if !defined(ANYURI_DATATYPEVALIDATOR_HPP)
#define ANYURI_DATATYPEVALIDATOR_HPP

#include <xercesc/validators/datatype/AbstractStringValidator.hpp>
#include <xercesc/util/XMLUri.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class VALIDATORS_EXPORT AnyURIDatatypeValidator : public AbstractStringValidator
{
public:

    // -----------------------------------------------------------------------
    //  Public ctor/dtor
    // -----------------------------------------------------------------------
	/** @name Constructors and Destructor */
    //@{

    AnyURIDatatypeValidator
    (
        MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    AnyURIDatatypeValidator
    (
        DatatypeValidator* const baseValidator
        , RefHashTableOf<KVStringPair>* const facets
        , RefArrayVectorOf<XMLCh>* const enums
        , const int finalSet
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    virtual ~AnyURIDatatypeValidator();

	//@}

    /**
      * Returns an instance of the base datatype validator class
	  * Used by the DatatypeValidatorFactory.
      */
    virtual DatatypeValidator* newInstance
    (
        RefHashTableOf<KVStringPair>* const facets
        , RefArrayVectorOf<XMLCh>* const enums
        , const int finalSet
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(AnyURIDatatypeValidator)

protected:

    virtual void checkValueSpace(const XMLCh* const content
        , MemoryManager* const manager);

private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    AnyURIDatatypeValidator(const AnyURIDatatypeValidator&);
    AnyURIDatatypeValidator& operator=(const AnyURIDatatypeValidator&);    
};

XERCES_CPP_NAMESPACE_END

#endif

/**
  * End of file AnyURIDatatypeValidator.hpp
  */
