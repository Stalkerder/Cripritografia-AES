#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

using namespace std;

string encryptAES(string plaintext, string key) {
    // Vetor de inicialização (IV)
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Inicializando o contexto AES
    AES_KEY aesKey;
    AES_set_encrypt_key((unsigned char *)key.c_str(), key.length() * 8, &aesKey);

    // Alocando memória para o texto criptografado
    int ciphertext_len = plaintext.length() + AES_BLOCK_SIZE;
    unsigned char *ciphertext = new unsigned char[ciphertext_len];

    // Criptografando o texto
    AES_cbc_encrypt((unsigned char*)plaintext.c_str(), ciphertext, plaintext.length(), &aesKey, iv, AES_ENCRYPT);

    // Concatenando o IV ao texto criptografado
    string result = string((char *)iv, AES_BLOCK_SIZE) + string((char *)ciphertext, ciphertext_len);

    // Liberando a memória alocada
    delete[] ciphertext;

    return result;
}

string decryptAES(string ciphertext, string key) {
    // Extraindo o IV do texto criptografado
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, ciphertext.c_str(), AES_BLOCK_SIZE);

    // Inicializando o contexto AES
    AES_KEY aesKey;
    AES_set_decrypt_key((unsigned char *)key.c_str(), key.length() * 8, &aesKey);

    // Alocando memória para o texto descriptografado
    int plaintext_len = ciphertext.length() - AES_BLOCK_SIZE;
    unsigned char *plaintext = new unsigned char[plaintext_len];

    // Descriptografando o texto
    AES_cbc_encrypt((unsigned char*)ciphertext.c_str() + AES_BLOCK_SIZE, plaintext, plaintext_len, &aesKey, iv, AES_DECRYPT);

    // Convertendo o texto descriptografado para string
    string result(reinterpret_cast<char*>(plaintext), plaintext_len);

    // Liberando a memória alocada
    delete[] plaintext;

    return result;
}