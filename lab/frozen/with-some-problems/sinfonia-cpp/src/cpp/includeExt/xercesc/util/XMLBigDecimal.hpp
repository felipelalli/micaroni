/*
 * Copyright 2001-2004 The Apache Software Foundation.
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
 * $Id: XMLBigDecimal.hpp,v 1.3 2005/01/21 20:27:30 felipelalli Exp $
 */

#ifndef XML_BIGDECIMAL_HPP
#define XML_BIGDECIMAL_HPP

#include <xercesc/util/XMLNumber.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLUTIL_EXPORT XMLBigDecimal : public XMLNumber
{
public:

    /**
     * Constructs a newly allocated <code>XMLBigDecimal</code> object that
     * represents the value represented by the string.
     *
     * @param  strValue the <code>String</code> to be converted to an
     *                  <code>XMLBigDecimal</code>.
     * @param  manager  Pointer to the memory manager to be used to
     *                  allocate objects.
     * @exception  NumberFormatException  if the <code>String</code> does not
     *               contain a parsable XMLBigDecimal.
     */

    XMLBigDecimal
    (
        const XMLCh* const strValue
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    ~XMLBigDecimal();

    static int            compareValues(const XMLBigDecimal* const lValue
                                      , const XMLBigDecimal* const rValue
                                      , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    static XMLCh* getCanonicalRepresentation
                  (
                   const XMLCh*         const rawData
                 ,       MemoryManager* const memMgr = XMLPlatformUtils::fgMemoryManager
                  );

    static void  parseDecimal
                ( 
                   const XMLCh* const toParse
                ,        XMLCh* const retBuffer
                ,        int&         sign
                ,        int&         totalDigits
                ,        int&         fractDigits
                ,        MemoryManager* const manager
                );

    static void  parseDecimal
                ( 
                   const XMLCh*         const toParse
                ,        MemoryManager* const manager
                );

    /**
     *
     *  Deprecated: please use getRawData
     *
     */
    virtual XMLCh*        toString() const;
    
    virtual XMLCh*        getRawData() const;

    virtual const XMLCh*  getFormattedString() const;

    virtual int           getSign() const;

    const XMLCh*          getValue() const;

    unsigned int          getScale() const;

    unsigned int          getTotalDigit() const;

    inline XMLCh*         getIntVal() const;

    /**
     * Compares this object to the specified object.
     *
     * @param   other   the object to compare with.
     * @return  <code>-1</code> value is less than other's
     *          <code>0</code>  value equals to other's
     *          <code>+1</code> value is greater than other's
     */
     int toCompare(const XMLBigDecimal& other) const;

    /*
     * Sets the value to be converted
     *
     * @param   strValue the value to convert
     */
    void setDecimalValue(const XMLCh* const strValue);

    MemoryManager* getMemoryManager() const;

    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(XMLBigDecimal)

    XMLBigDecimal(MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

private:

    void  cleanUp();
    
    // -----------------------------------------------------------------------
    //  Unimplemented contstructors and operators
    // -----------------------------------------------------------------------       
    XMLBigDecimal(const XMLBigDecimal& other);
    XMLBigDecimal& operator=(const XMLBigDecimal& other);        
    
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fSign
    //     sign
    //
    //  fTotalDigits
    //     the total number of didits 
    //
    //  fScale
    //     the number of digits to the right of the decimal point
    //
    //  fIntVal
    //     The value of this BigDecimal, w/o
    //         leading whitespace, leading zero
    //         decimal point
    //         trailing zero, trailing whitespace
    //
    //  fRawData
    //     to preserve the original string used to construct this object,
    //     needed for pattern matching.
    //
    // -----------------------------------------------------------------------
    int            fSign;
    unsigned int   fTotalDigits;
    unsigned int   fScale;
    unsigned int   fRawDataLen;
    XMLCh*         fRawData;
    XMLCh*         fIntVal;
    MemoryManager* fMemoryManager;

};

inline int XMLBigDecimal::getSign() const
{
    return fSign;
}

inline const XMLCh* XMLBigDecimal::getValue() const
{
    return fIntVal;
}

inline unsigned int XMLBigDecimal::getScale() const
{
    return fScale;
}

inline unsigned int XMLBigDecimal::getTotalDigit() const
{
    return fTotalDigits;
}

inline XMLCh*  XMLBigDecimal::getRawData() const
{
    return fRawData;
}

inline const XMLCh*  XMLBigDecimal::getFormattedString() const
{
    return fRawData;
}

inline MemoryManager* XMLBigDecimal::getMemoryManager() const
{
    return fMemoryManager;
}

inline XMLCh*  XMLBigDecimal::getIntVal() const
{
    return fIntVal;
}

//
// The caller needs to de-allocate the memory allocated by this function
//
inline XMLCh*  XMLBigDecimal::toString() const
{
    // Return data using global operator new
    return XMLString::replicate(fRawData);
}

XERCES_CPP_NAMESPACE_END

#endif
