#define BENCH_EMBEDDED
#define USE_CERT_BUFFERS_2048
#define HAVE_HKDF
#define WOLFSSL_SHA512
#define HAVE_ECC
#define ECC_TIMING_RESISTANT
#define HAVE_CURVE25519
#define CURVE25519_SMALL
#define WOLFCRYPT_HAVE_SRP
#define HAVE_CHACHA
#define HAVE_POLY1305
#define HAVE_ED25519
#define ED25519_SMALL
#define HAVE_ONE_TIME_AUTH
#define WC_NO_HARDEN

#include <esp_system.h>

static inline int hwrand_generate_block(uint8_t *buf, size_t len) {
    int i;
    for (i=0; i+4 < len; i+=4) {
        *((uint32_t*)buf) = esp_random();
        buf += 4;
    }
    if (i < len) {
        uint32_t r = esp_random();
        while (i < len) {
            *buf++ = r;
            r >>= 8;
            i++;
        }
    }

    return 0;
}
#define CUSTOM_RAND_GENERATE_BLOCK hwrand_generate_block