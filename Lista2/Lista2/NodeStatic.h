#ifndef NODE_STATIC
#define NODE_STATIC
#include <vector>;

class NodeStatic {
public:
	NodeStatic();
	NodeStatic(NodeStatic*);
	~NodeStatic();

	void set_value(int newVal);
	int get_children_number();
	void add_new_child();
	NodeStatic* get_child(int childOffset);
	void print();
	void print_all_below();
	void print_up();
	void change_parent(NodeStatic* newParent);
	void add_existing_child(NodeStatic* child);
private:
	std::vector<NodeStatic> children;
	NodeStatic* parentNode;
	int val;
};

#endif