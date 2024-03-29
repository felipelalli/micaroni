/*
 * Copyright 1999-2004 The Apache Software Foundation.
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
 * $Log: SynchronizedStringPool.hpp,v $
 * Revision 1.2  2005/01/21 20:27:30  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:16  fernandofernandes
 * no message
 *
 * Revision 1.2  2004/09/08 13:56:23  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.1  2003/10/09 13:51:16  neilg
 * implementation of a StringPool implementation that permits thread-safe updates.  This can now be used by a grammar pool that is locked so that scanners have somehwere to store information about newly-encountered URIs
 *
 */

#if !defined(SYNCHRONIZEDSTRINGPOOL_HPP)
#define SYNCHRONIZEDSTRINGPOOL_HPP

#include <xercesc/framework/MemoryManager.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/util/Mutexes.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
//  This class provides a synchronized string pool implementation.
//  This will necessarily be slower than the regular StringPool, so it
//  should only be used when updates need to be made in a thread-safe
//  way.  Updates will be made on datastructures local to this object;
//  all queries that don't involve mutation will first be directed at
//  the StringPool implementation with which this object is
//  constructed.
class XMLUTIL_EXPORT XMLSynchronizedStringPool : public XMLStringPool
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    XMLSynchronizedStringPool
    (
        const XMLStringPool *  constPool
        , const unsigned int   modulus = 109
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    virtual ~XMLSynchronizedStringPool();


    // -----------------------------------------------------------------------
    //  Pool management methods
    // -----------------------------------------------------------------------
    virtual unsigned int addOrFind(const XMLCh* const newString);
    virtual bool exists(const XMLCh* const newString) const;
    virtual bool exists(const unsigned int id) const;
    virtual void flushAll();
    virtual unsigned int getId(const XMLCh* const toFind) const;
    virtual const XMLCh* getValueForId(const unsigned int id) const;
    virtual unsigned int getStringCount() const;


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLSynchronizedStringPool(const XMLSynchronizedStringPool&);
    XMLSynchronizedStringPool& operator=(const XMLSynchronizedStringPool&);


    // -----------------------------------------------------------------------
    // private data members
    //  fConstPool
    //      the pool whose immutability we're protecting
    // fMutex
    //      mutex to permit synchronous updates of our StringPool
    const XMLStringPool* fConstPool;
    XMLMutex             fMutex;
};

XERCES_CPP_NAMESPACE_END

#endif
