#include <stdio.h>

//определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000

void process_line(char line[]);
int proverka( char *start, char *end);

int main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	return 0;
}

void process_line(char line[])
{
	char *line_ptr;//указатель на текущий символ
	char *start;//указатель на начало слова
	char *end;//указатель на конец слова
	char c;//текущий символ
	int flag = NO;
	int found = NO;

	//начальные присваивания
	line_ptr = line;
	start = line;
	end = line;

	//цикл чтения символов из строки
	do
	{
		c = *line_ptr;//взять текущий символ
		if (c == ' ' || c == '.' || c == ',' || c == '\n'||c=='\0')
		{
			if (flag == YES)//найден первый разделитель после слова
			{
				end = line_ptr - 1;
				if (proverka( start, end) == YES) //удаление слов палиндромов
				{
					char *src = end + 1;
					char *dst = start;
					while ((*dst++ = *src++) != '\0');
					line_ptr = start;//начать проверку с текущего слова
				}
			}
			flag = NO;
		}
		else
		{
			if (flag == NO)
			{
				start = line_ptr;//запомнить указатель на начало слова
				flag = YES;
			}
		}
		line_ptr++;//продвинуть указатель на текущий символ
	} 
	while (c != '\0');

}

int proverka( char *start, char *end)
{
	if (start == end)
		return NO;
	while(start < end)
	{
		if (*start != *end)
			return NO;
		start++;
		end--;
	}
	return YES;
}