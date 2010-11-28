/*
 * $RCSfile: DigestMD5.h,v $
 * $Date: 2005/01/20 21:29:04 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DIGESTMD5_H_SW
#define DIGESTMD5_H_SW

#include <string>
#include <stdio.h>
using namespace std;

#define MD5_BUFFER_SIZE 33

namespace biblia {
  namespace seguranca {

	class DigestMD5{

		private:
			typedef unsigned char md5_byte_t; /* 8-bit byte */
			typedef unsigned int md5_word_t; /* 32-bit word */

			/* Define the state of the MD5 Algorithm. */
			typedef struct md5_state_s {
				md5_word_t count[2];	/* message length in bits, lsw first */
				md5_word_t abcd[4];		/* digest buffer */
				md5_byte_t buf[64];		/* accumulate block */
			} md5_state_t;

			static void DigestMD5::md5_process(md5_state_t *pms, const md5_byte_t *data /*[64]*/);

			/* Initialize the algorithm. */
			static void DigestMD5::md5_init(md5_state_t *pms);

			/* Append a std::string to the message. */
			static void DigestMD5::md5_append(md5_state_t *pms, const md5_byte_t *data, int nbytes);

			/* Finish the message and return the digest. */
			static void DigestMD5::md5_finish(md5_state_t *pms, md5_byte_t digest[16]);


		public:
			static std::string toHexaString(const std::string& entrada);
			static std::string toHexaInt(const int& entrada);
			static void DigestMD5::md5 (const char* buffer,int tamanho,char* result);
			static int DigestMD5::md5_32bits (const char* buffer, int tamanho);
	};
  }
}

#endif