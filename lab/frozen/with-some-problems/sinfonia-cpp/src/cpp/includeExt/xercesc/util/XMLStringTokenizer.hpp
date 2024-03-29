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
 * $Id: XMLStringTokenizer.hpp,v 1.3 2005/01/21 20:27:31 felipelalli Exp $
 */

#if !defined(XMLSTRINGTOKENIZER_HPP)
#define XMLSTRINGTOKENIZER_HPP

#include <xercesc/util/RefArrayVectorOf.hpp>
#include <xercesc/util/XMLString.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
  * The string tokenizer class breaks a string into tokens.
  *
  * The XMLStringTokenizer methods do not distinguish among identifiers,
  * numbers, and quoted strings, nor do they recognize and skip comments
  *
  * A XMLStringTokenizer object internally maintains a current position within
  * the string to be tokenized. Some operations advance this current position
  * past the characters processed.
  */


  class XMLUTIL_EXPORT XMLStringTokenizer :public XMemory
{
public:
    // -----------------------------------------------------------------------
    //  Public Constructors
    // -----------------------------------------------------------------------
    /** @name Constructors */
    //@{

    /**
      * Constructs a string tokenizer for the specified string. The tokenizer
      * uses the default delimiter set, which is "\t\n\r\f": the space
      * character, the tab character, the newline character, the
      * carriage-return character, and the form-feed character. Delimiter
      * characters themselves will not be treated as tokens.
      *
      * @param  srcStr  The string to be parsed.
      * @param  manager Pointer to the memory manager to be used to
      *                 allocate objects.
      *
      */
	XMLStringTokenizer(const XMLCh* const srcStr,
                       MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    /**
      * Constructs a string tokenizer for the specified string. The characters
      * in the delim argument are the delimiters for separating tokens.
      * Delimiter characters themselves will not be treated as tokens.
      *
      * @param  srcStr  The string to be parsed.
      * @param  delim   The set of delimiters.
      * @param  manager Pointer to the memory manager to be used to
      *                 allocate objects.
      */
    XMLStringTokenizer(const XMLCh* const srcStr
                       , const XMLCh* const delim
                       , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    //@}

	// -----------------------------------------------------------------------
    //  Public Destructor
    // -----------------------------------------------------------------------
	/** @name Destructor. */
    //@{

    ~XMLStringTokenizer();

    //@}

    // -----------------------------------------------------------------------
    // Management methods
    // -----------------------------------------------------------------------
    /** @name Management Function */
    //@{

     /**
       * Tests if there are more tokens available from this tokenizer's string.
       *
       * Returns true if and only if there is at least one token in the string
       * after the current position; false otherwise.
       */
	bool hasMoreTokens();

    /**
      * Calculates the number of times that this tokenizer's nextToken method
      * can be called to return a valid token. The current position is not
      * advanced.
      *
      * Returns the number of tokens remaining in the string using the current
      * delimiter set.
      */
    int countTokens();

    /**
      * Returns the next token from this string tokenizer.
      *
      * Function allocated, function managed (fafm). The calling function
      * does not need to worry about deleting the returned pointer.
	  */
	XMLCh* nextToken();

    //@}

private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLStringTokenizer(const XMLStringTokenizer&);
    XMLStringTokenizer& operator=(const XMLStringTokenizer&);

    // -----------------------------------------------------------------------
    //  CleanUp methods
    // -----------------------------------------------------------------------
	void cleanUp();

    // -----------------------------------------------------------------------
    //  Helper methods
    // -----------------------------------------------------------------------
    bool isDelimeter(const XMLCh ch);

    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fOffset
    //      The current position in the parsed string.
    //
    //  fStringLen
    //      The length of the string parsed (for convenience).
    //
    //  fString
    //      The string to be parsed
	//
    //  fDelimeters
    //      A set of delimeter characters
    //
    //  fTokens
    //      A vector of the token strings
    // -----------------------------------------------------------------------
    int                 fOffset;
    int                 fStringLen;
	XMLCh*              fString;
    XMLCh*              fDelimeters;
	RefArrayVectorOf<XMLCh>* fTokens;
    MemoryManager*           fMemoryManager;
};


// ---------------------------------------------------------------------------
//  XMLStringTokenizer: CleanUp methods
// ---------------------------------------------------------------------------
inline void XMLStringTokenizer::cleanUp() {

	fMemoryManager->deallocate(fString);//delete [] fString;
    fMemoryManager->deallocate(fDelimeters);//delete [] fDelimeters;
    delete fTokens;
}

// ---------------------------------------------------------------------------
//  XMLStringTokenizer: Helper methods
// ---------------------------------------------------------------------------
inline bool XMLStringTokenizer::isDelimeter(const XMLCh ch) {

    return XMLString::indexOf(fDelimeters, ch) == -1 ? false : true;
}


// ---------------------------------------------------------------------------
//  XMLStringTokenizer: Management methods
// ---------------------------------------------------------------------------
inline int XMLStringTokenizer::countTokens() {

    if (fStringLen == 0)
		return 0;

    int  tokCount = 0;
    bool inToken = false;

    for (int i= fOffset; i< fStringLen; i++) {

        if (isDelimeter(fString[i])) {

            if (inToken) {
                inToken = false;
            }

            continue;
        }

		if (!inToken) {

            tokCount++;
            inToken = true;
        }

    } // end for

    return tokCount;
}

XERCES_CPP_NAMESPACE_END

#endif

/**
  * End of file XMLStringTokenizer.hpp
  */

