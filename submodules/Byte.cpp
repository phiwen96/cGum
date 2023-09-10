export module cGum.Concepts.Byte;

export template <typename T, auto n>
concept Bytes = sizeof (T) == n;

export template <typename T>
concept Byte = Bytes <T, 1>;

export template <typename T, auto n>
concept MaxBytes = sizeof (T) <= n;

export template <typename T, auto n>
concept MinBytes = sizeof (T) >= n;

static_assert (Bytes <char, 1>);
static_assert (Bytes <int, 4>);
static_assert (Bytes <unsigned short, 2>);
static_assert (not Bytes <unsigned char, 2>);