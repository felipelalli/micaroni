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
 * $Log: DefaultPanicHandler.hpp,v $
 * Revision 1.2  2005/01/21 20:27:25  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:10  fernandofernandes
 * no message
 *
 * Revision 1.4  2004/09/08 13:56:21  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.3  2003/12/24 17:12:21  cargilld
 * Memory management update.
 *
 * Revision 1.2  2003/03/10 16:05:11  peiyongz
 * assignment operator
 *
 * Revision 1.1  2003/03/09 17:06:16  peiyongz
 * PanicHandler
 *
 * $Id: DefaultPanicHandler.hpp,v 1.2 2005/01/21 20:27:25 felipelalli Exp $
 *
 */


#ifndef DEFAULT_PANICHANDLER_HPP
#define DEFAULT_PANICHANDLER_HPP

#include <xercesc/util/PanicHandler.hpp>
#include <xercesc/util/PlatformUtils.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
  * Receive notification of panic.
  *
  * <p>This is Xerces' default implementation of the PanicHanlder 
  *    interface, which will be instantiated and used in the 
  *    absence of an application's panic handler.
  * </p>
  */

class XMLUTIL_EXPORT DefaultPanicHandler : public XMemory, public PanicHandler
{
public:

    /** @name hidden Constructors */
    //@{
    /** Default constructor */
    DefaultPanicHandler(){};

    /** Destructor */
    virtual ~DefaultPanicHandler(){};
    //@}

    /** @name Implement virtual panic handler interface */
    //@{
   /**
    * Receive notification of panic
    *
    * <p>Upon invocation, a corresponding error message will be output 
    *    to the stderr, and program exit.
    * </p>
    *
    * @param reason The reason of panic
    *
    */
    virtual void panic(const PanicHandler::PanicReasons reason);
    //@}

private:

    /* Unimplemented Constructors and operators */
    /* Copy constructor */
    DefaultPanicHandler(const PanicHandler&);
    
    /** Assignment operator */
    DefaultPanicHandler& operator=(const DefaultPanicHandler&);

};

XERCES_CPP_NAMESPACE_END

#endif
