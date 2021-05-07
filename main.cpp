#include <time.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
const int xsize = 8;
const int ysize = 8;

using namespace std;

int sortdefault[10];
size_t sortSize = SIZE_OF_ARRAY(sortdefault);

void initSort(int _array[]);//配列初期化
void printSort(int _array[], int _arraySize);//配列の出力
void sentakuSort(int _array[]);//選択ソート
void bubbleSort(int _array[]);//バブルソート
void insertSort(int _array[]);//挿入ソート
void searchResult(int _target, int _result);
void hashArray(int _array[], int _hash[], int _arraySize);
int hashSearch(int _array[], int _hash[], int _arraySize, int _serchData);
void hashArray2(int _array[], int _hash[], int _pointa[], int _arraySize);
int hashSearch2(int _hash[], int _pointa[], int _serchData);
int linearSearch(int _array[], int _arraySize, int _serchData);//線形探索
int linearSearch2(int _array[], int _arraySize, int _serchData);//線形探索（番兵あり）
void printImage(int _array[][xsize]);//画像の出力
int kaijo(int n);
int binarySearch(int _array[], int _ans, int _low, int _high);//二分探索
void shellSort(int _array[], size_t _size);//シェルソート
void quickSort(int _array[], int left, int right);//クイックソート
int findPivot(int x, int y, int z);//クイックソートのピボット決定
void heapSort(int _array[], int _arraySize);//ヒープソート
void makeHeap(int _array[], int _arraySize);//ヒープ木作成　
void heapSwap(int _array[], int _a, int _b);//交換
void merge(int _array[], int _temp[], int _left, int _right);//統合
void mergeSort(int _array[], int _temp[], int _left, int _right);//分割とソート

int main() {
	initSort(sortdefault);
	printSort(sortdefault, sortSize);


	//1　選択ソート edittest
	/*sentakuSort(sortdefault);
	cout << "選択ソート" << endl;
	printSort(sortdefault, sortSize);*/


	//2　バブルソート
	/*bubbleSort(sortdefault);
	cout << "バブルソート" << endl;
	printSort(sortdefault, sortSize);*/


	//3　挿入ソート
	/*insertSort(sortdefault);
	cout << "挿入ソート" << endl;
	printSort(sortdefault, sortSize);*/


	//4-1　線形探索法1
	/*int ans = linearSearch(sortdefault, sortSize, 5);
	cout << "線形探索法1" << endl;
	
	searchResult(5, ans);*/
	
	
	//4-2　線形探索法2番兵あり
	/*int ans = linearSearch2(sortdefault, sortSize, 5);
	cout << "線形探索法(番兵あり)" << endl;
	cout << "探索データ：5" << endl;
	searchResult(5, ans);*/


	//5　二分探索法
	/*cout << "まずソート" << endl;
	sentakuSort(sortdefault);
	printSort(sortdefault, sortSize);

	cout << "二分探索法" << endl;
	cout << "探索データ：5" << endl;
	int ans = binarySearch(sortdefault, 5, 0, 9);
	searchResult(5, ans);*/



	//6　ハッシュ表探索(オープンアドレス法)
	//格納フェーズ
	//int hash[10];
	//hashArray(sortdefault, hash, sortSize);
	//printSort(hash, sortSize);

	////探索フェーズ
	//int searchData;
	//cout << "探索データを入力:";
	//cin >> searchData;
	//int ans = hashSearch(sortdefault, hash, sortSize, searchData);
	//cout << "オープンアドレス法" << endl;
	//searchResult(searchData, ans);



	//7　ハッシュ表探索(チェイン法)
	//格納フェーズ
	int hash[10 * 2];//後ろ10はハッシュ領域
	int pointa[10 * 2];
	hashArray2(sortdefault, hash, pointa, sortSize);
	printSort(hash, sortSize*2);
	printSort(pointa, sortSize*2);

	//探索フェーズ
	int searchData;
	cout << "探索データを入力:";
	cin >> searchData;
	int result = hashSearch2(hash, pointa, searchData);
	cout << "チェイン法" << endl;
	searchResult(searchData, result);
	


	//8　文字列操作
	/*string mondai = "ゆりこゆりあゆめよ";
	string search = "ゆりあ";
	cout << mondai << endl;

	int mondaiLength = mondai.length();
	int searchLength = search.length();
	int flag;
	int i = 0;
	int j = 0;

	while (1) {
		if (mondai[i] == search[j]) {
			i++;
			j++;
		}
		else {
			i++;
			j = 0;
		}
		if (j >= searchLength) {
			flag = i;
			break;
		}
		if (i >= mondaiLength) {
			flag = false;
			break;
		}
	}
	if (flag == 0) 	cout << search << "はない" << endl;
	else cout << search << "は" << (flag - 6) / 2 + 1 << "文字目にあり" << endl;*/
	



	//9　画像操作
	int data[] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,1,0,0,1,0,0,
		0,0,1,1,0,1,0,0,
		0,0,1,0,1,1,0,0,
		0,0,1,0,0,1,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
	};
	int field[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			field[i][j] = data[i * ysize + j];
		}
	}
	cout << "初期状態" << endl;
	printImage(field);


	//左回転----------------------------------------
	int rotate90left[ysize][xsize];
	//回転処理
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			rotate90left[i][j] = field[j][ysize-i-1];
		}
	}
	//出力
	cout << "左90度回転" << endl;
	printImage(rotate90left);


	//右回転----------------------------------------
	int rotate90right[ysize][xsize];
	//回転処理
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			rotate90right[i][j] = field[xsize-(j+1)][i];
		}
	}
	//出力
	cout << "右90度回転" << endl;
	printImage(rotate90right);


	//上下反転----------------------------------------
	//回転処理
	int flipUpsideDown[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			flipUpsideDown[i][j] = field[ysize-(i+1)][j];
		}
	}
	//出力
	cout << "上下反転" << endl;
	printImage(flipUpsideDown);


	//左右反転----------------------------------------
	//回転処理
	int flipHorizontal[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			flipHorizontal[i][j] = field[i][xsize - (j + 1)];
		}
	}
	//出力
	cout << "左右反転" << endl;
	printImage(flipHorizontal);


	//移動----------------------------------------
	int moveImage[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			if ((i >= ysize - 1) || (j >= xsize - 1)) moveImage[i][j] = 0;
			else moveImage[i][j] = field[i + 1][j + 1];
		}
	}
	cout << "移動" << endl;
	printImage(moveImage);

	//拡大----------------------------------------
	const int  zoomInSize = 2;
	int zoomIn[ysize* zoomInSize][xsize* zoomInSize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			for (int k = 0; k < zoomInSize; k++) {
				for (int l = 0; l < zoomInSize; l++) {
					zoomIn[i * zoomInSize + k][j * zoomInSize + l] = field[i][j];
				}
			}
		}
	}
	cout << "拡大" << endl;
	for (int i = 0; i < ysize*zoomInSize; i++) {
		for (int j = 0; j < xsize*zoomInSize; j++) {
			if (zoomIn[i][j] == 1)cout << "■";
			else cout << "□";
		}
		cout << endl;
	}

	//縮小----------------------------------------
	
	int zoomOut[ysize/zoomInSize][xsize/zoomInSize];
	for (int i = 0; i < ysize; i+=2) {
		for (int j = 0; j < xsize; j+=2) {
			zoomOut[i/zoomInSize][j/zoomInSize] = field[i][j];
		}
	}
	cout << "縮小" << endl;
	for (int i = 0; i < ysize / zoomInSize; i++) {
		for (int j = 0; j < xsize / zoomInSize; j++) {
			if (zoomOut[i][j] == 1)cout << "■";
			else cout << "□";
		}
		cout << endl;
	}
	
	//複写----------------------------------------
	const int copySize = 2;
	int copyImage[ysize* copySize][xsize* copySize];
	for (int i = 0; i < ysize; i ++) {
		for (int j = 0; j < xsize; j ++) {
			for (int k = 0; k < copySize; k++) {
				for (int l = 0; l < copySize; l++) {
					copyImage[(ysize * k) + i][(xsize * l) + j] = field[i][j];
				}
			}
		}
	}
	cout << "複写" << endl;
	for (int i = 0; i < ysize * copySize; i++) {
		for (int j = 0; j < xsize * copySize; j++) {
			if (copyImage[i][j] == 1)cout << "■";
			else cout << "□";
		}
		cout << endl;
	}

	//10　再帰処理
	////階乗
	//int num = 5;
	//cout << num << "の階乗は" << kaijo(num) << endl;

	////二分探索
	//sentakuSort(sortdefault);
	//printSort(sortdefault);
	//int low = 0;
	//int high = 9;
	//int ans=binarySearch(sortdefault, 5, low, high);
	//if (ans == -1)cout << "5は無い" << endl;
	//else cout << "5は" << ans+1 << "番目にあり" << endl;


	//11　シェルソート n個ごとの間隔で比較し、間隔を小さくしていく
	/*shellSort(sortdefault,sortSize);
	cout << "選択ソート" << endl;
	printSort(sortdefault);*/


	//12　クイックソート
	/*int sortLow = 0;
	int sortHigh = 9;
	quickSort(sortdefault, sortLow, sortHigh);
	cout << "クイックソート" << endl;
	printSort(sortdefault);*/


	//13　ヒープソート
	//入れ替わ手内
	/*heapSort(sortdefault, 10);
	cout << "ヒープソート" << endl;
	printSort(sortdefault);*/

	//14　マージソート
	/*int temp[10];
	mergeSort(sortdefault, temp, 0, 9);
	cout << "マージソート" << endl;
	printSort(sortdefault);*/


	//btap法
	//ハフマン符号
	//最短経路
	//リファクタリング　関数化やsort()を使うなど.カウントオーダーも追加,途中経過も出力
	//ライブラリ使って書く
}

void initSort(int _array[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < sortSize; i++) {
		_array[i] = rand() % 20;
	}
}

//降順の選択ソート
void sentakuSort(int _array[]) {
	int temp;
	for (int i = 0; i < sortSize - 1; i++) {
		int max = i;
		for (int j = i + 1; j < sortSize; j++) {
			if (_array[max] <= _array[j])max = j;
		}
		temp = _array[i];
		_array[i] = _array[max];
		_array[max] = temp;
	}
}

//バブルソート
void bubbleSort(int _array[]) {
	int temp;
	for (int i = 1; i < sortSize - 1; i++) {
		for (int j = 0; j < sortSize - i; j++) {
			if (_array[j] <= _array[j + 1]) {
				temp = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = temp;
			}
		}
	}
}

//挿入ソート
void insertSort(int _array[]) {
	int temp;
	for (int i = 1; i < sortSize; i++) {
		for (int j = 0; j < i; j++) {
			if (_array[i] <= _array[j]) {
				temp = _array[j];
				_array[j] = _array[i];
				_array[i] = temp;
			}
		}
	}
}

//配列を出力
void printSort(int _array[], int _arraySize) {
	for (int i = 0; i < _arraySize; i++) {
		cout << _array[i] << " ";
	}
	cout << endl;
}

//探索結果を出力
void searchResult(int _target, int _result) {
	cout << "探索データ：" << _target << endl;
	if (_result == -1)cout << "探索データ無し" << endl;
	else cout << "探索データは" << _result + 1 << "番目にあり" << endl;
}

//線形探索
int linearSearch(int _array[], int _arraySize, int _serchData) {
	int i = 0;
	while (i < _arraySize) {
		if (_array[i] == _serchData) {
			return i;
		}
		else if (i == _arraySize - 1) {
			return -1;
		}
		i++;
	}
	return -1;
}

//線形探索（番兵あり）
int linearSearch2(int _array[], int _arraySize, int _serchData) {
	int i = 0;
	int *newArray=new int[_arraySize+1];
	for (int j = 0; j < _arraySize + 1; j++) {
		newArray[j] = _array[j];
	}
	newArray[_arraySize] = _serchData;
	while (newArray[i] != _serchData) {
		i++;
	}
	delete[] newArray;
	if (i == _arraySize) return -1;
	else return i;
}

//オープンアドレス法のハッシュ化
void hashArray(int _array[], int _hash[], int _arraySize) {
	//ハッシュ配列を初期化
	int temp;
	int i = 0;
	for (i = 0; i < _arraySize; i++) {
		_hash[i] = -1;
	}

	//配列をハッシュ化
	for (i = 0; i < _arraySize; i++) {
		temp = _array[i] % _arraySize;
		while (1) {
			if (_hash[temp] == -1) {
				_hash[temp] = _array[i];
				break;
			}
			else temp++;
			if (temp >= _arraySize) temp = 0;
		}
	}
}
//オープンアドレス法の探索
int hashSearch(int _array[], int _hash[], int _arraySize, int _serchData) {
	int temp;
	temp = _serchData % _arraySize;
	int end = temp;
	while (1) {
		if (_hash[temp] == _serchData) {
			return temp;
		}
		else if (_hash[temp] == -1) {
			break;
		}

		if (temp < _arraySize)temp++;
		else if (temp == _arraySize)temp = 0;
		if (temp == end)break;
	}
	return -1;
}


//チェイン法のハッシュ化
void hashArray2(int _array[], int _hash[], int _pointa[], int _arraySize) {
	int temp;
	//初期化
	for (int i = 0; i < _arraySize * 2; i++) {
		_hash[i] = -1;
		_pointa[i] = -1;
	}
	//ハッシュ化
	int j = 0;
	for (int i = 0; i < _arraySize; i++) {
		//順番にハッシュ化
		temp = _array[i] % _arraySize;
		while (1) {
			//まだhash[temp]に値が入ってなかったら格納
			if (_hash[temp] == -1) {
				_hash[temp] = _array[i];
				break;
			}
			//既にhash[temp]に値が入ってたらpointa[temp]にhash[]のハッシュ領域へのアドレスを記憶
			//pointa[temp]にも値が入ってたらhash[]のハッシュ領域のpointa[]にアドレスを格納
			else {
				while (_pointa[temp] != -1) temp = _pointa[temp];
				_pointa[temp] = _arraySize + j;
				_hash[_arraySize + j] = _array[i];
			}
			j++;
			break;
		}
	}
}
//チェイン法の探索
int hashSearch2(int _hash[], int _pointa[], int _serchData) {
	//検索データをハッシュ化
	int temp = _serchData % 10;
	int end = temp;
	while (1) {
		if (_hash[temp] == _serchData) return temp;
		else if (_hash[temp] == -1) break;
		temp = _pointa[temp];
		if (temp == end)break;
	}
	return -1;
}

//画像を出力
void printImage(int _array[][xsize]) {
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			if (_array[i][j] == 1)cout << "■";
			else cout << "□";
		}
		cout << endl;
	}
}

//再帰的に階乗を計算
int kaijo(int n) {
	if (n < 1)return 0;
	if (n == 1)return 1;
	else return n * kaijo(n - 1);
}

//再帰的二分探索
int binarySearch(int _array[], int _ans, int _low, int _high) {
	if (_low <= _high) {
		int mid = (_low + _high) / 2;
		if (_array[mid] == _ans) return mid;
		else if(_array[mid] > _ans) return binarySearch(_array, _ans, mid + 1, _high);
		else return binarySearch(_array, _ans, _low, mid - 1); 
	}
	else return -1;
}

//シェルソート
void shellSort(int _array[],size_t _size) {
	int interval = _size/2;
	//インターバルを小さくしていくループ
	while (interval>0){
		//インターバル個ある新配列の数回すループ
		for (int i = 0; i < interval; i++)
		{
			//間隔intervalの挿入ソート
			for (int j = i; j < _size; j+=interval)
			{
				for (int k = j + interval; k < _size; k+=interval)
				{
					if (_array[j] >= _array[k]) {
						int temp = _array[j];
						_array[j] = _array[k];
						_array[k] = temp;
					}
				}
			}
		}
		interval /= 2;
	}
}

//インターバルを決める
//インターバル個ある新配列の1つ目の要素を決める
//新配列を挿入ソートする。
//1つ目の要素と1+nつ目の要素を比較する
//1つ目の要素と1+2nつ目の要素を比較する
//2つ目の要素と3つ目の要素を比較する
//1つ目の要素と4つ目の要素を比較する
//2つ目の要素と4つ目の要素を比較する
//3つ目の要素と4つ目の要素を比較する
//ｊ要素が基のサイズになるまで繰り返す
//一つ目の要素をインクリメントする。（インターバルまで）
//インターバルを小さくする（インターバルが1まで）

void quickSort(int _array[], int left, int right) {
	if (left < right) {
		int i = left;
		int j = right;
		int  temp;
		int pivot = findPivot(_array[i], _array[i + (j - i) / 2], _array[j]); /* (i+j)/2 ではオーバーフローしてしまう */
		while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
			while (_array[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
			while (pivot < _array[j]) j--; /* a[j] <= pivot となる位置を検索 */
			if (i >= j) break;
			temp = _array[i];
			_array[i] = _array[j];
			_array[j] = temp; /* a[i], a[j] を交換 */
			i++;
			j--;
		}
		quickSort(_array, left, i - 1);  /* 分割した左を再帰的にソート */
		quickSort(_array, j + 1, right); /* 分割した右を再帰的にソート */
	}
}


//3つの中央値を返す関数
int findPivot(int x, int y, int z) {
	if (x < y) {
		if (y < z) return y; 
		else if (z < x) return x; 
		else return z;
	}
	else {
		if (z < y) return y; 
		else if (x < z) return x; 
		else return z;
	}
}

//ピボットを決める
//iを左から順に値を調べピボットより大きいものを探す
//jを右から順に値を調べピボットより小さいものを探す
//入れ替える
//それぞれインクリメント、デクリメントする。（iまたはjがピボットまで）
//あまったらピボット本体と入れ替える
//iの左側を基準に二つに分割し、それぞれでピボットを決める。（要素数が1以下まで）



void heapSort(int _array[], int _arraySize) {
	if (_arraySize != 1) {
		heapSwap(_array, 0, _arraySize);
		makeHeap(_array, _arraySize-1);
		heapSort(_array, _arraySize - 1);
	}
}
//動作
//ルートを取り出して末尾と入れ替える。
//ヒープ木再構築
//n-1個の要素でヒープソートする。
//n=1なら終わるという動作を追加する。

void makeHeap(int _array[], int _arraySize) {
	
	int heapRoot = (_arraySize / 2) - 1;
	int heapBranch1 = _arraySize - 1;
	int heapBranch2 = _arraySize;
	if (_arraySize % 2 == 0) {
		if (_array[heapRoot] < _array[heapBranch1]) heapSwap(_array, heapRoot, heapBranch1);
		heapRoot -= 1;
		heapBranch1 -= 2;
		heapBranch2 -= 2;
	}

	while (1) {
		int temp = heapRoot;
		if (_array[heapRoot] < _array[heapBranch1]) {
			temp = heapBranch1;
			if(_array[heapBranch1] < _array[heapBranch2]) temp = heapBranch2;
			heapSwap(_array, heapRoot, temp);
		}
		if (_array[heapRoot] < _array[heapBranch2]) {
			temp = heapBranch2;
			heapSwap(_array, heapRoot, temp);
		}
		heapRoot -= 1;
		heapBranch1 -= 2;
		heapBranch2 -= 2;
		if (heapRoot < 0)break;
	}
}
//動作
//一番下の枝に注目
//奇数なら2偶数なら3の要素を比較し一番大きいものを根に置く
//前の枝に注目
//3の要素を比較し一番大きいものを根に置く
//前の枝に注目
//3の要素を比較し一番大きいものを根に置く
//要素が0番目になったら終了

void heapSwap(int _array[], int _a, int _b) {
	int temp = _array[_a];
	_array[_a] = _array[_b];
	_array[_b] = temp;
}



//_arrayは配列、_temp[]はコピー領域、_leftは開始インデックス、_rightは終了インデックス
void mergeSort(int _array[],int _temp[], int _left, int _right) {
	if (_left >= _right) return;
	int mid = (_left + _right) / 2;
	mergeSort(_array, _temp, _left, mid);
	mergeSort(_array, _temp, mid+1,_right);
	merge(_array, _temp, _left, _right);
}
//動作
//要素が1つになるまで配列を2つに分割する
//各配列を低い順にソートする
//2つの配列をマージする。ひとつならそれ自身をマージする。（配列が一つになるまで）

//iはtempの現在のインデックス。jは左の現在のインデックス。kは右の現在のインデックス。midは左の終了地点。
void merge(int _array[], int _temp[], int _left, int _right) {
	int i = 0;
	int j = _left;
	int k = (_left + _right) / 2 + 1;
	int mid = (_left + _right) / 2;
	while ((j<=mid)&&(k<=_right)) {
		if (_array[j] >= _array[k]) {
			_temp[i] = _array[k];
			k++;
		}
		else {
			_temp[i] = _array[j];
			j++;
		}
		i++;
	}
	if (j == mid+1) {
		while (k <= _right) {
			_temp[i] = _array[k];
			i++;
			k++;
		}
	}
	else {
		while (j<=mid) {
			_temp[i] = _array[j];
			i++;
			j++;
		}
	}
	for (int m = 0; m < i; m++) _array[_left + m] = _temp[m];
}
//動作
//コピー領域を用意する。
//2つの配列の始めの要素から比較していき、小さい方をコピー領域へコピーする
//片方が末端へ達したら、もう片方の残りを全てコピー領域へコピーする。
//基の配列にコピーする
