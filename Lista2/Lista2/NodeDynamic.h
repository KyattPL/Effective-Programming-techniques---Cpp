#ifndef NODE_DYNAMIC
#define NODE_DYNAMIC
#include <vector>;

class NodeDynamic {
public:
	NodeDynamic();
	NodeDynamic(NodeDynamic*);
	~NodeDynamic();

	void set_value(int newVal);
	int get_children_number();
	void add_new_child();
	NodeDynamic* get_child(int childOffset);
	void print();
	void print_all_below();
	void print_up();
	void change_parent(NodeDynamic* newParent);
	void add_existing_child(NodeDynamic* child);
private:
	std::vector<NodeDynamic* > children;
	NodeDynamic* parentNode;
	int val;
};

#endif