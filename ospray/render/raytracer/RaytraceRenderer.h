// ======================================================================== //
// Copyright 2009-2016 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

/*! \defgroup ospray_render_obj "Wavefront OBJ" Material-based Renderer

  \brief Implements the Wavefront OBJ Material Model
  
  \ingroup ospray_supported_renderers

  This renderer implementes a shading model roughly based on the
  Wavefront OBJ material format. In particular, this renderer
  implements the Material model as implemented in \ref
  ospray::OBJMaterial, and implements a recursive ray tracer on top of
  this mateiral model.

  Note that this renderer is NOT fully compatible with the Wavefront
  OBJ specifications - in particular, we do not support the different
  illumination models as specified in the 'illum' field, and always
  perform full ray tracing with the given material parameters.

*/

// ospray
#include "ospray/render/Renderer.h"
#include "ospray/common/Material.h"

// system
#include <vector>

namespace ospray {

  namespace raytracer {
    //    using embree::TaskScheduler;

    /*! \brief Renderer for the OBJ Wavefront Material/Lighting format

      See \ref ospray_render_raytracer
    */
    struct RaytraceRenderer : public Renderer {
      RaytraceRenderer();
      virtual std::string toString() const;
      virtual void commit();
      virtual Material *createMaterial(const char *type);

      std::vector<void*> lightArray; // the 'IE's of the XXXLights
      Data *lightData;
    };

    // Inlined member functions ///////////////////////////////////////////////

    inline std::string RaytraceRenderer::toString() const
    {
      return "ospray::RaytraceRenderer";
    }

  } // ::ospray::api
} // ::ospray
