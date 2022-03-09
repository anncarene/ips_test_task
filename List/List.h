#ifndef LIST_H
#define LIST_H

namespace DataStructs
{
	template <typename T>
	struct Node
	{
		T value;
		Node* next;

		Node(T _value, Node* _next = nullptr) : value(_value), next(_next){}
	};

	template <typename T>
	class List
	{
		private:

			Node<T>* first;
			int size;

		public:

			Node<T>* getFirst() const { return this->first; }
			int getSize() const { return this->size; }
			bool isEmpty();									

			void addToStart(T value);
			void addToEnd(T value);

			void print();

			void deleteFromStart();
			void deleteFromEnd();
			void deleteEquals(const T& value);

			void invert();
	    void swap(List<T>& someList);

			List() : first(nullptr), size(0){}
			List(const List<T>& someList);

			bool operator== (const List<T>& someList);
			bool operator!= (const List<T>& someList);

			List& operator= (const List<T>& someList);
			~List();
	};
}

#endif
