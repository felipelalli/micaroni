/*
 * $RCSfile: StringTokenizer.h,v $
 * $Date: 2005/01/20 21:29:31 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

/*
 * StringTokenizer baseado no fonte aberto do Java
 * em sua versão 1.4.2, com a interface para português
 * e algumas adaptações para o C++.
 */

/*
 * @(#)StringTokenizer.java	1.29 03/01/23
 *
 * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#ifndef JAVA_STRING_TOKENIZER_1_29_03_01_23
#define JAVA_STRING_TOKENIZER_1_29_03_01_23

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/util/UtilExcecao.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace util {
	/**
	 * StringTokenizer baseado no fonte aberto do Java
	 * em sua versão 1.4.2, com a interface para português
	 * e algumas adaptações para o C++. Segue a documentação
	 * na forma original do Java.
	 * <p>
	 * <i>
	 * The std::string tokenizer class allows an application to break a
	 * std::string into tokens. The tokenization method is much simpler than
	 * the one used by the <code>StreamTokenizer</code> class. The
	 * <code>StringTokenizer</code> methods do not distinguish among
	 * identifiers, numbers, and quoted std::strings, nor do they recognize
	 * and skip comments.
	 * <p>
	 * The set of delimiters (the characters that separate tokens) may
	 * be specified either at creation time or on a per-token basis.
	 * <p>
	 * An instance of <code>StringTokenizer</code> behaves in one of two
	 * ways, depending on whether it was created with the
	 * <code>returnDelims</code> flag having the value <code>true</code>
	 * or <code>false</code>:
	 * <ul>
	 * <li>If the flag is <code>false</code>, delimiter characters serve to
	 *     separate tokens. A token is a maximal sequence of consecutive
	 *     characters that are not delimiters.
	 * <li>If the flag is <code>true</code>, delimiter characters are themselves
	 *     considered to be tokens. A token is thus either one delimiter
	 *     character, or a maximal sequence of consecutive characters that are
	 *     not delimiters.
	 * </ul><p>
	 * A <tt>StringTokenizer</tt> object internally maintains a current
	 * position within the std::string to be tokenized. Some operations advance this
	 * current position past the characters processed.<p>
	 * A token is returned by taking a substd::string of the std::string that was used to
	 * create the <tt>StringTokenizer</tt> object.
	 * <p>
	 * The following is one example of the use of the tokenizer. The code:
	 * <blockquote><pre>
	 *     StringTokenizer st = new StringTokenizer("this is a test");
	 *     while (st.hasMoreTokens()) {
	 *         System.out.println(st.nextToken());
	 *     }
	 * </pre></blockquote>
	 * <p>
	 * prints the following output:
	 * <blockquote><pre>
	 *     this
	 *     is
	 *     a
	 *     test
	 * </pre></blockquote>
	 *
	 * <p>
	 * (...)
	 * </i>
	 *
	 * @author  unascribed, Sun Microsystems
	 * @version 1.29, 01/23/03
	 * @see     java.io.StreamTokenizer
	 * @since   JDK1.0
	 */
	class StringTokenizer: public Objeto {
		private:
			int StringTokenizer::currentPosition;
			mutable int StringTokenizer::newPosition;
			int StringTokenizer::maxPosition;
			std::string StringTokenizer::str;
			std::string StringTokenizer::delimiters;
			bool StringTokenizer::retDelims;
			bool StringTokenizer::delimsChanged;

			/**
			 * maxDelimChar stores the value of the
			 * delimiter character with the
			 * highest value. It is used to
			 * optimize the detection of delimiter
			 * characters.
			 */
			char StringTokenizer::maxDelimChar;

			/**
			 * Set maxDelimChar to the highest
			 * char in the delimiter set.
			 */
			StringTokenizer& StringTokenizer::setMaxDelimChar();

			/**
			 * Skips delimiters starting from the
			 * specified position. If retDelims
			 * is false, returns the index of the first
			 * non-delimiter character at or
			 * after startPos. If retDelims is true,
			 * startPos is returned.
			 */
			int StringTokenizer::skipDelimiters(int startPos) const;

			/**
			 * Skips ahead from startPos and returns the
			 * index of the next delimiter
			 * character encountered, or
			 * maxPosition if no such delimiter is found.
			 */
			int StringTokenizer::scanToken(int startPos) const;

		public:
			/**
			 * Constructs a std::string tokenizer for the specified std::string. All
			 * characters in the <code>delim</code> argument are the delimiters
			 * for separating tokens.
			 * <p>
			 * If the <code>returnDelims</code> flag is <code>true</code>, then
			 * the delimiter characters are also returned as tokens. Each
			 * delimiter is returned as a std::string of length one. If the flag is
			 * <code>false</code>, the delimiter characters are skipped and only
			 * serve as separators between tokens.
			 * <p>
			 * Note that if <tt>delim</tt> is <tt>null</tt>, this constructor does
			 * not throw an exception. However, trying to invoke other methods on the
			 * resulting <tt>StringTokenizer</tt> may result in a
			 * <tt>NullPointerException</tt>.
			 *
			 * @param   conteudo       a std::string to be parsed.
			 * @param   delimitadores  the delimiters with
			 *                         default=<code>"&nbsp;&#92;t&#92;n&#92;r&#92;f"</code>
			 * @param   returnarDelimitador flag indicating whether to return the delimiters
			 *                              as tokens.
			 */
			StringTokenizer::StringTokenizer(
					const std::string& conteudo,
					const std::string& delimitadores = " \t\n\r\f",
					const bool& returnarDelimitador = false);

			virtual StringTokenizer::~StringTokenizer();

			/**
			 * Tests if there are more tokens available from this tokenizer's std::string.
			 * If this method returns <tt>true</tt>, then a subsequent call to
			 * <tt>nextToken</tt> with no argument will successfully return a token.
			 *
			 * @return  <code>true</code> if and only if there is at least one token
			 *          in the std::string after the current position; <code>false</code>
			 *          otherwise.
			 */
			virtual const bool StringTokenizer::temMaisTokens() const;

			/**
			 * Returns the next token from this std::string tokenizer.
			 *
			 * @return     the next token from this std::string tokenizer.
			 * @exception  NoSuchElementException  if there are no more tokens in this
			 *               tokenizer's std::string.
			 */
			virtual const std::string StringTokenizer::proximo();

			/**
			 * Returns the next token in this std::string tokenizer's std::string. First,
			 * the set of characters considered to be delimiters by this
			 * <tt>StringTokenizer</tt> object is changed to be the characters in
			 * the std::string <tt>delim</tt>. Then the next token in the std::string
			 * after the current position is returned. The current position is
			 * advanced beyond the recognized token.  The new delimiter set
			 * remains the default after this call.
			 *
			 * @param      delimitador the new delimiters.
			 * @return     the next token, after switching to the new delimiter set.
			 * @exception  NoSuchElementException  if there are no more tokens in this
			 *               tokenizer's std::string.
			 */
			virtual const std::string StringTokenizer
					::proximo(const std::string& delimitador);

			/**
			 * Calculates the number of times that this tokenizer's
			 * <code>nextToken</code> method can be called before it generates an
			 * exception. The current position is not advanced.
			 *
			 * @return  the number of tokens remaining in the std::string using the current
			 *          delimiter set.
			 * @see     java.util.StringTokenizer#nextToken()
			 */
			virtual const int StringTokenizer::quantosTokens() const;

			// Objeto:

			/**
			 * Retorna a própria std::string principal.
			 */
			virtual std::string StringTokenizer::emString() const;
	};
  }
}

#endif
