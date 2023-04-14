export module cGum.Concepts.Number;

import cGum.Concepts.Number.Float;
import cGum.Concepts.Number.Integer;

export template <typename T>
concept Number = Float <T> or Integer <T>;