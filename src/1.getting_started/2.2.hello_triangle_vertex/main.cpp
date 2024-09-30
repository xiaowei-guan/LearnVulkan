////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License.  You may obtain a copy
// of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
// License for the specific language governing permissions and limitations
// under the License.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "hello_triangle_vertex.h"
#include "window.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

int main(int argc, char **argv) {
  Window window;
  HelloTriangleVertex helloTriangleVertex;
  // Window creation
  if (!window.Create("Hello, triangle", WIDTH, HEIGHT)) {
    return -1;
  }

  // Vulkan preparations and initialization
  if( !helloTriangleVertex.PrepareVulkan( window.GetWindow()) ) {
    return -1;
  }

  // Tutorial 04
  if( !helloTriangleVertex.CreateRenderPass() ) {
    return -1;
  }
  if( !helloTriangleVertex.CreatePipeline() ) {
    return -1;
  }
  if( !helloTriangleVertex.CreateVertexBuffer() ) {
    return -1;
  }
  if( !helloTriangleVertex.CreateRenderingResources() ) {
    return -1;
  }

  // Rendering loop
  if (!window.RenderingLoop(helloTriangleVertex)) {
    return -1;
  }
  return 0;
}
