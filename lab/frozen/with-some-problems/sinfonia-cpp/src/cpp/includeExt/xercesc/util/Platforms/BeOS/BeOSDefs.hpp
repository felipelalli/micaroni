/*
 * Copyright 2002,2004 The Apache Software Foundation.
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
 * $Log: BeOSDefs.hpp,v $
 * Revision 1.2  2005/01/21 20:27:34  felipelalli
 * colocando stlport 5.0 beta, o maldito erro continua.
 *
 * Revision 1.2  2005/01/10 23:16:24  fernandofernandes
 * no message
 *
 * Revision 1.4  2004/09/08 13:56:38  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.3  2003/02/23 05:34:57  jberry
 * Re-add BeOSDefs.hpp after munging repository
 *
 * Revision 1.1  2002/12/31 19:30:56  tng
 * [Bug 15590] BeOSDefs.hpp has wrong case in CVS.
 *
 *
 */


// ---------------------------------------------------------------------------
//  BeOS runs in little endian mode
// ---------------------------------------------------------------------------
#define ENDIANMODE_LITTLE
typedef void* FileHandle;

#ifndef BEOS
#define BEOS
#endif
