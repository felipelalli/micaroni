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
 * $Log: Mutexes.hpp,v $
 * Revision 1.3  2005/01/21 20:27:27  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:10  fernandofernandes
 * no message
 *
 * Revision 1.5  2004/09/08 13:56:22  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.4  2003/05/15 19:04:35  knoaman
 * Partial implementation of the configurable memory manager.
 *
 * Revision 1.3  2003/03/07 18:11:54  tng
 * Return a reference instead of void for operator=
 *
 * Revision 1.2  2002/11/04 15:22:04  tng
 * C++ Namespace Support.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:11  peiyongz
 * sane_include
 *
 * Revision 1.4  2000/03/02 19:54:42  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/24 20:05:24  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.2  2000/02/06 07:48:02  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.1.1.1  1999/11/09 01:04:46  twl
 * Initial checkin
 *
 * Revision 1.3  1999/11/08 20:45:10  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */


#if !defined(MUTEXES_HPP)
#define MUTEXES_HPP

#include <xercesc/util/XMemory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT XMLMutex : public XMemory
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    XMLMutex();

    ~XMLMutex();


    // -----------------------------------------------------------------------
    //  Lock control methods
    // -----------------------------------------------------------------------
    void lock();
    void unlock();


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLMutex(const XMLMutex&);
    XMLMutex& operator=(const XMLMutex&);


    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fHandle
    //      The raw mutex handle. Its just a void pointer so we do not
    //      pass judgement on its value at all. We just pass it into the
    //      platform utilities methods which knows what's really in it.
    // -----------------------------------------------------------------------
    void*   fHandle;


    // -----------------------------------------------------------------------
    //  Sun PlatformUtils needs acess to fHandle to initialize the
    //  atomicOpsMutex at startup.
    // -----------------------------------------------------------------------
    friend class XMLPlatformUtils;
};


class XMLUTIL_EXPORT XMLMutexLock : public XMemory
{
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
public:
    XMLMutexLock(XMLMutex* const toLock);
    ~XMLMutexLock();


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLMutexLock();
    XMLMutexLock(const XMLMutexLock&);
    XMLMutexLock& operator=(const XMLMutexLock&);


    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fToLock
    //      The mutex object that we are locking
    // -----------------------------------------------------------------------
    XMLMutex*   fToLock;
};

XERCES_CPP_NAMESPACE_END

#endif
