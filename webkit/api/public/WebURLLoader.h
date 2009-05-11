/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebURLLoader_h
#define WebURLLoader_h

#error "This header file is still a work in progress; do not include!"

#include "WebCommon.h"

namespace WebKit {
    class WebCString;
    class WebURLError;
    class WebURLLoaderClient;
    class WebURLRequest;
    class WebURLResponse;

    class WebURLLoader {
    public:
        virtual ~WebURLLoader() {}

        // Load the request synchronously, returning results directly to the
        // caller upon completion.  There is no mechanism to interrupt a
        // synchronous load!!
        virtual void loadSynchronously(const WebURLRequest&,
            WebURLResponse&, WebURLError&, WebCString& data) = 0;

        // Load the request asynchronously, sending notifications to the given
        // client.  The client will receive no further notifications if the
        // loader is disposed before it completes its work.
        virtual void loadAsynchronously(const WebURLRequest&,
            WebURLLoaderClient*) = 0;

        // Cancels an asynchronous load.  This will appear as a load error to
        // the client.
        virtual void cancel() = 0;

        // Suspends/resumes an asynchronous load.
        virtual void setDefersLoading(bool) = 0;
    };

} // namespace WebKit

#endif