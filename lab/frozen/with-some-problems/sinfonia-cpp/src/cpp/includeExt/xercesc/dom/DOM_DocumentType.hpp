/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2002 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log: DOM_DocumentType.hpp,v $
 * Revision 1.3  2005/01/21 20:27:06  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.1.1.1  2002/10/02 16:20:55  fernando
 * no message
 *
 * Revision 1.1.1.1  2002/03/23 18:02:15  cvs
 * Projeto Mega Turbo Bingo 2002
 * Stream Works (r), Mega Software (r)
 *
 * Barueri, S�o Paulo, 27 de mar�o de 2002
 * - vers�o limpa do projeto.
 *
 * Equipe de desenvolvimento:
 * - Fernando Fernandes
 * - Felipe Micaroni Lalli
 * - Luiz Cesar Borro
 *
 * Revision 1.1  2002/03/14 01:33:49  cvs
 * Includes do Xerces
 *
 * Revision 1.3  2002/02/20 18:17:00  tng
 * [Bug 5977] Warnings on generating apiDocs.
 *
 * Revision 1.2  2002/02/04 19:57:15  tng
 * Remove the phrase "Experimental".
 *
 * Revision 1.1.1.1  2002/02/01 22:21:45  peiyongz
 * sane_include
 *
 * Revision 1.8  2000/03/10 02:14:39  chchou
 * add null DOM_DocumentType constructor
 *
 * Revision 1.7  2000/03/02 19:53:55  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.6  2000/02/24 20:11:27  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.5  2000/02/17 17:47:24  andyh
 * Update Doc++ API comments
 * NameSpace update to track W3C
 * Changes were made by Chih Hsiang Chou
 *
 * Revision 1.4  2000/02/10 23:35:11  andyh
 * Update DOM_DOMImplementation::CreateDocumentType and
 * DOM_DocumentType to match latest from W3C
 *
 * Revision 1.3  2000/02/06 07:47:29  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  2000/01/05 01:16:07  andyh
 * DOM Level 2 core, namespace support added.
 *
 * Revision 1.1.1.1  1999/11/09 01:08:52  twl
 * Initial checkin
 *
 * Revision 1.3  1999/11/08 20:44:16  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

#ifndef DOM_DocumentType_HEADER_GUARD_
#define DOM_DocumentType_HEADER_GUARD_

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOM_Node.hpp>

class DOM_NamedNodeMap;
class DocumentTypeImpl;

/**
 * Each <code>Document</code> has a <code>doctype</code> whose value
 * is either <code>null</code> or a <code>DocumentType</code> object.
 *
 * The <code>DOM_DocumentType</code> class provides access
 *  to the list of entities and notations that are defined for the document.
 * <p>The DOM Level 1 doesn't support editing <code>DocumentType</code> nodes.
 */
class CDOM_EXPORT DOM_DocumentType: public DOM_Node {

public:
    /** @name Constructors and assignment operator */
    //@{
    /**
      * Default constructor for DOM_DocumentType.  The resulting object does not
      * refer to an actual DocumentType node; it will compare == to 0, and is similar
      * to a null object reference variable in Java.  It may subsequently be
      * assigned to refer to the actual DocumentType node.
      * <p>
      * A new DocumentType node for a document that does not already have one
      * can be created by DOM_Document::createDocumentType().
      *
      */
    DOM_DocumentType();

    /**
      * Constructor for a null DOM_DocumentType.
      * This allows passing 0 directly as a null DOM_DocumentType to
      * function calls that take DOM_DocumentType as parameters.
      *
      * @param nullPointer Must be 0.
      */
    DOM_DocumentType(int nullPointer);

    /**
      * Copy constructor.  Creates a new <code>DOM_Comment</code> that refers to the
      * same underlying node as the original.
      *
      *
      * @param other The object to be copied.
      */
    DOM_DocumentType(const DOM_DocumentType &other);


    /**
      * Assignment operator.
      *
      * @param other The object to be copied.
      */
    DOM_DocumentType & operator = (const DOM_DocumentType &other);

    /**
      * Assignment operator.  This overloaded variant is provided for
      *   the sole purpose of setting a DOM_Node reference variable to
      *   zero.  Nulling out a reference variable in this way will decrement
      *   the reference count on the underlying Node object that the variable
      *   formerly referenced.  This effect is normally obtained when reference
      *   variable goes out of scope, but zeroing them can be useful for
      *   global instances, or for local instances that will remain in scope
      *   for an extended time,  when the storage belonging to the underlying
      *   node needs to be reclaimed.
      *
      * @param val   Only a value of 0, or null, is allowed.
      */
    DOM_DocumentType & operator = (const DOM_NullPtr *val);

    //@}
    /** @name Destructor. */
    //@{
	 /**
	  * Destructor for DOM_DocumentType.  The object being destroyed is the reference
      * object, not the underlying DocumentType node itself.
	  *
	  */
    ~DOM_DocumentType();
    //@}

    /** @name Getter functions. */
    //@{
  /**
   * The name of DTD; i.e., the name immediately following the
   * <code>DOCTYPE</code> keyword in an XML source document.
   */
  DOMString       getName() const;

  /**
   * This function returns a  <code>NamedNodeMap</code> containing the general entities, both
   * external and internal, declared in the DTD. Parameter entities are not contained.
   * Duplicates are discarded.
   * <p>
   * Note: this functionality is not implemented in the initial release
   * of the parser, and the returned NamedNodeMap will be empty.
   */
  DOM_NamedNodeMap getEntities() const;


  /**
   * This function returns a named node map containing an entry for
   * each notation declared in a document's DTD.  Duplicates are discarded.
   *
   * <p>
   * Note: this functionality is not implemented in the initial release
   * of the parser, and the returned NamedNodeMap will be empty.
   */
  DOM_NamedNodeMap getNotations() const;
  //@}

    /** @name Functions introduced in DOM Level 2. */
    //@{
    /**
     * Get the public identifier of the external subset.
     *
     * @return The public identifier of the external subset.
     */
    DOMString     getPublicId() const;

    /**
     * Get the system identifier of the external subset.
     *
     * @return The system identifier of the external subset.
     */
    DOMString     getSystemId() const;

    /**
     * Get the internal subset as a string.
     *
     * @return The internal subset as a string.
     */
    DOMString     getInternalSubset() const;
    //@}

protected:
    DOM_DocumentType(DocumentTypeImpl *);

    friend class DOM_Document;
    friend class DOM_DOMImplementation;
};

#endif


