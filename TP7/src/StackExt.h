# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> st;
	stack<T> min;
public:
	StackExt() {};
	bool empty() const;
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T>
bool StackExt<T>::empty() const {
	return st.empty();
}

template <class T>
T& StackExt<T>::top() {
	return st.top();
}

template <class T>
void StackExt<T>::pop() {
	if(st.top() == min.top())
		min.pop();
	st.pop();
}

template <class T>
void StackExt<T>::push(const T& val) {
	st.push(val);
	if(min.empty())
		min.push(val);
	else if(val <= min.top()) {
		min.push(val);
	}

}

template <class T>
T& StackExt<T>::findMin() {
	return min.top();
}
