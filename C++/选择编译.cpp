#include<iostream>
using namespace std;
int main() {
#define a 1;
#ifdef a//���ʹ��Ԥ����궨��a,�ͱ����м�����
#define a 1;
	cout << "ifdef����" << endl;
#endif//ѡ���Ա���Ľ�����־

#define b 0
#if b//���Ԥ�������b��ֵΪ0�ͱ����һ����
	cout << "bΪ��ʱ,#if����" << endl;
#else//�����������
	cout << "b��Ϊ0ʱ,#else����" << endl;
#endif//������־


#ifndef c//���û��ʹ��Ԥ����궨�嶨��c,�ͱ���
#define c 1//����д������û�ж���c
	cout << "#ifndef,û�б���" << endl;
#endif
	return 0;
}
