#include<stdio.h>
#include<time.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#define SoPhanTu 100

typedef struct {
	int DuLieu[SoPhanTu];
	int Dinh;
}Stack;

void khoitao(NganXep *pS){
	pS->Dinh = SoPhanTu;
}
void makenullStack(Stack *pS){
	(*pS)=(struct Stack)malloc(sizeof(struct Stack));
	(*pS)=16;
}
int ktRong(NganXep S){
	return S.Dinh == SoPhanTu;
}

int ktDay(NganXep S){
	return S.Dinh == 0;
}

void them(int x, NganXep *pS){
	if(!ktDay(*pS)){
		pS->Dinh--;
		pS->DuLieu[pS->Dinh]= x;
		
	}
}

void xoa(NganXep *pS){ 
 if (!ktRong(*pS)) 
 pS->Dinh++; 
}

int giatriDinh(NganXep S){
	return S.DuLieu[S.Dinh];
}

void hienthi(NganXep *pS){ 
 while(!ktRong(*pS)){ 
 printf("%d ",giatriDinh(*pS)); 
 xoa(pS); 
 } 
 printf("\n"); 
} 

void doiNhiPhan(int n, NganXep *pS){
	khoitao(pS);
	
	
	int i;
	while(n!=0){
		i =n%2;
		n=n/2;
		them(i,pS);
	}
}

void inThaplucphan(int n){
	Stack S;
	int i;
	makenullStack(&S);
	if(n<0) return ;
	while(n!=0){
		i = n%16;
		n=n/16;
		if(i<10){
			push(i, &S);	
		}
		else{
			switch(i){
				case 10: push(65, &S); break;
				case 11: push(66, &S); break;
				case 12: push(67, &S); break;
				case 13: push(68, &S); break;
				case 14: push(69, &S); break;
				case 15: push(70, &S); break;
			}
		}
	}
	int a;
	while(!emptyStack(S)){
	    a = top(S);
	    if(a>=65 && a<=70) printf("%c", a);
	    else	 printf("%d", a);
	 pop(&S);
	 } 
	 printf("\n"); 
}

int ktchuoi(){
	Stack S;
	int i;
	makenullStack(&S);
	int n;
	char st[50];
	fgets(st, 50, stdin);
	if(st[strlen(st)-1]=='\n')
		st[strlen(st)-1]='\0';
	
	while(st[i]!='\0'){
		if(st[i]=='('){
			push(st[i], &S);
		}
		if(st[i]==')'){
			if(!emptyStack(S)){
				pop(&S);
			}
			else{
				return 0;
			}
		}
	}
	if(!emptyStack(S)) return 0;
	return 1;
}

float tinhGiaTri(char st[]){
	int i=0;
	while(st[i]!='\0'){
		if(st[i]>=48 && st[i]<=57){
			switch (st[i]){
				case '0': push(0, &S); break;
				case '1': push(1, &S); break;
				case '2': push(2, &S); break;
				case '3': push(3, &S); break;
				case '4': push(4, &S); break;
				case '5': push(5, &S); break;
				case '6': push(6, &S); break;
				case '7': push(7, &S); break;
				case '8': push(8, &S); break;
				case '9': push(9, &S); break;
		}		
	}
}


int main(){
NganXep S;
int n;
scanf("%d", &n);
doiNhiPhan(n, &S);
hienthi(&S);
	
}

