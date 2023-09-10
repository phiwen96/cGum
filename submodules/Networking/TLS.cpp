export module cGum.Networking.TLS;

export struct TLSParameters {

};

export int tls_connect (int connection, TLSParameters* parameters) {

}

export int tls_send (int connection, char const* application_data, int length, int options, TLSParameters* parameters) {

}

export int tls_recv (int connection, char * target_buffer, int buffer_size, int options, TLSParameters* parameters) {

}

export int tls_shutdown (int connection, TLSParameters* parameters) {
	
}