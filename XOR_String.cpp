#include <iostream>

int XOR(char* data, int data_len, char* key, int key_len, char* charArray)
{
	int counter=0;
	
	for (int i = 0; i < data_len; i++) {
		charArray[i] = 0;
	}
	
	printf("\nOutput Type One: \n");
	for (int i = 0; i < data_len; i++) {
		if (i == data_len - 1) {
			charArray[i] += data[i];
			data[i] ^= key[i % key_len];
			printf("\\x%02X\" };", data[i]);
		}
		else if (i == 0) {
			charArray[i] += data[i];
			data[i] ^= key[i % key_len];
			printf("char output[] = { \"\\x%02X", data[i]);
		}
		else {
			charArray[i] += data[i];
			data[i] ^= key[i % key_len];
			printf("\\x%02X", data[i]);
		}
		counter++;
	}

	printf("\n\nOutput Type Two:\n");
	for (int i = 0; i < data_len; i++) {
		if (i == data_len - 1) {
			charArray[i] ^= key[i % key_len];
			printf("\"0x%02X\" };", charArray[i]);
		}
		else if (i == 0) {
			charArray[i] ^= key[i % key_len];
			printf("const char* output[] = { \"0x%02X\", ", charArray[i]);
		}
		else {
			charArray[i] ^= key[i % key_len];
			printf("\"0x%02X\", ", charArray[i]);
		}
	}

	printf("\n");
	return counter;
}

void XOR_Validate(char* data, int counter, char* key, int key_len) 
{
	unsigned char* charArray = new unsigned char[counter];

	for (int i = 0; i < counter; i++) {
		charArray[i] = 0;
	}
	printf("\n\nValidating by XORing back to original phrase...\n");
	for (int i = 0; i < counter; i++) {
		data[i] ^= key[i % strlen(key)];
		printf("%c", data[i]);
	}
	printf("\n");
}


void main()
{
	char inKey[1000];
	char inData[1000];
	char key[1000];
	char data[1000];
	char modified[1000];
	char charArray[1000];

	printf("Enter your XOR key: ");
	std::cin.getline(inKey,999);

	printf("Enter your word, phrase, etc: ");
	std::cin.getline(inData,999);

	for (int i = 0; i < sizeof(inKey)-1; i++) {
		key[i] = inKey[i];
	}
	for (int i = 0; i < sizeof(inData)-1; i++) {
		data[i] = inData[i];
	}
	
	int counter = XOR(data, strlen(data), key, strlen(key), charArray);
	XOR_Validate(charArray, counter, key, strlen(key));
}