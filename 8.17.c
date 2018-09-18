#include <stdio.h>

//����������� ������������� ��������
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
	char *line_ptr;//��������� �� ������� ������
	char *start;//��������� �� ������ �����
	char *end;//��������� �� ����� �����
	char c;//������� ������
	int flag = NO;
	int found = NO;

	//��������� ������������
	line_ptr = line;
	start = line;
	end = line;

	//���� ������ �������� �� ������
	do
	{
		c = *line_ptr;//����� ������� ������
		if (c == ' ' || c == '.' || c == ',' || c == '\n'||c=='\0')
		{
			if (flag == YES)//������ ������ ����������� ����� �����
			{
				end = line_ptr - 1;
				if (proverka( start, end) == YES) //�������� ���� �����������
				{
					char *src = end + 1;
					char *dst = start;
					while ((*dst++ = *src++) != '\0');
					line_ptr = start;//������ �������� � �������� �����
				}
			}
			flag = NO;
		}
		else
		{
			if (flag == NO)
			{
				start = line_ptr;//��������� ��������� �� ������ �����
				flag = YES;
			}
		}
		line_ptr++;//���������� ��������� �� ������� ������
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