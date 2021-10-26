#include<iostream>
#include<ctime>
using namespace std;

int z = 1;

void vsefori(int i, int **arr, int R, int C){

	for (int stlb = i; stlb < C - i; stlb++){
		if (arr[i][stlb] == 0) {
			arr[i][stlb] = z;
			z++;
		}
	}
	for (int str = i; str < R - i; str++){
		if (arr[str][C - 1 - i] == 0) {
			arr[str][C - 1 - i] = z;
			z++;
		}
	}
	for (int stlb = C - (i + 1); stlb >=  i; stlb--){
		if (arr[R - 1 - i][stlb] == 0) {
			arr[R - 1 - i][stlb] = z;
			z++;
		}
	}
	for (int str = R - (1 + i); str > i; str--){
		if (arr[str][i] == 0) {
			arr[str][i] = z;
			z++;
		}
	}
}
void pechat(int** arr, int R, int C) {
	for (int str = 0; str < R; str++){
		for (int stlb = 0; stlb < C; stlb++)
		{
			cout << arr[str][stlb] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	setlocale(LC_ALL, "ru");



	int R;
	int C;
	cout << "Vvedite kolichestvo strok: " << endl;
	cin >> R;

	cout << "Vvedite kolichestvo stolbtsov: " << endl;
	cin >> C;
	cout << endl;

	int** arr = new int* [R];
	for (int i = 0; i < R; i++) {
		arr[i] = new int[C];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = 0;
		}
	}


	if (C < R) {
		for (int i = 0; i < (C + 1) / 2 ; i++) {
			vsefori(i, arr, R, C);
		}
	}
	else {
		for (int i = 0; i < (R + 1) / 2; i++) {
			vsefori(i, arr, R, C);
		}
	}

	pechat(arr, R, C);

	return 0;
}
