#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

class Node {
public:
	virtual ~Node() {}
	virtual void showData() = 0;
};

template <typename T>
class TypedNode  : public Node {
public:
	TypedNode() {}
	TypedNode(const T& t) : m_data(t) {}
	void showData() {
		std::cout << "my data type : " << typeid(m_data).name() << std::endl;
	}
private:
	T m_data;
};

class GLinkedList {
public:
	template <typename T>
	void saveNewNode(T&& t) {
		nodeList.emplace_back(new TypedNode<T>(t));
	}
	
	void checkData() {
		for (size_t i = 0; i < nodeList.size(); ++i)
			nodeList[i]->showData();
		std::cout << std::endl;
	}

	~GLinkedList() {
		while (!nodeList.empty()) 
			nodeList.pop_back();
	}
private:
	std::vector<std::shared_ptr<Node> > nodeList;
};