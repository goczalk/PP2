#ifndef tab_asoc_hpp
#define tab_asoc_hpp

class AssocTab{
	protected:
		struct node_t{
			node_t* next;
			char* key;
			int value;
		};
		node_t* head;
		void clear();
		//dodatkowo
		void delete_node(const char* key);

        virtual int compare(const char* a, const char* b) const;
        node_t* find(const char* key) const;
		
		void swap(AssocTab& t);
	public:
	
		void insert(const char* key, int value); //const key zeby bylo mozna podawac "x"
		AssocTab();
		AssocTab(const AssocTab& t);
		AssocTab& operator = (const AssocTab& t);
		virtual ~AssocTab();
		int& operator[](const char* key);
		
		void print();
};

//CaseIns = Case Insensitive
class AssocTab_CaseIns
	: public AssocTab{
        virtual int compare(const char* a, const char* b) const;
};

#endif 
