#ifndef DOMEntityResolver_HEADER_GUARD_
#define DOMEntityResolver_HEADER_GUARD_

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
 * $Log: DOMEntityResolver.hpp,v $
 * Revision 1.2  2005/01/21 20:27:03  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:15:52  fernandofernandes
 * no message
 *
 * Revision 1.7  2004/09/08 13:55:39  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.6  2003/03/07 19:59:04  tng
 * [Bug 11692] Unimplement the hidden constructors and assignment operator to remove warnings from gcc.
 *
 * Revision 1.5  2002/11/04 15:09:24  tng
 * C++ Namespace Support.
 *
 * Revision 1.4  2002/08/22 15:04:57  tng
 * Remove unused parameter variables in inline functions.
 *
 * Revision 1.3  2002/06/06 20:53:06  tng
 * Documentation Fix: Update the API Documentation for DOM headers
 *
 * Revision 1.2  2002/05/30 19:24:48  knoaman
 * documentation update
 *
 * Revision 1.1  2002/05/29 21:28:02  knoaman
 * DOM L3 LS: DOMInputSource, DOMEntityResolver, DOMImplementationLS and DOMBuilder
 *
 */


#include <xercesc/util/XercesDefs.hpp>

XERCES_CPP_NAMESPACE_BEGIN


class DOMInputSource;

/**
  * DOMEntityResolver provides a way for applications to redirect references
  * to external entities.
  *
  * <p>Applications needing to implement customized handling for external
  * entities must implement this interface and register their implementation
  * by setting the entityResolver attribute of the DOMBuilder.</p>
  *
  * <p>The DOMBuilder will then allow the application to intercept any
  * external entities (including the external DTD subset and external parameter
  * entities) before including them.</p>
  *
  * <p>Many DOM applications will not need to implement this interface, but it
  * will be especially useful for applications that build XML documents from
  * databases or other specialized input sources, or for applications that use
  * URNs.</p>
  *
  * @see DOMBuilder#setEntityResolver
  * @see DOMInputSource#DOMInputSource
  * @since DOM Level 3
  */
class CDOM_EXPORT DOMEntityResolver
{
protected:
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    /** @name Hidden constructors */
    //@{    
    DOMEntityResolver() {};
    //@}

private:
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    /** @name Unimplemented constructors and operators */
    //@{
    DOMEntityResolver(const DOMEntityResolver &);
    DOMEntityResolver & operator = (const DOMEntityResolver &);
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
    virtual ~DOMEntityResolver() {};
    //@}

    // -----------------------------------------------------------------------
    //  Virtual DOMEntityResolver interface
    // -----------------------------------------------------------------------
    /** @name Functions introduced in DOM Level 2 */
    //@{
    /**
     * Allow the application to resolve external entities.
     *
     * <p>The DOMBuilder will call this method before opening any external
     * entity except the top-level document entity (including the
     * external DTD subset, external entities referenced within the
     * DTD, and external entities referenced within the document
     * element): the application may request that the DOMBuilder resolve
     * the entity itself, that it use an alternative URI, or that it
     * use an entirely different input source.</p>
     *
     * <p>Application writers can use this method to redirect external
     * system identifiers to secure and/or local URIs, to look up
     * public identifiers in a catalogue, or to read an entity from a
     * database or other input source (including, for example, a dialog
     * box).</p>
     *
     * <p>If the system identifier is a URL, the DOMBuilder parser must
     * resolve it fully before reporting it to the application.</p>
     *
     * <p> The returned DOMInputSource is owned by the DOMBuilder which is
     *     responsible to clean up the memory.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param publicId The public identifier of the external entity
     *        being referenced, or null if none was supplied.
     * @param systemId The system identifier of the external entity
     *        being referenced.
     * @param baseURI The absolute base URI of the resource being parsed, or
     *        <code>null</code> if there is no base URI.
     * @return A DOMInputSource object describing the new input source,
     *         or <code>null</code> to request that the parser open a regular
     *         URI connection to the system identifier.
     *         The returned DOMInputSource is owned by the DOMBuilder which is
     *         responsible to clean up the memory.
     * @exception DOMSystemException Any DOMSystemException exception, possibly
     *            wrapping another exception.
     * @see DOMInputSource#DOMInputSource
     * @since DOM Level 3
     */
    virtual DOMInputSource* resolveEntity
    (
        const   XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const XMLCh* const    baseURI
    ) = 0;

    //@}

};

XERCES_CPP_NAMESPACE_END

#endif
