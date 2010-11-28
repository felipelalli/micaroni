#ifndef IDOM_HEADER_GUARD_HPP
#define IDOM_HEADER_GUARD_HPP


/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
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
 * $Log: IDOM.hpp,v $
 * Revision 1.3  2005/01/21 20:27:14  felipelalli
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
 * Revision 1.1.1.1  2002/02/01 22:21:55  peiyongz
 * sane_include
 *
 * Revision 1.4  2001/06/08 21:23:02  tng
 * IDOM: Remove the non-standard extension where XML Decl as a node
 *
 * Revision 1.3  2001/06/04 20:11:53  tng
 * IDOM: Complete IDNodeIterator, IDTreeWalker, IDNodeFilter.
 *
 * Revision 1.2  2001/05/11 13:25:48  tng
 * Copyright update.
 *
 * Revision 1.1.1.1  2001/04/03 00:14:26  andyh
 * IDOM
 *
 */

//
//  This is the primary header file for inclusion in application
//  programs using the C++ XML Document Object Model API.
//

#include <xercesc/idom/IDOM_Attr.hpp>
#include <xercesc/idom/IDOM_CDATASection.hpp>
#include <xercesc/idom/IDOM_CharacterData.hpp>
#include <xercesc/idom/IDOM_Comment.hpp>
#include <xercesc/idom/IDOM_Document.hpp>
#include <xercesc/idom/IDOM_DocumentFragment.hpp>
#include <xercesc/idom/IDOM_DocumentType.hpp>
#include <xercesc/idom/IDOM_DOMException.hpp>
#include <xercesc/idom/IDOM_DOMImplementation.hpp>
#include <xercesc/idom/IDOM_Element.hpp>
#include <xercesc/idom/IDOM_Entity.hpp>
#include <xercesc/idom/IDOM_EntityReference.hpp>
#include <xercesc/idom/IDOM_NamedNodeMap.hpp>
#include <xercesc/idom/IDOM_Node.hpp>
#include <xercesc/idom/IDOM_NodeFilter.hpp>
#include <xercesc/idom/IDOM_NodeIterator.hpp>
#include <xercesc/idom/IDOM_NodeList.hpp>
#include <xercesc/idom/IDOM_Notation.hpp>
#include <xercesc/idom/IDOM_ProcessingInstruction.hpp>
#include <xercesc/idom/IDOM_Range.hpp>
#include <xercesc/idom/IDOM_RangeException.hpp>
#include <xercesc/idom/IDOM_Text.hpp>
#include <xercesc/idom/IDOM_TreeWalker.hpp>

#endif
