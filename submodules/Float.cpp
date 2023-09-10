module;
// #if defined (MACOS)
// #include <arm_neon.h>
// #endif
#include <stdfloat>
export module cGum.Concepts.Number.Float;

import cGum.Concepts.Convertible;
import cGum.Concepts.Byte;

export template <typename T>
concept Float = Convertible <T, float> or 
	Convertible <T, double> or 
	Convertible <T, long double>;

// #if defined (MACOS)
// auto operator + (float32x4_t v1, float32x4_t v2) noexcept -> float32x4_t {
// 	return vaddq_f32 (v1, v2);
// }
// #endif

export template <Float T>
struct v_floats;

// export template <>
// struct v_floats <std::float32_t> {
// 	std::float32_t a, b, c, d;

// 	inline auto operator *= (std::float32_t s) noexcept -> v_floats& {
	
// 		auto v = float32x4_t {a, b, c, d};
// 		auto prod = vmulq_n_f32 (v, s);
// 		// a = prod[0];
	
// 		return *this;
// 	}
// };

static_assert (Bytes <float, 4>);
static_assert (Bytes <std::float32_t, 4>);
static_assert (Bytes <std::float64_t, 8>);


static_assert (Float <float>);
static_assert (Float <double>);
static_assert (Float <long double>);
static_assert (Float <std::float16_t>);
static_assert (Float <std::float32_t>);