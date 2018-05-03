// Member-function definitions for class Vector.
#include "s1031418hw4_Vector.h" // include definition of class Vector 
ostream &operator<<(ostream& output, const Vector& vec){
	size_t size = vec.getSize();
	if (size == 0)
		output << 0;
	else 
	for (size_t i = 0; i < size; i++)
	{
		output << vec.ptr[i]<<" ";
	}
	output << endl;
	return output;

}

Vector::Vector( size_t n, const int val )
{
   if( n > 10 )
   {
      ptr = new int[ n ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = n;
   }
   else if( n > 0 ) // n <= 10
   {
      ptr = new int[ 10 ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = 10;
   }
   else
   {
      size = 0;
      capacity = 0;
      ptr = new int[ 0 ];
   }
}
Vector::Vector(int *first, int *last){
	size = capacity = last - first;
	ptr = new int[capacity];
	assign(first, last);
}
Vector::Vector(const Vector &vectorToCopy)
{
	size = vectorToCopy.getSize();
	capacity = vectorToCopy.getCapacity();
	ptr = new int [capacity];
	assign(vectorToCopy.ptr, (vectorToCopy.ptr) + size);
}
//* destructor
Vector::~Vector()
{
	delete[] ptr;
}

void Vector::reserve(size_t n){
	if (n<= capacity)  //n<= capa ok and skip
		return;
	capacity = n;    //capa become big to n
	int *tmp = ptr;  // int old ptr's data
	ptr = new int[capacity]; // []become to capa too big
	assign(tmp, tmp + size); // form tmp to end copy to ptr ;
	delete[]tmp;
}

void Vector::assign(int *first, int *last){
	if (first > last) {
		cout << "Bad resize!!\n";
		return;
	}
	size = last - first;// ex.2 3 4 > size = 3 ;
	if (size > capacity || !capacity)
		reserve(size); //when size>capa will error so reserve capa to size to ok it ;
	for (unsigned int i = 0; i < size; i++)
		ptr[i] = *(first ++);//ptr will = those form first to last 's data ;
}
	
void Vector::assign(int n, const int val){
	*this = Vector(n, val);
}

void Vector::resize(size_t n, const int val )
{
	if (n > capacity) reserve(n);//n>capa capa become n 
	if (n > size)
	for (unsigned int i = size; i < n; i++)
		ptr[i] = val; // over size data to store in last 
	size = n;//size=n or error 
}
void Vector::insert(int *position, int *first, int *last){
	if (position<begin() || position>end()) return ;
	size_t loc = position - begin();  //find it's loc 
	size_t len = last - first; //find it's len
	resize(size + len);   //the max size =size+len 
	for (size_t i = size-1; i >= loc; i--)  
	{	
		ptr[i] = ptr[i-len];   // form pos's data after move right len length;  
	}
	for (size_t i = 0; i < len; i++)
	{
		ptr[i+loc] = *(first ++); //insert array data form first to last  
	}
}
void Vector::push_back(const int val)
{
	reserve(capacity + 1); //capa+1  if size=capa  capa don't+1 it will gg
	size++;  // size++
	ptr[size - 1] = val; //size ass add val;
}

void Vector::erase(int *first, int *last){
	int len = last - first; //find length ;
	int loc = first - begin();//fin where to erase;
	for (int i = loc; i < len + loc; i++)
	{
		ptr[i] = NULL;  //deleted data = NULL 
	}
	for (int i = loc + len; i < size; i++)
	{
		ptr[i - len] = ptr[i]; // back to < move and coverd NULL;
	}
	resize(size - len); //resize to give up not use back data ;
}
const Vector &Vector::operator=(const Vector &right)
{
	if (this != &right)
	{
		size = right.getSize();
		capacity = right.getCapacity();
		ptr = new int[right.getCapacity()];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = right.ptr[i];
		}
		return *this;
	}
	else
		return *this;

}
void Vector::swap(Vector &x){
	//int *tptr to store  x.ptr and give ptr data;
	//int tempsize,tempcapacity to store ;
	size_t tsize = x.size;
	size_t tcapacity = x.capacity;
	int *tptr = x.ptr;
	x.size = size;
	x.capacity = capacity;
	x.ptr = ptr;
	size = tsize;
	capacity = tcapacity;
	ptr = tptr;
}
void Vector::shrink_to_fit(){
	capacity = size;
} // Requests the container to reduce its capacity to fit its size.

bool Vector::operator==(const Vector &right) const{
	if (size != right.getSize())
		return false;
	else
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (ptr[i] != right[i])
				return false;
		}
		return true;
	}
} // equality operator

// inequality operator; returns opposite of == operator
bool Vector::operator!=( const Vector &right ) const  
{ 
  return !( *this == right ); // invokes Vector::operator==
}
int &Vector::operator[](size_t n)
{
	if (n < 0 || n >=size) //if n>=size or n<0 overflow (cross arr)
	{
		cout << "Error !Overflow!" << endl;
		system("pause");
		exit(0);
	}
	else
		return ptr[n];
}
int Vector::operator[](size_t n) const{
	if (n < 0 || n >= size)
	{
		cout << "Error !Overflow!" << endl;
		system("pause");
		exit(0);
	}
	else
		return ptr[n];
}
int* Vector::begin()	
{
   return ptr;
}

int* Vector::end()
{
   return ptr + size;
}

int& Vector::front()
{
   return ptr[0];
}

int& Vector::back()
{
   return ptr[ size - 1 ];
}

void Vector::pop_back()
{
   size--;
}

size_t Vector::getSize() const
{
   return size;
}

size_t Vector::getCapacity() const
{
   return capacity;
}

bool Vector::empty() const
{
   return ( size == 0 );
}

void Vector::clear()
{
   size = 0;
}