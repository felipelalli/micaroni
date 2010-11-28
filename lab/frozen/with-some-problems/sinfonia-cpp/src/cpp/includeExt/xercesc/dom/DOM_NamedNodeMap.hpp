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
 * $Log: DOM_NamedNodeMap.hpp,v $
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
 * Revision 1.3  2002/02/20 18:17:00  tng
 * [Bug 5977] Warnings on generating apiDocs.
 *
 * Revision 1.2  2002/02/04 19:57:15  tng
 * Remove the phrase "Experimental".
 *
 * Revision 1.1.1.1  2002/02/01 22:21:45  peiyongz
 * sane_include
 *
 * Revision 1.13  2000/06/07 22:49:40  andyh
 * Memory usage reduction:  DOM NamedNodeMaps for attributes are allocated
 * only for elements that actually have attributes.  By Joe Polastre.
 *
 * Revision 1.12  2000/03/11 03:19:13  chchou
 * Fix bug # 19, add const keyword to API
 *
 * Revision 1.11  2000/03/02 19:53:56  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.10  2000/02/24 20:11:28  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.9  2000/02/17 17:47:24  andyh
 * Update Doc++ API comments
 * NameSpace update to track W3C
 * Changes were made by Chih Hsiang Chou
 *
 * Revision 1.8  2000/02/15 23:17:36  andyh
 * Update Doc++ API comments
 * NameSpace bugfix and update to track W3C
 * Chih Hsiang Chou
 *
 * Revision 1.7  2000/02/10 20:20:42  abagchi
 * Added docs for assignment operators
 *
 * Revision 1.6  2000/02/10 20:19:24  abagchi
 * Added docs for equality operators
 *
 * Revision 1.5  2000/02/06 07:47:30  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.4  2000/02/04 01:49:28  aruna1
 * TreeWalker and NodeIterator changes
 *
 * Revision 1.3  2000/01/22 01:38:29  andyh
 * Remove compiler warnings in DOM impl classes
 *
 * Revision 1.2  2000/01/05 01:16:07  andyh
 * DOM Level 2 core, namespace support added.
 *
 * Revision 1.1.1.1  1999/11/09 01:08:59  twl
 * Initial checkin
 *
 * Revision 1.3  1999/11/08 20:44:18  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

#ifndef DOM_NamedNodeMap_HEADER_GUARD_
#define DOM_NamedNodeMap_HEADER_GUARD_

#include <xercesc/util/XercesDefs.hpp>

#include <xercesc/dom/DOM_Node.hpp>
class NamedNodeMapImpl;

/**
*  <code>NamedNodeMap</code>s  are used to
* represent collections of nodes that can be accessed by name.
*
* Note that <code>NamedNodeMap</code> does not inherit from <code>NodeList</code>;
* <code>NamedNodeMap</code>s are not maintained in any particular order.
* Nodes contained in a <code>NamedNodeMap</code> may
* also be accessed by an ordinal index, but this is simply to allow
* convenient enumeration of the contents, and
* does not imply that the DOM specifies an order to these Nodes.
*/
class CDOM_EXPORT DOM_NamedNodeMap {
private:
    void     *fImpl;
	short    flagElem;

	static const unsigned short NNM_ELEMENT;
	static const unsigned short NNM_OTHER;	

public:
    /** @name Constructors and assignment operator */
    //@{
    /**
      * Default constructor for DOM_NamedNodeMap.  The resulting object does not
      * refer to an actual DOM_NamedNodeMap node; it will compare == to 0, and is similar
      * to a null object reference variable in Java. NamedNopes are instantiated
      * by these methods:  DOM_Node::getAttributes, DOM_DocumentType::getEntities
      * andDOM_DocumentType::getNotations
      *
      */
    DOM_NamedNodeMap();

    /**
      * Copy constructor.  Creates a new <code>DOM_NamedNodeMap</code> reference object
      * that refers to the same underlying NamedNodeMap as the original.
      *
      * @param other The object to be copied.
      */
    DOM_NamedNodeMap(const DOM_NamedNodeMap &other);

    /**
      * Assignment operator.
      *
      * @param other The object to be copied.
      */
    DOM_NamedNodeMap & operator = (const DOM_NamedNodeMap &other);

    /**
      * Assignment operator.
      *
      * @param other The object to be copied.
      */
    DOM_NamedNodeMap & operator = (const DOM_NullPtr *other);

    //@}
    /** @name Destructor. */
    //@{
    /**
      * Destructor for DOM_NamedNodeMap.  The object being destroyed is the reference
      * object, not the underlying NamedNodeMap itself.
      *
      * <p>Like most other DOM types in this implementation, memory management
      * of named node maps is automatic.  Instances of DOM_NamedNodeMap function
      * as references to an underlying heap based implementation object,
      * and should never be explicitly new-ed or deleted in application code, but
      * should appear only as local variables or function parameters.
	  *
	  */
    ~DOM_NamedNodeMap();

    //@}

    /** @Comparisons. */
    //@{
    /**
     *  Test whether this NamedNodeMap reference refers to the same underlying
     *  named node map as the other reference object.  This does not
     *  compare the contents of two different objects.
     *
     *  @param other The value to be compared
     *  @return Returns true if the underlying named node map is same
     */
    bool operator == (const DOM_NamedNodeMap &other) const;

    /**
     *  Test whether this NamedNodeMap reference refers to a different underlying
     *  named node map as the other reference object.  This does not
     *  compare the contents of two different objects.
     *
     *  @param other The value to be compared
     *  @return Returns true if the underlying named node map is different
     */
    bool operator != (const DOM_NamedNodeMap &other) const;


    /**
     *  Use this comparison operator to test whether a Named Node Map reference
     *  is null.
     *
     *  @param p The value to be compared, which must be 0 or null.
     *  @return Returns true if the named node map is null
     */
    bool operator == (const DOM_NullPtr *p) const;

    /**
     *  Use this comparison operator to test whether a Named Node Map reference
     *  is not null.
     *
     *  @param p The value to be compared, which must not be 0 or null.
     *  @return Returns true if the named node map is not null
     */
    bool operator != (const DOM_NullPtr *p) const;

    //@}

    /** @name Set functions. */
    //@{

    /**
    * Adds a node using its <code>nodeName</code> attribute.
    *
    * <br>As the <code>nodeName</code> attribute is used to derive the name
    * which the node must be stored under, multiple nodes of certain types
    * (those that have a "special" string value) cannot be stored as the names
    * would clash. This is seen as preferable to allowing nodes to be aliased.
    * @param arg A node to store in a named node map. The node will later be
    *   accessible using the value of the <code>nodeName</code> attribute of
    *   the node. If a node with that name is already present in the map, it
    *   is replaced by the new one.
    * @return If the new <code>Node</code> replaces an existing node the
    *   replaced <code>Node</code> is returned,
    *   otherwise <code>null</code> is returned.
    * @exception DOMException
    *   WRONG_DOCUMENT_ERR: Raised if <code>arg</code> was created from a
    *   different document than the one that created the
    *   <code>NamedNodeMap</code>.
    *   <br>NO_MODIFICATION_ALLOWED_ERR: Raised if this
    *   <code>NamedNodeMap</code> is readonly.
    *   <br>INUSE_ATTRIBUTE_ERR: Raised if <code>arg</code> is an
    *   <code>Attr</code> that is already an attribute of another
    *   <code>Element</code> object. The DOM user must explicitly clone
    *   <code>Attr</code> nodes to re-use them in other elements.
    */
    DOM_Node               setNamedItem(DOM_Node arg);

    //@}
    /** @name Get functions. */
    //@{

    /**
    * Returns the <code>index</code>th item in the map.
    *
    * If <code>index</code>
    * is greater than or equal to the number of nodes in the map, this returns
    * <code>null</code>.
    * @param index Index into the map.
    * @return The node at the <code>index</code>th position in the
    *   <code>NamedNodeMap</code>, or <code>null</code> if that is not a valid
    *   index.
    */
    DOM_Node               item(unsigned int index) const;

    /**
    * Retrieves a node specified by name.
    *
    * @param name The <code>nodeName</code> of a node to retrieve.
    * @return A <code>DOM_Node</code> (of any type) with the specified <code>nodeName</code>, or
    *   <code>null</code> if it does not identify any node in
    *   the map.
    */
    DOM_Node               getNamedItem(const DOMString &name) const;

    /**
    * The number of nodes in the map.
    *
    * The range of valid child node indices is
    * 0 to <code>length-1</code> inclusive.
    */
    unsigned int           getLength() const;

    //@}
    /** @name Functions to change the node collection. */
    //@{

    /**
    * Removes a node specified by name.
    *
    * If the removed node is an
    * <code>Attr</code> with a default value it is immediately replaced.
    * @param name The <code>nodeName</code> of a node to remove.
    * @return The node removed from the map or <code>null</code> if no node
    *   with such a name exists.
    * @exception DOMException
    *   NOT_FOUND_ERR: Raised if there is no node named <code>name</code> in
    *   the map.
    * <br>
    *   NO_MODIFICATION_ALLOWED_ERR: Raised if this <code>NamedNodeMap</code>
    *   is readonly.
    */
    DOM_Node               removeNamedItem(const DOMString &name);

    //@}
    /** @name Functions introduced in DOM Level 2. */
    //@{

    /**
     * Retrieves a node specified by local name and namespace URI.
     *
     * @param namespaceURI The <em>namespace URI</em> of
     *    the node to retrieve.
     * @param localName The <em>local name</em> of the node to retrieve.
     * @return A <code>DOM_Node</code> (of any type) with the specified
     *    local name and namespace URI, or <code>null</code> if they do not
     *    identify any node in the map.
     */
    DOM_Node               getNamedItemNS(const DOMString &namespaceURI,
	const DOMString &localName);

    /**
     * Adds a node using its <CODE>namespaceURI</CODE> and <CODE>localName</CODE>.
     *
     * @param arg A node to store in a named node map. The node will later be
     *       accessible using the value of the <CODE>namespaceURI</CODE> and
     *       <CODE>localName</CODE> attribute of the node. If a node with those
     *       namespace URI and local name is already present in the map, it is
     *       replaced by the new one.
     * @return If the new <code>DOM_Node</code> replaces an existing node the
     *   replaced <code>DOM_Node</code> is returned,
     *   otherwise <code>null</code> is returned.
     * @exception DOMException
     *   WRONG_DOCUMENT_ERR: Raised if <code>arg</code> was created from a
     *   different document than the one that created the
     *   <code>DOM_NamedNodeMap</code>.
     *   <br>NO_MODIFICATION_ALLOWED_ERR: Raised if this
     *   <code>vNamedNodeMap</code> is readonly.
     *   <br>INUSE_ATTRIBUTE_ERR: Raised if <code>arg</code> is an
     *   <code>DOM_Attr</code> that is already an attribute of another
     *   <code>DOM_Element</code> object. The DOM user must explicitly clone
     *   <code>DOM_Attr</code> nodes to re-use them in other elements.
     */
    DOM_Node               setNamedItemNS(DOM_Node arg);

    /**
     * Removes a node specified by local name and namespace URI.
     *
     * @param namespaceURI The <em>namespace URI</em> of
     *    the node to remove.
     * @param localName The <em>local name</em> of the
     *    node to remove. When this <code>DOM_NamedNodeMap</code> contains the
     *    attributes attached to an element, as returned by the attributes
     *    attribute of the <code>DOM_Node</code> interface, if the removed
     *    attribute is known to have a default value, an attribute
     *    immediately appears containing the default value
     *    as well as the corresponding namespace URI, local name, and prefix.
     * @return The node removed from the map if a node with such a local name
     *    and namespace URI exists.
     * @exception DOMException
     *   NOT_FOUND_ERR: Raised if there is no node named <code>name</code> in
     *   the map.
     * <br>
     *   NO_MODIFICATION_ALLOWED_ERR: Raised if this <code>DOM_NamedNodeMap</code>
     *   is readonly.
     */
    DOM_Node               removeNamedItemNS(const DOMString &namespaceURI,
	const DOMString &localName);

    //@}

 protected:

    DOM_NamedNodeMap(NamedNodeMapImpl *impl);
	DOM_NamedNodeMap(NodeImpl *impl);

    friend class DOM_DocumentType;
    friend class DOM_Node;


};

#endif

