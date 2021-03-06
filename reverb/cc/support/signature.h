// Copyright 2019 DeepMind Technologies Limited.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef REVERB_CC_SUPPORT_SIGNATURE_H_
#define REVERB_CC_SUPPORT_SIGNATURE_H_

#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"
#include "absl/strings/string_view.h"
#include "absl/types/optional.h"
#include "reverb/cc/schema.pb.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/hash/hash.h"
#include "tensorflow/core/protobuf/struct.pb.h"

namespace deepmind {
namespace reverb {
namespace internal {

typedef absl::optional<std::vector<tensorflow::DtypeAndPartialTensorShape>>
    DtypesAndShapes;

tensorflow::Status FlatSignatureFromTableInfo(
    const TableInfo& info, DtypesAndShapes* dtypes_and_shapes);

tensorflow::Status FlatSignatureFromStructuredValue(
    const tensorflow::StructuredValue& value,
    DtypesAndShapes* dtypes_and_shapes);

tensorflow::StructuredValue StructuredValueFromChunkData(
    const ChunkData& chunk_data);

tensorflow::Status FlatPathFromStructuredValue(
    const tensorflow::StructuredValue& value, absl::string_view prefix,
    std::vector<std::string>* paths);

// Map from table name to optional vector of flattened (dtype, shape) pairs.
typedef absl::flat_hash_map<std::string, internal::DtypesAndShapes>
    FlatSignatureMap;

std::string DtypesShapesString(
    const std::vector<tensorflow::DtypeAndPartialTensorShape>&
        dtypes_and_shapes);

}  // namespace internal
}  // namespace reverb
}  // namespace deepmind

#endif  // REVERB_CC_SUPPORT_SIGNATURE_H_
