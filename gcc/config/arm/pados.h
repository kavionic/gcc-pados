/*
 * Copyright (C) 2025 Kurt Skauen. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define HAS_INIT_SECTION

/* PadOS exit() and abort() uses _Unwind_ForcedUnwind to unwind C++ stacks on
   process exit. They must therefore not be treated as nothrow by the compiler,
   or EH cleanup edges will be suppressed at call sites and destructors will
   never be invoked.  This flag is tested in except.cc.  */
#define PADOS_EXIT_NOT_NOTHROW 1

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
    do {					\
	builtin_define ("__pados__");		\
	builtin_assert ("system=pados");	\
	TARGET_BPABI_CPP_BUILTINS();    	\
    } while (0)

