#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack:" << endl;
    st.display();

    cout << "Popped from stack: " << st.pop() << endl;
    cout << "Stack after pop:" << endl;
    st.display();

    return 0;
}