#include "tests.h";
#include "NodeStatic.h";
#include "TreeDynamic.h";
#include "TreeStatic.h";
#include <iostream>;

void tree_test() {
	NodeStatic root;

	root.add_new_child();
	root.add_new_child();

	root.get_child(0)->set_value(1);
	root.get_child(1)->set_value(2);

	root.get_child(0)->add_new_child();
	root.get_child(0)->add_new_child();
	
	root.get_child(0)->get_child(0)->set_value(11);
	root.get_child(0)->get_child(1)->set_value(12);

	root.get_child(1)->add_new_child();
	root.get_child(1)->add_new_child();

	root.get_child(1)->get_child(0)->set_value(21);
	root.get_child(1)->get_child(1)->set_value(22);

	root.print_all_below();

	std::cout << "\n";

	root.get_child(0)->get_child(1)->print_up();
}

void dynamic_tree_test() {
	TreeDynamic tree;

	tree.set_root(new NodeDynamic());
	tree.get_root()->set_value(1);

	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->get_child(0)->set_value(1);
	tree.get_root()->get_child(1)->set_value(2);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->add_new_child();

	tree.get_root()->get_child(0)->get_child(0)->set_value(11);
	tree.get_root()->get_child(0)->get_child(1)->set_value(12);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->add_new_child();

	tree.get_root()->get_child(1)->get_child(0)->set_value(21);
	tree.get_root()->get_child(1)->get_child(1)->set_value(22);

	tree.get_root()->print_all_below();

	std::cout << "\n";

	tree.get_root()->get_child(0)->get_child(1)->print_up();
}

void move_subtree_test() {
	TreeStatic tree;

	tree.set_root(NodeStatic());
	tree.get_root()->set_value(1);

	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->get_child(0)->set_value(1);
	tree.get_root()->get_child(1)->set_value(2);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->add_new_child();

	tree.get_root()->get_child(0)->get_child(0)->set_value(11);
	tree.get_root()->get_child(0)->get_child(1)->set_value(12);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->add_new_child();

	tree.get_root()->get_child(1)->get_child(0)->set_value(21);
	tree.get_root()->get_child(1)->get_child(1)->set_value(22);

	tree.move_subtree(tree.get_root()->get_child(0)->get_child(1), tree.get_root()->get_child(1));
	tree.get_root()->print_all_below();
}