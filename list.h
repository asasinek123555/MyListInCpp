#ifndef z1_h
#define z1_h

#include <cstdlib>
#include <sstream>

#ifdef console
#include <iostream>
#endif

using namespace std;

template <class type>
string coutToString(type x)
{
	ostringstream y;
	y<<x;
	return y.str();
}

template <class type>
class element
{
	public:
		type *something;
		element *next;
		element *prev;
		element(element *prev=NULL, element *next=NULL)
		{
			this->prev=prev;
			this->next=next;
		}
		~element()
		{
			if(prev!=NULL)
			{
				prev->next=next;
			}
			if(next!=NULL)
			{
				next->prev=prev;
			}
		}
		string info(string text)
		{
			ostringstream pre, nex, thi;
			pre<<prev;
			nex<<next;
			thi<<this;
			string th="this: ", pr=" prev: ", ne=" next: ", end=" | ";
			return th+thi.str()+pr+pre.str()+ne+nex.str()+end+text;
		}
};
/*  // nadpisuje co niepowinno
template <class type>
ostream &operator<<(ostream &stream, const element<type> *elem)
{
	return  stream<<"this: "<<coutToString(elem)<<" prev: "<<coutToString(elem->prev)<<" next: "<<coutToString(elem->next)<<" | ";
}
*/

template <class type>
class lista
{
	private:
		int count;
		element<type> *start;
		element<type> *stop;
		element<type> *current;
	public:
		bool set_current(int x=0)
		{
			if(x<count)
			{
				element<type> *temp=start;
				for(int i=0;i<x;i++)
				{
					temp=temp->next;
				}
				current=temp;
				return 1;
			}
			else current=NULL;
			return 0;
		}
		lista()
		{
			start=NULL;
			stop=NULL;
			current=NULL;
			count=0;
		}
		~lista()
		{
			clear();
		}
		void clear()
		{
			while(count>0)
			{
				remove();
			}
		}
		bool removeFront(bool _deleteType=true)
		{
			remove(0, _deleteType);
		}
		bool removeBack(bool _deleteType=true)
		{
			remove(count-1, _deleteType);
		}
		bool remove(int x=0, bool _deleteType=true)
		{
			if(x<count)
			{
				set_current(x);
				if(x==0) start=start->next;
				if(x==count-1) stop=stop->prev;
				if(_deleteType&&current->something!=NULL) delete current->something;
				delete current;
				set_current(x);
				count--;
				return 1;
			}
			return 0;
		}
		bool addFront(type *typePointer=NULL)
		{
			return add(typePointer,0);
		}
		bool addBack(type *typePointer=NULL)
		{
			return add(typePointer,count-1);
		}
		bool add(type *typePointer=NULL, int x=0)
		{
			if(x<=count)
			{
				if(count>0)
				{
					if(x==0)
					{						
						start= new element<type>(NULL,start);
						start->next->prev=start;
						current=start;
					}
					else if(count==x)
					{
						stop->next= new element<type>(stop);
						stop=stop->next;
						current=stop;
					}
					else
					{
						set_current(x-1);
						current->next=new element<type>(current,current->next);
						current->next->next->prev=current->next;
						current=current->next;
					}
				}
				else start=stop=current=new element<type>();
				count++;
				current->something=typePointer;
				return 1;
			}
			return 0;
		}
		type* getFront()
		{
			return this->get(0);
		}
		type* getBack()
		{
			return this->get(count-1);
		}
		type* get(int x=0)
		{
			if(x<count)
			{
				set_current(x);
				return current->something;
			}
			else return NULL;
		}
		element<type> *get_element(int x=0)
		{
			if(x<count)
			{
				set_current(x);
				return current;
			}
			else return NULL;
		}
		bool set(type *something,int x=0)
		{
			if(x<count)
			{
				set_current(x);
				current->something=something;
			}
			else return 0;
		}
		int get_count()
		{
			return count;
		}
		element<type>* get_start()
		{
			return start;
		}
		element<type>* get_stop()
		{
			return stop;
		}
		element<type>* get_current()
		{
			return current;
		}
		string info(string text)
		{
			// start stop current count
			return "this: "+coutToString(this)+" start: "+coutToString(start)+" stop: "+coutToString(stop)+" current: "+coutToString(current)+" | "+text;
		}
		type* popFront()
		{
			return this->pop(0);
		}
		type* popBack()
		{
			return this->pop(0);
		}
		type* pop(int x=0)
		{
			if(x<count)
			{
				set_current(x);
				type *temp=current->something;
				this->remove(x,0);
				return temp;
			}
			else return NULL;
		}
		#ifdef console
		void print(lista<type> *list, bool dbg=0)
		{
			if(dbg)
			{
				cout<<list->info("\n");
				for(int i=0;i<list->get_count();i++)
				{
					cout<<i+1<<". [";
					string y="something: ";
					element <type>*ele=list->get_element(i);
					
					y+=coutToString(*(ele->something));
					
					cout<<ele->info(y)<<"]"<<endl;
				}
			}
			else for(int i=0;i<list->get_count();i++)
			{
				
				string y="|"+coutToString(i+1)+". [";
				element <type>*ele=list->get_element(i);
				
				y+=coutToString(*(ele->something));
				
				cout<<y<<"]| ";
			}
			cout<<endl;
		}
		#endif
};


#endif
