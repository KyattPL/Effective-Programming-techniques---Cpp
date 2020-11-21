#ifndef TREE_STATIC
#define TREE_STATIC

#include "NodeStatic.h";

class TreeStatic {
public:
	TreeStatic();
	~TreeStatic();

	NodeStatic* get_root();
	void set_root(NodeStatic value);
	void print_tree();
	bool move_subtree(NodeStatic* parentNode, NodeStatic* childNode);
private:
	NodeStatic root;
};

#endif