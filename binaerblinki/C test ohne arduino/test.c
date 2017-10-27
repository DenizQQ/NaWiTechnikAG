#include <stdio.h>
 


char wort[] = "AB";


int* toBinaer(char chr) {
	static int bArr[sizeof(wort)/ sizeof(wort[0])];

	for(int i = 0; i < 8; i++) {
		bArr[i] = !!((chr << i) & 0x80);
	}

	return bArr;
  
}


 
int main(void) {
	for(int x = 0; x < sizeof(wort)/sizeof(wort[0]); x++) {
		int *p = toBinaer(wort[x]);
		for(int i = 0; i < 8; i++) {
			printf("%d\n", *(p + i));
		}
	}

    return 0;
}
