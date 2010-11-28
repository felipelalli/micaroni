#ifndef DOMError_HEADER_GUARD_
#define DOMError_HEADER_GUARD_

/*
 * Copyright 2002,2004 The Apache Software Foundation.
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
 * $Log: DOMError.hpp,v $
 * Revision 1.2  2005/01/21 20:27:04  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:15:52  fernandofernandes
 * no message
 *
 * Revision 1.12  2004/09/08 13:55:39  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.11  2003/12/01 23:23:25  neilg
 * fix for bug 25118; thanks to Jeroen Witmond
 *
 * Revision 1.10  2003/05/30 16:11:43  gareth
 * Fixes so we compile under VC7.1. Patch by Alberto Massari.
 *
 * Revision 1.9  2003/05/14 18:06:53  gareth
 * Updated DOMError to http://www.w3.org/TR/2003/WD-DOM-Level-3-Core-20030226/core.html.
 *
 * Revision 1.8  2003/03/07 19:59:04  tng
 * [Bug 11692] Unimplement the hidden constructors and assignment operator to remove warnings from gcc.
 *
 * Revision 1.7  2002/11/04 15:09:24  tng
 * C++ Namespace Support.
 *
 * Revision 1.6  2002/08/22 15:04:57  tng
 * Remove unused parameter variables in inline functions.
 *
 * Revision 1.5  2002/07/15 19:25:25  tng
 * DOM L3:  declare a dummy DOMError::set/getRelatedException
 *
 * Revision 1.4  2002/06/06 21:01:21  tng
 * [Bug 9639] enum_mem in DOMError clashes with constant.
 *
 * Revision 1.3  2002/06/06 20:53:06  tng
 * Documentation Fix: Update the API Documentation for DOM headers
 *
 * Revision 1.2  2002/05/30 19:24:48  knoaman
 * documentation update
 *
 * Revision 1.1  2002/05/23 15:47:24  knoaman
 * DOM L3 core - support for DOMError, DOMErrorHandler and DOMLocator
 *
 */


#include <xercesc/util/XercesDefs.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class DOMLocator;


/**
  * DOMError is an interface that describes an error.
  *
  * @see DOMErrorHandler#handleError
  * @since DOM Level 3
  */

class CDOM_EXPORT DOMError
{
protected:
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    /** @name Hidden constructors */
    //@{    
    DOMError() {};
    //@}

private:
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    /** @name Unimplemented constructors and operators */
    //@{
    DOMError(const DOMError &);
    DOMError & operator = (const DOMError &);
    //@}

public:
    // -----------------------------------------------------------------------
    //  All constructors are hidden, just the destructor is available
    // -----------------------------------------------------------------------
    /** @name Destructor */
    //@{
    /**
     * Destructor
     *
     */
    virtual ~DOMError() {};
    //@}

    // -----------------------------------------------------------------------
    //  Class types
    // -----------------------------------------------------------------------
    /** @name Public constants */
    //@{
    /**
     * The severity of the error described by the <code>DOMError</code>.
     *
     * @since DOM Level 3
     */
    enum ErrorSeverity
    {
        DOM_SEVERITY_WARNING     = 0,
        DOM_SEVERITY_ERROR       = 1,
        DOM_SEVERITY_FATAL_ERROR = 2
    };
    //@}


    // -----------------------------------------------------------------------
    //  Virtual DOMError interface
    // -----------------------------------------------------------------------
    /** @name Functions introduced in DOM Level 3 */
    //@{
    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    /**
     * Get the severity of the error
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setSeverity
     * @since DOM Level 3
     */
    virtual short getSeverity() const = 0;

    /**
     * Get the message describing the error that occured.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setMessage
     * @since DOM Level 3
     */
    virtual const XMLCh* getMessage() const = 0;

    /**
     * Get the location of the error
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setLocation
     * @since DOM Level 3
     */
    virtual DOMLocator* getLocation() const = 0;

    /**
     * The related platform dependent exception if any.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setRelatedException
     * @since DOM Level 3
     */
    virtual void* getRelatedException() const = 0;

    /**
     * A <code>XMLCh*</code> indicating which related data is expected in 
     * relatedData. Users should refer to the specification of the error
     * in order to find its <code>XMLCh*</code> type and relatedData
     * definitions if any.
     *
     * Note: As an example, [DOM Level 3 Load and Save] does not keep the
     * [baseURI] property defined on a Processing Instruction information item.
     * Therefore, the DOMBuilder generates a SEVERITY_WARNING with type 
     * "infoset-baseURI" and the lost [baseURI] property represented as a
     * DOMString in the relatedData attribute.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setType
     * @since DOM Level 3
     */
    virtual const XMLCh* getType() const = 0;

    /**
     * The related DOMError.type dependent data if any.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   setRelatedData
     * @since DOM Level 3
     */
    virtual void* getRelatedData() const = 0;


    // -----------------------------------------------------------------------
    //  Setter methods
    // -----------------------------------------------------------------------
    /**
     * Set the severity of the error
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param severity the type of the error to set
     * @see   getLocation
     * @since DOM Level 3
     */
    virtual void setSeverity(const short severity) = 0;

    /**
     * Set the error message
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param message the error message to set.
     * @see   getMessage
     * @since DOM Level 3
     */
    virtual void setMessage(const XMLCh* const message) = 0;

    /**
     * Set the location of the error
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param location the location of the error to set.
     * @see   getLocation
     * @since DOM Level 3
     */
    virtual void setLocation(DOMLocator* const location) = 0;

    /**
     * The related platform dependent exception if any.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param exc the related exception to set.
     * @see   getRelatedException
     * @since DOM Level 3
     */
    virtual void setRelatedException(void* exc) const = 0;

    /**
     * A <code>XMLCh*</code> indicating which related data is expected in 
     * relatedData. Users should refer to the specification of the error
     * in order to find its <code>XMLCh*</code> type and relatedData
     * definitions if any.
     *
     * Note: As an example, [DOM Level 3 Load and Save] does not keep the
     * [baseURI] property defined on a Processing Instruction information item.
     * Therefore, the DOMBuilder generates a SEVERITY_WARNING with type 
     * "infoset-baseURI" and the lost [baseURI] property represented as a
     * DOMString in the relatedData attribute.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   getType
     * @since DOM Level 3
     */
    virtual void setType(const XMLCh* type) = 0;

    /**
     * The related DOMError.type dependent data if any.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @see   getRelatedData
     * @since DOM Level 3
     */
    virtual void setRelatedData(void* relatedData) = 0;

    //@}

};

XERCES_CPP_NAMESPACE_END

#endif
