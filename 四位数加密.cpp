#include <stdio.h>

int main(void) {
	int data, a, b, c, d, secert, origin;
	printf("请输入数据: ");
	scanf("%d", &data);

	//加密
	a = data / 1000;
	b = data % 1000 / 100;
	c = data % 100 / 10;
	d = data % 10;

	a = ( a + 7 ) % 10;
	b = ( b + 7 ) % 10;
	c = ( c + 7 ) % 10;
	d = ( d + 7 ) % 10;

	secert = c * 1000 + d * 100 + a * 10 + b ;
	printf("加密后是%d\n", secert);

	printf("\n解密ing\n");
	//解密
	a = secert / 1000;
	b = secert % 1000 / 100;
	c = secert % 100 / 10;
	d = secert % 10;

	if ( a > 6 )
		a = a - 7;
	else
		a = a + 10 - 7;

	if ( b > 6 )
		b = b - 7;
	else
		b = b + 10 - 7;

	if ( c > 6 )
		c = c - 7;
	else
		c = c + 10 - 7;

	if ( d > 6 )
		d = d - 7;
	else
		d = d + 10 - 7;

	origin = c * 1000 + d * 100 + a * 10 + b;
	printf("\n原码是: %d", origin);

	return 0 ;
}
