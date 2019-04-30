#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack
{
public:
    Stack(){};
    virtual void push(string w)=0;
    virtual string pop()=0;
    virtual string top()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    ~Stack(){};
};

class StackArray:public Stack
{
    string* buf;
    int tp;
    int capacity;
public:
    StackArray(int maxsize)
    :capacity(maxsize=4), tp(0), buf(new string[maxsize]){}
    ~StackArray(){}
    void push(string w) { buf[tp++] = w; }
    string pop() { return buf[--tp]; }
    string top() { return buf[tp-1]; cout << buf[tp-1] << endl; }
    bool isEmpty() { return tp <= 0; }
    bool isFull() { return tp >= capacity;}
};

class LinkedStack:public Stack
{
    struct ListNode{
        string info;
        ListNode* next;
        ListNode(string new_info, ListNode *new_next)
        :info(new_info), next(new_next){}
    };
    ListNode* head;
public:
    LinkedStack()
    :head(nullptr){}
    ~LinkedStack(){}
    //    void push(string w) { if(isFull()) error ("Push on full stack"); head = new ListNode(w, head); }
    void push(string w) { head = new ListNode(w, head); }
    string pop();
    //    string top() { if(isEmpty()) error("top on empty stack"); return head->info; }
    string top() { return head->info; }
    bool isEmpty() { return head == nullptr; }
    bool isFull() { return false; }
};

class BaseFlowException
{
public:
	BaseFlowException(){cout<<"BaseFlowException constructor\n";}
	~BaseFlowException(){cout<<"BaseFlowException destructor\n";}
};

class ContainerOverFlow:public BaseFlowException
{
private:
	string of_msg;
public:
	ContainerOverFlow(string error)
		:of_msg(error){cout<<"Overflow constructor\n";}
	const char* getError(){ return of_msg.c_str(); }
	~ContainerOverFlow(){cout<<"Overflow Destructor\n";}
};


class ContainerUnderFlow:public BaseFlowException
{
private:
	string uf_msg;
public:
	ContainerUnderFlow(string error)
		:uf_msg(error) {cout<<"Underflow constructor\n";}
	const char* getError(){ return uf_msg.c_str(); }
	~ContainerUnderFlow(){cout<<"Underflow Destructor\n";}
};


string LinkedStack::pop(){
	ListNode* p = head;
	string w = head->info;
	head = head -> next;
	delete p;
	return w;	
}

void fillAll(string file_name, Stack& L){
	ifstream f(file_name.c_str());
   	string w;
   	if(f.is_open()){
	       	while(getline(f, w)){
		try{
			if(L.isFull()){
				throw ContainerOverFlow("OverFlow Error");
			} else {
		            	L.push(w);
			}	
		}
		catch(ContainerOverFlow& exception)
			{
				cerr <<	exception.getError() << endl;
			}
    		}
   		f.close();
	}
}

void emptyAll(Stack& L, string& output_file)
{
	try{
		if(L.isEmpty()){
			throw ContainerUnderFlow("UnderFlow Error");
		} else {
			ofstream f(output_file.c_str(), ios::out);
			while(L.isEmpty() == 0){
     				f << L.top() << endl;
       				L.pop();
   			}
			f.close();
		}
	}
	catch(ContainerUnderFlow& exception)
	{
		cerr << "An Exception Occurred: " << exception.getError() << endl;
	}
}


void Stack_test(string file_name, Stack& L, string output_file)
{
    fillAll(file_name, L);
//    emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
    const char* input_file = argc == 2? argv[1]: "random_5.txt";
    const char* output_file1 = "StackArrayOutput.txt";
    const char* output_file2 = "LinkedStackOutput.txt";
    
    StackArray a(10);
    LinkedStack b;

    Stack& s = a;
    Stack& t = b;

    Stack_test(input_file, s, output_file1);
//    Stack_test(input_file, t, output_file2);

    
    return 0;
}

