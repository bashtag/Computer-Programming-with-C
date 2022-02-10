#include<unistd.h>

void ft_print_comb(void);

int main() {

	ft_print_comb();

	return 0;
}

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_alphabet(void) {
	char letter = 'a';
	while(letter!='z'+1) {
		write(1, &letter ,1);
		letter--;
	}
}

void ft_print_reverse_alphabet(void) {
	char letter = 'z';
	while(letter!='a'-1) {
		write(1, &letter ,1);
		letter--;
	}
}

void ft_print_numbers(void) {
	char digit= '0';
	while(digit!='9'+1) {
		write(1, &digit ,1);
		digit++;
	}
}

void ft_is_negative(int n) {
	char result = 'N';
	if (n>=0) {
		result = 'P';
	}
	write(1,&result,1);
}

void ft_print_comb(void) {
	char num[3];
	num[0] = '0';
	while(num[0]<'9'+1) {
		num[1]=num[0]+1;
		while(num[1]<'9'+1) {
			num[2]=num[1]+1;
			while(num[2]<'9'+1) {
				write(1,num,3);
				write(1,", ",2);
				num[2]++;
			}
			num[1]++;
		}
		num[0]++;
	}
}

void ft_print_comb(void) {
	char num1[2] ="00";
	char num2[2] ="01";
}
