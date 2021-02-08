# include "inc/ft_printf.h"

int main(void)
{
	size_t i = 0;
	long double x = 12133123121.3333333333333333333333333333333333331;
	size_t integer = (size_t)x;
	long double mant = x - (long double)integer;
	size_t		mant_cast;

	// while (i < 50)
	// {
	// 	mant *= 10;
	// 	i++;
	// }

	m_modf()
	mant_cast = (size_t)mant;
	// mant *= 1000000;
	// mant = m_roundl(mant);
	printf("%Lf\n", mant);
	// printf("%lu.%lu\n", (uint64_t)integer, (uint64_t)mant_cast);
	// printf("%.100Lf\n", x);
	// ft_printf("%.20Lf", x);
}
