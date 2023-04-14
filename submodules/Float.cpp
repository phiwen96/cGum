export module cGum.Concepts.Number.Float;

import cGum.Concepts.Convertible;

export template <typename T>
concept Float = Convertible <T, float> or 
	Convertible <T, double> or 
	Convertible <T, long double>;