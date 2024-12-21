#include<iostream>
#include<cstdlib>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node(int value) :data(value),next(nullptr){}
};
class Queue {
private:
	Node* front, * rear;
public:
	// 队列初始化
	Queue() :front(nullptr), rear(nullptr) {}
	//入队
	void enqueue(int value) {
		Node* newnode = new Node(value);
		if (front == nullptr) {
			front = rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
	}
	//出队
	int dequeue() {
		if (front == nullptr) {
			cerr << "队列为空" << endl;
			return -1;
		}
		int value = front->data;
		Node* temp = front;
		front = front->next;
		if (front == nullptr) {
			rear = nullptr;
		}
		delete temp;
		return value;
	}
	//查找队首数据
	int peek() {
		if (front == nullptr) {
			cerr << "队列为空" << endl;
			return -1;
		}
		else {
			return front->data;
		}

	}
	//撤销队列
	void queueClear() {
		while (!isEmpty()) {
			dequeue();
		}
	}
	//判断队列是否为空
	bool isEmpty() {
		return front == rear;
	}
	//判断数据是否在队列中
	bool findValue(int value) {
		int num = 0;
		Node* current = front;
		while (current != nullptr) {
			if (current->data == value) {
				cout << value << "在第" << num << "位置" << endl;
				return true;
			}
			num++;
		}
		return false;
	}
	//获取队列长度
	int getlength() {
		if (isEmpty()) {
			cerr << "队列为空" << endl;
			return -1;
		}
		else {
			int count=0;
			Node* current = front;
			while (current != nullptr) {
				count++;
				current = current->next;
			}
			return count;
		}
	}
	//插入元素
	bool insertat(int value, int position) {
		Node* newnode = new Node(value);
		Node* current = front;
		if (position== 0) {
			newnode->next = front;
			front = newnode;
			if (rear == nullptr) {
				rear = newnode;
			}
			return true;
		}
		int count = 0;
		while (current != nullptr && count < position - 1) {
			current = current->next;
			count++;
		}
		if (current == nullptr) {
			return false;
		}
		newnode->next = current->next;
		current->next = newnode;
		if (current == rear) {
			rear = newnode;
		}
		return true;
	}
	//删除元素
	bool deleteat(int position) {
		if (position == 0) {
			if (front == nullptr) {
				return false;
			}
			Node* temp = front;
			front = front->next;
			if (front = nullptr) {
				rear = nullptr;
			}
			delete temp;
			return true;
		}
		int count = 0;
		Node* current = front;
		while (current != nullptr && count < position - 1)
		{
			current = current->next;
			count++;
		}
		if (current == nullptr || current->next == nullptr) {
			return false;
		}
		Node* temp = current->next;
		current->next = temp->next;
		if (temp == rear) {
			rear = current;
		}
		delete temp;
		return true;
	}
	//队列反转
	void reserve() {
		Node* next = nullptr, * previous = nullptr, *current = front;
		while (current != nullptr) {
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		swap(front, rear);
	}
	//队列打印
	void print() {
		Node* current = front;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;

		}
		cout << endl;
	}
};
void menue() {
	cout << "菜单 " << endl;
	cout << "   1.初始化队列 " << endl;
	cout << "   2.判断队列是否为空" << endl;
	cout << "   3.入队" << endl;
	cout << "   4.出队" << endl;
	cout << "   5.撤销队列" << endl;
	cout << "   6.获取队列长度" << endl;
	cout << "   7.获取队首数据" << endl;
	cout << "   8.数据查找" << endl;
	cout << "   9.数据插入" << endl;
	cout << "   10.数据删除" << endl;
	cout << "   11.反转队列" << endl;
	cout << "   12.打印队列数据" << endl;
	cout << "   13.退出系统" << endl;
}
int main() {
	Queue p;
	int option, value,position;
	while (true) {
		
		menue();
		cout << "输入选项" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cout << " 队列初始化成功" << endl;
			break;
		case 2:
			if (p.isEmpty()) {
				cout << "队列为空" << endl;
			}
			else {
				cout << " 队列非空" << endl;
			}
			break;
		case 3:
			cout << "输入入队数据" << endl;
			cin >> value;
			p.enqueue(value);
			cout << value << "入队成功" << endl;
			break;
		case 4:
			
			cout << p.dequeue() << "出队成功" << endl;
			break;
		case 5:
			p.queueClear();
			cout << "队列撤销成功" << endl;
			break;
		case 6:
			cout << "队列长度为:" << p.getlength() << endl;
			break;
		case 7:
			cout << "队首数据为:" << p.peek() << endl;
			break;
		case 8:
			cout << "请输入需要要判断的数据:";
			cin >> value;
			if (p.findValue(value)) {
				cout << value << "在队列中" << endl;
			}
			else {
				cout << value << "不在队列中" << endl;
			}
			break;
		case 9:
			cout << "输入插入数据:";
			cin >> value;
			cout << "输入插入位置:";
			cin >> position;
			if (p.insertat(value, position)) {
				cout <<value<< "成功插入" << endl;
			}
			else {
				cout << value << "未成功插入" << endl;
			}
			break;
		case 10:
			cout << "输入删除数据位置：";
			cin >> position;
			if (p.deleteat(position)) {
				cout << "位置" << position << "元素删除成功" << endl;
			
			}
			else {
				cout << "位置" << position << "元素删除未成功" << endl;
			}
			break;
		case 11:
			p.reserve();
			cout << "队列反转成功" << endl;
			break;
		case 12:
			p.print();
			cout << "队列打印成功" << endl;
			break;
		case 13:
			cout << "退出......." << endl;
				exit(0);
				break;
		default:
			cout << "不在选择范围，请重新输入" << endl;
		}
	}
	return 0;
}
