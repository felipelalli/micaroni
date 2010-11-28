/*
 * $RCSfile: randomc.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

/***************************** RANDOMC.H *********************** 2001-10-24 AF *
*
* This file contains class declarations for the C++ library of uniform
* random number generators.
*
* Overview of classes:
* ====================
*
* class TRanrotBGenerator:
* Random number generator of type RANROT-B.
* Source file ranrotb.cpp
*
* class TRanrotWGenerator:
* Random number generator of type RANROT-W.
* Source file ranrotw.cpp
*
* class TRandomMotherOfAll:
* Random number generator of type Mother-of-All (Multiply with carry).
* Source file mother.cpp
*
* class TRandomMersenne:
* Random number generator of type Mersenne twister.
* Source file mersenne.cpp
*
* class TRandomMotRot:
* Combination of Mother-of-All and RANROT-W generators.
* Source file ranmoro.cpp and motrot.asm.
* Coded in assembly language for improved speed.
* Must link in RANDOMAO.LIB or RANDOMAC.LIB.
*
*
* Member functions (methods):
* ===========================
*
* All these classes have identical member functions:
*
* Constructor(long int seed):
* The seed can be any integer. Usually the time is used as seed.
* Executing a program twice with the same seed will give the same sequence of
* random numbers. A different seed will give a different sequence.
*
* double Random();
* Gives a floating point random number in the interval 0 <= x < 1.
* The resolution is 32 bits in TRanrotBGenerator, TRandomMotherOfAll and
* TRandomMersenne. 52 or 63 bits in TRanrotWGenerator. 63 bits in
* TRandomMotRot.
*
* int IRandom(int min, int max);
* Gives an integer random number in the interval min <= x <= max.
* The resolution is the same as for Random().
*
* unsigned long BRandom();
* Gives 32 random bits.
* Only available in the classes TRanrotWGenerator and TRandomMersenne.
*
*
* Example:
* ========
* The file EX-RAN.CPP contains an example of how to generate random numbers.
*
*
* Further documentation:
* ======================
* The file randomc.htm contains further documentation on these random number
* generators.
*
*******************************************************************************/

#ifndef RANDOMC_H
#define RANDOMC_H

#include <math.h>
#include <assert.h>
#include <stdio.h>

class TRanrotBGenerator {             // encapsulate random number generator
  enum constants {                    // define parameters
    KK = 17, JJ = 10, R1 = 13, R2 =  9};
  public:
  void RandomInit(long int seed);     // initialization
  int IRandom(int min, int max);      // get integer random number in desired interval
  double Random();                    // get floating point random number
  TRanrotBGenerator(long int seed);   // constructor
  protected:
  int p1, p2;                         // indexes into buffer
  unsigned long randbuffer[KK];       // history buffer
#ifdef SELF_TEST
  unsigned long randbufcopy[KK*2];    // used for self-test
#endif
};


#ifdef HIGH_RESOLUTION
typedef long double trfloat;        // use long double precision
#else
typedef double trfloat;             // use double precision
#endif

class TRanrotWGenerator {           // encapsulate random number generator
  enum constants {                  // define parameters
    KK = 17, JJ = 10, R1 = 19, R2 =  27};
  public:
  void RandomInit(long int seed);   // initialization
  int IRandom(int min, int max);    // get integer random number in desired interval
  trfloat Random();                 // get floating point random number
  unsigned long BRandom();          // output random bits
  TRanrotWGenerator(long int seed); // constructor
  protected:
  int p1, p2;                       // indexes into buffer
  union {                           // used for conversion to float
    trfloat randp1;
    unsigned long randbits[3];};
  unsigned long randbuffer[KK][2];  // history buffer
#ifdef SELF_TEST
  unsigned long randbufcopy[KK*2][2];// used for self-test
#endif
};

class TRandomMotherOfAll {               // encapsulate random number generator
  public:
  void RandomInit(long int seed);        // initialization
  int IRandom(int min, int max);         // get integer random number in desired interval
  double Random();                       // get floating point random number
  TRandomMotherOfAll(long int seed);     // constructor
  protected:
  double x[5];                           // history buffer
  };

class TRandomMersenne {                  // encapsulate random number generator
  enum constants {
#if 1
    // define constants for MT11213A
    N = 351, M = 175, R = 19, MATRIX_A = 0xEABD75F5,
    TEMU = 11, TEMS = 7, TEMT = 15, TEML = 17, TEMB = 0x655E5280, TEMC = 0xFFD58000
#else
    // or constants for MT19937
    N = 624, M = 397, R = 31, MATRIX_A = 0x9908B0DF,
    TEMU = 11, TEMS = 7, TEMT = 15, TEML = 18, TEMB = 0x9D2C5680, TEMC = 0xEFC60000
#endif
  };
  public:
  TRandomMersenne(long int seed) {           // constructor
    RandomInit(seed);}
  void RandomInit(long int seed);            // re-seed
  long IRandom(long min, long max);          // output random integer
  double Random();                           // output random float
  unsigned long BRandom();                   // output random bits
  private:
  unsigned long mt[N];                       // state vector
  int mti;                                   // index into mt
  };

class TRandomMotRot {              // encapsulate random number generator from assembly library
  public:
  int IRandom(int min, int max);   // get integer random number in desired interval
  double Random();                 // get floating point random number
  TRandomMotRot(long int seed);    // constructor
  };

#endif