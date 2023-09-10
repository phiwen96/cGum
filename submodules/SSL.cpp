export module cGum.SSL;

import cGum.Concepts.Byte;
import cGum.Concepts.Char;
import cGum.Concepts.Number;

enum struct SSL_cipher_suites {
	// Key exchange, Cipher, Hash
	SSL_NULL_WITH_NULL_NULL = 0x0000,
	SSL_RSA_WITH_NULL_MD5 = 0x0001,
	SSL_RSA_WITH_NULL_SHA = 0x0002,
	SSL_RSA_EXPORT_WITH_RC4_40_MD5 = 0x0003,
	SSL_RSA_WITH_RC4_128_MD5 = 0x0004,
	SSL_RSA_WITH_RC4_128_SHA = 0x0005,
	SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5 = 0x0006,
	SSL_RSA_WITH_IDEA_CBC_SHA = 0x0007,
	SSL_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0008,
	SSL_RSA_WITH_DES_CBC_SHA = 0x0009,
	SSL_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,
	SSL_DH_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x000B,
	SSL_DH_DSS_WITH_DES_CBC_SHA = 0x000C,
	SSL_DH_DSS_WITH_3DES_EDE_CBC_SHA = 0x000D,
	SSL_DH_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x000F,
	SSL_DH_RSA_WITH_DES_CBC_SHA = 0x0010,
	SSL_DH_RSA_WITH_3DES_EDE_CBC_SHA = 0x0011,
	SSL_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x0012,
	SSL_DHE_DSS_WITH_DES_CBC_SHA = 0x0013,
	SSL_DHE_DSS_WITH_3DES_EDE_CBC_SHA = 0x0014,
	SSL_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0015,
	SSL_DHE_RSA_WITH_DES_CBC_SHA = 0x0016,
	SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA = 0x0017,
	SSL_DH_anon_EXPORT_WITH_RC4_40_MD5 = 0x0018,
	SSL_DH_anon_WITH_RC4_128_MD5 = 0x0019,
	SSL_DH_anon_EXPORT_WITH_DES40_CBC_SHA = 0x001A,
	SSL_DH_anon_WITH_DES_CBC_SHA = 0x001B,
	SSL_DH_anon_WITH_3DES_EDE_CBC_SHA = 0x001C,
	SSL_FORTEZZA_KEA_WITH_NULL_SHA = 0x001D,
	SSL_FORTEZZA_KEA_WITH_FORTEZZA_CBC_SHA = 0x001E,
	SSL_FORTEZZA_KEA_WITH_RC4_128_SHA = 0x001F
};

template <Byte byte/* = unsigned char*/,
	typename peer_certificate_t,
	typename compression_method_t,
	typename cipher_spec_t>
struct SSL_session_state {
	byte session_identifier [32]; // Arbitrary byte sequence chosen by the server to identify an active or resumable session state (the maximum length is 32 bytes)
	peer_certificate_t peer_certificate; // X.509v3 certificate of the peer (if available)
	compression_method_t compression_method; // Data compression algorithm used (prior to encryption)
	cipher_spec_t cipher_spec; // Data encryption and MAC algorithms used (together with cryptographic parameters, such as the length of the hash values)
	byte master_secret [48]; // 48-byte secret that is shared between the client and the server
	bool is_resumable; // Flag indicating whether the SSL session is resumable, meaning that it can be used to initiate new connections
};

template <Byte byte/* = unsigned char*/,
	typename initialization_vectors_t,
	typename sequence_numbers_t>
struct SSL_connection_state {
	byte * server_and_client_random; // Byte sequences that are chosen by the server and client for each connection.
	byte * server_write_MAC_key; // Secret used in MAC operations on data written by the server
	byte * client_write_MAC_key; // Secret used in MAC operations on data written by the client.
	byte * server_write_key; // Key used for data encrypted by the server and decrypted by the client.
	byte * client_write_key; // Key used for data encrypted by the client and decrypted by the server
	initialization_vectors_t initialization_vectors; // If a block cipher in CBC mode is used for data encryption, then an IV must be maintained for each key. This field is first initialized by the SSL handshake protocol. Afterward, the final ciphertext block from each SSL record is preserved to serve as IV for the next record.
	sequence_numbers_t sequence_numbers; // SSL message authentication employs sequence numbers. This means that the client and server must maintain a sequence number for the messages that are transmitted or received on a particular connection. Each sequence number is 64 bits long and ranges from 0 to 2^64 − 1. It is set to zero whenever a CHANGECIPHERSPEC message is sent or received. Since it cannot wrap, a new connection must be negotiated when the number reaches 2^64 − 1.
};

enum SSL_protocol_type {
	change_cipher_spec = 0x14,
	alert = 0x15,
	handshake = 0x16,
	application_data = 0x17
};

template <Byte type_t = SSL_protocol_type,
	Bytes <2> version_t = unsigned short,
	Bytes <2> length_t = version_t>
struct SSL_record_header {
// 	constexpr SSL_header (type_t&& type, version_t&& version, length_t&& length) noexcept : type {(type_t&&) type}, version {(version_t&&) version}, length {(length_t&&) length}{

// 	}
// private:
	type_t type;
	version_t version; // 0x0300
	length_t length;
};

struct SSL_fragment {

};

// (1) Fragmentation
template <typename header_t,
	typename fragment_t>
struct SSL_plaintext {
	// the data structure that results after fragmentation is called SSLPlaintext
	constexpr SSL_plaintext (Char auto const * text) noexcept {

	}
	header_t header;
	fragment_t fragment;
};

// (2) Compression
template <typename header_t,
	typename fragment_t>
struct SSL_compressed {
	constexpr SSL_compressed (SSL_plaintext <header_t, fragment_t> && text) noexcept {

	}
};


// (3, 4) Message authentication, Encryption
template <typename header_t,
	typename fragment_t>
struct SSL_ciphertext {
	constexpr SSL_ciphertext (SSL_compressed <header_t, fragment_t> && text) noexcept {

	}
};

// (5) Prepend SSL Record Header
template <typename header_t,
	typename fragment_t>
struct SSL_record {
	// constexpr SSL_record (SSL_header&& header, SSL_ciphertext&& text) noexcept {

	// }
	header_t header;
	fragment_t fragment;
};


enum SSL_handshake_message_type {
	HelloRequest = 0x00,
	ClientHello = 0x01,
	ServerHello = 0x02,
	Certificate = 0x0B,
	ServerKeyExchange = 0x0C,
	CertificateRequest = 0x0D,
	ServerHelloDone = 0x0E,
	CertificateVerify = 0x0F,
	ClientKeyExchange = 0x10,
	Finished = 0x14
};

template <SSL_handshake_message_type>
struct SSL_handshake_message_body;

// template <typename record_header,
// 	SSL_handshake_message_type message_type,
// 	Number auto message_length>
// 	requires (Bytes <record_header, 5> and 
// 		Bytes <SSL_handshake_message_type, 1> and 
// 		Bytes <decltype (message_length), 3>)
// struct SSL_handshake_message {

// };

// template <typename record_header>
// struct SSL_handshake_message <SSL_handshake_message_type::ClientHello, record_header> {

// };



template <>
struct SSL_handshake_message_body <SSL_handshake_message_type::Certificate> {
	constexpr SSL_handshake_message_body () noexcept {
		
	}
};



