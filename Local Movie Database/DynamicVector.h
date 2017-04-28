#pragma once
template <typename T>
class DynamicVector
{
private:
	int size;
	int capacity;
	T* elems;
	void resize();

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);
	
	// Precond: pos is a valid position
	T& operator[](int pos);

	void add(T el);
	void update(T el, int pos);
	void deleteOnPos(int pos);

	int getSize() const;
	int isEmpty() const;
	T* getAllElems() const;
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity = 10)
{
	this->capacity = capacity;
	this->size = 0;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& v)
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.size; ++i)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	delete[] this->elems;

	this->capacity = v.capacity;
	this->size = v.size;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.size; ++i)
		this->elems[i] = v.elems[i];

	return *this;
}

template<typename T>
T& DynamicVector<T>::operator[](int pos) {
	return this->elems[pos];
}

template<typename T>
void DynamicVector<T>::add(T el) {
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size] = el;
	this->size++;
}

template<typename T>
void DynamicVector<T>::update(T el, int pos) {
	if (pos > this->size)
		return;
	this->elems[pos] = el;
}

template<typename T>
void DynamicVector<T>::deleteOnPos(int pos) {
	if (pos > this->size)
		return;
	for(int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template<typename T>
void DynamicVector<T>::resize() {
	this->capacity *= 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

template<typename T>
T* DynamicVector<T>::getAllElems() const {
	return this->elems;
}

template<typename T>
int DynamicVector<T>::getSize() const{
	return this->size;
}

template<typename T>
int DynamicVector<T>::isEmpty() const {
	if (this->size == 0)
		return 1;
	return 0;
}

