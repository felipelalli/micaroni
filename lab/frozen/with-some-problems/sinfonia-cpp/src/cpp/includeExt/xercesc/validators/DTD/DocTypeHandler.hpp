/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
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
 * $Log: DocTypeHandler.hpp,v $
 * Revision 1.3  2005/01/21 20:27:56  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:40  fernandofernandes
 * no message
 *
 * Revision 1.5  2004/09/08 13:56:50  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.4  2003/03/07 18:17:12  tng
 * Return a reference instead of void for operator=
 *
 * Revision 1.3  2002/11/04 14:50:40  tng
 * C++ Namespace Support.
 *
 * Revision 1.2  2002/08/14 15:20:38  knoaman
 * [Bug 3111] Problem with LexicalHandler::startDTD() and LexicalHandler::endDTD().
 *
 * Revision 1.1.1.1  2002/02/01 22:22:43  peiyongz
 * sane_include
 *
 * Revision 1.5  2001/06/19 16:43:46  tng
 * Correct description of DocTypeHandler
 *
 * Revision 1.4  2000/03/02 19:55:39  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/24 20:16:49  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.2  2000/02/09 21:42:39  abagchi
 * Copyright swat
 *
 * Revision 1.1.1.1  1999/11/09 01:03:21  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:45:43  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */



#if !defined(DOCTYPEHANDLER_HPP)
#define DOCTYPEHANDLER_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>
#include <xercesc/validators/DTD/DTDAttDef.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
//  This abstract class defines the document type handler API's which can be
//  used to process the DTD events generated by the DTDScanner as it scans the
//  internal and external subset.

class VALIDATORS_EXPORT DocTypeHandler
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    DocTypeHandler()
    {
    }

    virtual ~DocTypeHandler()
    {
    }


    // -----------------------------------------------------------------------
    //  The document type handler virtual handler interface
    // -----------------------------------------------------------------------
    virtual void attDef
    (
        const   DTDElementDecl&     elemDecl
        , const DTDAttDef&          attDef
        , const bool                ignoring
    ) = 0;

    virtual void doctypeComment
    (
        const   XMLCh* const    comment
    ) = 0;

    virtual void doctypeDecl
    (
        const   DTDElementDecl& elemDecl
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const bool            hasIntSubset
        , const bool            hasExtSubset = false
    ) = 0;

    virtual void doctypePI
    (
        const   XMLCh* const    target
        , const XMLCh* const    data
    ) = 0;

    virtual void doctypeWhitespace
    (
        const   XMLCh* const    chars
        , const unsigned int    length
    ) = 0;

    virtual void elementDecl
    (
        const   DTDElementDecl& decl
        , const bool            isIgnored
    ) = 0;

    virtual void endAttList
    (
        const   DTDElementDecl& elemDecl
    ) = 0;

    virtual void endIntSubset() = 0;

    virtual void endExtSubset() = 0;

    virtual void entityDecl
    (
        const   DTDEntityDecl&  entityDecl
        , const bool            isPEDecl
        , const bool            isIgnored
    ) = 0;

    virtual void resetDocType() = 0;

    virtual void notationDecl
    (
        const   XMLNotationDecl&    notDecl
        , const bool                isIgnored
    ) = 0;

    virtual void startAttList
    (
        const   DTDElementDecl& elemDecl
    ) = 0;

    virtual void startIntSubset() = 0;

    virtual void startExtSubset() = 0;

    virtual void TextDecl
    (
        const   XMLCh* const    versionStr
        , const XMLCh* const    encodingStr
    ) = 0;


private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    DocTypeHandler(const DocTypeHandler&);
    DocTypeHandler& operator=(const DocTypeHandler&);
};

XERCES_CPP_NAMESPACE_END

#endif
