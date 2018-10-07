#include<stdio.h> 
#define YES 1 
#define NO 0 

void del (char bufer[]);

int main(void)
{
	char line[1000];
	FILE *filein, *fileout;
	char *ptr;


	if ((filein = fopen("input.txt", "rt")) == NULL) 
		return 1;
	if ((fileout = fopen("result.txt", "wt")) == NULL) 
		return 1;

	while (!feof(filein))
	{
		ptr = fgets(line, 100, filein);
		if (ptr == NULL) break;

		// удаление самого длинного слова 
		del(line);

		fputs(line, fileout);

	}

	fclose(filein);
	fclose(fileout);

	return 0;
}

void del (char line[])
{
	char *line_ptr;//указатель на адрес обрабатываемого элемента строки 
	char *start_ptr;//указатель на адрес элемента начала слова 
	char *stop_ptr;//указатель на адрес элемента конца слова 
	int flag;
	char *beginmax_ptr;//указатель на адрес элемента начала самого длинного слова 
	char *endmax_ptr;//указатель на адрес элемента конца самого длинного слова 
	int max;//Разность указателей начала самого длинного слова и конца самого длинного слова 


	start_ptr = stop_ptr = line_ptr = beginmax_ptr = endmax_ptr = line;
	max = 0;
	flag = NO;


	do
	{
		//если втречен разделитель 
		if (((*line_ptr < 'a') || (*line_ptr >'z')) && ((*line_ptr < 'A') || (*line_ptr > 'Z')))
		{
			if (flag == YES)
			{
				stop_ptr = line_ptr - 1;
				if (max < (stop_ptr - start_ptr + 1))
				{
					max = (stop_ptr - start_ptr + 1);
					beginmax_ptr = start_ptr;
					endmax_ptr = stop_ptr;
				}

				flag = NO;
			}
		}
		else
		{
			if (flag == NO)
			{
				start_ptr = line_ptr;
				flag = YES;
			}
		}


		line_ptr++;
	} while (*line_ptr != '\0');


	//удалить самое длинное слово 

	endmax_ptr += 1;

	for (; *beginmax_ptr != '\0'; beginmax_ptr++)
	{
		*beginmax_ptr = *endmax_ptr;
		endmax_ptr++;
	}
	*endmax_ptr = '\0';

}