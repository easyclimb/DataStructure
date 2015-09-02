*****************************simple implementation with array*******************************************
class stack {
public:
    stack(int size);
    ~stack();
    void push(int elem);
    int top();
    void pop();
    void display();
    
private:
    int *p;
    int top, length;
};

stack::stack(int size) {
    top = -1;
    length = size;
    if(size == 0)
        p = NULL;
    else
        p = new int[length];
}

stack::~stack() {
    if(p != 0)
        delete [] p;
}

void stack::push(int elem) {
    if(p == NULL) {
        cout << "stack of zero size" << endl;
        cout << "enter a size for stack:" << endl;
        cin >> length;
        p = new int[length];
    }
    if(top == length - 1) {
        cout << "can't push " << elem << " stack full" << endl;
        return;
    }
    else {
        top++;
        p[top] = elem;
    }
}

int stack::top() {
    if(p == NULL || top == -1)
        cout << "stack empty" << endl;
    return p[top];
}

void stack::pop() {
    if(p == NULL || top ==-1)
        return;
    top--;
    length--;
    return;
}

void stack:display() {
    for(int i = 0; i <= top; i++)
        cout << p[i] << ' ';
    cout << endl;
    return;
}
