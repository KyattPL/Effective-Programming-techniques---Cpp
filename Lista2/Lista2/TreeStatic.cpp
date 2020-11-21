#include "TreeStatic.h";

TreeStatic::TreeStatic() : 
	root(NULL)
{

}

TreeStatic::~TreeStatic() {

}

NodeStatic* TreeStatic::get_root() {
	return &root;
}

void TreeStatic::set_root(NodeStatic root) {
	root = root;
}

void TreeStatic::print_tree() {
	root.print_all_below();
}

bool TreeStatic::move_subtree(NodeStatic* parentNode, NodeStatic* childNode) {

	if (parentNode == NULL || childNode == NULL || parentNode == childNode) {
		return false;
	}

	parentNode->add_existing_child(childNode);
	childNode->change_parent(parentNode);
	return true;
}