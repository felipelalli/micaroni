#ifndef DomMemDebug_HEADER_GUARD_
#define DomMemDebug_HEADER_GUARD_

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
 * $Log: DomMemDebug.hpp,v $
 * Revision 1.3  2005/01/21 20:27:08  felipelalli
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
 * Revision 1.1.1.1  2002/02/01 22:21:44  peiyongz
 * sane_include
 *
 * Revision 1.4  2000/03/02 19:54:00  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/24 20:11:29  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.2  2000/02/06 07:47:32  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.1.1.1  1999/11/09 01:08:47  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:44:25  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

#include <xercesc/util/XercesDefs.hpp>

//
// This class aids in debugging memory management problems with the
//  reference counted DOM classes - DOMStrings, Nodes (including subclasses),
//  and NamedNodeMaps.
//
// Usage Example:
//      DomMemDebug  initialState;   // Captures allocation totals
//          ...                     //    Test code performs DOM
//          ...                     //    operations here.
//
//      DomMemDebug  exitState;     //   Captures post-test state.
//      ExitState.printDifference(initialState);  // Display leaks.
//
class CDOM_EXPORT DomMemDebug
{
public:
    int         liveStringHandles;
    int         totalStringHandles;
    int         liveStringBuffers;
    int         totalStringBuffers;
    int         liveNodeImpls;
    int         totalNodeImpls;
    int         liveNamedNodeMaps;
    int         totalNamedNodeMaps;

public:
    DomMemDebug();
    ~DomMemDebug();

    void        print();
    void        printDifference(const DomMemDebug &other);
    bool        operator == (const DomMemDebug &other);
    bool        operator != (const DomMemDebug &other);
    void        operator =  (const DomMemDebug &other);
};


#endif
