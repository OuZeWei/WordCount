#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int CharacterCount(char* file)//字符计算
{
	FILE *fp = fopen(file, "r");
	char ch;
	int count = 0;
	while (EOF != (ch = fgetc(fp)))
	{
			count = count + 1;
	}
	fclose(fp);
	return count;
}
int WordCount(char* file)//单词计算
{
	FILE *fp = fopen(file, "r");
	char word;
	int is_word=0;
	int count = 0;
	while (EOF != (word = fgetc(fp)))
	{
		if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z'))//判断是否处于单词中
		{
			if (is_word == 0)
			{
				count = count + 1;
				is_word = 1;
			}
			
		}
		else
		{
			
			is_word = 0;
		}
	}
	fclose(fp);
	return count;
}
void Run(char Type, char* file)
{
	switch (Type)
	{
	case 'c':printf("character count: %d\n", CharacterCount(file));
		break;
	case 'w':printf("word count:%d\n", WordCount(file));
		break;
	default:printf("error");
		break;
	}
}
int main(int argc, char* argv[])
{
	char Type;
	Type = (char)malloc(sizeof(char));
	char* file;
	file = (char*)malloc(sizeof(char));

	for (int i = 0; i < argc; i++)
	{
		if (i == 1)
			Type =* argv[1];
		if (i ==2)
			file = argv[2];
		
	}
	Run(Type, file);
	
	return 0;

}
	
