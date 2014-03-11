   /** @file pch.h : include file for standard system include files,
 *  or project specific include files that are used frequently, but
 *  are changed infrequently
 */

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef MONGO_PCH_H
#define MONGO_PCH_H

// our #define macros must not be active when we include
// system headers and boost headers
#include "mongo/client/undef_macros.h"

#include "mongo/platform/basic.h"

// TODO: Remove after removing 'using namespace std', or this header doesn't compile
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <time.h>
#include <string.h>
#include <limits.h>

#include "mongo/client/redef_macros.h"

#include "mongo/client/export_macros.h"
#include "mongo/util/exit_code.h"

namespace mongo {

    using namespace std;

    void dbexit( ExitCode returnCode, const char *whyMsg = "" );

    /**
       this is here so you can't just type exit() to quit the program
       you should either use dbexit to shutdown cleanly, or ::exit to tell the system to quit
       if you use this, you'll get a link error since mongo::exit isn't defined
     */
    MONGO_CLIENT_API void exit( ExitCode returnCode );
    MONGO_CLIENT_API bool inShutdown();

}

#endif // MONGO_PCH_H
