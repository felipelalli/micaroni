/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2000 The Apache Software Foundation.  All rights
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
 * $Log: DOM_Entity.hpp,v $
 * Revision 1.3  2005/01/21 20:27:06  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.1.1.1  2002/10/02 16:20:56  fernando
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
 * Revision 1.2  2002/02/20 18:17:00  tng
 * [Bug 5977] Warnings on generating apiDocs.
 *
 * Revision 1.1.1.1  2002/02/01 22:21:45  peiyongz
 * sane_include
 *
 * Revision 1.8  2000/09/09 00:11:46  andyh
 * Virtual Destructor Patch, submitted by Kirk Wylie
 *
 * Revision 1.7  2000/04/19 02:26:16  aruna1
 * Full support for DOM_EntityReference, DOM_Entity and DOM_DocumentType introduced
 *
 * Revision 1.6  2000/03/11 02:58:38  chchou
 * Fix bug # 18, remove set method of readonly attributes
 *
 * Revision 1.5  2000/03/02 19:53:55  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.4  2000/02/24 20:11:28  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.3  2000/02/06 07:47:30  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  2000/01/05 01:16:07  andyh
 * DOM Level 2 core, namespace support added.
 *
 * Revision 1.1.1.1  1999/11/09 01:08:58  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:44:17  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

#ifndef DOM_Entity_HEADER_GUARD_
#define DOM_Entity_HEADER_GUARD_

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOM_Node.hpp>

class EntityImpl;

/**
 * This interface represents an entity, either parsed or unparsed, in an XML
 * document.
 *
 * Note that this models the entity itself not the entity
 * declaration. <code>Entity</code> declaration modeling has been left for a
 * later Level of the DOM specification.
 * <p>The <code>nodeName</code> attribute that is inherited from
 * <code>Node</code> contains the name of the entity.
 * <p>An XML processor may choose to completely expand entities before  the
 * structure model is passed to the DOM; in this case there will be no
 * <code>EntityReference</code> nodes in the document tree.
 *
 * <p>Note: the first release of this parser does not create entity
 *    nodes when reading an XML document.  Entities may be
 *    programatically created using DOM_Document::createEntity().
 */
class CDOM_EXPORT DOM_Entity: public DOM_Node {
public:
    /** @name Constructors and assignment operator */
    //@{
    /**
      * Default constructor for DOM_Entity.
      *
      */
    DOM_Entity();

    /**
      * Copy constructor.
      *
      * @param other The object to be copied.
      */
    DOM_Entity(const DOM_Entity &other);

    /**
      * Assignment operator.
      *
      * @param other The object to be copied.
      */
    DOM_Entity & operator = (const DOM_Entity &other);

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
    DOM_Entity & operator = (const DOM_NullPtr *val);

    //@}
    /** @name Destructor. */
    //@{
	 /**
	  * Destructor for DOM_Entity.
	  *
	  */
    ~DOM_Entity();

    //@}
    /** @name Get functions. */
    //@{
  /**
   * The public identifier associated with the entity, if specified.
   *
   * If the public identifier was not specified, this is <code>null</code>.
   */
  DOMString        getPublicId() const;

  /**
   * The system identifier associated with the entity, if specified.
   *
   * If the system identifier was not specified, this is <code>null</code>.
   */
  DOMString        getSystemId() const;

  /**
   * For unparsed entities, the name of the notation for the entity.
   *
   * For parsed entities, this is <code>null</code>.
   */
  DOMString        getNotationName() const;

  DOM_Node		getFirstChild() const;
  DOM_Node      getLastChild() const;
  DOM_NodeList  getChildNodes() const;
  bool          hasChildNodes() const;
  DOM_Node		getPreviousSibling() const;
  DOM_Node		getNextSibling() const;
  //@}

protected:
    DOM_Entity(EntityImpl *impl);

    friend class DOM_Document;
};

#endif

