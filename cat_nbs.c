#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


void option_n(FILE *fp);
void option_b(FILE *fp);
void option_s(FILE *fp);
int opt_n = 0;
int opt_b = 0;
int opt_s = 0;
int opt;

void main(int argc, char *const argv[])
{
	void view_file(FILE *);
	void fatal(char *);
	FILE *fp;
	if (argc == 1)
	{
		puts("사용법 : a.out [-n] [-b] [-s] filename");
		exit(0);
	}


	while ((opt = getopt(argc, argv, "nbs")) != -1)
	{
		switch (opt)
		{
		case 'n':
			opt_n = 1;
			break;

		case 'b':
			opt_b = 1;
			break;

		case 's':
			opt_s = 1;
			break;
		default:
			printf("알 수 없는 옵션 : %c\n", opt);
		}
	}

	if (argc != 2)
		*argv++;

	while (*(++argv))
	{
		// argv 출력 >> 인자로 받은 파일이름이 *argv 이다
		printf("%s\n", *argv);
		// 파일 오픈 실패
		if ((fp = fopen(*argv, "r")) == NULL)
		{
			fatal("fopen");
		}
		// 파일 읽기 성공이면 실행
		if (opt_n == 1)
			option_n(fp);
		if (opt_b == 1)
			option_b(fp);
		if (opt_s == 1)
			option_s(fp);

		view_file(fp);
		fclose(fp);
	}
	exit(0);
}

void view_file(FILE *fp) 
{
	int	c;
	while ((c = getc(fp)) != EOF)
		putc(c, stdout);
}
void fatal(char *error_name) 
{
	perror(error_name);
	exit(1);
}


// option_n 은 라인 맨 앞에 라인 번호 출력한다.
void option_n(FILE *fp)
{
	int ch = 0;
	int line = 1;
	if (opt_n)
		printf("%6d  ", 1);

	while ((ch = getc(fp)) != EOF)
	{
		// 옵션이 지정되고, ch가 공백이면 실행
		if (opt_n && ch == '\n')
		{
			// ch가 EOF면 멈춘다
			if ((ch = getc(fp)) == EOF)
				break;
			// if문에서 getc한 문자 1개 다시 버퍼안에 넣는다
			ungetc(ch, fp);
			printf("\n%6d  ", ++line);
		}
		else
			putc(ch, stdout);
	}
	printf("\n");
	exit(0);
}

// option_b 는 공백인 라인은 번호 붙이지 않는다.
void option_b(FILE *fp)
{
	int ch = 0;
	int line = 1;
	if (option_b)
		printf("%6d  ", 1);

	// 파일에서 1문자 읽고 ch에 저장, ch != EOF인 동안 실행
	while ((ch = getc(fp)) != EOF)
	{
		// 옵션이 지정되고, ch가 공백이면 실행
		if (option_b && ch == '\n')
		{
			// ch가 EOF면 멈춘다
			if ((ch = getc(fp)) == EOF)
				break;
			// if문에서 getc한 문자 1개 다시 버퍼안에 넣는다
			ungetc(ch, fp);

			// 만약 ch 가 개행이면 번호를 붙이지 않는다
			if (ch == '\n')
				printf("\n");
			// \n 과 라인 수 출력한다
			else
				printf("\n%6d  ", ++line);
		}

		// ch 가 공백이 아니거나, 옵션이 지정되지 않으면 그냥 문자 쭉 출력
		else
			putc(ch, stdout);
	}
	printf("\n");
	exit(0);
}

// option_s 는 개행여러개를 1개로 처리해야한다.
void option_s(FILE *fp)
{
	int ch = 0;

	// 파일에서 1문자 읽고 ch에 저장, ch != EOF인 동안 실행
	while ((ch = getc(fp)) != EOF)
	{
		// 옵션이 지정되고, ch가 개행이면 실행.. 현재 ch는 \n
		if (option_s && ch == '\n')
		{
			// 다음 ch가 EOF면 멈춘다
			if ((ch = getc(fp)) == EOF)
				break;
			// if문에서 getc한 문자 1개 다시 버퍼안에 넣는다
			ungetc(ch, fp);

			// 만약 다음  ch 가 또 개행이면, 개행이 아닐때까지 읽는다
			if ((ch = getc(fp)) == '\n')
			{
				printf("\n");
				ungetc(ch, fp);
				while (ch == '\n')
				{
					ch = getc(fp);
				}
				// 버퍼에서 1개 살린다
			}
			printf("\n");
			putc(ch, stdout);
		}
		else
			putc(ch, stdout);
	}
	printf("\n");
	exit(0);
}


