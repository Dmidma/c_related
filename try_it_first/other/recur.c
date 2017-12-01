#include <stdio.h>



void afficheRec(int i, char** string);

int main(void)
{
	char* string[4] = {"Dernier", "cours", "algo", "avanccee"};
	afficheRec(0, string);

}


void afficheRec(int i, char** string)
{
	if (i < 4)
	{
		afficheRec(i + 1, string);
		printf("%s\n", string[i]);
		afficheRec(i + 1, string);
	}
}

