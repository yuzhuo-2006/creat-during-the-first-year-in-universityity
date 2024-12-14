/*#include<iostream>
using namespace std;


template<typename T>
struct Node {
	T data;
	Node* next;
	Node(const T &value):data(value),next(NULL){}
};



template<typename T>
class NodeList {
private:
	Node<T>* front, * rear;
public:
	
	
	
	NodeList():front(NULL),rear(NULL){}//��ʼ��
	 
	
	
	void enque(const T& e) {// ����
		
		Node<T>* NewNode = new Node<T>  (e);
		if (empty()) {
			front = NewNode;
			rear = NewNode;
		}

		else {
			rear->next = NewNode;
			rear = NewNode;
		}
	}

	
	
	~NodeList() {//���г���
		while (!empty()) 
		{
			deque();
		}
	}
	bool empty() {
		return front == NULL;
	}
	T deque() {
		if (empty()) {
			throw runtime_error("����Ϊ�գ��޷�������");
		}
			T value = front->data;
			Node<T>* temp = front;
			front = front->next;
			delete temp;
		
		if (front==NULL){
			rear = NULL;
		}
		return value;
	}

	//��ȡ���г���
void getlength() {
		int count = 0;
		Node<T>* p = front;
		while(p!=NULL)
		{
			count++;
		p = p->next;
		}
		cout << count << endl;
	}


	//���������Ƿ��ڶ�����
	void findValue(const T& value) {
		Node<T>* p = front->next;
		do {
			if (p->data == value) {
				cout << "���������ڶ�����" << endl;
				break;
			}
			
		 if (p == NULL) {
				cout << "δ���ҵ�ָ������" << endl;
				break;
			}
		 p=p->next;
		} while (p != NULL);

	}

};
void menue() {//�˵�����
	cout << "�����в����˵��˵���" << endl;
	cout << "  1.���г�ʼ�� " << endl;
	cout << "  2.���" << endl;
	cout << "  3.����" << endl;
	cout << "  4.����������" << endl;
	cout << "  5.��ӣ���������г��ȣ�ͬʱ�ж����������Ƿ��ڶ�����" << endl;
	cout << "  6.�˳�ϵͳ" << endl;
	cout << "�����빦�����֣�" << endl;
}
int main() {

	NodeList<int> NodeList;
	int value;
	
	while (true) {//�˵�����ʵ��
		menue();
		int option;
		cin >> option;
		switch (option) {
		case 1:
			
			cout << "���г�ʼ���ɹ�" << endl;
			break;
		case 2:
			cout << "���������������" << endl;
			cin >> value;
			NodeList.enque(value);
			cout<<value << "��ӳɹ�" << endl;
		
			break;
		case 3:
			try {
				value=NodeList.deque();
				cout << value << "���ӳɹ�" << endl;
			}
			catch (runtime_error &e){
				cout << e.what() << endl;
			}
			break;
		case 4:
	
			
			cout << "�����гɹ�����" << endl;
			break;
		case 5:
			cout << "�������������" << endl;
			while (cin>>value) {
			
				NodeList.enque(value);
				if (value==0) {
					NodeList.deque();
					break; }
			}
			cout << "���еĳ���Ϊ��" ;
			NodeList.getlength();
			cout << endl;
			cout << "������Ҫ���ҵ�����" << endl;
			cin >> value;
			NodeList.findValue(value);
			
			break;
		case 6:
			cout << "ϵͳ�˳��ɹ�" << endl;
			return 0;
		default:
			cout << "����ѡ��Χ������������" << endl;
}
	}
	return 0;
}
*/