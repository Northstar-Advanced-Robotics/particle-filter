#pragma once

// min and max for host and device code under either CUDA the robot may have. CCCL 2 (CUDA 12,
// JetPack 6) offers thrust::min/max; CCCL 3 (CUDA 13, JetPack 7) removed those in favour of
// cuda::std::min/max. Thrust is there for every target (CUDA and OMP), so its version decides.

#include <thrust/version.h>

#if THRUST_VERSION >= 300000
#include <cuda/std/algorithm>
#else
#include <thrust/extrema.h>
#endif

namespace pf::util {

#if THRUST_VERSION >= 300000
using ::cuda::std::max;
using ::cuda::std::min;
#else
using ::thrust::max;
using ::thrust::min;
#endif

}  // namespace pf::util
