#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include <bits/stdc++.h>
using namespace std;

// Creating a template to use any data type in this program.
//data type is called T

template <class T>
//creating class.
class VectorClass
{
// Create 3 private variables a T array named vect and 2 integer variables sizee and capacityy.
private:
    T* vect;
    int sizee ,capacityy;
public:
    //Constructor that takes integer parameter.
    VectorClass(int num)
    {
        //set the capacity of the vector.
        capacityy=num;
        vect=new T [capacityy];
        sizee=0;
    }
    //Constructor that takes array and integer parameters.
    VectorClass(T* arr, int n)
    {
        //set size of the vector and fill the vector with elements in given array.
        sizee = n;
        vect = new T[sizee];
        for (int x = 0; x < sizee; x++)
        {
            vect[x] = arr[x];
        }
    }

    //Constructor that takes class data type parameter.
    VectorClass(const VectorClass &new_vect)
        {
            //Fill the new vector with old vector and set the new vector size and capacity as the old one.
            sizee = new_vect.sizee;
            capacityy = new_vect.capacityy;
            vect = new T[capacityy];
            for (int x = 0; x < sizee; x++)
            {
                vect[x] = new_vect.vect[x];
            }

        }

        // Copy assignment.

        VectorClass &operator=(const VectorClass& new_vect)
        {
            delete [] vect;
            sizee=new_vect.sizee;
            capacityy=new_vect.capacityy;
            vect = new T[capacityy];
            for (int x= 0 ;x < sizee ; x++)
            {
                vect[x] = new_vect.vect[x] ;


            }
            return *this;
        }

        // Move assignment.

        VectorClass &operator=(const VectorClass&& new_vect)
        {
            delete [] vect;
            sizee= move (new_vect.sizee);
            capacity= move(new_vect.capacityy);
            vect= new T[capacityy];
            for(int x= 0 ;x < sizee ; x++)
            {
                vect[x]= move(new_vect.vect[x]);
            }
            return *this;
        }

        // Access item by reference.
        // Throw an exception if out of range.

        T& operator[](int i)
        {
            if( i >= 0 || i <= sizee-1)
            {
                return vect[i];
            }
            try
            {
                if(i > sizee-1 || i <0 )
                {
                    throw 0;
                }
            }
            catch (int n)
            {
                cout<<"wrong index"<<endl;
            }

        }

        // Return true if a vector ==  another vector.

        bool operator==(const VectorClass<T>& vec)
        {
            if (sizee == vect.sizee)
            {
                for(int x = 0 ; x < sizee ; x++)
                {
                    if(vect[x] != vec.vect[x] )
                    {
                        return false;
                        break;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                return false;
            }
        }

        // Compares item by item.
        // Return true if first different item in this is < in other.

        bool operator< (const VectorClass<T>& vec)
        {
            if(sizee==vec.sizee)
            {
                for(int x = 0 ; x < sizee ; x++)
                {
                    if(vect[x]<vec.vect[x])
                    {
                        return true;
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        // Return current size of vector.

        int size() const
        {
            return sizee;
        }
        // Return size of current allocated array.
        int capacity() const
        {
            return capacityy;
        }

        // Relocate to bigger space.

        int resize()
        {
            if(sizee == capacityy)
            {
                capacityy *=2;
                T* new_vect = new T[capacityy];
                for(int x = 0 ; x < sizee ; x++)
                {
                    new_vect[x]=vect[x];
                }
                delete vect;
                for(int x = 0 ; x < sizee ; x++)
                {
                    vect[x]=new_vect[x];
                }

            }
            return capacityy ;
        }
        // Return true if size is 0.
        bool empty()
        {
            if(sizee==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        //Overload operator << to print the vector by cout.

        friend ostream& operator << (ostream& out, VectorClass<T> vc)
        {
            out << "{";
            for(int x = 0 ; x < vc.sizee ; x++)
            {
                out<<vc.vect[x];
                if(x != vc.sizee -1){
                    out << "," ;
                }
            }
            out << "}";
            return out;

        }

        // Delete allocated memory

        virtual ~VectorClass()
        {

            delete [] vect;
        }

        // Insert item at iterator
        // Throw exception if invalid

        void insert(T* ite,int V )
        {
            if(ite < this-> begin()|| ite > this-> end()){
                cout << "out of range" ;

            }

            else{
                this->push_back(0);
                int ix = ite - begin()  ;
                for (int i = sizee-1 ; i > ix ; i--){
                    this-> vect[i] = this->vect[i-1];
                }
                this->vect[ix] = V;

            }

        }

        // Add item to end of vec & return # of items
		// Increase capacity of needed

        int push_back (T var)
        {
            if(sizee < capacityy){
                vect[sizee++] = var;
            }
            else

            {
                T* newvect = new T[capacityy*2];
                capacityy *= 2;

                for (int i=0; i < sizee ; i++){
                    newvect[i] = vect[i];

                }
                delete[] vect;
                vect = new T[capacityy];
                for (int i =0 ; i < sizee ; i++){
                    vect[i]= newvect[i];
                }
                delete[] newvect;
                vect[sizee+1] = var;

            }
            return sizee;

        }

        // Return an iterator (T*)

        T* begin()
        {
            return this->vect;
        }

        // Return an iterator (T*)

        T* end()
        {
            return this->begin()+size()-1;
        }


        void clear()
        {
            for(int i=0 ;i < this->size();i++)
            {
                this->vect[i]= T();
            }

            this->sizee=0;
        }

        // Remove and return last element in vec

        T pop_back() {
            T* newvect = new T[capacityy] ;
            for (int x = 0 ; x < sizee-1 ;x++) {
                newvect[x] = vect[x] ;

            }
            T z = vect[sizee -1] ;

            delete[]vect ;
            vect = new T[capacityy] ;
            sizee = sizee - 1 ;
            for (int x = 0 ; x < sizee ; x++) {
                vect[x] = newvect[x] ;

            }
            delete[]newvect ;
            return z ;
        }

        // Remove item at iterator
		// Throw exception if invalid iter

        void erase(T* ite){
            if(ite < this-> begin() || ite > this->end() ) {
                cout << "not in range"<<endl;
            }
            else {
                int index=ite-begin();
                for(int i=index+1;i< this->size();i++) {
                    this->vect[i - 1] = this->vect[i];

                }
                this->sizee--;
            }
        }

        // Remove items between
        // iterator 1 <= iterator 2 otherwise do nothing
        // Throw exception if any iterator outside range

        void erase(T* ite1 , T* ite2){
            if(ite1 < this-> begin() || ite2 > this->end() ) {
                cout << "not in range"<<endl;
            }

            else {

                if (ite2<ite1)
                    return;
                int startindex=ite1-begin();
                int endindex=ite2-begin();
                int counter=0;
                for(int i = endindex+1;i< this->size();i++) {
                    this->vect[startindex + counter] = this->vect[i];
                    counter++;
                }
                this->sizee-=endindex-startindex+1;
            }
        }



    };

#endif // VECTORCLASS_H
