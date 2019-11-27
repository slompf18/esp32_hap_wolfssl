# ESP32 HAP WolfSSL
A wolfssl clone specifically for esp32_hap project.

# How to update
1. Clone Wolfssl: git clone https://github.com/wolfSSL/wolfssl.git $IDF_PATH/wolfssl
1. Install to esp-idf: $IDF_PATH/wolfssl/IDE/Espressif/ESP-IDF/setup.sh
1. Uncomment follwing defines from $IDF_PATH/components/wolfssl/wolfssl/wolfcrypt/settings.h
    - #define WOLFSSL_ESPIDF
    - #define WOLFSSL_ESPWROOM32
1. Restore user_settings.h