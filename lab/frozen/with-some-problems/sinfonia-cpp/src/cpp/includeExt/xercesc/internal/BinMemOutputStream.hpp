/*
 * Copyright 2003,2004 The Apache Software Foundation.
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
 * $Id: BinMemOutputStream.hpp,v 1.2 2005/01/21 20:27:17 felipelalli Exp $
 * $Log: BinMemOutputStream.hpp,v $
 * Revision 1.2  2005/01/21 20:27:17  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:02  fernandofernandes
 * no message
 *
 * Revision 1.3  2004/09/08 13:56:13  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.2  2004/02/16 04:02:34  neilg
 * fix for bug 26936
 *
 * Revision 1.1  2003/12/16 16:56:51  peiyongz
 * BinMemOutputStream
 *
 *
 */

#ifndef BINMEMOUTPUTSTREAM_HEADER_GUARD_
#define BINMEMOUTPUTSTREAM_HEADER_GUARD_

#include <xercesc/framework/BinOutputStream.hpp>
#include <xercesc/util/PlatformUtils.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT BinMemOutputStream : public BinOutputStream 
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------

    ~BinMemOutputStream();

    BinMemOutputStream
    (
         int                     initCapacity = 1023
       , MemoryManager* const    manager      = XMLPlatformUtils::fgMemoryManager
    );

    // -----------------------------------------------------------------------
    //  Implementation of the output stream interface
    // -----------------------------------------------------------------------
    virtual unsigned int curPos() const;

    virtual void writeBytes
    (
      const XMLByte*     const      toGo
    , const unsigned int            maxToWrite
    ) ;

    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    const XMLByte* getRawBuffer() const;

    unsigned int getSize() const;
    void reset();

private :
    // -----------------------------------------------------------------------
    //  Unimplemented methods.
    // -----------------------------------------------------------------------
    BinMemOutputStream(const BinMemOutputStream&);
    BinMemOutputStream& operator=(const BinMemOutputStream&);

    // -----------------------------------------------------------------------
    //  Private helpers
    // -----------------------------------------------------------------------
    void insureCapacity(const unsigned int extraNeeded);

    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fDataBuf
    //      The pointer to the buffer data. Its grown as needed. Its always
    //      one larger than fCapacity, to leave room for the null terminator.
    //
    //  fIndex
    //      The current index into the buffer, as characters are appended
    //      to it. If its zero, then the buffer is empty.
    //
    //  fCapacity
    //      The current capacity of the buffer. Its actually always one
    //      larger, to leave room for the null terminator.
    //
    // -----------------------------------------------------------------------
    MemoryManager*  fMemoryManager;
    XMLByte*        fDataBuf;
    unsigned int    fIndex;
    unsigned int    fCapacity;

};


XERCES_CPP_NAMESPACE_END

#endif

