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
 * $Id: XProtoType.hpp,v 1.2 2005/01/21 20:27:19 felipelalli Exp $
 * $Log: XProtoType.hpp,v $
 * Revision 1.2  2005/01/21 20:27:19  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:05  fernandofernandes
 * no message
 *
 * Revision 1.5  2004/09/08 13:56:14  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.4  2004/01/29 11:46:30  cargilld
 * Code cleanup changes to get rid of various compiler diagnostic messages.
 *
 * Revision 1.3  2003/12/17 00:18:34  cargilld
 * Update to memory management so that the static memory manager (one used to call Initialize) is only for static data.
 *
 * Revision 1.2  2003/09/23 18:12:19  peiyongz
 * Macro re-organized: provide create/nocreate macros for abstract and
 * nonabstract classes
 *
 * Revision 1.1  2003/09/18 18:31:24  peiyongz
 * OSU: Object Serialization Utilities
 *
 */


#if !defined(XPROTOTYPE_HPP)
#define XPROTOTYPE_HPP

#include <xercesc/util/PlatformUtils.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XSerializeEngine;
class XSerializable;

class XMLUTIL_EXPORT XProtoType
{
public:

           void       store(XSerializeEngine& serEng) const;

    static void        load(XSerializeEngine&          serEng
                          , XMLByte*          const    name
                          , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
                          );

    // -------------------------------------------------------------------------------
    //  data
    //
    //  fClassName: 
    //            name of the XSerializable derivatives
    //
    //  fCreateObject:
    //            pointer to the factory method (createObject()) 
    //            of the XSerializable derivatives
    //
    // -------------------------------------------------------------------------------

    XMLByte*          fClassName;

    XSerializable*    (*fCreateObject)(MemoryManager*);

};

#define DECL_XPROTOTYPE(class_name) \
static  XProtoType        class##class_name;                   \
static  XSerializable*    createObject(MemoryManager* manager);

/***
 * For non-abstract class
 ***/
#define IMPL_XPROTOTYPE_TOCREATE(class_name) \
IMPL_XPROTOTYPE_INSTANCE(class_name) \
XSerializable* class_name::createObject(MemoryManager* manager) \
{return new (manager) class_name(manager);}

/***
* For abstract class
 ***/
#define IMPL_XPROTOTYPE_NOCREATE(class_name) \
IMPL_XPROTOTYPE_INSTANCE(class_name) \
XSerializable* class_name::createObject(MemoryManager*) \
{return 0;}


/***
 * Helper Macro 
 ***/
#define XPROTOTYPE_CLASS(class_name) ((XProtoType*)(&class_name::class##class_name))

#define IMPL_XPROTOTYPE_INSTANCE(class_name) \
XProtoType class_name::class##class_name = \
{(XMLByte*) #class_name, class_name::createObject };

XERCES_CPP_NAMESPACE_END

#endif
