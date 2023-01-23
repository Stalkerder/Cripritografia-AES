#include <iostream>
using namespace std;

int main() {
    string plaintext = "Este é um texto de exemplo";
    string key = "minha_senha_secreta";

    string ciphertext = encryptAES(plaintext, key);
    cout << "Texto criptografado: " << ciphertext << endl;

    string decryptedtext = decryptAES(ciphertext, key);
    cout << "Texto descriptografado: " << decryptedtext << endl;

    return 0;
}


/*   Esse exemplo criptografa o texto "Este é um texto de exemplo" usando a chave "minha_senha_secreta" e,
em seguida, descriptografa o texto criptografado para mostrar o texto original. Certifique-se de incluir todas as bibliotecas necessárias
e configurar o ambiente de acordo com as instruções fornecidas antes de executar o código.