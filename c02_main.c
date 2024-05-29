/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:05:11 by bworrawa          #+#    #+#             */
/*   Updated: 2024/05/29 18:16:46 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest,char *src);
char	*ft_strncpy(char *dest,char *src, unsigned long n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char    *ft_strcapitalize(char *str);
unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);

void	test_00(){
	char	dest[100];
	char	source[100] = "Hello Me!";
	char	*temp;

	dest[0] = '\0';
	printf("==================\ntest 00: ft_strcpy\n==================\n\n");
	printf(" source: $%s$\n dest : $%s$\n\n", source , dest);

	printf("====\n");
	// temp = strcpy(dest , source);
	// printf(" CONTROL source : $%s$ , dest = $%s$\n\n", source , dest);
	
	// printf(" source len = %lu, dest len = %lu\n", strlen(source) , strlen(dest));
	// printf(" temp = $%s$, temp length = %lu\n\n" , temp , strlen(temp));

	// strcpy(dest , "XXX");
	// strcpy(temp , "YYY");

	ft_strcpy(dest , source);
	printf("=====\nTEST ft_strcpy()\n=====\n source = $%s$\n dest = $%s$, length = %lu\n" , source , dest , strlen(dest));
	printf(" dest = $%s$, dest length = %lu\n\n", dest , strlen(dest));
	// printf(" temp = $%s$, temp length = %lu\n\n", temp , strlen(temp));
}

void	test_01()
{
	
	char	dest[10];
	char	*source = "Hello Me!";
	unsigned int	len = 5;

	dest[0] = '\0';
	printf("==================\ntest 01: ft_strncopy\n==================\n\n");
	printf("PARAMS\n");
	printf(" source: $%s$\n dest : $%s$\n len : $%u$ \n\n", source , dest , len);

	// temp = strncpy(dest , source , len);
	// printf("CONTROL\n=====\nsource : $%s$ , dest = $%s$ , len=%lu\n\n", source , dest, len);	
	// printf(" source len = %lu, dest len = %lu\n", strlen(source) , strlen(dest));
	// printf(" temp = $%s$, temp length = %lu\n\n" , temp , strlen(temp));

	strcpy(dest , "XXX");
//	strcpy(temp , "YYY");

	ft_strncpy(dest , source , len);
	printf("=====\nTEST\n=====\nft_strncpy()\nsource = $%s$\ndest = $%s$\nlength = %lu\n" , source , dest , strlen(dest));
	// printf(" temp (return value) = $%s$, temp length = %lu\n\n", temp , strlen(temp));
}


void	test_02()
{
	char	*str1 = "ThisIsAllAlphaNumeric123";
	char	*str2 = "ThisIsAllAlphaNumeric123 with some space";
	char	*str3 = "æøåöä";
	char	*str4 = "";
	

	printf("==================\ntest 02: ft_str_is_alpha\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str1, 1 , ft_str_is_alpha(str1));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str2, 0 , ft_str_is_alpha(str2));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str3, 0 , ft_str_is_alpha(str3));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str4, 1 , ft_str_is_alpha(str4));	

}


void 	test_03()
{
	char	*str1 = "ThisIsNOTNumeric123";
	char	*str2 = "1200976";
	char	*str3 = "-5";
	char	*str4 = "0.987761";
	char 	*str5 = "";
	char	*str6 = ".9";
	

	printf("==================\ntest 03: ft_str_is_numeric\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str1, 0 , ft_str_is_numeric(str1));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str2, 1 , ft_str_is_numeric(str2));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str3, 0 , ft_str_is_numeric(str3));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str4, 0 , ft_str_is_numeric(str4));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str5, 1 , ft_str_is_numeric(str5));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str6, 0 , ft_str_is_numeric(str6));	
	
	
}


void test_04()
{
	char	*str1 = "ThisIsNOTLowercase";
	char	*str2 = "1200976";
	char	*str3 = "thisislowecase";
	char	*str4 = "lowercase but with spaces";
	char 	*str5 = "lowercase,withsymbols";
	char	*str6 = "";
	

	printf("==================\ntest 04: ft_str_is_lowercase\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str1, 0 , ft_str_is_lowercase(str1));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str2, 0 , ft_str_is_lowercase(str2));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str3, 1 , ft_str_is_lowercase(str3));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str4, 0 , ft_str_is_lowercase(str4));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str5, 0 , ft_str_is_lowercase(str5));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str6, 1 , ft_str_is_lowercase(str6));	
	
}

void test_05()
{
	char	*str1 = "ThisIsNOTUppercase";
	char	*str2 = "1200976";
	char	*str3 = "THISISUPPERCASE";
	char	*str4 = "lowercasenospaces";
	char 	*str5 = "THIS IS UPPERCASE WITH SPACES";
	char	*str6 = "UPPERCASE,SYMBOLS";
	char	*str7 = "";

	printf("==================\ntest 05: ft_str_is_uppercase()\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str1, 0 , ft_str_is_uppercase(str1));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str2, 0 , ft_str_is_uppercase(str2));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str3, 1 , ft_str_is_uppercase(str3));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str4, 0 , ft_str_is_uppercase(str4));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str5, 0 , ft_str_is_uppercase(str5));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str6, 0 , ft_str_is_uppercase(str6));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str7, 1 , ft_str_is_uppercase(str7));	
	
}


void test_06()
{
	char	*str1 = "ThisIsNOTUppercase,but all printable";
	char	*str2 = "1200976";
	char	*str3 = "THISISUPPERCASE\nWITHNEWLINE";
	char	*str4 = "lowercasenospaces";
	char 	*str5 = "THIS IS UPPERCASE WITH SPACES";
	char	*str6 = "UPPERCASE,SYMBOLS";
	char	*str7 = "";

	

	printf("==================\ntest 06: ft_str_is_printable\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str1, 0 , ft_str_is_printable(str1));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str2, 1 , ft_str_is_printable(str2));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str3, 0 , ft_str_is_printable(str3));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str4, 1 , ft_str_is_printable(str4));
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str5, 0 , ft_str_is_printable(str5));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str6, 1 , ft_str_is_printable(str6));	
	printf(" INPUT: $%s$\nexpected output %d\nactual output %d\n\n", str7, 1 , ft_str_is_printable(str7));	
	
}

void test_07()
{
	char	str1[50] = "This is not the Uppercase letters,but SHOULD BE";
	char	str2[50] = "1200976";
	char	str3[50] = "THIS LINE IS ALREADY UPPERCASE";
	char	str4[50] = "allthecharislowercasenospaces";
	char 	str5[50] = "What the hell is going on";
	char	str6[50] = "Booyah!";
	char	str7[50] = "";	


	char 	temp[255];

	strcpy( temp, str1);
	printf("==================\ntest 07: ft_strupcase\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$", str1);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str1));
	printf(" INPUT: $%s$", str2);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str2));
	printf(" INPUT: $%s$", str3);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str3));
	printf(" INPUT: $%s$", str4);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str4));
	printf(" INPUT: $%s$", str5);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str5));
	printf(" INPUT: $%s$", str6);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str6));
	printf(" INPUT: $%s$", str7);
	printf("\n expected output to be all Uppercase, output = $%s$\n", ft_strupcase(str7));
	
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str2, ft_strupcase(str2));
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str3, ft_strupcase(str3));
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str4, ft_strupcase(str4));
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str5, ft_strupcase(str5));
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str6, ft_strupcase(str6));
	// printf(" INPUT: _%s_, expected output to be all Uppercase, actual output _%s_\n", str7, ft_strupcase(str7));
							
}

void test_08()
{
	char	str1[50] = "This is not the lower case letters,but SHOULD BE";
	char	str2[50] = "1200976";
	char	str3[50] = "THIS LINE IS ALREADY UPPERCASE";
	char	str4[50] = "allthecharislowercasenospaces";
	char 	str5[50] = "What the hell is going on";
	char	str6[50] = "Booyah!";
	char	str7[50] = "";	


	char 	temp[255];

	strcpy( temp, str1);

	printf("==================\ntest 08: ft_strlowcase\n==================\n\n");
	printf("PARAMS\n");

	printf(" INPUT: $%s$", str1);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str1));
	printf(" INPUT: $%s$", str2);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str2));
	printf(" INPUT: $%s$", str3);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str3));
	printf(" INPUT: $%s$", str4);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str4));
	printf(" INPUT: $%s$", str5);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str5));
	printf(" INPUT: $%s$", str6);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n", ft_strlowcase(str6));
	printf(" INPUT: $%s$", str7);
	printf("\n expected output to be all Lowercase, output = $%s$\n\n\n", ft_strlowcase(str7));
								
}

void test_09(){
	
	char input[255] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char output[255] =  "Salut, Comment tu vas ? 42mots Quarante-deux; Cinquante+Et+Un";

	char*temp;

	printf("==================\ntest 09: ft_strcapitalize\n==================\n\n");
	printf("input: $%s$\nexpected output : $%s$\n\n", input , output);
	// printf(" strcasecmp() case insensitive comparison result: %d\n\n" , strcasecmp(input, output));

	temp = ft_strcapitalize(input);
	printf(" returned value from ft_strcapitalize(): $%s$", temp);
	printf("\nstrcmp() comparison result: %d\n\n" , strcmp(input, temp));

}


void test_10()
{
	char 	source[255] = "01234567890123456789X";
	//char 	source[255] = "012";
	char	dest[10] = "destinatn";
	unsigned	int	size;
	unsigned int	out;
	
	printf("==================\ntest 10: ft_strlcpy()\n==================\n\n");

	size = 5;
	printf("TEST#1\n");
	printf(" source: $%s$\n dest : $%s$\n\n", source , dest);
	printf(" ft_strlcpy()\n");
	out = ft_strlcpy(dest , source , size);
	printf(" source : $%s$\n", source);
	printf(" dest : $%s$\n", dest);
	printf(" size (as params) : %u\n", size);
	printf(" source length (calc) :  %lu should be same as\n" , strlen(source));
	printf(" returned value (out) :  %u\n\n" , out);

	size = 8;
	printf("TEST#2\n");
	printf(" source: %s\n dest : %s\n\n", source , dest);
	printf(" ft_strlcpy()\n");
	out = ft_strlcpy(dest , source , size);
	printf(" source : $%s$\n", source);
	printf(" dest : $%s$\n", dest);
	printf(" size (as params) : %u\n", size);
	printf(" source length (calc) :  %lu should be same as\n" , strlen(source));
	printf(" returned value (out) :  %u\n\n" , out);
	
	size = 0;
	printf("TEST#3\n");
	printf(" source: %s\n dest : %s\n\n", source , dest);
	printf(" ft_strlcpy()\n");
	out = ft_strlcpy(dest , source , size);
	printf(" source : $%s$\n", source);
	printf(" dest : $%s$ - could be whatever since it ignored the copy process\n", dest);
	printf(" size (as params) : %u\n", size);
	printf(" source length (calc) :  %lu should be same as\n" , strlen(source));
	printf(" returned value (out) :  %u\n\n" , out);
	
}

void test_11()
{
	char	*input = "Coucou\ntu vas bien ?";
	char	*input2 = "This one contains tab\t,new line\n";
	
	printf("==================\ntest 11: ft_putstr_non_printable\n==================\n\n");

	printf("source :$%s$\n\n", input);
	ft_putstr_non_printable(input);
	printf("\n\n");

	printf("source :$%s$\n\n: ", input2);
	ft_putstr_non_printable(input2);
	printf("\n\n");
}

void	test_X()
{
	char	dest[] = "                                   ";
	char	*src;
	int		size;

	size = 5;
	src = "Bonjour les chacaux";
//	printf(".%s.\n\n", ft_strncpy(dest, src, size));
	printf(".%s.\n\n", strncpy(dest, src, size));

}
int	main(int argc, char **argv)
{
	// test_00();
	// test_01();
	// test_02();
	// test_03();
	// printf(" STILL FAILLLLL!\n\n");
	// test_04();
	// test_05();
	// test_06();
	// test_07();

	int	test_option = 0;
	if (argc > 1)
	{
		test_option = atoi(argv[1]);	
		// printf("argv[0] %s\n", argv[1]);
	}

	

	switch( test_option )
	{
		case 0	:   test_00();
						break;	
		case 1	:   test_01();
					//test_X();
						break;
		case 2	:   test_02();
						break;
		case 3	:   test_03();
						break;
		case 4	:   test_04();
						break;
		case 5	:   test_05();
						break;
		case 6	:   test_06();
						break;
		case 7	:   test_07();
						break;
		case 8	:   test_08();
						break;
		case 9	:   test_09();
							break;
		case 10	:   test_10();
			 			break;
		case 11	:   test_11();
						break;
			// case 'C'	:   test_00();
			// 				break;
	}
	
	
	// test_08();
	return (1);
}



// cc main.c ./ex00/ft_strcpy.c ./ex01/ft_strncpy.c ./ex02/ft_str_is_alpha.c ./ex03/ft_str_is_numeric.c ./ex04/ft_str_is_lowercase.c ./ex05/ft_str_is_uppercase.c ./ex06/ft_str_is_printable.c ./ex07/ft_strupcase.c ./ex08/ft_strlowcase.c 	temp = ft_strcapitalize(ioput);
