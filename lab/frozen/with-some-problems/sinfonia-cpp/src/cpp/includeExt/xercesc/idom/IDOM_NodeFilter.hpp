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
 * $Log: IDOM_NodeFilter.hpp,v $
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
 * Revision 1.2  2002/02/04 21:11:55  tng
 * Remove the phrase "Experimental".
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

// IDOM_NodeFilter.h: interface for the IDOM_NodeFilter class.
//
//////////////////////////////////////////////////////////////////////

#ifndef IDOM_NodeFilter_HEADER_GUARD_
#define IDOM_NodeFilter_HEADER_GUARD_

#include "IDOM_Node.hpp"

class IDNodeFilterImpl;


/**
 * Filters are objects that know how to "filter out" nodes. If a
 * <code>IDOM_NodeIterator</code> or <code>IDOM_TreeWalker</code> is given a
 * filter, it applies the filter before it returns the next node.
 *
 * If the filter says to accept the node, the iterator returns it; otherwise, the
 * iterator looks for the next node and pretends that the node that was rejected
 * was not there.
 *
 *  The DOM does not provide any filters. Filter is just an interface that users can
 *  implement to provide their own filters.
 *
 *  Filters do not need to know how to iterate, nor do they need to know anything
 *  about the data structure that is being iterated. This makes it very easy to write
 *  filters, since the only thing they have to know how to do is evaluate a single node.
 *  One filter may be used with a number of different kinds of iterators, encouraging
 *  code reuse.
 *
 */
class CDOM_EXPORT IDOM_NodeFilter
{
    protected:
        IDOM_NodeFilter() {};
        IDOM_NodeFilter(const IDOM_NodeFilter &other) {};
        IDOM_NodeFilter & operator = (const IDOM_NodeFilter &other) {return *this;};

    public:
        /** @name Enumerators for Node Filter */
        //@{
        /*
         *    <table><tr><td>FILTER_ACCEPT</td>
         *               <td>Accept the node. Navigation methods defined for
         *               NodeIterator or TreeWalker will return this node.</td>
         *           </tr>
         *           <tr>
         *               <td>FILTER_REJECT</td>
         *               <td>Reject the node. Navigation methods defined for
         *               NodeIterator or TreeWalker will not return this
         *               node. For TreeWalker, the children of this node will
         *               also be rejected. Iterators treat this as a synonym
         *               for FILTER_SKIP.</td>
         *           </tr>
         *           <tr><td>FILTER_SKIP</td>
         *               <td>Reject the node. Navigation methods defined for
         *               NodeIterator or TreeWalker will not return this
         *               node. For both NodeIterator and Treewalker, the
         *               children of this node will still be considered.</td>
         *           </tr>
         *    </table>
         *
         */
        enum FilterAction {FILTER_ACCEPT = 1,
                           FILTER_REJECT = 2,
                           FILTER_SKIP   = 3};

        enum ShowType {
            SHOW_ALL                       = 0x0000FFFF,
            SHOW_ELEMENT                   = 0x00000001,
            SHOW_ATTRIBUTE                 = 0x00000002,
            SHOW_TEXT                      = 0x00000004,
            SHOW_CDATA_SECTION             = 0x00000008,
            SHOW_ENTITY_REFERENCE          = 0x00000010,
            SHOW_ENTITY                    = 0x00000020,
            SHOW_PROCESSING_INSTRUCTION    = 0x00000040,
            SHOW_COMMENT                   = 0x00000080,
            SHOW_DOCUMENT                  = 0x00000100,
            SHOW_DOCUMENT_TYPE             = 0x00000200,
            SHOW_DOCUMENT_FRAGMENT         = 0x00000400,
            SHOW_NOTATION                  = 0x00000800
        };
        //@}

        /** @name Test function. */
        //@{
        /**
         * Test whether a specified node is visible in the logical view of a IDOM_TreeWalker
         * or IDOM_NodeIterator. This function will be called by the implementation of
         * IDOM_TreeWalker and IDOM_NodeIterator; it is not intended to be called directly from user
         * code.
         *
         * @param node The node to check to see if it passes the filter or not.
         * @return A constant to determine whether the node is accepted, rejected, or skipped.
         */
        virtual short acceptNode (const IDOM_Node* node) const =0;
        //@}

};

#endif
