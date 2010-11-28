#ifndef DOMErrorHandler_HEADER_GUARD_
#define DOMErrorHandler_HEADER_GUARD_

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
 * $Log: DOMErrorHandler.hpp,v $
 * Revision 1.2  2005/01/21 20:27:04  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:15:52  fernandofernandes
 * no message
 *
 * Revision 1.8  2004/09/08 13:55:39  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.7  2003/03/07 19:59:05  tng
 * [Bug 11692] Unimplement the hidden constructors and assignment operator to remove warnings from gcc.
 *
 * Revision 1.6  2002/11/04 15:09:24  tng
 * C++ Namespace Support.
 *
 * Revision 1.5  2002/08/22 15:04:57  tng
 * Remove unused parameter variables in inline functions.
 *
 * Revision 1.4  2002/07/15 19:26:34  tng
 * DOM L3: remove non standard resetErrors
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


class DOMError;

/**
  * Basic interface for DOM error handlers.
  *
  * <p>DOMErrorHandler is a callback interface that the DOM implementation
  * can call when reporting errors that happens while processing XML data, or
  * when doing some other processing (e.g. validating a document).</p>
  *
  * <p>The application that is using the DOM implementation is expected to
  * implement this interface.</p>
  *
  * @see DOMBuilder#setErrorHandler
  * @since DOM Level 3
  */

class CDOM_EXPORT DOMErrorHandler
{
protected:
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    /** @name Hidden constructors */
    //@{    
    DOMErrorHandler() {};
    //@}

private:
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    /** @name Unimplemented constructors and operators */
    //@{
    DOMErrorHandler(const DOMErrorHandler &);
    DOMErrorHandler & operator = (const DOMErrorHandler &);
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
    virtual ~DOMErrorHandler() {};
    //@}

    // -----------------------------------------------------------------------
    //  Virtual DOMErrorHandler interface
    // -----------------------------------------------------------------------
    /** @name Functions introduced in DOM Level 3 */
    //@{
    /**
     * This method is called on the error handler when an error occures.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param domError The error object that describes the error, this object
     *                 may be reused by the DOM implementation across multiple
     *                 calls to the handleEvent method.
     * @return If the handleError method returns <code>true</code> the DOM
     *         implementation should continue as if the error didn't happen
     *         when possible, if the method returns <code>false</code> then the
     *         DOM implementation should stop the current processing when
     *         possible.
     *
     * @since DOM Level 3
     */
    virtual bool handleError(const DOMError& domError) = 0;
    //@}

};

XERCES_CPP_NAMESPACE_END

#endif
