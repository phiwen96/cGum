export module cGum.TLS;

import cGum.Concepts.Byte;
import cGum.Concepts.Char;
import cGum.Concepts.Number;

template <typename T>
concept TypeField = Byte <T>;

template <typename T>
concept VersionField = Bytes <T, 2>;

template <typename T>
concept LengthField = Bytes <T, 2>;

template <typename T>
concept FragmentField = MaxBytes <T, 16384>;

enum TLS_protocols {
	change_cipher_spec = 0x14,
	alert = 0x15,
	handshake = 0x16,
	application_data = 0x17
};

template <TypeField type,
	VersionField version,
	LengthField length,
	FragmentField fragment>
struct TLS_plaintext {

};

template <TypeField type,
	VersionField version,
	LengthField length,
	FragmentField fragment>
struct TLS_compressed {

};

template <TypeField type,
	VersionField version,
	LengthField length,
	FragmentField fragment>
struct TLS_ciphertext {

};