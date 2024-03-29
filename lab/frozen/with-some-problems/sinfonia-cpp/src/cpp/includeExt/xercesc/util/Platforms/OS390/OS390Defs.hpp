/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
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
 * $Log: OS390Defs.hpp,v $
 * Revision 1.3  2005/01/21 20:27:35  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:24  fernandofernandes
 * no message
 *
 * Revision 1.2  2004/09/08 13:56:41  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.1.1.1  2002/02/01 22:22:25  peiyongz
 * sane_include
 *
 * Revision 1.4  2000/03/02 19:55:29  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/06 07:48:29  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  2000/01/21 22:17:21  abagchi
 * OS390 Change: rollup MQWF changes
 *
 * Revision 1.1.1.1  1999/11/09 01:06:36  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:45:31  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */


// ---------------------------------------------------------------------------
//  OS390OE runs in big endian mode
// ---------------------------------------------------------------------------
#define ENDIANMODE_BIG
typedef void* FileHandle;

#ifdef EXM_OS390
#define APP_NO_THREADS
#endif
