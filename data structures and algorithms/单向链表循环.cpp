#include <iostream>
using namespace std;

class CircleLink {
public:
	CircleLink() {
		head_ = new Node;
		tail_ = head_;
		tail_->next = head_;
	}
	~CircleLink()
	{
		Node *p=head_->next;
		while (p!=head_)
		{
			p = head_->next;
			delete p;
			head_->next = p;
		}
		delete head_;
	}
	void inserTail(int val) {
		Node *node = new Node(val);
		tail_->next=node;
		tail_=node;//		tail_->next = head_;
		


	}
private:
	struct Node {
		Node(int val = 0) :data(val), next(nullptr) {}
		int data;
		Node* next;
	};
	Node* head_;
	Node* tail_;
};



int main() {
	return 0;
}