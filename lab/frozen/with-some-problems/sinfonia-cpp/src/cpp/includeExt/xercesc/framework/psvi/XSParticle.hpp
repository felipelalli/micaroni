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
 * $Log: XSParticle.hpp,v $
 * Revision 1.2  2005/01/21 20:27:13  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:01  fernandofernandes
 * no message
 *
 * Revision 1.6  2004/09/08 13:56:09  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.5  2003/12/01 23:23:26  neilg
 * fix for bug 25118; thanks to Jeroen Witmond
 *
 * Revision 1.4  2003/11/21 17:34:04  knoaman
 * PSVI update
 *
 * Revision 1.3  2003/11/14 22:47:53  neilg
 * fix bogus log message from previous commit...
 *
 * Revision 1.2  2003/11/14 22:33:30  neilg
 * Second phase of schema component model implementation.  
 * Implement XSModel, XSNamespaceItem, and the plumbing necessary
 * to connect them to the other components.
 * Thanks to David Cargill.
 *
 * Revision 1.1  2003/09/16 14:33:36  neilg
 * PSVI/schema component model classes, with Makefile/configuration changes necessary to build them
 *
 */

#if !defined(XSPARTICLE_HPP)
#define XSPARTICLE_HPP

#include <xercesc/framework/psvi/XSObject.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
 * This class describes all properties of a Schema Particle
 * component.
 * This is *always* owned by the validator /parser object from which
 * it is obtained.  
 */

// forward declarations
class XSElementDeclaration;
class XSModelGroup;
class XSWildcard;

class XMLPARSER_EXPORT XSParticle : public XSObject
{
public:

    // possible terms of this particle
    enum TERM_TYPE {
        /*
         * an empty particle
         */
        TERM_EMPTY          = 0,
        /*
         * the particle has element content
         */
        TERM_ELEMENT        = XSConstants::ELEMENT_DECLARATION,
        /*
         * the particle's content is a model group 
         */
        TERM_MODELGROUP     = XSConstants::MODEL_GROUP_DEFINITION,
        /*
         * the particle's content is a wildcard
         */
        TERM_WILDCARD       = XSConstants::WILDCARD
    };

    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    /** @name Constructors */
    //@{

    /**
      * The default constructor 
      *
      * @param  termType
      * @param  xsModel
      * @param  particleTerm
      * @param  minOccurs
      * @param  maxOccurs
      * @param  manager     The configurable memory manager
      */
    XSParticle
    (
        TERM_TYPE              termType
        , XSModel* const       xsModel
        , XSObject* const      particleTerm
        , int                  minOccurs
        , int                  maxOccurs
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    //@};

    /** @name Destructor */
    //@{
    ~XSParticle();
    //@}

    //---------------------
    /** @name XSParticle methods */
    //@{

    /**
     * [min occurs]: determines the minimum number of terms that can occur. 
     */
    int getMinOccurs() const;

    /**
     * [max occurs] determines the maximum number of terms that can occur. To 
     * query for value of unbounded use <code>maxOccursUnbounded</code>. 
     */
    int getMaxOccurs() const;

    /**
     * [max occurs] whether the maxOccurs value is unbounded.
     */
    bool getMaxOccursUnbounded() const;

    /**
     * Returns the type of the [term]: one of 
     * TERM_EMPTY, TERM_ELEMENT, TERM_MODELGROUP, or TERM_WILDCARD.
     */
    TERM_TYPE getTermType() const;

    /**
     * If this particle has an [element declaration] for its term,
     * this method returns that declaration; otherwise, it returns 0.
     * @returns The element declaration that is the [term] of this Particle
     * if and only if getTermType() == TERM_ELEMENT.
     */ 
    XSElementDeclaration *getElementTerm();

    /**
     * If this particle has a [model group] for its term,
     * this method returns that definition; otherwise, it returns 0.
     * @returns The model group that is the [term] of this Particle
     * if and only if getTermType() == TERM_MODELGROUP.
     */ 
    XSModelGroup *getModelGroupTerm();

    /**
     * If this particle has an [wildcard] for its term,
     * this method returns that declaration; otherwise, it returns 0.
     * @returns The wildcard declaration that is the [term] of this Particle
     * if and only if getTermType() == TERM_WILDCARD.
     */ 
    XSWildcard *getWildcardTerm();

    //@}

    //----------------------------------
    /** methods needed by implementation */
    //@{

    //@}
private:

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XSParticle(const XSParticle&);
    XSParticle & operator=(const XSParticle &);

protected:

    // -----------------------------------------------------------------------
    //  data members
    // -----------------------------------------------------------------------
    TERM_TYPE fTermType;
    int       fMinOccurs;
    int       fMaxOccurs;
    XSObject* fTerm;
};

inline int XSParticle::getMinOccurs() const
{
    return fMinOccurs;
}

inline int XSParticle::getMaxOccurs() const
{
    return fMaxOccurs;
}

inline bool XSParticle::getMaxOccursUnbounded() const
{
    return (fMaxOccurs == -1);
}

inline XSParticle::TERM_TYPE XSParticle::getTermType() const
{
    return fTermType;
}

XERCES_CPP_NAMESPACE_END

#endif
