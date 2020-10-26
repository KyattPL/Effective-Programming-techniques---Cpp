void alloc_table_add_5(int size);
bool alloc_table_2_dim(int*** piTable, int sizeX, int sizeY);
bool dealloc_table_2_dim(int*** piTable, int sizeX, int sizeY);

class CTable {
	private:
		string name;
		int* table;

	public:
		CTable();
		CTable(string name, int tableLength);
		CTable(CTable& otherTable);
		~CTable();

		string get_name();
		int* get_table();
		void set_name(string name);
		bool set_new_size(int tableLength);
		CTable* clone();
};