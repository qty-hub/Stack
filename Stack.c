#include <stdio.h>
#include <string.h>
#define MAX_STACK 3

typedef struct{
	int top;
	char data[3][3];
} STACK;

STACK tumpuk;

void inisialisasi(){
	tumpuk.top=-1;
}

int isFull(){
	if(tumpuk.top==MAX_STACK-1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(tumpuk.top==-1){
		return 1;
	}else{
		return 0;
	}
}

void push(char d[3]){
	tumpuk.top++;
	strcpy(tumpuk.data[tumpuk.top], d);
}

void pop(){
	printf("Data yang ingin diambil: %s\n", tumpuk.data[tumpuk.top]);
	tumpuk.top--;
}

void cetak(){
	int i, n=1;
	for(i=tumpuk.top; i>=0; i--){
		printf("Data ke-%d: %s\n", n, tumpuk.data[i]);
		n++;
	}
}

void hapus(){
	tumpuk.top=-1;
}

int main(){
	int pilihan;
	inisialisasi();
	char dt[3];
	do{
		system("cls");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Cetak isi array stack\n");
		printf("4. Hapus isi array stack\n");
		printf("5. Keluar\n");
		printf("Piihan: "); scanf("%s", pilihan);
		switch(pilihan){
			case 1: if(isFull()!=1){
					printf("Data yang ingin disimpan: "); scanf("%s", &dt);
					push(dt);
				}else{
					printf("Array stack penuh!");
				}getch(); break;
			case 2: if(isEmpty()!=1){
					pop();
				}else{
					printf("Array stack kosong!");
				}getch(); break;
			case 3: if(isEmpty()!=1){
					cetak();
				}else{
					printf("Array stack kosong!");
				}getch(); break;
			case 4: hapus(); printf("Array stack sudah dihapus!"); getch(); break;
		}
	}while(pilihan!=5);
	printf("Keluar dari program!");
}
