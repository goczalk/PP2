# include <iostream>
# include <iomanip>
# include <stdexcept>

#ifndef wzorzec_tab_asoc_hpp
#define wzorzec_tab_asoc_hpp

template <class idType, class aType> class Map{
		struct node_t{
			node_t* next;
            idType key;
            aType* wsk;
		};

		node_t* head;
		void clear(){
				node_t * o, *temp;
				for(o = head; o != NULL; o = temp){
					temp = o->next;
					delete o->wsk;
					delete o;
				}
			}

        node_t* find(idType key) const{
				node_t * o;
				for(o = head; o != NULL; o = o->next){
					if (o->key == key){
						break;
					}
					else{
						if (o->next == NULL){
							throw std::out_of_range("No such key in Map");}
					}
				}
				return o;
			}
			
        void swap(Map& t){
				node_t* temp = t.head;
				t.head = head;
				head = temp;
			}
	public:
        void insert(idType key, aType value){
				node_t* wsk = new node_t;
				aType* temp_obj = new aType; //to pass as temp obj made by constructor
				*temp_obj = value;
				
				wsk->next = NULL;
				wsk->key = key;
				wsk->wsk = temp_obj;
				
				if (head == NULL){
					head = wsk;
					return;
				}

				node_t * temp;
				//go to last element
				for(temp = head; temp->next != NULL; temp=temp->next);
				temp->next = wsk;
			}
        Map(){
			head = NULL;
			}
			
        Map(const Map& t){
			head = NULL;
			
			node_t* temp;
			for(temp=t.head; temp != NULL; temp = temp->next){
				insert(temp->key, *(temp->wsk));
				}
			}
			
        Map& operator = (const Map& t){
				if (&t == this){
					return *this;
				}
				
				Map temp(t);
				swap(temp);
				return *this;
			}
			
        ~Map(){
			clear();
			}
			
		aType& operator[](idType key) const{
				return *(find(key)->wsk);
			}
			
         friend std::ostream & operator <<( std::ostream & s, const Map& m){
				node_t * o;
				for(o = m.head; o != NULL; o = o->next){
					s << "key: " << std::setw(20) << o->key << std::setw(8) << 	"value: " << *(o->wsk) << std::endl;
				}
				return s;
			}
};

#endif 
