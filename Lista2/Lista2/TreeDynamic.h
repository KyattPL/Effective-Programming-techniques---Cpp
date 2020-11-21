#ifndef TREE_DYNAMIC
#define TREE_DYNAMIC

#include "NodeDynamic.h";

class TreeDynamic {
public:
	TreeDynamic();
	~TreeDynamic();

	NodeDynamic* get_root();
	void set_root(NodeDynamic* root);
	void print_tree();
	bool move_subtree(NodeDynamic* parentNode, NodeDynamic* childNode);
private:
	NodeDynamic* root;
};

#endif