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
 * $Id: XMemory.hpp,v 1.2 2005/01/21 20:27:32 felipelalli Exp $
 */


#if !defined(XMEMORY_HPP)
#define XMEMORY_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <stdlib.h>

XERCES_CPP_NAMESPACE_BEGIN

class MemoryManager;

/**
 *  This class makes it possible to override the C++ memory management by
 *  adding new/delete operators to this base class.
 *
 *  This class is used in conjuction with the pluggable memory manager. It
 *  allows applications to control Xerces memory management.
 */

class XMLUTIL_EXPORT XMemory
{
public :
    // -----------------------------------------------------------------------
    //  The C++ memory management
    // -----------------------------------------------------------------------
    /** @name The C++ memory management */
    //@{

    /**
      * This method overrides operator new
      *
      * @param size The requested memory size
      */
    void* operator new(size_t size);

#if defined(XML_VISUALCPP)
    /**
      * This method overrides the MFC debug version of the operator new
      * 
      * @param size   The requested memory size
      * @param file   The file where the allocation was requested
      * @param line   The line where the allocation was requested 
      */ 
    void* operator new(size_t size, const char* file, int line);
    /**
      * This method provides a matching delete for the MFC debug new
      * 
      * @param p      The pointer to the allocated memory
      * @param file   The file where the allocation was requested
      * @param line   The line where the allocation was requested 
      */ 
    void operator delete(void* p, const char* file, int line);
#endif

    /**
      * This method overrides placement operator new
      *
      * @param size   The requested memory size
      * @param memMgr An application's memory manager
      */
    void* operator new(size_t size, MemoryManager* memMgr);

    /**
      * This method overrides operator delete
      *
      * @param p The pointer to the allocated memory
      */
    void operator delete(void* p);

     //The Borland compiler is complaining about duplicate overloading of delete
#if !defined(XML_BORLAND)
    /**
      * This method provides a matching delete for the placement new
      *
      * @param p      The pointer to the allocated memory
      * @param memMgr An application's memory manager 
      */
    void operator delete(void* p, MemoryManager* memMgr);
#endif

    //@}

protected :
    // -----------------------------------------------------------------------
    //  Hidden Constructors
    // -----------------------------------------------------------------------
    /** @name Constructor */
    //@{

    /**
      * Protected default constructor and copy constructor
      */
    XMemory()
    {
    }

    XMemory(const XMemory&)
    {
    }
    //@}

#if defined(XML_BORLAND)
    virtual ~XMemory()
    {
    }
#endif

private:
    // -----------------------------------------------------------------------
    //  Unimplemented operators
    // -----------------------------------------------------------------------
    XMemory& operator=(const XMemory&);
};

XERCES_CPP_NAMESPACE_END

#endif
