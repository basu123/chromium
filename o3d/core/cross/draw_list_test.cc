/*
 * Copyright 2009, Google Inc.
 * All rights reserved.
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


// This file implements unit tests for class DrawList.

#include "core/cross/client.h"
#include "tests/common/win/testing_common.h"
#include "core/cross/draw_list.h"

namespace o3d {

class DrawListTest : public testing::Test {
 protected:

  DrawListTest()
      : object_manager_(g_service_locator) {}

  virtual void SetUp();
  virtual void TearDown();

  Pack* pack() { return pack_; }

 private:

  ServiceDependency<ObjectManager> object_manager_;
  DrawListManager* draw_list_manager_;
  TransformationContext* transformation_context_;
  Pack* pack_;
};

void DrawListTest::SetUp() {
  draw_list_manager_ = new DrawListManager(g_service_locator);
  transformation_context_ = new TransformationContext(g_service_locator);
  pack_ = object_manager_->CreatePack();
}

void DrawListTest::TearDown() {
  pack_->Destroy();
  delete transformation_context_;
  delete draw_list_manager_;
}

TEST_F(DrawListTest, Basic) {
  DrawList* draw_list = pack()->Create<DrawList>();
  // Check that draw_list got created.
  EXPECT_TRUE(draw_list != NULL);
}

}  // namespace o3d
