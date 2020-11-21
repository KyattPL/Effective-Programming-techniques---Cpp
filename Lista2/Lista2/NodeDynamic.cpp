#include "NodeDynamic.h";
#include <iostream>;

NodeDynamic::NodeDynamic() :
	children(std::vector<NodeDynamic*>()),
	parentNode(NULL),
	val(0)
{

}

NodeDynamic::NodeDynamic(NodeDynamic* parent) :
	children(std::vector<NodeDynamic*>()),
	parentNode(parent),
	val(0)
{

}

NodeDynamic::~NodeDynamic() {
	for (int i = children.size() - 1; i >= 0; i--) {
		children[i]->~NodeDynamic();
	}
	children.clear();
}

void NodeDynamic::set_value(int newVal) {
	val = newVal;
}

int NodeDynamic::get_children_number() {
	return children.size();
}

void NodeDynamic::add_new_child() {
	children.push_back(new NodeDynamic(this));
}

NodeDynamic* NodeDynamic::get_child(int childOffset) {
	if (childOffset < 0 || childOffset >= children.size()) {
		return NULL;
	}
	else {
		return children[childOffset];
	}
}

void NodeDynamic::print() {
	std::cout << " " << val;
}

void NodeDynamic::print_all_below() {
	print();
	for (int i = 0; i < children.size(); i++) {
		children[i]->print_all_below();
	}
}

void NodeDynamic::print_up() {
	print();
	if (parentNode != NULL) {
		parentNode->print_up();
	}
}

void NodeDynamic::change_parent(NodeDynamic* newParent) {
	int index = 0;
	for (int i = 0; i < parentNode->children.size(); i++) {
		if (parentNode->get_child(i) == this) {
			index = i;
		}
	}
	parentNode->children.erase(parentNode->children.begin() + index);
	parentNode = newParent;
}

void NodeDynamic::add_existing_child(NodeDynamic* child) {
	children.push_back(child);
}