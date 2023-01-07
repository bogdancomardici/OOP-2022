#include <iostream>
using namespace std;

class stack
{
    private:

    int* s = new int[1];
    int cap = 0;
    int last_idx = -1;

    public:

    // constructors
   
    explicit stack(int cap = 0) // empty stack with max capacity cap
    {   
        delete[] s;
        this -> cap = cap;
        s = new int[cap];
    }

    stack(int* x, int xsize) // stack from array and array size
    {
        this -> cap = xsize;
        delete[] s;
        s = new int[cap];

        for(int i = 0; i < cap; i++)
            this -> push(x[i]);
    }

    stack(const stack& t) // copy stack
    {
        this -> cap = t.cap;
        delete[] this -> s;
        s = new int[this -> cap];
        last_idx = -1;

        for(int i = 0; i <= t.last_idx; i++)
            this -> push(t.s[i]);

    }

    // destructor
    ~stack()
    {
        delete[] s; // delete array of stack elements
    }

    // functions
    int get_cap() const
    {
        return cap;
    }

    void set_cap(int newCap)
    {
        this -> cap = newCap;
        int* aux = new int[newCap];
        int aux_cap = 0;
        int i = 0;

        while(i <= last_idx && i < newCap)
        {
            aux[i] = s[i];
            aux_cap++;
            i++;
        }

        delete[] s;

        s = new int[newCap];
        for(i = 0; i <= aux_cap; i++)
            s[i] = aux[i];
        
        last_idx = aux_cap - 1;

        delete[] aux;
    }

    int* get_stack() const 
    {
        return s;
    }

    void set_stack(const int* v, int vcap)
    {
        if(vcap > cap)
        {
            cout << "New stack capacity is too big, use set_cap to adjust it" << endl;
        }
        else
        {
            for(int i = 0; i < vcap; i++)
                s[i] = v[i];
            
            last_idx = vcap - 1;
        }
    }

    int get_last_index() const
    {
        return last_idx;
    }

    void set_last_index(int newIdx)
    {
        last_idx = newIdx;
    }

    void show() const
    {
        for(int i = 0; i <= last_idx; i++)
            cout << s[i] << " ";
        
        cout << endl;
    }

    void read()
    {
        int temp_cap;
        
        cout << "Capacity of the stack: ";
        cin >> temp_cap;

        delete[] s;
        s = new int[temp_cap];
        this -> cap = temp_cap;

        cout << "No. of elements to be inserted into the stack: ";

        int c;
        cin >> c;

        if(c > temp_cap)
        {
            cout << "Too many elements" << endl;
        }
        else
            for(int i = 0; i < c; i++)
            {
                int temp;
                cin >> temp;
                this -> push(temp);
            }
    }

    int top() const
    {
        return s[last_idx];
    }

    void pop()
    {
        last_idx--;
    }

    void push(int el)
    {
        if(last_idx + 1 < cap)
        {
            last_idx++;
            s[last_idx] = el;
        }
        else
            cout << "Maximum capacity has been reached" << endl;
    }

    int len() const
    {
        return last_idx + 1;
    }

    // operators
    stack& operator<<(int el) // insert element, pointer to this so we can use operator multiple times
    {   
        if(last_idx + 1 < cap)
        {
            last_idx++;
            s[last_idx] = el;
        }
        else
            cout << "Maximum capacity has been reached" << endl;

        return *this;
    }

    stack& operator>>(int el) // delete all occurences of element el
    {
        int i = 0;
        int nr = 0;
        while(i <= last_idx)
            if(s[i] == el)
            {   
                nr++;
                for(int j = i; j <= last_idx - 1; j++)
                s[j] = s[j + 1];
                last_idx--;
            }
            else
                i++;
        
         cout << "Deleted " << nr << " occurences of element " << el << endl;

        return *this;
    }

    stack& operator=(stack& rhs) // copy operator
    {   
        if(&rhs != this)
        {
        this -> cap = rhs.cap;
        delete[] this -> s;
        s = new int[this -> cap];

        last_idx = -1;
        for(int i = 0; i <= rhs.last_idx; i++)
            this -> push(rhs.s[i]);
        }
        return *this;
    }

    bool operator==(const stack& rhs) const // two stacks are equal if they have the same elements in the same order
    {
        if(this -> cap != rhs.cap)
            return false;
        
        for(int i = 0; i < this -> cap; i++)
            if(this -> s[i] != rhs.s[i])
                return false;

        return true;
    }

    bool operator!=(const stack& rhs) const // the oposite of ==
    {
        if(this -> cap != rhs.cap)
            return true;
        
        for(int i = 0; i < this -> cap; i++)
            if(this -> s[i] != rhs.s[i])
                return true;

        return false;
    }

    // cin and cout
    
    friend ostream& operator<< (ostream &out, const stack& st)
    {
        for(int i = 0; i <=st.last_idx; i++)
            out << st.s[i] << " ";

        out << endl;
    
        return out;
    }

    friend istream& operator>> (istream &in, stack& st)
    {
        int temp_cap = 0;
        
        cout << "Capacity of the stack: ";
        cin >> temp_cap;

        delete[] st.s;
        st.s = new int[temp_cap];
        st.cap = temp_cap;

        cout << "No. of elements to be inserted into the stack: ";

        int c = 0;
        in >> c;

        if(c > temp_cap)
        {
            cout << "Too many elements" << endl;
        }
        else
            for(int i = 0; i < c; i++)
            {
                int temp;
                in >> temp;
                st.push(temp);
            }
    
        return in;
    }
};

class menu
{   
    private:
    int choice = - 1;
    
    stack* vstack = new stack[1];
    int vstack_last = -1;

    public:

    ~menu()
    {
        delete[] vstack;
    }
    void increase_size()
    {   
        // dynamic memory allocation
        // copy contents in auxiliary array, delete the reinitialize array with new capacity
        // copy contents from the auxiliary array back to the primary array
        // delete the auxiliary array
        stack* res = new stack[vstack_last + 1];

        for(int i = 0; i < vstack_last; i++)
            res[i] = vstack[i];

        delete[] vstack;
        vstack = new stack[vstack_last + 1];

        for(int i = 0; i < vstack_last; i++)
            vstack[i] = res[i];

        delete[] res;
    }

    void decrease_size(int d)
    {
        stack* res = new stack[vstack_last];

        for(int i = 0; i < d; i++)
            res[i] = vstack[i];
        
        for(int i = d + 1; i <= vstack_last; i++)
            res[i - 1] = vstack[i];

        delete[] vstack;
        vstack = new stack[vstack_last];

        for(int i = 0; i < vstack_last; i++)
            vstack[i] = res[i];

        delete[] res;
    }
    void begin()
    {
        while(choice != 0)
        {   
            cout << "0. Exit" << endl;
            cout << "1. New Stack" << endl;
            cout << "2. Delete Stack " << endl;
            cout << "3. List previously created stacks" << endl;
            cout << "4. Add data to existing stack" << endl;
            cout << "5. Delete data from existing stack" << endl;
            cout << "6. Pop element from existing stack" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
            {   
                cout << endl << "New Stack" << endl;
                vstack_last++;

                increase_size();

                vstack[vstack_last].read();
                cout << "Created new stack with id " << vstack_last << endl;
                break;
            }
            
            case 2:
            {
                cout << endl << "Delete Stack" << endl;
                int d = -1;

                for(int i = 0; i <= vstack_last; i++)
                {
                    cout << "Stack " << i << " : ";
                    vstack[i].show();
                }

                cin >> d;
                if(d > vstack_last)
                {
                    cout << "No stack with this id" << endl;
                    break;
                }
                
                decrease_size(d);
                vstack_last--;
                break;
            }

            case 3:
            {   
                cout << endl << "Listing all the stacks:" << endl;

                for(int i = 0; i <= vstack_last; i++)
                {   
                    cout << "Stack " << i << " : ";
                    vstack[i].show();
                    
                }
                cout << endl;
                break;
            }

            case 4:
            {   
                int d, nr, x;
                cout << endl << "Add data to existing stack, select one:" << endl;

                for(int i = 0; i <= vstack_last; i++)
                {   
                    cout << "Stack " << i << " : ";
                    vstack[i].show();
                    cout << endl;
                }

                cin >> d;
                if(d > vstack_last)
                {
                    cout << "No stack with this id" << endl;
                    break;
                }

                cout << "No. of elements to insert in the stack: ";
                cin >> nr;

                cout << "Elements to be inserted: " << endl;
                for(int i = 0; i < nr; i++)
                {
                    cin >> x;
                    vstack[d] << x;
                }

                break;
            }
            
            case 5:
            {   
                int d, nr, x;
                cout << endl << "Remove data from existing stack, select one:" << endl;

                for(int i = 0; i <= vstack_last; i++)
                {   
                    cout << "Stack " << i << " : ";
                    vstack[i].show();
                    cout << endl;
                }

                cin >> d;
                if(d > vstack_last)
                {
                    cout << "No stack with this id" << endl;
                    break;
                }
                cout << "No. of elements to delete from the stack: ";
                cin >> nr;

                cout << "Elements to be deleted: " << endl;
                for(int i = 0; i < nr; i++)
                {
                    cin >> x;
                    vstack[d] >> x;
                }

                cout << endl;
                break;
            }

            case 6:
            {
                int d;
                cout << endl << "Pop element from existing stack, select one:" << endl;

                for(int i = 0; i <= vstack_last; i++)
                {   
                    cout << "Stack " << i << " : ";
                    vstack[i].show();
                    cout << endl;
                }

                cin >> d;
                if(d > vstack_last)
                {
                    cout << "No stack with this id" << endl;
                    break;
                }
                
                vstack[d].pop();
            }
            
            default:
                break;
            }
        }
    }
};

int main()
{   
    cout << "C++ Stack Implementation" << endl;

    menu interface;

    interface.begin();
    
    //demo for overloaded operators
    
    
    stack s1(10), s2(10), s3(10), s5;
    s1 << 3 << 5 << 7;
    s1 << 89;
    s2 = s1;
    s3 << 5 << 6;
    s1 >> 3;

    cout << s1 << s2 << s3;

    cin >> s5;
    cout << s5;
    
    int* v = new int[2];
    v[0] = 6;
    v[1] = 9;

   
    
    stack s4(v,2);
    cout << s4.get_cap() << " " << s4.get_last_index() << " " << s4.len() << " " << s4.top() << endl;
    s4.set_cap(4);
    s4 << 8;
    cout << s4;
    s4.set_last_index(2);
    cout << endl;
    cout << s4.get_cap() << " " << s4.get_last_index() << " " << s4.len() << " " << s4.top() << endl;
    
    int* u = s4.get_stack();
    s4.set_stack(u, s4.get_last_index() + 1);

    cout << s4;

    delete[] v;
    if(s2 == s3)
        cout << "Same Content" << endl;
    
    
    return 0;
}