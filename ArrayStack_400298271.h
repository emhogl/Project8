/*
 * MyStack.h
 *
 *  Created on: Mar. 22, 2022
 *      Author: emma
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>
//#include

/*
template <typename E>
class Stack {
    public:
        virtual bool isEmpty () = 0;
        virtual E top () = 0;
        virtual void push (const E& e) = 0;
        virtual E pop () = 0;
};
*/

template <typename E>
class ArrayStack {
    private:
        int capacity;
        E* items;
        int topIndex = -1;

    public:
    //constructors
        ArrayStack() : ArrayStack(100) {}
        ArrayStack(int n){
            items = new E[n];
            capacity = n;
        }
        ~ArrayStack() {
            delete [] items;
        }

    //methods
        bool isEmpty() {
            return (topIndex<0);
        }
        void push(const E& e) {
            if (topIndex == capacity-1) {
                E* newArray = new E[2*capacity];
                for (int i=0; i<capacity; i++) {
                    newArray[i]=items[i];
                }
                delete[] items;
                items=newArray;
                capacity *= 2;
            }
            topIndex++;
            items[topIndex]=e;
        }
        E pop() {
            if (isEmpty()==true) {
                //std::cout<<"This is broken. "<<input[i]<<std::endl;
                throw std::underflow_error("Stack underflow");
            }
            else {
                E tempE = items[topIndex];
                topIndex--; //this is considered removing it
                return tempE;
            }
        }
        E top() {
            if (isEmpty()==true) {
                throw std::underflow_error("Stack underflow");
                //std::cout<<"Stack underflow"<<std::endl;
            }
            else {
                return items[topIndex];
            }
            return items[topIndex];
        }

        void printStack() {
            for (int i=0; i<=topIndex; i++) {
                std::cout<<items[i]<<std::endl;
            }
        }

};



#endif /* ARRAYSTACK_H_ */
