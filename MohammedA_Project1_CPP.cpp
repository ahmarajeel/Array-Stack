	/* Ahmar Mohammed
	   23132761
	   Project 1 (Stack)
	   
	   Steps of the algorithm:
	   
	   Step 0: Prepare all the things that are needed for your program
	   #include, initialization, counter etc
	   
	   Step 1: inFile <-- Open file, input file
	   inFile.open(argv[])
	   
	   Step 2: date <-- read one data from input file
	   inFile >> data
	   output data to the console
	   
	   Step 3: count++;
	   
	   Step 4: repeat step 2 and 3 while inFile is not empty
	   
	   Step 5: close inFile, open inFile 
	   declare stack
	   
	   Step 6: data <-- get one data from inFile 
	   
	   Step 7: Push(data)
	   output data to the console
	   
	   Step 8: repeat step 6 and 7 while inFile is not empty
	   
	   Step 9: data <-- pop()
	   
	   Step 10: output data to the console
	   
	   Step 11: repeat step 9 and 10 while stack is not empty
	   
	   step 12: close inFile
	   call destructor
	   
	*/
	
	#include <iostream>
	#include <fstream>
	using namespace std;
	
	//================Stack Class==================//
	class Stack 
	{
		private: 
		int* ary;
		int top;
		
		public: 
		
		//constructor
		Stack(int n)
		{
			ary = new int[n];
			top = -1;
		}
		
		//Destrutor
		~Stack() 
		{
			delete[] ary;
		}
		
		int pop()
		{
			if(top != -1)
			return ary[top--];
		}
		
		void push(int n)
		{
			top++;
			ary[top] = n;
		}
		
		bool isEmpty()
		{
			if(top < 0)
				return true;
			else 
				return false;
		}
			
	};
	
	//================= Main Method ====================//
	int main(int argc, char* argv[])
	{
		int n, counter = 0;
		ifstream myFile;
		myFile.open(argv[1]);
		
		cout << "Reading integers from the file: " << endl << endl;
		
		while(myFile >> n)
		{
			cout << n << endl;	
			counter++;
		}
		
		myFile.close();
		myFile.open(argv[1]);
		Stack myStack(counter);
		int m;
		
		cout << "\nPushing integers into the Stack: " << endl << endl;
		
		while (myFile >> m)
		{
			myStack.push(m);
			cout << m << endl;
		}
		
		cout << "\nPoping integers from the Stack: " << endl << endl;
		
		while (!myStack.isEmpty())             
		{
			cout << myStack.pop() << endl;
		}
		myFile.close();
		
		return 0;
	}
	    
