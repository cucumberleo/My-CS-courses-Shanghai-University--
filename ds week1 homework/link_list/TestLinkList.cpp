#include "LinkList.h"		// ��������
#include "windows.h"
void merge(LinkList<int>&ls1,LinkList<int>&ls2,LinkList<int>&ls3){
	Node<int>*p1 = ls1.head->next;
	Node<int>*p2 = ls2.head->next;
	int counter = 1;
	while(p1!=NULL && p2!=NULL){
		int e1 = p1->data, e2 = p2->data;
		if(e1<=e2) {
			ls3.InsertElem(counter,e1);
			++counter;
			p1 = p1->next;
		}else{
			ls3.InsertElem(counter,e2);
			++counter;
			p2 = p2->next;
		}
	}
	while(p1!=NULL){
		int e1 = p1->data;
		ls3.InsertElem(counter,e1);
		++counter,p1 = p1->next;
	}
	while(p2!=NULL){
		int e2 = p2->data;
		ls3.InsertElem(counter,e2);
		++counter,p2 = p2->next;
	}
	ls3.Reverse();
}
void init(LinkList<int>&la){
	la.Clear();
	int e;
	cout << endl << "����e(e = 0ʱ�˳�):";
	cin >> e;
	while (e != 0){
		la.InsertElem(e);
		cin >> e;
	}
}
int main(void)
{
	// SetConsoleOutputCP(CP_UTF8);
	char c = '*';
    LinkList<int> la,lb,lc;
    int e;
	int i;

    while (c != '0')
	{
        cout << endl << "1. ���ɵ�����.";
        cout << endl << "2. ��ʾ������.";
        cout << endl << "3. ȡָ��λ�õ�Ԫ��.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
		cout << endl << "7. Ԫ�ض�λ";
		cout << endl << "8. ȡ��������";
		cout << endl << "9. ���õ�������";
  		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~9):";
		cin >> c;
		switch (c) 
		{
			case '1':
			    la.Clear();
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0)   {
					la.InsertElem(e);
					cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (la.GetElem(i, e) == RANGE_ERROR) 
					cout << "Ԫ�ز�����." << endl;
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
			    if (la.InsertElem(i, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "�ɹ�:" << e << endl;
			    break;
			case '7':
			    cout << endl << "����Ԫ�ص�ֵ:";
			    cin >> e;
			    i = la.LocateElem(e);
			    if (i == 0) 
					cout << "Ԫ�ز�����." << endl;
				else
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
			    break;
			case '8':
			    cout << endl << "������ĳ���Ϊ:" << la.GetLength()  << endl;
			    break;
		//  case '9':
		//  	la.RemoveRep();
		// 	break;
		 	case '9':
		 		la.Reverse();
				break;
			// case '9':
			// 	cout << "��������Ҫɾ����Ԫ��ֵ��"<<'\n';
			// 	int el;
			// 	cin >> el;
			// 	la.Deleval(el);
			// 	break;
			// case '9':
			// 	init(la),init(lb);
			// 	merge(la,lb,lc);
			// 	lc.Traverse(Write<int>);
		}
	}
	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ1
}
