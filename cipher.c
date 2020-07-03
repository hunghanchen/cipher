/* 
 Title:  Encrypted & Decrypted
 Author: Hung Han Chen
 Student ID: 9915311000
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encipher(char message[], char key[]);
void decipher(char encrypted[], char key[]);
int isInputAlpha(char input[]);

int main()
{
	//User input
	char message[100];
	char key[100];

	int x = 0;
	int failCount = 0;

	//If user input non-alpha character give one more change only
	//after one change will exit program
	do
	{
		if (failCount == 2)
		{
			printf("Exit the program\ns");
			exit(0);
		}
		printf("Enter a message and keyword (letter values only): ");
		scanf("%s %s", message, key);
		failCount++;

	} while (isInputAlpha(message) == 0 || isInputAlpha(key) == 0);

	//Make lower case only need to foucs on message lenght
	while (message[x])
	{
		message[x] = tolower(message[x]);
		key[x] = tolower(key[x]);
		x++;
	};

	encipher(message, key);
	return 0;
}

void encipher(char message[], char key[])
{

	int offset = 97;
	char encrypted[100];
	int x = 0;
	int y = 0;

	while (message[x])
	{
		if (!key[y]) //if key iterate till end of key reset start from y 0
		{
			y = 0;
		}
		key[x] = key[y];

		//Encrypt message. fomula: c = (m + k) % 26
		encrypted[x] = (((message[x] - offset) + (key[y] - offset)) % 26) + offset;

		x++;
		y++;
	}

	//need to put nul indicate its end
	encrypted[x] = '\0';
	key[x] = '\0';
	printf("\n***** Encipher *****\n");
	printf("message: %s\n", message);
	printf("key:     %s\n", key);
	printf("enc:     %s\n", encrypted);
	decipher(encrypted, key);
}

void decipher(char encrypted[], char key[])
{
	int offset = 97;
	char decrypted[100];
	int x = 0;

	//When encrypted character ascii greater equal than key character ascii
	//only need to encrypted character minus key character
	//when encrypted character ascii smaller than key character ascii
	//encrypted character plus 26 minus key character
	while (encrypted[x])
	{
		if (encrypted[x] >= key[x])
		{
			decrypted[x] = encrypted[x] - key[x] + offset;
		}
		else
		{
			decrypted[x] = encrypted[x] + 26 - key[x] + offset;
		}
		x++;
	}

	decrypted[x] = '\0';
	printf("\n***** Decipher *****\n");
	printf("enc:     %s\n", encrypted);
	printf("key:     %s\n", key);
	printf("message: %s\n", decrypted);
}

//check input is alpha or not
//if no return 0 yes return 1
int isInputAlpha(char input[])
{
	int x = 0;
	while (input[x])
	{
		if (isalpha(input[x]) == 0)
		{
			return 0;
		}
		x++;
	}
	return 1;
}


int main()
{
    int x[] = {42, 70, 132};
    left(&x);
    return 0;
}

void left(int *ptr)
{
    for (int i = 0; i < 3; i++)
    {

        *++ptr = ptr;
        print("%d\n",*(&ptr));
    }
}