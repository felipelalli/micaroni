/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id: IDOMParser.hpp,v 1.3 2005/01/21 20:27:20 felipelalli Exp $
 *
 */

#if !defined(IDOMPARSER_HPP)
#define IDOMPARSER_HPP


#include <xercesc/idom/IDOM_Document.hpp>
#include <xercesc/framework/XMLDocumentHandler.hpp>
#include <xercesc/framework/XMLErrorReporter.hpp>
#include <xercesc/framework/XMLEntityHandler.hpp>
#include <xercesc/util/ValueStackOf.hpp>

#include <xercesc/validators/DTD/DocTypeHandler.hpp>
#include <xercesc/idom/IDOM_DocumentType.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>

class EntityResolver;
class ErrorHandler;
class XMLPScanToken;
class XMLScanner;
class XMLValidator;
class IDDocumentImpl;
class IDDocumentTypeImpl;


/**
  * This class implements the Document Object Model (DOM) interface.
  * It should be used by applications which choose to parse and
  * process the XML document using the DOM api's. This implementation
  * also allows the applications to install an error and an entitty
  * handler (useful extensions to the DOM specification).
  *
  * <p>It can be used to instantiate a validating or non-validating
  * parser, by setting a member flag.</p>
  */
class PARSERS_EXPORT IDOMParser :

    public XMLDocumentHandler
    , public XMLErrorReporter
    , public XMLEntityHandler
    , public DocTypeHandler
{
public :
    // -----------------------------------------------------------------------
    //  Class types
    // -----------------------------------------------------------------------
    enum ValSchemes
    {
        Val_Never
        , Val_Always
        , Val_Auto
    };


    // -----------------------------------------------------------------------
    //  Constructors and Detructor
    // -----------------------------------------------------------------------

    /** @name Constructors and Destructor */
    //@{
    /** Construct a IDOMParser, with an optional validator
      *
      * Constructor with an instance of validator class to use for
      * validation. If you don't provide a validator, a default one will
      * be created for you in the scanner.
      *
      * @param valToAdopt Pointer to the validator instance to use. The
      *                   parser is responsible for freeing the memory.
      */
    IDOMParser(XMLValidator* const valToAdopt = 0);

    /**
      * Destructor
      */
    ~IDOMParser();

    //@}

    /** Reset the parser
      *
      * This method resets the state of the IDOM driver and makes
      * it ready for a fresh parse run.
      */
    void reset();

    /** Reset the documents vector pool and release all the associated memory
      * back to the system.
      *
      * When parsing a document using an IDOMParser, all memory allocated
      * for a DOM tree is associated to the DOM document.
      *
      * If you do multiple parse using the same IDOMParser instance, then
      * multiple DOM documents will be generated and saved in a vector pool.
      * All these documents (and thus all the allocated memory)
      * won't be deleted until the parser instance is destroyed.
      *
      * If you don't need these DOM documents anymore and don't want to
      * destroy the IDOMParser instance at this moment, then you can call this method
      * to reset the document vector pool and release all the allocated memory
      * back to the system.
      *
      * It is an error to call this method if you are in the middle of a
      * parse (e.g. in the mid of a progressive parse).
      *
      * @exception IOException An exception from the parser if this function
      *            is called when a parse is in progress.
      *
      */
    void resetDocumentPool();


    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------

    /** @name Getter methods */
    //@{

    /** Get the IDOM document
      *
      * This method returns the IDOM_Document object representing the
      * root of the document tree. This object provides the primary
      * access to the document's data.
      *
      * @return The IDOM_Document object which represents the entire
      *         XML document.
      */
    IDOM_Document* getDocument();

    /** Get a pointer to the error handler
      *
      * This method returns the installed error handler. If no handler
      * has been installed, then it will be a zero pointer.
      *
      * @return The pointer to the installed error handler object.
      */
    ErrorHandler* getErrorHandler();

    /** Get a const pointer to the error handler
      *
      * This method returns the installed error handler.  If no handler
      * has been installed, then it will be a zero pointer.
      *
      * @return A const pointer to the installed error handler object.
      */
    const ErrorHandler* getErrorHandler() const;

    /** Get a pointer to the entity resolver
      *
      * This method returns the installed entity resolver.  If no resolver
      * has been installed, then it will be a zero pointer.
      *
      * @return The pointer to the installed entity resolver object.
      */
    EntityResolver* getEntityResolver();

    /** Get a const pointer to the entity resolver
      *
      * This method returns the installed entity resolver. If no resolver
      * has been installed, then it will be a zero pointer.
      *
      * @return A const pointer to the installed entity resolver object.
      */
    const EntityResolver* getEntityResolver() const;

    /** Get a const reference to the validator
      *
      * This method returns a reference to the parser's installed
      * validator.
      *
      * @return A const reference to the installed validator object.
      */
    const XMLValidator& getValidator() const;

    /**
      * This method returns an enumerated value that indicates the current
      * validation scheme set on this parser.
      *
      * @return The ValSchemes value current set on this parser.
      * @see #setValidationScheme
      */
    ValSchemes getValidationScheme() const;

    /** Get the 'do schema' flag
      *
      * This method returns the state of the parser's schema processing
      * flag.
      *
      * @return true, if the parser is currently configured to
      *         understand schema, false otherwise.
      *
      * @see #setDoSchema
      */
    bool getDoSchema() const;

    /** Get the 'full schema constraint checking' flag
      *
      * This method returns the state of the parser's full schema constraint
      * checking flag.
      *
      * @return true, if the parser is currently configured to
      *         have full schema constraint checking, false otherwise.
      *
      * @see #setValidationSchemaFullChecking
      */
    bool getValidationSchemaFullChecking() const;

    /** Get error count from the last parse operation.
      *
      * This method returns the error count from the last parse
      * operation. Note that this count is actually stored in the
      * scanner, so this method simply returns what the
      * scanner reports.
      *
      * @return number of errors encountered during the latest
      *			parse operation.
      *
      */
    int getErrorCount() const;

    /** Get the 'do namespaces' flag
      *
      * This method returns the state of the parser's namespace processing
      * flag.
      *
      * @return true, if the parser is currently configured to
      *         understand namespaces, false otherwise.
      *
      * @see #setDoNamespaces
      */
    bool getDoNamespaces() const;

    /** Get the 'exit on first error' flag
      *
      * This method returns the state of the parser's
      * exit-on-First-Fatal-Error flag. If this flag is true, then the
      * parse will exit the first time it sees any non-wellformed XML or
      * any validity error. The default state is true.
      *
      * @return true, if the parser is currently configured to
      *         exit on the first fatal error, false otherwise.
      *
      * @see #setExitOnFirstFatalError
      */
    bool getExitOnFirstFatalError() const;

    /**
      * This method returns the state of the parser's
      * validation-constraint-fatal flag.
      *
      * @return true, if the parser is currently configured to
      *         set validation constraint errors as fatal, false
      *         otherwise.
      *
      * @see #setValidationContraintFatal
      */
    bool getValidationConstraintFatal() const;

    /** Get the 'expand entity references' flag.
      * DEPRECATED Use getCreateEntityReferenceNodes() instead.
      *
      * This method returns the state of the parser's expand entity
      * references flag.
      *
      * @return 'true' if the expand entity reference flag is set on
      *         the parser, 'false' otherwise.
      *
      * @see #setExpandEntityReferences
      */
    bool getExpandEntityReferences() const;

    /** Get the 'include entity references' flag
      *
      * This flag  specifies whether the parser is
      * creating entity reference nodes in the DOM tree being produced.
      * When the 'create' flag is
      * true, the DOM tree will contain entity reference nodes.
      * When the 'create' flag is false, no entity reference nodes
      * are included in the DOM tree.
      * <p>The replacement text
      * of the entity is included in either case, either as a
      * child of the Entity Reference node or in place at the location
      * of the reference.
      *
      * @return  The state of the create entity reference node
      *               flag.
      * @see #setCreateEntityReferenceNodes
      */
    bool  getCreateEntityReferenceNodes()const;

   /** Get the 'include ignorable whitespace' flag.
      *
      * This method returns the state of the parser's include ignorable
      * whitespace flag.
      *
      * @return 'true' if the include ignorable whitespace flag is set on
      *         the parser, 'false' otherwise.
      *
      * @see #setIncludeIgnorableWhitespace
      */
    bool getIncludeIgnorableWhitespace() const;

   /** Get the set of Namespace/SchemaLocation that is specified externaly.
      *
      * This method returns the list of Namespace/SchemaLocation that was
      * specified using setExternalSchemaLocation.
      *
      * The parser owns the returned string, and the memory allocated for
      * the returned string will be destroyed when the parser is deleted.
      *
      * To ensure assessiblity of the returned information after the parser
      * is deleted, callers need to copy and store the returned information
      * somewhere else.
      *
      * @return a pointer to the list of Namespace/SchemaLocation that was
      *         specified externally.  The pointer spans the same life-time as
      *         the parser.  A null pointer is returned if nothing
      *         was specified externally.
      *
      * @see #setExternalSchemaLocation(const XMLCh* const)
      */
    XMLCh* getExternalSchemaLocation() const;

   /** Get the noNamespace SchemaLocation that is specified externaly.
      *
      * This method returns the no target namespace XML Schema Location
      * that was specified using setExternalNoNamespaceSchemaLocation.
      *
      * The parser owns the returned string, and the memory allocated for
      * the returned string will be destroyed when the parser is deleted.
      *
      * To ensure assessiblity of the returned information after the parser
      * is deleted, callers need to copy and store the returned information
      * somewhere else.
      *
      * @return a pointer to the no target namespace Schema Location that was
      *         specified externally.  The pointer spans the same life-time as
      *         the parser.  A null pointer is returned if nothing
      *         was specified externally.
      *
      * @see #setExternalNoNamespaceSchemaLocation(const XMLCh* const)
      */
    XMLCh* getExternalNoNamespaceSchemaLocation() const;

    //@}


    // -----------------------------------------------------------------------
    //  Setter methods
    // -----------------------------------------------------------------------

    /** @name Setter methods */
    //@{

    /** Set the error handler
      *
      * This method allows applications to install their own error handler
      * to trap error and warning messages.
      *
      * <i>Any previously set handler is merely dropped, since the parser
      * does not own them.</i>
      *
      * @param handler  A const pointer to the user supplied error
      *                 handler.
      *
      * @see #getErrorHandler
      */
    void setErrorHandler(ErrorHandler* const handler);

    /** Set the entity resolver
      *
      * This method allows applications to install their own entity
      * resolver. By installing an entity resolver, the applications
      * can trap and potentially redirect references to external
      * entities.
      *
      * <i>Any previously set resolver is merely dropped, since the parser
      * does not own them.</i>
      *
      * @param handler  A const pointer to the user supplied entity
      *                 resolver.
      *
      * @see #getEntityResolver
      */
    void setEntityResolver(EntityResolver* const handler);

    /** Set the 'do namespaces' flag
      *
      * This method allows users to enable or disable the parser's
      * namespace processing. When set to true, parser starts enforcing
      * all the constraints and rules specified by the NameSpace
      * specification.
      *
      * The parser's default state is: false.
      *
      * This flag is ignored by the underlying scanner if the installed
      * validator indicates that namespace constraints should be
      * enforced.
      *
      * @param newState The value specifying whether NameSpace rules should
      *                 be enforced or not.
      *
      * @see #getDoNamespaces
      */
    void setDoNamespaces(const bool newState);

    /** Set the 'exit on first error' flag
      *
      * This method allows users to set the parser's behaviour when it
      * encounters the first fatal error. If set to true, the parser
      * will exit at the first fatal error. If false, then it will
      * report the error and continue processing.
      *
      * The default value is 'true' and the parser exits on the
      * first fatal error.
      *
      * @param newState The value specifying whether the parser should
      *                 continue or exit when it encounters the first
      *                 fatal error.
      *
      * @see #getExitOnFirstFatalError
      */
    void setExitOnFirstFatalError(const bool newState);

    /**
      * This method allows users to set the parser's behaviour when it
      * encounters a validtion constraint error. If set to true, and the
      * the parser is set to exit when it encounter the first fatal error,
      * the parser will exit at the first encounter. If false, then it will
      * report the error and continue processing.
      *
      * <p>The default value is 'false'.</p>
      *
      * @param newState The value specifying whether the parser should
      *                 continue or exit when it encounters a validation
      *                 constraint error.
      *
      * @see #getValidationConstraintFatal
      */
    void setValidationConstraintFatal(const bool newState);

    /** Set the 'expand entity references' flag
      *
      * DEPRECATED.  USE setCreateEntityReferenceNodes instead.
      * This method allows the user to specify whether the parser should
      * expand all entity reference nodes. When the 'do expansion' flag is
      * true, the DOM tree does not have any entity reference nodes. It is
      * replaced by the sub-tree representing the replacement text of the
      * entity. When the 'do expansion' flag is false, the DOM tree
      * contains an extra entity reference node, whose children is the
      * sub tree of the replacement text.
      *
      * @param expand The new state of the expand entity reference
      *               flag.
      */
    void setExpandEntityReferences(const bool expand);

     /** Set the 'include entity references' flag
      *
      * This method allows the user to specify whether the parser should
      * create entity reference nodes in the DOM tree being produced.
      * When the 'create' flag is
      * true, the DOM tree constains entity reference nodes.
      * When the 'create' flag is false, no entity reference nodes
      * are included in the DOM tree.
      * <p>The replacement text
      * of the entity is included in either case, either as a
      * child of the Entity Reference node or in place at the location
      * of the reference.
      *
      * @param create The new state of the create entity reference nodes
      *               flag.
      */
    void setCreateEntityReferenceNodes(const bool create);

   /** Set the 'include ignorable whitespace' flag
      *
      * This method allows the user to specify whether a validating parser
      * should include ignorable whitespaces as text nodes.  It has no effect
      * on non-validating parsers which always include non-markup text.
      * <p>When set to true (also the default), ignorable whitespaces will be
      * added to the DOM tree as text nodes.  The method
      * IDOM_Text::isIgnorableWhitespace() will return true for those text
      * nodes only.
      * <p>When set to false, all ignorable whitespace will be discarded and
      * no text node is added to the DOM tree.  Note: applications intended
      * to process the "xml:space" attribute should not set this flag to false.
      * And this flag also overrides any schema datateye whitespace facets,
      * that is, all ignorable whitespace will be discarded even though
      * 'preserve' is set in schema datatype whitespace facets.
      *
      * @param include The new state of the include ignorable whitespace
      *                flag.
      *
      * @see #getIncludeIgnorableWhitespace
      */
    void setIncludeIgnorableWhitespace(const bool include);

    /**
      * This method allows users to set the validation scheme to be used
      * by this parser. The value is one of the ValSchemes enumerated values
      * defined by this class:
      *
      * <br>  Val_Never  - turn off validation
      * <br>  Val_Always - turn on validation
      * <br>  Val_Auto   - turn on validation if any internal/external
      *                  DTD subset have been seen
      *
      * <p>The parser's default state is: Val_Auto.</p>
      *
      * @param newScheme The new validation scheme to use.
      *
      * @see #getValidationScheme
      */
    void setValidationScheme(const ValSchemes newScheme);

    /** Set the 'do schema' flag
      *
      * This method allows users to enable or disable the parser's
      * schema processing. When set to false, parser will not process
      * any schema found.
      *
      * The parser's default state is: false.
      *
      * @param newState The value specifying whether schema support should
      *                 be enforced or not.
      *
      * @see #getDoSchema
      */
    void setDoSchema(const bool newState);

    /**
      * This method allows the user to turn full Schema constraint checking on/off.
      * Only takes effect if Schema validation is enabled.
      * If turned off, partial constraint checking is done.
      *
      * Full schema constraint checking includes those checking that may
      * be time-consuming or memory intensive. Currently, particle unique
      * attribution constraint checking and particle derivation resriction checking
      * are controlled by this option.
      *
      * The parser's default state is: false.
      *
      * @param schemaFullChecking True to turn on full schema constraint checking.
      *
      * @see #getValidationSchemaFullChecking
      */
    void setValidationSchemaFullChecking(const bool schemaFullChecking);

    /**
      * This method allows the user to specify a list of schemas to use.
      * If the targetNamespace of a schema specified using this method matches
      * the targetNamespace of a schema occuring in the instance document in
      * the schemaLocation attribute, or if the targetNamespace matches the
      * namespace attribute of the "import" element, the schema specified by the
      * user using this method will be used (i.e., the schemaLocation attribute
      * in the instance document or on the "import" element will be effectively ignored).
      *
      * If this method is called more than once, only the last one takes effect.
      *
      * The syntax is the same as for schemaLocation attributes in instance
      * documents: e.g, "http://www.example.com file_name.xsd". The user can
      * specify more than one XML Schema in the list.
      *
      * @param schemaLocation the list of schemas to use
      *
      * @see #getExternalSchemaLocation
      */

    void setExternalSchemaLocation(const XMLCh* const schemaLocation);

    /**
      * This method is same as setExternalSchemaLocation(const XMLCh* const).
      * It takes native char string as parameter
      *
      * @param schemaLocation the list of schemas to use
      *
      * @see #setExternalSchemaLocation(const XMLCh* const)
      */
    void setExternalSchemaLocation(const char* const schemaLocation);

    /**
      * This method allows the user to specify the no target namespace XML
      * Schema Location externally.  If specified, the instance document's
      * noNamespaceSchemaLocation attribute will be effectively ignored.
      *
      * If this method is called more than once, only the last one takes effect.
      *
      * The syntax is the same as for the noNamespaceSchemaLocation attribute
      * that may occur in an instance document: e.g."file_name.xsd".
      *
      * @param noNamespaceSchemaLocation the XML Schema Location with no target namespace
      *
      * @see #getExternalNoNamespaceSchemaLocation
      */
    void setExternalNoNamespaceSchemaLocation(const XMLCh* const noNamespaceSchemaLocation);

    /**
      * This method is same as setExternalNoNamespaceSchemaLocation(const XMLCh* const).
      * It takes native char string as parameter
      *
      * @param noNamespaceSchemaLocation the XML Schema Location with no target namespace
      *
      * @see #setExternalNoNamespaceSchemaLocation(const XMLCh* const)
      */
    void setExternalNoNamespaceSchemaLocation(const char* const noNamespaceSchemaLocation);

    //@}


    // -----------------------------------------------------------------------
    //  Parsing methods
    // -----------------------------------------------------------------------

    /** @name Parsing methods */
    //@{

    /** Parse via an input source object
      *
      * This method invokes the parsing process on the XML file specified
      * by the InputSource parameter. This API is borrowed from the
      * SAX Parser interface.
      *
      * @param source A const reference to the InputSource object which
      *               points to the XML file to be parsed.
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing run.
      *                     If true, there cannot be any internal subset.
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception IDOM_DOMException A DOM exception as per DOM spec.
      * @see InputSource#InputSource
      * @see #setEntityResolver
      * @see #setErrorHandler
      */
    void parse(const InputSource& source, const bool reuseGrammar = false);

    /** Parse via a file path or URL
      *
      * This method invokes the parsing process on the XML file specified by
      * the Unicode string parameter 'systemId'. This method is borrowed
      * from the SAX Parser interface.
      *
      * @param systemId A const XMLCh pointer to the Unicode string which
      *                 contains the path to the XML file to be parsed.
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing run.
      *                     If true, there cannot be any internal subset.
      *
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception DOM_DOMException A DOM exception as per DOM spec.
      * @see #parse(InputSource,...)
      */
    void parse(const XMLCh* const systemId, const bool reuseGrammar = false);

    /** Parse via a file path or URL (in the local code page)
      *
      * This method invokes the parsing process on the XML file specified by
      * the native char* string parameter 'systemId'.
      *
      * @param systemId A const char pointer to a native string which
      *                 contains the path to the XML file to be parsed.
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing run.
      *                     If true, there cannot be any internal subset.
      *
      * @exception SAXException Any SAX exception, possibly
      *            wrapping another exception.
      * @exception XMLException An exception from the parser or client
      *            handler code.
      * @exception DOM_DOMException A DOM exception as per DOM spec.
      * @see #parse(InputSource,...)
      */
    void parse(const char* const systemId, const bool reuseGrammar = false);

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
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing process.
      *                     If true, there cannot be any internal subset.
      * @return 'true', if successful in parsing the prolog. It indicates the
      *         user can go ahead with parsing the rest of the file. It
      *         returns 'false' to indicate that the parser could not parse
      *         the prolog.
      *
      * @see #parseNext
      * @see #parseFirst(char*,...)
      * @see #parseFirst(InputSource&,...)
      */
    bool parseFirst
    (
        const   XMLCh* const    systemId
        ,       XMLPScanToken&  toFill
        , const bool            reuseGrammar = false
    );

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
      *                 internal consistency between invocation of 'parseNext'
      *                 calls.
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing run.
      *                     If true, there cannot be any internal subset.
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
    bool parseFirst
    (
        const   char* const     systemId
        ,       XMLPScanToken&  toFill
        , const bool            reuseGrammar = false
    );

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
      * @param reuseGrammar The flag indicating whether the existing Grammar
      *                     should be reused or not for this parsing process.
      *                     If true, there cannot be any internal subset.
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
    bool parseFirst
    (
        const   InputSource&    source
        ,       XMLPScanToken&  toFill
        , const bool            reuseGrammar = false
    );

    /** Continue a progressive parse operation
      *
      * This method is used to continue with progressive parsing of
      * XML files started by a call to 'parseFirst' method.
      *
      * It parses the XML file and stops as soon as it comes across
      * a XML token (as defined in the XML specification).
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
    bool parseNext(XMLPScanToken& token);

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
      *
      * @see #parseFirst(XMLCh*,...)
      * @see #parseFirst(char*,...)
      * @see #parseFirst(InputSource&,...)
      */
    void parseReset(XMLPScanToken& token);

    //@}



    // -----------------------------------------------------------------------
    //  Implementation of the XMLErrorReporter interface.
    // -----------------------------------------------------------------------

    /** @name Implementation of the XMLErrorReporter interface. */
    //@{

    /** Handle errors reported from the parser
      *
      * This method is used to report back errors found while parsing the
      * XML file. This method is also borrowed from the SAX specification.
      * It calls the corresponding user installed Error Handler method:
      * 'fatal', 'error', 'warning' depending on the severity of the error.
      * This classification is defined by the XML specification.
      *
      * @param errCode An integer code for the error.
      * @param msgDomain A const pointer to an Unicode string representing
      *                  the message domain to use.
      * @param errType An enumeration classifying the severity of the error.
      * @param errorText A const pointer to an Unicode string representing
      *                  the text of the error message.
      * @param systemId  A const pointer to an Unicode string representing
      *                  the system id of the XML file where this error
      *                  was discovered.
      * @param publicId  A const pointer to an Unicode string representing
      *                  the public id of the XML file where this error
      *                  was discovered.
      * @param lineNum   The line number where the error occurred.
      * @param colNum    The column number where the error occurred.
      * @see ErrorHandler
      */
    virtual void error
    (
        const   unsigned int                errCode
        , const XMLCh* const                msgDomain
        , const XMLErrorReporter::ErrTypes  errType
        , const XMLCh* const                errorText
        , const XMLCh* const                systemId
        , const XMLCh* const                publicId
        , const unsigned int                lineNum
        , const unsigned int                colNum
    );

    /** Reset any error data before a new parse
     *
      * This method allows the user installed Error Handler callback to
      * 'reset' itself.
      *
      * <b><font color="#FF0000">This method is a no-op for this IDOM
      * implementation.</font></b>
      */
    virtual void resetErrors();
    //@}


    // -----------------------------------------------------------------------
    //  Implementation of the XMLEntityHandler interface.
    // -----------------------------------------------------------------------

    /** @name Implementation of the XMLEntityHandler interface. */
    //@{

    /** Handle an end of input source event
      *
      * This method is used to indicate the end of parsing of an external
      * entity file.
      *
      * <b><font color="#FF0000">This method is a no-op for this IDOM
      * implementation.</font></b>
      *
      * @param inputSource A const reference to the InputSource object
      *                    which points to the XML file being parsed.
      * @see InputSource
      */
    virtual void endInputSource(const InputSource& inputSource);

    /** Expand a system id
      *
      * This method allows an installed XMLEntityHandler to further
      * process any system id's of enternal entities encountered in
      * the XML file being parsed, such as redirection etc.
      *
      * <b><font color="#FF0000">This method always returns 'false'
      * for this IDOM implementation.</font></b>
      *
      * @param systemId  A const pointer to an Unicode string representing
      *                  the system id scanned by the parser.
      * @param toFill    A pointer to a buffer in which the application
      *                  processed system id is stored.
      * @return 'true', if any processing is done, 'false' otherwise.
      */
    virtual bool expandSystemId
    (
        const   XMLCh* const    systemId
        ,       XMLBuffer&      toFill
    );

    /** Reset any entity handler information
      *
      * This method allows the installed XMLEntityHandler to reset
      * itself.
      *
      * <b><font color="#FF0000">This method is a no-op for this IDOM
      * implementation.</font></b>
      */
    virtual void resetEntities();

    /** Resolve a public/system id
      *
      * This method allows a user installed entity handler to further
      * process any pointers to external entities. The applications can
      * implement 'redirection' via this callback. This method is also
      * borrowed from the SAX specification.
      *
      * @param publicId A const pointer to a Unicode string representing the
      *                 public id of the entity just parsed.
      * @param systemId A const pointer to a Unicode string representing the
      *                 system id of the entity just parsed.
      * @return The value returned by the user installed resolveEntity
      *         method or NULL otherwise to indicate no processing was done.
      * @see EntityResolver
      */
    virtual InputSource* resolveEntity
    (
        const   XMLCh* const    publicId
        , const XMLCh* const    systemId
    );

    /** Handle a 'start input source' event
      *
      * This method is used to indicate the start of parsing an external
      * entity file.
      *
      * <b><font color="#FF0000">This method is a no-op for this IDOM parse
      * implementation.</font></b>
      *
      * @param inputSource A const reference to the InputSource object
      *                    which points to the external entity
      *                    being parsed.
      */
    virtual void startInputSource(const InputSource& inputSource);

    //@}



    // -----------------------------------------------------------------------
    //  Implementation of the XMLDocumentHandler interface.
    // -----------------------------------------------------------------------

    /** @name Implementation of the XMLDocumentHandler interface. */
    //@{

    /** Handle document character events
      *
      * This method is used to report all the characters scanned by the
      * parser. This IDOM implementation stores this data in the appropriate
      * IDOM node, creating one if necessary.
      *
      * @param chars   A const pointer to a Unicode string representing the
      *                character data.
      * @param length  The length of the Unicode string returned in 'chars'.
      * @param cdataSection  A flag indicating if the characters represent
      *                      content from the CDATA section.
      */
    virtual void docCharacters
    (
        const   XMLCh* const    chars
        , const unsigned int    length
        , const bool            cdataSection
    );

    /** Handle a document comment event
      *
      * This method is used to report any comments scanned by the parser.
      * A new comment node is created which stores this data.
      *
      * @param comment A const pointer to a null terminated Unicode
      *                string representing the comment text.
      */
    virtual void docComment
    (
        const   XMLCh* const    comment
    );

    /** Handle a document PI event
      *
      * This method is used to report any PI scanned by the parser. A new
      * PI node is created and appended as a child of the current node in
      * the tree.
      *
      * @param target A const pointer to a Unicode string representing the
      *               target of the PI declaration.
      * @param data   A const pointer to a Unicode string representing the
      *               data of the PI declaration. See the PI production rule
      *               in the XML specification for details.
      */
    virtual void docPI
    (
        const   XMLCh* const    target
        , const XMLCh* const    data
    );

    /** Handle the end of document event
      *
      * This method is used to indicate the end of the current document.
      */
    virtual void endDocument();

    /** Handle and end of element event
      *
      * This method is used to indicate the end tag of an element. The
      * IDOMParse pops the current element off the top of the element
      * stack, and make it the new current element.
      *
      * @param elemDecl A const reference to the object containing element
      *                 declaration information.
      * @param urlId    An id referring to the namespace prefix, if
      *                 namespaces setting is switched on.
      * @param isRoot   A flag indicating whether this element was the
      *                 root element.
      */
    virtual void endElement
    (
        const   XMLElementDecl& elemDecl
        , const unsigned int    urlId
        , const bool            isRoot
    );

    /** Handle and end of entity reference event
      *
      * This method is used to indicate that an end of an entity reference
      * was just scanned.
      *
      * @param entDecl A const reference to the object containing the
      *                entity declaration information.
      */
    virtual void endEntityReference
    (
        const   XMLEntityDecl&  entDecl
    );

    /** Handle an ignorable whitespace vent
      *
      * This method is used to report all the whitespace characters, which
      * are determined to be 'ignorable'. This distinction between characters
      * is only made, if validation is enabled.
      *
      * Any whitespace before content is ignored. If the current node is
      * already of type IDOM_Node::TEXT_NODE, then these whitespaces are
      * appended, otherwise a new Text node is created which stores this
      * data. Essentially all contiguous ignorable characters are collected
      * in one node.
      *
      * @param chars   A const pointer to a Unicode string representing the
      *                ignorable whitespace character data.
      * @param length  The length of the Unicode string 'chars'.
      * @param cdataSection  A flag indicating if the characters represent
      *                      content from the CDATA section.
      */
    virtual void ignorableWhitespace
    (
        const   XMLCh* const    chars
        , const unsigned int    length
        , const bool            cdataSection
    );

    /** Handle a document reset event
      *
      * This method allows the user installed Document Handler to 'reset'
      * itself, freeing all the memory resources. The scanner calls this
      * method before starting a new parse event.
      */
    virtual void resetDocument();

    /** Handle a start document event
      *
      * This method is used to report the start of the parsing process.
      */
    virtual void startDocument();

    /** Handle a start element event
      *
      * This method is used to report the start of an element. It is
      * called at the end of the element, by which time all attributes
      * specified are also parsed. A new IDOM Element node is created
      * along with as many attribute nodes as required. This new element
      * is added appended as a child of the current node in the tree, and
      * then replaces it as the current node (if the isEmpty flag is false.)
      *
      * @param elemDecl A const reference to the object containing element
      *                 declaration information.
      * @param urlId    An id referring to the namespace prefix, if
      *                 namespaces setting is switched on.
      * @param elemPrefix A const pointer to a Unicode string containing
      *                 the namespace prefix for this element. Applicable
      *                 only when namespace processing is enabled.
      * @param attrList A const reference to the object containing the
      *                 list of attributes just scanned for this element.
      * @param attrCount A count of number of attributes in the list
      *                 specified by the parameter 'attrList'.
      * @param isEmpty  A flag indicating whether this is an empty element
      *                 or not. If empty, then no endElement() call will
      *                 be made.
      * @param isRoot   A flag indicating whether this element was the
      *                 root element.
      * @see DocumentHandler#startElement
      */
    virtual void startElement
    (
        const   XMLElementDecl&         elemDecl
        , const unsigned int            urlId
        , const XMLCh* const            elemPrefix
        , const RefVectorOf<XMLAttr>&   attrList
        , const unsigned int            attrCount
        , const bool                    isEmpty
        , const bool                    isRoot
    );

    /** Handle a start entity reference event
      *
      * This method is used to indicate the start of an entity reference.
      * If the expand entity reference flag is true, then a new
      * IDOM Entity reference node is created.
      *
      * @param entDecl A const reference to the object containing the
      *                entity declaration information.
      */
    virtual void startEntityReference
    (
        const   XMLEntityDecl&  entDecl
    );

    /** Handle an XMLDecl event
      *
      * This method is used to report the XML decl scanned by the parser.
      * Refer to the XML specification to see the meaning of parameters.
      *
      * <b><font color="#FF0000">This method is a no-op for this IDOM
      * implementation.</font></b>
      *
      * @param versionStr A const pointer to a Unicode string representing
      *                   version string value.
      * @param encodingStr A const pointer to a Unicode string representing
      *                    the encoding string value.
      * @param standaloneStr A const pointer to a Unicode string
      *                      representing the standalone string value.
      * @param actualEncStr A const pointer to a Unicode string
      *                     representing the actual encoding string
      *                     value.
      */
    virtual void XMLDecl
    (
        const   XMLCh* const    versionStr
        , const XMLCh* const    encodingStr
        , const XMLCh* const    standaloneStr
        , const XMLCh* const    actualEncStr
    );
    //@}


    /** @name Deprecated Methods */
    //@{
    /**
      * This method returns the state of the parser's validation
      * handling flag which controls whether validation checks
      * are enforced or not.
      *
      * @return true, if the parser is currently configured to
      *         do validation, false otherwise.
      *
      * @see #setDoValidation
      */
    bool getDoValidation() const;

    /**
      * This method allows users to enable or disable the parser's validation
      * checks.
      *
      * <p>By default, the parser does not to any validation. The default
      * value is false.</p>
      *
      * @param newState The value specifying whether the parser should
      *                 do validity checks or not against the DTD in the
      *                 input XML document.
      *
      * @see #getDoValidation
      */
    void setDoValidation(const bool newState);

    /**
      * Deprecated doctypehandler interfaces
      */
	virtual void attDef
    (
        const   DTDElementDecl&     elemDecl
        , const DTDAttDef&          attDef
        , const bool                ignoring
    );

    virtual void doctypeComment
    (
        const   XMLCh* const    comment
    );

    virtual void doctypeDecl
    (
        const   DTDElementDecl& elemDecl
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const bool            hasIntSubset
    );

    virtual void doctypePI
    (
        const   XMLCh* const    target
        , const XMLCh* const    data
    );

    virtual void doctypeWhitespace
    (
        const   XMLCh* const    chars
        , const unsigned int    length
    );

    virtual void elementDecl
    (
        const   DTDElementDecl& decl
        , const bool            isIgnored
    );

    virtual void endAttList
    (
        const   DTDElementDecl& elemDecl
    );

    virtual void endIntSubset();

    virtual void endExtSubset();

    virtual void entityDecl
    (
        const   DTDEntityDecl&  entityDecl
        , const bool            isPEDecl
        , const bool            isIgnored
    );

    virtual void resetDocType();

    virtual void notationDecl
    (
        const   XMLNotationDecl&    notDecl
        , const bool                isIgnored
    );

    virtual void startAttList
    (
        const   DTDElementDecl& elemDecl
    );

    virtual void startIntSubset();

    virtual void startExtSubset();

    virtual void TextDecl
    (
        const   XMLCh* const    versionStr
        , const XMLCh* const    encodingStr
    );


    //@}


protected :
    // -----------------------------------------------------------------------
    //  Protected getter methods
    // -----------------------------------------------------------------------

    /** @name Protected getter methods */
    //@{
    /** Get the current IDOM node
      *
      * This provides derived classes with access to the current node, i.e.
      * the node to which new nodes are being added.
      */
    IDOM_Node* getCurrentNode();

    //@}


    // -----------------------------------------------------------------------
    //  Protected setter methods
    // -----------------------------------------------------------------------

    /** @name Protected setter methods */
    //@{

    /** Set the current IDOM node
      *
      * This method sets the current node maintained inside the parser to
      * the one specified.
      *
      * @param toSet The IDOM node which will be the current node.
      */
    void setCurrentNode(IDOM_Node* toSet);

    /** Set the document node
      *
      * This method sets the IDOM Document node to the one specified.
      *
      * @param toSet The new IDOM Document node for this XML document.
      */
    void setDocument(IDOM_Document* toSet);
    //@}


private :
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fCurrentNode
    //  fCurrentParent
    //      Used to track the current node during nested element events. Since
    //      the tree must be built from a set of disjoint callbacks, we need
    //      these to keep up with where we currently are.
    //
    //  fDocument
    //      The root document object, filled with the document contents.
    //
    //  fEntityResolver
    //      The installed SAX entity resolver, if any. Null if none.
    //
    //  fErrorHandler
    //      The installed SAX error handler, if any. Null if none.
    //
    //  fCreateEntityReferenceNode
    //      Indicates whether entity reference nodes should be created.
    //
    //  fIncludeIgnorableWhitespace
    //      Indicates whether ignorable whiltespace should be added to
    //      the IDOM tree for validating parsers.
    //
    //  fNodeStack
    //      Used to track previous parent nodes during nested element events.
    //
    //  fParseInProgress
    //      Used to prevent multiple entrance to the parser while its doing
    //      a parse.
    //
    //  fScanner
    //      The scanner used for this parser. This is created during the
    //      constructor.
    //
    //  fWithinElement
    //      A flag to indicate that the parser is within at least one level
    //      of element processing.
    //
    //  fDocumentType
    //      Used to store and update the documentType variable information
    //      in fDocument
    //
    //  fDocumentVector
    //      Store all the previous fDocument(s) (thus not the current fDocument)
    //      created in this parser.  It is destroyed when the parser is destructed.
    // -----------------------------------------------------------------------
    IDOM_Node*               fCurrentParent;
    IDOM_Node*               fCurrentNode;
    IDDocumentImpl*          fDocument;
    EntityResolver*          fEntityResolver;
    ErrorHandler*            fErrorHandler;
    bool                     fCreateEntityReferenceNodes;
    bool                     fIncludeIgnorableWhitespace;
    ValueStackOf<IDOM_Node*>* fNodeStack;
    bool                     fParseInProgress;
    XMLScanner*              fScanner;
    bool                     fWithinElement;
    IDDocumentTypeImpl*      fDocumentType;
    RefVectorOf<IDDocumentImpl>* fDocumentVector;
};



// ---------------------------------------------------------------------------
//  IDOMParser: Handlers for the XMLEntityHandler interface
// ---------------------------------------------------------------------------
inline void IDOMParser::endInputSource(const InputSource&)
{
    // The IDOM entity resolver doesn't handle this
}

inline bool IDOMParser::expandSystemId(const XMLCh* const, XMLBuffer&)
{
    // The IDOM entity resolver doesn't handle this
    return false;
}

inline void IDOMParser::resetEntities()
{
    // Nothing to do on this one
}

inline void IDOMParser::startInputSource(const InputSource&)
{
    // The IDOM entity resolver doesn't handle this
}


// ---------------------------------------------------------------------------
//  IDOMParser: Getter methods
// ---------------------------------------------------------------------------
inline ErrorHandler* IDOMParser::getErrorHandler()
{
    return fErrorHandler;
}

inline const ErrorHandler* IDOMParser::getErrorHandler() const
{
    return fErrorHandler;
}

inline EntityResolver* IDOMParser::getEntityResolver()
{
    return fEntityResolver;
}

inline const EntityResolver* IDOMParser::getEntityResolver() const
{
    return fEntityResolver;
}

inline bool IDOMParser::getExpandEntityReferences() const
{
    return fCreateEntityReferenceNodes;
}
inline bool IDOMParser::getCreateEntityReferenceNodes() const
{
    return fCreateEntityReferenceNodes;
}

inline bool IDOMParser::getIncludeIgnorableWhitespace() const
{
    return fIncludeIgnorableWhitespace;
}


// ---------------------------------------------------------------------------
//  IDOMParser: Setter methods
// ---------------------------------------------------------------------------
inline void IDOMParser::setExpandEntityReferences(const bool expand)
{
    fCreateEntityReferenceNodes = expand;
}

inline void IDOMParser::setCreateEntityReferenceNodes(const bool create)
{
    fCreateEntityReferenceNodes = create;
}

inline void IDOMParser::setIncludeIgnorableWhitespace(const bool include)
{
    fIncludeIgnorableWhitespace = include;
}


// ---------------------------------------------------------------------------
//  IDOMParser: Protected getter methods
// ---------------------------------------------------------------------------
inline IDOM_Node* IDOMParser::getCurrentNode()
{
    return fCurrentNode;
}


// ---------------------------------------------------------------------------
//  IDOMParser: Protected setter methods
// ---------------------------------------------------------------------------
inline void IDOMParser::setCurrentNode(IDOM_Node* toSet)
{
    fCurrentNode = toSet;
}

inline void IDOMParser::setDocument(IDOM_Document* toSet)
{
    fDocument = (IDDocumentImpl *)toSet;
}

#endif
