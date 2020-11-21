#include "NodeStatic.h";
#include <iostream>;

NodeStatic::NodeStatic() :
	children(std::vector<NodeStatic>()),
	parentNode(NULL),
	val(0)
{

}

NodeStatic::NodeStatic(NodeStatic* parent) :
	children(std::vector<NodeStatic>()),
	parentNode(parent),
	val(0)
{

}


NodeStatic::~NodeStatic() {

}

void NodeStatic::set_value(int newVal) {
	val = newVal;
}

int NodeStatic::get_children_number() {
	return children.size();
}

void NodeStatic::add_new_child() {
	children.push_back(NodeStatic(this));
}

NodeStatic* NodeStatic::get_child(int childOffset) {
	if (childOffset < 0 || childOffset >= children.size()) {
		return NULL;
	}
	else {
		return &children[childOffset];
	}
}

void NodeStatic::print() {
	std::cout << " " << val;
}

void NodeStatic::print_all_below() {
	print();
	for (int i = 0; i < children.size(); i++) {
		children[i].print_all_below();
	}
}

void NodeStatic::print_up() {
	print();
	if (parentNode != NULL) {
		parentNode->print_up();
	}
}

void NodeStatic::change_parent(NodeStatic* newParent) {
	int index = 0;
	for (int i = 0; i < parentNode->children.size(); i++) {
		if (parentNode->get_child(i) == this) {
			index = i;
		}
	}
	parentNode->children.erase(parentNode->children.begin() + index);
	parentNode = newParent;
}

void NodeStatic::add_existing_child(NodeStatic* child) {
	children.push_back(*child);
}