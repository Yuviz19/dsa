# STL (Standard Template Library)

!> [!NOTE]
> these are the notes taught in take U forward's lecture
- STL is a compilation of containers, algorithms, iterators and functions, to avoid manual work.
- for DSA, use library bits/stdc++.h
	- this includes all the libraries in cpp
	- and also write using namespace std
	  
## Pairs - used to store items in pairs (part of utility library)

```c++
pair<int, int> p = {1, 3};
cout << p.first << p.second;
	  
// nested property of pair
pair<int, pair<int, int>> p = {1, {2,3}};
cout << p.first << p.second.second;
	  
// an array of pair
pair<int, int> arr[] = {{1,3}, {2,5}, {4,6}};
cout << arr[1].second; // 5
```
	  
## Vectors - it is a dynamic size array (part of vector library)

```c++
vector<int> v;
v.push_back(1); // inserts 1 at the back
v.emplace_back(2); // adds 2 to the end and increases the size of container dynamically

vector<pair<int,int>> vec;
v.push_back({1,3});
v.emplace_back({2,5});

vector<int> v(5,100); // makes a container with 5 instances of 100
// if second value is not given, it will fill 5 spaces with 0 or garbage value

// to copy into another vector
vector<int> v2(v1);

// to access an element in vector v[1] or v.at(2);
// another method is using an iterator

vector<int>::iterator it = v.begin();
// so what this does gives a reference of the starting element of the container
// to print the element *(it)
cout << *(it) << " ";
it++;

vector<int>::iterator it = v.end(); // here u can it-- to access elements, gives the memory address of one past the last element

// not used
vector<int>::iterator it = v.rend(); // reverse end -> points to the first element 
vector<int>::iterator it = v.rbegin(); // points to the first element 

v.back() // -> it is used to print the last element of the container

// to print the items
for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
    cout << *(it) << endl;
}
// the same can be done in reverse order
// defining the vector iterator everytime is hectic so u can use auto word
for (auto it = v.begin(); it != v.end(); it++){
    // print *(it)
}

// using for each loop
for (auto it : v){
    cout << it << " ";
}

// deletion in a vector
v.erase(v.begin()+2); // delete 3rd element
// delete a series of elements
v.erase(v.begin()+2, v.begin()+4); // delete from element 3rd to 4th element (last element is not included)
git clone --depth 1 https://github.com/doomemacs/doomemacs ~/.config/emacs
// insertion of element
vector<int> v(2,100);
v.insert(v.begin(), 300); // insert 300 at the start
v.insert(v.begin(), 2, 10); // insert 10 twice at the second position 

// inserting a vector into another vector
vector<int> copy(2,100);
v.insert(v.begin(), copy.begin(), copy.end()) //adds copy to the end

v.size() // gives the size of the vector with 1 based indexing
v.pop_back() // pops out the last element
v.swap() // swaps content of 2 Vectors
v.clear() // erases teh vector
v.empty() // returns a bool value, for is vector is empty or not
```

## List - exactly similar to vector, but it gives front operation as well
```c++
list<int> ls;
ls.push_back(2);
ls.emplace_back(3);

ls.push_front(3);
ls.emplace_front(8);
// rest all functions are same
// begin, end, rbegin, rend, clear, insert, size, swap
```
## Deque - a double ended queue
```c++
deque<int> dq;
dq.push_back(1);
dq.push_front(2);

// same for emplace_back and emplace_front
dq.pop_back();
dq.pop_front();

dq.front();
dq.back();
// rest functions are same as vector
```

## Stack - follows LIFO (Last in First Out)
```c++
stack<int> st;
// insert
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.emplace(5);

st.top() // -> return 5

st.pop() // pops out the last inserted element i.e 5
// stack is not iterable
// we can use size, empty and swap function

// all operations take place in O(1) time
```
##  Queue - similar to stack, but follows FIFO (First in First Out)
```c++
queue<int> q;
q.push(1);
q.push(2);
q.emplace(4);

q.back() += 5;
q.back(); // -> 9
q.front(); // 1

q.pop() // pops out 1
// it is not iterable too
// size, empty, and swap are same as stack

// all operations take place in O(1) time 
```

## Priority queue - similar to queue, but the largest element gets the highest priority (lexographic for string)
```c++
priority_queue<int> pq;
pq.push(5);
pq.push(2);
pq.push(8); // {8,5,2}
// emplace do work
// otherwise, all functions are same as queue pop, top, size, swap, empty

// the operations do not take O(1), time is taken to sort
// a tree ds is maintained

// to maintain a min-heap
priority_queue<int, vector<int>, greater<int>> pq;
// now perform all basic operations, this will work as min queue

// a max and min heap are maintained
// hence push and pop take O(logn) and top takes O(1)
```

## Set - a container used to store unique elements in a sorted manner
```c++
set<int> st;
st.insert(1);
st.insert(2);
st.insert(2); // not work
st.insert(3);
st.emplace(4);

// {1,2,3,4}
auto it = st.find(3); // returns an iterator (momory address of 3)
auto it = st.find(6); // if an element is not present in a set, it will return set.end() {memory address of one after the end element}

st.erase(4); // erases the specific element and maintains the sorted order

// u can either give the element to be ereased or use the iterarator
auto it = st.find(3);
st.erase(it);

// {1,2,3,4,5}
auto it1 = st.find(2);
auto it2 = st.find(4);
st.erase(it1, it2); // erases 2,3 (last element is not included)

// begin, end, rend, rbegin, size - all works in the same way
st.count(3) // checks weather an element exists in an array or not (return 0 or 1)

// in set everything happens in a logarithmic time
```

## MultiSet - obeys sorted, but not unique
- everything is same as a set, 
- but there are duplicates present in the set
- on deletion of one, every element (instaces) are deleted
- count() function gives the count of the instances of element

```c++
multiset<int> ms;
ms.insert(1);
ms.insert(2);
ms.insert(2);
ms.insert(1);
// {1,1,2,2}

ms.erase(1);
// {2,2}

ms.count(2);
// returns 2

// to delete a specific element
ms.erase(ms.find(2)); 
ms.erase(ms.find(2), ms.find(2)+1);

// otherwise all set operations are same
```

## Unordered Set - everything is same is set, but does not obeys sorted property (uniqueness in maintained)
- upper_bound and lower_bound functions not valid, rest all functions are same
- it does not store elements in particular order
- hence a better complexity is maintained, except some cases when collision happens
- O(1) constant time (~almost)

## Map - a container to store data in forms of key-value pairs
- #NOTE - the keys in a map are unique, and the container is sorted for keys
- key and value can be of any data type
```c++
map<int, int> mp;
map<int, pair<int, int>> mp;
map<pair<int, int>, int> mpp;

mp[1] = 2;
mp.emplace({3,2});
mp.insert({2,4});
mpp[{2,3}] = 10;

{
    {1,3}
    {2,4}
    {3,5}
}

for (auto it : mp){
    cout << it.first << " " << it.second;
}

cout << mp[1]; // 3
cout << mp[2]; // 4
cout << mp[5]; // says null or 0

auto it = mp.find(3);
cout << *(it).second; // 5, gives the iterator to {3,5} element

// the lower_bound and the upper_bound functions are also valid
// size, erase, swap and empty are also valid in a map
```
## Multi-Map - Everything is same as map, but only it can store multiple keys
- map[key] cannot be used here

## Unnordered-Map -
- same as set and unordered set difference

-- all major containers and iterators are done

## ALgorithms

### Sorting
- to sort an array
- we can use sort(a, a+n), where n is the size of the array
- to sort a specific section of an array sort(a+x, a+y), where a+y index is not included

- to sort a vector
- sort(v.begin(), v.end())
- same for sorting a specific section of a vector

#NOTE - sort() method uses Introsort (it is an hybrid algo, which combines)
1. Quicksort (fast average case)
  - if recursion is too costly
2. use Heapsort
  - if the partitions is too small
3. finally do Insertionsort

- to sort in descending order
- sort(a, a+n greater<int>)
- the greater<int> is used as a comparator

- how to sort in some random fashion
- for say - sort a pair based on ascending second element, but if same, sort according to first element, but in decreasing order
pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};
sort(a, a+n, comp), where comp is a self written comparator (a bool function)

```c++
bool comp(pair<int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second) return true; // are these in the correct order
    if (p1.second > p2.second) return false; // now, swapping is internal
    if (p1.first > p2.first) return true;
    return false;
}
```

## built-in pop count
__builtin_popcount - this is used to count the number of set bits(1s) in the binary representation of an integer
```c++
int x = 13; // 1101
int count = __builtin_popcount(x); // gives 3
// the above function is used for 32 - bits number

// for 64 bits (long long)
long long y = 165786578678;
int cnt = __builtin_popcountll(y);
```
- use case - 
- this can be usefull to check if a number is in the power of 2
  - __builtin__popcount(x) == 1


-- other usefull builtins
- __builtin_ctz(x) - count trailing zeros in binary number 1011000 - 3
- __builtin_clz(x) - count leading zeros 0000000011010 - 8
- __builtin_parity(a)
  - 1 if set bits is odd
  - 0 if set bits is even

## Permutation in a String
```c++
string s = "123";

do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));
```
1. print s = 123
2. for the next iterations print all the permutations of the string
3. after that it will go to null, hence a false

- lets say if the strings are not sorted (if started at 231)
123
132
213
231  <- start here
312
321

- because the function is not a generate all permutaion funtion
  - rather it is a give the next larger permutation function
- so not all permutations printed
- hence, first sort(s.begin(), s.end())

## Max_Element
int maxi = *max_element(a, a+n);
- starts an iterator from a to a+n (end), and returns the memory address of the largest element
- similarly min_element also exists
