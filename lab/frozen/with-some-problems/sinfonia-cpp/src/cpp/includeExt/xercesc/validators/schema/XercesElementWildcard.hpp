/*
 * Copyright 2001,2004 The Apache Software Foundation.
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
 * $Log: XercesElementWildcard.hpp,v $
 * Revision 1.3  2005/01/21 20:28:02  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:49  fernandofernandes
 * no message
 *
 * Revision 1.3  2004/09/08 13:56:58  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.2  2002/11/04 14:49:42  tng
 * C++ Namespace Support.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:50  peiyongz
 * sane_include
 *
 * Revision 1.2  2001/11/21 14:30:13  knoaman
 * Fix for UPA checking.
 *
 * Revision 1.1  2001/08/21 15:58:42  tng
 * Schema: New files XercesElementWildCard.
 *

*/


#if !defined(XERCESELEMENTWILDCARD_HPP)
#define XERCESELEMENTWILDCARD_HPP

#include <xercesc/util/QName.hpp>
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/validators/schema/SubstitutionGroupComparator.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  Forward declarations
// ---------------------------------------------------------------------------
class SchemaGrammar;


class VALIDATORS_EXPORT XercesElementWildcard
{

public :

    // -----------------------------------------------------------------------
    //  Class static methods
    // -----------------------------------------------------------------------
    /*
     * check whether two elements are in conflict
     */
    static bool conflict(SchemaGrammar* const         pGrammar,
                         ContentSpecNode::NodeTypes   type1,
                         QName*                       q1,
                         ContentSpecNode::NodeTypes   type2,
                         QName*                       q2,
                         SubstitutionGroupComparator* comparator);

private:

    // -----------------------------------------------------------------------
    //  private helper methods
    // -----------------------------------------------------------------------
    static bool uriInWildcard(SchemaGrammar* const         pGrammar,
                              QName*                       qname,
                              unsigned int                 wildcard,
                              ContentSpecNode::NodeTypes   wtype,
                              SubstitutionGroupComparator* comparator);

    static bool wildcardIntersect(ContentSpecNode::NodeTypes t1,
                                  unsigned int               w1,
                                  ContentSpecNode::NodeTypes t2,
                                  unsigned int               w2);

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XercesElementWildcard();
    ~XercesElementWildcard();
};

XERCES_CPP_NAMESPACE_END

#endif // XERCESELEMENTWILDCARD_HPP

