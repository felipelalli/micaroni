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
  * $Log: MemoryManager.hpp,v $
  * Revision 1.2  2005/01/21 20:27:09  felipelalli
  * colocando stlport 5.0 beta, o maldito erro continua.
  *
  * Revision 1.2  2005/01/10 23:15:55  fernandofernandes
  * no message
  *
  * Revision 1.3  2004/09/08 13:55:57  peiyongz
  * Apache License Version 2.0
  *
  * Revision 1.2  2003/04/27 17:17:01  jberry
  * Add include for stdlib to pull in size_t declaration
  *
  * Revision 1.1  2003/04/21 15:47:45  knoaman
  * Initial check-in.
  *
  */


#if !defined(MEMORYMANAGER_HPP)
#define MEMORYMANAGER_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <stdlib.h>


XERCES_CPP_NAMESPACE_BEGIN


/**
 *  Configurable memory manager
 *
 *  <p>This interface allows outside applications to plug in their own memory
 *  manager to be used by Xerces for memory allocation/deallocation.</p> 
 */
class XMLPARSER_EXPORT MemoryManager
{
public:
    // -----------------------------------------------------------------------
    //  Constructors are hidden, only the virtual destructor is exposed
    // -----------------------------------------------------------------------

    /** @name Destructor */
    //@{

    /**
      * Default destructor
      */
    virtual ~MemoryManager()
    {
    }
    //@}


    // -----------------------------------------------------------------------
    //  The virtual memory manager interface
    // -----------------------------------------------------------------------
    /** @name The pure virtual methods in this interface. */
    //@{

    /**
      * This method allocates requested memory.
      *
      * @param size The requested memory size
      *
      * @return A pointer to the allocated memory
      */
    virtual void* allocate(size_t size) = 0;

    /**
      * This method deallocates memory
      *
      * @param p The pointer to the allocated memory to be deleted
      */
    virtual void deallocate(void* p) = 0;

    //@}


protected :
    // -----------------------------------------------------------------------
    //  Hidden Constructors
    // -----------------------------------------------------------------------
    /** @name Constructor */
    //@{

    /**
      * Protected default constructor
      */
    MemoryManager()
    {
    }
    //@}



private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    MemoryManager(const MemoryManager&);
    MemoryManager& operator=(const MemoryManager&);
};

XERCES_CPP_NAMESPACE_END

#endif
