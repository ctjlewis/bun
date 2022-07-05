/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "ImportMetaObjectBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_importMetaObjectRequireCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_importMetaObjectRequireCodeConstructorKind = JSC::ConstructorKind::None;
const int s_importMetaObjectRequireCodeLength = 1162;
static const JSC::Intrinsic s_importMetaObjectRequireCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_importMetaObjectRequireCode =
    "(function (name) {\n" \
    "  \"use strict\";\n" \
    "  if (typeof name !== \"string\") {\n" \
    "    @throwTypeError(\"require() expects a string as its argument\");\n" \
    "  }\n" \
    "  \n" \
    "  const resolved = this.resolveSync(name, this.path);\n" \
    "  var cached = @requireMap.@get(resolved);\n" \
    "  const last5 = resolved.substring(resolved.length - 5);\n" \
    "  if (cached) {\n" \
    "    if (last5 === \".node\") {\n" \
    "      return cached.exports;\n" \
    "    }\n" \
    "\n" \
    "    return cached;\n" \
    "  }\n" \
    "\n" \
    "  \n" \
    "  //\n" \
    "  if (last5 === \".json\") {\n" \
    "    var fs = (globalThis[Symbol.for(\"_fs\")] ||= Bun.fs());\n" \
    "    var exports = JSON.parse(fs.readFileSync(resolved, \"utf8\"));\n" \
    "    @requireMap.@set(resolved, exports);\n" \
    "    return exports;\n" \
    "  } else if (last5 === \".node\") {\n" \
    "    var module = { exports: {} };\n" \
    "    globalThis.process.dlopen(module, resolved);\n" \
    "    @requireMap.@set(resolved, module);\n" \
    "    return module.exports;\n" \
    "  } else if (last5 === \".toml\") {\n" \
    "    var fs = (globalThis[Symbol.for(\"_fs\")] ||= Bun.fs());\n" \
    "    var exports = Bun.TOML.parse(fs.readFileSync(resolved, \"utf8\"));\n" \
    "    @requireMap.@set(resolved, exports);\n" \
    "    return exports;\n" \
    "  } else {\n" \
    "    var exports = this.requireModule(this, resolved);\n" \
    "    @requireMap.@set(resolved, exports);\n" \
    "    return exports;\n" \
    "  }\n" \
    "})\n" \
;

const JSC::ConstructAbility s_importMetaObjectLoadModuleCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_importMetaObjectLoadModuleCodeConstructorKind = JSC::ConstructorKind::None;
const int s_importMetaObjectLoadModuleCodeLength = 2818;
static const JSC::Intrinsic s_importMetaObjectLoadModuleCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_importMetaObjectLoadModuleCode =
    "(function (meta, resolvedSpecifier) {\n" \
    "  \"use strict\";\n" \
    "\n" \
    "  var queue = @createFIFO();\n" \
    "  var key = resolvedSpecifier;\n" \
    "  while (key) {\n" \
    "    //\n" \
    "    //\n" \
    "    //\n" \
    "    var entry = Loader.registry.@get(key);\n" \
    "\n" \
    "    if (!entry || entry.state <= @ModuleFetch) {\n" \
    "      @fulfillModuleSync(key);\n" \
    "      entry = Loader.registry.@get(key);\n" \
    "    }\n" \
    "\n" \
    "\n" \
    "    //\n" \
    "    //\n" \
    "    //\n" \
    "    //\n" \
    "    var sourceCodeObject = @getPromiseInternalField(\n" \
    "      entry.fetch,\n" \
    "      @promiseFieldReactionsOrResult\n" \
    "    );\n" \
    "\n" \
    "    //\n" \
    "    //\n" \
    "    //\n" \
    "    var moduleRecordPromise = Loader.parseModule(key, sourceCodeObject);\n" \
    "    var module = entry.module;\n" \
    "    if (!module && moduleRecordPromise && @isPromise(moduleRecordPromise)) {\n" \
    "      var reactionsOrResult = @getPromiseInternalField(\n" \
    "        moduleRecordPromise,\n" \
    "        @promiseFieldReactionsOrResult\n" \
    "      );\n" \
    "      var flags = @getPromiseInternalField(\n" \
    "        moduleRecordPromise,\n" \
    "        @promiseFieldFlags\n" \
    "      );\n" \
    "      var state = flags & @promiseStateMask;\n" \
    "\n" \
    "      //\n" \
    "      if (\n" \
    "        state === @promiseStatePending ||\n" \
    "        (reactionsOrResult && @isPromise(reactionsOrResult))\n" \
    "      ) {\n" \
    "        @throwTypeError(`require() async module \\\"${key}\\\" is unsupported`);\n" \
    "      } else if (state === @promiseStateRejected) {\n" \
    "        //\n" \
    "        //\n" \
    "        @throwTypeError(\n" \
    "          `${\n" \
    "            reactionsOrResult?.message ?? \"An error occurred\"\n" \
    "          } while parsing module \\\"${key}\\\"`\n" \
    "        );\n" \
    "      }\n" \
    "      entry.module = module = reactionsOrResult;\n" \
    "    } else if (moduleRecordPromise && !module) {\n" \
    "      entry.module = module = moduleRecordPromise;\n" \
    "    }\n" \
    "\n" \
    "    //\n" \
    "    @setStateToMax(entry, @ModuleLink);\n" \
    "    var dependenciesMap = module.dependenciesMap;\n" \
    "    var requestedModules = Loader.requestedModules(module);\n" \
    "    var dependencies = @newArrayWithSize(requestedModules.length);\n" \
    "\n" \
    "    for (var i = 0, length = requestedModules.length; i < length; ++i) {\n" \
    "      var depName = requestedModules[i];\n" \
    "\n" \
    "      //\n" \
    "      //\n" \
    "      var depKey =\n" \
    "        depName[0] === \"/\"\n" \
    "          ? depName\n" \
    "          : Loader.resolveSync(depName, key, @undefined);\n" \
    "      var depEntry = Loader.ensureRegistered(depKey);\n" \
    "\n" \
    "      if (depEntry.state < @ModuleLink) {\n" \
    "        queue.push(depKey);\n" \
    "      }\n" \
    "\n" \
    "      @putByValDirect(dependencies, i, depEntry);\n" \
    "      dependenciesMap.@set(depName, depEntry);\n" \
    "    }\n" \
    "\n" \
    "    entry.dependencies = dependencies;\n" \
    "    key = queue.shift();\n" \
    "    while (key && (Loader.registry.@get(key)?.state ?? @ModuleFetch) >= @ModuleLink) {\n" \
    "      key = queue.shift();\n" \
    "    }\n" \
    "\n" \
    "  }\n" \
    "\n" \
    "  var linkAndEvaluateResult = Loader.linkAndEvaluateModule(\n" \
    "    resolvedSpecifier,\n" \
    "    @undefined\n" \
    "  );\n" \
    "  if (linkAndEvaluateResult && @isPromise(linkAndEvaluateResult)) {\n" \
    "    //\n" \
    "    //\n" \
    "    @throwTypeError(\n" \
    "      `require() async module \\\"${resolvedSpecifier}\\\" is unsupported`\n" \
    "    );\n" \
    "  }\n" \
    "\n" \
    "  return Loader.registry.@get(resolvedSpecifier);\n" \
    "\n" \
    "})\n" \
;

const JSC::ConstructAbility s_importMetaObjectRequireModuleCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_importMetaObjectRequireModuleCodeConstructorKind = JSC::ConstructorKind::None;
const int s_importMetaObjectRequireModuleCodeLength = 606;
static const JSC::Intrinsic s_importMetaObjectRequireModuleCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_importMetaObjectRequireModuleCode =
    "(function (meta, resolved) {\n" \
    "  \"use strict\";\n" \
    "  var Loader = globalThis.Loader;\n" \
    "  var entry = Loader.registry.@get(resolved);\n" \
    "\n" \
    "  if (!entry || !entry.evaluated) {\n" \
    "    entry = this.loadModule(meta, resolved); \n" \
    "  }\n" \
    "\n" \
    "  if (!entry || !entry.evaluated || !entry.module) {\n" \
    "    @throwTypeError(`require() failed to evaluate module \\\"${resolved}\\\". This is an internal consistentency error.`);\n" \
    "  }\n" \
    "  var exports = Loader.getModuleNamespaceObject(entry.module);\n" \
    "  var commonJS = exports.default;\n" \
    "  if (commonJS && @isObject(commonJS) && @commonJSSymbol in commonJS) {\n" \
    "    return commonJS();\n" \
    "  }\n" \
    "  return exports;\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().importMetaObjectBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().importMetaObjectBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
