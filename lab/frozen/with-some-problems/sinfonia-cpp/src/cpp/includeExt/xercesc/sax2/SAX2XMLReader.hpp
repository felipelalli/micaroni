/*
 * Copyright 1999-2001,2004 The Apache Software Foundation.
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
 * $Log: SAX2XMLReader.hpp,v $
 * Revision 1.3  2005/01/21 20:27:21  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:08  fernandofernandes
 * no message
 *
 * Revision 1.12  2004/09/30 14:07:43  peiyongz
 * setInputBufferSize
 *
 * Revision 1.11  2004/09/08 13:56:20  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.10  2003/03/07 18:10:30  tng
 * Return a reference instead of void for operator=
 *
 * Revision 1.9  2003/01/09 19:07:27  tng
 * [Bug 15802] Add "const" qualifier to getURIText.
 *
 * Revision 1.8  2002/12/23 15:23:18  knoaman
 * Added a public api to various parsers to return the src offset within the input
 * source.
 *
 * Revision 1.7  2002/11/04 14:55:45  tng
 * C++ Namespace Support.
 *
 * Revision 1.6  2002/07/11 18:29:09  knoaman
 * Grammar caching/preparsing - initial implementation.
 *
 * Revision 1.5  2002/07/04 15:35:44  tng
 * API Documentation typo fix.
 *
 * Revision 1.4  2002/06/27 18:46:53  tng
 * API Documentation Update.
 *
 * Revision 1.3  2002/06/17 15:39:49  tng
 * To be consistent, SAX2 is updated with:
 * 1. the progressive parse methods should use the fReuseGrammar flag set from setFeature instead of using parameter
 * 2. add feature "http://apache.org/xml/features/continue-after-fatal-error", and users should use setFeature instead of setExitOnFirstFatalError
 * 3. add feature "http://apache.org/xml/features/validation-error-as-fatal", and users should use setFeature instead of setValidationConstraintFatal
 *
 * Revision 1.2  2002/05/30 16:22:53  tng
 * Add feature to optionally ignore external DTD.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:09  peiyongz
 * sane_include
 *
 * Revision 1.18  2002/01/28 18:45:40  knoaman
 * Update documentation for SAX2 feature 'namespace-prefixes'.
 *
 * Revision 1.17  2002/01/28 17:08:33  knoaman
 * SAX2-ext's DeclHandler support.
 *
 * Revision 1.16  2002/01/18 16:31:26  tng
 * Break program.xml which takes too long to load, into program-sax.xml, program-sax2.xml, program-dom.xml, program-idom.xml.
 *
 * Revision 1.15  2002/01/02 15:36:54  tng
 * Some documentation update.
 *
 * Revision 1.14  2001/11/20 18:51:44  tng
 * Schema: schemaLocation and noNamespaceSchemaLocation to be specified outside the instance document.  New methods setExternalSchemaLocation and setExternalNoNamespaceSchemaLocation are added (for SAX2, two new properties are added).
 *
 * Revision 1.13  2001/11/14 14:15:59  tng
 * Update SAX2 feature documentation.
 *
 * Revision 1.12  2001/09/12 13:03:43  tng
 * [Bug 3155] SAX2 does not offer progressive parse.
 *
 * Revision 1.11  2001/08/01 19:11:02  tng
 * Add full schema constraint checking flag to the samples and the parser.
 *
 * Revision 1.10  2001/06/27 17:40:16  knoaman
 * Fix for bug #2353.
 *
 * Revision 1.9  2001/06/19 16:44:31  tng
 * Add installAdvDocHandler to SAX2XMLReader as the code is there already.
 *
 * Revision 1.8  2001/06/04 21:03:07  jberry
 * Add pure virtual getErrorCount to SAX2XMLReader interface.
 *
 * Revision 1.7  2001/05/11 13:26:25  tng
 * Copyright update.
 *
 * Revision 1.6  2001/02/15 15:56:31  tng
 * Schema: Add setSchemaValidation and getSchemaValidation for DOMParser and SAXParser.
 * Add feature "http://apache.org/xml/features/validation/schema" for SAX2XMLReader.
 * New data field  fSchemaValidation in XMLScanner as the flag.
 *
 * Revision 1.5  2001/01/12 21:22:00  tng
 * Documentation Enhancement: Add list of SAX2 feature strings that are supported.
 *
 * Revision 1.4  2000/12/22 15:17:04  tng
 * SAX2-ext's LexicalHandler support added by David Bertoni.
 *
 * Revision 1.3  2000/08/09 22:19:29  jpolast
 * many conformance & stability changes:
 *   - ContentHandler::resetDocument() removed
 *   - attrs param of ContentHandler::startDocument() made const
 *   - SAXExceptions thrown now have msgs
 *   - removed duplicate function signatures that had 'const'
 *       [ eg: getContentHander() ]
 *   - changed getFeature and getProperty to apply to const objs
 *   - setProperty now takes a void* instead of const void*
 *   - SAX2XMLReaderImpl does not inherit from SAXParser anymore
 *   - Reuse Validator (http://apache.org/xml/features/reuse-validator) implemented
 *   - Features & Properties now read-only during parse
 *
 * Revision 1.2  2000/08/07 18:21:27  jpolast
 * change SAX_EXPORT module to SAX2_EXPORT
 *
 * Revision 1.1  2000/08/02 18:02:35  jpolast
 * initial checkin of sax2 implementation
 * submitted by Simon Fell (simon@fell.com)
 * and Joe Polastre (jpolast@apache.org)
 *
 *
 */

#ifndef SAX2XMLReader_HPP
#define SAX2XMLReader_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class ContentHandler ;
class DTDHandler;
class EntityResolver;
class ErrorHandler;
class InputSource;
class LexicalHandler;
class DeclHandler;
class XMLDocumentHandler;
class Grammar;

class SAX2_EXPORT SAX2XMLReader
{
public:
    // -----------------------------------------------------------------------
    //  Class types
    // -----------------------------------------------------------------------
    /** @name Public constants */
    //@{

    /** ValScheme enum used in setValidationScheme
      *    Val_Never:  Do not report validation errors.
      *    Val_Always: The parser will always report validation errors.
      *    Val_Auto:   The parser will report validation errors only if a grammar is specified.
      *
      * @see #setValidationScheme
      */
    enum ValSchemes
    {
        Val_Never
        , Val_Always
        , Val_Auto
    };
    //@}


    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    /** @name Constructors and Destructor */
    //@{
    /** The default constructor */
    SAX2XMLReader()
    {
    }
    /** The destructor */
    virtual ~SAX2XMLReader()
    {
    }
    //@}

    //-----------------------------------------------------------------------
    // The XMLReader interface
    //-----------------------------------------------------------------------
    /** @name Implementation of SAX 2.0 XMLReader interface's. */
    //@{

    /**
      * This method returns the installed content handler.
      *
      * @return A pointer to the installed content handler object.
      */
    virtual ContentHandler* getContentHandler() const = 0 ;

    /**
      * This method returns the installed DTD handler.
      *
      * @return A pointer to the installed DTD handler object.
      */
    virtual DTDHandler* getDTDHandler() const = 0;

    /**
      * This method returns the installed entity resolver.
      *
      * @return A pointer to the installed entity resolver object.
      */
    virtual EntityResolver* getEntityResolver() const = 0 ;

    /**
      * This method returns the installed error handler.
      *
      * @return A pointer to the installed error handler object.
      */
    virtual ErrorHandler* getErrorHandler() const = 0 ;

	/**
     * Query the current state of any feature in a SAX2 XMLReader.
	  *
	  * @param name The unique identifier (URI) of the feature being set.
	  * @return The current state of the feature.
     * @exception SAXNotRecognizedException If the requested feature is not known.
	  */
	virtual bool getFeature(const XMLCh* const name) const = 0;

	/**
     * Query the current value of a property in a SAX2 XMLReader.
     *
     * The parser owns the returned pointer.  The memory allocated for
     * the returned pointer will be destroyed when the parser is deleted.
     *
     * To ensure assessiblity of the returned information after the parser
     * is deleted, callers need to copy and store the returned information
     * somewhere else; otherwise you may get unexpected result.  Since the returned
     * pointer is a generic void pointer, see
     * http://xml.apache.org/xerces-c/program-sax2.html#SAX2Properties to learn
     * exactly what type of property value each property returns for replication.
     *
     * @param name The unique identifier (URI) of the property being set.
     * @return     The current value of the property.  The pointer spans the same
     *             life-time as the parser.  A null pointer is returned if nothing
     *             was specified externally.
     * @exception  SAXNotRecognizedException If the requested property is not known.
     */
	virtual void* getProperty(const XMLCh* const name) const = 0 ;

  /**
    * Allow an application to register a document event handler.
    *
    * If the application does not register a document handler, all
    * document events reported by the SAX parser will be silently
    * ignored (this is the default behaviour implemented by
    * HandlerBase).
    *
    * Applications may register a new or different handler in the
    * middle of a parse, and the SAX parser must begin using the new
    * handler immediately.
    *
    * @param handler The document handler.
    * @see DocumentHandler#DocumentHandler
    * @see HandlerBase#HandlerBase
    */
    virtual void setContentHandler(ContentHandler* const handler) = 0;

  /**
    * Allow an application to register a DTD event handler.
    *
    * If the application does not register a DTD handler, all DTD
    * events reported by the SAX parser will be silently ignored (this
    * is the default behaviour implemented by HandlerBase).
    *
    * Applications may register a new or different handler in the middle
    * of a parse, and the SAX parser must begin using the new handler
    * immediately.
    *
    * @param handler The DTD handler.
    * @see DTDHandler#DTDHandler
    * @see HandlerBase#HandlerBase
    */
    virtual void setDTDHandler(DTDHandler* const handler) = 0;

  /**
    * Allow an application to register a custom entity resolver.
    *
    * If the application does not register an entity resolver, the
    * SAX parser will resolve system identifiers and open connections
    * to entities itself (this is the default behaviour implemented in
    * DefaultHandler).
    *
    * Applications may register a new or different entity resolver
    * in the middle of a parse, and the SAX parser must begin using
    * the new resolver immediately.
    *
    * @param resolver The object for resolving entities.
    * @see EntityResolver#EntityResolver
    * @see DefaultHandler#DefaultHandler
    */
    virtual void setEntityResolver(EntityResolver* const resolver) = 0;

  /**
    * Allow an application to register an error event handler.
    *
    * If the application does not register an error event handler,
    * all error events reported by the SAX parser will be silently
    * ignored, except for fatalError, which will throw a SAXException
    * (this is the default behaviour implemented by HandlerBase).
    *
    * Applications may register a new or different handler in the
    * middle of a parse, and the SAX parser must begin using the new
    * handler immediately.
    *
    * @param handler The error handler.
    * @see ErrorHandler#ErrorHandler
    * @see SAXException#SAXException
    * @see HandlerBase#HandlerBase
    */
    virtual void setErrorHandler(ErrorHandler* const handler) = 0;

  /**
    * Set the state of any feature in a SAX2 XMLReader.
    * Supported features in SAX2 for xerces-c are:
    * <br>(See http://xml.apache.org/xerces-c/program-sax2.html#SAX2Features for detail description).
    *
    * <br>http://xml.org/sax/features/validation (default: true)
    * <br>http://xml.org/sax/features/namespaces (default: true)
    * <br>http://xml.org/sax/features/namespace-prefixes (default: false)
    * <br>http://apache.org/xml/features/validation/dynamic (default: false)
    * <br>http://apache.org/xml/features/validation/reuse-grammar (default: false)
    * <br>http://apache.org/xml/features/validation/schema (default: true)
    * <br>http://apache.org/xml/features/validation/schema-full-checking (default: false)
    * <br>http://apache.org/xml/features/nonvalidating/load-external-dtd (default: true)
    * <br>http://apache.org/xml/features/continue-after-fatal-error (default: false)
    * <br>http://apache.org/xml/features/validation-error-as-fatal (default: false)
    * <br>http://apache.org/xml/features/validation/reuse-validator (Deprecated) (default: false)
    *
    * @param name The unique identifier (URI) of the feature.
    * @param value The requested state of the feature (true or false).
    * @exception SAXNotRecognizedException If the requested feature is not known.
    * @exception SAXNotSupportedException Feature modification is not supported during parse
    *
    */
	virtual void setFeature(const XMLCh* const name, const bool value) = 0;

  /**
    * Set the value of any property in a SAX2 XMLReader.
    * Supported properties in SAX2 for xerces-c are:
    * <br>(See http://xml.apache.org/xerces-c/program-sax2.html#SAX2Properties for detail description).
    *
    * <br>http://apache.org/xml/properties/schema/external-schemaLocation
    * <br>http://apache.org/xml/properties/schema/external-noNamespaceSchemaLocation.
    *
    * It takes a void pointer as the property value.  Application is required to initialize this void
    * pointer to a correct type.  See http://xml.apache.org/xerces-c/program-sax2.html#SAX2Properties
    * to learn exactly what type of property value each property expects for processing.
    * Passing a void pointer that was initialized with a wrong type will lead to unexpected result.
    * If the same property is set more than once, the last one takes effect.
    *
    * @param name The unique identifier (URI) of the property being set.
    * @param value The requested value for the property.  See
    *            http://xml.apache.org/xerces-c/program-sax2.html#SAX2Properties to learn
    *            exactly what type of property value each property expects for processing.
    *            Passing a void pointer that was initialized with a wrong type will lead
    *            to unexpected result.
    * @exception SAXNotRecognizedException If the requested property is not known.
    * @exception SAXNotSupportedException Property modification is not supported during parse
    */
	virtual void setProperty(const XMLCh* const name, void* value) = 0 ;

  /**
    * Parse an XML document.
    *
    * The application can use this method to instruct the SAX parser
    * to begin parsing an XML document from any valid input
    * source (a character stream, a byte stream, or a URI).
    *
    * Applications may not invoke this method while a parse is in
    * progress (they should create a new Parser instead for each
    * additional XML document).  Once a parse is complete, an
    * application may reuse the same Parser object, possibly with a
    * different input source.
    *
    * @param source The input source for the top-level of the
    *               XML document.
    * @exception SAXException Any SAX exception, possibly
    *            wrapping another exception.
    * @exception XMLException An exception from the parser or client
    *            handler code.
    * @see InputSource#InputSource
    * @see #setEntityResolver
    * @see #setDTDHandler
    * @see #setDocumentHandler
    * @see #setErrorHandler
    */
    virtual void parse
    (
        const   InputSource&    source
    ) = 0;

  /**
    * Parse an XML document from a system identifier (URI).
    *
    * This method is a shortcut for the common case of reading a
    * document from a system identifier.  It is the exact equivalent
    * of the following:
    *
    * parse(new URLInputSource(systemId));
    *
    * If the system identifier is a URL, it must be fully resolved
    * by the application before it is passed to the parser.
    *
    * @param systemId The system identifier (URI).
    * @exception SAXException Any SAX exception, possibly
    *            wrapping another exception.
    * @exception XMLException An exception from the parser or client
    *            handler code.
    * @see #parse(InputSource)
    */
    virtual void parse
    (
        const   XMLCh* const    systemId
    ) = 0;

  /**
    * Parse an XML document from a system identifier (URI).
    *
    * This method is a shortcut for the common case of reading a
    * document from a system identifier.  It is the exact equivalent
    * of the following:
    *
    * parse(new URLInputSource(systemId));
    *
    * If the system identifier is a URL, it must be fully resolved
    * by the application before it is passed to the parser.
    *
    * @param systemId The system identifier (URI).
    * @exception SAXException Any SAX exception, possibly
    *            wrapping another exception.
    * @exception XMLException An exception from the parser or client
    *            handler code.
    * @see #parse(InputSource)
    */
    virtual void parse
    (
        const   char* const     systemId
    ) = 0;
	
    //@}

    // -----------------------------------------------------------------------
    //  SAX 2.0-ext
    // -----------------------------------------------------------------------
    /** @name SAX 2.0-ext */
    //@{
    /**
      * This method returns the installed declaration handler.
      *
      * @return A pointer to the installed declaration handler object.
      */
    virtual DeclHandler* getDeclarationHandler() const = 0 ;

	/**
      * This method returns the installed lexical handler.
      *
      * @return A pointer to the installed lexical handler object.
      */
    virtual LexicalHandler* getLexicalHandler() const = 0 ;

   /**
    * Allow an application to register a declaration event handler.
    *
    * If the application does not register a declaration handler,
    * all events reported by the SAX parser will be silently
    * ignored. (this is the default behaviour implemented by DefaultHandler).
    *
    * Applications may register a new or different handler in the
    * middle of a parse, and the SAX parser must begin using the new
    * handler immediately.
    *
    * @param handler The DTD declaration handler.
    * @see DeclHandler#DeclHandler
    * @see SAXException#SAXException
    * @see DefaultHandler#DefaultHandler
    */
    virtual void setDeclarationHandler(DeclHandler* const handler) = 0;

   /**
    * Allow an application to register a lexical event handler.
    *
    * If the application does not register a lexical handler,
    * all events reported by the SAX parser will be silently
    * ignored. (this is the default behaviour implemented by HandlerBase).
    *
    * Applications may register a new or different handler in the
    * middle of a parse, and the SAX parser must begin using the new
    * handler immediately.
    *
    * @param handler The error handler.
    * @see LexicalHandler#LexicalHandler
    * @see SAXException#SAXException
    * @see HandlerBase#HandlerBase
    */
    virtual void setLexicalHandler(LexicalHandler* const handler) = 0;

    //@}

    // -----------------------------------------------------------------------
    //  Getter Methods
    // -----------------------------------------------------------------------
    /** @name Getter Methods (Xerces-C specific) */
    //@{
    /**
	  * This method is used to get the current validator.
	  *
	  * <b>SAX2XMLReader assumes responsibility for the validator.  It will be
	  * deleted when the XMLReader is destroyed.</b>
	  *
	  * @return A pointer to the validator.  An application should not deleted
	  * the object returned.
	  *
	  */
	virtual XMLValidator* getValidator() const = 0;

    /** Get error count from the last parse operation.
      *
      * This method returns the error count from the last parse
      * operation. Note that this count is actually stored in the
      * scanner, so this method simply returns what the
      * scanner reports.
      *
      * @return number of errors encountered during the latest
      *			parse operation.
      */
    virtual int getErrorCount() const = 0 ;

    /**
      * This method returns the state of the parser's
      * exit-on-First-Fatal-Error flag.
      *
      * <p>Or you can query the feature "http://apache.org/xml/features/continue-after-fatal-error"
      * which indicates the opposite state.</p>
      *
      * @return true, if the parser is currently configured to
      *         exit on the first fatal error, false otherwise.
      *
      * @see #setExitOnFirstFatalError
      * @see #getFeature
      */
    virtual bool getExitOnFirstFatalError() const = 0;

    /**
      * This method returns the state of the parser's
      * validation-constraint-fatal flag.
      *
      * <p>Or you can query the feature "http://apache.org/xml/features/validation-error-as-fatal"
      * which means the same thing.
      *
      * @return true, if the parser is currently configured to
      *         set validation constraint errors as fatal, false
      *         otherwise.
      *
      * @see #setValidationContraintFatal
      * @see #getFeature
      */
    virtual bool getValidationConstraintFatal() const = 0;

    /**
      * Retrieve the grammar that is associated with the specified namespace key
      *
      * @param  nameSpaceKey Namespace key
      * @return Grammar associated with the Namespace key.
      */
    virtual Grammar* getGrammar(const XMLCh* const nameSpaceKey) = 0;

    /**
      * Retrieve the grammar where the root element is declared.
      *
      * @return Grammar where root element declared
      */
    virtual Grammar* getRootGrammar() = 0;

    /**
      * Returns the string corresponding to a URI id from the URI string pool.
      *
      * @param uriId id of the string in the URI string pool.
      * @return URI string corresponding to the URI id.
      */
    virtual const XMLCh* getURIText(unsigned int uriId) const = 0;

    /**
      * Returns the current src offset within the input source.
      *
      * @return offset within the input source
      */
    virtual unsigned int getSrcOffset() const = 0;

    //@}

    // -----------------------------------------------------------------------
    //  Setter Methods
    // -----------------------------------------------------------------------
    /** @name Setter Methods (Xerces-C specific) */
    //@{
    /**
	  * This method is used to set a validator.
	  *
	  * <b>SAX2XMLReader assumes responsibility for the validator.  It will be
	  * deleted when the XMLReader is destroyed.</b>
	  *
	  * @param valueToAdopt A pointer to the validator that the reader should use.
	  *
	  */
	virtual void setValidator(XMLValidator* valueToAdopt) = 0;

    /**
      * This method allows users to set the parser's behaviour when it
      * encounters the first fatal error. If set to true, the parser
      * will exit at the first fatal error. If false, then it will
      * report the error and continue processing.
      *
      * <p>The default value is 'true' and the parser exits on the
      * first fatal error.</p>
      *
      * <p>Or you can set the feature "http://apache.org/xml/features/continue-after-fatal-error"
      * which has the opposite behaviour.</p>
      *
      * <p>If both the feature above and this function are used, the latter takes effect.</p>
      *
      * @param newState The value specifying whether the parser should
      *                 continue or exit when it encounters the first
      *                 fatal error.
      *
      * @see #getExitOnFirstFatalError
      * @see #setFeature
      */
    virtual void setExitOnFirstFatalError(const bool newState) = 0;

    /**
      * This method allows users to set the parser's behaviour when it
      * encounters a validtion constraint error. If set to true, and the
      * the parser will treat validation error as fatal and will exit depends on the
      * state of "getExitOnFirstFatalError". If false, then it will
      * report the error and continue processing.
      *
      * Note: setting this true does not mean the validation error will be printed with
      * the word "Fatal Error".   It is still printed as "Error", but the parser
      * will exit if "setExitOnFirstFatalError" is set to true.
      *
      * <p>The default value is 'false'.</p>
      *
      * <p>Or you can set the feature "http://apache.org/xml/features/validation-error-as-fatal"
      * which means the same thing.</p>
      *
      * <p>If both the feature above and this function are used, the latter takes effect.</p>
      *
      * @param newState If true, the parser will exit if "setExitOnFirstFatalError"
      *                 is set to true.
      *
      * @see #getValidationConstraintFatal
      * @see #setExitOnFirstFatalError
      * @see #setFeature
      */
    virtual void setValidationConstraintFatal(const bool newState) = 0;
    //@}


    // -----------------------------------------------------------------------
    //  Progressive scan methods
    // -----------------------------------------------------------------------

    /** @name Progressive scan methods */
    //@{

    /** Begin a progressive parse operation
      *
      * This method is used to start a progressive parse on a XML file.
      * To continue parsing, subsequent calls must be to the parseNext
      * method.
      *
      * It scans through the prolog and returns a token to be used on
      * subsequent scanNext() calls. If the return value is true, then the
      * token is legal and ready for further use. If it returns false, then
      * the scan of the prolog failed and the token is not going to work on
      * subsequent scanNext() calls.
      *
      * @param systemId A pointer to a Unicode string represting the path
      *                 to the XML file to be parsed.
      * @param toFill   A token maintaing state information to maintain
      *                 internal consistency between invocation of 'parseNext'
      *                 calls.
      *
      * @return 'true', if successful in parsing the prolog. It indicates the
      *         user can go ahead with parsing the rest of the file. It
      *         returns 'false' to indicate that the parser could parse the
      *         prolog (which means the token will not be valid.)
      *
      * @see #parseNext
      * @see #parseFirst(char*,...)
      * @see #parseFirst(InputSource&,...)
      */
    virtual bool parseFirst
    (
        const   XMLCh* const    systemId
        ,       XMLPScanToken&  toFill
    ) = 0;

    /** Begin a progressive parse operation
      *
      * This method is used to start a progressive parse on a XML file.
      * To continue parsing, subsequent calls must be to the parseNext
      * method.
      *
      * It scans through the prolog and returns a token to be used on
      * subsequent scanNext() calls. If the return value is true, then the
      * token is legal and ready for further use. If it returns false, then
      * the scan of the prolog failed and the token is not going to work on
      * subsequent scanNext() calls.
      *
      * @param systemId A pointer to a regular native string represting
      *                 the path to the XML file to be parsed.
      * @param toFill   A token maintaing state information to maintain
      *                 internal consIstency between invocation of 'parseNext'
      *                 calls.
      *
      * @return 'true', if successful in parsing the prolog. It indicates the
      *         user can go ahead with parsing the rest of the file. It
      *         returns 'false' to indicate that the parser could not parse
      *         the prolog.
      *
      * @see #parseNext
      * @see #parseFirst(XMLCh*,...)
      * @see #parseFirst(InputSource&,...)
      */
    virtual bool parseFirst
    (
        const   char* const     systemId
        ,       XMLPScanToken&  toFill
    ) = 0;

    /** Begin a progressive parse operation
      *
      * This method is used to start a progressive parse on a XML file.
      * To continue parsing, subsequent calls must be to the parseNext
      * method.
      *
      * It scans through the prolog and returns a token to be used on
      * subsequent scanNext() calls. If the return value is true, then the
      * token is legal and ready for further use. If it returns false, then
      * the scan of the prolog failed and the token is not going to work on
      * subsequent scanNext() calls.
      *
      * @param source   A const reference to the InputSource object which
      *                 points to the XML file to be parsed.
      * @param toFill   A token maintaing state information to maintain
      *                 internal consistency between invocation of 'parseNext'
      *                 calls.
      *
      * @return 'true', if successful in parsing the prolog. It indicates the
      *         user can go ahead with parsing the rest of the file. It
      *         returns 'false' to indicate that the parser could not parse
      *         the prolog.
      *
      * @see #parseNext
      * @see #parseFirst(XMLCh*,...)
      * @see #parseFirst(char*,...)
      */
    virtual bool parseFirst
    (
        const   InputSource&    source
        ,       XMLPScanToken&  toFill
    ) = 0;

    /** Continue a progressive parse operation
      *
      * This method is used to continue with progressive parsing of
      * XML files started by a call to 'parseFirst' method.
      *
      * It parses the XML file and stops as soon as it comes across
      * a XML token (as defined in the XML specification). Relevant
      * callback handlers are invoked as required by the SAX
      * specification.
      *
      * @param token A token maintaing state information to maintain
      *              internal consistency between invocation of 'parseNext'
      *              calls.
      *
      * @return 'true', if successful in parsing the next XML token.
      *         It indicates the user can go ahead with parsing the rest
      *         of the file. It returns 'false' to indicate that the parser
      *         could not find next token as per the XML specification
      *         production rule.
      *
      * @see #parseFirst(XMLCh*,...)
      * @see #parseFirst(char*,...)
      * @see #parseFirst(InputSource&,...)
      */
    virtual bool parseNext(XMLPScanToken& token) = 0;

    /** Reset the parser after a progressive parse
      *
      * If a progressive parse loop exits before the end of the document
      * is reached, the parser has no way of knowing this. So it will leave
      * open any files or sockets or memory buffers that were in use at
      * the time that the parse loop exited.
      *
      * The next parse operation will cause these open files and such to
      * be closed, but the next parse operation might occur at some unknown
      * future point. To avoid this problem, you should reset the parser if
      * you exit the loop early.
      *
      * If you exited because of an error, then this cleanup will be done
      * for you. Its only when you exit the file prematurely of your own
      * accord, because you've found what you wanted in the file most
      * likely.
      *
      * @param token A token maintaing state information to maintain
      *              internal consistency between invocation of 'parseNext'
      *              calls.
      */
    virtual void parseReset(XMLPScanToken& token) = 0;

    //@}

    // -----------------------------------------------------------------------
    //  Grammar preparsing interface
    // -----------------------------------------------------------------------

    /** @name Grammar preparsing interface's. */
    //@{
    /**
      * Preparse schema grammar (XML Schema, DTD, etc.) via an input source
      * object.
      *
      * This method invokes the preparsing process on a schema grammar XML
      * file specified by the SAX InputSource parameter. If the 'toCache' flag
      * is enabled, the parser will cache the grammars for re-use. If a grammar
      * key is found in the pool, no caching of any grammar will take place.
      *
      * <p><b>"Experimental - subject to change"</b></p>
      *
      * @param source A const reference to the SAX InputSource object which
      *               points to the schema grammar file to be preparsed.
      * @param grammarType The grammar type (Schema or DTD).
      * @param toCache If <code>true</code>, we cache the preparsed grammar,
      *                otherwise, no chaching. Default is <code>false</code>.
      * @return The preparsed schema grammar object (SchemaGrammar or
      *         DTDGrammar). That grammar object is owned by the parser.
      *
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception DOMException A DOM exception as per DOM spec.
      *
      * @see InputSource#InputSource
      */
    virtual Grammar* loadGrammar(const InputSource& source,
                                 const short grammarType,
                                 const bool toCache = false) = 0;

    /**
      * Preparse schema grammar (XML Schema, DTD, etc.) via a file path or URL
      *
      * This method invokes the preparsing process on a schema grammar XML
      * file specified by the file path parameter. If the 'toCache' flag
      * is enabled, the parser will cache the grammars for re-use. If a grammar
      * key is found in the pool, no caching of any grammar will take place.
      *
      * <p><b>"Experimental - subject to change"</b></p>
      *
      * @param systemId A const XMLCh pointer to the Unicode string which
      *                 contains the path to the XML grammar file to be
      *                 preparsed.
      * @param grammarType The grammar type (Schema or DTD).
      * @param toCache If <code>true</code>, we cache the preparsed grammar,
      *                otherwise, no chaching. Default is <code>false</code>.
      * @return The preparsed schema grammar object (SchemaGrammar or
      *         DTDGrammar). That grammar object is owned by the parser.
      *
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception DOMException A DOM exception as per DOM spec.
      */
    virtual Grammar* loadGrammar(const XMLCh* const systemId,
                                 const short grammarType,
                                 const bool toCache = false) = 0;

    /**
      * Preparse schema grammar (XML Schema, DTD, etc.) via a file path or URL
      *
      * This method invokes the preparsing process on a schema grammar XML
      * file specified by the file path parameter. If the 'toCache' flag
      * is enabled, the parser will cache the grammars for re-use. If a grammar
      * key is found in the pool, no caching of any grammar will take place.
      *
      * <p><b>"Experimental - subject to change"</b></p>
      *
      * @param systemId A const char pointer to a native string which contains
      *                 the path to the XML grammar file to be preparsed.
      * @param grammarType The grammar type (Schema or DTD).
      * @param toCache If <code>true</code>, we cache the preparsed grammar,
      *                otherwise, no chaching. Default is <code>false</code>.
      * @return The preparsed schema grammar object (SchemaGrammar or
      *         DTDGrammar). That grammar object is owned by the parser.
      *
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception DOMException A DOM exception as per DOM spec.
      */
    virtual Grammar* loadGrammar(const char* const systemId,
                                 const short grammarType,
                                 const bool toCache = false) = 0;

    /**
      * Clear the cached grammar pool
      */
    virtual void resetCachedGrammarPool() = 0;

    /** Set maximum input buffer size
      *
      * This method allows users to limit the size of buffers used in parsing
      * XML character data. The effect of setting this size is to limit the
      * size of a ContentHandler::characters() call.
      *
      * The parser's default input buffer size is 1 megabyte.
      *
      * @param bufferSize The maximum input buffer size
      */
    void setInputBufferSize(const size_t bufferSize) {};

    //@}


    // -----------------------------------------------------------------------
    //  Advanced document handler list maintenance methods
    // -----------------------------------------------------------------------

    /** @name Advanced document handler list maintenance methods */
    //@{
    /**
      * This method installs the specified 'advanced' document callback
      * handler, thereby allowing the user to customize the processing,
      * if they choose to do so. Any number of advanced callback handlers
      * maybe installed.
      *
      * <p>The methods in the advanced callback interface represent
      * Xerces-C extensions. There is no specification for this interface.</p>
      *
      * @param toInstall A pointer to the users advanced callback handler.
      *
      * @see #removeAdvDocHandler
      */
    virtual void installAdvDocHandler(XMLDocumentHandler* const toInstall) = 0;

    /**
      * This method removes the 'advanced' document handler callback from
      * the underlying parser scanner. If no handler is installed, advanced
      * callbacks are not invoked by the scanner.
      * @param toRemove A pointer to the advanced callback handler which
      *                 should be removed.
      *
      * @see #installAdvDocHandler
      */
    virtual bool removeAdvDocHandler(XMLDocumentHandler* const toRemove) = 0;
    //@}

private :
    /* The copy constructor, you cannot call this directly */
    SAX2XMLReader(const SAX2XMLReader&);

    /* The assignment operator, you cannot call this directly */
    SAX2XMLReader& operator=(const SAX2XMLReader&);

};

XERCES_CPP_NAMESPACE_END

#endif
