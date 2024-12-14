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
	
	
	
	NodeList():front(NULL),rear(NULL){}//初始化
	 
	
	
	void enque(const T& e) {// 入列
		
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

	
	
	~NodeList() {//队列撤销
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
			throw runtime_error("队列为空，无法操作！");
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

	//获取队列长度
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


	//查找整数是否在队列中
	void findValue(const T& value) {
		Node<T>* p = front->next;
		do {
			if (p->data == value) {
				cout << "查找整数在队列中" << endl;
				break;
			}
			
		 if (p == NULL) {
				cout << "未查找到指定数字" << endl;
				break;
			}
		 p=p->next;
		} while (p != NULL);

	}

};
void menue() {//菜单构造
	cout << "链队列操作菜单菜单：" << endl;
	cout << "  1.队列初始化 " << endl;
	cout << "  2.入队" << endl;
	cout << "  3.出队" << endl;
	cout << "  4.撤销链队列" << endl;
	cout << "  5.入队，并输出队列长度，同时判断输入整数是否在队列中" << endl;
	cout << "  6.退出系统" << endl;
	cout << "请输入功能数字：" << endl;
}
int main() {

	NodeList<int> NodeList;
	int value;
	
	while (true) {//菜单功能实现
		menue();
		int option;
		cin >> option;
		switch (option) {
		case 1:
			
			cout << "队列初始化成功" << endl;
			break;
		case 2:
			cout << "请输入入队整数：" << endl;
			cin >> value;
			NodeList.enque(value);
			cout<<value << "入队成功" << endl;
		
			break;
		case 3:
			try {
				value=NodeList.deque();
				cout << value << "出队成功" << endl;
			}
			catch (runtime_error &e){
				cout << e.what() << endl;
			}
			break;
		case 4:
	
			
			cout << "链队列成功撤销" << endl;
			break;
		case 5:
			cout << "请输入入队整数" << endl;
			while (cin>>value) {
			
				NodeList.enque(value);
				if (value==0) {
					NodeList.deque();
					break; }
			}
			cout << "队列的长度为：" ;
			NodeList.getlength();
			cout << endl;
			cout << "请输入要查找的整数" << endl;
			cin >> value;
			NodeList.findValue(value);
			
			break;
		case 6:
			cout << "系统退出成功" << endl;
			return 0;
		default:
			cout << "不在选择范围，请重新输入" << endl;
}
	}
	return 0;
}
*/