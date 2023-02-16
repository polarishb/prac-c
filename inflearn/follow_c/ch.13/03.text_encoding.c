#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    const char* default_cp_tmp = setlocale(LC_ALL, NULL);
    const char * default_cp = strdup(default_cp_tmp);
    printf("%s\n", default_cp);

	int ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";
	const char* out_filename = "사본.txt";

	unsigned long count = 0;

	if ((fr = fopen(in_filename, "r")) == NULL)
	{
		printf("Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL)
	{
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

    setlocale(LC_ALL, "en_US");

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);
		fputc(ch, fw);
		count++;
	}

	fclose(fr);
	fclose(fw);

    setlocale(LC_ALL, default_cp);

	printf("FILE %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인\n");

	return 0;
}