// Copyright (c) 2015 Sonic Detours. All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Patch data.
//
#ifndef NM102_PATCH_H_
#define NM102_PATCH_H_

#include "avrlib/base.h"

namespace nm102 {

const uint8_t kPatchNameSize = 8;

// #define PATCH_SIZE (sizeof(Patch) - 8)

class Patch {
 public:
  uint16_t rate;
  uint16_t depth;
  uint16_t mix;

  uint8_t shape;

  uint8_t name[kPatchNameSize];
  uint8_t version;
};

}  // namespace nm102

#endif