#include <stdarg.h>
#include "./libft/libft.h"
#define FLAG_ALT   0b00000001
#define FLAG_BLANK 0b00000010
#define FLAG_SIGN  0b00000100

int ft_printf(const char *, ...);

char * ft_utoax(unsigned int n);
char * ft_utoa(unsigned int n);
int	voidpspec(va_list ap);
int	print_in_hex(char *p, short sz);
int	bigxspecifier(va_list ap, unsigned short flags);
int	hexspecifier(va_list ap, unsigned short flags);
int	print_hx(unsigned char c, int first);
int	strspecifier(va_list	ap);
int	uspecifier(va_list ap);
int	dispecifier(va_list	ap, unsigned short flags);
