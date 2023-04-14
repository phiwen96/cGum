export module cGum.Concepts.Char;

import cGum.Concepts.Convertible;

// using char_types = typelist <char, signed char, unsigned char, char16_t, char32_t, wchar_t>;

export template <typename T>
concept Char = Convertible <T, char> or 
	Convertible <T, signed char> or 
	Convertible <T, unsigned char> or 
	Convertible <T, char16_t> or 
	Convertible <T, char32_t> or 
	Convertible <T, wchar_t>;

//AnyOf <[] <typename U> {return Convertible <T, U>;}, char_types>;

// static_assert (Char <char&>);