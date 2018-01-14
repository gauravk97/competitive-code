#include <iostream>
#include <string>
using namespace std ;
char Stack[200],Queue[200];
int top,sizeQ,frontQ,endingQ;


//initialise stack and queue pointers
void init()
{
    top=-1;
    sizeQ=0;
    frontQ=0;
    endingQ=-1;

}





//precedence function
struct preced
{
	char op;
	int pre;
};

preced ope[5]={{'+',1},{'-',2},{'*',3},{'/',4},{'^',5}};

bool precedence(char a, char b)
{ bool w=false;
for(int j=0;j<5;j++)
	for(int k =0; k<5;k++){
		if((a==ope[j].op)&&(b==ope[k].op))
		{	if (ope[j].pre>ope[k].pre)
				w=true;
		}

	}
	return w;
}

//stack functions


void pushS(char a)
{
	Stack[++top]=a;

}
char popS()
{

	return Stack[top--];

}
//queue fn
void enqueue(char a){
	Queue[++endingQ]=a;
	sizeQ++;
}
char dequeue(){
	sizeQ--;
	return Queue[frontQ++];
}
void traverse(){
	for(int i=frontQ;i<=endingQ;i++)
	{
		cout<<Queue[i];
	}
}//output the queue fifo


//functions to check whether operator, alphabet
bool isOperator(char a){
		return (a=='+'||a=='-'||a=='*'||a=='/'||a=='^')?true:false;
}

bool isAlphabet(char a)
{
	bool b=false;
		for (int i = 97; i <= 122; ++i)
		{
			if((int)a==i) b=true;
		}
	return b;
}

//main transformation
void transform(string& Arr)
{
	for(char & c: Arr)
	{
		if(isAlphabet(c)){enqueue(c);}

		else if (isOperator(c)){
			while(precedence(Stack[top],c))
			{
				enqueue( popS());
			}	//precedence
			pushS(c);
		}

		else if (c=='('){pushS(c);}

		else if(c==')') {
				while(Stack[top]!='('){
					enqueue(popS());
				}
				if(Stack[top]=='(') top--;
		}

	}

	while(top>0){
		enqueue(popS());
	}


}





int main ()
{
	int q=0,t;
	string Arr;
	cin>>t;
	while(q++<t)
	{

        init();
		cin>>Arr;
		transform(Arr);
		traverse();
		cout<<endl;

	}

	return 0;
}
