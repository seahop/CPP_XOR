#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int XOR(char* data, int data_len, char* key, int key_len, char* charArray)
{
	int counter=0;
	for (int i = 0; i < data_len; i++) {
		charArray[i] = 0;
	}
	printf("\n");
	for (int i = 0; i < data_len; i++) {
		if (i == data_len-1) {
			data[i] ^= key[i % key_len];
			charArray[i] += data[i];
			printf("\\x%x\" };", charArray[i]);
		}
		else if (i == 0) {
			data[i] ^= key[i % key_len];
			charArray[i] += data[i];
			printf("char output[] = { \"\\x%x", charArray[i]);
		}
		else {
			data[i] ^= key[i % key_len];
			charArray[i] += data[i];
			printf("\\x%x", charArray[i]);
		}
		counter++;
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
		//charArray[i] += output[i];
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
	cin.getline(inKey,999);

	printf("Enter your word, phrase, etc: ");
	cin.getline(inData,999);

	for (int i = 0; i < sizeof(inKey)-1; i++) {
		key[i] = inKey[i];
	}
	for (int i = 0; i < sizeof(inData)-1; i++) {
		data[i] = inData[i];
	}
	
	int counter = XOR(data, strlen(data), key, strlen(key), charArray);
	XOR_Validate(charArray, counter, key, strlen(key));
}