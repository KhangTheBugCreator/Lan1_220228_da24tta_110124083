/*
-mssv: 110124083
-Ho ten: Nguyen Minh Khang
-lop: DA24TTA
*/
#include <stdio.h>

int demsongaydathoacvuotmuctieu(float a[], int n, float x);
int demsongaykhongdatmuctieu(float a[], int n, float x);
float sogiohocnhieunhat(float a[], int n), sogiohocitnhat(float a[], int n);
double tongsogiohoc(float a[], int n), tbsogiohoc(float a[], int n);
void nhap(float a[],int n), xuat(float a[], int n),incacngayhocnhieunhat(float a[], int n),incacngayhocitnhat(float a[], int n),sapxep(float a[], int n);

int main(){
	int n=7;
	float a[n];
	nhap(a,n);
	xuat(a,n);
	printf("tong so gio hoc trong tuan la: %.2lf\n\n",tongsogiohoc(a,n));
	printf("trung binh so gio hoc trong mot ngay la: %.2lf\n\n",tbsogiohoc(a,n));
	incacngayhocnhieunhat(a,n);
	incacngayhocitnhat(a,n);
	float x;
	printf("nhap so gio muc tieu X=");
	scanf("%f",&x);
	printf("\n");
	printf("so ngay dat hoac vuot muc tieu la: %d\n\n",demsongaydathoacvuotmuctieu(a,n,x));
	printf("so ngay khong dat muc tieu: %d\n\n",demsongaykhongdatmuctieu(a,n,x));
	sapxep(a,n);
	return 0;
}

void nhap(float a[],int n){
	for (int i=0;i<n;i++){
		if (i+2!=8){
			do{
				printf("nhap thoi gian hoc tap cho thu %d (don vi la gio): ",i+2);
				scanf("%f",&a[i]);
			}while(a[i]<0 || a[i]>15);
		}else{
			do{
				printf("nhap thoi gian hoc cho chu nhat (don vi la gio): ");
				scanf("%f",&a[i]);
			}while (a[i]<0 || a[i]>15);
		}
	}
	printf("\n");
}
void xuat(float a[], int n){
	for (int i=0;i<n;i++){
		if (i+2!=8){
			printf("thoi gian hoc tap cua thu %d la: %.2f gio\n",i+2,a[i]);
		}else{
			printf("thoi gian hoc tap vao chu nhat la: %.2f gio\n",a[i]);
		}
	}
	printf("\n");
}
double tongsogiohoc(float a[], int n){
	double kq=0;
	for (int i=0;i<n;i++){
		kq+=a[i];
	}
	return kq;	
}
double tbsogiohoc(float a[], int n){
	return tongsogiohoc(a,n)/7;
}
float sogiohocnhieunhat(float a[], int n){
	float max=a[0];
	for (int i=1;i<n;i++){
		if (max<a[i]) max=a[i];
	}
	return max;
}
float sogiohocitnhat(float a[], int n){
	float min=a[0];
	for (int i=1;i<n;i++){
		if (min>a[i]) min=a[i];
	}
	return min;
}
void incacngayhocnhieunhat(float a[], int n){
	printf("cac ngay hoc nhieu nhat trong tuan: \n");
	for (int i=0;i<n;i++){
		int thu=i+2;
		if (a[i]==sogiohocnhieunhat(a,n)){
			if (thu!=8){
				printf("thu %d \n",thu);
			}
			else{
				printf("chu nhat\n");
			}
		}
	}
	printf("\n");
}
void incacngayhocitnhat(float a[], int n){
	printf("cac ngay hoc it nhat trong tuan: \n");
	for (int i=0;i<n;i++){
		int thu=i+2;
		if (a[i]==sogiohocitnhat(a,n)){
			if (thu!=8){
				printf("thu %d\n",thu);
			}
			else{
				printf("chu nhat");
			}
		}
	}
	printf("\n");
}
int demsongaydathoacvuotmuctieu(float a[], int n, float x){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]>=x){
			dem++;
		}
	}
	return dem;
}
int demsongaykhongdatmuctieu(float a[], int n, float x){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]<x){
			dem++;
		}
	}
	return dem;
}
void sapxep(float a[], int n){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[j]>a[i]){
				float t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	printf("gio hoc cac ngay theo thu tu giam dan: \n");
	for (int i=0;i<n;i++){
		printf("%.2f ",a[i]);
	}
}
