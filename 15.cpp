#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(int key, char *ciphertext);

int main(){
	int i,key;
	char imsi[100];
	char **plaintext;

	plaintext = (char **)malloc(sizeof(char*)*3);
	printf("3개의 평문을 영어 소문자로 입력해주세요.(100글자 이내)\n");
	for(i=0;i<3;i++){
		scanf("%s",imsi);
		plaintext[i]=(char *)malloc(sizeof(char)*strlen(imsi)+1);
		strcpy(plaintext[i],imsi);
	}
	printf("\n문자열 암호화에 사용할 key를 입력하세요. :");
	scanf("%d",&key);

	printf("\n입력된 문자열을 암호문으로 변경합니다.\n");
	for(i=0;i<3;i++)
		encrypt(key,plaintext[i]);

	for(i=0;i<3;i++)
		printf("%s\n",plaintext[i]);		

}
void encrypt(int key, char *ciphertext){
	int i;

	for(i=0;ciphertext[i];i++){
		if(ciphertext[i]>='A' && ciphertext[i]<='Z'){
			ciphertext[i]+=key;
			if(ciphertext[i]>'Z')
				ciphertext-=26;
		}
		else if(ciphertext[i]>='a' && ciphertext[i]<='z'){
			ciphertext[i]+=key;
			if(ciphertext[i]>'z')
				ciphertext[i]-=26;
		}
	}
}

