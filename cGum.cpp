module;
#include <iostream>
#include <stdlib.h>
#include <arm_neon.h>
// #include <x86intrin.h>
// #include <emmintrin.h>
// #include <immintrin.h>
export module cGum;

export import cGum.Concepts.Byte;
export import cGum.Concepts.Same;
export import cGum.Concepts.Convertible;
export import cGum.Concepts.Char;
export import cGum.Concepts.Number.Float;
export import cGum.Concepts.Number.Integer;
export import cGum.Concepts.Number;
// export import cGum.SSL;
export import cGum.Networking;

 __attribute__ ((constructor, destructor, cold)) 
auto _cgum () -> int {
	// std::cout << "yoyoyo" << std::endl;
	return 0;
}

static_assert (__builtin_has_attribute (_cgum, constructor), "constructor");



// static_assert (__has_builtin (__builtin_cpu_supports));



// __attribute__ ((ifunc ("cgum_resolver")))
// void ccgum ();

// auto cgum_optimized () -> void {

// }

// auto cgum_debug () -> void {
// 	std::cout << "cgum debug" << std::endl;
// }

// using cgum_t = decltype (ccgum);

// extern "C" {
// auto cgum_resolver () -> cgum_t* {
// 	__builtin_cpu_init ();
// 	if (__builtin_cpu_supports("dfp")) {

// 	}
// 	else {

// 	}
// 	// return getenv ("DEBUG") ? cgum_debug : cgum_optimized;
// 	return cgum_optimized;
// }
// }


// export __attribute__ ((access (read_only, 1)))
// int puts (const char*) {
// 	return 0;
// }


