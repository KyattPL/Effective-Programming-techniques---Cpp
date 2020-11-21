#include "TreeDynamic.h";

TreeDynamic::TreeDynamic() :
	root(NULL)
{

}

TreeDynamic::~TreeDynamic() {
	delete root;
}

NodeDynamic* TreeDynamic::get_root() {
	return root;
}

void TreeDynamic::set_root(NodeDynamic* root) {
	this->root = root;
}

void TreeDynamic::print_tree() {
	root->print_all_below();
}

bool TreeDynamic::move_subtree(NodeDynamic* parentNode, NodeDynamic* childNode) {
	
	if (parentNode == NULL || childNode == NULL || parentNode == childNode) {
		return false;
	}
	
	parentNode->add_existing_child(childNode);
	childNode->change_parent(parentNode);
	return true;
}