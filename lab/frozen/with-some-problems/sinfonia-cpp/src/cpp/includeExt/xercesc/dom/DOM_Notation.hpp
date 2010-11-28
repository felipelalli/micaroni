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
 * $Log: DOM_Notation.hpp,v $
 * Revision 1.3  2005/01/21 20:27:07  felipelalli
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
 * Revision 1.1.1.1  2002/02/01 22:21:46  peiyongz
 * sane_include
 *
 * Revision 1.6  2000/03/11 02:58:39  chchou
 * Fix bug # 18, remove set method of readonly attributes
 *
 * Revision 1.5  2000/03/02 19:53:57  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.4  2000/02/24 20:11:28  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.3  2000/02/06 07:47:31  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  2000/01/05 01:16:08  andyh
 * DOM Level 2 core, namespace support added.
 *
 * Revision 1.1.1.1  1999/11/09 01:09:03  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:44:21  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

#ifndef DOM_Notation_HEADER_GUARD_
#define DOM_Notation_HEADER_GUARD_

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOM_Node.hpp>

class NotationImpl;

/**
 * This interface represents a notation declared in the DTD. A notation either
 * declares, by name, the format of an unparsed entity (see section 4.7 of
 * the XML 1.0 specification), or is used for formal declaration of
 * Processing Instruction targets (see section 2.6 of the XML 1.0
 * specification). The <code>nodeName</code> attribute inherited from
 * <code>Node</code> is set to the declared name of the notation.
 * <p>The DOM Level 1 does not support editing <code>Notation</code> nodes;
 * they are therefore readonly.
 * <p>A <code>Notation</code> node does not have any parent.
 */
class CDOM_EXPORT DOM_Notation: public DOM_Node {
public:
    /** @name Constructors and assignment operator */
    //@{
    /**
      * Default constructor for DOM_Notation.  The resulting object does not
    * refer to an actual Notation node; it will compare == to 0, and is similar
    * to a null object reference variable in Java.  It may subsequently be
    * assigned to refer to an actual Notation node.
    * <p>
    * New notation nodes are created by DOM_Document::createNotation().
    *
      *
      */
    DOM_Notation();

    /**
      * Copy constructor.  Creates a new <code>DOM_Notation</code> that refers to the
      * same underlying node as the original.  See also DOM_Node::clone(),
      * which will copy the actual notation node, rather than just creating a new
      * reference to the original node.
      *
      * @param other The object to be copied.
      */
    DOM_Notation(const DOM_Notation &other);

    /**
      * Assignment operator.
      *
      * @param other The object to be copied.
      */
    DOM_Notation & operator = (const DOM_Notation &other);

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
    DOM_Notation & operator = (const DOM_NullPtr *val);


    //@}
    /** @name Destructor. */
    //@{
	 /**
	  * Destructor for DOM_Notation.  The object being destroyed is the reference
      * object, not the underlying Notation node itself.
      *
	  */
    ~DOM_Notation();

    //@}
    /** @name Get functions. */
    //@{

    /**
     * Get the public identifier of this notation.
     *
     * If the  public identifier was not
     * specified, this is <code>null</code>.
     * @return Returns the public identifier of the notation
     */
    DOMString        getPublicId() const;
    /**
     * Get the system identifier of this notation.
     *
     * If the  system identifier was not
     * specified, this is <code>null</code>.
     * @return Returns the system identifier of the notation
     */
    DOMString        getSystemId() const;


    //@}

protected:
    DOM_Notation(NotationImpl *impl);

    friend class DOM_Document;

};

#endif


