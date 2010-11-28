/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001-2002 The Apache Software Foundation.  All rights
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
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log: IDOM_NodeIterator.hpp,v $
 * Revision 1.3  2005/01/21 20:27:16  felipelalli
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
 * Revision 1.2  2002/02/04 21:20:59  tng
 * Add DOM 2 Level missing functions:
 *   1. NodeIterator::getRoot
 *   2. TreeWalker::getRoot
 *   3. Element::hasAttribute
 *   4. Element::hasAttributeNS
 *   5. Node::hasAttributes
 *   6. Node::isSupported
 *
 * Revision 1.1.1.1  2002/02/01 22:21:56  peiyongz
 * sane_include
 *
 * Revision 1.3  2001/06/04 20:11:53  tng
 * IDOM: Complete IDNodeIterator, IDTreeWalker, IDNodeFilter.
 *
 * Revision 1.2  2001/05/11 13:25:53  tng
 * Copyright update.
 *
 * Revision 1.1.1.1  2001/04/03 00:14:31  andyh
 * IDOM
 *
 */

#ifndef IDOM_NodeIterator_HEADER_GUARD_
#define IDOM_NodeIterator_HEADER_GUARD_

#include "IDOM_NodeFilter.hpp"
#include "IDOM_Node.hpp"

class IDNodeIteratorImpl;

/**
 * NodeIterators are used to step through a set of nodes
 * e.g. the set of nodes in a NodeList, the document subtree governed by
 * a particular node, the results of a query, or any other set of nodes.
 * The set of nodes to be iterated is determined by the implementation
 * of the NodeIterator. DOM Level 2 specifies a single NodeIterator
 * implementation for document-order traversal of a document
 * subtree. Instances of these iterators are created by calling
 * <code>DocumentTraversal.createNodeIterator()</code>.
 *
 */
class CDOM_EXPORT IDOM_NodeIterator
{
    protected:
        IDOM_NodeIterator() {};
        IDOM_NodeIterator(const IDOM_NodeIterator &other) {};
        IDOM_NodeIterator & operator = (const IDOM_NodeIterator &other) {return *this;};

    public:
        /** @name Get functions. */
        //@{
        /**
         * The <code>root</code> node of the <code>NodeIterator</code>, as specified
         * when it was created.
         */
        virtual IDOM_Node*          getRoot() = 0;
        /**
          * Return which node types are presented via the iterator.
          * The available set of constants is defined in the IDOM_NodeFilter interface.
          *
          */
        virtual unsigned long       getWhatToShow() = 0;

        /**
          * Return The filter used to screen nodes.
          *
          */
        virtual IDOM_NodeFilter*     getFilter() = 0;

        /**
          * Return the expandEntityReferences flag.
          * The value of this flag determines whether the children of entity reference
          * nodes are visible to the IDOM_NodeFilter. If false, they will be skipped over.
          *
          */
        virtual bool getExpandEntityReferences() = 0;

        /**
          * Returns the next node in the set and advances the position of the iterator
          * in the set. After a IDOM_NodeIterator is created, the first call to nextNode()
          * returns the first node in the set.
          *
          * @exception DOMException
          *   INVALID_STATE_ERR: Raised if this method is called after the
          *   <code>detach</code> method was invoked.
          */
        virtual IDOM_Node*           nextNode() = 0;

        /**
          * Returns the previous node in the set and moves the position of the iterator
          * backwards in the set.
          *
          * @exception DOMException
          *   INVALID_STATE_ERR: Raised if this method is called after the
          *   <code>detach</code> method was invoked.
          */
        virtual IDOM_Node*           previousNode() = 0;
        //@}

        /** @name Detaching functions. */
        //@{
        /**
          * Detaches the iterator from the set which it iterated over, releasing any
          * computational resources and placing the iterator in the INVALID state. After
          * <code>detach</code> has been invoked, calls to <code>nextNode</code> or
          * <code>previousNode</code> will raise the exception INVALID_STATE_ERR.
          *
          */
        virtual void                 detach() = 0;
        //@}
};

#endif
