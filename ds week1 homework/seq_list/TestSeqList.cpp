#include "SeqList.h"	// ˳�����
#include <iostream>
using namespace std;
template<class T>
void Merge_List(const SeqList<T>& la, const SeqList<T>& lb, SeqList<T>& lc) {
    int i = 1, j = 1;
    int counter = 0;
	int lena = la.GetLength(), lenb = lb.GetLength();
    // �ϲ����������
    while (i <= lena && j <= lenb) {
        T e1, e2;
        la.GetElem(i, e1);  // ��ȡla�е�Ԫ��
        lb.GetElem(j, e2);  // ��ȡlb�е�Ԫ��
        // �Ƚ�������ǰԪ�صĴ�С
        if (e1 <= e2) {
            lc.InsertElem(counter, e1);
            ++i;
        } else {
            lc.InsertElem(counter, e2);
            ++j;
        }
        ++counter;
    }
    // ���la����ʣ��Ԫ�أ�ֱ�Ӳ��뵽lc��
    while (i<=lena) {
        T e1;
        la.GetElem(i, e1);
        lc.InsertElem(counter, e1);
        ++i;
        ++counter;
    }
    // ���lb����ʣ��Ԫ�أ�ֱ�Ӳ��뵽lc��
    while (j<=lenb) {
        T e2;
        lb.GetElem(j, e2);
        lc.InsertElem(counter, e2);
        ++j;
        ++counter;
    }
}
int main(void)
{
	char c = '*';
    SeqList<int> la(20),lb(20),lc(20);
    int e, i;
    Status sta;
	while (c != '0')
	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
		cout << endl << "9. �������Ա�.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~9):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW) 
						cout << "���Ա�����." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT) 
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
				if (la.SetElem(i, e) == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "���óɹ�." << endl;
			    break;
			case '5':
			    cout << endl << "����λ��:";
			    cin >> i;
			    if (la.DeleteElem(i, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "��ɾ��Ԫ��ֵ:" << e << endl;
			    break;
			case '6':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    sta = la.InsertElem(i, e);
			    
			    if (sta == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else if (sta == OVER_FLOW) 
					cout << "���Ա�����." << endl;
				else
					cout << "����ɹ�." << endl;	
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = la.LocateElem(e); 
			    if (i != 0) 
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else

					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << la.GetLength() << endl; 
			    break;
			// case '9':
			// 	la.RemoveRep();
			// 	break;
			// 
			// case '9':
			// 	int s,t;
			// 	cout << "������s��"<<'\n';
			// 	cin >> s;
			// 	cout << "������t:" <<'\n';
			// 	cin >> t;
			// 	la.RemoveStT(s,t);
			case '9':
				la.Reverse();
				break;
			// case '9':
			// 	int a[6] = {1,6,7,9,10,30},b[4] = {3,4,8,9};
			// 	SeqList<int>list1(a,6,10),list2(b,4,10),list3;
			// 	// list2.Traverse(Write<int>);
			// 	Merge_List(list1,list2,list3);
				
       	}
	}
   	system("PAUSE");        		// ���ÿ⺯��system()����ͣ�������� 
   	return 0;               		// ���ز���ϵͳ
}


