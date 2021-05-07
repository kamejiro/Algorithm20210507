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

void initSort(int _array[]);//�z�񏉊���
void printSort(int _array[], int _arraySize);//�z��̏o��
void sentakuSort(int _array[]);//�I���\�[�g
void bubbleSort(int _array[]);//�o�u���\�[�g
void insertSort(int _array[]);//�}���\�[�g
void searchResult(int _target, int _result);
void hashArray(int _array[], int _hash[], int _arraySize);
int hashSearch(int _array[], int _hash[], int _arraySize, int _serchData);
void hashArray2(int _array[], int _hash[], int _pointa[], int _arraySize);
int hashSearch2(int _hash[], int _pointa[], int _serchData);
int linearSearch(int _array[], int _arraySize, int _serchData);//���`�T��
int linearSearch2(int _array[], int _arraySize, int _serchData);//���`�T���i�ԕ�����j
void printImage(int _array[][xsize]);//�摜�̏o��
int kaijo(int n);
int binarySearch(int _array[], int _ans, int _low, int _high);//�񕪒T��
void shellSort(int _array[], size_t _size);//�V�F���\�[�g
void quickSort(int _array[], int left, int right);//�N�C�b�N�\�[�g
int findPivot(int x, int y, int z);//�N�C�b�N�\�[�g�̃s�{�b�g����
void heapSort(int _array[], int _arraySize);//�q�[�v�\�[�g
void makeHeap(int _array[], int _arraySize);//�q�[�v�؍쐬�@
void heapSwap(int _array[], int _a, int _b);//����
void merge(int _array[], int _temp[], int _left, int _right);//����
void mergeSort(int _array[], int _temp[], int _left, int _right);//�����ƃ\�[�g

int main() {
	initSort(sortdefault);
	printSort(sortdefault, sortSize);


	//1�@�I���\�[�g
	/*sentakuSort(sortdefault);
	cout << "�I���\�[�g" << endl;
	printSort(sortdefault, sortSize);*/


	//2�@�o�u���\�[�g
	/*bubbleSort(sortdefault);
	cout << "�o�u���\�[�g" << endl;
	printSort(sortdefault, sortSize);*/


	//3�@�}���\�[�g
	/*insertSort(sortdefault);
	cout << "�}���\�[�g" << endl;
	printSort(sortdefault, sortSize);*/


	//4-1�@���`�T���@1
	/*int ans = linearSearch(sortdefault, sortSize, 5);
	cout << "���`�T���@1" << endl;
	
	searchResult(5, ans);*/
	
	
	//4-2�@���`�T���@2�ԕ�����
	/*int ans = linearSearch2(sortdefault, sortSize, 5);
	cout << "���`�T���@(�ԕ�����)" << endl;
	cout << "�T���f�[�^�F5" << endl;
	searchResult(5, ans);*/


	//5�@�񕪒T���@
	/*cout << "�܂��\�[�g" << endl;
	sentakuSort(sortdefault);
	printSort(sortdefault, sortSize);

	cout << "�񕪒T���@" << endl;
	cout << "�T���f�[�^�F5" << endl;
	int ans = binarySearch(sortdefault, 5, 0, 9);
	searchResult(5, ans);*/



	//6�@�n�b�V���\�T��(�I�[�v���A�h���X�@)
	//�i�[�t�F�[�Y
	//int hash[10];
	//hashArray(sortdefault, hash, sortSize);
	//printSort(hash, sortSize);

	////�T���t�F�[�Y
	//int searchData;
	//cout << "�T���f�[�^�����:";
	//cin >> searchData;
	//int ans = hashSearch(sortdefault, hash, sortSize, searchData);
	//cout << "�I�[�v���A�h���X�@" << endl;
	//searchResult(searchData, ans);



	//7�@�n�b�V���\�T��(�`�F�C���@)
	//�i�[�t�F�[�Y
	int hash[10 * 2];//���10�̓n�b�V���̈�
	int pointa[10 * 2];
	hashArray2(sortdefault, hash, pointa, sortSize);
	printSort(hash, sortSize*2);
	printSort(pointa, sortSize*2);

	//�T���t�F�[�Y
	int searchData;
	cout << "�T���f�[�^�����:";
	cin >> searchData;
	int result = hashSearch2(hash, pointa, searchData);
	cout << "�`�F�C���@" << endl;
	searchResult(searchData, result);
	


	//8�@�����񑀍�
	/*string mondai = "��肱��肠��߂�";
	string search = "��肠";
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
	if (flag == 0) 	cout << search << "�͂Ȃ�" << endl;
	else cout << search << "��" << (flag - 6) / 2 + 1 << "�����ڂɂ���" << endl;*/
	



	//9�@�摜����
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
	cout << "�������" << endl;
	printImage(field);


	//����]----------------------------------------
	int rotate90left[ysize][xsize];
	//��]����
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			rotate90left[i][j] = field[j][ysize-i-1];
		}
	}
	//�o��
	cout << "��90�x��]" << endl;
	printImage(rotate90left);


	//�E��]----------------------------------------
	int rotate90right[ysize][xsize];
	//��]����
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			rotate90right[i][j] = field[xsize-(j+1)][i];
		}
	}
	//�o��
	cout << "�E90�x��]" << endl;
	printImage(rotate90right);


	//�㉺���]----------------------------------------
	//��]����
	int flipUpsideDown[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			flipUpsideDown[i][j] = field[ysize-(i+1)][j];
		}
	}
	//�o��
	cout << "�㉺���]" << endl;
	printImage(flipUpsideDown);


	//���E���]----------------------------------------
	//��]����
	int flipHorizontal[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			flipHorizontal[i][j] = field[i][xsize - (j + 1)];
		}
	}
	//�o��
	cout << "���E���]" << endl;
	printImage(flipHorizontal);


	//�ړ�----------------------------------------
	int moveImage[ysize][xsize];
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			if ((i >= ysize - 1) || (j >= xsize - 1)) moveImage[i][j] = 0;
			else moveImage[i][j] = field[i + 1][j + 1];
		}
	}
	cout << "�ړ�" << endl;
	printImage(moveImage);

	//�g��----------------------------------------
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
	cout << "�g��" << endl;
	for (int i = 0; i < ysize*zoomInSize; i++) {
		for (int j = 0; j < xsize*zoomInSize; j++) {
			if (zoomIn[i][j] == 1)cout << "��";
			else cout << "��";
		}
		cout << endl;
	}

	//�k��----------------------------------------
	
	int zoomOut[ysize/zoomInSize][xsize/zoomInSize];
	for (int i = 0; i < ysize; i+=2) {
		for (int j = 0; j < xsize; j+=2) {
			zoomOut[i/zoomInSize][j/zoomInSize] = field[i][j];
		}
	}
	cout << "�k��" << endl;
	for (int i = 0; i < ysize / zoomInSize; i++) {
		for (int j = 0; j < xsize / zoomInSize; j++) {
			if (zoomOut[i][j] == 1)cout << "��";
			else cout << "��";
		}
		cout << endl;
	}
	
	//����----------------------------------------
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
	cout << "����" << endl;
	for (int i = 0; i < ysize * copySize; i++) {
		for (int j = 0; j < xsize * copySize; j++) {
			if (copyImage[i][j] == 1)cout << "��";
			else cout << "��";
		}
		cout << endl;
	}

	//10�@�ċA����
	////�K��
	//int num = 5;
	//cout << num << "�̊K���" << kaijo(num) << endl;

	////�񕪒T��
	//sentakuSort(sortdefault);
	//printSort(sortdefault);
	//int low = 0;
	//int high = 9;
	//int ans=binarySearch(sortdefault, 5, low, high);
	//if (ans == -1)cout << "5�͖���" << endl;
	//else cout << "5��" << ans+1 << "�Ԗڂɂ���" << endl;


	//11�@�V�F���\�[�g n���Ƃ̊Ԋu�Ŕ�r���A�Ԋu�����������Ă���
	/*shellSort(sortdefault,sortSize);
	cout << "�I���\�[�g" << endl;
	printSort(sortdefault);*/


	//12�@�N�C�b�N�\�[�g
	/*int sortLow = 0;
	int sortHigh = 9;
	quickSort(sortdefault, sortLow, sortHigh);
	cout << "�N�C�b�N�\�[�g" << endl;
	printSort(sortdefault);*/


	//13�@�q�[�v�\�[�g
	//����ւ���
	/*heapSort(sortdefault, 10);
	cout << "�q�[�v�\�[�g" << endl;
	printSort(sortdefault);*/

	//14�@�}�[�W�\�[�g
	/*int temp[10];
	mergeSort(sortdefault, temp, 0, 9);
	cout << "�}�[�W�\�[�g" << endl;
	printSort(sortdefault);*/


	//btap�@
	//�n�t�}������
	//�ŒZ�o�H
	//���t�@�N�^�����O�@�֐�����sort()���g���Ȃ�.�J�E���g�I�[�_�[���ǉ�,�r���o�߂��o��
	//���C�u�����g���ď���
}

void initSort(int _array[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < sortSize; i++) {
		_array[i] = rand() % 20;
	}
}

//�~���̑I���\�[�g
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

//�o�u���\�[�g
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

//�}���\�[�g
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

//�z����o��
void printSort(int _array[], int _arraySize) {
	for (int i = 0; i < _arraySize; i++) {
		cout << _array[i] << " ";
	}
	cout << endl;
}

//�T�����ʂ��o��
void searchResult(int _target, int _result) {
	cout << "�T���f�[�^�F" << _target << endl;
	if (_result == -1)cout << "�T���f�[�^����" << endl;
	else cout << "�T���f�[�^��" << _result + 1 << "�Ԗڂɂ���" << endl;
}

//���`�T��
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

//���`�T���i�ԕ�����j
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

//�I�[�v���A�h���X�@�̃n�b�V����
void hashArray(int _array[], int _hash[], int _arraySize) {
	//�n�b�V���z���������
	int temp;
	int i = 0;
	for (i = 0; i < _arraySize; i++) {
		_hash[i] = -1;
	}

	//�z����n�b�V����
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
//�I�[�v���A�h���X�@�̒T��
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


//�`�F�C���@�̃n�b�V����
void hashArray2(int _array[], int _hash[], int _pointa[], int _arraySize) {
	int temp;
	//������
	for (int i = 0; i < _arraySize * 2; i++) {
		_hash[i] = -1;
		_pointa[i] = -1;
	}
	//�n�b�V����
	int j = 0;
	for (int i = 0; i < _arraySize; i++) {
		//���ԂɃn�b�V����
		temp = _array[i] % _arraySize;
		while (1) {
			//�܂�hash[temp]�ɒl�������ĂȂ�������i�[
			if (_hash[temp] == -1) {
				_hash[temp] = _array[i];
				break;
			}
			//����hash[temp]�ɒl�������Ă���pointa[temp]��hash[]�̃n�b�V���̈�ւ̃A�h���X���L��
			//pointa[temp]�ɂ��l�������Ă���hash[]�̃n�b�V���̈��pointa[]�ɃA�h���X���i�[
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
//�`�F�C���@�̒T��
int hashSearch2(int _hash[], int _pointa[], int _serchData) {
	//�����f�[�^���n�b�V����
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

//�摜���o��
void printImage(int _array[][xsize]) {
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			if (_array[i][j] == 1)cout << "��";
			else cout << "��";
		}
		cout << endl;
	}
}

//�ċA�I�ɊK����v�Z
int kaijo(int n) {
	if (n < 1)return 0;
	if (n == 1)return 1;
	else return n * kaijo(n - 1);
}

//�ċA�I�񕪒T��
int binarySearch(int _array[], int _ans, int _low, int _high) {
	if (_low <= _high) {
		int mid = (_low + _high) / 2;
		if (_array[mid] == _ans) return mid;
		else if(_array[mid] > _ans) return binarySearch(_array, _ans, mid + 1, _high);
		else return binarySearch(_array, _ans, _low, mid - 1); 
	}
	else return -1;
}

//�V�F���\�[�g
void shellSort(int _array[],size_t _size) {
	int interval = _size/2;
	//�C���^�[�o�������������Ă������[�v
	while (interval>0){
		//�C���^�[�o������V�z��̐��񂷃��[�v
		for (int i = 0; i < interval; i++)
		{
			//�Ԋuinterval�̑}���\�[�g
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

//�C���^�[�o�������߂�
//�C���^�[�o������V�z���1�ڂ̗v�f�����߂�
//�V�z���}���\�[�g����B
//1�ڂ̗v�f��1+n�ڂ̗v�f���r����
//1�ڂ̗v�f��1+2n�ڂ̗v�f���r����
//2�ڂ̗v�f��3�ڂ̗v�f���r����
//1�ڂ̗v�f��4�ڂ̗v�f���r����
//2�ڂ̗v�f��4�ڂ̗v�f���r����
//3�ڂ̗v�f��4�ڂ̗v�f���r����
//���v�f����̃T�C�Y�ɂȂ�܂ŌJ��Ԃ�
//��ڂ̗v�f���C���N�������g����B�i�C���^�[�o���܂Łj
//�C���^�[�o��������������i�C���^�[�o����1�܂Łj

void quickSort(int _array[], int left, int right) {
	if (left < right) {
		int i = left;
		int j = right;
		int  temp;
		int pivot = findPivot(_array[i], _array[i + (j - i) / 2], _array[j]); /* (i+j)/2 �ł̓I�[�o�[�t���[���Ă��܂� */
		while (1) { /* a[] �� pivot �ȏ�ƈȉ��̏W�܂�ɕ������� */
			while (_array[i] < pivot) i++; /* a[i] >= pivot �ƂȂ�ʒu������ */
			while (pivot < _array[j]) j--; /* a[j] <= pivot �ƂȂ�ʒu������ */
			if (i >= j) break;
			temp = _array[i];
			_array[i] = _array[j];
			_array[j] = temp; /* a[i], a[j] ������ */
			i++;
			j--;
		}
		quickSort(_array, left, i - 1);  /* �������������ċA�I�Ƀ\�[�g */
		quickSort(_array, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */
	}
}


//3�̒����l��Ԃ��֐�
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

//�s�{�b�g�����߂�
//i�������珇�ɒl�𒲂׃s�{�b�g���傫�����̂�T��
//j���E���珇�ɒl�𒲂׃s�{�b�g��菬�������̂�T��
//����ւ���
//���ꂼ��C���N�������g�A�f�N�������g����B�ii�܂���j���s�{�b�g�܂Łj
//���܂�����s�{�b�g�{�̂Ɠ���ւ���
//i�̍�������ɓ�ɕ������A���ꂼ��Ńs�{�b�g�����߂�B�i�v�f����1�ȉ��܂Łj



void heapSort(int _array[], int _arraySize) {
	if (_arraySize != 1) {
		heapSwap(_array, 0, _arraySize);
		makeHeap(_array, _arraySize-1);
		heapSort(_array, _arraySize - 1);
	}
}
//����
//���[�g�����o���Ė����Ɠ���ւ���B
//�q�[�v�؍č\�z
//n-1�̗v�f�Ńq�[�v�\�[�g����B
//n=1�Ȃ�I���Ƃ��������ǉ�����B

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
//����
//��ԉ��̎}�ɒ���
//��Ȃ�2�����Ȃ�3�̗v�f���r����ԑ傫�����̂����ɒu��
//�O�̎}�ɒ���
//3�̗v�f���r����ԑ傫�����̂����ɒu��
//�O�̎}�ɒ���
//3�̗v�f���r����ԑ傫�����̂����ɒu��
//�v�f��0�ԖڂɂȂ�����I��

void heapSwap(int _array[], int _a, int _b) {
	int temp = _array[_a];
	_array[_a] = _array[_b];
	_array[_b] = temp;
}



//_array�͔z��A_temp[]�̓R�s�[�̈�A_left�͊J�n�C���f�b�N�X�A_right�͏I���C���f�b�N�X
void mergeSort(int _array[],int _temp[], int _left, int _right) {
	if (_left >= _right) return;
	int mid = (_left + _right) / 2;
	mergeSort(_array, _temp, _left, mid);
	mergeSort(_array, _temp, mid+1,_right);
	merge(_array, _temp, _left, _right);
}
//����
//�v�f��1�ɂȂ�܂Ŕz���2�ɕ�������
//�e�z���Ⴂ���Ƀ\�[�g����
//2�̔z����}�[�W����B�ЂƂȂ炻�ꎩ�g���}�[�W����B�i�z�񂪈�ɂȂ�܂Łj

//i��temp�̌��݂̃C���f�b�N�X�Bj�͍��̌��݂̃C���f�b�N�X�Bk�͉E�̌��݂̃C���f�b�N�X�Bmid�͍��̏I���n�_�B
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
//����
//�R�s�[�̈��p�ӂ���B
//2�̔z��̎n�߂̗v�f�����r���Ă����A�����������R�s�[�̈�փR�s�[����
//�Е������[�֒B������A�����Е��̎c���S�ăR�s�[�̈�փR�s�[����B
//��̔z��ɃR�s�[����